#include "clase.h"
#include "mainwindow.h"
#include <qdebug.h>
extern QList<errorT> *listaErrores;


Clase::Clase()
{
    this->tipo = "clase";
}


Clase::Clase(QString nombre, QString visibilidad, QString padre)
{
    this->nombre=nombre;
    this->visibilidad =visibilidad;
    this->padre = padre;
}


void Clase::addAtributo(nodo raiz)
{
    QString nombre = raiz.valor;
    bool existe = false;
    for(int i = 0 ; i<this->listaAtributos.count(); i++)
    {
        if(nombre == listaAtributos[i].nombre)
        {
            existe = true;
            break;
        }
    }
    if(existe)
    {
        // Registramos el error
        errorT *nuevoError = new errorT("Semantico","Atributo " + nombre + " ya existe.",raiz.linea, raiz.columna);
        listaErrores->append(*nuevoError);
        return;
    }
    Atributo *atrib = new Atributo(nombre, raiz);
    this->listaAtributos.append(*atrib);
}


void Clase::addFuncion(nodo raiz)
{
    Funcion *fun = new Funcion(raiz);  
    qDebug() << fun->id;
    bool existe = false;
    for(int i = 0 ; i<this->listaFunciones.count(); i++)
    {
        if(fun->id == listaFunciones[i].id)
        {
            existe = true;
            break;
        }
    }
    if(existe)
    {
        // Registramos el error
        errorT *nuevoError = new errorT("Semantico"," Funcion " + fun->nombre + " ya existe.",raiz.linea, raiz.columna);
        listaErrores->append(*nuevoError);
        return;
    }
    this->listaFunciones.append(*fun);
}



