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
#include "preguntarexperto.h"

class botones: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool flagPuntaje = true;
    bool flagResumen = true;
    bool flagHilo = false;
    bool *flagHiloPtr = &flagHilo;
public:
    botones (QGraphicsItem *parent=nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /**
     * @brief puntaje Actualiza graficamente el puntaje
     * @param pts
     */
    void puntaje(int pts);
    /**
     * @brief resumen Actualiza graficamente el resumen de la ultima palabra
     * @param res
     */
    void resumen(string res);
    QLabel *label = new QLabel();
    QLabel *labelR = new QLabel();

    static botones & getInstance(){
        static botones instance;
        return instance;
    }
    /**
     * @brief cicloPartida Actualiza el turno de cada juador
     * @param tsala
     * @param turno
     */
    void cicloPartida(int tsala, int turno);
    /**
     * @brief fichaAdversario Agrega las fichas que el adversario agrego
     * @param letra
     * @param fila
     * @param columna
     * @param tam
     */
    void fichaAdversario(char *letra, int *fila, int *columna, int tam);
    /**
     * @brief freeWidget Limpia lo que habia de labels antes de volverlos a agregar para actualizar
     * @param foo
     */
    void freeWidget(QWidget *foo);
};

#endif // BOTONES_H
