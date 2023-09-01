#include <QtGui>
#include "randomwalk.h"

RandomWalk::RandomWalk(QWidget * parent) : QWidget(parent)
{
	init = true;
	resized=0;
	timer = new QTimer(this);
    connect ( timer, SIGNAL(timeout()), this, SLOT( walk() ) );
    setPalette(QPalette(QColor(250, 250, 250)));
    setAutoFillBackground(true);
}

void RandomWalk::walk()
{
	//srand((unsigned)time(0)); do not use this in THIS program!!!
    double random = (double)rand()/RAND_MAX;
    if (random < 0.25 )
		x += stepLength;
    if (random >= 0.25 && random < 0.5 )
        x -= stepLength;
    if (random >= 0.5 && random < 0.75 )
        y += stepLength;
    if (random > 0.75 )
		y -= stepLength;

	if (y == y0)
		updateRegion = QRegion(qMin(x0, x), y0-stepLength, stepLength, 2*stepLength,
							QRegion::Ellipse);
	if (x == x0)
		updateRegion = QRegion(x0-stepLength, qMin(y,y0), 2*stepLength, stepLength,
							QRegion::Ellipse);
	update(updateRegion);

}


void RandomWalk::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
	QPen pen(Qt::red);
    painter.setPen(pen);
	if ( init || resized) {
		x0 = width() / 2;
		y0 = height() / 2;
		x = width() / 2;
		y = height() / 2;
		init = false;
		resized=0;
	}
	painter.drawLine(x0, y0, x, y); 
	x0 = x;
	y0 = y;
}

QTimer * RandomWalk::walkTimer()
{
        return timer;
}


void RandomWalk::resetInit()
{
	init=true;
}

void RandomWalk::resizeEvent ( QResizeEvent * /*event*/ )   
{
    resized = 1;
}

void RandomWalk::setStepLength(int len)
{
	stepLength = len;
}

