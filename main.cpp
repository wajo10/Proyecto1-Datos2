#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "pantalla.h"
#include "ficha.h"
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
    pantalla * Pantalla = new pantalla();
    scene->addItem(Pantalla);
    ficha * Ficha = new ficha('M');
    Ficha->setX(45);
    Ficha->setY(45);
    scene->addItem(Ficha);
    Ficha->setFlag(QGraphicsItem:: ItemIsFocusable);
    Ficha->setFocus();



    return a.exec();
}
