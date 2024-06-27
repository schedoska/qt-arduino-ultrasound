#ifndef PASEK_CM_H
#define PASEK_CM_H

#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>

class Pasek_cm: public QGraphicsLineItem
{
    QGraphicsPolygonItem *strzalka_prawa;
    QGraphicsPolygonItem *strzalka_lewa;

    QGraphicsSimpleTextItem *napis;

    void int_strzalki();

public:
    Pasek_cm(QGraphicsScene *scn);

    void update_lenght(int dlugosc);
};

#endif // PASEK_CM_H
