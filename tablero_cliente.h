#ifndef TABLERO_CLIENTE_H
#define TABLERO_CLIENTE_H

#include "ficha.h"
#include "linkedlist.h"
#include <string>
using namespace std;
#include "traductorcliente.h"


class Tablero_Cliente
{
private:
    //______________
    //Atributos propios del objeto
    bool FichasColocadas[15][15];
    string nombre;
    LinkedList* FichasJugadas;
    int puntos;
    int turno;
    int c =0;

    //______________
    //Atributos de implementación
    bool VaHorizontal;
    int referencia;
    int menor;
    bool HayFichas=true;
    bool Val;
    QString ip;
    QString puerto;
    QString expertoCel;
    string repo;
    string resumen;
    int puertoServidor;
    int tsala;

    //______________
    //Métodos internos
    Tablero_Cliente();
    bool VerificarPos(int fila, int columna);
    bool VerificarSentido(int fila,int columna);
public:
    //______________
    //Métodos propios del objeto
    string ResumenFichas(); 
    void RemoverFichas();
    void RecibirRespuesta(string json);
    void limpiarJugadas();
    void ColocarFicha(int*,int*,int);
    bool JugarFicha(Ficha* F,int fila, int columna);

    //______________
    //Métodos de implementación
    void readInfo();
    void print();
    static Tablero_Cliente& getInstance(){
        static Tablero_Cliente instance;
        return instance;
    }
    LinkedList getFichasJugadas();
    bool getHayFichas() const;
    void setHayFichas(bool value);
    bool getVal() const;
    void setVal(bool value);
    string getRepo() const;
    void setRepo(const string &value);
    QString getIp();
    QString getPuerto();
    QString getExpertoCel();
    int getPuertoServidor() const;
    void setPuertoServidor(int value);
    int getTurno() const;
    void setTurno(int value);
    int getTsala() const;
    void setTsala(int value);
    int getPuntos() const;
    void setPuntos(int value);
    string getResumen() const;
    void setResumen(const string &value);
    int getC() const;
    void setC(int value);
};

#endif // TABLERO_CLIENTE_H
