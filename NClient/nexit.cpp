#include "nexit.h"
#include "ui_nexit.h"

namespace NChat {
NExit::NExit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NExit)
{
    ui->setupUi(this);
}

NExit::~NExit()
{
    delete ui;
}

void NExit::on_okey_clicked()
{
    exit(0);
}
}
