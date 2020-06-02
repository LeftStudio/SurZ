/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "tomatobellframe.h"
#include "ui_tomatobellframe.h"

#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTimer>
//#include <QDebug>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

TomatobellFrame::TomatobellFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TomatobellFrame)
{
    ui->setupUi(this);
    this->initUI();
    this->setAttribute(Qt::WA_Hover);
    this->installEventFilter(this);
}

TomatobellFrame::~TomatobellFrame()
{
    delete ui;
}

void TomatobellFrame::initUI()
{
    this->setFixedWidth(80);
    ui->TimerLabel->setAlignment(Qt::AlignCenter);
}

void TomatobellFrame::work()
{
    workSec++;
    isWork=true;

    time.setSecsSinceEpoch(workSec);

    ui->TimerLabel->setStyleSheet("color:black");
    ui->TimerLabel->setText(time.toString("mm:s"));
}

void TomatobellFrame::relax()
{
    relaxSec++;
    isWork=false;

    time.setSecsSinceEpoch(relaxSec);

    ui->TimerLabel->setStyleSheet("color:green");
    ui->TimerLabel->setText(time.toString("mm:s"));
}

void TomatobellFrame::startAnimation()
{
    animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(150);
    animation->setStartValue(QRect(this->pos().x()+85,this->pos().y(),0,50));
    animation->setEndValue(QRect(this->pos().x(),this->pos().y(),80,50));
    animation->start();
}

void TomatobellFrame::endAnimation()
{
    if(animation!=nullptr)
    {
        animation->setStartValue(QRect(this->pos().x(),this->pos().y(),150,50));
        animation->setEndValue(QRect(this->pos().x()+85,this->pos().y(),0,50));
        animation->start();
    }
}

void TomatobellFrame::initTomatobell(int w, int r, int num)
{
    workMin=w;
    relaxMin=r;
    tomatobellNum=num;

    m_Timer=new QTimer(this);
    connect(m_Timer,SIGNAL(timeout()),this,
            SLOT(update()));
    this->work();
    m_Timer->start(1000);
}

void TomatobellFrame::update()
{
    if(isWork)
    {
        if(workSec<workMin*60)
        {
            this->work();
        }
        else
        {
            if(tomatobellNum>relaxStep-1)
            {
                relaxSec=0;
                workStep++;
                this->relax();
            }
        }
    }
    else
    {
        if(relaxSec<relaxMin*60)
        {
            this->relax();
        }
        else
        {
            if(tomatobellNum>workStep)
            {
                workSec=0;
                relaxStep++;
                this->work();
            }
            else
            {
                QMessageBox::information(this,"番茄钟","番茄钟已结束");
                this->on_StopBtn_clicked();
            }
        }
    }
}

void TomatobellFrame::showEvent(QShowEvent *event)
{
    this->startAnimation();
    event->accept();
}

void TomatobellFrame::closeEvent(QCloseEvent *event)
{
    emit finished();
    event->accept();
}

bool TomatobellFrame::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==this)
    {
        static int curX,curY;
        if(event->type() == QEvent::HoverEnter)
        {
            curX = this->pos().x();
            curY = this->pos().y();
            this->setFixedWidth(150);
            animation->setStartValue(QRect(curX,curY,80,50));
            animation->setEndValue(QRect(curX-70,curY,150,50));
            animation->start();
            return true;
        }
        else if(event->type() == QEvent::HoverLeave)
        {
            this->setFixedWidth(80);
            animation->setStartValue(QRect(this->pos().x(),this->pos().y(),150,50));
            animation->setEndValue(QRect(curX,curY,80,50));
            animation->start();
            return true;
        }
    }
    return QFrame::eventFilter(obj,event);
}

void TomatobellFrame::on_StopBtn_clicked()
{
    m_Timer->stop();
    this->endAnimation();

    connect(animation,SIGNAL(finished()),this,
            SLOT(close()));
}

void TomatobellFrame::on_PauseBtn_clicked()
{
    static bool isPause=false;
    if(isPause)
    {
        m_Timer->start();
        ui->PauseBtn->setIcon(QIcon(":/images/images/icon/Continue.ico"));
        isPause=false;
    }
    else
    {
        m_Timer->stop();
        ui->PauseBtn->setIcon(QIcon(":/images/images/icon/Pause.ico"));
        isPause=true;
    }
}
