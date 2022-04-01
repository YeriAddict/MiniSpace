#include "webcam.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Webcam w;
    w.show();
    return a.exec();
}
