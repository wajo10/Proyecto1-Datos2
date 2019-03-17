#include "linkedlist.h"
#include "mainwindow.h"
#include "tablero.h"
#include <QApplication>
#include <QLabel>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    Tablero* T=new Tablero();
    Ficha* A1=new Ficha(1,1,'a');
    Ficha* A2=new Ficha(2,1,'b');
    Ficha* A3=new Ficha(0,0,'c');
    T->ColocarFicha(A1);
    T->ColocarFicha(A2);
    T->ColocarFicha(A3);
    T->ValorFicha();

    LinkedList* L=new LinkedList();
    Ficha* A4=new Ficha(2,6,'d');
    Ficha* A5=new Ficha(3,6,'e');
    Ficha* A6=new Ficha(1,6,'f');
    L->Add(A4);
    L->Add(A5);
    L->Add(A6);
    T->ColocarPorOrden(L);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
