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
listener::listener(int id, int tsala, int turno)
{
    this->id = id;
    this->tsala = tsala;
    this->turno=turno;
    this->start();
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
        Tablero_Cliente* Tc=&Tablero_Cliente::getInstance();
        qDebug()<<"LISTENING";
        string json = Socket::getInstance().escuchar2(Tc->getPuertoServidor()+Tc->getC());
        qDebug()<<json.c_str()<<"jSON";
        int tam;
        char letras[7];
        int filas[7];
        int columnas[7];
        string ganador;
        TraductorCliente::getInstance().DeserializarRespuestaTurnoAjeno(json,&tam,letras,filas,columnas,&ganador);
        if (ganador != ""){
            preguntarExperto *x = new preguntarExperto;
            x->addText("Fin del juego. Ganador: "+ganador);
            x->show();
            qDebug()<< "Fin del juego"<<"ganador";
            return;
        }
        if (tam !=0){
            botones::getInstance().fichaAdversario(letras,filas,columnas,tam);
        }
        Tc->setC(Tc->getC()+1);
        botones::getInstance().cicloPartida(tsala,turno);


    }
}

