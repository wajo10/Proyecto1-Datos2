#include "ficha.h"

char Ficha::getLetra() const
{
    return letra;
}

void Ficha::setLetra(char value)
{
    letra = value;
}

Ficha::Ficha(char letra)
{
    this->letra=letra;
}
