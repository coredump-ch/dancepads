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

    // enable mousetrack
    setMouseTracking(true);
    ui->plotWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    connect(ui->plotWidget, &QCustomPlot::mousePress, this, &Dancepad::mouseButton);
    connect(ui->plotWidget, &QCustomPlot::mouseWheel, this, &Dancepad::mouseButton);

    // configure plot
    setupPlot();

    // establish USB connection and initialize tiles
    handle = OpenUsbComm();
    rgbColor = hsi2rgb(hue, saturation, intensity);
    SetRgbColor(handle, uchar(rgbColor.r), uchar(rgbColor.g), uchar(rgbColor.b));

    // start execution timer
    connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    mDataTimer.start(executionTime);

    // initialize variables
    state = 0;

    // initialize color widgets
    initColor();
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
        }
        break;

        // color changing state
        case 1:
        {
            colorChangingState();
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
        }
    }
}

//****************************************************************************************
// Trend plot page:
//****************************************************************************************

void Dancepad::setupPlot()
{
    // initializing variables
    replotPlot = 1;
    rescalePlot = 1;
    firstPlotValue = 1;

    // configure value axes
    ui->plotWidget->yAxis->setTickLabels(false);
    connect(ui->plotWidget->yAxis2, SIGNAL(rangeChanged(QCPRange)), ui->plotWidget->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    ui->plotWidget->yAxis2->setVisible(true);
    ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(60);
    ui->plotWidget->axisRect()->axis(QCPAxis::atRight, 0)->setRange(0, 300); // add some padding to have space for tags

    // create graphs
    mGraph1 = ui->plotWidget->addGraph();
    mGraph2 = ui->plotWidget->addGraph();
    mGraph3 = ui->plotWidget->addGraph();
    mGraph4 = ui->plotWidget->addGraph();
    mGraph5 = ui->plotWidget->addGraph();
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
}

void Dancepad::plotValues(unsigned char* piezoData)
{
    ct = QDateTime::currentDateTime();
    if (firstPlotValue == 1)
    {
        timeStart = ct.toMSecsSinceEpoch() / 1000.0;
        firstPlotValue = 0;
    }
    time = ct.toMSecsSinceEpoch() / 1000.0;

    // calculate and add a new data point to each graph
    mGraph1->addData(time-timeStart, piezoData[0]);
    mGraph2->addData(time-timeStart, piezoData[1]);
    mGraph3->addData(time-timeStart, piezoData[2]);
    mGraph4->addData(time-timeStart, piezoData[3]);
    mGraph5->addData(time-timeStart, piezoData[4]);


    if(replotPlot && rescalePlot)
    {
        ui->plotWidget->yAxis->setRange(0, 300);
        ui->plotWidget->xAxis->rescale();
        ui->plotWidget->xAxis->setRange(ui->plotWidget->xAxis->range().upper, 10, Qt::AlignRight);
        plotUpperPosition = ui->plotWidget->xAxis->range().upper;
        plotLowerPosition = ui->plotWidget->xAxis->range().lower;
    }
    else if (replotPlot)
    {
        ui->plotWidget->xAxis->rescale();
        ui->plotWidget->xAxis->setRange(ui->plotWidget->xAxis->range().upper, (plotUpperPosition-plotLowerPosition), Qt::AlignRight);
    }
    else if (rescalePlot)
    {
        ui->plotWidget->yAxis->setRange(0, 300);
        ui->plotWidget->xAxis->setRange((plotUpperPosition+plotLowerPosition)/2+5, 10, Qt::AlignRight);
    }
    else if (!replotPlot && !rescalePlot)
    {
        plotUpperPosition = ui->plotWidget->xAxis->range().upper;
        plotLowerPosition = ui->plotWidget->xAxis->range().lower;
    }

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

void Dancepad::mouseButton()
{
    rescalePlot = 0;
    replotPlot = 0;
    ui->pbTrendRun->setText("Move Time");
}

void Dancepad::on_pbTrendStart_clicked()
{
    // start data recording, if it is stopped
    if(state == 2)
    {
        state = 0;
        ui->pbTrendStart->setText("Start Data Record");
    }
    // stop data recording, if it is started
    else
    {
        state = 2;
        ui->pbTrendStart->setText("Pause Data Record");
    }
}

void Dancepad::on_pbTrendRun_clicked()
{
    // start data recording, if it is stopped
    if(replotPlot == 1)
    {
        replotPlot = 0;
        ui->pbTrendRun->setText("Move Time");
    }
    // stop data recording, if it is started
    else
    {
        replotPlot = 1;
        ui->pbTrendRun->setText("Pause Time");
    }
}

void Dancepad::on_pbTrend100Percent_clicked()
{
    rescalePlot = 1;
}


//****************************************************************************************
// Color changing page:
//****************************************************************************************
void Dancepad::initColor()
{
    ui->inHue->setValue(int(hue));
    ui->sbHue->setValue(int(hue));
    ui->sbSaturation->setValue(int(100*saturation));
    ui->inSaturation->setValue(double(saturation));
    ui->sbIntensity->setValue(int(100*intensity));
    ui->inIntensity->setValue(double(intensity));

    ui->sbRed->setValue(rgbColor.r);
    ui->inRed->setValue(rgbColor.r);
    ui->sbGreen->setValue(rgbColor.g);
    ui->inGreen->setValue(rgbColor.g);
    ui->sbBlue->setValue(rgbColor.b);
    ui->inBlue->setValue(rgbColor.b);
}

void Dancepad::colorChangingState()
{
    // state machine
    switch(colorState)
    {
        // sweep hue
        case 0:
        {
            hue = hue + 1;
            if (hue >= 361)
            {
                hue = 0;
            }

            rgbChanged = 0;
            updateColor();

            ui->inHue->setValue(int(hue));
            ui->sbHue->setValue(int(hue));
        }
        break;

        // sweep saturation
        case 1:
        {
            saturation = saturation + 0.01f;
            if (saturation >= 1.01f)
            {
                saturation = 0;
            }

            rgbChanged = 0;
            updateColor();

            ui->inSaturation->setValue(int(saturation));
            ui->sbSaturation->setValue(int(100*saturation));
        }
        break;

        // sweep intensity
        case 2:
        {
            intensity = intensity +  0.01f;
            if (intensity >= 1.01f)
            {
                intensity = 0;
            }

            rgbChanged = 0;
            updateColor();

            ui->inIntensity->setValue(int(intensity));
            ui->sbIntensity->setValue(int(100*intensity));
        }
        break;

        // sweep red
        case 3:
        {
            rgbColor.r = rgbColor.r +  1;
            if (rgbColor.r >= 256)
            {
                rgbColor.r = 0;
            }

            rgbChanged = 1;
            updateColor();

            ui->inRed->setValue(rgbColor.r);
            ui->sbRed->setValue(rgbColor.r);
        }
        break;

        // sweep green
        case 4:
        {
            rgbColor.g = rgbColor.g +  1;
            if (rgbColor.g >= 256)
            {
                rgbColor.g = 0;
            }

            rgbChanged = 1;
            updateColor();

            ui->inGreen->setValue(rgbColor.g);
            ui->sbGreen->setValue(rgbColor.g);
        }
        break;

        // sweep blue
        case 5:
        {
            rgbColor.b = rgbColor.b +  1;
            if (rgbColor.b >= 256)
            {
                rgbColor.b = 0;
            }

            rgbChanged = 1;
            updateColor();

            ui->inBlue->setValue(rgbColor.b);
            ui->sbBlue->setValue(rgbColor.b);
        }
        break;

        // error state
        default:
        {
        }
    }
}

void Dancepad::updateColor()
{
    if(rgbChanged == 0)
    {
        rgbColor = hsi2rgb(hue, saturation, intensity);
        ui->sbRed->setValue(rgbColor.r);
        ui->inRed->setValue(rgbColor.r);
        ui->sbGreen->setValue(rgbColor.g);
        ui->inGreen->setValue(rgbColor.g);
        ui->sbBlue->setValue(rgbColor.b);
        ui->inBlue->setValue(rgbColor.b);
    }
    if (rgbChanged == 1)
    {
        hsiColor = rgb2hsi(rgbColor.r, rgbColor.g, rgbColor.b);
        hue = hsiColor.h;
        intensity = hsiColor.i;
        saturation = hsiColor.s;

        ui->sbHue->setValue(int(hue));
        ui->inHue->setValue(int(hue));
        ui->sbSaturation->setValue(int(100*saturation));
        ui->inSaturation->setValue(double(saturation));
        ui->sbIntensity->setValue(int(100*intensity));
        ui->inIntensity->setValue(double(intensity));
    }

    SetRgbColor(handle, uchar(rgbColor.r), uchar(rgbColor.g), uchar(rgbColor.b));
    cout << "hue: " << hue << ", saturation: " << saturation << ", intensity: " << intensity << endl;
    cout << "red: " << rgbColor.r << ", green: " << rgbColor.g << ", blue: " << rgbColor.b << endl;
}


void Dancepad::on_pbSweepHue_clicked()
{
    // start hue changing, if it is stopped
    if(state == 1)
    {
        rgbChanged = 0;
        state = 0;
        ui->pbSweepHue->setText("Sweep");

        ui->pbSweepSaturation->setEnabled(true);
        ui->pbSweepIntensity->setEnabled(true);
        ui->inRed->setEnabled(true);
        ui->pbSweepRed->setEnabled(true);
        ui->inGreen->setEnabled(true);
        ui->pbSweepGreen->setEnabled(true);
        ui->inBlue->setEnabled(true);
        ui->pbSweepBlue->setEnabled(true);
    }
    // stop hue changing, if it is started
    else
    {
        state = 1;
        colorState = 0;
        ui->pbSweepHue->setText("Stop");

        ui->pbSweepSaturation->setEnabled(false);
        ui->pbSweepIntensity->setEnabled(false);
        ui->inRed->setEnabled(false);
        ui->pbSweepRed->setEnabled(false);
        ui->inGreen->setEnabled(false);
        ui->pbSweepGreen->setEnabled(false);
        ui->inBlue->setEnabled(false);
        ui->pbSweepBlue->setEnabled(false);
    }
}

void Dancepad::on_pbSweepSaturation_clicked()
{
    // start saturation changing, if it is stopped
    if(state == 1)
    {
        rgbChanged = 0;
        state = 0;
        ui->pbSweepSaturation->setText("Sweep");

        ui->pbSweepHue->setEnabled(true);
        ui->pbSweepIntensity->setEnabled(true);
        ui->inRed->setEnabled(true);
        ui->pbSweepRed->setEnabled(true);
        ui->inGreen->setEnabled(true);
        ui->pbSweepGreen->setEnabled(true);
        ui->inBlue->setEnabled(true);
        ui->pbSweepBlue->setEnabled(true);
    }
    // stop saturation changing, if it is started
    else
    {
        state = 1;
        colorState = 1;
        ui->pbSweepSaturation->setText("Stop");

        ui->pbSweepHue->setEnabled(false);
        ui->pbSweepIntensity->setEnabled(false);
        ui->inRed->setEnabled(false);
        ui->pbSweepRed->setEnabled(false);
        ui->inGreen->setEnabled(false);
        ui->pbSweepGreen->setEnabled(false);
        ui->inBlue->setEnabled(false);
        ui->pbSweepBlue->setEnabled(false);
    }
}

void Dancepad::on_pbSweepIntensity_clicked()
{
    // start intensity changing, if it is stopped
    if(state == 1)
    {
        rgbChanged = 0;
        state = 0;
        ui->pbSweepIntensity->setText("Sweep");

        ui->pbSweepHue->setEnabled(true);
        ui->pbSweepSaturation->setEnabled(true);
        ui->inRed->setEnabled(true);
        ui->pbSweepRed->setEnabled(true);
        ui->inGreen->setEnabled(true);
        ui->pbSweepGreen->setEnabled(true);
        ui->inBlue->setEnabled(true);
        ui->pbSweepBlue->setEnabled(true);
    }
    // stop intensity changing, if it is started
    else
    {
        state = 1;
        colorState = 2;
        ui->pbSweepIntensity->setText("Stop");

        ui->pbSweepHue->setEnabled(false);
        ui->pbSweepSaturation->setEnabled(false);
        ui->inRed->setEnabled(false);
        ui->pbSweepRed->setEnabled(false);
        ui->inGreen->setEnabled(false);
        ui->pbSweepGreen->setEnabled(false);
        ui->inBlue->setEnabled(false);
        ui->pbSweepBlue->setEnabled(false);
    }
}

void Dancepad::on_pbSweepRed_clicked()
{
    // start red changing, if it is stopped
    if(state == 1)
    {
        rgbChanged = 1;
        state = 0;
        ui->pbSweepRed->setText("Sweep");

        ui->inHue->setEnabled(true);
        ui->pbSweepHue->setEnabled(true);
        ui->inSaturation->setEnabled(true);
        ui->pbSweepSaturation->setEnabled(true);
        ui->inIntensity->setEnabled(true);
        ui->pbSweepIntensity->setEnabled(true);
        ui->pbSweepGreen->setEnabled(true);
        ui->pbSweepBlue->setEnabled(true);
    }
    // stop red changing, if it is started
    else
    {
        rgbChanged = 0;
        state = 1;
        colorState = 3;
        ui->pbSweepRed->setText("Stop");

        ui->inHue->setEnabled(false);
        ui->pbSweepHue->setEnabled(false);
        ui->inSaturation->setEnabled(false);
        ui->pbSweepSaturation->setEnabled(false);
        ui->inIntensity->setEnabled(false);
        ui->pbSweepIntensity->setEnabled(false);
        ui->pbSweepGreen->setEnabled(false);
        ui->pbSweepBlue->setEnabled(false);
    }
}

void Dancepad::on_pbSweepGreen_clicked()
{
    // start green changing, if it is stopped
    if(state == 1)
    {
        rgbChanged = 1;
        state = 0;
        ui->pbSweepGreen->setText("Sweep");

        ui->inHue->setEnabled(true);
        ui->pbSweepHue->setEnabled(true);
        ui->inSaturation->setEnabled(true);
        ui->pbSweepSaturation->setEnabled(true);
        ui->inIntensity->setEnabled(true);
        ui->pbSweepIntensity->setEnabled(true);
        ui->pbSweepRed->setEnabled(true);
        ui->pbSweepBlue->setEnabled(true);
    }
    // stop green changing, if it is started
    else
    {
        rgbChanged = 0;
        state = 1;
        colorState = 4;
        ui->pbSweepGreen->setText("Stop");

        ui->inHue->setEnabled(false);
        ui->pbSweepHue->setEnabled(false);
        ui->inSaturation->setEnabled(false);
        ui->pbSweepSaturation->setEnabled(false);
        ui->inIntensity->setEnabled(false);
        ui->pbSweepIntensity->setEnabled(false);
        ui->pbSweepRed->setEnabled(false);
        ui->pbSweepBlue->setEnabled(false);
    }
}

void Dancepad::on_pbSweepBlue_clicked()
{
    // start blue changing, if it is stopped
    if(state == 1)
    {
        rgbChanged = 1;
        state = 0;
        ui->pbSweepBlue->setText("Sweep");

        ui->inHue->setEnabled(true);
        ui->pbSweepHue->setEnabled(true);
        ui->inSaturation->setEnabled(true);
        ui->pbSweepSaturation->setEnabled(true);
        ui->inIntensity->setEnabled(true);
        ui->pbSweepIntensity->setEnabled(true);
        ui->pbSweepRed->setEnabled(true);
        ui->pbSweepGreen->setEnabled(true);
    }
    // stop blue changing, if it is started
    else
    {
        rgbChanged = 0;
        state = 1;
        colorState = 5;
        ui->pbSweepBlue->setText("Stop");

        ui->inHue->setEnabled(false);
        ui->pbSweepHue->setEnabled(false);
        ui->inSaturation->setEnabled(false);
        ui->pbSweepSaturation->setEnabled(false);
        ui->inIntensity->setEnabled(false);
        ui->pbSweepIntensity->setEnabled(false);
        ui->pbSweepRed->setEnabled(false);
        ui->pbSweepGreen->setEnabled(false);
    }
}

void Dancepad::on_inHue_editingFinished()
{
    hue = float(ui->inHue->value());
    rgbChanged = 0;
    ui->sbHue->setValue(int(hue));
    updateColor();
}

void Dancepad::on_sbHue_actionTriggered(int action)
{
    hue = float(ui->sbHue->value());
    rgbChanged = 0;
    ui->inHue->setValue(int(hue));
    updateColor();
}

void Dancepad::on_inSaturation_editingFinished()
{
    saturation = float(ui->inSaturation->value());
    rgbChanged = 0;
    ui->sbSaturation->setValue(int(100*saturation));
    updateColor();
}

void Dancepad::on_sbSaturation_actionTriggered(int action)
{
    saturation = float(ui->sbSaturation->value())/100;
    rgbChanged = 0;
    ui->inSaturation->setValue(double(saturation));
    updateColor();
}

void Dancepad::on_inIntensity_editingFinished()
{
    intensity = float(ui->inIntensity->value());
    rgbChanged = 0;
    ui->sbIntensity->setValue(int(100*intensity));
    updateColor();
}

void Dancepad::on_sbIntensity_actionTriggered(int action)
{
    intensity = float(ui->sbIntensity->value())/100;
    rgbChanged = 0;
    updateColor();
    ui->inIntensity->setValue(double(intensity));
}

void Dancepad::on_inRed_editingFinished()
{
    rgbColor.r = ui->inRed->value();
    rgbChanged = 1;
    ui->sbRed->setValue(rgbColor.r);
    updateColor();
}

void Dancepad::on_sbRed_actionTriggered(int action)
{
    rgbColor.r = ui->sbRed->value();
    rgbChanged = 1;
    ui->inRed->setValue(rgbColor.r);
    updateColor();
}

void Dancepad::on_inGreen_editingFinished()
{
    rgbColor.g = ui->inGreen->value();
    rgbChanged = 1;
    ui->sbGreen->setValue(rgbColor.g);
    updateColor();
}

void Dancepad::on_sbGreen_actionTriggered(int action)
{
    rgbColor.g = ui->sbGreen->value();
    rgbChanged = 1;
    ui->inGreen->setValue(rgbColor.g);
    updateColor();
}

void Dancepad::on_inBlue_editingFinished()
{
    rgbColor.b = ui->inBlue->value();
    rgbChanged = 1;
    ui->sbBlue->setValue(rgbColor.b);
    updateColor();
}

void Dancepad::on_sbBlue_actionTriggered(int action)
{
    rgbColor.b = ui->sbBlue->value();
    rgbChanged = 1;
    ui->inBlue->setValue(rgbColor.b);
    updateColor();
}
