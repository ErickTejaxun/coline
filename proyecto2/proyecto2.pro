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
    clase.cpp \
    atributo.cpp \
    funcion.cpp \
    tablasimbolos.cpp \
    simbolo.cpp \
    principal.cpp \
    simbol.cpp \
    variable.cpp \
    primerRecorrido.cpp \
    generadorcodigo.cpp \
    codigo3d.cpp \
    resultado.cpp \
    operaciones.cpp

HEADERS  += mainwindow.h \
    editor.h \
    scanner.h \
    parser.h \
    graficador.h \
    nodo.h \
    constantes.h \
    errorT.h \
    clase.h \
    atributo.h \
    funcion.h \
    tablasimbolos.h \
    simbolo.h \
    principal.h \
    simbol.h \
    variable.h \
    primerRecorrido.h \
    generadorcodigo.h \
    codigo3d.h \
    resultado.h \
    operaciones.h

FORMS    += mainwindow.ui \
    editor.ui

DISTFILES += \
    lexico.l \
    sintactico.yy \
    compilacion.bat \
    parser.output
