#include "tablero.h"
#include <iostream>
using namespace std;
/**
 * @brief Tablero::Tablero constructor que indica espacios especiales para valor de fichas
 */
Tablero::Tablero()
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

/**
 * @brief Tablero::ValorPos imprime las posiciones especiales
 */
void Tablero::ValorPos()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            cout<<PosEspeciales[i][j]<<" ";
        }
        cout<<endl;
    }
}
/**
 * @brief Tablero::ValorFicha imprime las fichas presentes en cada posicion
 */
void Tablero::ValorFicha()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            if (FichasColocadas[i][j]==nullptr){
                cout<<0<<" ";
            }
            else{
                cout<<FichasColocadas[i][j]->getLetra()<<" ";
            }
        }
        cout<<endl;
    }
}
/**
 * @brief Tablero::VerificarPos Se encarga de verificar si una ficha no cae sobre otra
 * @param PosX eje X
 * @param PosY eje Y
 * @return false si ya hay otra ficha, true si no
 */
bool Tablero::VerificarPos(int PosX, int PosY)
{
    if (this->FichasColocadas[PosX][PosY]==nullptr){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Tablero::ColocarFicha coloca una ficha existente en el tablero
 * @param PosX eje X
 * @param PosY eje Y
 * @param ficha ficha del jugador a colocar
 * @return true si es válida la colocación, false sino
 */
void Tablero::ColocarFicha(int PosX, int PosY, Ficha* ficha)
{
    this->FichasColocadas[PosX][PosY]=ficha;
}
/**
 * @brief Tablero::ColocarPorOrden Verifica y luego coloca un conjunto de fichas.
 * como solo se forma una palabra vertical u horizontal, todas las fichas deben compartir columna o fila
 * @param L Lista con las fichas a colocar
 */
void Tablero::ColocarPorOrden(LinkedList* L)
{
    L->Print();
}

