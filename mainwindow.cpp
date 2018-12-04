#include "mainwindow.h"

Mainwindow::Mainwindow()
{
    centralWidget = new CentralWidget();
    setCentralWidget(centralWidget);
}

Mainwindow::~Mainwindow()
{
}
