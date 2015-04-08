#include <QRectF>
#include <QPointF>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QMessageBox>

#include "shslider.h"

SHSlider::SHSlider(QWidget *parent) :
    QWidget(parent)
{
    this->m_value = 0;
    this->m_maxValue = 99;
    this->m_sliderRect.setRect(this->width()/2-25, (this->height()-14)*(m_maxValue-m_value)/m_maxValue+2, 50, 10);
    this->m_mousePressPositionInSliderRect = false;
    this->m_stretchingDirection = horizontal;
}


void SHSlider::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    switch (m_stretchingDirection) {
    case horizontal:
    {
        //draw background image
        painter.drawImage(QRectF(2.0, this->height()/2.0-5.0, this->width()-4.0, 10.0)
                          , QImage(":/image/horizontal_background.svg"));
        //draw foreground image
        painter.drawImage(QRectF(2.0, this->height()/2.0-3.0, (this->width()-4.0)*m_value/m_maxValue, 8.0)
                          , QImage(":/image/horizontal_foreground.svg"));
        //draw slider image
        m_sliderRect.setRect((this->width()-12.0)*m_value/m_maxValue, this->height()/2.0-25.0, 10.0, 50.0);
        painter.drawImage(m_sliderRect, QImage(":/image/horizontal_slider.svg"));

        break;
    }
    case vertical:
    {
        //draw background image
        painter.drawImage(QRectF(this->width()/2.0-5.0, 2.0, 10.0, this->height()-4.0)
                          , QImage(":/image/vertical_background.svg"));
        //draw foreground image
        painter.drawImage(QRectF(this->width()/2.0-3.0, (this->height()-14.0)*(m_maxValue-m_value)/m_maxValue+2.0, 8.0, this->height()-4.0-((this->height()-14.0)*(m_maxValue-m_value)/m_maxValue+2.0) )
                          , QImage(":/image/vertical_foreground.svg"));
        //draw slider image
        m_sliderRect.setRect(this->width()/2.0-25.0, (this->height()-14.0)*(m_maxValue-m_value)/m_maxValue+2.0, 50.0, 10.0);
        painter.drawImage(m_sliderRect, QImage(":/image/vertical_slider.svg"));

        break;
    }
    default:
    {
        break;
    }
    }
}

void SHSlider::mousePressEvent(QMouseEvent *event)
{
    if(m_sliderRect.contains(event->pos()))
    {
        m_mousePressPositionInSliderRect = true;
    }
    else
    {
        m_mousePressPositionInSliderRect = false;
    }
}

void SHSlider::mouseReleaseEvent(QMouseEvent *event)
{
    if(true == m_mousePressPositionInSliderRect)
    {
        switch (m_stretchingDirection) {
        case horizontal:
        {
            if(2 >= event->pos().x())
            {
                setValue(0);
            }
            else if(this->width()-2.0 <= event->pos().x())
            {
                setValue(m_maxValue);
            }
            else
            {
                setValue((event->pos().x()-2.0)*m_maxValue/(this->width()-4.0));
            }

            break;
        }
        case vertical:
        {
            if(2 >= event->pos().y())
            {
                setValue(m_maxValue);
            }
            else if(this->height()-2.0 <= event->pos().y())
            {
                setValue(0);
            }
            else
            {
                setValue(m_maxValue - (event->pos().y()-2.0)*m_maxValue/(this->height()-4.0));
            }

            break;
        }
        default:
        {
            break;
        }
        }

        repaint();
    }
}
