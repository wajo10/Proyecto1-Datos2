#include "pantalla.h"
#include <QGraphicsScene>


pantalla::pantalla(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/Tablero.jpg"));


};

