#include "dancepad.h"
#include "ui_dancepad.h"

using namespace std;

Dancepad::Dancepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dancepad)
{
    // Set up main window
    ui->setupUi(this);

    // Start main window maximized
    QWidget::showMaximized();

    // Open first tab
    ui->tabWidget->setCurrentIndex(0);

    // Establish USB connection and initialize tiles
    handle = OpenUsbComm();
    SetRgbColor(handle, 0, 0, 0);

    // Start execution timer
    connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    mDataTimer.start(executionTime);

    // Initialize variables
    state = 0;
}

Dancepad::~Dancepad()
{
    delete ui;
}

void Dancepad::on_pbChangeHue_clicked()
{
    // Start hue changing, if it is stopped
    if(state == 1)
    {
        state = 0;
        ui->pbChangeHue->setText("Start");
    }
    // Stop hue changing, if it is started
    else
    {
        state = 1;
        ui->pbChangeHue->setText("Stop");
    }
}

void Dancepad::timerSlot()
{
    // State machine
    switch(state)
    {
        // Initial state
        case 0:
        {
             SetRgbColor(handle, 0, 0, 0);
        }
        break;

        // Hue changing state
        case 1:
        {
            rgbColor = hsi2rgb(hue, 1, 0.1);
            SetRgbColor(handle, rgbColor.r, rgbColor.g, rgbColor.b);
            hue = hue + 1;
        }
        break;

        // Error state
        default:
        {
            rgbColor = hsi2rgb(0, 0, 0);
            hue = 0;
        }
    }
}
