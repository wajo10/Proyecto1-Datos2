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
    int valor=0;
    //Bolsa* prueba1= new Bolsa();
    //cout<<"hola"<< prueba1->contar_cantidad()<<endl;
   //cout<< prueba1->agarrar_ficha()<<endl;
    //char* ptr=prueba1->fichas_turno(6);

    //cout<< *ptr+2<<endl;
    //cout<< *ptr+3<<endl;
    //cout<< *ptr+4<<endl;
   //cout<< valor<<" "<<"fichas"<<endl;
    QApplication a(argc, argv);

//    //Crear scene
//    QGraphicsScene * scene = new QGraphicsScene();


//    //Crear view
//    QGraphicsView * view = new QGraphicsView(scene);
//    view->show();
//    view-> setFixedSize(1300,700);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    scene->setSceneRect(0,0,1300,700);

//    //Hud
//    pantalla * Pantalla = new pantalla();
//    scene->addItem(Pantalla);

//    //Primera Ficha
//    Ficha * ficha = new Ficha('m');
//    ficha->setX(807);
//    ficha->setY(237);
//    scene->addItem(ficha);

//    //Segunda Ficha
//    Ficha * ficha1 = new Ficha('z');
//    ficha1->setX(862);
//    ficha1->setY(237);
//    scene->addItem(ficha1);

//    //Tercera Ficha
//    Ficha * ficha2 = new Ficha('a');
//    ficha2->setX(920);
//    ficha2->setY(237);
//    scene->addItem(ficha2);

//    //Boton
//    botones *Boton = new botones();
//    Boton->setX(1000);
//    Boton->setY(404);
//    scene->addItem(Boton);

    MainWindow w;
    w.show();
   return a.exec();

}

