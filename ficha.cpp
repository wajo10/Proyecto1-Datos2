#include "ficha.h"
#include <iostream>
#include <stdlib.h>
#include <QGraphicsSceneMouseEvent>


int* agregar(int,int);
ficha::ficha(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){


}
ficha::ficha(char letra){
//Casos para cada letra
    switch (letra) {
        case('A'):setPixmap(QPixmap(":/images/A.jpg"));break;
        case('B'):setPixmap(QPixmap(":/images/B.jpg"));break;
        case('C'):setPixmap(QPixmap(":/images/C.jpg"));break;
        case('D'):setPixmap(QPixmap(":/images/D.jpg"));break;
        case('E'):setPixmap(QPixmap(":/images/E.jpg"));break;
        case('F'):setPixmap(QPixmap(":/images/F.jpg"));break;
        case('G'):setPixmap(QPixmap(":/images/G.jpg"));break;
        case('H'):setPixmap(QPixmap(":/images/H.jpg"));break;
        case('I'):setPixmap(QPixmap(":/images/I.jpg"));break;
        case('J'):setPixmap(QPixmap(":/images/J.jpg"));break;
        case('K'):setPixmap(QPixmap(":/images/K.jpg"));break;
        case('L'):setPixmap(QPixmap(":/images/L.jpg"));break;
        case('M'):setPixmap(QPixmap(":/images/M.jpg"));break;
        case('N'):setPixmap(QPixmap(":/images/N.jpg"));break;
        case('O'):setPixmap(QPixmap(":/images/O.jpg"));break;
        case('P'):setPixmap(QPixmap(":/images/P.jpg"));break;
        case('Q'):setPixmap(QPixmap(":/images/Q.jpg"));break;
        case('R'):setPixmap(QPixmap(":/images/R.jpg"));break;
        case('S'):setPixmap(QPixmap(":/images/S.jpg"));break;
        case('T'):setPixmap(QPixmap(":/images/T.jpg"));break;
        case('U'):setPixmap(QPixmap(":/images/U.jpg"));break;
        case('V'):setPixmap(QPixmap(":/images/V.jpg"));break;
        case('W'):setPixmap(QPixmap(":/images/W.jpg"));break;
        case('X'):setPixmap(QPixmap(":/images/X.jpg"));break;
        case('Y'):setPixmap(QPixmap(":/images/Y.jpg"));break;
        case('Z'):setPixmap(QPixmap(":/images/Z.jpg"));break;
};
}
//Deteccion
void ficha:: mouseMoveEvent(QGraphicsSceneMouseEvent *ev){
    this->setX(ev->scenePos().x());
    this->setY(ev->scenePos().y());
}

 void ficha::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     xInicial = (int)this->x();
     yInicial = (int)this->y();

}

void ficha::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    int* posicion = agregar(event->scenePos().x(), event->scenePos().y());
    this->fila = *(posicion);
    this->columna = *(posicion+1);
    this->setX((fila+1)*44);
    this->setY((columna+1)*44);
    qDebug()<<fila;

}
 int* ficha:: agregar(int x, int y){
    int posicion[2];
    int inicial = 44;
    int* posicionPtr = posicion;
    posicion[0] = (x-inicial)/44;
    posicion[1] = (y-inicial)/44;
    return posicionPtr;

}
