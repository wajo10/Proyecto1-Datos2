#ifndef FICHA_H
#define FICHA_H
#include "tablero.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>
#include "linkedlist.h"

class linkedlist;
class ficha: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ficha(QGraphicsItem *parent=nullptr);
    ficha(char letra = 'A');
    char letra;
    int yInicial, xInicial, fila, columna;
    int *agregar(int x, int y);
    int inicial = 44;//Espacio antes de las celdas
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    bool flagMove = true;
};
#endif // FICHA_H
