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
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Socket.h"

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);


   //MainWindow w;
   // w.show();
    string mensaje="Funciona perros putos";
        Socket  *canal=new Socket();
        printf("vamos a escuchar");
       // canal->set_mensaje(mensaje,9090);
        //free(canal);
        string mensaje1="Funciona perros putos";

        canal->enviar(mensaje1,8080);
        mensaje1="Funciona perros putos2";
        canal->enviar(mensaje1,8081);
   //return a.exec();
return 0;
}

