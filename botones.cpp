#include "botones.h"
#include "tablero_servidor.h"


botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));


};

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    string s=Tablero_Cliente::getInstance().ResumenFichas();
    Tablero_Servidor::getInstance().Desempaquetar(s);
    Tablero_Servidor::getInstance().LeerPalabras();
}
