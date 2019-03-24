#ifndef TABLERO_CLIENTE_H
#define TABLERO_CLIENTE_H

#include "ficha.h"
#include "linkedlist.h"



class Tablero_Cliente
{
private:
    bool FichasColocadas[15][15];
    bool VaHorizontal;
    LinkedList* FichasJugadas;
    int referencia;
public:
    Tablero_Cliente();
    void JugarFicha(Ficha* F,int fila, int columna);
    bool VerificarPos(int fila, int columna);
    LinkedList* ResumenFichas();
    bool VerificarSentido(int fila,int columna);
    void RemoverFichas();
    void print();
    static Tablero_Cliente& getInstance(){
        static Tablero_Cliente instance;
        return instance;
    }
};

#endif // TABLERO_CLIENTE_H
