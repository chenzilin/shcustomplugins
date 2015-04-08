#ifndef SHANALOGCLOCK_H
#define SHANALOGCLOCK_H

#include <QTime>
#include <QWidget>
#include <QPaintEvent>

class QColor;

class SHAnalogClock : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor hourHandColor READ hourHandColor WRITE setHourHandColor RESET resetHourHandColor)
    Q_PROPERTY(QColor minuteHandColor READ minuteHandColor WRITE setMinuteHandColor RESET resetMinuteHandColor)
    Q_PROPERTY(QColor secondHandColor READ secondHandColor WRITE setSecondHandColor RESET resetSecondHandColor)

    Q_PROPERTY(QColor diskRingColor READ diskRingColor WRITE setDiskRingColor RESET resetDiskRingColor)
    Q_PROPERTY(QColor sixtyPartsColor READ sixtyPartsColor WRITE setSixtyPartsColor RESET resetSixtyPartsColor)
    Q_PROPERTY(QColor twelvePartsColor READ twelvePartsColor WRITE setTwelvePartsColor RESET resetTwelvePartsColor)
    Q_PROPERTY(QColor timeDigitsColor READ timeDigitsColor WRITE setTimeDigitsColor RESET resetTimeDigitsColor)
    Q_PROPERTY(BackgroundImage backgroundImage READ backgroundImage WRITE setBackgroundImage RESET resetBackgroundImage)

    Q_ENUMS(BackgroundImage)

public:

    enum BackgroundImage{defaultImage, chick, mouse, dog, dragon, sheep, monkey, pig, tiger, snake, ox, rabbit, horse};

public:

    explicit SHAnalogClock(QWidget *parent = 0);

    QColor hourHandColor()const {return m_hourHandColor;}
    QColor minuteHandColor()const {return m_minuteHandColor;}
    QColor secondHandColor()const {return m_secondHandColor;}
    QColor diskRingColor()const {return m_diskRingColor;}
    QColor sixtyPartsColor()const {return m_sixtyPartsColor;}
    QColor twelvePartsColor()const {return m_twelvePartsColor;}
    QColor timeDigitsColor()const {return m_timeDigitsColor;}
    BackgroundImage backgroundImage()const {return m_backgroundImage;}

    void setHourHandColor(QColor color){m_hourHandColor = color; update();} 
    void setMinuteHandColor(QColor color){m_minuteHandColor = color; update();}
    void setSecondHandColor(QColor color){m_secondHandColor = color; update();}
    void setDiskRingColor(QColor color){m_diskRingColor = color; update();}
    void setSixtyPartsColor(QColor color){m_sixtyPartsColor = color; update();}
    void setTwelvePartsColor(QColor color){m_twelvePartsColor = color; update();}
    void setTimeDigitsColor(QColor color){m_timeDigitsColor = color; update();}
    void setBackgroundImage(BackgroundImage backgroundImage){m_backgroundImage = backgroundImage; update();}

    void resetHourHandColor(){setHourHandColor(Qt::green); update();}
    void resetMinuteHandColor(){setMinuteHandColor(Qt::blue); update();}
    void resetSecondHandColor(){setSecondHandColor(Qt::red); update();}
    void resetDiskRingColor(){setDiskRingColor(Qt::blue); update();}
    void resetSixtyPartsColor(){setSixtyPartsColor(Qt::red); update();}
    void resetTwelvePartsColor(){setTwelvePartsColor(Qt::green); update();}
    void resetTimeDigitsColor(){setTimeDigitsColor(Qt::blue); update();}
    void resetBackgroundImage(){setBackgroundImage(defaultImage); update();}

public slots:
    void setCurrentTime();
	void setTime(const QTime& time = QTime::currentTime());
	const QTime& currentTime()const;

protected:
	void paintEvent(QPaintEvent *);

private:
    QTime m_time;

    QColor m_hourHandColor;
    QColor m_minuteHandColor;
    QColor m_secondHandColor;

    QColor m_diskRingColor;
    QColor m_sixtyPartsColor;
    QColor m_twelvePartsColor;
    QColor m_timeDigitsColor;

    BackgroundImage m_backgroundImage;
};
#endif
