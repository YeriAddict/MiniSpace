#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class Result; }
QT_END_NAMESPACE

#pragma once
class Result : public QWidget {
    Q_OBJECT

public:
    Result(QString result, QString time, QWidget *parent = nullptr);
    ~Result();

private:
    Ui::Result *ui;

private slots:
    void restart();
    void quit();
};

#endif // RESULT_H
