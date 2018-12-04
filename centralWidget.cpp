#include "centralWidget.h"

#define BACKGROUNDCOLOR_RELEASED "background-color: rgba(94, 0, 0, 0);"
#define BACKGROUNDCOLOR_DEFAULT  "background-color: rgba(0, 0, 94, 0);"

CentralWidget::CentralWidget():MAXNUMBER(99)
{
    bingoCore = new BingoCore;

    titleLabel = new QLabel("Bingo!");
    
    QVBoxLayout *mainLayout = new QVBoxLayout(); 
    QGridLayout *gridLayout = new QGridLayout;

    iconLabel = new QLabel("icon");
    gridLayout->addWidget(iconLabel, 0, 0);

    for(quint8 index = 0; index < 9; index++){
        numbersLabel.append(new QLabel(QString("%1").arg(index+1)));
        numbersLabel.last()->setStyleSheet(BACKGROUNDCOLOR_DEFAULT);
        gridLayout->addWidget(numbersLabel.last(),index / 10, (index % 10) + 1);
    }
    for(quint8 index = 9; index < MAXNUMBER; index++){
        numbersLabel.append(new QLabel(QString("%1").arg(index+1)));
        gridLayout->addWidget(numbersLabel.last(),index / 10, index % 10);
        numbersLabel.last()->setStyleSheet(BACKGROUNDCOLOR_DEFAULT);
    }

    startGame = new QPushButton(tr("Start new game"));
    connect(startGame, SIGNAL(clicked()), this, SLOT(newGame()));
    newNumber = new QPushButton(tr("Get new number"));
    connect(newNumber, SIGNAL(clicked()), this, SLOT(getNewNumber()));

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(startGame);
    bottomLayout->addWidget(newNumber);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}

CentralWidget::~CentralWidget()
{
}

void CentralWidget::newGame(void)
{

}

void CentralWidget::getNewNumber()
{
	quint8 number= bingoCore->getNewNumber();
    if(number > 0){
        setReleasedNumber(number);
    }else{
        QMessageBox::information(this, tr("End has ended"),
                tr("All numbers have been released, please restart new game"));
    }
}

void CentralWidget::setReleasedNumber(quint8 number)
{
    numbersLabel[number-1]->setStyleSheet(BACKGROUNDCOLOR_RELEASED);
}

void CentralWidget::restartGame(void)
{
    for(quint8 index = 0; index < numbersLabel.length(); index++){
        numbersLabel[index]->setStyleSheet(BACKGROUNDCOLOR_DEFAULT);
    }
    bingoCore->restartGame();
}
