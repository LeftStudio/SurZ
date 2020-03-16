/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include "wavewater.h"

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *label;
    WaveWater *LogoWaveWater;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(312, 389);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        AboutDialog->setFont(font);
        AboutDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"background:white;\n"
"}"));
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 230, 311, 121));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        LogoWaveWater = new WaveWater(AboutDialog);
        LogoWaveWater->setObjectName(QString::fromUtf8("LogoWaveWater"));
        LogoWaveWater->setGeometry(QRect(40, 0, 230, 230));
        LogoWaveWater->setRefractive(3);
        LogoWaveWater->setStoneWeight(100);

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\345\205\263\344\272\216", nullptr));
        label->setText(QApplication::translate("AboutDialog", "<html><head/><body><p align=\"center\">\344\271\246\347\237\245\347\274\226\350\276\221\345\231\250</p><p align=\"center\">By Left Studio</p><p align=\"center\">1.2 \346\255\243\345\274\217\347\211\210</p><p align=\"center\"><a href=\"http://left-studio.gitee.io\"><span style=\" text-decoration: underline; color:#007af4;\">Left-Studio.gitee.io</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
