#include "my_switchbutton.h"

#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>

my_SwitchButton::my_SwitchButton(QWidget *parent) :
    QWidget(parent)
{
    backgroundgColorOff = QColor(192,192,192);
    backgroundColorOn = QColor(22,155,213);

    sliderColorOff = QColor(150, 155, 160);
    sliderColorOn = QColor(100, 184, 255);
    sliderColor = sliderColorOff;

    //textColorOn = QColor(255,255,255);
    //textColorOff = QColor(0,0,0);
}

my_SwitchButton::~my_SwitchButton()
{

}

void my_SwitchButton::setChecked(bool isChecked)
{
    if (isChecked)
    {
        sliderColor = sliderColorOn;

        if(!m_isChecked)
            emit checkedChanged(true);

        m_isChecked = true;
    }
    else
    {
        sliderColor = sliderColorOff;

        if(m_isChecked)
            emit checkedChanged(false);

        m_isChecked = false;
    }
    this->update();
}

void my_SwitchButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if ((event->pos().x() - centerPoint.x())*(event->pos().y() - centerPoint.y()) <= ((rect().height()/2) * (rect().height()/2)))
        {
            m_isPress = true;
            mouseX = event->pos().x();
            sliderColor = QColor(80, 90, 95);
            update();
        }
    }
}

void my_SwitchButton::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPress)
    {
        if ((event->pos().x() >= startPoint.x()) && (event->pos().x() <= endPoint.x()))
        {
            int tempX = event->pos().x();
            centerPoint.setX(tempX - mouseX + centerPoint.x());
            mouseX = centerPoint.x();

            update();
        }
    }
}

void my_SwitchButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_isPress = false;
    sliderColor = QColor(245,245,245);

    if (centerPoint.x() >= rect().width()/2)
    {
        centerPoint.setX(endPoint.x());
        sliderColor = sliderColorOn;

        if(!m_isChecked)
            emit checkedChanged(true);

        m_isChecked = true;
    }
    else if (centerPoint.x() < rect().width()/2)
    {
        centerPoint.setX(startPoint.x());
        sliderColor = sliderColorOff;

        if(m_isChecked)
            emit checkedChanged(false);

        m_isChecked = false;
    }

    update();
}

void my_SwitchButton::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    startPoint = QPoint(rect().height()/2,rect().height()/2);
    endPoint = QPoint((rect().right() - rect().height()/2),rect().height()/2);

    if(m_isChecked)
        centerPoint = endPoint;
    else
        centerPoint = startPoint;
}

void my_SwitchButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(painter);
    drawSlidBlock(painter);
    //drawText(painter);
}

/* 绘制背景 */
void my_SwitchButton::drawBackground(QPainter& painter)
{
    painter.save();
    painter.setPen(Qt::NoPen);

    if (m_isChecked)
        painter.setBrush(QBrush(backgroundColorOn));
    else
        painter.setBrush(QBrush(backgroundgColorOff));

    /* 绘制按钮外边框 */
    QPainterPath path;
    int startX = rect().height()/2;
    int startY = rect().top();

    path.moveTo(startX,startY);
    path.arcTo(QRect(rect().left(),rect().top(),rect().height(),rect().height()),90,180);
    path.lineTo((rect().right() - startX),rect().height());
    path.arcTo(QRect((rect().right() - rect().height()),rect().top(),rect().height(),rect().height()),270,180);
    path.lineTo(startX,startY);
    painter.drawPath(path);

    painter.restore();
}

/* 绘制滑块 */
void my_SwitchButton::drawSlidBlock(QPainter& painter)
{
    painter.save();
    painter.setPen(Qt::NoPen);

    painter.setBrush(QBrush(sliderColor));

    painter.drawEllipse(centerPoint,rect().height()/2 - 2,rect().height()/2 - 2);

    painter.restore();
}

/*void my_SwitchButton::drawText(QPainter& painter)
{
    painter.save();

    int x,y;

    if (isChecked)
    {
        painter.setPen(QPen(textColorOn));

        x = rect().left();
        y = rect().top();

        strText = QString::fromLocal8Bit("开");
    }
    else
    {
        painter.setPen(QPen(textColorOff));

        x = rect().right() - rect().height();
        y = rect().top();

        strText = QString::fromLocal8Bit("关");
    }

    painter.drawText(x,y,rect().height(),rect().height(),Qt::AlignCenter,strText);

    painter.restore();
}*/
