#include "game.h"
#include "ui_game.h"
#include "opencv2/opencv.hpp"
using namespace cv;

Game::Game(int asteroidNumber, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
    space = new SpaceWidget(asteroidNumber);
    ui->horizontalLayout->addWidget(space);
    space->setFocus();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateChronometer()));
    ui->timeLabel->setText(QTime(0, 0).toString());
    startTime.restart();
    timer->start(1000);

    webcamTimer = new QTimer(this);
    connect(webcamTimer,SIGNAL(timeout()), this, SLOT(updateWebcam()));
    webcamTimer->start(100);
}

Game::~Game() {
    delete ui;
    delete space;
}

void Game::updateChronometer(){
    ui->timeLabel->setText(QTime(0, 0).addMSecs(startTime.elapsed()).toString());
}

int Game::updateWebcam(){
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
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
