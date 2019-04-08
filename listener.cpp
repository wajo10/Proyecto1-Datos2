#include "listener.h"

listener::listener(int id, int tsala, int puerto, string nombre, bool *flag, string* iniciales)
{
    this->id = id;
    this->tsala = tsala;
    this->puerto=puerto;
    this->nombre = nombre;
    this->start();
    this->flag = flag;
    this->iniciales = iniciales;
}

void listener::run()
{
    Tablero_Cliente* TabClien = &Tablero_Cliente::getInstance();
    Socket* sock = &Socket::getInstance();
    TraductorCliente* TC=&TraductorCliente::getInstance();
    if (this->id==0){ //Caso esperar crear sala
        string confirmacion = sock->escuchar2(8078);
        qDebug()<<confirmacion.c_str();
        int puerto2;
        int turno;
        TC->DeSerializarRespuestaUnirseSala(confirmacion,&puerto2,&turno,iniciales,&tsala);
        qDebug()<<"paso Abajo";
        TabClien->setPuertoServidor(puerto2);
        TabClien->setTurno(turno);
        TabClien->setTsala(tsala);
        *flag = true;
    }
    else if (this->id == 1) {
        string confirmacion = sock->escuchar2(8078);
        qDebug()<<confirmacion.c_str();
        int puerto2;
        int turno;
        TC->DeSerializarRespuestaUnirseSala(confirmacion,&puerto2,&turno,iniciales,&tsala);
        TabClien->setPuertoServidor(puerto2);
        TabClien->setTurno(turno);
        TabClien->setTsala(tsala);
        *flag = true;
    }
    else if (this->id == 2) {

    }
}

