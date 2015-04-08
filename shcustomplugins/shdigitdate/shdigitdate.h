#ifndef SHDIGITDATE_H
#define SHDIGITDATE_H

#include <QLCDNumber>

class QTimer;

class SHDigitDate : public QLCDNumber
{
	Q_OBJECT

public:
    explicit SHDigitDate(QWidget *parent = 0);
    ~SHDigitDate(){}

private slots:
	void displayDate();

private:
	QTimer *m_timer;
};

#endif
