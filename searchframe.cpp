/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "searchframe.h"
#include "ui_searchframe.h"

#include <QPropertyAnimation>
#include <QCloseEvent>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

SearchFrame::SearchFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SearchFrame)
{
    ui->setupUi(this);
    this->initUI();
    this->initSignalSlots();
}

SearchFrame::~SearchFrame()
{
    delete ui;
}

void SearchFrame::startAnimation()
{
    animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(this->pos().x(),20,370,this->height()));
    animation->setEndValue(QRect(this->pos().x(),70,370,this->height()));
    animation->start();
}

void SearchFrame::initUI()
{
    ui->DisplaceWidget->hide();
    this->setFixedHeight(50);
    ui->OpenBtn->setFixedHeight(30);
    ui->SearchLineEdit->setTextMargins(2,2,25,2);
}

void SearchFrame::initSignalSlots()
{
    connect(ui->CaseSensitive,&QPushButton::clicked,
            [this](bool checked){
        if(checked)
            ui->CaseSensitive->setIcon(QIcon(":/images/images/CaseSensitive_2.ico"));
        else
            ui->CaseSensitive->setIcon(QIcon(":/images/images/CaseSensitive.ico"));
    });
    connect(ui->FindLastBtn,&QPushButton::clicked,
            [this]{
        if(!ui->SearchLineEdit->text().isEmpty())
            emit callTextSearch(ui->SearchLineEdit->text(),
                                true,
                                ui->CaseSensitive->isChecked());
    });
    connect(ui->FindNextBtn,&QPushButton::clicked,
            [this]{
        if(!ui->SearchLineEdit->text().isEmpty())
            emit callTextSearch(ui->SearchLineEdit->text(),
                                false,
                                ui->CaseSensitive->isChecked());
    });
    connect(ui->DisplaceBtn,&QPushButton::clicked,
            [this]{
        if((!ui->SearchLineEdit->text().isEmpty())
                &&(!ui->DisplaceLineEdit->text().isEmpty()))
            emit callTextDisplace(ui->SearchLineEdit->text(),
                                  ui->CaseSensitive->isChecked(),
                                  ui->DisplaceLineEdit->text(),
                                  false);
    });
    connect(ui->DisplaceAllBtn,&QPushButton::clicked,
            [this]{
        if((!ui->SearchLineEdit->text().isEmpty())
                &&(!ui->DisplaceLineEdit->text().isEmpty()))
            emit callTextDisplace(ui->SearchLineEdit->text(),
                                  ui->CaseSensitive->isChecked(),
                                  ui->DisplaceLineEdit->text(),
                                  true);
    });
}

void SearchFrame::closeEvent(QCloseEvent *event)
{
    emit finished();
    event->accept();
}

void SearchFrame::on_OpenBtn_clicked()
{
    if(isOpen)
    {
        ui->DisplaceWidget->hide();
        this->setFixedHeight(50);
        ui->OpenBtn->setFixedHeight(30);
        ui->OpenBtn->setIcon(QIcon(":/images/images/down.ico"));

        isOpen=false;
    }
    else
    {
        ui->DisplaceWidget->show();
        this->setFixedHeight(90);
        ui->OpenBtn->setFixedHeight(70);
        ui->OpenBtn->setIcon(QIcon(":/images/images/up.ico"));

        isOpen=true;
    }
}

void SearchFrame::on_CloseBtn_clicked()
{
    animation->setDuration(100);
    animation->setStartValue(QRect(this->pos().x(),70,370,this->height()));
    animation->setEndValue(QRect(this->pos().x(),20,370,this->height()));
    animation->start();

    connect(animation,SIGNAL(finished()),this,
            SLOT(close()));
}

