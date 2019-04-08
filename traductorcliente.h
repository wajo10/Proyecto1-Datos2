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
    void DeserializarRespuestaTurnoPropio(string json,bool* val, bool* hayfichas,int* puntos, string* repo, string *resumen);
    void DeserializarRespuestaTurnoAjeno(string json, int *tam, char *letras, int *filas, int *columnas, string *ganador);
    int getID(string json);

    string SerializarAgregarPalabra(string palabra);

    string SerializarUnirseSala(string ip,string nombre, string codigo);
    void DeSerializarRespuestaUnirseSala(string json,int* puerto,int* turno,string* iniciales, int* tsala);

    string SerializarCrearSala(string ip,string nombre, int cantidadJugadores);
    void DeSerializarRespuestaCrearSala(string json,int* codigo);

    string SerializarNuevaPalabra(string palabra);
};

#endif // TRADUCTORCLIENTE_H
