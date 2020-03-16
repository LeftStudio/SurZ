/********************************************************************************
** Form generated from reading UI file 'imagesizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESIZEDIALOG_H
#define UI_IMAGESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include "switchbutton.h"

QT_BEGIN_NAMESPACE

class Ui_ImageSizeDialog
{
public:
    QPushButton *OK_Button;
    QGroupBox *PictureSizeBox;
    QSpinBox *HeightSpinBox;
    QLabel *WidthLabel;
    QSpinBox *WidthSpinBox;
    QLabel *HeightLabel;
    QLabel *label;
    SwitchButton *KeepSizeCheck;

    void setupUi(QDialog *ImageSizeDialog)
    {
        if (ImageSizeDialog->objectName().isEmpty())
            ImageSizeDialog->setObjectName(QString::fromUtf8("ImageSizeDialog"));
        ImageSizeDialog->resize(283, 111);
        ImageSizeDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"background:rgb(245, 245, 245);\n"
"}"));
        OK_Button = new QPushButton(ImageSizeDialog);
        OK_Button->setObjectName(QString::fromUtf8("OK_Button"));
        OK_Button->setGeometry(QRect(170, 50, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        OK_Button->setFont(font);
        OK_Button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-style:none;\n"
"padding:10px;\n"
"border-radius:6px;\n"
"color:#E6F8F5;\n"
"background:rgb(22,155,213);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"color:#FFFFFF;\n"
"background:rgb(70, 197, 255);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"color:#A7EEE6;\n"
"background:rgb(19, 139, 190);\n"
"}"));
        PictureSizeBox = new QGroupBox(ImageSizeDialog);
        PictureSizeBox->setObjectName(QString::fromUtf8("PictureSizeBox"));
        PictureSizeBox->setEnabled(true);
        PictureSizeBox->setGeometry(QRect(30, 10, 111, 81));
        PictureSizeBox->setFont(font);
        HeightSpinBox = new QSpinBox(PictureSizeBox);
        HeightSpinBox->setObjectName(QString::fromUtf8("HeightSpinBox"));
        HeightSpinBox->setEnabled(false);
        HeightSpinBox->setGeometry(QRect(50, 50, 51, 22));
        HeightSpinBox->setFont(font);
        HeightSpinBox->setMinimum(5);
        HeightSpinBox->setMaximum(2080);
        WidthLabel = new QLabel(PictureSizeBox);
        WidthLabel->setObjectName(QString::fromUtf8("WidthLabel"));
        WidthLabel->setGeometry(QRect(10, 20, 31, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        WidthLabel->setFont(font1);
        WidthSpinBox = new QSpinBox(PictureSizeBox);
        WidthSpinBox->setObjectName(QString::fromUtf8("WidthSpinBox"));
        WidthSpinBox->setEnabled(false);
        WidthSpinBox->setGeometry(QRect(50, 20, 51, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        WidthSpinBox->setFont(font2);
        WidthSpinBox->setMinimum(5);
        WidthSpinBox->setMaximum(2080);
        HeightLabel = new QLabel(PictureSizeBox);
        HeightLabel->setObjectName(QString::fromUtf8("HeightLabel"));
        HeightLabel->setGeometry(QRect(10, 50, 31, 16));
        HeightLabel->setFont(font1);
        label = new QLabel(ImageSizeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 51, 16));
        label->setFont(font1);
        KeepSizeCheck = new SwitchButton(ImageSizeDialog);
        KeepSizeCheck->setObjectName(QString::fromUtf8("KeepSizeCheck"));
        KeepSizeCheck->setGeometry(QRect(220, 20, 51, 21));
        KeepSizeCheck->setSpace(15);
        KeepSizeCheck->setRectRadius(3);
        KeepSizeCheck->setChecked(true);
        KeepSizeCheck->setAnimation(true);
        KeepSizeCheck->setButtonStyle(SwitchButton::ButtonStyle_CircleOut);
        KeepSizeCheck->setBgColorOn(QColor(22, 155, 213));
        KeepSizeCheck->setSliderColorOn(QColor(22, 155, 213));

        retranslateUi(ImageSizeDialog);

        QMetaObject::connectSlotsByName(ImageSizeDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageSizeDialog)
    {
        ImageSizeDialog->setWindowTitle(QApplication::translate("ImageSizeDialog", "\350\256\276\347\275\256\345\233\276\347\211\207\345\244\247\345\260\217", nullptr));
        OK_Button->setText(QApplication::translate("ImageSizeDialog", "\347\241\256\345\256\232", nullptr));
        PictureSizeBox->setTitle(QApplication::translate("ImageSizeDialog", "\345\233\276\347\211\207\345\244\247\345\260\217", nullptr));
        WidthLabel->setText(QApplication::translate("ImageSizeDialog", "\345\256\275\345\272\246", nullptr));
        HeightLabel->setText(QApplication::translate("ImageSizeDialog", "\351\253\230\345\272\246", nullptr));
        label->setText(QApplication::translate("ImageSizeDialog", "\344\277\235\346\214\201\345\244\247\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageSizeDialog: public Ui_ImageSizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESIZEDIALOG_H
