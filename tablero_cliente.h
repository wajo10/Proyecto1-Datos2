#ifndef TABLERO_CLIENTE_H
#define TABLERO_CLIENTE_H

#include "ficha.h"
#include "linkedlist.h"
#include <string>
using namespace std;


class Tablero_Cliente
{
private:
    bool FichasColocadas[15][15];
    bool VaHorizontal;
    LinkedList* FichasJugadas;
    int referencia;
    int menor;
public:
    Tablero_Cliente();
    bool JugarFicha(Ficha* F,int fila, int columna);
    bool VerificarPos(int fila, int columna);
    string ResumenFichas();
    bool VerificarSentido(int fila,int columna);
    void RemoverFichas();
    void print();
    LinkedList getFichasJugadas();
    void setJugadas(); // Hacer que las fichas validadas no se muevan mas

    static Tablero_Cliente& getInstance(){
        static Tablero_Cliente instance;
        return instance;
    }
    void generar(int cantidad);
};

#endif // TABLERO_CLIENTE_H
