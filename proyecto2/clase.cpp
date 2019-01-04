#include "clase.h"
#include "mainwindow.h"
extern QList<errorT> listaErrores;


Clase::Clase()
{

}


Clase::Clase(QString nombre, QString visibilidad, QString padre)
{
    this->nombre=nombre;
    this->visibilidad =visibilidad;
    this->padre = padre;
}


void Clase::addAtributo(nodo *raiz)
{
    QString nombre = raiz->valor;
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
        errorT *nuevoError = new errorT("Semantico","Atributo " + nombre + " ya existe.",raiz->linea, raiz->columna);
        listaErrores.append(*nuevoError);
        return;
    }
    Atributo *atrib = new Atributo(nombre, raiz);
    this->listaAtributos.append(*atrib);
}


void Clase::addFuncion(nodo *raiz)
{
    QString nombre = raiz->valor;
    bool existe = false;
    for(int i = 0 ; i<this->listaFunciones.count(); i++)
    {
        if(nombre == listaFunciones[i].valor)
        {
            existe = true;
            break;
        }
    }
    if(existe)
    {
        // Registramos el error
        errorT *nuevoError = new errorT("Semantico"," Funcion " + nombre + " ya existe.",raiz->linea, raiz->columna);
        listaErrores.append(*nuevoError);
        return;
    }
    Atributo *atrib = new Atributo(nombre, raiz);
    this->listaAtributos.append(*atrib);
}
