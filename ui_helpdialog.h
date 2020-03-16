/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QTextEdit *HelpText;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(621, 631);
        HelpDialog->setStyleSheet(QString::fromUtf8(""));
        HelpText = new QTextEdit(HelpDialog);
        HelpText->setObjectName(QString::fromUtf8("HelpText"));
        HelpText->setEnabled(true);
        HelpText->setGeometry(QRect(0, 0, 621, 631));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        HelpText->setFont(font);
        HelpText->setFocusPolicy(Qt::NoFocus);
        HelpText->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "\345\270\256\345\212\251", nullptr));
        HelpText->setHtml(QApplication::translate("HelpDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:xx-large; font-weight:600;\">SueZ NoteBook  \342\200\224\342\200\224   \344\271\246\347\237\245\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250</span></h1>\n"
"<h1 align=\"center\" style=\" margin-top:18px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span sty"
                        "le=\" font-size:16pt; font-weight:600;\">\345\270\256\345\212\251\346\226\207\346\241\243(version 1.0.0\347\211\210\346\234\254)</span></h1>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240</p>\n"
"<h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">\344\275\277\347\224\250\346\226\271\345\274\217</span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\345\212\240\347\262\227\343\200\202\346\226\234\344\275\223\343\200\202\344\270\213\345\210\222\347\272\277\343\200\202</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\210\221\344\273\254\345\234\250\351\273\230\350\256\244\347\232\204\344\275\215\344\272\216\351\241\266\351\203\250\345\267\245\345\205\267\346\240\217\344\270\255\346\217\220\344\276\233\346\255\244\345\212\237\350\203\275\343\200\202\346\202\250\345\217\257\344\273\245\351\200\232\350\277\207\351\200\211\344\270\255\346\226\207\346\234\254-&gt;\345\215\225\345\207\273\345\255\227\344\275\223\346\240\267\345\274\217\345\267\245\345\205\267\346\240\217\344\270\212\347\232\204\346\214\211\351\222\256\346\235\245\346\267\273\345\212\240\346\225\210\346\236\234\343\200\202</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\346\226\207\346\234\254\345\257\271\351\275\220\343\200\202</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px;\">\346\263\250\346\204\217\345\210\260\351\241\266\351\203\250\345\267\245\345\205\267\346\240\217\346\234\200\345\267\246\344\276\247\347\232\204\344\270\211\344\270\252\346\214\211\351\222\256\344\272\206\345\220\227\357\274\237\344\273\226\344\273\254\345\260\261\346\230\257\345\267\246\345\257\271\351\275\220\343\200\201\345\261\205\344\270\255\343\200\201\345\217\263\345\257\271\351\275\220\357\274\201</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\350\260\203\346\225\264\345\255\227\344\275\223\344\270\216\345\244\247\345\260\217</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\202\250\350\277\230\346\230\257\345\217\257\344\273\245\351\200\232\350\277\207\345\255\227\344\275\223\346\240\267\345\274\217\345\267\245\345\205\267\346\240\217\346\235\245\350\260\203"
                        "\346\225\264\344\273\226\344\273\254\357\274\201</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">MORE COLOR!</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\275\223\347\204\266\344\272\206\357\274\214\346\202\250\344\271\237\345\217\257\344\273\245\350\260\203\346\225\264\344\273\226\344\273\254\347\232\204\351\242\234\350\211\262\357\274\201</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\215\225\345\207\273\346\240\267\345\274\217\345\267\245\345\205\267\346\240\217\347\232\204\345\275\251\350\211\262\345\234\206\345\234\210\350\257\225\350\257\225\357\274\237"
                        "</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\344\277\235\345\255\230\346\202\250\347\232\204\345\210\233\344\275\234</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\216\260\345\234\250\350\256\251\346\210\221\344\273\254\346\212\212\347\233\256\345\205\211\350\201\232\347\204\246\345\210\260\345\267\246\344\276\247\345\267\245\345\205\267\346\240\217\343\200\202</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\202\250\345\217\257\344\273\245\346\226\260\345\273\272\344\270\200\344\270\252\346\226\207\346\241\243\357\274\233</p>\n"
"<p style=\" margin-top:1"
                        "2px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\202\250\345\217\257\344\273\245\346\211\223\345\274\200\344\270\200\344\270\252\346\226\207\346\241\243\357\274\233</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\202\250\345\275\223\347\204\266\344\271\237\345\217\257\344\273\245\344\277\235\345\255\230\344\270\200\344\270\252\346\226\207\346\241\243\357\274\233</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\224\232\350\207\263\342\200\224\342\200\224\345\246\202\346\236\234\346\202\250\345\257\271\346\202\250\347\232\204\350\256\260\345\275\225\344\270\215\346\273\241\346\204\217\357\274\214\344\275\240\344\271\237\345\217\257\344\273\245\345\205\250\351\203\250\345\210\240\351\231\244\357\274\201</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-righ"
                        "t:0px; -qt-block-indent:0; text-indent:0px;\">\302\240</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\246\202\346\236\234\346\202\250\345\217\221\347\216\260\344\272\206\345\210\253\344\272\272\347\232\204\346\226\260\346\203\263\346\263\225\346\210\226\350\200\205\346\202\250\346\203\263\347\247\273\346\244\215\346\202\250\345\234\250\345\205\266\344\273\226\345\272\224\347\224\250\344\270\255\347\232\204\346\226\207\345\255\227\357\274\214\346\202\250\350\277\230\345\217\257\344\273\245\345\244\215\345\210\266\343\200\201\347\262\230\350\264\264\343\200\201\345\211\252\345\210\207\342\200\246\342\200\246</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\205\263\344\272\216\344\277\235\345\255\230\357\274\232</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:40px; margin-right:40px; -qt-block-indent:0; text-indent:0px;"
                        "\">\346\210\221\344\273\254\346\217\220\344\276\233\347\232\204\344\277\235\345\255\230\346\226\271\345\274\217\346\234\211\346\272\220\346\226\207\344\273\266\343\200\201\345\257\214\346\226\207\346\234\254\345\222\214txt\346\226\207\346\234\254\346\226\207\344\273\266\343\200\202\347\224\232\350\207\263\357\274\214\346\202\250\350\277\230\345\217\257\344\273\245\344\277\235\345\255\230\344\270\272\346\211\200\346\234\211\346\202\250\346\203\263\344\277\235\345\255\230\347\232\204\346\226\207\344\273\266\345\275\242\345\274\217\357\274\201</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:40px; margin-right:40px; -qt-block-indent:0; text-indent:0px;\">\346\263\250\357\274\232\345\257\214\346\226\207\346\234\254\345\217\257\344\273\245\344\277\235\345\255\230\346\202\250\346\211\200\345\210\233\351\200\240\347\232\204\344\273\273\344\275\225\346\240\267\345\274\217\357\274\214\344\275\206\346\230\257txt\345\222\214\346\272\220\346\226\207\344\273\266\345\215\264\344\270\215\350\241\214\343\200"
                        "\202\357\274\210\345\246\202\351\234\200\344\277\235\345\255\230\346\272\220\344\273\243\347\240\201\346\226\207\344\273\266\350\257\267\345\217\226\346\266\210\345\213\276\351\200\211&quot;\346\226\207\344\273\266-&gt;\344\277\235\345\255\230\344\270\272\345\257\214\346\226\207\346\234\254&quot;\357\274\214\345\246\202\351\234\200\344\273\245\344\273\243\347\240\201\345\275\242\345\274\217\346\211\223\345\274\200\345\257\214\346\226\207\346\234\254\346\226\207\344\273\266\350\257\267\345\217\226\346\266\210\345\213\276\351\200\211&quot;\346\226\207\344\273\266-&gt;\346\216\245\345\217\227\345\257\214\346\226\207\346\234\254\350\276\223\345\205\245&quot;\357\274\211</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\346\237\245\346\211\276</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346"
                        "\226\207\346\234\254\345\244\215\346\235\202\343\200\201\345\206\227\351\225\277\357\274\237\346\237\245\346\211\276\344\270\200\344\270\213\357\274\201\346\202\250\345\217\257\344\273\245\344\273\245\345\205\211\346\240\207\345\244\204\344\270\272\345\237\272\345\207\206\357\274\214\345\220\221\345\211\215\346\210\226\350\200\205\345\220\221\345\220\216\346\237\245\346\211\276\343\200\202</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\344\277\235\345\255\230\345\210\260Git</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\202\250\345\217\257\344\273\245\351\235\236\345\270\270\346\226\271\344\276\277\347\232\204\344\277\235\345\255\230\344\270\272Git\342\200\224\342\200\224</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\">\345\210\251\347\224\250\350\277\231\344\270\252\345\212\237\350\203\275\357\274\214\346\202\250\345\217\257\344\273\245\351\235\236\345\270\270\346\226\271\344\276\277\347\232\204\344\277\235\345\255\230\345\210\260\346\234\254\345\234\260Git\344\273\223\345\272\223\343\200\202</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\345\220\204\347\247\215\346\240\207\350\256\260</span></h3>\n"
"<h4 style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:medium; font-weight:600;\">\345\246\202\346\236\234\346\202\250\345\277\230\350\256\260\344\272\206\350\277\231\344\272\233\347\224\250\346\263\225\357\274\237\344\270\215\347\224\250\347\235\200\346\200\245\357\274\201</span></h4>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-blo"
                        "ck-indent:0; text-indent:0px;\">-&gt;\345\213\276\351\200\211&quot;\346\240\267\345\274\217-&gt;\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217\346\226\207\345\255\227\346\240\207\347\255\276&quot;</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\277\231\346\240\267\357\274\214\345\234\250\346\257\217\344\270\252\346\214\211\351\222\256\347\232\204\344\270\213\346\226\271\357\274\214\345\260\261\344\274\232\345\207\272\347\216\260\344\273\226\347\232\204\345\220\253\344\271\211\347\224\232\350\207\263\344\275\277\347\224\250\346\226\271\346\263\225\343\200\202</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\345\205\263\344\272\216\346\215\242\350\241\214</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-i"
                        "ndent:0px;\">\346\210\221\344\273\254\346\217\220\344\276\233\344\272\206\344\270\215\346\215\242\350\241\214\343\200\201\346\214\211\345\256\275\345\272\246\346\215\242\350\241\214\343\200\201\346\214\211\345\203\217\347\264\240\346\215\242\350\241\214\344\270\211\347\247\215\346\226\271\345\274\217\357\274\214\344\273\273\346\202\250\351\200\211\346\213\251\343\200\202</p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:large; font-weight:600;\">\345\205\263\344\272\216\347\274\251\350\277\233</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\246\202\346\236\234\346\202\250\345\210\251\347\224\250SurZ NoteBook\350\277\233\350\241\214\346\226\207\346\234\254\346\256\265\350\220\275\347\274\226\350\276\221\357\274\214\346\210\221\344\273\254\346\217\220\344\276\233\344\272\206\346\256\265\350\220\275\350\207\252\345"
                        "\212\250\347\274\251\350\277\233\345\212\237\350\203\275\343\200\202</p>\n"
"<h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:x-large; font-weight:600;\">\345\205\263\344\272\216BUG</span></h2>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\246\202\346\236\234\346\202\250\345\234\250\344\275\277\347\224\250\344\270\255\345\217\221\347\216\260\344\272\206\344\273\273\344\275\225BUG\357\274\214\346\254\242\350\277\216EMAIL AT <a href=\"mailto:QINGDKJ@OUTLOOK.COM\"><span style=\" text-decoration: underline; color:#007af4;\">QINGDKJ@OUTLOOK.COM</span></a>!</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\302\240</"
                        "p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
