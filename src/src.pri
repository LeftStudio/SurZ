INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp \
    $$PWD/my_texteditor.cpp


HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/my_texteditor.h


include($$PWD/about/about.pri)
include($$PWD/customWidget/customWidget.pri)
include($$PWD/until/until.pri)
include($$PWD/translate/translate.pri)


FORMS += \
    $$PWD/mainwindow.ui

DISTFILES +=
