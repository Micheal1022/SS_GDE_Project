#-------------------------------------------------
#
# Project created by QtCreator 2020-09-14T13:32:48
#
#-------------------------------------------------


#DEFINES += BEVONE
DEFINES += SENSOR

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#DESTDIR = ./SSAPP/BEVONE
DESTDIR = ./SSAPP/SENSOR

TARGET = SS_GDE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    RecordInfo/recordinfo.cpp \
    SystemConf/systemconf.cpp \
    UserLgoin/userlgoin.cpp \
    ViewWidget/viewwidget.cpp \
    ViewWidget/sensoritem.cpp \
    ViewWidget/qwgraphicsview.cpp \
    ViewWidget/graphicsview.cpp

HEADERS += \
        mainwindow.h \
    RecordInfo/recordinfo.h \
    SystemConf/systemconf.h \
    UserLgoin/userlgoin.h \
    ViewWidget/viewwidget.h \
    ViewWidget/sensoritem.h \
    ViewWidget/qwgraphicsview.h \
    ViewWidget/graphicsview.h

FORMS += \
        mainwindow.ui \
    RecordInfo/recordinfo.ui \
    SystemConf/systemconf.ui \
    UserLgoin/userlgoin.ui \
    ViewWidget/viewwidget.ui \
    ViewWidget/graphicsview.ui

RESOURCES += \
    image.qrc

