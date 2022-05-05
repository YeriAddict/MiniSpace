#include <QApplication>
#include "webcam.h"
#include "spacewidget.h"

int main(int argc, char *argv[])
{
    // Creation de l'application QT
    QApplication app(argc, argv);

    // Creation du widget opengl
    SpaceWidget spaceWidget;
    spaceWidget.show();
    //    Webcam w;
    //    w.show();

    // Execution de l'application QT
    return app.exec();
}
