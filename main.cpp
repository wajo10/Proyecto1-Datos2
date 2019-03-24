#include "mainwindow.h"
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

    //Crear scene
    QGraphicsScene * scene = new QGraphicsScene();


    //Crear view
    QGraphicsView * view = new QGraphicsView(scene);
    view->show();
    view-> setFixedSize(1300,700);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0,0,1300,700);

    //Hud
    pantalla * Pantalla = new pantalla();
    scene->addItem(Pantalla);

    //Primera Ficha
    ficha * Ficha = new ficha('M');
    Ficha->setX(807);
    Ficha->setY(237);
    scene->addItem(Ficha);

    //Segunda Ficha
    ficha * Ficha1 = new ficha('Z');
    Ficha1->setX(862);
    Ficha1->setY(237);
    scene->addItem(Ficha1);

    //Boton
    botones *Boton = new botones();
    Boton->setX(1000);
    Boton->setY(404);
    scene->addItem(Boton);

    return a.exec();
}
