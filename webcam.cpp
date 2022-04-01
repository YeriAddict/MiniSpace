#include "webcam.h"
#include "ui_webcam.h"
#include "opencv2/opencv.hpp"
using namespace cv;

Webcam::Webcam(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Webcam)
{
    ui->setupUi(this);

    webCam_ = new VideoCapture(0);
    int width=webCam_->get(CAP_PROP_FRAME_WIDTH);
    int height=webCam_->get(CAP_PROP_FRAME_HEIGHT);

    if(!webCam_->isOpened())  // check if we succeeded
    {
        ui->infoLabel_->setText("Default camera cannot be opened");
    }
    else
    {
        ui->infoLabel_->setText(QString("Video ok, image size is %1x%2 pixels").arg(width).arg(height));
    }
}

Webcam::~Webcam()
{
    delete ui;
    delete webCam_;
}

void Webcam::updateFrame()
{
    if (webCam_->isOpened()) {
        Mat image;
        if (webCam_->read(image)) {   // Capture a frame
            // Flip to get a mirror effect
            flip(image,image,1);
            // Invert Blue and Red color channels
            cvtColor(image,image,COLOR_BGR2RGB);
            // Convert to Qt image
            QImage img= QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
            // Display on label
            ui->webcamLabel_->setPixmap(QPixmap::fromImage(img));
            // Resize the label to fit the image
            ui->webcamLabel_->resize(ui->webcamLabel_->pixmap().size());
        }
        else {
            ui->infoLabel_->setText("Error capturing the frame");
        }
    }
}

void Webcam::on_captureButton_clicked()
{
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(updateFrame()));
    timer->start(100);
}

