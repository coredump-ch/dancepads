#include "dancepad.h"
#include "ui_dancepad.h"

Dancepad::Dancepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dancepad)
{
    ui->setupUi(this);

    QWidget::showMaximized();           // Start main window maximized.

    ui->tabWidget->setCurrentIndex(0);  // Start the first tab.
}

Dancepad::~Dancepad()
{
    delete ui;
}
