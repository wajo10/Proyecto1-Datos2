#include "botones.h"
#include "tablero_servidor.h"
#include "tablero_cliente.h"
#include "mainwindow.h"
#include "traductorcliente.h"


botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));


};

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Tablero_Cliente Tc=Tablero_Cliente::getInstance();
    Tablero_Servidor Ts=Tablero_Servidor::getInstance();

    string s1=Tc.ResumenFichas();
    Ts.Desempaquetar(s1);
    string s2=Ts.LeerPalabras();
    Tc.RecibirRespuesta(s2);
    if(Tc.getVal()){
        MainWindow::request(Tc.getRepo());
    }
    else{ 
        Tablero_Cliente::getInstance().RemoverFichas();
    }
}
