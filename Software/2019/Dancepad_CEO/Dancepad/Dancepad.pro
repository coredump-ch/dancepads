QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DP_Communication.cpp \
    USB_Communication.cpp \
    axistag.cpp \
    hsi.cpp \
    main.cpp \
    dancepad.cpp \
    qcustomplot.cpp

HEADERS += \
    DP_Communication.h \
    USB_Communication.h \
    axistag.h \
    dancepad.h \
    hsi.h \
    mcp2221_dll_um.h \
    qcustomplot.h

FORMS += \
    dancepad.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/./ -lmcp2221_dll_um_x64

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/./mcp2221_dll_um_x64.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/./libmcp2221_dll_um_x64.a
