#include "dancepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dancepad w;
    w.show();
    return a.exec();
}
