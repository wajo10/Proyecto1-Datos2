#include "linkedlist.h"
#include "mainwindow.h"
#include "tablero.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Tablero* T=new Tablero();
    Ficha* A1=new Ficha('a');
    Ficha* A2=new Ficha('b');
    Ficha* A3=new Ficha('c');
    T->ColocarFicha(1,1,A1);
    T->ColocarFicha(0,1,A2);
    T->ColocarFicha(0,3,A3);
    T->ValorFicha();

    LinkedList* L=new LinkedList();
    L->Add(A1);
    L->Add(A2);
    L->Add(A3);
    T->ColocarPorOrden(L);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
