#include "spacewidget.h"

const unsigned int WINDOW_SIZE = 650;
const float PI = 3.14159265359;
int Webcam::webcamDetector_ = 0;

SpaceWidget::SpaceWidget(int asteroidNumber, QWidget * parent) : QOpenGLWidget(parent){
    setFixedSize(WINDOW_SIZE, WINDOW_SIZE);

    asteroidNumber_ = asteroidNumber;

    for(int i = 0; i < asteroidNumber; i++){
        randX[i] = QRandomGenerator::global()->bounded(-300,300);
        randY[i] = QRandomGenerator::global()->bounded(-300,300);
        randZ[i] = QRandomGenerator::global()->bounded(-300,300);
        randRadius[i] = QRandomGenerator::global()->bounded(1,20);
    }
    randXStation = QRandomGenerator::global()->bounded(10,200);
    randYStation = QRandomGenerator::global()->bounded(10,200);
    randZStation = QRandomGenerator::global()->bounded(10,200);

    starship = new Starship(0,0,0,0,0);
    generateAsteroid(asteroidNumber_);
    station = new Station(randXStation,randYStation,randZStation,6);

    connect(&m_AnimationTimer,  &QTimer::timeout, [&]{
        m_TimeElapsed += 1.0f;
        update();
    });

    m_AnimationTimer.setInterval(20);
    m_AnimationTimer.start();
}

SpaceWidget::~SpaceWidget() {
    deleteAsteroid(asteroidNumber_);
    delete starship;
    delete station;
    delete result;
}

void SpaceWidget::initializeGL(){
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    GLfloat ambient_tab[] = { 1.f, 1.f, 1.f, 1.f};
    GLfloat diffuse_tab[] = { 1.f, 1.f, 1.f, 1.f};
    GLfloat specular_tab[] = { 1.f, 1.f, 1.f, 1.f};
    GLfloat light_tab[] = { 0.f, 0.f, 1.f, 0.f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_tab);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_tab);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_tab);
    glLightfv(GL_LIGHT0, GL_POSITION, light_tab);

    glEnable(GL_LIGHT1);
    GLfloat light_tab_station[] = { station->getX(), station->getY(), station->getZ(), 1.f};
    GLfloat direction_tab_station[] = { 0.0, 0.0, 1.0};
    GLfloat yellow_tab[] = {1.f,1.f,0.f,1.f};
    glLightfv(GL_LIGHT1,GL_POSITION,light_tab_station);
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,direction_tab_station);
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,5);

    if ((uint64_t)m_TimeElapsed%100 <50){

        glLightfv(GL_LIGHT1,GL_AMBIENT,yellow_tab);
        glLightfv(GL_LIGHT1,GL_DIFFUSE,yellow_tab);
        glLightfv(GL_LIGHT1,GL_SPECULAR,yellow_tab);
        }
    else{
        glDisable(GL_LIGHT1);
    }

    glEnable(GL_LIGHT2);
    GLfloat light_tab_starship[] = { starship->getX(), starship->getY(), starship->getZ(), 1.f};
    GLfloat direction_tab_starship[] = { 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT2,GL_POSITION,light_tab_starship);
    glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION,direction_tab_starship);
    glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,5);
}

