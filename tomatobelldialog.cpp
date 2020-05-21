/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "tomatobelldialog.h"
#include "ui_tomatobelldialog.h"

#if _MSC_VER >= 1600
    #pragma execution_character_set("utf-8")
#endif

TomatobellDialog::TomatobellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TomatobellDialog)
{
    ui->setupUi(this);
    this->initUI();
}

TomatobellDialog::~TomatobellDialog()
{
    delete ui;
}

void TomatobellDialog::initUI()
{
    this->setFixedSize(this->size());
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

void TomatobellDialog::on_OK_Btn_clicked()
{
    *tomatobellNum=ui->tomatobellNum->value();
    *workMin=ui->workMin->value();
    *relaxMin=ui->relaxMin->value();

    this->accept();
}
