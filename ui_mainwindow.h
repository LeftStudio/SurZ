/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_texteditor.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actNew;
    QAction *actFontBold;
    QAction *actFontItalic;
    QAction *actFontUnder;
    QAction *actOpen;
    QAction *actSave;
    QAction *actExit;
    QAction *actClear;
    QAction *actNoWrap;
    QAction *actWidgetWidth;
    QAction *actFixedPixelWidth;
    QAction *actSaveAs;
    QAction *actSetTextColor;
    QAction *actLeftAlign;
    QAction *actCenter;
    QAction *actRightAlign;
    QAction *actSearch;
    QAction *actHelp;
    QAction *actAbout;
    QAction *actUpdateToGit;
    QAction *actToolbarStyle;
    QAction *actSaveToRichText;
    QAction *actAcceptRichText;
    QAction *actIndent;
    QAction *actAboutQt;
    QAction *actWindowTop;
    QAction *actClearData;
    QAction *actInsterPicture;
    QAction *actInsterForm;
    QAction *actCreateLink;
    QAction *actInsertDate;
    QAction *actTomatoBell;
    QAction *actConcise;
    QWidget *centralWidget;
    My_TextEditor *txtEdit;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *RecentlyOpenedMenu;
    QMenu *edit;
    QMenu *help;
    QMenu *format;
    QMenu *WrapMenu;
    QMenu *inster;
    QMenu *tools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *TextStyleToolBar;
    QToolBar *InsertToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(909, 622);
        MainWindow->setMinimumSize(QSize(600, 400));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"background:white;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"background:#aaaaff;\n"
