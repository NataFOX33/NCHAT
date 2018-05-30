#include "widget.h"
#include "ui_widget.h"
#include "ndialog.h"
#include "auth.h"

namespace NChat {

    void next() {
        CONTEXT ctx;
        ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
        GetThreadContext(GetCurrentThread(), &ctx);
        if (ctx.Dr0 != 0 || ctx.Dr1 != 0 || ctx.Dr2 != 0 || ctx.Dr3 != 0) {
            exit(0);
        }
        else
            return;
    }

    Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
        QTime t;
        t.start();
        next();
        Auth A(this);
        A.exec();
        if (t.elapsed() > 10000)
            exit(0);
        else {
            ui->setupUi(this);
            nsSocket = new QTcpSocket(this);
            connect(nsSocket, &QTcpSocket::readyRead, [&](){
                    QTextStream T(nsSocket);
                    auto text = T.readAll();
                    ui->textEdit->append(text);
            });
        }
    }
    Widget::~Widget() {
        delete ui;
    }

    void Widget::on_send_clicked() {
        QTextStream T(nsSocket);
        T << ui->nickname->text() << ": " << ui->message->text();
        nsSocket->flush();
        ui->message->clear();
    }

    void Widget::on_bind_clicked() {
        NDialog D(this);
        if (D.exec() == QDialog::Rejected) {
            return;
        }
        nsSocket->connectToHost(D.hostname(), D.port());
    }
} // NChat
