#ifndef SHDIGITCLOCK_H
#define SHDIGITCLOCK_H

#include <QLCDNumber>

class QTimer;

class SHDigitClock : public QLCDNumber
{
	Q_OBJECT
public:
	explicit SHDigitClock(QWidget *parent = 0);
    ~SHDigitClock(){}
	
private slots:
	void displayDigitClock();

private:
	QTimer *m_timer;
};

#endif
