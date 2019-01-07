#include "principal.h"

Principal::Principal()
{
    this->listaCodigo = new QList<QString>();
    this->tabla = new tablaSimbolos();
    this->claseActual = "";
    this->metodoActual = "";
    this->ambito->push_back("global");
    this->listaErrores = new QList<errorT>();
    this->sobrescrito = 0; // falso
    this->contadorSent = 1;    
}
Principal:: Principal(nodo * raiz)
{
    Principal(); // :v
    this->raiz = raiz;
}
