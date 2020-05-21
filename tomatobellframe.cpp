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
    this->setMouseTracking(true);
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
    animation->setDuration(200);
    animation->setStartValue(QRect(this->pos().x()+85,this->pos().y(),0,50));
    animation->setEndValue(QRect(this->pos().x(),this->pos().y(),80,50));
    animation->start();
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

void TomatobellFrame::closeEvent(QCloseEvent *event)
{
    emit finished();
    event->accept();
}

void TomatobellFrame::mouseMoveEvent(QMouseEvent *event)
{
    QFrame::mouseMoveEvent(event);
    static bool isInside=false;
    if(event->pos().x()>=5&&this->width()-5>=event->pos().x()
     &&event->pos().y()>=5&&this->height()-5>=event->pos().y())
    {
        if(!isInside)
        {
            this->setFixedWidth(150);

            animation->setStartValue(QRect(this->pos().x(),this->pos().y(),0,50));
            animation->setEndValue(QRect(this->pos().x()-70,this->pos().y(),150,50));
            animation->start();

            isInside=true;
        }
    }
    else
    {
        if(isInside)
        {
            this->setFixedWidth(80);

            animation->setStartValue(QRect(this->pos().x(),this->pos().y(),150,50));
            animation->setEndValue(QRect(this->pos().x()+70,this->pos().y(),80,50));
            animation->start();

            isInside=false;
        }
    }
}

void TomatobellFrame::on_StopBtn_clicked()
{
    m_Timer->stop();
    emit finished();
    this->close();
}

void TomatobellFrame::on_PauseBtn_clicked()
{
    static bool isPause=false;
    if(isPause)
    {
        m_Timer->start();
        ui->PauseBtn->setIcon(QIcon(":/images/images/Continue.ico"));
        isPause=false;
    }
    else
    {
        m_Timer->stop();
        ui->PauseBtn->setIcon(QIcon(":/images/images/Pause.ico"));
        isPause=true;
    }
}
