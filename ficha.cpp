#include "ficha.h"

char Ficha::getLetra() const
{
    return letra;
}

void Ficha::setLetra(char value)
{
    letra = value;
}

int Ficha::getFila() const
{
    return Fila;
}

void Ficha::setFila(int value)
{
    Fila = value;
}

int Ficha::getColumna() const
{
    return Columna;
}

void Ficha::setColumna(int value)
{
    Columna = value;
}

int Ficha::getValor() const
{
    return Valor;
}

void Ficha::setValor(int value)
{
    Valor = value;
}

Ficha::Ficha(char letra)
{
    this->Valor=5;
    this->letra=letra;
}
Ficha::Ficha(int Fila,int Columna,char letra)
{
    this->Valor=5;
    this->letra=letra;
    this->Fila=Fila;
    this->Columna=Columna;
}

