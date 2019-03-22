#ifndef FICHA_H
#define FICHA_H


#include <QObject>
#include <QGraphicsPixmapItem>

class ficha: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ficha(QGraphicsItem *parent=nullptr);
    ficha(char letra = 'A');
};
#endif // PANTALLA_H
