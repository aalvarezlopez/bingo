#ifndef BINGOCORE_H
#define BINGOCORE_H

#include <QtWidgets>

class BingoCore
{
    public:
        BingoCore();
        ~BingoCore();
        quint8 getNewNumber(void);
        void getListOfNumbersReleased(QList<quint8> *list);
        bool endOfGame(void);
        void restartGame(void);
    private:
        QList<quint8> releasedNumbers;
        
        const quint8 MAXNUMBER;
};

#endif
