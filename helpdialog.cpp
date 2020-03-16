/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "helpdialog.h"
#include "ui_helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    this->initUI();
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::initUI()
{
    ui->HelpText->setReadOnly(true);

    this->setFixedSize(this->size());
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}
