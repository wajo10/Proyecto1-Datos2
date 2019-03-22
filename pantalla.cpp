#include "pantalla.h"
#include <QGraphicsScene>
#include <QObject>
pantalla::pantalla(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/Tablero.jpg"));


};
