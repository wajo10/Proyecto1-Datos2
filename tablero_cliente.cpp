#include "ficha.h"
#include "tablero_cliente.h"
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace std;
using namespace rapidjson;

bool Tablero_Cliente::getHayFichas() const
{
    return HayFichas;
}

void Tablero_Cliente::setHayFichas(bool value)
{
    HayFichas = value;
}

bool Tablero_Cliente::getVal() const
{
    return Val;
}

void Tablero_Cliente::setVal(bool value)
{
    Val = value;
}

string Tablero_Cliente::getRepo() const
{
    return repo;
}

void Tablero_Cliente::setRepo(const string &value)
{
    repo = value;
}

int Tablero_Cliente::getPuertoServidor() const
{
    return puertoServidor;
}

void Tablero_Cliente::setPuertoServidor(int value)
{
    puertoServidor = value;
}

int Tablero_Cliente::getTurno() const
{
    return turno;
}

void Tablero_Cliente::setTurno(int value)
{
    turno = value;
}

int Tablero_Cliente::getTsala() const
{
    return tsala;
}

void Tablero_Cliente::setTsala(int value)
{
    tsala = value;
}

int Tablero_Cliente::getPuntos() const
{
    return puntos;
}

void Tablero_Cliente::setPuntos(int value)
{
    puntos = value;
}

string Tablero_Cliente::getResumen() const
{
    return resumen;
}

void Tablero_Cliente::setResumen(const string &value)
{
    resumen = value;
}

int Tablero_Cliente::getC() const
{
    return c;
}

void Tablero_Cliente::setC(int value)
{
    c = value;
}

Tablero_Cliente::Tablero_Cliente()
{
    this->FichasJugadas=new LinkedList();
}
/**
 * @brief Tablero_Cliente::JugarFicha Interfaz básica para colocar una ficha en una posicion específica
 * @param F ficha
 * @param fila eje Y
 * @param columna eje X
 */
bool Tablero_Cliente::JugarFicha(Ficha* F,int fila, int columna)
{
    if (VerificarPos(fila,columna) && VerificarSentido(fila,columna)){
        this->FichasColocadas[fila][columna]=1;
        F->setFila(fila);
        F->setColumna(columna);
        this->FichasJugadas->Add(F);
        cout<<"Se acepta la ficha: "<<fila<<","<<columna<<endl;
        return true;
    }
    else{
        cout<<"Se niega la ficha: "<<fila<<","<<columna<<endl;
        return false;
    }
}

/**
 * @brief Tablero_Cliente::VerificarPos Verifica que la posición no esté llena
 * @param fila eje Y
 * @param columna eje X
 * @return true si es válida
 */
