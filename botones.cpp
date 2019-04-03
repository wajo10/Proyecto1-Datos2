#include "botones.h"
#include "tablero_cliente.h"
#include "mainwindow.h"
#include "traductorcliente.h"



botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));

};

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (Ficha::flagTurno){
        TraductorCliente* TradC=&TraductorCliente::getInstance();
        Tablero_Cliente* Tc=&Tablero_Cliente::getInstance();
        string s1=Tc->ResumenFichas();
        string respuesta = Socket::getInstance().enviar(s1,Tc->getPuertoServidor(),Tc->getIp().toUtf8().constData(),true);
        Tc->RecibirRespuesta(respuesta);
        if(Tc->getVal()){
            MainWindow::getInstance().puntaje(Tc->getPuntos());
            Tc->limpiarJugadas();
            qDebug() << Tc->getRepo().c_str();
            if (Tc->getHayFichas()){
                MainWindow::request(Tc->getRepo());

            }
            else{
                qDebug()<< "no hay suficientes fichas en bolsa para reponer";
            }

        }
        else{
            if (Tc->getHayFichas()){
                qDebug()<< "Fichas inválidas";
            }
            else{
                qDebug()<< "Fin del juego";
            }
            Tc->RemoverFichas();
        }

    }

}
