#ifndef TRADUCTORCLIENTE_H
#define TRADUCTORCLIENTE_H


#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
using namespace std;
using namespace rapidjson;

class TraductorCliente
{
public:
    TraductorCliente();
    static TraductorCliente& getInstance(){
        static TraductorCliente instance;
        return instance;
    }
    string SerilizarFichasJugadas(int tam, bool EsHorizontal,char letras[7],int filas[7], int columnas[7]);
};

#endif // TRADUCTORCLIENTE_H
