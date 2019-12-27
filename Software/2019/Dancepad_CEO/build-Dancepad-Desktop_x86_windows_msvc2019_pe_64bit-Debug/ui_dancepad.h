/********************************************************************************
** Form generated from reading UI file 'dancepad.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DANCEPAD_H
#define UI_DANCEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dancepad
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_2;
    QLabel *lblTitel;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblUsbConn;
    QLabel *lblLifeLed;
    QLabel *lblRainbow;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pbUsbConn;
    QPushButton *pbLifeLed;
    QPushButton *pbRainbow;
    QWidget *tab_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbTrendStart;
    QPushButton *pbTrendRun;
    QPushButton *pbTrend100Percent;
    QSpacerItem *horizontalSpacer;
    QCustomPlot *plotWidget;
    QWidget *tab_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QPushButton *pbSweepHue;
    QScrollBar *sbHue;
    QSpinBox *inHue;
    QLabel *lblHue;
    QGridLayout *gridLayout_4;
    QLabel *lblSaturation;
    QScrollBar *sbSaturation;
    QPushButton *pbSweepSaturation;
    QDoubleSpinBox *inSaturation;
    QGridLayout *gridLayout_7;
    QPushButton *pbSweepIntensity;
    QLabel *lblIntensity;
    QScrollBar *sbIntensity;
    QDoubleSpinBox *inIntensity;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_5;
    QLabel *lblRed;
    QPushButton *pbSweepRed;
    QScrollBar *sbRed;
    QSpinBox *inRed;
    QGridLayout *gridLayout_6;
    QPushButton *pbSweepGreen;
    QSpinBox *inGreen;
    QScrollBar *sbGreen;
    QLabel *lblGreen;
    QGridLayout *gridLayout_8;
    QScrollBar *sbBlue;
    QPushButton *pbSweepBlue;
    QLabel *lblBlue;
    QSpinBox *inBlue;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuDancepad;

    void setupUi(QMainWindow *Dancepad)
    {
        if (Dancepad->objectName().isEmpty())
            Dancepad->setObjectName(QString::fromUtf8("Dancepad"));
        Dancepad->resize(800, 600);
        centralwidget = new QWidget(Dancepad);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        tab_1->setContextMenuPolicy(Qt::CustomContextMenu);
        gridLayout_2 = new QGridLayout(tab_1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblTitel = new QLabel(tab_1);
        lblTitel->setObjectName(QString::fromUtf8("lblTitel"));
        QFont font;
        font.setPointSize(72);
        lblTitel->setFont(font);
        lblTitel->setLayoutDirection(Qt::LeftToRight);
        lblTitel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblTitel, 0, 0, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 212, 85));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lblUsbConn = new QLabel(layoutWidget);
        lblUsbConn->setObjectName(QString::fromUtf8("lblUsbConn"));

        verticalLayout_5->addWidget(lblUsbConn);

        lblLifeLed = new QLabel(layoutWidget);
        lblLifeLed->setObjectName(QString::fromUtf8("lblLifeLed"));

        verticalLayout_5->addWidget(lblLifeLed);

        lblRainbow = new QLabel(layoutWidget);
        lblRainbow->setObjectName(QString::fromUtf8("lblRainbow"));

        verticalLayout_5->addWidget(lblRainbow);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pbUsbConn = new QPushButton(layoutWidget);
        pbUsbConn->setObjectName(QString::fromUtf8("pbUsbConn"));

        verticalLayout_4->addWidget(pbUsbConn);

        pbLifeLed = new QPushButton(layoutWidget);
        pbLifeLed->setObjectName(QString::fromUtf8("pbLifeLed"));

        verticalLayout_4->addWidget(pbLifeLed);

        pbRainbow = new QPushButton(layoutWidget);
        pbRainbow->setObjectName(QString::fromUtf8("pbRainbow"));

        verticalLayout_4->addWidget(pbRainbow);


        horizontalLayout_2->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout = new QGridLayout(tab_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbTrendStart = new QPushButton(tab_3);
        pbTrendStart->setObjectName(QString::fromUtf8("pbTrendStart"));
        pbTrendStart->setMaximumSize(QSize(100, 23));

        horizontalLayout->addWidget(pbTrendStart);

        pbTrendRun = new QPushButton(tab_3);
        pbTrendRun->setObjectName(QString::fromUtf8("pbTrendRun"));
        pbTrendRun->setMaximumSize(QSize(100, 23));

        horizontalLayout->addWidget(pbTrendRun);

        pbTrend100Percent = new QPushButton(tab_3);
        pbTrend100Percent->setObjectName(QString::fromUtf8("pbTrend100Percent"));
        pbTrend100Percent->setMaximumSize(QSize(100, 23));

        horizontalLayout->addWidget(pbTrend100Percent);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        plotWidget = new QCustomPlot(tab_3);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plotWidget->sizePolicy().hasHeightForWidth());
        plotWidget->setSizePolicy(sizePolicy);
        plotWidget->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(plotWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        layoutWidget1 = new QWidget(tab_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 441, 89));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pbSweepHue = new QPushButton(layoutWidget1);
        pbSweepHue->setObjectName(QString::fromUtf8("pbSweepHue"));
        pbSweepHue->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(pbSweepHue, 0, 3, 1, 1);

        sbHue = new QScrollBar(layoutWidget1);
        sbHue->setObjectName(QString::fromUtf8("sbHue"));
        sbHue->setMaximum(360);
        sbHue->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(sbHue, 0, 2, 1, 1);

        inHue = new QSpinBox(layoutWidget1);
        inHue->setObjectName(QString::fromUtf8("inHue"));
        inHue->setMaximumSize(QSize(50, 16777215));
        inHue->setFrame(true);
        inHue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inHue->setKeyboardTracking(true);
        inHue->setMaximum(360);

        gridLayout_3->addWidget(inHue, 0, 1, 1, 1);

        lblHue = new QLabel(layoutWidget1);
        lblHue->setObjectName(QString::fromUtf8("lblHue"));
        lblHue->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(lblHue, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lblSaturation = new QLabel(layoutWidget1);
        lblSaturation->setObjectName(QString::fromUtf8("lblSaturation"));
        lblSaturation->setMaximumSize(QSize(60, 16777215));

        gridLayout_4->addWidget(lblSaturation, 0, 0, 1, 1);

        sbSaturation = new QScrollBar(layoutWidget1);
        sbSaturation->setObjectName(QString::fromUtf8("sbSaturation"));
        sbSaturation->setMaximum(100);
        sbSaturation->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(sbSaturation, 0, 2, 1, 1);

        pbSweepSaturation = new QPushButton(layoutWidget1);
        pbSweepSaturation->setObjectName(QString::fromUtf8("pbSweepSaturation"));
        pbSweepSaturation->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(pbSweepSaturation, 0, 3, 1, 1);

        inSaturation = new QDoubleSpinBox(layoutWidget1);
        inSaturation->setObjectName(QString::fromUtf8("inSaturation"));
        inSaturation->setMaximumSize(QSize(50, 16777215));
        inSaturation->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inSaturation->setMaximum(1.000000000000000);
        inSaturation->setSingleStep(0.010000000000000);
        inSaturation->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout_4->addWidget(inSaturation, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pbSweepIntensity = new QPushButton(layoutWidget1);
        pbSweepIntensity->setObjectName(QString::fromUtf8("pbSweepIntensity"));
        pbSweepIntensity->setEnabled(true);
        pbSweepIntensity->setMaximumSize(QSize(50, 16777215));

        gridLayout_7->addWidget(pbSweepIntensity, 0, 3, 1, 1);

        lblIntensity = new QLabel(layoutWidget1);
        lblIntensity->setObjectName(QString::fromUtf8("lblIntensity"));
        lblIntensity->setMaximumSize(QSize(60, 16777215));

        gridLayout_7->addWidget(lblIntensity, 0, 0, 1, 1);

        sbIntensity = new QScrollBar(layoutWidget1);
        sbIntensity->setObjectName(QString::fromUtf8("sbIntensity"));
        sbIntensity->setOrientation(Qt::Horizontal);
        sbIntensity->setInvertedControls(false);

        gridLayout_7->addWidget(sbIntensity, 0, 2, 1, 1);

        inIntensity = new QDoubleSpinBox(layoutWidget1);
        inIntensity->setObjectName(QString::fromUtf8("inIntensity"));
        inIntensity->setMaximumSize(QSize(50, 16777215));
        inIntensity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inIntensity->setMaximum(1.000000000000000);
        inIntensity->setSingleStep(0.010000000000000);

        gridLayout_7->addWidget(inIntensity, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_7);

        layoutWidget2 = new QWidget(tab_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 130, 441, 89));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lblRed = new QLabel(layoutWidget2);
        lblRed->setObjectName(QString::fromUtf8("lblRed"));
        lblRed->setMaximumSize(QSize(60, 16777215));

        gridLayout_5->addWidget(lblRed, 0, 0, 1, 1);

        pbSweepRed = new QPushButton(layoutWidget2);
        pbSweepRed->setObjectName(QString::fromUtf8("pbSweepRed"));
        pbSweepRed->setMaximumSize(QSize(50, 16777215));

        gridLayout_5->addWidget(pbSweepRed, 0, 3, 1, 1);

        sbRed = new QScrollBar(layoutWidget2);
        sbRed->setObjectName(QString::fromUtf8("sbRed"));
        sbRed->setMaximum(255);
        sbRed->setTracking(false);
        sbRed->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(sbRed, 0, 2, 1, 1);

        inRed = new QSpinBox(layoutWidget2);
        inRed->setObjectName(QString::fromUtf8("inRed"));
        inRed->setMaximumSize(QSize(50, 16777215));
        inRed->setFrame(true);
        inRed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inRed->setKeyboardTracking(true);
        inRed->setMaximum(255);

        gridLayout_5->addWidget(inRed, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pbSweepGreen = new QPushButton(layoutWidget2);
        pbSweepGreen->setObjectName(QString::fromUtf8("pbSweepGreen"));
        pbSweepGreen->setMaximumSize(QSize(50, 16777215));

        gridLayout_6->addWidget(pbSweepGreen, 0, 3, 1, 1);

        inGreen = new QSpinBox(layoutWidget2);
        inGreen->setObjectName(QString::fromUtf8("inGreen"));
        inGreen->setMaximumSize(QSize(50, 16777215));
        inGreen->setFrame(true);
        inGreen->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inGreen->setKeyboardTracking(true);
        inGreen->setMaximum(255);

        gridLayout_6->addWidget(inGreen, 0, 1, 1, 1);

        sbGreen = new QScrollBar(layoutWidget2);
        sbGreen->setObjectName(QString::fromUtf8("sbGreen"));
        sbGreen->setMaximum(255);
        sbGreen->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(sbGreen, 0, 2, 1, 1);

        lblGreen = new QLabel(layoutWidget2);
        lblGreen->setObjectName(QString::fromUtf8("lblGreen"));
        lblGreen->setMaximumSize(QSize(60, 16777215));

        gridLayout_6->addWidget(lblGreen, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_6);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        sbBlue = new QScrollBar(layoutWidget2);
        sbBlue->setObjectName(QString::fromUtf8("sbBlue"));
        sbBlue->setEnabled(true);
        sbBlue->setMouseTracking(false);
        sbBlue->setTabletTracking(false);
        sbBlue->setAcceptDrops(false);
        sbBlue->setAutoFillBackground(false);
        sbBlue->setMaximum(255);
        sbBlue->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(sbBlue, 0, 2, 1, 1);

        pbSweepBlue = new QPushButton(layoutWidget2);
        pbSweepBlue->setObjectName(QString::fromUtf8("pbSweepBlue"));
        pbSweepBlue->setMaximumSize(QSize(50, 16777215));

        gridLayout_8->addWidget(pbSweepBlue, 0, 3, 1, 1);

        lblBlue = new QLabel(layoutWidget2);
        lblBlue->setObjectName(QString::fromUtf8("lblBlue"));
        lblBlue->setMaximumSize(QSize(60, 16777215));

        gridLayout_8->addWidget(lblBlue, 0, 0, 1, 1);

        inBlue = new QSpinBox(layoutWidget2);
        inBlue->setObjectName(QString::fromUtf8("inBlue"));
        inBlue->setMaximumSize(QSize(50, 16777215));
        inBlue->setFrame(true);
        inBlue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        inBlue->setKeyboardTracking(true);
        inBlue->setMaximum(255);

        gridLayout_8->addWidget(inBlue, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_8);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout_3->addWidget(tabWidget);

        Dancepad->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Dancepad);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Dancepad->setStatusBar(statusbar);
        menubar = new QMenuBar(Dancepad);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuDancepad = new QMenu(menubar);
        menuDancepad->setObjectName(QString::fromUtf8("menuDancepad"));
        Dancepad->setMenuBar(menubar);
        QWidget::setTabOrder(pbTrendStart, pbTrendRun);
        QWidget::setTabOrder(pbTrendRun, pbTrend100Percent);

        menubar->addAction(menuDancepad->menuAction());

        retranslateUi(Dancepad);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dancepad);
    } // setupUi

    void retranslateUi(QMainWindow *Dancepad)
    {
        Dancepad->setWindowTitle(QApplication::translate("Dancepad", "Dancepad", nullptr));
        lblTitel->setText(QApplication::translate("Dancepad", "!!! Dancepad !!!", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("Dancepad", "Welcome", nullptr));
        lblUsbConn->setText(QApplication::translate("Dancepad", "Communication to master:", nullptr));
        lblLifeLed->setText(QApplication::translate("Dancepad", "Life LED:", nullptr));
        lblRainbow->setText(QApplication::translate("Dancepad", "Rainbow:", nullptr));
        pbUsbConn->setText(QApplication::translate("Dancepad", "Connect", nullptr));
        pbLifeLed->setText(QApplication::translate("Dancepad", "Synchronize", nullptr));
        pbRainbow->setText(QApplication::translate("Dancepad", "Activate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dancepad", "Commissioning", nullptr));
#ifndef QT_NO_TOOLTIP
        tab_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pbTrendStart->setText(QApplication::translate("Dancepad", "Start Data Record", nullptr));
        pbTrendRun->setText(QApplication::translate("Dancepad", "Pause Time", nullptr));
        pbTrend100Percent->setText(QApplication::translate("Dancepad", "Zoom 100%", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Dancepad", "Trending", nullptr));
        pbSweepHue->setText(QApplication::translate("Dancepad", "Sweep", nullptr));
        lblHue->setText(QApplication::translate("Dancepad", "Hue:", nullptr));
        lblSaturation->setText(QApplication::translate("Dancepad", "Saturation:", nullptr));
        pbSweepSaturation->setText(QApplication::translate("Dancepad", "Sweep", nullptr));
        pbSweepIntensity->setText(QApplication::translate("Dancepad", "Sweep", nullptr));
        lblIntensity->setText(QApplication::translate("Dancepad", "Intensity:", nullptr));
        lblRed->setText(QApplication::translate("Dancepad", "Red:", nullptr));
        pbSweepRed->setText(QApplication::translate("Dancepad", "Sweep", nullptr));
        pbSweepGreen->setText(QApplication::translate("Dancepad", "Sweep", nullptr));
        lblGreen->setText(QApplication::translate("Dancepad", "Green:", nullptr));
        pbSweepBlue->setText(QApplication::translate("Dancepad", "Sweep", nullptr));
        lblBlue->setText(QApplication::translate("Dancepad", "Blue:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Dancepad", "Color changing", nullptr));
        menuDancepad->setTitle(QApplication::translate("Dancepad", "Dancepad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dancepad: public Ui_Dancepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DANCEPAD_H
