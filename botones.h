#ifndef BOTONES_H
#define BOTONES_H

#include <QObject>
#include <QGraphicsPixmapItem>

class botones: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    botones (QGraphicsItem *parent=nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // BOTONES_H
