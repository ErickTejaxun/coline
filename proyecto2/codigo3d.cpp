#include "codigo3d.h"
#include <QList>
#include <primerRecorrido.h>
#include <resultado.h>
extern  primerRecorrido *recorrido1;
extern QList<errorT> *listaErrores;
Codigo3d::Codigo3d()
{
    this->cadena3d ="";
    this->etiqueta = 0;
    this->temporal = 0;
    this->pilaAmbitos = new QList<QString>();
    this->pilaAmbitos->append("global");
    this->NADA_ = 78331339*7;
}
QString Codigo3d::genEti()
{
    return "L" + QString::number(etiqueta++);
}

QString Codigo3d:: genTemp()
{
    return "t" +QString::number(temporal++);
}

void Codigo3d:: apilarMetodo(QString nombreMetodo)
{
    this->metodoActual = nombreMetodo;
    this->pilaAmbitos->append(nombreMetodo);
}

void Codigo3d:: desapilarMetodo()
{
    this->pilaAmbitos->pop_back();
    metodoActual = this->pilaAmbitos->value(this->pilaAmbitos->count()-1);
    tablaSimbolos * tabla = recorrido1->tabla;
    int a = 100;
}

QString Codigo3d::getAmbitoActual()
{
   QString ambito ="";
   for(int i =0 ; i < this->pilaAmbitos->count(); i++)
   {
       if(ambito=="")
       {
           ambito = this->pilaAmbitos->value(i);
       }
       else
       {
           ambito += "$"+ this->pilaAmbitos->value(i);
       }
   }
   return ambito;
}

QString Codigo3d:: getMetodoActual()
{
    return this->metodoActual;
}

int Codigo3d:: getTamanoAmbitoActual()
{
    QString actual = getAmbitoActual();
    int contador  = 0;
    for(int i = 0 ; i < recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(actual == recorrido1->tabla->listaSimbolos->value(i).ambito)
        {
            contador++;
        }
    }
    return contador;
}

int Codigo3d:: getTamanoAmbitoActual(QString actual)
{
    int contador  = 0;
    for(int i = 0 ; i < recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(actual == recorrido1->tabla->listaSimbolos->value(i).ambito)
        {
            contador++;
        }
    }
    return contador;
}

Simbolo Codigo3d:: getSimboloPorId(QString id)
{
    Simbolo simbolo ;
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(recorrido1->tabla->listaSimbolos->value(i).id == id)
        {
            return recorrido1->tabla->listaSimbolos->value(i);
        }
    }
    return simbolo;
}

Simbolo Codigo3d::getSimboloPorNombre(QString nombre)
{
    Simbolo simbolo ;
    Simbolo simaux ;
    tablaSimbolos * tabla = recorrido1->tabla;
    QString ambito = getAmbitoActual();    
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        simaux = tabla->listaSimbolos->value(i);
        qDebug() << "------------------------------";
        qDebug() << nombre << "==="<< simaux.nombre;
        qDebug() << ambito  << "==="<<simaux.ambito;
        if(
           simaux.nombre ==nombre&&
           simaux.ambito == ambito)
        {
            /*qDebug() << "Encontatrado en "<< i;
            simbolo.id = simaux.id;
            simbolo.nombre = simaux.nombre;
            simbolo.direccionLocal = simaux.direccionLocal;
            simbolo.direccionGlobal = simaux.direccionGlobal;
            simbolo.ambito = simaux.ambito;
            simbolo.raiz = simaux.raiz;*/
            return simaux;
        }
    }
    return simbolo;
}

Simbolo Codigo3d:: getSimboloDeclaracion(QString nombre)
/*Este metodo sirve para cuando se instancia algún objeto dentro de un método.
Para asignaciones
*/
{    
    QList<QString> *pilaAuxiliar  =  new QList<QString>();
    for(int i = 0; i< this->pilaAmbitos->count(); i++)
    {
        pilaAuxiliar->append(pilaAmbitos->value(i));
    }

    int encontrado = 0;    
    Simbolo simboloBuscado;
    while(!encontrado)
    {
        simboloBuscado = getSimboloPorNombre(nombre);
        if(simboloBuscado.id !="")
        {
            /*Limpiamos la pila*/
            this->pilaAmbitos->clear();
            for(int j = 0 ; j < pilaAuxiliar->count(); j++)
            {
                this->pilaAmbitos->append(pilaAuxiliar->value(j));
            }
            encontrado = 1;
            return  simboloBuscado;
        }
        if(getAmbitoActual()=="global")
        {
            /*Limpiamos la pila*/
            this->pilaAmbitos->clear();
            for(int j = 0 ; j < pilaAuxiliar->count(); j++)
            {
                this->pilaAmbitos->append(pilaAuxiliar->value(j));
            }
            errorT * error = new errorT("Semantico", "No se ha encontrado la variable o atributo "+ nombre , 0,0);

            break;
        }else
        {
         this->desapilarMetodo();
        }
    }
    return simboloBuscado;
}




