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

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QDebug>
#include <QImage>
#include <QImageReader>
#include <QApplication>
#include <QDesktopWidget>

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
    void on_pbTrendStart_clicked();

private:
    Ui::Dancepad *ui;
//    QCustomPlot *mPlot;
    QTimer mDataTimer;
    RGB rgbColor;
    QPointer<QCPGraph> mGraph1;
    QPointer<QCPGraph> mGraph2;
    QPointer<QCPGraph> mGraph3;
    QPointer<QCPGraph> mGraph4;
    QPointer<QCPGraph> mGraph5;
    AxisTag *mTag1;
    AxisTag *mTag2;
    AxisTag *mTag3;
    AxisTag *mTag4;
    AxisTag *mTag5;
    QCPItemText *textLabel1;
    QCPItemText *textLabel2;
    void* handle;
    float hue = 0;
    unsigned int state = 0;

    // functions
    void plotValues(unsigned char* piezoData);
    void mousePress();
    void mouseWheel();
};
#endif // DANCEPAD_H
