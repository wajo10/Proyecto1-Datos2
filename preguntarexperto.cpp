#include "preguntarexperto.h"
#include "ui_preguntarexperto.h"
#include <QtDebug>
preguntarExperto::preguntarExperto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preguntarExperto)
{
    ui->setupUi(this);
}

preguntarExperto::~preguntarExperto()
{
    delete ui;
}

void preguntarExperto::on_buttonBox_accepted()
{
    qDebug()<<"Preguntar a experto";

}

void preguntarExperto::on_buttonBox_rejected()
{

}
