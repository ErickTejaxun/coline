#include "nodo.h"


nodo::nodo()
{        
    tipo ="";
    valor = "";
    linea = 0;
    columna = 0;    
    hijos =  QList<nodo>();
}

nodo::nodo(QString etiqueta, QString valor)
{
    nodo();
    this->tipo = etiqueta;
    this->valor = valor;    
}

nodo::nodo(QString etiqueta, QString valor, int linea, int columna)
{
    nodo();
    this->tipo = etiqueta;
    this->valor = valor;
    this->columna = columna;
    this->linea = linea;    
}

void nodo::add(nodo nd)
{
    this->hijos.append(nd);
}



nodo::nodo(QString etiqueta)
{
    nodo();
    this->tipo = etiqueta;    
}


