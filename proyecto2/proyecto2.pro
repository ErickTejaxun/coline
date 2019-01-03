#-------------------------------------------------
#
# Project created by QtCreator 2018-12-26T11:05:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editor.cpp \
    parser.cpp \
    scanner.cpp \
    graficador.cpp \
    nodo.cpp \
    constantes.cpp \
    error.cpp \
    interprete.cpp

HEADERS  += mainwindow.h \
    editor.h \
    scanner.h \
    parser.h \
    graficador.h \
    nodo.h \
    constantes.h \
    interprete.h \
    errorT.h

FORMS    += mainwindow.ui \
    editor.ui

DISTFILES += \
    lexico.l \
    sintactico.yy \
    compilacion.bat \
    parser.output
