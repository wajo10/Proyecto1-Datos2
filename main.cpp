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
    Ficha* A1=new Ficha('a');
    Ficha* A2=new Ficha('b');
    Ficha* A3=new Ficha('c');
    Tablero_Cliente* T=new Tablero_Cliente();
    T->JugarFicha(A1,1,2);
    T->JugarFicha(A2,1,3);
    T->JugarFicha(A3,1,12);
    LinkedList* L=T->ResumenFichas();
    Tablero_Servidor* T2=new Tablero_Servidor();
    T2->Desempaquetar(L);
    T2->ColocarFichaManual('d',1,2);
    //T2->ColocarFichaManual('e',1,4);
    T2->ColocarFichaManual('f',2,4);
    T2->LeerPalabras();
    T2->print();




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
