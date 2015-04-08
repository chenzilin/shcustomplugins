#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWidget>
#include <QPaintEvent>

class QRectF;
class QPointF;
class QPaintEvent;
class QMouseEvent;


class SHSlider : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue RESET resetValue  DESIGNABLE true)
    Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue RESET resetMaxValue  DESIGNABLE true)
    Q_PROPERTY(StretchingDirection stretchingDirection READ stretchingDirection WRITE setStretchingDirection RESET resetStretchingDirection  DESIGNABLE true)

    Q_ENUMS(StretchingDirection)

public:

    enum StretchingDirection{vertical, horizontal};

public:
    explicit SHSlider(QWidget *parent = 0);

    int value()const{ return m_value; }
    void resetValue(){ setValue();  repaint(); }

    int maxValue()const{ return m_maxValue; }
    void setMaxValue(int maxValue = 99){ m_maxValue = maxValue; repaint();}
    void resetMaxValue(){ setValue();  repaint(); }

    StretchingDirection stretchingDirection()const{ return m_stretchingDirection; }
    void setStretchingDirection(StretchingDirection stretchingDirection = horizontal){ m_stretchingDirection = stretchingDirection; repaint();}
    void resetStretchingDirection(){ setStretchingDirection();  repaint(); }

signals:
    void valueChanged(int);

public slots:
    void setValue(int value = 0)
    {
        if(m_value != value)
        {
            m_value = value%(m_maxValue+1);
            repaint();
            emit valueChanged(value);
        }
    }

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:

    int m_value;
    int m_maxValue;

    QRectF m_sliderRect;
    bool  m_mousePressPositionInSliderRect;
    StretchingDirection m_stretchingDirection;
};
#endif
