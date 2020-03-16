/********************************************************************************
** Form generated from reading UI file 'searchframe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHFRAME_H
#define UI_SEARCHFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchFrame
{
public:
    QPushButton *OpenBtn;
    QWidget *DisplaceWidget;
    QLineEdit *DisplaceLineEdit;
    QPushButton *DisplaceBtn;
    QPushButton *DisplaceAllBtn;
    QWidget *SearchWidget;
    QLineEdit *SearchLineEdit;
    QPushButton *CaseSensitive;
    QPushButton *FindLastBtn;
    QPushButton *FindNextBtn;
    QPushButton *CloseBtn;

    void setupUi(QFrame *SearchFrame)
    {
        if (SearchFrame->objectName().isEmpty())
            SearchFrame->setObjectName(QString::fromUtf8("SearchFrame"));
        SearchFrame->resize(370, 90);
        SearchFrame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"border-style:none;\n"
"border-radius:10px;\n"
"padding:3px;\n"
"border:3px solid white;\n"
"background:lightgray;\n"
"}\n"
"\n"
"QPushButton\n"
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
        OpenBtn = new QPushButton(SearchFrame);
        OpenBtn->setObjectName(QString::fromUtf8("OpenBtn"));
        OpenBtn->setGeometry(QRect(10, 10, 20, 70));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OpenBtn->sizePolicy().hasHeightForWidth());
        OpenBtn->setSizePolicy(sizePolicy);
        OpenBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/down.ico"), QSize(), QIcon::Normal, QIcon::Off);
        OpenBtn->setIcon(icon);
        DisplaceWidget = new QWidget(SearchFrame);
        DisplaceWidget->setObjectName(QString::fromUtf8("DisplaceWidget"));
        DisplaceWidget->setGeometry(QRect(40, 50, 271, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DisplaceWidget->sizePolicy().hasHeightForWidth());
        DisplaceWidget->setSizePolicy(sizePolicy1);
        DisplaceWidget->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        DisplaceLineEdit = new QLineEdit(DisplaceWidget);
        DisplaceLineEdit->setObjectName(QString::fromUtf8("DisplaceLineEdit"));
        DisplaceLineEdit->setGeometry(QRect(0, 0, 191, 31));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DisplaceLineEdit->sizePolicy().hasHeightForWidth());
        DisplaceLineEdit->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        DisplaceLineEdit->setFont(font);
        DisplaceLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
"}"));
        DisplaceBtn = new QPushButton(DisplaceWidget);
        DisplaceBtn->setObjectName(QString::fromUtf8("DisplaceBtn"));
        DisplaceBtn->setGeometry(QRect(200, 0, 30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Displace.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DisplaceBtn->setIcon(icon1);
        DisplaceAllBtn = new QPushButton(DisplaceWidget);
        DisplaceAllBtn->setObjectName(QString::fromUtf8("DisplaceAllBtn"));
        DisplaceAllBtn->setGeometry(QRect(240, 0, 30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/DisplaceAll.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DisplaceAllBtn->setIcon(icon2);
        SearchWidget = new QWidget(SearchFrame);
        SearchWidget->setObjectName(QString::fromUtf8("SearchWidget"));
        SearchWidget->setGeometry(QRect(40, 10, 321, 31));
        SearchWidget->setStyleSheet(QString::fromUtf8(""));
        SearchLineEdit = new QLineEdit(SearchWidget);
        SearchLineEdit->setObjectName(QString::fromUtf8("SearchLineEdit"));
        SearchLineEdit->setGeometry(QRect(0, 0, 191, 31));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(SearchLineEdit->sizePolicy().hasHeightForWidth());
        SearchLineEdit->setSizePolicy(sizePolicy3);
        SearchLineEdit->setFont(font);
        SearchLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit\n"
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
"}"));
        CaseSensitive = new QPushButton(SearchWidget);
        CaseSensitive->setObjectName(QString::fromUtf8("CaseSensitive"));
        CaseSensitive->setGeometry(QRect(165, 5, 20, 20));
        CaseSensitive->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-style:none;\n"
"padding:2px;\n"
"border-radius:5px;\n"
"border:1px solid rgb(119,119,119);\n"
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
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"background:rgb(22,155,213);\n"
"border:1px solid rgb(22,155,213);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/CaseSensitive.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CaseSensitive->setIcon(icon3);
        CaseSensitive->setCheckable(true);
        CaseSensitive->setChecked(false);
        FindLastBtn = new QPushButton(SearchWidget);
        FindLastBtn->setObjectName(QString::fromUtf8("FindLastBtn"));
        FindLastBtn->setGeometry(QRect(200, 0, 30, 30));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(FindLastBtn->sizePolicy().hasHeightForWidth());
        FindLastBtn->setSizePolicy(sizePolicy4);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/left.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FindLastBtn->setIcon(icon4);
        FindNextBtn = new QPushButton(SearchWidget);
        FindNextBtn->setObjectName(QString::fromUtf8("FindNextBtn"));
        FindNextBtn->setGeometry(QRect(240, 0, 30, 30));
        sizePolicy4.setHeightForWidth(FindNextBtn->sizePolicy().hasHeightForWidth());
        FindNextBtn->setSizePolicy(sizePolicy4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/right.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FindNextBtn->setIcon(icon5);
        CloseBtn = new QPushButton(SearchWidget);
        CloseBtn->setObjectName(QString::fromUtf8("CloseBtn"));
        CloseBtn->setGeometry(QRect(290, 0, 30, 30));
        sizePolicy4.setHeightForWidth(CloseBtn->sizePolicy().hasHeightForWidth());
        CloseBtn->setSizePolicy(sizePolicy4);
        CloseBtn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/close.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CloseBtn->setIcon(icon6);

        retranslateUi(SearchFrame);

        QMetaObject::connectSlotsByName(SearchFrame);
    } // setupUi

    void retranslateUi(QFrame *SearchFrame)
    {
        SearchFrame->setWindowTitle(QApplication::translate("SearchFrame", "Frame", nullptr));
        OpenBtn->setText(QString());
        DisplaceLineEdit->setPlaceholderText(QApplication::translate("SearchFrame", "\346\233\277\346\215\242\344\270\272", nullptr));
#ifndef QT_NO_WHATSTHIS
        DisplaceBtn->setWhatsThis(QApplication::translate("SearchFrame", "\346\233\277\346\215\242", nullptr));
#endif // QT_NO_WHATSTHIS
        DisplaceBtn->setText(QString());
#ifndef QT_NO_WHATSTHIS
        DisplaceAllBtn->setWhatsThis(QApplication::translate("SearchFrame", "\345\205\250\351\203\250\346\233\277\346\215\242", nullptr));
#endif // QT_NO_WHATSTHIS
        DisplaceAllBtn->setText(QString());
#ifndef QT_NO_WHATSTHIS
        SearchLineEdit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        SearchLineEdit->setPlaceholderText(QApplication::translate("SearchFrame", "\346\237\245\346\211\276...", nullptr));
        CaseSensitive->setText(QString());
        FindLastBtn->setText(QString());
        FindNextBtn->setText(QString());
        CloseBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SearchFrame: public Ui_SearchFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHFRAME_H
