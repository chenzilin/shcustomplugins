#ifndef SHARROWS_H
#define SHARROWS_H

#include <QTimer>
#include <QWidget>
#include <QPaintEvent>

class SHArrows : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool isStart READ isStart WRITE setStart DESIGNABLE true)
    Q_PROPERTY(ArrowsColor arrowsColor READ arrowsColor WRITE setArrowsColor RESET resetArrowsColor  DESIGNABLE true)
    Q_PROPERTY(StretchingDirection stretchingDirection READ stretchingDirection WRITE setStretchingDirection RESET resetStretchingDirection  DESIGNABLE true)

    Q_ENUMS(ArrowsColor)
    Q_ENUMS(StretchingDirection)


public:

    enum ArrowsColor{nocolor, red, yellow, green};
    enum StretchingDirection{leftToRight, rightToLeft};

public:
    explicit SHArrows(QWidget *parent = 0);


    bool isStart()const{return m_isStart;}
    void setStart(bool state = false);


    ArrowsColor arrowsColor()const{return m_arrowsColor;}
    void setArrowsColor(ArrowsColor arrowsColor = green){m_arrowsColor = arrowsColor; repaint();}
    void resetArrowsColor(){setArrowsColor(); repaint();}

    StretchingDirection stretchingDirection()const{ return m_stretchingDirection; }
    void setStretchingDirection(StretchingDirection stretchingDirection = leftToRight){ m_stretchingDirection = stretchingDirection; repaint();}
    void resetStretchingDirection(){ setStretchingDirection();  repaint(); }

protected:
    void paintEvent(QPaintEvent *);

protected slots:

    void flashArrows();

private:

    QTimer *m_timer;

    bool m_isStart;
    ArrowsColor m_arrowsColor;
    StretchingDirection m_stretchingDirection;

    bool m_displayHasOrNot;
};
#endif
