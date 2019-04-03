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

/**
 * @brief Comodin::on_pushButton_clicked setea la nueva letra al comodin
 */
void Comodin::on_pushButton_clicked()
{
    string letra = ui->lineEdit->text().toUtf8().constData();
    this->ficha->setLetra(letra[0]);
    qDebug()<<this->ficha->getLetra()<<"LETRA";
    delete(this);
}

Ficha *Comodin::getFicha() const
{
    return ficha;
}

void Comodin::setFicha(Ficha *value)
{
    ficha = value;
}
