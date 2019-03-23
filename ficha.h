#ifndef FICHA_H
#define FICHA_H
#include "tablero.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>

class ficha: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ficha(QGraphicsItem *parent=nullptr);
    ficha(char letra = 'A');
    int yInicial, xInicial, fila, columna;
    int *agregar(int x, int y);
    int inicial = 44;//Espacio antes de las celdas
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};
#endif // FICHA_H
