#include "traductorservidor.h"
#include "qdebug.h"

TraductorServidor::TraductorServidor()
{

}

void TraductorServidor::DeserializarFichasJugadas(string json, int *tam, bool *EsHorizontal, char *letras, int *filas, int *columnas)
{
    Document d;
    d.Parse(json.c_str());
    *tam =d["tam"].GetInt();
    *EsHorizontal=d["horizontal"].GetBool();
    string stmp;
    for (int i=0;i<*tam;i++){
        stmp=d["letras"].GetString();
        letras[i]=stmp[i];
        filas[i]=d["filas"].GetArray()[i].GetInt();
        columnas[i]= d["columnas"].GetArray()[i].GetInt();
    }
}

string TraductorServidor::SerializarRespuestaTurnoPropio(bool val, bool hayfichas, int puntos, string repo)
{
    const char* json = "{\"val\":true,"
                       "\"hayfichas\":true,"
                       "\"puntos\":0,"
                       "\"repo\":\"abcd\"}";

    Document d;
    d.Parse(json);
    d["val"].SetBool(val);
    d["hayfichas"].SetBool(hayfichas);
    d["puntos"].SetInt(puntos);
    d["repo"].SetString(repo.c_str(),sizeof (char)*repo.length());
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    qDebug() <<buffer.GetString();
    return buffer.GetString();
}

