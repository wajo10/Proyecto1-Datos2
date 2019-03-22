#ifndef PANTALLA_H
#define PANTALLA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMouseEvent>

class pantalla: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pantalla(QGraphicsItem *parent=nullptr);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);

    int x,y;
signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();
};
#endif // PANTALLA_H
