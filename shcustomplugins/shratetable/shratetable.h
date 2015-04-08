#ifndef SHRATETABLE_H
#define SHRATETABLE_H

#include <QWidget>

class QColor;

class SHRateTable : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor indicatorHandColor READ indicatorHandColor WRITE setIndicatorHandColor RESET resetIndicatorHandColor)
    Q_PROPERTY(QColor diskRingColor READ diskRingColor WRITE setDiskRingColor RESET resetDiskRingColor)
    Q_PROPERTY(QColor digitsColor READ digitsColor WRITE setDigitsColor RESET resetDigitsColor)
    Q_PROPERTY(QColor rateDigitsColor READ rateDigitsColor WRITE setRateDigitsColor RESET resetRateDigitsColor)
    Q_PROPERTY(BackgroundImage backgroundImage READ backgroundImage WRITE setBackgroundImage RESET resetBackgroundImage)

    Q_ENUMS(BackgroundImage)

public:
    enum BackgroundImage{defaultImage, chick, mouse, dog, dragon, sheep, monkey, pig, tiger, snake, ox, rabbit, horse};

public:
    explicit SHRateTable(QWidget *parent = 0);
	void setRate(const float);
	float rate()const;

    QColor indicatorHandColor()const {return m_indicatorHandColor;}
    QColor diskRingColor()const {return m_diskRingColor;}
    QColor digitsColor()const {return m_digitsColor;}
    QColor rateDigitsColor()const {return m_rateDigitsColor;}
    BackgroundImage backgroundImage()const {return m_backgroundImage;}

    void setIndicatorHandColor(QColor color){m_indicatorHandColor = color; update();}
    void setDiskRingColor(QColor color){m_diskRingColor = color; update();}
    void setDigitsColor(QColor color){m_digitsColor = color; update();}
    void setRateDigitsColor(QColor color){m_rateDigitsColor = color; update();}
    void setBackgroundImage(BackgroundImage backgroundImage){m_backgroundImage = backgroundImage; update();}


    void resetIndicatorHandColor(){setIndicatorHandColor(Qt::green); update();}
    void resetDiskRingColor(){setDiskRingColor(Qt::black); update();}
    void resetDigitsColor(){setDigitsColor(Qt::blue); update();}
    void resetRateDigitsColor(){setRateDigitsColor(Qt::blue); update();}
    void resetBackgroundImage(){setBackgroundImage(defaultImage); update();}
protected:
    void paintEvent(QPaintEvent *);

private:
    float m_rate;

    QColor m_indicatorHandColor;
    QColor m_diskRingColor;
    QColor m_digitsColor;
    QColor m_rateDigitsColor;
    BackgroundImage m_backgroundImage;
};
#endif
