#include "botones.h"
#include "tablero_servidor.h"
#include "tablero_cliente.h"


botones::botones(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/jugar.png"));


};

void botones::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    string s=Tablero_Cliente::getInstance().ResumenFichas();
    Tablero_Servidor::getInstance().Desempaquetar(s);
    LinkedList *valid = Tablero_Servidor::getInstance().LeerPalabras();
    if(!Tablero_Servidor::getInstance().ValidarPalabras(valid)){
        Tablero_Cliente::getInstance().RemoverFichas();
    }
}
