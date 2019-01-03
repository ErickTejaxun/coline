#ifndef NODO_H
#define NODO_H
#include "nodo.h"
#include "QString"
#include "qlist.h"


class nodo
{
public:
    nodo();
    nodo(QString tipo);
    nodo(QString tipo, QString valor);
    nodo(QString tipo, QString valor, int linea, int columna);
    nodo(int tipo, QString valor, int linea, int columna);
    int getTipo();
    void add(nodo nd);
    QList<nodo> hijos;
    QString tipo;
    int tipo_;
    QString valor;
    QString etiqueta;
    int linea;
    int columna;
};

#endif // NODO_H
