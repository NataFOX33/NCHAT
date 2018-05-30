#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTextStream>
#include <QFile>
#include <QTime>
#include <qt_windows.h>

namespace Ui {
class Widget;
}

class QTcpSocket;

namespace NChat {
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_send_clicked();
    void on_bind_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *nsSocket;
};
} // NChat
#endif // WIDGET_H
