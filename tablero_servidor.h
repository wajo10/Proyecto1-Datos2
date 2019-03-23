#ifndef TABLERO_SERVIDOR_H
#define TABLERO_SERVIDOR_H

#include "linkedlist.h"



class Tablero_Servidor
{
private:
    int PosEspeciales[15][15];
    char FichasColocadas[15][15];
    LinkedList *FichasJugadas;
public:
    Tablero_Servidor();
    void ColocarFichas(LinkedList* FichasJugadas);
    void print();
};

#endif // TABLERO_SERVIDOR_H
