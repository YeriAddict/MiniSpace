#include "spacewidget.h"

const unsigned int WINDOW_SIZE = 650;
const float PI = 3.14159265359;

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
    GLfloat light_tab_station[] = { 30.f, 30.f, 30.f, 1.f};
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
}

void SpaceWidget::keyPressEvent(QKeyEvent * keyEvent)
{
    if(keyEvent->key() == Qt::Key_Q)
    {
        //starship->setX(starship->getX() - 3);
        starship->setPhi(starship->getPhi() + 2);
    }
    if(keyEvent->key() == Qt::Key_D)
    {
        //starship->setX(starship->getX() + 3);
        starship->setPhi(starship->getPhi() - 2);
    }
    if(keyEvent->key() == Qt::Key_S)
    {
        //starship->setY(starship->getY() + 3);
        starship->setTheta(starship->getTheta() - 2);
    }
    if(keyEvent->key() == Qt::Key_Z)
    {
        //starship->setY(starship->getY() - 3);
        starship->setTheta(starship->getTheta() + 2);
    }
    if(keyEvent->key() == Qt::Key_E)
    {
        starship->setZ(starship->getZ() - 5);
    }
    if(keyEvent->key() == Qt::Key_R)
    {
        starship->setZ(starship->getZ() + 5);
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
