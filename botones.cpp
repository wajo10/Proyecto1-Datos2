#include "botones.h"
#include "tablero_servidor.h"
#include "tablero_cliente.h"
#include "mainwindow.h"
#include "traductorcliente.h"
#include "traductorservidor.h"


botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));


};

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Tablero_Cliente* Tc=&Tablero_Cliente::getInstance();
    Tablero_Servidor* Ts=&Tablero_Servidor::getInstance();

    string s1=Tc->ResumenFichas();
    TraductorServidor::getInstance().SerializarRespuestaTurnoAjeno(s1);
    Ts->Desempaquetar(s1);
    string s2=Ts->LeerPalabras();
    Tc->RecibirRespuesta(s2);


    if(Tc->getVal()){
        Tc->limpiarJugadas();
        qDebug() << Tc->getRepo().c_str();
        MainWindow::request(Tc->getRepo());
        if (Tc->getHayFichas()){

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
