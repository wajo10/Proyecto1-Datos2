#ifndef BOTONES_H
#define BOTONES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "tablero_cliente.h"

class botones: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    botones (QGraphicsItem *parent=nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BOTONES_H
