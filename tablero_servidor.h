#ifndef TABLERO_SERVIDOR_H
#define TABLERO_SERVIDOR_H

#include "linkedlist.h"



class Tablero_Servidor
{
private:

    char FichasColocadas[15][15];
    char LetrasJugadas[7];
    char FilasJugadas[7];
    char ColumnasJugadas[7];
    bool VaHorizontal;
    int tam;
    int menor;
    int ref;
    LinkedList* ListaPalabras;
    int PosEspeciales[15][15];
public:
    Tablero_Servidor();
    void ColocarFichas();
    void ColocarFichaManual(char letra,int fila, int columna);
    int MenorDesdeTablero(bool VaHorizontal,int fila, int columna);
    LinkedList* Leer(bool VaHorizontal,int fila,int columna);
    void print();
    void Desempaquetar(LinkedList* L);
    int SumaParcial(int a,int t);
};

#endif // TABLERO_SERVIDOR_H
