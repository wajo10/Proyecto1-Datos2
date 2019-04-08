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
    if (!finalizo){
        TraductorCliente *Tc = &TraductorCliente::getInstance();
        Tablero_Cliente *TabClien = &Tablero_Cliente::getInstance();
        Socket *sock = &Socket::getInstance();
        int size =TabClien->getResumen().length();
        string s = Tc->SerializarNuevaPalabra(TabClien->getResumen().substr(0,size-1));
        sock->enviar(s,8078,"192.168.100.11",false);
    }
    else{
       qDebug()<<"GAME OVER";
    }

}

void preguntarExperto::on_buttonBox_rejected()
{
    if(!finalizo){
        Socket *sock = &Socket::getInstance();
        TraductorCliente *Tc = &TraductorCliente::getInstance();
        Tablero_Cliente *TabClien = &Tablero_Cliente::getInstance();

        string s = Tc->SerializarNuevaPalabra("");
        qDebug()<<TabClien->getPuertoServidor()<<"PUERTO";
        sock->enviar(s,8078,"192.168.100.11",false);
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
