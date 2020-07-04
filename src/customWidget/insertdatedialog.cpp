/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "insertdatedialog.h"
#include "ui_insertdatedialog.h"

#include <QDateTime>
#include <QPushButton>
//#include <QDebug>

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

InsertDateDialog::InsertDateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDateDialog)
{
    ui->setupUi(this);

    this->initUI();
    this->initTime();

    connect(ui->DateFormatList,&QListWidget::itemDoubleClicked,
            [this](QListWidgetItem *item){
        *DateTimeString=item->text();
        this->accept();
    });
}

InsertDateDialog::~InsertDateDialog()
{
    delete ui;
}

void InsertDateDialog::initTime()
{
    QDateTime DateTime=QDateTime::currentDateTime();

    ui->DateFormatList->addItem(DateTime.toString("yyyy/MM/dd"));
    ui->DateFormatList->addItem(DateTime.toString("yyyy年MM月"));
    ui->DateFormatList->addItem(DateTime.toString("yyyy年MM月dd日"));
    ui->DateFormatList->addItem(DateTime.toString("yyyy年MM月dd日 ddd"));
    ui->DateFormatList->addItem(DateTime.toString("MMMM d日 ap"));
    ui->DateFormatList->addItem(DateTime.toString("ap h时m分"));
    ui->DateFormatList->addItem(DateTime.toString("ap h时m分s秒"));
    ui->DateFormatList->addItem(DateTime.toString("h:m:s"));

    ui->DateFormatList->setCurrentRow(0);
}

void InsertDateDialog::initUI()
{
    this->setFixedSize(this->size());
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}
