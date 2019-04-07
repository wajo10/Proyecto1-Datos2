#ifndef FICHA_H
#define FICHA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>



class Ficha: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    char letra;
    int Fila;
    int Columna;
    int Valor;
    bool seJugo = false;
    static int posiciones[7];
public:
    Ficha(QGraphicsItem *parent=nullptr);
    int yInicial, xInicial, fila, columna, posInicial;
    /**
     * @brief agregar agrega graficamente las fichas con su imagen respectiva
     * @param x
     * @param y
     * @return
     */
    int *agregar(int x, int y);

    int inicial = 44;//Espacio antes de las celdas

    Ficha(char letra);
    /**
     * @brief Ficha Constructor de ficha con fila y columna
     * @param Fila
     * @param Columna
     * @param letra
     */
    Ficha(int Fila,int Columna,char letra);

    char getLetra() const;
    void setLetra(char value);
    int getFila() const;
    void setFila(int value);
    int getColumna() const;
    void setColumna(int value);
    int getValor() const;
    void setValor(int value);
    bool flagMove = true;
    static int *getFichasIniciales();
    static int Puntos(char letra);
    static int *ptrPosicionUnplayed;
    void setUnplayed();
    void setPlayed();
    bool getSeJugo();
    void setSejugo(bool);
    static bool flagTurno;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


};
#endif // FICHA_H

