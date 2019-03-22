#include "pantalla.h"
#include <QGraphicsScene>


pantalla::pantalla(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/images/Tablero.jpg"));


};
void pantalla::mouseMoveEvent(QMouseEvent *ev){
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

void pantalla::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void pantalla::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}
