#include "simbolo.h"

Simbolo::Simbolo()
{
    this->nombre ="";
    this->tipo = "";
    this->rol = "";
    this->ambito = "";
    this->isArray = 0;
    this->linea = 0;
    this->columna = 0;
    this->tamano = 0;
    this->sobrescrito = 0;
    this->dimension = 0;
}

Simbolo::Simbolo(QString nombre, QString tipo, QString rol, QString ambito, int direccion, int tamanio, int dim, int ref)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->rol = rol;
    this->ambito = ambito;
    this->direccionGlobal = direccion;
    this->tamano = tamanio;
    this->dimension = dim ;
    this->referencia = ref;
    this->linea = 0;
    this->columna = 0;
    //this->raiz = NULL;
    this->isArray = 0;
    this->inicializado =0;
}


Simbolo::Simbolo(QString nombre, QString tipo, QString rol, QString ambito, int direccion, int tamanio, int dim, int ref, int linea, int columna
                 , nodo * raiz, int inicializacion)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->rol = rol;
    this->ambito = ambito;
    this->direccionGlobal = direccion;
    this->tamano = tamanio;
    this->dimension = dim ;
    this->referencia = ref;
    this->linea = linea;
    this->columna = columna;
    //this->raiz = raiz;
    this->isArray = 0;
    this->inicializado =inicializacion;
}

void Simbolo:: setValores(QString nombre, QString id, QString ambito, QString nivel, QString tipo, QString rol, int tamanio, QString visibilidad, int hereado, int sobrescribir)
{
    this->nombre = nombre;
    this->id = id;
    this->ambito = ambito;
    this->nivel = nivel;
    this->tipo = tipo;
    this->rol = rol;
    this->tamano = tamanio;
    this->visibilidad = visibilidad;
    this->heredado = heredado;
    this->sobrescribir = sobrescribir;
}


