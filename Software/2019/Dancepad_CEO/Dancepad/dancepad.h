#ifndef DANCEPAD_H
#define DANCEPAD_H

#include <QMainWindow>
#include <iostream>
#include "qcustomplot.h"
#include "axistag.h"
#include "hsi.h"
#include "mcp2221_dll_um.h"
#include "USB_Communication.h"
#include "DP_Communication.h"

#define executionTime 10

//QT_BEGIN_NAMESPACE
namespace Ui { class Dancepad; }
//QT_END_NAMESPACE

class Dancepad : public QMainWindow
{
    Q_OBJECT

public:
    Dancepad(QWidget *parent = nullptr);
    ~Dancepad();

private slots:
    void timerSlot();
    void on_pbChangeHue_clicked();

private:
    Ui::Dancepad *ui;
    QTimer mDataTimer;
    RGB rgbColor;
    void* handle;
    float hue = 0;
    unsigned int state = 0;
};
#endif // DANCEPAD_H
