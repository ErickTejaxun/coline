#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H
#include <simbolo.h>
#include <qlist.h>
#include <errorT.h>
#include <parser.h>
#include <scanner.h>
#include <qdebug.h>


class tablaSimbolos
{
public:
    tablaSimbolos();
    QList<Simbolo> *listaSimbolos; // lista de simbolos.
    QList<QString> *ambito; // Pila de ambitos
    int contadorIf;
    int contadorWhile;
    int contadorFor;
    int contadorDoWhile;
    int contadorElse;
    int contadorElseIf;


    Simbolo getSimbolo(QString id);
    int addSimbolo(Simbolo simbolo);
    int existeSimbolo(Simbolo simbolo);
    int existeSimbolo(QString nombre, QString ambito, QString tipo);
    int existeClase(QString nombreClase);


    int agregarClase(Simbolo clase, nodo  raiz);
    int agregarVariable(Simbolo simbolo, nodo  raiz);
    int getTamanoAmbitoActual(QString ambitoActual);
    int agregarFuncion(Simbolo constructor, nodo raiz);
    //int agregarFuncion(Simbolo *constructor, nodo raiz);


    void addError(QString tipo, QString desc, int linea, int columna);

    QList<QString> *listaCodigo;
    QString claseActual;
    QString metodoActual;
    //QList<errorT> *listaErrores;
    QString codigo3D;
    int sobrescrito ; // 0 falso, 1 verdadero
    int contadorSent; // contador de sentencias.
    nodo *raiz;

};

#endif // TABLASIMBOLOS_H
