#include "ficha.h"
#include <map>
#include <iostream>
#include <stdlib.h>
#include "tablero_cliente.h"
#include <QGraphicsSceneMouseEvent>
#include "comodin.h"

char Ficha::getLetra() const{
   return this->letra;
}


int* agregar(int,int);
Ficha::Ficha(QGraphicsItem *parent):QObject (), QGraphicsPixmapItem(parent){


}
int* Ficha:: ptrPosicionUnplayed = posiciones;
int Ficha:: posiciones[7];
bool Ficha:: flagTurno = false;
Ficha::Ficha(char letra){
//Casos para cada letra
    this->letra = letra;
    switch (letra) {
        case('a'):setPixmap(QPixmap(":/images/A.jpg"));break;
        case('b'):setPixmap(QPixmap(":/images/B.jpg"));break;
        case('c'):setPixmap(QPixmap(":/images/C.jpg"));break;
        case('d'):setPixmap(QPixmap(":/images/D.jpg"));break;
        case('e'):setPixmap(QPixmap(":/images/E.jpg"));break;
        case('f'):setPixmap(QPixmap(":/images/F.jpg"));break;
        case('g'):setPixmap(QPixmap(":/images/G.jpg"));break;
        case('h'):setPixmap(QPixmap(":/images/H.jpg"));break;
        case('i'):setPixmap(QPixmap(":/images/I.jpg"));break;
        case('j'):setPixmap(QPixmap(":/images/J.jpg"));break;
        case('k'):setPixmap(QPixmap(":/images/K.jpg"));break;
        case('l'):setPixmap(QPixmap(":/images/L.jpg"));break;
        case('m'):setPixmap(QPixmap(":/images/M.jpg"));break;
        case('n'):setPixmap(QPixmap(":/images/N.jpg"));break;
        case('o'):setPixmap(QPixmap(":/images/O.jpg"));break;
        case('p'):setPixmap(QPixmap(":/images/P.jpg"));break;
        case('q'):setPixmap(QPixmap(":/images/Q.jpg"));break;
        case('r'):setPixmap(QPixmap(":/images/R.jpg"));break;
        case('s'):setPixmap(QPixmap(":/images/S.jpg"));break;
        case('t'):setPixmap(QPixmap(":/images/T.jpg"));break;
        case('u'):setPixmap(QPixmap(":/images/U.jpg"));break;
        case('v'):setPixmap(QPixmap(":/images/V.jpg"));break;
        case('w'):setPixmap(QPixmap(":/images/W.jpg"));break;
        case('x'):setPixmap(QPixmap(":/images/X.jpg"));break;
        case('y'):setPixmap(QPixmap(":/images/Y.jpg"));break;
        case('z'):setPixmap(QPixmap(":/images/Z.jpg"));break;
        case(' '):setPixmap(QPixmap(":/images/1.jpg"));break;

};
}
//Deteccion
void Ficha:: mouseMoveEvent(QGraphicsSceneMouseEvent *ev){
    if (flagMove && flagTurno){
        this->setX(ev->scenePos().x()-22);
        this->setY(ev->scenePos().y()-22);
    }

}


void Ficha::setLetra(char value)
{
    letra = value;
}

int Ficha::getFila() const
{
    return Fila;
}

void Ficha::setFila(int value)
{
    Fila = value;
}

int Ficha::getColumna() const
{
    return Columna;
}

void Ficha::setColumna(int value)
{
    Columna = value;
}

int Ficha::getValor() const
{
    return Valor;
}

void Ficha::setValor(int value)
{
    Valor = value;
}

int *Ficha::getFichasIniciales()
{
    return ptrPosicionUnplayed;
}

int Ficha::Puntos(char letra)
{
    std::map<char, char> m;
    m['a']=1;
    m['e']=1;
    m['o']=1;
    m['i']=1;
    m['s']=1;
    m['n']=1;
    m['l']=1;
    m['r']=1;
    m['u']=1;
    m['t']=1;

    m['d']=2;
    m['g']=2;

    m['c']=3;
    m['b']=3;
    m['p']=3;
    m['m']=3;

    m['h']=4;
    m['y']=4;
    m['v']=4;
    m['f']=4;
    m['w']=4;

    m['k']=5;

    m['j']=8;
    m['x']=8;

    m['z']=10;
    m['q']=10;

    return m[letra];
}



Ficha::Ficha(int Fila,int Columna,char letra)
{
    this->Valor=5;
    this->letra=letra;
    this->Fila=Fila;
    this->Columna=Columna;
}
//Setea las posiciones ocupadas de las fichas no utilizadas

void Ficha::setUnplayed()
{   int contador= 0;
    while(contador < 7){
        if (this->posInicial==(contador)){
            posiciones[contador]=1;
        }
        contador++;

    }
}

void Ficha:: setPlayed(){
    posiciones[this->posInicial]=0;
    for(int i =0; i<7;i++){
        qDebug()<<posiciones[i]<<i;
    }
}

void Ficha::setSejugo(bool flag)
{
    this->seJugo = flag;
}
bool Ficha::getSeJugo()
{
    return this->seJugo;
}

void Ficha::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)//Terminar de arrastrar
{
    if (flagMove && flagTurno){
        int* posicion = agregar(event->scenePos().x(), event->scenePos().y());
        this->columna = *(posicion);
        this->fila = *(posicion+1);
        int cantidadFichas = Tablero_Cliente::getInstance().getFichasJugadas().getT();
        //Si esta dentro el tablero, y la primera se pone en el centro
        if (this->fila<15 && this->columna <15 && this->fila>=0 && this->columna>=0){
            //Valida la ficha
            if (Tablero_Cliente::getInstance().JugarFicha(this,this->fila,this->columna)){
                this->setX((columna*43.65)+41.513);
                this->setY((fila*43.65)+44);
                flagMove = false;
                setPlayed();
                qDebug()<<this->posInicial<<"Init";
                }
            else{
                this->setX(xInicial);
                this->setY(yInicial);

            }

        }
        else{
            qDebug()<<"In";
            this->setX(xInicial);
            this->setY(yInicial);
        }
        if(this->letra==' '){
            Comodin *x = new Comodin();
            x->setFicha(this);
            x->show();
        }
    }
    else{

    }


}

void Ficha::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (flagMove && flagTurno){
       xInicial = (int)this->x();
       yInicial = (int)this->y();
    }

}

 int* Ficha:: agregar(int x, int y){
    int posicion[2];
    int inicial = 44;
    int* posicionPtr = posicion;
    posicion[0] = (x-inicial)/44;
    posicion[1] = (y-inicial)/44;
    return posicionPtr;

}

