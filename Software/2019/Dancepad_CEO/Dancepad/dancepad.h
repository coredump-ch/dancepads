#ifndef DANCEPAD_H
#define DANCEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Dancepad; }
QT_END_NAMESPACE

class Dancepad : public QMainWindow
{
    Q_OBJECT

public:
    Dancepad(QWidget *parent = nullptr);
    ~Dancepad();

private slots:

private:
    Ui::Dancepad *ui;
};
#endif // DANCEPAD_H
