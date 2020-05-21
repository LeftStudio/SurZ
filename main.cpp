#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QTranslator>

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

    MainWindow w;
    w.show();
    return a.exec();
}
