#include "scena.h"
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QPixmap>

const int dodadtowa_stala = 0;

Scena::Scena(QWidget *rodzic)
{
    setParent(rodzic);
    QPixmap echo_txt;
    QPixmap obs_txt;
    echo_txt.load("C:/Users/chedo/OneDrive/Pulpit/RoadTxT/echo.png");
    obs_txt.load("C:/Users/chedo/OneDrive/Pulpit/RoadTxT/obstacle.png");

    echo = new QGraphicsPixmapItem(echo_txt);
    addItem(echo);
    obstacle = new QGraphicsPixmapItem(obs_txt);
    addItem(obstacle);

    echo->setScale(0.6);
    echo->setPos(50,150);

    obstacle->setScale(0.7);
    obstacle->setPos(1000,110);

    pasek = new Pasek_cm(this);
}

void Scena::Przesun(int output_ardu)
{
    obstacle->setPos(echo->pos().x()+echo->pixmap().size().width()*0.6+output_ardu+dodadtowa_stala
                     ,obstacle->pos().y());
    pasek->update_lenght(obstacle->pos().x()-echo->pos().x()-echo->pixmap().size().width()*0.6);
}
