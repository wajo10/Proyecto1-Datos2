#ifndef TABLERO_CLIENTE_H
#define TABLERO_CLIENTE_H

#include "ficha.h"
#include "linkedlist.h"
#include <string>
using namespace std;
#include "traductorcliente.h"


class Tablero_Cliente
{
private:
    bool FichasColocadas[15][15];
    bool VaHorizontal;
    LinkedList* FichasJugadas;
    int referencia;
    int menor;
    bool HayFichas=true;
    bool Val;
    int puntos;
    string repo;
public:
    Tablero_Cliente();
    bool JugarFicha(Ficha* F,int fila, int columna);
    bool VerificarPos(int fila, int columna);
    string ResumenFichas();
    bool VerificarSentido(int fila,int columna);
    void RemoverFichas();
    void print();
    LinkedList getFichasJugadas();
    static Tablero_Cliente& getInstance(){
        static Tablero_Cliente instance;
        return instance;
    }
    void RecibirRespuesta(string json);
    void RecibirRespuestaAjena(string json);
    void limpiarJugadas();
    void ColocarFicha(int*,int*,int);

    bool getHayFichas() const;
    void setHayFichas(bool value);
    bool getVal() const;
    void setVal(bool value);
    string getRepo() const;
    void setRepo(const string &value);
};

#endif // TABLERO_CLIENTE_H
