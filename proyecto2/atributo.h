#ifndef ATRIBUTO_H
#define ATRIBUTO_H
#include <QString>
#include <QObject>
#include <nodo.h>

class Atributo
{
public:
    Atributo();
    Atributo(QString nombre, nodo *raiz);
    QString nombre;
    nodo *raiz;
};

#endif // ATRIBUTO_H
