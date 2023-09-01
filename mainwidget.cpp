#include <QtGui>
#include "mainwidget.h"
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget * parent) : QWidget(parent)
{
	setWindowTitle(tr("Random walk simulator"));
	resize(700,400);
	drawPanel = new RandomWalk(this);
    QFrame *drawBox = new QFrame;
    drawBox->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
    QVBoxLayout *drawLayout = new QVBoxLayout;
    drawLayout->addWidget(drawPanel);
    drawBox->setLayout(drawLayout);

    stepLabel = new QLabel( tr( "Step length:" ) );
    stepEdit = new QLineEdit; 
    QIntValidator* stepValidator = new QIntValidator(1, 100, stepEdit);
    stepEdit->setValidator(stepValidator);
    stepEdit->setText("10");
    stepLabel->setBuddy(stepEdit);

    timeLabel = new QLabel( tr( "Timer (ms)" ) );
    timeEdit = new QLineEdit; 
    QIntValidator* timeValidator=new QIntValidator(1, 10000, timeEdit);
    timeEdit->setValidator(timeValidator);
    timeEdit->setText("1000");
    stepLabel->setBuddy(stepEdit);

	startButton = new QPushButton;
	startButton -> setText(tr("start"));
 	stopButton = new QPushButton;
	stopButton -> setText(tr("stop"));
	stopButton->setEnabled(false);
	resetButton = new QPushButton;
	resetButton-> setText(tr("reset"));
	resetButton-> setEnabled(false);
	
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(drawBox, 0, 0, 8, 1);
    gridLayout->addWidget(stepLabel, 0, 1);
    gridLayout->addWidget(stepEdit, 0, 2);
    gridLayout->addWidget(timeLabel, 1, 1);
    gridLayout->addWidget(timeEdit, 1, 2);
    gridLayout->addWidget(startButton, 5, 2);
    gridLayout->addWidget(stopButton, 6, 2);
    gridLayout->addWidget(resetButton, 7, 2);
    gridLayout->setColumnStretch(0, 15);
	setLayout(gridLayout);

	connect(startButton, SIGNAL(clicked()), this, SLOT( start() ) );
	connect(stopButton, SIGNAL(clicked()), this, SLOT( stop() ) );
	connect(resetButton, SIGNAL(clicked()), this, SLOT( reset() ) );
}


void MainWidget::start()
{
    QVariant sVar(stepEdit->text());
    QVariant tVar(timeEdit->text());
    int s = sVar.toInt();
    int t = tVar.toInt();
    drawPanel->setStepLength(s);
	drawPanel->walkTimer()->start(t);
    startButton->setEnabled(false);
    stopButton->setEnabled(true);
    resetButton->setEnabled(true);

}

void MainWidget::stop()
{
	drawPanel->walkTimer()->stop();
    startButton->setEnabled(true);
    stopButton->setEnabled(false);
    resetButton->setEnabled(true);

}

void MainWidget::reset()
{
	if ( drawPanel->walkTimer()->isActive() )
		drawPanel->walkTimer()->stop(); 
	startButton->setEnabled(true);
 	drawPanel->resetInit();
	drawPanel->update();   
}




