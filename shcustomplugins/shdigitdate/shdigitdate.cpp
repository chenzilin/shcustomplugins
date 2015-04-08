#include <QDate>
#include <QTimer>

#include "shdigitdate.h"

SHDigitDate::SHDigitDate(QWidget *parent)
	:QLCDNumber(parent)
{
	setDigitCount(10);

	m_timer = new QTimer(this);
	QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(displayDate()));
	m_timer->start(1000);
}

void SHDigitDate::displayDate()
{
	display(QDate::currentDate().toString("yyyy:MM:dd"));
}
