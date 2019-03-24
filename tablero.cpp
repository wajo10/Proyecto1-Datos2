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
 * @param Fila eje X
 * @param Columna eje Y
 * @return false si ya hay otra ficha, true si no
 */
bool Tablero::VerificarPos(int Fila, int Columna)
{
    if (this->FichasColocadas[Fila][Columna]==nullptr){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Tablero::ColocarFicha coloca una ficha existente en el tablero
 * @param Fila eje X
 * @param Columna eje Y
 * @param ficha ficha del jugador a colocar
 * @return true si es válida la colocación, false sino
 */
void Tablero::ColocarFicha(Ficha* ficha)
{
    this->FichasColocadas[ficha->getFila()][ficha->getColumna()]=ficha;
}
/**
 * @brief Tablero::ColocarPorOrden Verifica y luego coloca un conjunto de fichas.
 * como solo se forma una palabra vertical u horizontal, todas las fichas deben compartir columna o fila
 * @param L Lista con las fichas a colocar
 */
void Tablero::ColocarPorOrden(LinkedList* L)
{
    //Caso de que solo ponga una ficha
    Node* tmp1=L->getFirst();
    Node* tmp2=L->getFirst()->getNext();
    Ficha* F1=(Ficha*)tmp1->getData();
    if (tmp2==nullptr){
        BuscarTodoSentido(F1);
        cout<<"Puntaje= "<<PuntajePorFicha(F1)<<endl;
        return;
    }

    //Se define el sentido de la palabra
    Ficha* F2=(Ficha*)tmp2->getData();
    int referencia;
    bool EsHorizontal=false;
    if (F1->getFila()==F2->getFila()){
        referencia=F1->getFila();
        EsHorizontal=true;
    }
    else if (F1->getColumna()==F2->getColumna()){
        referencia=F1->getColumna();
        EsHorizontal=false;
    }
    else{
        cout<<"fichas en diferentes filas y columnas"<<endl;
        return;
    }

    Ficha* Menor=F1;
    ColocarFicha(F1);
    //Se verifica que compartan fila o columna
    //Además se busca la ficha más cercana a (0,0)
    if(EsHorizontal){
        while(tmp2!=nullptr){
            F2=(Ficha*)tmp2->getData();
            if(F2->getFila()!=referencia){
                cout<<"fichas en diferentes filas"<<endl;
                return;
            }
            if(F2->getColumna()<Menor->getColumna()){
                Menor=F2;
            }
            ColocarFicha(F2);
            tmp2=tmp2->getNext();
        }
        BuscarAdyacentes(Menor,true,true);
    }
    else{
        while(tmp2!=nullptr){
            F2=(Ficha*)tmp2->getData();
            if(F2->getColumna()!=referencia){
                cout<<"fichas en diferentes columnas"<<endl;
                return;
            }
            if(F2->getFila()<Menor->getFila()){
                Menor=F2;
            }
            ColocarFicha(F2);
            tmp2=tmp2->getNext();
        }
        BuscarAdyacentes(Menor,false,true);
    }
    cout<<"Puntaje= "<<PuntajePorConjunto(L)<<endl;


}
/**
 * @brief Tablero::BuscarAdyacentes Busca fichas adyacnetes a una cierta posicion en ciertas direcciones
 * @param Fila eje x
 * @param Columna eje y
 * @param Horizontal si el sentido es horizontal
 * @param SentidoPositivo positivo si es hacia la derecha o arriba
 */
void Tablero::BuscarAdyacentes(Ficha* F, bool Horizontal, bool SentidoPositivo)
{
    string palabra;
    palabra+=F->getLetra();
    int Fila=F->getFila();
    int Columna=F->getColumna();
    if (!Horizontal){
        if (SentidoPositivo){
            cout<<"Leyendo hacia abajo: ";
            Fila++;
            while(Fila<=14 && this->FichasColocadas[Fila][Columna]!=nullptr){
                palabra+=this->FichasColocadas[Fila][Columna]->getLetra();
                Fila++;
            }
        }
        else{
            cout<<"Leyendo hacia arriba: ";
            Fila--;
            while(Fila>=0 && this->FichasColocadas[Fila][Columna]!=nullptr){
                palabra+=this->FichasColocadas[Fila][Columna]->getLetra();
                Fila--;
            }
        }
    }
    else{
        if (SentidoPositivo){
            cout<<"Leyendo hacia la derecha: ";
            Columna++;
            while(Columna<=14 &&this->FichasColocadas[Fila][Columna]!=nullptr){
                palabra+=this->FichasColocadas[Fila][Columna]->getLetra();
                Columna++;
            }
        }
        else{
            cout<<"Leyendo hacia la izquierda: ";
            Columna--;
            while(Columna>=0 &&this->FichasColocadas[Fila][Columna]!=nullptr){
                palabra+=this->FichasColocadas[Fila][Columna]->getLetra();
                Columna--;
            }
        }
    }
    cout<<palabra<<endl;
}
/**
 * @brief Tablero::BuscarTodoSentido caso especial de BuscarAdyacentes
 * @param Fila eje X
 * @param Columna eje Y
 */
void Tablero::BuscarTodoSentido(Ficha* F1)
{
    BuscarAdyacentes( F1, true, false);
    BuscarAdyacentes( F1, true, true);
    BuscarAdyacentes( F1, false,false);
    BuscarAdyacentes( F1, false,true);
}

/**
 * @brief Tablero::PuntajePorFicha da puntaje por la ficha y su posición
 * @param F ficha a evaluar
 * @return cantidad de puntos
 */
int Tablero::PuntajePorFicha(Ficha* F)
{
    int Puntos=0;
    Puntos+=F->getValor();
    int columna=F->getFila();
    int fila=F->getColumna();
    if(this->PosEspeciales[fila][columna]==1){
        Puntos*=2;
    }
    return Puntos;
}

/**
 * @brief Tablero::PuntajePorConjunto Recoje un conjunto de fichas y suma sus puntos
 * @param L Lista de fichas a evaluar
 * @return Suma de puntos
 */
int Tablero::PuntajePorConjunto(LinkedList *L)
{
    int Puntos=0;
    int Doble=1;
    int columna;
    int fila;
    Node* tmp=L->getFirst();
    Ficha* F;
    while(tmp!=nullptr){
        F=(Ficha*)tmp->getData();
        columna=F->getFila();
        fila=F->getColumna();
        if(this->PosEspeciales[fila][columna]==2){
            Doble=2;
        }
        Puntos+=PuntajePorFicha(F);
        tmp=tmp->getNext();
    }
    return Puntos*Doble;
}







