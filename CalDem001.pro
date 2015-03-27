#-------------------------------------------------
#
# Project created by QtCreator 2015-03-26T13:13:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CalDem001
TEMPLATE = app


SOURCES += main.cpp\
        src/mainwindow.cpp \
    src/inputdlg.cpp \
    src/celement.cpp \
    src/contact.cpp \
    src/caculate.cpp

HEADERS  += include/mainwindow.h \
    include/inputdlg.h \
    include/celement.h \
    include/contact.h \
    include/caculate.h

FORMS    += layout/mainwindow.ui \
    layout/inputdlg.ui
