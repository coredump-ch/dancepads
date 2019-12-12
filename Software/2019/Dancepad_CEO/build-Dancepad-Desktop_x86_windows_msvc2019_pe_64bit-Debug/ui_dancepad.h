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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QLabel *label;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbTrendStart;
    QPushButton *pbTrendRun;
    QPushButton *pbTrend100Percent;
    QSpacerItem *horizontalSpacer;
    QCustomPlot *plotWidget;
    QWidget *tab_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *pbChangeHue;
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
        label = new QLabel(tab_1);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(72);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbTrendStart = new QPushButton(tab_2);
        pbTrendStart->setObjectName(QString::fromUtf8("pbTrendStart"));
        pbTrendStart->setMaximumSize(QSize(100, 23));

        horizontalLayout->addWidget(pbTrendStart);

        pbTrendRun = new QPushButton(tab_2);
        pbTrendRun->setObjectName(QString::fromUtf8("pbTrendRun"));
        pbTrendRun->setMaximumSize(QSize(100, 23));

        horizontalLayout->addWidget(pbTrendRun);

        pbTrend100Percent = new QPushButton(tab_2);
        pbTrend100Percent->setObjectName(QString::fromUtf8("pbTrend100Percent"));
        pbTrend100Percent->setMaximumSize(QSize(100, 23));

        horizontalLayout->addWidget(pbTrend100Percent);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        plotWidget = new QCustomPlot(tab_2);
        plotWidget->setObjectName(QString::fromUtf8("plotWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plotWidget->sizePolicy().hasHeightForWidth());
        plotWidget->setSizePolicy(sizePolicy);
        plotWidget->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(plotWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 146, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        pbChangeHue = new QPushButton(layoutWidget);
        pbChangeHue->setObjectName(QString::fromUtf8("pbChangeHue"));

        horizontalLayout_2->addWidget(pbChangeHue);

        tabWidget->addTab(tab_3, QString());

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
        QWidget::setTabOrder(tabWidget, pbTrendStart);
        QWidget::setTabOrder(pbTrendStart, pbTrendRun);
        QWidget::setTabOrder(pbTrendRun, pbTrend100Percent);
        QWidget::setTabOrder(pbTrend100Percent, pbChangeHue);

        menubar->addAction(menuDancepad->menuAction());

        retranslateUi(Dancepad);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dancepad);
    } // setupUi

    void retranslateUi(QMainWindow *Dancepad)
    {
        Dancepad->setWindowTitle(QApplication::translate("Dancepad", "Dancepad", nullptr));
        label->setText(QApplication::translate("Dancepad", "!!! Dancepad !!!", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("Dancepad", "Welcome", nullptr));
#ifndef QT_NO_TOOLTIP
        tab_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pbTrendStart->setText(QApplication::translate("Dancepad", "Start Data Record", nullptr));
        pbTrendRun->setText(QApplication::translate("Dancepad", "Pause Time", nullptr));
        pbTrend100Percent->setText(QApplication::translate("Dancepad", "Zoom 100%", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dancepad", "Trending", nullptr));
        label_2->setText(QApplication::translate("Dancepad", "Change Hue:", nullptr));
        pbChangeHue->setText(QApplication::translate("Dancepad", "Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Dancepad", "Color changing", nullptr));
        menuDancepad->setTitle(QApplication::translate("Dancepad", "Dancepad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dancepad: public Ui_Dancepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DANCEPAD_H
