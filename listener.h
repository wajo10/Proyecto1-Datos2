#ifndef LISTENER_H
#define LISTENER_H
#include <QThread>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "tablero_cliente.h"
#include "traductorcliente.h"
#include "socket.h"
#include "mainwindow.h"
#include <QtDebug>
using namespace std;
class listener: public QThread
{
public:
    listener(int id,int tsala, int puerto, string nombre, bool *flag, string* iniciales);
    void run();

    listener(int id, int tsala, int turno);
private:
    int id;
    int tsala;
    int puerto;
    int turno;
    string nombre;
    bool *flag;
    string *iniciales;
};

#endif // LISTENER_H
