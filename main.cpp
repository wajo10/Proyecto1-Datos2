#include "mainwindow.h"
#include <QApplication>
#include "bolsa.h"
#include "iostream"
#include <ctime>
using namespace std;
int main(int argc, char *argv[])
{
    Bolsa* prueba1= new Bolsa();
    cout<< "la ficha que se agarro fue "<< prueba1->agarrar_ficha()<< "la ficha que se agarro fue "<< prueba1->agarrar_ficha()<<endl;
    prueba1->poner_cero();

     cout<< "valor "<< prueba1->revisar_cantidad()<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   return a.exec();

}
