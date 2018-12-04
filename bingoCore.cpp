#include "bingoCore.h"

BingoCore::BingoCore():MAXNUMBER(99)
{
}

BingoCore::~BingoCore()
{
}


quint8 BingoCore::getNewNumber()
{
    bool notUsedFound = false;
    quint8 value;
    if(releasedNumbers.length() >= MAXNUMBER){
        value = 0;
    }else{
        value = (random() % MAXNUMBER) + 1;
        while(!notUsedFound){
            bool valueFound = false;
            for(quint8 index = 0; index < releasedNumbers.length(); index++){
                if( value == releasedNumbers.at(index) ){
                    valueFound = true;
                }
            }
            if(!valueFound){
                notUsedFound = true;
            }else{
                value = (random() % MAXNUMBER) + 1;
            }
        }
        releasedNumbers.append(value);
    }
    return value;
}

void BingoCore::getListOfNumbersReleased(QList<quint8> *list)
{
    *list = releasedNumbers;
}

bool BingoCore::endOfGame(void)
{
    return (releasedNumbers.length() >= MAXNUMBER);
}

void BingoCore::restartGame(void)
{
    releasedNumbers.clear();
}
