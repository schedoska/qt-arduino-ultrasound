#ifndef OKNO_H
#define OKNO_H

#include <QWidget>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "scena.h"
#include <QGraphicsView>


class Okno: public QWidget
{
public:
    QSerialPort Arduino;
    Okno();
    QString lancuch_koncowy;

    Scena *scene;
    QGraphicsView *ekran;

signals:
    void _show();
};

#endif // OKNO_H
