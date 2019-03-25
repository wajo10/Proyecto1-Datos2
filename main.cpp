#include "linkedlist.h"
#include "mainwindow.h"
#include "tablero.h"
#include "tablero_cliente.h"
#include "tablero_servidor.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "pantalla.h"
#include "ficha.h"
#include "botones.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
   return a.exec();

}

