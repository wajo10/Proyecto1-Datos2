#include "botones.h"
#include "tablero_servidor.h"
#include "tablero_cliente.h"
#include "mainwindow.h"


botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));


};

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    string s=Tablero_Cliente::getInstance().ResumenFichas();
    Tablero_Servidor::getInstance().Desempaquetar(s);
    if(!Tablero_Servidor::getInstance().LeerPalabras()){
        Tablero_Cliente::getInstance().RemoverFichas();
    }
    else{
        int solicitar = Tablero_Cliente::getInstance().getFichasJugadas().getT();
        MainWindow::request(solicitar);
    }
}
