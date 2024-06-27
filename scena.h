#ifndef SCENA_H
#define SCENA_H

#include <QGraphicsScene>
#include "pasek_cm.h"

class Scena: public QGraphicsScene
{
    QGraphicsPixmapItem *obstacle;
    QGraphicsPixmapItem *echo;

    Pasek_cm *pasek;

public:
    Scena(QWidget *rodzic);

    void Przesun(int output_ardu);
};

#endif // SCENA_H
