#include "botones.h"
#include "tablero_servidor.h"
#include "tablero_cliente.h"
#include "mainwindow.h"
#include "traductorcliente.h"
#include "traductorservidor.h"
#include "socket.h"


botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));


};

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    string s1=Tablero_Cliente::getInstance().ResumenFichas();
    Socket* S=&Socket::getInstance();
    S->enviar(s1,8080);
}
