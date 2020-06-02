#ifndef MY_SWITCHBUTTON_H
#define MY_SWITCHBUTTON_H

#include <QWidget>

class my_SwitchButton : public QWidget
{
    Q_OBJECT

public:
    explicit my_SwitchButton(QWidget *parent = nullptr);
    ~my_SwitchButton();

    void setChecked(bool m_isChecked);

    bool getChecked() const { return m_isChecked; }

signals:
    void checkedChanged(bool m_isChecked);

private:
    bool m_isChecked = false;             //开关状态:开true，关false
    bool m_isPress   = false;             //左键是否按下

    QColor backgroundColorOn;           //开状态时的背景颜色
    QColor backgroundgColorOff;         //关状态时的背景颜色

    QColor sliderColor;
    QColor sliderColorOn;               //开状态时滑块的背景颜色
    QColor sliderColorOff;              //关状态时滑块的背景颜色

    //QColor textColorOn;               //开状态时文字颜色
    //QColor textColorOff;              //关状态时文字颜色

    //QString strText;                  //文字内容

    QPoint startPoint;                  //滑块移动的起始点
    QPoint endPoint;                    //滑块移动的终点
    QPoint centerPoint;                 //滑块移动的中间某点

    int mouseX = 0;

    /* 事件重写 */
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void drawBackground(QPainter& painter);     //绘制背景
    void drawSlidBlock(QPainter& painter);      //绘制滑块
    //void drawText(QPainter& painter);         //绘制文字

};

#endif // MY_SWITCHBUTTON_H