"color:white;\n"
"}\n"
"\n"
"QToolBar\n"
"{\n"
"border-style:none;\n"
"border-radius:10px;\n"
"padding:3px;\n"
"border:3px solid white;\n"
"background:lightgray;\n"
"}\n"
"\n"
"QToolBar::separator\n"
"{\n"
"margin:5 5px;\n"
"background:rgb(49, 49, 49);\n"
"width:2px;\n"
"height:2px;\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"\n"
"}\n"
"\n"
"QMenuBar\n"
"{\n"
"background:white;\n"
"}"));
        MainWindow->setInputMethodHints(Qt::ImhNone);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextOnly);
        actCut = new QAction(MainWindow);
        actCut->setObjectName(QString::fromUtf8("actCut"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/cut_128px_1223050_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actCut->setIcon(icon);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        actCut->setFont(font1);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName(QString::fromUtf8("actCopy"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/copy_128px_1223049_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::On);
        actCopy->setIcon(icon1);
        actCopy->setFont(font1);
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName(QString::fromUtf8("actPaste"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/clipboard_128px_1222862_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actPaste->setIcon(icon2);
        actPaste->setFont(font1);
        actNew = new QAction(MainWindow);
        actNew->setObjectName(QString::fromUtf8("actNew"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/file_create_128px.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actNew->setIcon(icon3);
        actNew->setFont(font1);
        actFontBold = new QAction(MainWindow);
        actFontBold->setObjectName(QString::fromUtf8("actFontBold"));
        actFontBold->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/text_bold_104px_1223110_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actFontBold->setIcon(icon4);
        actFontBold->setFont(font1);
        actFontItalic = new QAction(MainWindow);
        actFontItalic->setObjectName(QString::fromUtf8("actFontItalic"));
        actFontItalic->setCheckable(true);
        actFontItalic->setChecked(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/text_italic_101px_1223112_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actFontItalic->setIcon(icon5);
        actFontItalic->setFont(font1);
        actFontUnder = new QAction(MainWindow);
        actFontUnder->setObjectName(QString::fromUtf8("actFontUnder"));
        actFontUnder->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/text_underline_32px_1223113_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actFontUnder->setIcon(icon6);
        actFontUnder->setFont(font1);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QString::fromUtf8("actOpen"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/folder_opened_128px.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon7);
        actOpen->setFont(font1);
        actSave = new QAction(MainWindow);
        actSave->setObjectName(QString::fromUtf8("actSave"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/floppy_128px_1222830_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actSave->setIcon(icon8);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(false);
        font2.setWeight(50);
        actSave->setFont(font2);
        actExit = new QAction(MainWindow);
        actExit->setObjectName(QString::fromUtf8("actExit"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/arrow_left_curved_128px_1223140_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon9);
        actClear = new QAction(MainWindow);
        actClear->setObjectName(QString::fromUtf8("actClear"));
        actClear->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/delete_128px_1223051_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon10);
        actClear->setFont(font1);
        actNoWrap = new QAction(MainWindow);
        actNoWrap->setObjectName(QString::fromUtf8("actNoWrap"));
        actWidgetWidth = new QAction(MainWindow);
        actWidgetWidth->setObjectName(QString::fromUtf8("actWidgetWidth"));
        actFixedPixelWidth = new QAction(MainWindow);
        actFixedPixelWidth->setObjectName(QString::fromUtf8("actFixedPixelWidth"));
        actSaveAs = new QAction(MainWindow);
        actSaveAs->setObjectName(QString::fromUtf8("actSaveAs"));
        actSetTextColor = new QAction(MainWindow);
        actSetTextColor->setObjectName(QString::fromUtf8("actSetTextColor"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/images/color_palette_128px_1202956_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actSetTextColor->setIcon(icon11);
        actSetTextColor->setFont(font2);
        actLeftAlign = new QAction(MainWindow);
        actLeftAlign->setObjectName(QString::fromUtf8("actLeftAlign"));
        actLeftAlign->setCheckable(true);
        actLeftAlign->setChecked(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/images/text_align_left_128px_1223107_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actLeftAlign->setIcon(icon12);
        actLeftAlign->setFont(font);
        actCenter = new QAction(MainWindow);
        actCenter->setObjectName(QString::fromUtf8("actCenter"));
        actCenter->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/images/text_align_center_128px_1223105_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actCenter->setIcon(icon13);
        actCenter->setFont(font);
        actRightAlign = new QAction(MainWindow);
        actRightAlign->setObjectName(QString::fromUtf8("actRightAlign"));
        actRightAlign->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/images/text_align_right_128px_1223108_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actRightAlign->setIcon(icon14);
        actRightAlign->setFont(font);
        actSearch = new QAction(MainWindow);
        actSearch->setObjectName(QString::fromUtf8("actSearch"));
        actSearch->setEnabled(false);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/images/Search_128px_1190971_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actSearch->setIcon(icon15);
        actSearch->setFont(font);
        actHelp = new QAction(MainWindow);
        actHelp->setObjectName(QString::fromUtf8("actHelp"));
        actAbout = new QAction(MainWindow);
        actAbout->setObjectName(QString::fromUtf8("actAbout"));
        actUpdateToGit = new QAction(MainWindow);
        actUpdateToGit->setObjectName(QString::fromUtf8("actUpdateToGit"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/images/vc_git_128px_1097266_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actUpdateToGit->setIcon(icon16);
        actUpdateToGit->setFont(font);
        actToolbarStyle = new QAction(MainWindow);
        actToolbarStyle->setObjectName(QString::fromUtf8("actToolbarStyle"));
        actToolbarStyle->setCheckable(true);
        actSaveToRichText = new QAction(MainWindow);
        actSaveToRichText->setObjectName(QString::fromUtf8("actSaveToRichText"));
        actSaveToRichText->setCheckable(true);
        actSaveToRichText->setChecked(true);
        actAcceptRichText = new QAction(MainWindow);
        actAcceptRichText->setObjectName(QString::fromUtf8("actAcceptRichText"));
        actAcceptRichText->setCheckable(true);
        actAcceptRichText->setChecked(true);
        actIndent = new QAction(MainWindow);
        actIndent->setObjectName(QString::fromUtf8("actIndent"));
        actIndent->setCheckable(true);
        actAboutQt = new QAction(MainWindow);
        actAboutQt->setObjectName(QString::fromUtf8("actAboutQt"));
        actWindowTop = new QAction(MainWindow);
        actWindowTop->setObjectName(QString::fromUtf8("actWindowTop"));
        actWindowTop->setCheckable(true);
        actWindowTop->setChecked(false);
        actWindowTop->setEnabled(true);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/images/WindowTop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actWindowTop->setIcon(icon17);
        actWindowTop->setFont(font);
        actClearData = new QAction(MainWindow);
        actClearData->setObjectName(QString::fromUtf8("actClearData"));
        actInsterPicture = new QAction(MainWindow);
        actInsterPicture->setObjectName(QString::fromUtf8("actInsterPicture"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/images/images/image_picture_128px.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actInsterPicture->setIcon(icon18);
        actInsterPicture->setFont(font);
        actInsterForm = new QAction(MainWindow);
        actInsterForm->setObjectName(QString::fromUtf8("actInsterForm"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/images/images/spreadsheet_128px.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actInsterForm->setIcon(icon19);
        actInsterForm->setFont(font);
        actCreateLink = new QAction(MainWindow);
        actCreateLink->setObjectName(QString::fromUtf8("actCreateLink"));
        actInsertDate = new QAction(MainWindow);
        actInsertDate->setObjectName(QString::fromUtf8("actInsertDate"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/images/images/calendar_128px.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actInsertDate->setIcon(icon20);
        actTomatoBell = new QAction(MainWindow);
        actTomatoBell->setObjectName(QString::fromUtf8("actTomatoBell"));
        actConcise = new QAction(MainWindow);
        actConcise->setObjectName(QString::fromUtf8("actConcise"));
        actConcise->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setFont(font);
        txtEdit = new My_TextEditor(centralWidget);
        txtEdit->setObjectName(QString::fromUtf8("txtEdit"));
        txtEdit->setGeometry(QRect(0, 0, 871, 541));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtEdit->sizePolicy().hasHeightForWidth());
        txtEdit->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        txtEdit->setFont(font3);
        txtEdit->setContextMenuPolicy(Qt::DefaultContextMenu);
        txtEdit->setLayoutDirection(Qt::LeftToRight);
        txtEdit->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"border-style:none;\n"
"padding:3px;\n"
"border-radius:10px;\n"
"border:3px solid #DCE4EC;\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"border:3px solid #aaaaff;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"background:rgb(242,242,242)\n"
"}"));
        txtEdit->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        txtEdit->setTabChangesFocus(false);
        txtEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 909, 22));
        file = new QMenu(menuBar);
        file->setObjectName(QString::fromUtf8("file"));
        RecentlyOpenedMenu = new QMenu(file);
        RecentlyOpenedMenu->setObjectName(QString::fromUtf8("RecentlyOpenedMenu"));
        edit = new QMenu(menuBar);
        edit->setObjectName(QString::fromUtf8("edit"));
        help = new QMenu(menuBar);
        help->setObjectName(QString::fromUtf8("help"));
        format = new QMenu(menuBar);
        format->setObjectName(QString::fromUtf8("format"));
        WrapMenu = new QMenu(format);
        WrapMenu->setObjectName(QString::fromUtf8("WrapMenu"));
        inster = new QMenu(menuBar);
        inster->setObjectName(QString::fromUtf8("inster"));
        tools = new QMenu(menuBar);
        tools->setObjectName(QString::fromUtf8("tools"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setFont(font2);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setToolTipDuration(-1);
        statusBar->setAutoFillBackground(false);
        statusBar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setStatusBar(statusBar);
        TextStyleToolBar = new QToolBar(MainWindow);
        TextStyleToolBar->setObjectName(QString::fromUtf8("TextStyleToolBar"));
        TextStyleToolBar->setFont(font);
        TextStyleToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, TextStyleToolBar);
        InsertToolBar = new QToolBar(MainWindow);
        InsertToolBar->setObjectName(QString::fromUtf8("InsertToolBar"));
        InsertToolBar->setFont(font);
        InsertToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, InsertToolBar);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(edit->menuAction());
        menuBar->addAction(format->menuAction());
        menuBar->addAction(inster->menuAction());
        menuBar->addAction(tools->menuAction());
        menuBar->addAction(help->menuAction());
        file->addAction(actNew);
        file->addAction(actOpen);
        file->addAction(RecentlyOpenedMenu->menuAction());
        file->addSeparator();
        file->addAction(actSave);
        file->addAction(actSaveAs);
        file->addSeparator();
        file->addAction(actAcceptRichText);
        file->addAction(actSaveToRichText);
        file->addSeparator();
        file->addAction(actExit);
        RecentlyOpenedMenu->addAction(actClearData);
        RecentlyOpenedMenu->addSeparator();
        edit->addAction(actCut);
        edit->addAction(actCopy);
        edit->addAction(actPaste);
        edit->addSeparator();
        edit->addAction(actClear);
        edit->addSeparator();
        edit->addAction(actSearch);
        help->addAction(actHelp);
        help->addSeparator();
        help->addAction(actCreateLink);
        help->addSeparator();
        help->addAction(actAbout);
        help->addAction(actAboutQt);
        format->addAction(actLeftAlign);
        format->addAction(actCenter);
        format->addAction(actRightAlign);
        format->addSeparator();
        format->addAction(actFontBold);
        format->addAction(actFontItalic);
        format->addAction(actFontUnder);
        format->addSeparator();
        format->addAction(actSetTextColor);
        format->addSeparator();
        format->addAction(actToolbarStyle);
        format->addSeparator();
        format->addAction(WrapMenu->menuAction());
        format->addAction(actIndent);
        WrapMenu->addAction(actNoWrap);
        WrapMenu->addSeparator();
        WrapMenu->addAction(actWidgetWidth);
        WrapMenu->addAction(actFixedPixelWidth);
        inster->addAction(actInsterPicture);
        inster->addAction(actInsterForm);
        tools->addAction(actConcise);
        mainToolBar->addAction(actNew);
        mainToolBar->addAction(actOpen);
        mainToolBar->addAction(actSave);
        mainToolBar->addAction(actClear);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actCut);
        mainToolBar->addAction(actCopy);
        mainToolBar->addAction(actPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actSearch);
        mainToolBar->addAction(actWindowTop);
        mainToolBar->addAction(actUpdateToGit);
        TextStyleToolBar->addAction(actLeftAlign);
        TextStyleToolBar->addAction(actCenter);
        TextStyleToolBar->addAction(actRightAlign);
        TextStyleToolBar->addSeparator();
        TextStyleToolBar->addAction(actFontItalic);
        TextStyleToolBar->addAction(actFontBold);
        TextStyleToolBar->addAction(actFontUnder);
        TextStyleToolBar->addSeparator();
        InsertToolBar->addAction(actInsterPicture);
        InsertToolBar->addAction(actInsterForm);
        InsertToolBar->addAction(actInsertDate);

        retranslateUi(MainWindow);
        QObject::connect(actExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actCut, SIGNAL(triggered()), txtEdit, SLOT(cut()));
        QObject::connect(actPaste, SIGNAL(triggered()), txtEdit, SLOT(paste()));
        QObject::connect(actCopy, SIGNAL(triggered()), txtEdit, SLOT(copy()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\271\246\347\237\245\347\274\226\350\276\221\345\231\250", nullptr));
        actCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#ifndef QT_NO_TOOLTIP
        actCut->setToolTip(QApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#ifndef QT_NO_SHORTCUT
        actCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#ifndef QT_NO_SHORTCUT
        actPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
#ifndef QT_NO_TOOLTIP
        actNew->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actFontBold->setText(QApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#ifndef QT_NO_TOOLTIP
        actFontBold->setToolTip(QApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actFontBold->setShortcut(QApplication::translate("MainWindow", "Alt+B", nullptr));
#endif // QT_NO_SHORTCUT
        actFontItalic->setText(QApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#ifndef QT_NO_TOOLTIP
        actFontItalic->setToolTip(QApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actFontItalic->setShortcut(QApplication::translate("MainWindow", "Alt+I", nullptr));
#endif // QT_NO_SHORTCUT
        actFontUnder->setText(QApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#ifndef QT_NO_SHORTCUT
        actFontUnder->setShortcut(QApplication::translate("MainWindow", "Alt+U", nullptr));
#endif // QT_NO_SHORTCUT
        actOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200...(&O)", nullptr));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#ifndef QT_NO_TOOLTIP
        actSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_TOOLTIP
        actExit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("MainWindow", "\346\270\205\347\251\272\345\206\205\345\256\271", nullptr));
#endif // QT_NO_TOOLTIP
        actNoWrap->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#ifndef QT_NO_TOOLTIP
        actNoWrap->setToolTip(QApplication::translate("MainWindow", "\345\205\263\351\227\255\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#endif // QT_NO_TOOLTIP
        actWidgetWidth->setText(QApplication::translate("MainWindow", "\346\214\211\345\256\275\345\272\246\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#ifndef QT_NO_TOOLTIP
        actWidgetWidth->setToolTip(QApplication::translate("MainWindow", "\346\214\211\345\256\275\345\272\246\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#endif // QT_NO_TOOLTIP
        actFixedPixelWidth->setText(QApplication::translate("MainWindow", "\346\214\211\345\215\225\345\203\217\347\264\240\345\256\275\345\272\246\346\215\242\350\241\214", nullptr));
#ifndef QT_NO_TOOLTIP
        actFixedPixelWidth->setToolTip(QApplication::translate("MainWindow", "\346\214\211\345\215\225\345\203\217\347\264\240\345\256\275\345\272\246\346\215\242\350\241\214", nullptr));
#endif // QT_NO_TOOLTIP
        actSaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272...", nullptr));
#ifndef QT_NO_TOOLTIP
        actSaveAs->setToolTip(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_NO_TOOLTIP
        actSetTextColor->setText(QApplication::translate("MainWindow", "\350\260\203\350\211\262\346\235\277", nullptr));
#ifndef QT_NO_TOOLTIP
        actSetTextColor->setToolTip(QApplication::translate("MainWindow", "\350\260\203\346\225\264\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSetTextColor->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actLeftAlign->setText(QApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220", nullptr));
#ifndef QT_NO_TOOLTIP
        actLeftAlign->setToolTip(QApplication::translate("MainWindow", "\345\260\206\345\206\205\345\256\271\344\270\216\345\267\246\350\276\271\350\267\235\345\257\271\351\275\220", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actLeftAlign->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actCenter->setText(QApplication::translate("MainWindow", "\345\261\205\344\270\255", nullptr));
#ifndef QT_NO_TOOLTIP
        actCenter->setToolTip(QApplication::translate("MainWindow", "\344\275\277\345\206\205\345\256\271\345\234\250\347\225\214\351\235\242\344\270\212\345\261\205\344\270\255\345\257\271\351\275\220", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actCenter->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        actRightAlign->setText(QApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220", nullptr));
#ifndef QT_NO_TOOLTIP
        actRightAlign->setToolTip(QApplication::translate("MainWindow", "\345\260\206\345\206\205\345\256\271\344\270\216\345\267\246\350\276\271\350\267\235\345\257\271\351\275\220", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actRightAlign->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actSearch->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
#ifndef QT_NO_TOOLTIP
        actSearch->setToolTip(QApplication::translate("MainWindow", "\346\237\245\346\211\276\346\214\207\345\256\232\346\226\207\346\234\254", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actSearch->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actHelp->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\270\256\345\212\251(&H)", nullptr));
#ifndef QT_NO_TOOLTIP
        actHelp->setToolTip(QApplication::translate("MainWindow", "\350\216\267\345\217\226\345\270\256\345\212\251", nullptr));
#endif // QT_NO_TOOLTIP
        actAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216...(&A)", nullptr));
#ifndef QT_NO_TOOLTIP
        actAbout->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216\344\271\246\347\237\245", nullptr));
#endif // QT_NO_TOOLTIP
        actUpdateToGit->setText(QApplication::translate("MainWindow", "Git", nullptr));
#ifndef QT_NO_TOOLTIP
        actUpdateToGit->setToolTip(QApplication::translate("MainWindow", "\346\217\220\344\272\244\350\207\263Git", nullptr));
#endif // QT_NO_TOOLTIP
        actToolbarStyle->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217\346\226\207\345\255\227\346\240\207\347\255\276", nullptr));
#ifndef QT_NO_TOOLTIP
        actToolbarStyle->setToolTip(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217\346\226\207\345\255\227\346\240\207\347\255\276", nullptr));
#endif // QT_NO_TOOLTIP
        actSaveToRichText->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272\345\257\214\346\226\207\346\234\254", nullptr));
#ifndef QT_NO_TOOLTIP
        actSaveToRichText->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\272\345\257\214\346\226\207\346\234\254(\347\272\257\346\226\207\346\234\254\344\277\235\345\255\230\350\257\267\345\217\226\346\266\210\345\213\276\351\200\211\346\255\244\351\241\271)", nullptr));
#endif // QT_NO_TOOLTIP
        actAcceptRichText->setText(QApplication::translate("MainWindow", "\346\216\245\345\217\227\345\257\214\346\226\207\346\234\254\350\276\223\345\205\245", nullptr));
#ifndef QT_NO_TOOLTIP
        actAcceptRichText->setToolTip(QApplication::translate("MainWindow", "\346\216\245\345\217\227\345\257\214\346\226\207\346\234\254\350\276\223\345\205\245", nullptr));
#endif // QT_NO_TOOLTIP
        actIndent->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\347\274\251\350\277\233", nullptr));
#ifndef QT_NO_TOOLTIP
        actIndent->setToolTip(QApplication::translate("MainWindow", "\350\207\252\345\212\250\347\274\251\350\277\233", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actIndent->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actAboutQt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", nullptr));
#ifndef QT_NO_TOOLTIP
        actAboutQt->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", nullptr));
#endif // QT_NO_TOOLTIP
        actWindowTop->setText(QApplication::translate("MainWindow", "\347\252\227\345\217\243\347\275\256\351\241\266", nullptr));
#ifndef QT_NO_TOOLTIP
        actWindowTop->setToolTip(QApplication::translate("MainWindow", "\347\252\227\345\217\243\347\275\256\351\241\266", nullptr));
#endif // QT_NO_TOOLTIP
        actClearData->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\350\256\260\345\275\225", nullptr));
        actInsterPicture->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\345\233\276\347\211\207", nullptr));
#ifndef QT_NO_TOOLTIP
        actInsterPicture->setToolTip(QApplication::translate("MainWindow", "\345\220\221\345\257\214\346\226\207\346\234\254\346\241\206\344\270\255\346\217\222\345\205\245\345\233\276\347\211\207", nullptr));
#endif // QT_NO_TOOLTIP
        actInsterForm->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\350\241\250\346\240\274", nullptr));
#ifndef QT_NO_TOOLTIP
        actInsterForm->setToolTip(QApplication::translate("MainWindow", "\345\220\221\345\257\214\346\226\207\346\234\254\346\241\206\344\270\255\346\217\222\345\205\245\350\241\250\346\240\274", nullptr));
#endif // QT_NO_TOOLTIP
        actCreateLink->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272\346\241\214\351\235\242\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
#ifndef QT_NO_TOOLTIP
        actCreateLink->setToolTip(QApplication::translate("MainWindow", "\345\210\233\345\273\272\346\241\214\351\235\242\345\277\253\346\215\267\346\226\271\345\274\217", nullptr));
#endif // QT_NO_TOOLTIP
        actInsertDate->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\346\227\245\346\234\237", nullptr));
#ifndef QT_NO_TOOLTIP
        actInsertDate->setToolTip(QApplication::translate("MainWindow", "\346\217\222\345\205\245\346\227\266\351\227\264\345\222\214\346\227\245\346\234\237", nullptr));
#endif // QT_NO_TOOLTIP
        actTomatoBell->setText(QApplication::translate("MainWindow", "\347\225\252\350\214\204\351\222\237", nullptr));
        actConcise->setText(QApplication::translate("MainWindow", "\347\256\200\346\264\201\346\250\241\345\274\217", nullptr));
        file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        RecentlyOpenedMenu->setTitle(QApplication::translate("MainWindow", "\346\234\200\350\277\221\350\256\277\351\227\256\347\232\204\346\226\207\344\273\266", nullptr));
        edit->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        format->setTitle(QApplication::translate("MainWindow", "\346\240\267\345\274\217(&S)", nullptr));
        WrapMenu->setTitle(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214...", nullptr));
        inster->setTitle(QApplication::translate("MainWindow", "\346\217\222\345\205\245(&I)", nullptr));
        tools->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267(&T)", nullptr));
        TextStyleToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        InsertToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
