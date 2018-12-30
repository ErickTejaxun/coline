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
    nodo(QString etiqueta, QString valor, int linea, int columna);
    void add(nodo nd);
    QList<nodo> hijos;
    QString tipo;
    QString valor;
    QString etiqueta;
    int linea;
    int columna;
};

#endif // NODO_H