void SpaceWidget::resizeGL(int width, int height){
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
       glFrustum(-5, 5, -5, 5, 2, 2000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SpaceWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  
    gluLookAt(starship->getX()+5*cos(starship->getTheta()*PI/180)*sin(starship->getPhi()*PI/180),
              3 + starship->getY()+5*sin(starship->getTheta()*PI/180),
              starship->getZ()+5*cos(starship->getPhi()*PI/180)*cos(starship->getTheta()*PI/180),
              starship->getX(),
              starship->getY(),
              starship->getZ(),
              0,
              cos(starship->getTheta()*PI/180),
              0);
    collisionDetection(asteroidNumber_);
    glPushMatrix();
    for(int i = 0; i < asteroidNumber_; i++){
        asteroidTab_[i]->display();
    }
    glPopMatrix();
    glPushMatrix();
    starship->display();
    glPopMatrix();
    glPushMatrix();
    station->display(m_TimeElapsed);
    glPopMatrix();
    qDebug() << Webcam::webcamDetector_;
    moveWithWebcam();
}

void SpaceWidget::keyPressEvent(QKeyEvent * keyEvent){
    float r;

    // Turn up
    if(keyEvent->key() == Qt::Key_Up)
    {
        starship->setTheta(starship->getTheta() + 2);
    }
    // Turn down
    if(keyEvent->key() == Qt::Key_Down)
    {
        starship->setTheta(starship->getTheta() - 2);
    }
    // Turn right
    if(keyEvent->key() == Qt::Key_Right)
    {
        starship->setPhi(starship->getPhi() - 2);
    }
    // Turn left
    if(keyEvent->key() == Qt::Key_Left)
    {
        starship->setPhi(starship->getPhi() + 2);
    }
    // Move backward
    if(keyEvent->key() == Qt::Key_S)
    {
        r = 5;
        starship->setX(starship->getX() + r*cos(starship->getTheta()*PI/180)*sin(starship->getPhi()*PI/180));
        starship->setZ(starship->getZ() + r*cos(starship->getTheta()*PI/180)*cos(starship->getPhi()*PI/180));
        starship->setY(starship->getY() + r*sin(starship->getTheta()*PI/180));
    }
    // Move forward
    if(keyEvent->key() == Qt::Key_Z)
    {
        r = -5;
        starship->setX(starship->getX() + r*cos(starship->getTheta()*PI/180)*sin(starship->getPhi()*PI/180));
        starship->setZ(starship->getZ() + r*cos(starship->getTheta()*PI/180)*cos(starship->getPhi()*PI/180));
        starship->setY(starship->getY() + r*sin(starship->getTheta()*PI/180));
    }

    if (starship->getTheta() == 360 || starship->getTheta() == -360){
        starship->setTheta(0);
    }

    if (starship->getPhi() == 360 || starship->getPhi() == -360){
        starship->setPhi(0);
    }
}

void SpaceWidget::moveWithWebcam(){
    float r;

    // Move forward
    if(Webcam::webcamDetector_ == 1000)
    {
        r = -5;
        starship->setX(starship->getX() + r*cos(starship->getTheta()*PI/180)*sin(starship->getPhi()*PI/180));
        starship->setZ(starship->getZ() + r*cos(starship->getTheta()*PI/180)*cos(starship->getPhi()*PI/180));
        starship->setY(starship->getY() + r*sin(starship->getTheta()*PI/180));
    }
    // Turn up
    if(Webcam::webcamDetector_ == 2000)
    {
        starship->setTheta(starship->getTheta() + 2);
    }
    // Turn down
    if(Webcam::webcamDetector_ == 3000)
    {
        starship->setTheta(starship->getTheta() - 2);
    }
    // Turn right
    if(Webcam::webcamDetector_ == 4000)
    {
        starship->setPhi(starship->getPhi() - 2);
    }
    // Turn left
    if(Webcam::webcamDetector_ == 5000)
    {
        starship->setPhi(starship->getPhi() + 2);
    }

    if (starship->getTheta() == 360 || starship->getTheta() == -360){
        starship->setTheta(0);
    }

    if (starship->getPhi() == 360 || starship->getPhi() == -360){
        starship->setPhi(0);
    }
}

void SpaceWidget::generateAsteroid(int asteroidNumber){
    for(int i = 0; i < asteroidNumber; i++){
        asteroidTab_[i] = new Asteroid(randX[i],randY[i],randZ[i],randRadius[i]);
    }
}

void SpaceWidget::deleteAsteroid(int asteroidNumber){
    for(int i = 0; i < asteroidNumber; i++){
        delete(asteroidTab_[i]);
    }
}

void SpaceWidget::collisionDetection(int asteroidNumber){
    int distance;
    for(int i = 0; i < asteroidNumber; i++){
        distance = sqrt((randX[i]-starship->getX())*(randX[i]-starship->getX())+
                        (randY[i]-starship->getY())*(randY[i]-starship->getY())+
                        (randZ[i]-starship->getZ())*(randZ[i]-starship->getZ()));
        if(distance < randRadius[i] + 18 && end_ == true){
            qDebug() << "Partie perdue";
            end_ = false;
            QTime currentTime = QTime::currentTime();
            int elapsedTime = startTime.msecsTo(currentTime);
            result = new Result("Partie perdue", QTime(0,0).addMSecs(elapsedTime).toString("mm:ss:z"));
            result->show();
        }
    }
    distance = sqrt((randXStation-starship->getX())*(randXStation-starship->getX())+
                    (randYStation-starship->getY())*(randYStation-starship->getY())+
                    (randZStation-starship->getZ())*(randZStation-starship->getZ()));
    if(distance < 6 + 18 && end_ == true){
        qDebug() << "Partie gagnée";
        end_ = false;
        QTime currentTime = QTime::currentTime();
        int elapsedTime = startTime.msecsTo(currentTime);
        result = new Result("Partie gagnée", QTime(0,0).addMSecs(elapsedTime).toString("mm:ss:z"));
        result->show();
    }
}
