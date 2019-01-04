#include "funcion.h"

Funcion::Funcion(nodo *raiz)
{
    this->raiz = raiz;
    this->nombre = raiz->valor;
    this->id = getId();
}

QString Funcion::getId()
{
    nodo tmp = this->raiz->hijos[2];
    QString id = "";
    for(int i = 0; i<tmp.hijos.count(); i++)
    {
        if(i==0)
        {
            id = tmp.hijos[i].tipo;
        }
        else
        {
            id = id + "$" + tmp.hijos[i].tipo;
        }
    }
    return id;
}
