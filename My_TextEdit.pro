#-------------------------------------------------
#
# Project created by QtCreator 2020-01-14T20:42:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = My_TextEdit
TEMPLATE = app

VERSION = 1.2.0.0    # 1.2.0.0

RC_ICONS = images/SurZ.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        aboutdialog.cpp \
        gitdialog.cpp \
        helpdialog.cpp \
        imagesizedialog.cpp \
        insertdatedialog.cpp \
        main.cpp \
        mainwindow.cpp \
        my_texteditor.cpp \
        searchframe.cpp

HEADERS += \
        aboutdialog.h \
        gitdialog.h \
        helpdialog.h \
        imagesizedialog.h \
        insertdatedialog.h \
        mainwindow.h \
        my_texteditor.h \
        searchframe.h \
        switchbutton.h \
        wavewater.h

FORMS += \
        aboutdialog.ui \
        gitdialog.ui \
        helpdialog.ui \
        imagesizedialog.ui \
        insertdatedialog.ui \
        mainwindow.ui \
        searchframe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Quc/ -lquc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Quc/ -lqucd
else:unix: LIBS += -L$$PWD/Quc/ -lquc

INCLUDEPATH += $$PWD/Quc
DEPENDPATH += $$PWD/Quc
