#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QCryptographicHash>
#include <stdint.h>
#include <QByteArray>
#include <stdio.h>

namespace Ui {
class Auth;
}
namespace NChat {
class Auth : public QDialog
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = 0);
    ~Auth();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Auth *ui;
    QString p;
    QString a = "CLIENTPASSWORD";
    QString t = "A7F337122FC030092D8A1B73C8094D86";
};
}
#endif // AUTH_H
