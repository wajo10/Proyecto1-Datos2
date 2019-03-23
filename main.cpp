#include "linkedlist.h"
#include "mainwindow.h"
#include "tablero.h"
#include "tablero_cliente.h"
#include "tablero_servidor.h"
#include <QApplication>
#include <QLabel>
#include <iostream>
using namespace std;

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
    T2->ColocarFichaManual('e',1,5);
    T2->ColocarFichas();
    T2->Leer();
    T2->print();




    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
