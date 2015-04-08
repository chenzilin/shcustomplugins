#include <QImage>
#include <QPainter>

#include "sharrows.h"

SHArrows::SHArrows(QWidget *parent) :
    QWidget(parent)
{
    m_isStart = false;
    m_arrowsColor = green;
    m_stretchingDirection = leftToRight;
    m_displayHasOrNot = true;

    m_timer = new QTimer(this);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(flashArrows()));
}

void SHArrows::setStart(bool state)
{
    m_isStart = state;

    if(m_isStart)
        m_timer->start(500);
    else
    {
        m_timer->stop();
        m_displayHasOrNot = true;
        update();
    }
}

void SHArrows::flashArrows()
{
    m_displayHasOrNot = !m_displayHasOrNot;
    update();
}

void SHArrows::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(m_stretchingDirection == leftToRight)
    {
    	painter.save();
        painter.translate(this->width(), this->height());
        painter.rotate(180);

        if(m_displayHasOrNot)
        {
            if(m_arrowsColor  == red)
            {
                QImage image(":/image/redarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
            else if(m_arrowsColor  == green)
            {
                QImage image(":/image/greenarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
            else if(m_arrowsColor  == yellow)
            {
                QImage image(":/image/yellowarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
            else
            {
                QImage image(":/image/noarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
        }
        else
        {
            QImage image(":/image/noarrows.svg");
            painter.drawImage(this->rect(), image, image.rect());
        }


        painter.restore();
    }
    else
    {
        if(m_displayHasOrNot)
        {
            if(m_arrowsColor  == red)
            {
                QImage image(":/image/redarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
            else if(m_arrowsColor  == green)
            {
                QImage image(":/image/greenarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
            else if(m_arrowsColor  == yellow)
            {
                QImage image(":/image/yellowarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
            else
            {
                QImage image(":/image/noarrows.svg");
                painter.drawImage(this->rect(), image, image.rect());
            }
        }
        else
        {
            QImage image(":/image/noarrows.svg");
            painter.drawImage(this->rect(), image, image.rect());
        }
    }
}
