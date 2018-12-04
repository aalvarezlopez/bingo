#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "centralWidget.h"

class Mainwindow : public QMainWindow
{
Q_OBJECT
public:
    Mainwindow();
    ~Mainwindow();
private:
    QWidget* centralWidget;
};

#endif
