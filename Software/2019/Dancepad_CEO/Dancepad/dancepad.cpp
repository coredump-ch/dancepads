#include "dancepad.h"
#include "ui_dancepad.h"

using namespace std;

Dancepad::Dancepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dancepad),
    mTag1(0),
    mTag2(0),
    mTag3(0),
    mTag4(0),
    mTag5(0)
{
    // set up main window
    ui->setupUi(this);

    // start main window maximized
    QWidget::showMaximized();

    // open first tab
    ui->tabWidget->setCurrentIndex(0);

    // configure value axes
    ui->plotWidget->yAxis->setTickLabels(false);
    connect(ui->plotWidget->yAxis2, SIGNAL(rangeChanged(QCPRange)), ui->plotWidget->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    ui->plotWidget->yAxis2->setVisible(true);
    ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(60);
    ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0)->setRange(0, 300); // add some padding to have space for tags

    // create graphs
    mGraph1 = ui->plotWidget->addGraph(ui->plotWidget->xAxis, ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph2 = ui->plotWidget->addGraph(ui->plotWidget->xAxis, ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph3 = ui->plotWidget->addGraph(ui->plotWidget->xAxis, ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph4 = ui->plotWidget->addGraph(ui->plotWidget->xAxis, ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph5 = ui->plotWidget->addGraph(ui->plotWidget->xAxis, ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph1->setPen(QPen(QColor(250, 0, 0)));
    mGraph2->setPen(QPen(QColor(250, 250, 0)));
    mGraph3->setPen(QPen(QColor(0, 250, 0)));
    mGraph4->setPen(QPen(QColor(0, 250, 250)));
    mGraph5->setPen(QPen(QColor(0, 0, 250)));
    mGraph1->setName("Piezo Sum");
    mGraph2->setName("Piezo 1");
    mGraph3->setName("Piezo 2");
    mGraph4->setName("Piezo 3");
    mGraph5->setName("Piezo 4");

    // create tags
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1->setPen(mGraph1->pen());
    mTag2 = new AxisTag(mGraph2->valueAxis());
    mTag2->setPen(mGraph2->pen());
    mTag3 = new AxisTag(mGraph3->valueAxis());
    mTag3->setPen(mGraph3->pen());
    mTag4 = new AxisTag(mGraph4->valueAxis());
    mTag4->setPen(mGraph4->pen());
    mTag5 = new AxisTag(mGraph5->valueAxis());
    mTag5->setPen(mGraph5->pen());

    // create legend
    ui->plotWidget->legend->setVisible(true);
    ui->plotWidget->legend->setRowSpacing(-3);

    // establish USB connection and initialize tiles
    handle = OpenUsbComm();
    SetRgbColor(handle, 0, 0, 0);

    // start execution timer
    connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    mDataTimer.start(executionTime);

    // initialize variables
    state = 0;
}

Dancepad::~Dancepad()
{
    delete ui;
}

void Dancepad::timerSlot()
{
    unsigned char piezoValues[5];

    // state machine
    switch(state)
    {
        // initial state
        case 0:
        {
             SetRgbColor(handle, 0, 0, 0);
        }
        break;

        // hue changing state
        case 1:
        {
            rgbColor = hsi2rgb(hue, 1, 0.1);
            SetRgbColor(handle, rgbColor.r, rgbColor.g, rgbColor.b);
            hue = hue + 1;
        }
        break;

        // plot trend
        case 2:
        {
            ReadPiezo(handle, piezoValues);
            plotValues(piezoValues);
        }
        break;

        // error state
        default:
        {
            rgbColor = hsi2rgb(0, 0, 0);
            hue = 0;
        }
    }
}

void Dancepad::plotValues(unsigned char* piezoData)
{
    // calculate and add a new data point to each graph
    mGraph1->addData(mGraph1->dataCount(), piezoData[0]);
    mGraph2->addData(mGraph2->dataCount(), piezoData[1]);
    mGraph3->addData(mGraph3->dataCount(), piezoData[2]);
    mGraph4->addData(mGraph4->dataCount(), piezoData[3]);
    mGraph5->addData(mGraph5->dataCount(), piezoData[4]);

    ui->plotWidget->xAxis->rescale();
    ui->plotWidget->xAxis->setRange(ui->plotWidget->xAxis->range().upper, 100, Qt::AlignRight);

    // update the vertical axis tag positions and texts to match the rightmost data point of the graphs
    double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
    double graph2Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    double graph3Value = mGraph3->dataMainValue(mGraph3->dataCount()-1);
    double graph4Value = mGraph4->dataMainValue(mGraph4->dataCount()-1);
    double graph5Value = mGraph5->dataMainValue(mGraph5->dataCount()-1);

    mTag1->updatePosition(graph1Value);
    mTag2->updatePosition(graph2Value);
    mTag3->updatePosition(graph3Value);
    mTag4->updatePosition(graph4Value);
    mTag5->updatePosition(graph5Value);

    mTag1->setText(QString::number(graph1Value, 'f', 2));
    mTag2->setText(QString::number(graph2Value, 'f', 2));
    mTag3->setText(QString::number(graph3Value, 'f', 2));
    mTag4->setText(QString::number(graph4Value, 'f', 2));
    mTag5->setText(QString::number(graph5Value, 'f', 2));

    ui->plotWidget->replot();
}

void Dancepad::on_pbChangeHue_clicked()
{
    // start hue changing, if it is stopped
    if(state == 1)
    {
        state = 0;
        ui->pbChangeHue->setText("Start");
    }
    // stop hue changing, if it is started
    else
    {
        state = 1;
        ui->pbChangeHue->setText("Stop");
    }
}

void Dancepad::on_pbTrendStart_clicked()
{
    // start trend plotting, if it is stopped
    if(state == 2)
    {
        state = 0;
        ui->pbTrendStart->setText("Start");
    }
    // stop trend plotting, if it is started
    else
    {
        state = 2;
        ui->pbTrendStart->setText("Stop");
    }
}
