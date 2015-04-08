#include <QTime>
#include <QTimer>

#include "shdigitclock.h"

SHDigitClock::SHDigitClock(QWidget *parent)
	:QLCDNumber(parent)
{
	setDigitCount(8);

	m_timer = new QTimer(this);
	QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(displayDigitClock()));
	m_timer->start(100);
}

void SHDigitClock::displayDigitClock()
{
	display(QTime::currentTime().toString("hh:mm:ss"));
}
