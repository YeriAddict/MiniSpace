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
    CascadeClassifier face_cascade;
    if( !face_cascade.load( "../Resources/palm.xml" ) )
    {
        qDebug()<<"erreur";
        return -1;
    }
    while (waitKey(5)<0)
    {
        Mat frame,frame_gray;
        std::vector<Rect> faces;
        cap >> frame;
        cv::flip(frame,frame,1);
        cv::cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
        face_cascade.detectMultiScale( frame_gray, faces, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
        if (faces.size()>0)
        {
            for (int i=0;i<(int)faces.size();i++)
                rectangle(frame,faces[i],Scalar(0,255,0),2);
        }

        QImage img= QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,QImage::Format_BGR888);
        ui->webcamLabel->setPixmap(QPixmap::fromImage(img));
        ui->webcamLabel->resize(ui->webcamLabel->pixmap().size());
    }
    return 0;
}
