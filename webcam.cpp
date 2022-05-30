#include "webcam.h"
#include "ui_webcam.h"
#include "opencv2/opencv.hpp"
using namespace cv;

Webcam::Webcam(QWidget *parent) : QWidget(parent)
    , ui(new Ui::Webcam)
{
    ui->setupUi(this);
    webcamTimer = new QTimer(this);
    connect(webcamTimer,SIGNAL(timeout()), this, SLOT(updateWebcam()));
    webcamTimer->start(100);
}

Webcam::~Webcam()
{
    delete ui;
}

int Webcam::updateWebcam(){
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        return -1;
    }
    CascadeClassifier palm;
    CascadeClassifier fist;
    if( !palm.load( "../Resources/palm.xml" ) )
    {
        qDebug()<<"erreur";
        return -1;
    }
    if( !fist.load( "../Resources/fist.xml" ) )
    {
        qDebug()<<"erreur";
        return -1;
    }
    while (waitKey(5)<0)
    {
        Mat frame,frame_gray;
        std::vector<Rect> vecPalm;
        std::vector<Rect> vecFist;
        cap >> frame;
        cv::flip(frame,frame,1);
        cv::cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
        palm.detectMultiScale( frame_gray, vecPalm, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
        // Mode : Idle
//        webcamDetector_=0;
        if (vecPalm.size()>0)
        {
            for (int i=0;i<(int)vecPalm.size();i++){
                Coordinates coordinatesPalm = {vecPalm[i].x, vecPalm[i].y};
                palmPositions.push_back(coordinatesPalm);
                rectangle(frame,vecPalm[i],Scalar(0,255,0),2);
            }
        }
        fist.detectMultiScale( frame_gray, vecFist, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
        if (vecFist.size()>0)
        {
            for (int i=0;i<(int)vecFist.size();i++){
                Coordinates coordinatesFist = {vecFist[i].x, vecFist[i].y};
                fistPositions.push_back(coordinatesFist);
                rectangle(frame,vecFist[i],Scalar(255,0,0),2);
            }
        }

        if((int)palmPositions.size()==2){
            // Mode : Move forward
            webcamDetector_=1000;
        }
        if((int)fistPositions.size()==2){
            Coordinates leftPoint,rightPoint;
            if(fistPositions[0].x < fistPositions[1].x){
                leftPoint = fistPositions[0];
                rightPoint = fistPositions[1];
            }
            else{
                leftPoint = fistPositions[1];
                rightPoint = fistPositions[0];
            }
            if(leftPoint.y > rightPoint.y){
                // Mode : Turn left
                webcamDetector_ = 4000;
            }
            else{
                // Mode : Turn right
                webcamDetector_ = 5000;
            }
            if((leftPoint.y>300)&&(rightPoint.y>300)){
                // Mode : Turn down
                webcamDetector_ = 3000;
            }
            if ((leftPoint.y<50)&&(rightPoint.y<50)){
                // Mode : Turn up
                webcamDetector_ = 2000;
            }
        }
        palmPositions.clear();
        fistPositions.clear();
        QImage img= QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_BGR888);
        ui->webcamLabel->setPixmap(QPixmap::fromImage(img));
        ui->webcamLabel->resize(ui->webcamLabel->pixmap().size());
    }
    return 0;
}
