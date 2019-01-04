#ifndef FUNCION_H
#define FUNCION_H
#include <QString>
#include <nodo.h>

class Funcion
{
public:
    Funcion( nodo *raiz);
    QString getId();
    QString nombre;
    QString id;
    nodo *raiz;
};

#endif // FUNCION_H
