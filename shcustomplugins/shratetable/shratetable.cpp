#include "shratetable.h"

#include <QPen>
#include <QSize>
#include <QFont>
#include <QBrush>
#include <QColor>
#include <QRectF>
#include <QPoint>
#include <QString>
#include <QPointF>
#include <QPainter>
#include <QPolygon>

SHRateTable::SHRateTable(QWidget *parent) :
    QWidget(parent)
{
    this->m_rate = 0.00;

    this->m_indicatorHandColor = Qt::green;
    this->m_diskRingColor = Qt::black;
    this->m_digitsColor = Qt::blue;
    this->m_rateDigitsColor = Qt::blue;
}

void SHRateTable::paintEvent(QPaintEvent *)
{
    // set ths min of width and height as the radius
    float radius = ::qMin(this->width(), this->height() ) / 2.0;

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QPen pen;
    QFont font;
    QPolygon polygon;

    // draw background image
    painter.save();
    QRectF rect(0, 0, 2*radius, 2*radius);
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
    painter.drawEllipse(QPointF(0, 0), radius, radius);
    painter.restore();

    //draw parts line
    painter.save();
    painter.rotate(150.0);

    painter.save();
    for(int i =1; i <= 33; i += 4)
    {
        pen.setWidth(5);
        pen.setColor(Qt::blue);
        painter.setPen(pen);
        painter.setBrush(Qt::blue);
        painter.drawLine(QPoint(radius * 6.5 / 8.0, 0), QPoint(radius - 1.0, 0));
        painter.rotate(30);
    }
    painter.restore();

    painter.save();
    painter.rotate(7.5);
    for(int i =2; i <= 32; i += 2)
    {
        pen.setWidth(2);
        pen.setColor(Qt::red);
        painter.setPen(pen);
        painter.setBrush(Qt::red);
        painter.drawLine(QPoint(radius * 7.4 / 8.0, 0), QPoint(radius - 1.0, 0));
        painter.rotate(15.0);
    }
    painter.restore();

    painter.save();
    painter.rotate(15.0);
    for(int i =3; i <= 31; i += 4)
    {
        pen.setWidth(4);
        pen.setColor(Qt::green);
        painter.setPen(pen);
        painter.setBrush(Qt::green);
        painter.drawLine(QPoint(radius * 7.0 / 8.0, 0), QPoint(radius - 1.0, 0));
        painter.rotate(30.0);
    }
    painter.restore();

    painter.restore();

    //draw rate digits
    painter.save();
    font.setPointSize(radius/12.0);
    painter.setFont(font);
    painter.setPen(m_rateDigitsColor);
    painter.setBrush(m_rateDigitsColor);
    painter.drawText(-radius*2.0/16.0, -radius*6.5/8.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("80"));
    painter.drawText(-radius*6.8/8.0, -radius*1.0/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("20"));
    painter.drawText(radius*4.5/8.0, -radius*1.0/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("140"));
    painter.drawText(-radius*6.1/8.0, radius*5.2/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("0"));
    painter.drawText(radius*3.6/8.0, radius*5.2/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("160"));
    painter.drawText(-radius*6.1/8.0, -radius*6.8/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("40"));
    painter.drawText(radius*3.6/8.0, -radius*6.8/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("120"));
    painter.drawText(radius*2.0/8.0, -radius*11.0/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("100"));
    painter.drawText(-radius*4.0/8.0, -radius*11.0/16.0, radius*2.0/8.0, radius*1.0/8.0,
                      Qt::AlignCenter , QString("60"));
    painter.restore();

    //draw (km/h Rate Table)
    painter.save();
    pen.setColor(m_digitsColor);
    font.setPointSize(radius/14.0);
    painter.setPen(pen);
    painter.setFont(font);
    painter.setBrush(m_digitsColor);
    painter.drawText(-radius/4.0, -radius*2.0/3.0, radius*4.0/8.0, radius*3.0/8.0,
                      Qt::AlignCenter , QString("km/h\n Rate Table"));

    font.setPointSize(radius/12.0);

    painter.setPen(Qt::black);
    painter.setFont(font);
    painter.setBrush(Qt::white);
    painter.drawRect(-radius/3.0, radius*1.0/3.0, radius*2.0/3.0, radius*1.5/8.0);
    painter.setPen(m_digitsColor);
    painter.setBrush(m_digitsColor);
    QString str;
    str.setNum(this->m_rate, 'f',2);
    str += " km/h";
    painter.drawText(-radius/3.0, radius*0.74/3.0, radius*2.0/3.0, radius*3.0/8.0,
                      Qt::AlignCenter , str);
    painter.restore();

    //draw the indicator hand
    painter.save();
    polygon<<QPoint(0, 0)<<QPoint(radius / 16.0,radius / 16.0)<<QPoint(radius * 7.5 / 8.0, 0)
           <<QPoint(radius / 16.0, -radius / 16.0);
    painter.setBrush(m_indicatorHandColor);
    painter.rotate(this->m_rate*3.0/2.0 + 150.0);
    painter.drawPolygon(polygon);
    painter.restore();
}

void SHRateTable::setRate(const float rate)
{
    this->m_rate = rate;
    this->repaint();
}

float SHRateTable::rate()const
{
    return this->m_rate;
}
