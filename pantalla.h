#ifndef PANTALLA_H
#define PANTALLA_H
#include <QObject>
#include <QGraphicsPixmapItem>

class pantalla: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pantalla(QGraphicsItem *parent=nullptr);

};
#endif // PANTALLA_H
