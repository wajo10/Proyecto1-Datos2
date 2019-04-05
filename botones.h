#ifndef BOTONES_H
#define BOTONES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "tablero_cliente.h"
#include "socket.h"
#include <stdlib.h>
//#include <iostream>
#include <string>
#include <QLabel>

class botones: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool flagPuntaje = true;
    bool flagResumen = true;
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
    void cicloPartida(int tsala, int turno);
    void fichaAdversario(char *letra, int *fila, int *columna, int tam);
    void freeWidget(QWidget *foo);
    void freeWidgetR(QWidget *foo);
};

#endif // BOTONES_H
