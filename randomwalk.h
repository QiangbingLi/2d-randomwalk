#ifndef RANDOMWALK_H
#define RANDOMWALK_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class RandomWalk : public QWidget
{
	Q_OBJECT

	public:
		RandomWalk(QWidget* parent=0);
		void paintEvent(QPaintEvent *);
		QTimer* walkTimer();
		void resetInit();
		void resizeEvent ( QResizeEvent * /*event*/ ); 
		void setStepLength(int);
	public slots:
		void walk();
	private:
		int x0, y0;
		int x, y;
		int stepLength;
		QTimer* timer;
		bool init;
		bool resized;
		QRegion updateRegion;

};
#endif
