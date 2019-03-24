#include "ficha.h"
#include "tablero_servidor.h"
#include <iostream>
#include <string>
using namespace std;

Tablero_Servidor::Tablero_Servidor()
{
    ListaPalabras=new LinkedList();
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            if (i==j || i+j==14){
                this->PosEspeciales[i][j]=1;
            }
            this->FichasColocadas[i][j]='.';
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
 * @brief Tablero_Servidor::ColocarFichas Se encarga de colocar una lista de fichas desempequetadas en otros atributos
 * además asigna la menor ficha y la referencia
 */
void Tablero_Servidor::ColocarFichas()
{
    menor=15;
    int det=0;
    for(int i=0;i<tam;i++){
        int f=FilasJugadas[i];
        int c=ColumnasJugadas[i];
        this->FichasColocadas[f][c]=LetrasJugadas[i];
        if (VaHorizontal){
            ref=f;
            det+=c;
            if(menor>c) menor=c;
        }
        else{
            ref=c;
            det+=f;
            if(menor>f) menor=f;
        }
    }
    if (det!=SumaParcial(menor,tam)){
        cout<<"Fragmentación"<<endl;
    }

    cout<<"Menor: "<<menor<<endl;
    cout<<"Ref: "<<ref<<endl;
}

LinkedList* Tablero_Servidor::LeerPalabras()
{

    ColocarFichas();
    LinkedList* L= new LinkedList();
    string* stmp;
    if (VaHorizontal){
         menor= MenorDesdeTablero(VaHorizontal,ref,menor);
         stmp=Leer(VaHorizontal,ref,menor);
    }
    else{
        menor= MenorDesdeTablero(VaHorizontal,menor,ref);
        stmp=Leer(VaHorizontal,menor,ref);
    }
    cout<<"Palabra principal: "<<*stmp<<endl;
    L->Add(stmp);
    AgregarPerpendiculares(L);
    ValidarPalabras(L);
    return L;
}

void Tablero_Servidor::AgregarPerpendiculares(LinkedList *L)
{
    int tmp;
    int fila;
    int columna;
    string* stmp;
    for (int i=0;i<tam;i++){
        fila=FilasJugadas[i];
        columna=ColumnasJugadas[i];
        if(VaHorizontal){
            tmp=MenorDesdeTablero(false,fila,columna);
            stmp=Leer(false,tmp,columna);
        }
        else{
            tmp=MenorDesdeTablero(true,fila,columna);
            stmp=Leer(true,fila,tmp);
        }
        if (stmp->length()<2) return;
        cout<<"Palabra perpendicular: "<<*stmp<<endl;
        L->Add(stmp);
    }
}
/**
 * @brief Tablero_Servidor::ColocarFichaManual Coloca fichas sin restricciones para pruebas
 * @param letra char
 * @param fila eje Y
 * @param columna eje X
 */
void Tablero_Servidor::ColocarFichaManual(char letra, int fila, int columna)
{
    this->FichasColocadas[fila][columna]=letra;
}
/**
 * @brief Tablero_Servidor::MenorDesdeTablero Con la menor posición de las fichas jugadas
 * busca si hay una menor conectada a en la palabra
 */
int Tablero_Servidor::MenorDesdeTablero(bool VaHorizontal,int fila, int columna)
{
    char tmp;
    if(VaHorizontal){
        if (columna==0) return 0;
        tmp=this->FichasColocadas[fila][columna-1];
        while (tmp!='.' && columna!=0){
            columna--;
            tmp=this->FichasColocadas[fila][columna-1];
        }
        return columna;
    }
    else{
        if (fila==0) return 0;
        tmp=this->FichasColocadas[fila-1][columna];
        while (tmp!='.' && fila!=0){
            fila--;
            tmp=this->FichasColocadas[fila-1][columna];
        }
        return fila;
    }
}
/**
 * @brief Tablero_Servidor::Leer Se encarga de leer a partir de una posicón en sentido horizontal o vertical
 * @return Palabra principal formada
 */
string* Tablero_Servidor::Leer(bool VaHorizontal,int fila,int columna)
{
    char tmp;
    string* palabra=new string("");
    if(VaHorizontal){
        tmp=this->FichasColocadas[fila][columna];
        while (tmp!='.' && menor!=14){
            *palabra+=tmp;
            columna++;
            tmp=this->FichasColocadas[fila][columna];
        }
    }
    else{
        tmp=this->FichasColocadas[fila][columna];
        while (tmp!='.' && menor!=14){
            *palabra+=tmp;
            fila++;
            tmp=this->FichasColocadas[fila][columna];
        }
    }
    return palabra;
}


/**
 * @brief Tablero_Servidor::print print de los char colocadas en el tablero
 */
void Tablero_Servidor::print()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            cout<<this->FichasColocadas[i][j]<<" ";
        }
        cout<<endl;
    }
}

/**
 * @brief Tablero_Servidor::Desempaquetar
 * @param L
 */
void Tablero_Servidor::Desempaquetar(LinkedList *L)
{
    for (int k=0;k<7;k++){
        this->LetrasJugadas[k]='.';
    }

    this->LetrasJugadas[0]='b';
    this->FilasJugadas[0]=1;
    this->ColumnasJugadas[0]=3;

    this->LetrasJugadas[1]='g';
    this->FilasJugadas[1]=2;
    this->ColumnasJugadas[1]=3;

    this->tam=2;
    this->VaHorizontal=false;
}
/**
 * @brief Tablero_Servidor::SumaParcial suma elementos desde a hasta a+t
 * @param a primer elemento
 * @param t largo
 * @return suma
 */
int Tablero_Servidor::SumaParcial(int a, int t)
{
    int b=0;
    int c=a+t;
    for (;a<c;a++) {
        b+=a;
    }
    return b;
}

bool Tablero_Servidor::ValidarPalabras(LinkedList *L)
{
    Node* tmp=L->getFirst();
    string* s;
    cout<<"VALIDANDO: ";
    while (tmp!=nullptr){
        s=(string*)tmp->getData();
        cout<<*s<<", ";
        if (!Validar(s)) return false;
        tmp=tmp->getNext();
    }
    cout<<"-VALIDADCIÓN EXITOSA"<<endl;
    return true;
}

bool Tablero_Servidor::Validar(string *s)
{
    if (1){
        return true;
    }
    else{
        return false;
    }
}



