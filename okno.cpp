#include "okno.h"
#include <QGraphicsScene>

Okno::Okno()
{
    setGeometry(300,170,1200,700);
    setWindowTitle("Arduino Serialport Connection");

    scene = new Scena(this);
    ekran = new QGraphicsView(scene, this);

    scene->setSceneRect(0,0,1200,700);
    ekran->setGeometry(0,0,1200,700);

    ekran->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ekran->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Arduino.setPort(QSerialPortInfo::availablePorts().at(0));
    Arduino.setBaudRate(QSerialPort::Baud9600);
    Arduino.setDataBits(QSerialPort::Data8);
    Arduino.setParity(QSerialPort::NoParity);
    Arduino.setStopBits(QSerialPort::OneStop);
    Arduino.setFlowControl(QSerialPort::NoFlowControl);
    Arduino.open(QSerialPort::ReadOnly);

    lancuch_koncowy = "";
    QObject::connect(&Arduino, &QSerialPort::readyRead, this, &Okno::show);
}

void Okno::_show(){
    QByteArray arra = Arduino.readAll();
    lancuch_koncowy += arra;
    QStringList lista = lancuch_koncowy.split('-');

    if(lista.size() > 3){
        scene->Przesun(lista.at(0).toInt()/3);
        lancuch_koncowy.clear();
    }
}
