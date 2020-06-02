/********************/
/*  By Left Studio  */
/*     @Ho 229      */
/********************/

#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QTranslator>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForLocale(
                QTextCodec::codecForName("UTF-8"));

    QTranslator qtGloble;
    qtGloble.load(":/tr/tr/qtbase_zh_CN.qm");
    a.installTranslator(&qtGloble);

#ifdef Q_OS_WIN
    a.setFont(QFont("Microsoft YaHei",9));
#endif

    a.setWindowIcon(QIcon(":/images/images/icon/SurZ.ico"));

    QApplication::setQuitOnLastWindowClosed(false);

    MainWindow w;
    w.show();
    return a.exec();
}
