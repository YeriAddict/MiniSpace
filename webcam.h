#ifndef WEBCAM_H
#define WEBCAM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Webcam; }
QT_END_NAMESPACE

class Webcam : public QWidget
{
    Q_OBJECT

public:
    Webcam(QWidget *parent = nullptr);
    ~Webcam();

private:
    Ui::Webcam *ui;
};
#endif // WEBCAM_H
