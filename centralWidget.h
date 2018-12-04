#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtWidgets>
#include "bingoCore.h"

class CentralWidget: public QWidget
{
    Q_OBJECT
 public:
        CentralWidget();
        ~CentralWidget();
private slots:
	void newGame(void);
	void getNewNumber(void);
private:
	QLabel *titleLabel;
	QLabel *iconLabel;
        QList<QLabel*> numbersLabel;
        const quint8 MAXNUMBER;
	QPushButton *startGame;
	QPushButton *newNumber;
	BingoCore *bingoCore;

	void setReleasedNumber(quint8 number);
	void restartGame(void);
};

#endif
