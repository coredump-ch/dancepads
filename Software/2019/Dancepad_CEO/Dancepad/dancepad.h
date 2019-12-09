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

#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QDebug>
#include <QImage>
#include <QImageReader>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>

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
    void on_pbTrendRun_clicked();
    void on_pbTrend100Percent_clicked();
    void mouseButton();
//    void mouseWheel();

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
    bool replotPlot;
    bool rescalePlot;
    float hue = 0;
    unsigned int state = 0;

    // functions
    void plotValues(unsigned char* piezoData);
    void setupPlot();
};
#endif // DANCEPAD_H
