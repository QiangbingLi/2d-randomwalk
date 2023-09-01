#ifndef MainWidget_H
#define MainWidget_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <randomwalk.h>

class MainWidget : public QWidget
{
	Q_OBJECT

	public:
		MainWidget(QWidget* parent=0);

	public slots:
		void start();
		void stop();
		void reset();
	private:
		RandomWalk * drawPanel;
		QPushButton * startButton;
		QPushButton * stopButton;
		QPushButton * resetButton;
	    QLineEdit * stepEdit;
        QLineEdit * timeEdit;
        QLabel * stepLabel;
        QLabel * timeLabel;
		int interval;

};
#endif
