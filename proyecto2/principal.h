#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <QString>
#include <QList>
#include <tablasimbolos.h>
#include <errorT.h>

class Principal
{
public:
    Principal();
    Principal(nodo * raiz);
    QList<QString> *listaCodigo;
    tablaSimbolos *tabla;
    QString claseActual;
    QString metodoActual;
    QList<QString> *ambito; // Esto es una pila
    QList<errorT> *listaErrores;
    QString codigo3D;
    int sobrescrito ; // 0 falso, 1 verdadero
    int contadorSent; // contador de sentencias.
    nodo *raiz;
};

#endif // PRINCIPAL_H
