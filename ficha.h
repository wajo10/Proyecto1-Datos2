#ifndef FICHA_H
#define FICHA_H


class Ficha
{
private:
    char letra;
    int Fila;
    int Columna;
    int Valor;
public:
    Ficha(char letra);
    Ficha(int Fila,int Columna,char letra);
    char getLetra() const;
    void setLetra(char value);
    int getFila() const;
    void setFila(int value);
    int getColumna() const;
    void setColumna(int value);
    int getValor() const;
    void setValor(int value);
};

#endif // FICHA_H
