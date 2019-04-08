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
//    delete ui;
}

void preguntarExperto::on_buttonBox_accepted()
{
   qDebug()<<"Preguntar a experto";

}

void preguntarExperto::on_buttonBox_rejected()
{
    if (!finalizo){
        TraductorCliente *Tc = &TraductorCliente::getInstance();
        string s = Tc->SerializarNuevaPalabra("");
    }
    else{
       qDebug()<<"GAME OVER";
    }
}
void preguntarExperto::addText(string s){
    finalizo=true;
    ui->textEdit->setText(QString::fromStdString(s));
}

void preguntarExperto::on_textEdit_textChanged()
{

}
