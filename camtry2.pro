#-------------------------------------------------
#
# Project created by QtCreator 2017-01-30T03:25:09
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = camtry2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camop.cpp

HEADERS  += mainwindow.h \
    camop.h

FORMS    += mainwindow.ui
LIBS += -lglut -lGL -lGLU -lIL
