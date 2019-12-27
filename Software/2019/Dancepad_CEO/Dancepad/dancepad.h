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
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTime>
#include <QDateTime>

#define executionTime 10

// define states of main state machine
#define DISCONNECTED 0
#define LIFELEDSYNCH 1
#define RAINBOW 2
#define FREERUN 3
#define COLORCHANGE 4
#define PLOT 5


// define states of color changing state machine
#define SWEEPHUE 0
#define SWEEPSATURATION 1
#define SWEEPINTENSITY 2
#define SWEEPRED 3
#define SWEEPGREEN 4
#define SWEEPBLUE 5

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
    void on_pbSweepHue_clicked();
    void on_pbTrendStart_clicked();
    void on_pbTrendRun_clicked();
    void on_pbTrend100Percent_clicked();
    void mouseButton();
    void on_inHue_editingFinished();
    void on_sbHue_actionTriggered(int action);
    void on_inSaturation_editingFinished();
    void on_sbSaturation_actionTriggered(int action);
    void on_inIntensity_editingFinished();
    void on_sbIntensity_actionTriggered(int action);
    void initColor();
    void colorChangingState();
    void updateColor();
    void on_pbSweepSaturation_clicked();
    void on_pbSweepIntensity_clicked();
    void on_sbRed_actionTriggered(int action);
    void on_inRed_editingFinished();
    void on_inGreen_editingFinished();
    void on_sbGreen_actionTriggered(int action);
    void on_inBlue_editingFinished();
    void on_sbBlue_actionTriggered(int action);
    void on_pbSweepRed_clicked();
    void on_pbSweepGreen_clicked();
    void on_pbSweepBlue_clicked();
    void on_pbUsbConn_clicked();
    void on_pbLifeLed_clicked();

private:
    Ui::Dancepad *ui;
    QTimer mDataTimer;
    QDateTime ct;
    RGB rgbColor;
    HSI hsiColor;
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
    bool firstPlotValue;
    bool rgbChanged = 0;
    bool usbConnected = 0;
    bool lifeLED = 0;
    unsigned int state = DISCONNECTED;
    unsigned int colorState = SWEEPHUE;
    unsigned int synchCount = 0;
    int error = 0;
    float hue = 0;
    float saturation = 1.0;
    float intensity = 0.01;
    double plotUpperXPosition = 0;
    double plotLowerXPosition = 0;
    double plotUpperYPosition = 0;
    double plotLowerYPosition = 0;
    double time;
    double timeStart;

    // functions
    void plotValues(unsigned char* piezoData);
    void setupPlot();
};
#endif // DANCEPAD_H
