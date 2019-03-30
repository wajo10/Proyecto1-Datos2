#include "traductorcliente.h"


TraductorCliente::TraductorCliente()
{

}

string TraductorCliente::SerilizarFichasJugadas(int tam, bool EsHorizontal, char letras[], int filas[], int columnas[])
{
    const char* json = "{\"tam\":0,"
                       "\"id\":0,"
                       "\"horizontal\":true,"
                       "\"letras\":\"abcdefg\","
                       "\"filas\":[0,0,0,0,0,0,0],"
                       "\"columnas\":[0,0,0,0,0,0,0]}";

    Document d;
    d.Parse(json);
    d["tam"].SetInt(tam);
    d["horizontal"].SetBool(EsHorizontal);
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
    return buffer.GetString();
}

void TraductorCliente::DeserializarRespuestaTurnoPropio(string json,bool *val, bool *hayfichas, int *puntos, string *repo)
{
    Document d;
    d.Parse(json.c_str());
    *val =d["val"].GetBool();
    *hayfichas=d["hayfichas"].GetBool();
    *puntos=d["puntos"].GetInt();
    *repo=d["repo"].GetString();
}
