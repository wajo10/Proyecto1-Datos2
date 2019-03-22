#ifndef FICHA_H
#define FICHA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class ficha: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ficha(QGraphicsItem *parent=nullptr);
    ficha(char letra = 'A');
    void keyPressEvent(QKeyEvent *event);

};
#endif // FICHA_H
