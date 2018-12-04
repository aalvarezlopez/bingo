#include <QApplication>
#include "mainwindow.h"

#define CORE
#ifdef CORE
#include "bingoCore.h"
#endif

int main(int argc, char **argv)
{
#ifndef CORE
    QApplication a(argc, argv);
    Mainwindow *mainwindow = new Mainwindow;
    mainwindow->showMaximized();
#else
    QCoreApplication a(argc, argv);
    BingoCore *bingoCore = new BingoCore;
    for(quint8 i = 0; i < 105; i++){
        qDebug() << bingoCore->getNewNumber();
    }
#endif

    return a.exec();
}
