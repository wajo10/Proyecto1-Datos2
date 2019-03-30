#include "linkedlist.h"
#include "mainwindow.h"
#include "traductorcliente.h"
#include "traductorservidor.h"


int main(int argc, char *argv[])

{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
   return a.exec();

}

