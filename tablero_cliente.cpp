#include "ficha.h"
#include "tablero_cliente.h"
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace std;
using namespace rapidjson;

Tablero_Cliente::Tablero_Cliente()
{
    this->FichasJugadas=new LinkedList();
}
/**
 * @brief Tablero_Cliente::JugarFicha Interfaz básica para colocar una ficha en una posicion específica
 * @param F ficha
 * @param fila eje Y
 * @param columna eje X
 */
bool Tablero_Cliente::JugarFicha(Ficha* F,int fila, int columna)
{
    if (VerificarPos(fila,columna) && VerificarSentido(fila,columna)){
        this->FichasColocadas[fila][columna]=1;
        F->setFila(fila);
        F->setColumna(columna);
        this->FichasJugadas->Add(F);
        cout<<"Se acepta la ficha: "<<fila<<","<<columna<<endl;
        return true;
    }
    else{
        cout<<"Se niega la ficha: "<<fila<<","<<columna<<endl;
        return false;
    }
}

/**
 * @brief Tablero_Cliente::VerificarPos Verifica que la posición no esté llena
 * @param fila eje Y
 * @param columna eje X
 * @return true si es válida
 */
bool Tablero_Cliente::VerificarPos(int fila, int columna)
{
    if (this->FichasColocadas[fila][columna]==0){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Tablero_Cliente::ResumenFichas Hace tres arrays: uno de letras, otro de filas y otro de columnas
 * @return una lista con los tres arrays para el servidor
 */
string Tablero_Cliente::ResumenFichas()
{
    int tam=this->FichasJugadas->getT();
    if (tam==0){
        return "";
    }

    int filas[7];
    int columnas[7];
    char letras[7];
    cout<<"RESUMEN DE FICHAS DEL TURNO: ";
    int i=0;
    Node* tmp=this->FichasJugadas->getFirst();
    Ficha* F;
    while (tmp!=nullptr){
        F=(Ficha*)tmp->getData();
        filas[i]=F->getFila();
        columnas[i]=F->getColumna();
        letras[i]=F->getLetra();
        printf("%c(%d,%d), ",letras[i],filas[i],columnas[i]);
        i++;
        tmp=tmp->getNext();
    }
    cout<<endl;

    const char* json = "{\"tam\":0,"
                       "\"id\":0,"
                       "\"horizontal\":true,"
                       "\"letras\":\"abcdefg\","
                       "\"filas\":[0,0,0,0,0,0,0],"
                       "\"columnas\":[0,0,0,0,0,0,0]}";

    Document d;
    d.Parse(json);
    d["tam"].SetInt(tam);
    d["horizontal"].SetBool(VaHorizontal);
    string stmp;
    for (int j=0;j<tam;j++){
        stmp=d["letras"].GetString();
        stmp[j]=letras[j];
        d["letras"].SetString(stmp.c_str(),sizeof (char)*7);
        d["filas"].GetArray()[j]=filas[j];
        d["columnas"].GetArray()[j]=columnas[j];
    }
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    //cout << buffer.GetString() << endl;
    return buffer.GetString();
}

/**
 * @brief Tablero_Cliente::VerificarSentido Verifica que las fichas jugadas compartan sentido
 * @param fila eje Y
 * @param columna eje X
 * @return true si comparten sentido
 */
bool Tablero_Cliente::VerificarSentido(int fila, int columna)
{
    //Caso nunguna ficha colocada
    if(FichasJugadas->getT()==0){
        return true;

    }
    //Caso una ficha colocada
    else if(FichasJugadas->getT()==1){
        Ficha* F=(Ficha*)FichasJugadas->getFirst()->getData();
        int filatmp=F->getFila();
        int columnatmp=F->getColumna();
        if (fila==filatmp){
            this->referencia=fila;
            this->VaHorizontal=true;
            return true;
        }
        else if(columna==columnatmp){
            this->referencia=columna;
            this->VaHorizontal=false;
            return true;
        }
        else{
            return false;
        }
    }
    //Caso más de una ficha colocada
    else{
        if (this->VaHorizontal){
            if(fila==referencia){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(columna==referencia){
                return true;
            }
            else{
                return false;
            }
        }
    }
}

void Tablero_Cliente::RemoverFichas()
{
    Node* tmp=this->FichasJugadas->getFirst();
    Ficha* F;
    int fila;
    int columna;
    while (tmp!=nullptr){
        F=(Ficha*)tmp->getData();
        fila=F->getFila();
        columna=F->getColumna();
        this->FichasColocadas[fila][columna]=0;
        F->setX(F->xInicial);
        F->setY(F->yInicial);
        F->flagMove =true;
        tmp=tmp->getNext();
    }
    delete(this->FichasJugadas);
    this->FichasJugadas=new LinkedList();
}

void Tablero_Cliente::print()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            cout<<this->FichasColocadas[i][j]<<" ";
        }
        cout<<endl;
    }
}

LinkedList Tablero_Cliente::getFichasJugadas()
{
    return *FichasJugadas;
}

