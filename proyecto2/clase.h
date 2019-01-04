#ifndef CLASE_H
#define CLASE_H
#include <QString>
#include <QList>
#include <nodo.h>
#include <atributo.h>
#include <errorT.h>

class Clase
{
public:
    Clase();
    Clase(QString nombre, QString visibilidad, QString padre);
    void addAtributo(nodo *raiz);
    void addFuncion(nodo *raiz);
    QString nombre;
    QString visibilidad;
    QString padre;
    QList<Atributo> listaAtributos;
    QList<nodo> listaFunciones;
};

#endif // CLASE_H
