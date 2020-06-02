#-------------------------------------------------
#
# Project created by QtCreator 2020-01-14T20:42:10
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = My_TextEdit
TEMPLATE = app

VERSION = 1.5.0.0    # 1.5.0.0

RC_ICONS = $$_PRO_FILE_PWD_/resource/images/icon/SurZ.ico


DEFINES += QT_DEPRECATED_WARNINGS


CONFIG += c++11

include($$_PRO_FILE_PWD_/src/src.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    $$_PRO_FILE_PWD_/resource/res.qrc
