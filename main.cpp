#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QTranslator qtGloble;
    qtGloble.load(":/tr/tr/qtbase_zh_CN.qm");
    a.installTranslator(&qtGloble);

    a.setFont(QFont("Microsoft YaHei",9));

    MainWindow w;
    w.show();
    return a.exec();
}
