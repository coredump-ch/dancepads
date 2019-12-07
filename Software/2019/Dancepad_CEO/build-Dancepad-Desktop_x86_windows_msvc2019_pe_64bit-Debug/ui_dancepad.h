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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dancepad
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QWidget *tab_2;
    QWidget *tab_3;
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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
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
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

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

        menubar->addAction(menuDancepad->menuAction());

        retranslateUi(Dancepad);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Dancepad);
    } // setupUi

    void retranslateUi(QMainWindow *Dancepad)
    {
        Dancepad->setWindowTitle(QApplication::translate("Dancepad", "Dancepad", nullptr));
        label->setText(QApplication::translate("Dancepad", "!!Dancepad!!", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("Dancepad", "Welcome", nullptr));
#ifndef QT_NO_TOOLTIP
        tab_2->setToolTip(QApplication::translate("Dancepad", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dancepad", "Trending", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Dancepad", "Color changing", nullptr));
        menuDancepad->setTitle(QApplication::translate("Dancepad", "Dancepad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dancepad: public Ui_Dancepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DANCEPAD_H
