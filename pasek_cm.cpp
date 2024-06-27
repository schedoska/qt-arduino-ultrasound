#include "pasek_cm.h"
#include <QPen>
#include <QPolygon>
#include <QBrush>
#include <QtDebug>
#include <QFont>

#define SKALA 2

void Pasek_cm::int_strzalki()
{
    QPen dlugosz(Qt::NoPen);
    QBrush pedzel(Qt::black);
    pedzel.setColor(QColor(80,80,80));

    QPolygon lewa_trzala;
    lewa_trzala << QPoint(-5,0) << QPoint(0,-5) << QPoint(0,5);
    strzalka_lewa = new QGraphicsPolygonItem;
    strzalka_lewa->setPolygon(lewa_trzala);
    strzalka_lewa->setPen(dlugosz);
    strzalka_lewa->setBrush(pedzel);
    strzalka_lewa->setPos(50,50);
    strzalka_lewa->setScale(SKALA);

    QPolygon prawa_trzala;
    prawa_trzala << QPoint(5,0) << QPoint(0,-5) << QPoint(0,5);
    strzalka_prawa = new QGraphicsPolygonItem;
    strzalka_prawa->setPolygon(prawa_trzala);
    strzalka_prawa->setPen(dlugosz);
    strzalka_prawa->setBrush(pedzel);
    strzalka_prawa->setPos(50,50);
    strzalka_prawa->setScale(SKALA);

    napis = new QGraphicsSimpleTextItem;
    QFont czcionka("Arial",20,QFont::Bold);
    napis->setFont(czcionka);
    napis->setBrush(pedzel);
}

Pasek_cm::Pasek_cm(QGraphicsScene *scn)
{
    QPen dlugosz;
    dlugosz.setWidth(3);
    dlugosz.setStyle(Qt::DashLine);
    dlugosz.setColor(QColor(80,80,80));
    setPen(dlugosz);

    setPos(330,580);
    scn->addItem(this);

    int_strzalki();

    scn->addItem(strzalka_lewa);
    scn->addItem(strzalka_prawa);
    scn->addItem(napis);
}

void Pasek_cm::update_lenght(int dlugosc)
{
    setLine(0,0,dlugosc+80,0);

    strzalka_lewa->setPos(pos().x() - 5,580);

    strzalka_prawa->setPos(pos().x()+line().length() + 5, 580);

    napis->setText(QString::number(dlugosc*0.034*3/2) + " cm");
    napis->setPos(pos().x() + line().center().x() - 35, 610);
}
