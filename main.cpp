#include "mainwindow.h"
#include <QApplication>
#include "bolsa.h"
#include "iostream"
#include <ctime>
using namespace std;
int main(int argc, char *argv[])
{
    int valor=0;
    Bolsa* prueba1= new Bolsa();
    //cout<<"hola"<< prueba1->contar_cantidad()<<endl;
   //cout<< prueba1->agarrar_ficha()<<endl;
    char* ptr=prueba1->fichas_turno(6);

    //cout<< *ptr+2<<endl;
    //cout<< *ptr+3<<endl;
    //cout<< *ptr+4<<endl;
   //cout<< valor<<" "<<"fichas"<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   return a.exec();

}
