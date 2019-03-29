#ifndef TRADUCTORSERVIDOR_H
#define TRADUCTORSERVIDOR_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
using namespace std;
using namespace rapidjson;


class TraductorServidor
{
public:
    TraductorServidor();
    static TraductorServidor& getInstance(){
        static TraductorServidor instance;
        return instance;
    }
    void DeserializarFichasJugadas(string json, int* tam,bool* EsHorizontal, char* letras,int* filas,int* columnas);
};

#endif // TRADUCTORSERVIDOR_H
