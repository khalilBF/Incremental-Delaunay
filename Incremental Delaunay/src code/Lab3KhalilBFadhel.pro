#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T19:52:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab3KhalilBFadhel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    visualiseur.cpp \
    point3d.cpp \
    curseurs.cpp \
    restriangles.cpp \
    triangle.cpp \
    matricetransformation.cpp

HEADERS  += mainwindow.h \
    visualiseur.h \
    point3d.h \
    curseurs.h \
    restriangles.h \
    triangle.h \
    matricetransformation.h

FORMS    += mainwindow.ui \
    visualiseur.ui \
    curseurs.ui
