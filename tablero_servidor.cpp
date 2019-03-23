#include "ficha.h"
#include "tablero_servidor.h"
#include <iostream>
using namespace std;

Tablero_Servidor::Tablero_Servidor()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            if (i==j || i+j==14){
                this->PosEspeciales[i][j]=1;
            }
        }
    }

    this->PosEspeciales[2][6]=2;
    this->PosEspeciales[2][7]=2;
    this->PosEspeciales[2][8]=2;

    this->PosEspeciales[12][6]=2;
    this->PosEspeciales[12][7]=2;
    this->PosEspeciales[12][8]=2;

    this->PosEspeciales[6][2]=2;
    this->PosEspeciales[7][2]=2;
    this->PosEspeciales[8][2]=2;

    this->PosEspeciales[6][12]=2;
    this->PosEspeciales[7][12]=2;
    this->PosEspeciales[8][12]=2;
}

void Tablero_Servidor::ColocarFichas(LinkedList *L)
{
    Node* tmp=L->getFirst();
    Ficha* F;
    int fila;
    int columna;
    cout<<"$$$"<<endl;
    while (tmp!=nullptr){
        F=(Ficha*)tmp->getData();
        fila=F->getFila();
        columna=F->getColumna();
        this->FichasColocadas[fila][columna]=F->getLetra();
        tmp=tmp->getNext();
    }
    cout<<"$$$"<<endl;
    this->FichasJugadas=L;
}

void Tablero_Servidor::print()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            cout<<this->FichasColocadas[i][j]<<" ";
        }
        cout<<endl;
    }
}


