/********************************************************************************
** Form generated from reading UI file 'insertdatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTDATEDIALOG_H
#define UI_INSERTDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InsertDateDialog
{
public:
    QPushButton *OK_Btn;
    QPushButton *Cancel_Btn;
    QListWidget *DateFormatList;

    void setupUi(QDialog *InsertDateDialog)
    {
        if (InsertDateDialog->objectName().isEmpty())
            InsertDateDialog->setObjectName(QString::fromUtf8("InsertDateDialog"));
        InsertDateDialog->resize(312, 213);
        InsertDateDialog->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QListWidget::item:selected\n"
"{\n"
"background:rgb(22,155,213);\n"
"color:white;\n"
"}\n"
""));
        OK_Btn = new QPushButton(InsertDateDialog);
        OK_Btn->setObjectName(QString::fromUtf8("OK_Btn"));
        OK_Btn->setGeometry(QRect(50, 170, 80, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        OK_Btn->setFont(font);
        OK_Btn->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        Cancel_Btn = new QPushButton(InsertDateDialog);
        Cancel_Btn->setObjectName(QString::fromUtf8("Cancel_Btn"));
        Cancel_Btn->setGeometry(QRect(180, 170, 80, 31));
        Cancel_Btn->setFont(font);
        Cancel_Btn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-style:none;\n"
"padding:2px;\n"
"border-radius:5px;\n"
"border:1px solid rgb(119,119,119);\n"
"color:black;\n"
"background:white;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"background:rgb(250, 250, 250);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background:rgb(220, 220, 220);\n"
"}"));
        DateFormatList = new QListWidget(InsertDateDialog);
        DateFormatList->setObjectName(QString::fromUtf8("DateFormatList"));
        DateFormatList->setGeometry(QRect(0, 0, 311, 161));

        retranslateUi(InsertDateDialog);
        QObject::connect(Cancel_Btn, SIGNAL(clicked()), InsertDateDialog, SLOT(reject()));

        DateFormatList->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(InsertDateDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertDateDialog)
    {
        InsertDateDialog->setWindowTitle(QApplication::translate("InsertDateDialog", "\346\217\222\345\205\245\346\227\245\346\234\237", nullptr));
        OK_Btn->setText(QApplication::translate("InsertDateDialog", "\347\241\256\345\256\232", nullptr));
        Cancel_Btn->setText(QApplication::translate("InsertDateDialog", "\345\217\226\346\266\210", nullptr));
#ifndef QT_NO_WHATSTHIS
        DateFormatList->setWhatsThis(QApplication::translate("InsertDateDialog", "\346\227\245\346\234\237\346\240\274\345\274\217\345\210\227\350\241\250", nullptr));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class InsertDateDialog: public Ui_InsertDateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTDATEDIALOG_H