bool Tablero_Cliente::VerificarPos(int fila, int columna)
{
    if (this->FichasColocadas[fila][columna]==0){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Tablero_Cliente::ResumenFichas Hace tres arrays: uno de letras, otro de filas y otro de columnas
 * @return una lista con los tres arrays para el servidor
 */
string Tablero_Cliente::ResumenFichas()
{
    int tam=this->FichasJugadas->getT();
    TraductorCliente T=TraductorCliente::getInstance();
    if (tam==0){
        return T.SerilizarFichasJugadas(0,0,0,0,0);
    }

    int filas[7];
    int columnas[7];
    char letras[7];
    cout<<"RESUMEN DE FICHAS DEL TURNO: ";
    qDebug()<<tam<<"SE AGREGARON ESAS FICHAS";
    int i=0;
    Node* tmp=this->FichasJugadas->getFirst();
    Ficha* F;
    while (tmp!=nullptr){
        F=(Ficha*)tmp->getData();
        filas[i]=F->getFila();
        columnas[i]=F->getColumna();
        letras[i]=F->getLetra();
        printf("%c(%d,%d), ",letras[i],filas[i],columnas[i]);
        i++;
        tmp=tmp->getNext();
    }
    cout<<endl;
    string s=T.SerilizarFichasJugadas(tam,VaHorizontal,letras,filas,columnas);
    return s;
}

/**
 * @brief Tablero_Cliente::VerificarSentido Verifica que las fichas jugadas compartan sentido
 * @param fila eje Y
 * @param columna eje X
 * @return true si comparten sentido
 */
bool Tablero_Cliente::VerificarSentido(int fila, int columna)
{
    //Caso nunguna ficha colocada
    if(FichasJugadas->getT()==0){
        return true;

    }
    //Caso una ficha colocada
    else if(FichasJugadas->getT()==1){
        Ficha* F=(Ficha*)FichasJugadas->getFirst()->getData();
        int filatmp=F->getFila();
        int columnatmp=F->getColumna();
        if (fila==filatmp){
            this->referencia=fila;
            this->VaHorizontal=true;
            return true;
        }
        else if(columna==columnatmp){
            this->referencia=columna;
            this->VaHorizontal=false;
            return true;
        }
        else{
            return false;
        }
    }
    //Caso más de una ficha colocada
    else{
        if (this->VaHorizontal){
            if(fila==referencia){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(columna==referencia){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
/**
 * @brief Tablero_Cliente::RemoverFichas Mueve las fichas colocadas a su posicin inicial
 */
void Tablero_Cliente::RemoverFichas()
{
    Node* tmp=this->FichasJugadas->getFirst();
    Ficha* F;
    int fila;
    int columna;
    int i = 0;
    while (tmp!=nullptr){
        F=(Ficha*)tmp->getData();
        fila=F->getFila();
        columna=F->getColumna();
        if (!F->getSeJugo()){
            this->FichasColocadas[fila][columna]=0;
            F->setX(F->xInicial);
            F->setY(F->yInicial);
            F->flagMove =true;
            if(*(F->ptrPosicionUnplayed + i)==0){
                *(F->ptrPosicionUnplayed + i)=1;
                 F->posInicial = i;
                }
        }

        tmp=tmp->getNext();
        i++;
    }
    delete(this->FichasJugadas);
    this->FichasJugadas=new LinkedList();
}

void Tablero_Cliente::print()
{
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            cout<<this->FichasColocadas[i][j]<<" ";
        }
        cout<<endl;
    }
}

LinkedList Tablero_Cliente::getFichasJugadas()
{
    return *FichasJugadas;
}

void Tablero_Cliente::RecibirRespuesta(string json)
{
    int p=0;
    TraductorCliente::getInstance().DeserializarRespuestaTurnoPropio(json,&Val,&HayFichas,&p,&repo,&resumen);
    if (Val==true) puntos+=p;
}
/**
 * @brief Tablero_Cliente::limpiarJugadas quita la lista de fichas utilizadas para luego ser reutilizada
 */

void Tablero_Cliente::limpiarJugadas()
{

    delete(this->FichasJugadas);
    this->FichasJugadas=new LinkedList();
}

void Tablero_Cliente::ColocarFicha(int *fila, int *columna, int tam)
{
    int aux = 0;
    while(aux<tam){
        this->FichasColocadas[*(fila+aux)][*(columna+aux)]=1;
        aux++;
    }
}
/**
 * @brief Tablero_Cliente::readInfo lee el txt con la ip, puerto y numero del experto
 */

void Tablero_Cliente::readInfo()
{
    QFile file(":/txt/txt/info.txt");
    if (!file.exists()){
        qDebug()<<"Error, no existe el archivo";
    }
    else{
        file.open(QFile::ReadOnly);
        QTextStream stream(&file);
        ip = stream.readLine();
        puerto = stream.readLine();
        expertoCel = stream.readLine();
    }
}
QString Tablero_Cliente::getIp(){
    return this->ip;
}

QString Tablero_Cliente::getPuerto()
{
    return this->puerto;
}

QString Tablero_Cliente::getExpertoCel()
{
    return this->expertoCel;
}

