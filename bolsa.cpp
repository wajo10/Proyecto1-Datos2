#include "bolsa.h"
#include <cstdlib>
#include "iostream"
#include <ctime>
#include <array>
Bolsa::Bolsa()
{
      srand((int)time(0));//manera que el rand detecta que es que
}

char Bolsa::agarrar_ficha()
{
    int r = (rand() % 26) + 1;;
    if (cantidad[r]>0){
        cantidad[r]=cantidad[r]-1;
       return letras[r];
    }
    else if (revisar_cantidad()){
        return agarrar_ficha();
    }
    else{
        return '0';//este caso es cuando no hay mas fichas en la bolsa entonces se devuelve este char signifancos que no hay mas fichas
    }

}

int Bolsa::prueba()
{

}

bool Bolsa::revisar_cantidad()
{
    int valores_en_cero=0;
    int valor=0;
    while(valor!=27)
    {
        if (cantidad[valor]==0){
            valores_en_cero=valores_en_cero+1;
        }
        valor=valor+1;
    }
    if (valores_en_cero>=27){
        return false;
    }
    else{
        return true;
    }
}

void Bolsa::poner_cero()
{
    int valor=0;
    while(valor!=27){
     cantidad[valor]=0;
     valor=valor+1;
    }

}

