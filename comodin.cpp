#include "comodin.h"
#include "ui_comodin.h"

Comodin::Comodin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Comodin)
{
    ui->setupUi(this);
}

Comodin::~Comodin()
{
    delete ui;
}


void Comodin::on_pushButton_clicked()
{
    //string letra = ui->lineEdit->text().toUtf8().constData();
}
