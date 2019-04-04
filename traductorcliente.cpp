#include "traductorcliente.h"
#include "qdebug.h"


TraductorCliente::TraductorCliente()
{

}

string TraductorCliente::SerilizarFichasJugadas(int tam, bool EsHorizontal, char letras[], int filas[], int columnas[])
{
    const char* json = "{\"tam\":0,"
                       "\"id\":2,"
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

void TraductorCliente::DeserializarRespuestaTurnoPropio(string json,bool *val, bool *hayfichas, int *puntos, string *repo, string *resumen)
{
    Document d;
    d.Parse(json.c_str());
    *val =d["val"].GetBool();
    *hayfichas=d["hayfichas"].GetBool();
    *puntos=d["puntos"].GetInt();
    *repo=d["repo"].GetString();
    *resumen=d["resumen"].GetString();
}
void TraductorCliente::DeserializarRespuestaTurnoAjeno(string json, int *tam, char *letras, int *filas, int *columnas)
{
    Document d;
    d.Parse(json.c_str());
    *tam =d["tam"].GetInt();
    string stmp;
    for (int i=0;i<*tam;i++){
        stmp=d["letras"].GetString();
        letras[i]=stmp[i];
        filas[i]=d["filas"].GetArray()[i].GetInt();
        columnas[i]= d["columnas"].GetArray()[i].GetInt();
    }
}

int TraductorCliente::getID(string json)
{
    Document d;
    d.Parse(json.c_str());
    return d["id"].GetInt();
}

string TraductorCliente::SerializarAgregarPalabra(string palabra)
{
    const char* json = "{\"palabra\":\"123456789\","
                       "\"id\":3}";

    Document d;
    d.Parse(json);
    d["palabra"].SetString(palabra.c_str(),sizeof(char)*palabra.length());

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    return buffer.GetString();
}

string TraductorCliente::SerializarUnirseSala(string ip, string nombre, string codigo)
{
    const char* json = "{\"ip\":\"0.0.0.0\","
                        "\"nombre\":\"lol\","
                        "\"codigo\":123456,"
                       "\"id\":1 }";

    Document d;
    d.Parse(json);
    d["ip"].SetString(ip.c_str(),sizeof(char)*ip.length());
    d["nombre"].SetString(nombre.c_str(),sizeof(char)*nombre.length());
    d["codigo"].SetInt(stoi(codigo));
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    return buffer.GetString();
}

void TraductorCliente::DeSerializarRespuestaUnirseSala(string json, int *puerto, int *turno, string* iniciales, int* tsala)
{
    Document d;
    d.Parse(json.c_str());
    *puerto =d["puerto"].GetInt();
    *turno =d["turno"].GetInt();
    *iniciales=d["iniciales"].GetString();
    *tsala =d["tsala"].GetInt();
}

string TraductorCliente::SerializarCrearSala(string ip,string nombre, int cantidadJugadores)
{
    const char* json = "{\"ip\":\"0.0.0.0\","
                        "\"nombre\":\"lol\","
                        "\"tsala\":2,"
                       "\"id\":0 }";

    Document d;
    d.Parse(json);
    d["tsala"].SetInt(cantidadJugadores);
    d["ip"].SetString(ip.c_str(),sizeof(char)*ip.length());
    d["nombre"].SetString(nombre.c_str(),sizeof(char)*nombre.length());

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    return buffer.GetString();
}

void TraductorCliente::DeSerializarRespuestaCrearSala(string json, int* codigo)
{
    Document d;
    d.Parse(json.c_str());
    *codigo =d["codigo"].GetInt();
}
