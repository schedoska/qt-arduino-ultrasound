#include "okno.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Okno okno;
    okno.show();
    return a.exec();
}
