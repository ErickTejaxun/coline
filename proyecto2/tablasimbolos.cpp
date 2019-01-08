#include "tablasimbolos.h"
extern QList<errorT> *listaErrores;  //
extern QString claseActual;

tablaSimbolos::tablaSimbolos()
{
    this->tabla = new QList<Simbolo>();
}

int tablaSimbolos::existeSimbolo(QString nombre, QString ambito, QString tipo)
{
    Simbolo  sim;
    for(int i =0 ; i<this->tabla->count();i++)
    {
         sim = this->tabla->takeAt(i);
         if
         (sim.id ==  nombre &&
          sim.tipo == ambito &&
          sim.rol == tipo)
         {
            return 0;
         }
    }
}


int tablaSimbolos:: agregarClase(Simbolo clase, nodo * raiz)
{
    for(int i =0  ; i<this->tabla->count(); i++)
    {
        if(this->tabla->value(i).nombre.toLower() == clase.nombre.toLower())
        {
            addError("Semantico", "La clase "+ clase.nombre+ " ya existe.",raiz->linea,raiz->columna);
            return 0;
        }
    }
    // Si no hay error, agregamos la clase.    
    this->tabla->append(clase);
    /*Agregamos el this
    clase.id = "este";
    clase.nombre = "este";
    this->tabla->append(clase);
    */
    claseActual = clase.nombre.toLower();
    return 1;
}

int tablaSimbolos:: agregarVariable(Simbolo variable, nodo * raiz)
{
    for(int i =0  ; i<this->tabla->count(); i++)
    {
        if(this->tabla->value(i).nombre.toLower() == variable.nombre.toLower() &&// id
           this->tabla->value(i).ambito.toLower() == variable.ambito.toLower()   // entorno
           )
        {
            addError("Semantico", "La variable "+ variable.nombre+ " ya existe.",raiz->linea,raiz->columna);
            return 0;
        }
    }
    // Si no hay error, agregamos la clase.
    //this->tabla->append(clase);
    this->tabla->append(variable);
    return 1;
}

int tablaSimbolos:: agregarFuncion(Simbolo constructor, nodo *raiz)
{
    for(int i =0  ; i<this->tabla->count(); i++)
    {
        if(this->tabla->value(i).id.toLower() == constructor.id.toLower() )
        {
            addError("Semantico", "Error en el constructor. Ya existe uno con el mismo tipo y cantidad de parametros.",raiz->linea,raiz->columna);
            return 0;
        }
    }
    // Si no hay error, agregamos la clase.
    this->tabla->append(constructor);
    return 1;
}









void tablaSimbolos:: addError(QString tipo, QString descripcion, int linea , int columna)
{
    errorT *error = new errorT(tipo, descripcion, linea, columna);
    listaErrores->append(*error);
}
