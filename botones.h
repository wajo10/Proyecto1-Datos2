#ifndef BOTONES_H
#define BOTONES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "tablero_cliente.h"
#include "socket.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <QLabel>

class botones: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    botones (QGraphicsItem *parent=nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void puntaje(int pts);
    QLabel *label = new QLabel();
    QLabel *labelR = new QLabel();
    void resumen(string res);
    static botones & getInstance(){
        static botones instance;
        return instance;
    }
};

#endif // BOTONES_H
