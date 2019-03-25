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


    Ficha* A1=new Ficha('a');
    Ficha* A2=new Ficha('b');
    Ficha* A3=new Ficha('c');
    Tablero_Cliente* T=new Tablero_Cliente();
    T->JugarFicha(A1,1,2);
    T->JugarFicha(A2,1,3);
    T->JugarFicha(A3,1,12);
    string s=T->ResumenFichas();

    Tablero_Servidor* T2=new Tablero_Servidor();
    T2->Desempaquetar(s);
    return 0;

    MainWindow w;
    w.show();
   return a.exec();

}

