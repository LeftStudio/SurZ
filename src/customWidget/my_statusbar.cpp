/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "my_statusbar.h"
#include "ui_my_statusbar.h"

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

my_StatusBar::my_StatusBar(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::my_StatusBar)
{
    ui->setupUi(this);
}

my_StatusBar::~my_StatusBar()
{
    delete ui;
}

void my_StatusBar::setCurpos(const int& row, const int& col, const int& count) const
{
    ui->CurposLabel->setText(QString("行:%1  列:%2  字数:%3")
                             .arg(row).arg(col).arg(count));
}

void my_StatusBar::setSaved(const bool& isSave) const
{
    ui->isSaveLabel->setHidden(!isSave);
}
