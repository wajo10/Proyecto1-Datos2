#ifndef TABLERO_H
#define TABLERO_H

#include "ficha.h"
#include "linkedlist.h"

class Tablero
{
private:
    int PosEspeciales[15][15]={};
    Ficha* FichasColocadas[15][15]={};
public:
    Tablero();
    void ValorPos();
    void ValorFicha();
    bool VerificarPos(int PosX,int PosY);
    void ColocarFicha(Ficha* ficha);
    void ColocarPorOrden(LinkedList* L);
    void BuscarAdyacentes(Ficha* F,bool Horizontal, bool SentidoPositivo);
    void BuscarTodoSentido(Ficha* F);
    int PuntajePorFicha(Ficha* F);
    int PuntajePorConjunto(LinkedList* L);
};

#endif // TABLERO_H
