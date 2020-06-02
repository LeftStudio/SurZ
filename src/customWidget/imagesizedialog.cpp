/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "imagesizedialog.h"
#include "ui_imagesizedialog.h"

ImageSizeDialog::ImageSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageSizeDialog)
{
    ui->setupUi(this);
    this->initUI();
}

ImageSizeDialog::~ImageSizeDialog()
{
    delete ui;
}

void ImageSizeDialog::initImageSize(int *w, int *h)
{
    ImageWidth=w;
    ImageHeight=h;

    ui->WidthSpinBox->setValue(*ImageWidth);
    ui->HeightSpinBox->setValue(*ImageHeight);

    ui->KeepSizeCheck->setChecked(true);
}

void ImageSizeDialog::initUI()
{
    this->setFixedSize(this->size());
    this->setWindowFlag(Qt::WindowContextHelpButtonHint,false);
}

void ImageSizeDialog::on_OK_Button_clicked()
{
    if(!isKeepSize)
    {
        *ImageWidth=ui->WidthSpinBox->value();
        *ImageHeight=ui->HeightSpinBox->value();
    }
    this->close();
}

void ImageSizeDialog::on_KeepSizeCheck_checkedChanged(bool checked)
{
    isKeepSize=checked;

    ui->WidthSpinBox->setEnabled(!checked);
    ui->HeightSpinBox->setEnabled(!checked);
}
