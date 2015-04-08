#include <QPen>
#include <QTime>
#include <QRect>
#include <QColor>
#include <QImage>
#include <QBrush>
#include <QString>
#include <QPainter>
#include <QPolygon>

#include "shanalogclock.h"

SHAnalogClock::SHAnalogClock(QWidget *parent) :
    QWidget(parent)
{
    this->m_hourHandColor = Qt::green;
    this->m_minuteHandColor =  Qt::blue;
    this->m_secondHandColor = Qt::red;
    this->m_diskRingColor = Qt::blue;
    this->m_sixtyPartsColor = Qt::red;
    this->m_twelvePartsColor = Qt::green;
    this->m_timeDigitsColor = Qt::blue;

    this->setCurrentTime();
}

void SHAnalogClock::setCurrentTime()
{
    this->setTime();
}

void SHAnalogClock::setTime(const QTime& time)
{
    this->m_time = time;
    this->repaint();
}

const QTime& SHAnalogClock::currentTime()const
{
    return this->m_time;
}


void SHAnalogClock::paintEvent(QPaintEvent *)
{
    QPen pen;
    QFont font;
    QPolygon polygon;
    QPainter painter(this);

    // set ths min of width and height as the radius
    int radius = ::qMin(this->width(), this->height() ) / 2;
    painter.setRenderHint(QPainter::Antialiasing);

    // draw background image
    painter.save();
    QRect rect(0, 0, 2*radius, 2*radius);
    switch(this->backgroundImage())
    {
    case dragon:
    {
        QImage imageDragon(":/image/dragon.svg");
        painter.drawImage(rect, imageDragon, imageDragon.rect() );
        break;
    }
    case snake:
    {
        QImage imageSnake(":/image/snake.svg");
        painter.drawImage(rect, imageSnake, imageSnake.rect() );
        break;
    }
    case chick:
    {
        QImage imageChick(":/image/chick.svg");
        painter.drawImage(rect, imageChick, imageChick.rect() );
        break;
    }
    case pig:
    {
        QImage imagePig(":/image/pig.svg");
        painter.drawImage(rect, imagePig, imagePig.rect() );
        break;
    }
    case sheep:
    {
        QImage imageSheep(":/image/sheep.svg");
        painter.drawImage(rect, imageSheep, imageSheep.rect() );
        break;
    }
    case tiger:
    {
        QImage imageTiger(":/image/tiger.svg");
        painter.drawImage(rect, imageTiger, imageTiger.rect() );
        break;
    }
    case mouse:
    {
        QImage imageMouse(":/image/mouse.svg");
        painter.drawImage(rect, imageMouse, imageMouse.rect() );
        break;
    }
    case horse:
    {
        QImage imageHorse(":/image/horse.svg");
        painter.drawImage(rect, imageHorse, imageHorse.rect() );
        break;
    }
    case ox:
    {
        QImage imageOx(":/image/ox.svg");
        painter.drawImage(rect, imageOx, imageOx.rect() );
        break;
    }
    case dog:
    {
        QImage imageDog(":/image/dog.svg");
        painter.drawImage(rect, imageDog, imageDog.rect() );
        break;
    }
    case rabbit:
    {
        QImage imageRabbit(":/image/rabbit.svg");
        painter.drawImage(rect, imageRabbit, imageRabbit.rect() );
        break;
    }
    case monkey:
    {
        QImage imageMonkey(":/image/monkey.svg");
        painter.drawImage(rect, imageMonkey, imageMonkey.rect() );
        break;
    }
    case defaultImage:
    {
        QImage imageDefault(":/image/defaultImage.svg");
        painter.drawImage(rect, imageDefault, imageDefault.rect() );
        break;
    }
    default:
    {
        QImage imageDefault(":/image/defaultImage.svg");
        painter.drawImage(rect, imageDefault, imageDefault.rect() );
        break;
    }
    }
    painter.restore();

    //move center point
    painter.translate(radius, radius);

    // draw diskRing
    painter.save();
    painter.setPen(m_diskRingColor);
    painter.drawEllipse(QPoint(0, 0), radius, radius);
    painter.restore();

    // draw sixty parts
    painter.save();
    pen.setWidth(radius / 80);
    pen.setColor(m_sixtyPartsColor);
    pen.setBrush(QBrush(m_sixtyPartsColor));
    painter.setPen(pen);
    for(int i = 0; i < 60; ++i)
    {
        painter.drawLine(QPoint(radius - radius / 20, 0), QPoint(radius - radius / 64, 0));
        painter.rotate(6.0);
    }
    painter.restore();

    // draw twelve parts
    painter.save();
    pen.setWidth(radius / 32);
    pen.setColor(m_twelvePartsColor);
    pen.setBrush(m_twelvePartsColor);
    painter.setPen(pen);

    for(int i =0; i < 12; ++i)
    {
        painter.drawLine(QPoint(radius - radius / 9, 0), QPoint(radius - radius / 64, 0));
        painter.rotate(30.0);
    }
    painter.restore();


    // draw time digits
    painter.save();
    font.setPointSize(radius / 10);
    pen.setWidth(radius / 16);
    pen.setColor(m_timeDigitsColor);
    pen.setBrush(m_timeDigitsColor);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(QPointF(radius - radius / 5, radius / 17), QString("3"));
    painter.drawText(QPointF(-(radius - radius / 8), radius / 17), QString("9"));
    painter.drawText(QPointF(- radius / 20, radius - radius / 8), QString("6"));
    painter.drawText(QPointF(- radius / 14, -(radius - radius / 5)), QString("12"));
    painter.drawText(QPointF(radius / 2.8, -(radius - radius / 3)), QString("1"));
    painter.drawText(QPointF(radius / 2.8, radius - radius / 4), QString("5"));
    painter.drawText(QPointF(-radius / 2.2, radius - radius / 4), QString("7"));
    painter.drawText(QPointF(-radius / 2.2, -(radius - radius / 3)), QString("11"));
    painter.drawText(QPointF(radius - radius / 3, -radius / 2.5), QString("2"));
    painter.drawText(QPointF(radius - radius / 3, radius / 2.2), QString("4"));
    painter.drawText(QPointF(-(radius - radius / 4.2), radius / 2.2), QString("8"));
    painter.drawText(QPointF(-(radius - radius / 4.2), -radius / 2.5), QString("10"));
    painter.restore();

    painter.save();
    painter.rotate(-90.0);

    // draw hour hand
    painter.save();
    painter.rotate(30.0 * (this->m_time.hour() + this->m_time.minute() / 60.0 ));
    painter.setBrush(m_hourHandColor);
    polygon.clear();
    polygon << QPoint(0, 0) << QPoint(radius / 10, radius / 10) << QPoint(radius - radius / 4, 0) << QPoint(radius / 10, -radius / 10);
    painter.drawPolygon(polygon);
    painter.restore();

    // draw minute hand
    painter.save();
    painter.rotate(6.0 * (this->m_time.minute() + this->m_time.second() / 60.0) );
    painter.setBrush(m_minuteHandColor);
    polygon.clear();
    polygon << QPoint(0, 0) << QPoint(radius / 20, radius / 20) << QPoint(radius - radius / 8, 0) << QPoint(radius / 20, -radius / 20);
    painter.drawPolygon(polygon);
    painter.restore();

    // draw second hand
    painter.save();
    painter.rotate(6.0 * this->m_time.second());
    painter.setBrush(m_secondHandColor);
    polygon.clear();
    polygon << QPoint(0, 0) << QPoint(radius / 30, radius / 30) << QPoint(radius - radius / 15, 0) << QPoint(radius / 30, -radius / 30);
    painter.drawPolygon(polygon);
    painter.restore();

    painter.restore();
}
