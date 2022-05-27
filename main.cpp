#include <QApplication>
#include "game.h"
#include "menu.h"
#include "webcam.h"
#include "spacewidget.h"

int main(int argc, char *argv[])
{
    // Creation de l'application QT
    QApplication app(argc, argv);

    //SpaceWidget spaceWidget;
    //spaceWidget.show();
    //Menu m;
    //m.show();
    //Webcam w;
    //w.show();
    Game g;
    g.show();

    return app.exec();
}
