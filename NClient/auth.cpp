#include "auth.h"
#include "ui_auth.h"


#define GET_VARIABLE_NAME(Variable) (#Variable)

namespace NChat {

    Auth::Auth(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Auth) {
        ui->setupUi(this);
        setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    }

    Auth::~Auth() {
    delete ui;
    }

    void Auth::on_pushButton_clicked() {
        p = ui->lineEdit->text();
        QString s = "Привет, отладчик! :)";
        QString n = "";
        n = n.append(QString(GET_VARIABLE_NAME(n)).toUpper());
        n = n.append(QString(GET_VARIABLE_NAME(c)).toUpper());
        n = n.append(QString(GET_VARIABLE_NAME(h)).toUpper());
        n = n.append(QString(GET_VARIABLE_NAME(a)).toUpper());
        n = n.append(QString(GET_VARIABLE_NAME(t)).toUpper());
        n = n.append(QString(GET_VARIABLE_NAME(p)).toUpper());
        n = n.append(QString(GET_VARIABLE_NAME(a)).toUpper());
        n = n.append(QString(GET_VARIABLE_NAME(s)).toUpper()).append(QString(GET_VARIABLE_NAME(s)).toUpper());
        QString c = QString(QCryptographicHash::hash((n.toLocal8Bit()),QCryptographicHash::Md5).toHex());
        QString h = QString(QCryptographicHash::hash((p.toLocal8Bit()),QCryptographicHash::Md5).toHex());
        if (c == h)
            accept();
    }

    void Auth::on_pushButton_2_clicked() {
        reject();
        exit(0);
    }
}


