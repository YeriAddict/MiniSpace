#include <QApplication>
#include "webcam.h"
#include "spacewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpaceWidget spaceWidget;
    spaceWidget.show();
//    Webcam w;
//    w.show();
    return a.exec();
}
