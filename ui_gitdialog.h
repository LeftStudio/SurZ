/********************************************************************************
** Form generated from reading UI file 'gitdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GITDIALOG_H
#define UI_GITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GitDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *NotesEdit;
    QPushButton *GitPathBtn;
    QPushButton *FilePathBtn;
    QPushButton *CommitBtn;
    QPushButton *CancelBtn;
    QLineEdit *GitPathEdit;
    QLineEdit *FilePathEdit;
    QLabel *TitleLabel;
    QLabel *Notes;

    void setupUi(QDialog *GitDialog)
    {
        if (GitDialog->objectName().isEmpty())
            GitDialog->setObjectName(QString::fromUtf8("GitDialog"));
        GitDialog->resize(524, 295);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        GitDialog->setFont(font);
        GitDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"background:rgb(238,238,238);\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"border-style:none;\n"
"padding:2px;\n"
"border-radius:5px;\n"
"border:2px solid #DCE4EC;\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"border:2px solid rgb(22,155,213);\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"border-style:none;\n"
"padding:2px;\n"
"border-radius:5px;\n"
"border:2px solid #DCE4EC;\n"
"}\n"
"\n"
"QPlainTextEdit:focus\n"
"{\n"
"border:2px solid rgb(22,155,213);\n"
"}"));
        label = new QLabel(GitDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 80, 71, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(GitDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 130, 81, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(GitDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 180, 81, 31));
        label_3->setFont(font1);
        NotesEdit = new QPlainTextEdit(GitDialog);
        NotesEdit->setObjectName(QString::fromUtf8("NotesEdit"));
        NotesEdit->setGeometry(QRect(130, 180, 231, 81));
        NotesEdit->setFont(font);
        NotesEdit->setStyleSheet(QString::fromUtf8(""));
        GitPathBtn = new QPushButton(GitDialog);
        GitPathBtn->setObjectName(QString::fromUtf8("GitPathBtn"));
        GitPathBtn->setGeometry(QRect(390, 80, 81, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        GitPathBtn->setFont(font2);
        GitPathBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        FilePathBtn = new QPushButton(GitDialog);
        FilePathBtn->setObjectName(QString::fromUtf8("FilePathBtn"));
        FilePathBtn->setGeometry(QRect(390, 130, 81, 31));
        FilePathBtn->setFont(font2);
        FilePathBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        CommitBtn = new QPushButton(GitDialog);
        CommitBtn->setObjectName(QString::fromUtf8("CommitBtn"));
        CommitBtn->setGeometry(QRect(390, 180, 81, 31));
        CommitBtn->setFont(font2);
        CommitBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        CancelBtn = new QPushButton(GitDialog);
        CancelBtn->setObjectName(QString::fromUtf8("CancelBtn"));
        CancelBtn->setGeometry(QRect(390, 230, 81, 31));
        CancelBtn->setFont(font2);
        CancelBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        GitPathEdit = new QLineEdit(GitDialog);
        GitPathEdit->setObjectName(QString::fromUtf8("GitPathEdit"));
        GitPathEdit->setGeometry(QRect(130, 80, 231, 31));
        FilePathEdit = new QLineEdit(GitDialog);
        FilePathEdit->setObjectName(QString::fromUtf8("FilePathEdit"));
        FilePathEdit->setGeometry(QRect(130, 130, 231, 31));
        TitleLabel = new QLabel(GitDialog);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(40, 30, 41, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        TitleLabel->setFont(font3);
        Notes = new QLabel(GitDialog);
        Notes->setObjectName(QString::fromUtf8("Notes"));
        Notes->setGeometry(QRect(130, 40, 231, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        Notes->setFont(font4);

        retranslateUi(GitDialog);
        QObject::connect(CancelBtn, SIGNAL(clicked()), GitDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(GitDialog);
    } // setupUi

    void retranslateUi(QDialog *GitDialog)
    {
        GitDialog->setWindowTitle(QApplication::translate("GitDialog", "Git", nullptr));
        label->setText(QApplication::translate("GitDialog", "<html><head/><body><p> Git\350\267\257\345\276\204:</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("GitDialog", "<html><head/><body><p>\346\226\207\344\273\266\350\267\257\345\276\204:</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("GitDialog", "<html><head/><body><p>\346\217\220\344\272\244\346\263\250\351\207\212:</p></body></html>", nullptr));
        GitPathBtn->setText(QApplication::translate("GitDialog", "\346\265\217\350\247\210...", nullptr));
        FilePathBtn->setText(QApplication::translate("GitDialog", "\346\265\217\350\247\210...", nullptr));
        CommitBtn->setText(QApplication::translate("GitDialog", "\346\217\220\344\272\244", nullptr));
        CancelBtn->setText(QApplication::translate("GitDialog", "\345\217\226\346\266\210", nullptr));
        TitleLabel->setText(QApplication::translate("GitDialog", "<html><head/><body><p align=\"center\">Git</p></body></html>", nullptr));
        Notes->setText(QApplication::translate("GitDialog", "<html><head/><body><p align=\"center\"><span style=\" font-style:italic; text-decoration: underline;\">\346\263\250\357\274\232\344\275\277\347\224\250\345\211\215\350\257\267\351\205\215\347\275\256\345\271\266\345\210\233\345\273\272Git\346\234\254\345\234\260\344\273\223\345\272\223</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GitDialog: public Ui_GitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GITDIALOG_H
