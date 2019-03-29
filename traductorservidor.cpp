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
        qDebug() <<"$$$"<<i;
    }
    qDebug() <<json.c_str();
}
