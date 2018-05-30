#include "ndialog.h"
#include "ui_ndialog.h"

namespace NChat {

    NDialog::NDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::NDialog) {
        ui->setupUi(this);
    }

    NDialog::~NDialog() {
        delete ui;
    }

    void NDialog::on_ok_clicked() {
        nHostname = ui->hostname->text();
        nPort = ui->port->value();
        accept();
    }

    void NDialog::on_cancel_clicked() {
        reject();
    }
} // NChat
