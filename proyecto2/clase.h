#ifndef CLASE_H
#define CLASE_H
#include <QString>
#include <QList>
#include <nodo.h>
#include <atributo.h>
#include <errorT.h>
#include <funcion.h>
#include <simbolo.h>

class Clase : public Simbolo
{
public:
    Clase();
    Clase(QString nombre, QString visibilidad, QString padre);
    void addAtributo(nodo raiz);
    void addFuncion(nodo raiz);       
    QList<Atributo> listaAtributos;
    QList<Funcion> listaFunciones;
};

#endif // CLASE_H
