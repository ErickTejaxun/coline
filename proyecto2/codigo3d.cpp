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

QString Codigo3d:: getClaseActual()
{
    return this->pilaAmbitos->value(1);
}

Simbolo Codigo3d::getClase(QString nombre)
{
    Simbolo simb;
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(nombre== recorrido1->tabla->listaSimbolos->value(i).nombre &&
           recorrido1->tabla->listaSimbolos->value(i).ambito == "global")
        {
            simb = recorrido1->tabla->listaSimbolos->value(i);
        }
    }
    return simb;
}

Simbolo Codigo3d::getAtributoClase(QString nombre,QString clase)
{
    QList<Simbolo> atributos=obtenerListaAtributos(clase);
    Simbolo s;
    for(int i=0;i<atributos.count();i++)
    {
        if(nombre==atributos[i].nombre)
        {
            return atributos[i];
        }
    }

    return s;

}


QList<Simbolo> Codigo3d::obtenerListaAtributos(QString nombreClase)
{
    QList<Simbolo> *listaAtributos = new QList<Simbolo>();
    QString claseActual = nombreClase; //
    tablaSimbolos *tablaActual = recorrido1->tabla;
    int linea = 0, columna = 0;
    while(claseActual!="nada" && claseActual!="")
    {
        if(tablaActual->existeClase(claseActual))
        {
            /*Buscamos la clase*/
            Simbolo clase = getClase(claseActual);
            linea = clase.linea;
            columna = clase.columna;
            QString ambitoBuscado = "global$"+claseActual;
            for(int i = 0 ; i < tablaActual->listaSimbolos->count(); i++)
            {
                Simbolo simbolo = tablaActual->listaSimbolos->value(i);
                if
                (
                  simbolo.rol == "variable" &&
                  simbolo.ambito == ambitoBuscado
                )
                {
                    int flag = 0;
                    for(int j = 0 ; j < listaAtributos->count(); j++)
                    {
                        if(listaAtributos->value(j).nombre == tablaActual->listaSimbolos->value(i).nombre)
                        {
                            flag =1;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        listaAtributos->append(tablaActual->listaSimbolos->value(i));
                    }
                    else
                    {
                        errorT *error = new errorT("Advertencia ", "El atributo " + simbolo.nombre + " de la clase "+ claseActual+" se ha refenido en la clase hija " + nombreClase
                                                   , simbolo.linea, simbolo.columna);
                        listaErrores->append(*error);
                    }
                }
            }
            claseActual = clase.padre; // Obtenemos el nombre del padre.
        }
        else
        {
            if( claseActual != "principal")
            {
                errorT * error = new errorT("Semantico","No existe la clase "+claseActual,linea, columna);
                listaErrores->append(*error);
            }
            break;
        }
    }
    return  *listaAtributos;
}


int Codigo3d::getIndiceAtributo(QString nombre,QString clase)
{
    QList<Simbolo> atributos=obtenerListaAtributos(clase);
    for(int i=0;i<atributos.count();i++)
    {
        if(nombre==atributos[i].nombre)
        {
            return i;
        }
    }

    return -1;
}


void Codigo3d::copiarPila(QList<QString> *actual,QList<QString> *nueva)
{
    for(int i=0;i<actual->count();i++)
    {
        nueva->append(actual->value(i));
    }
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


void Codigo3d:: apilarTamanoDimension(QString nombreVariable, QString temporal)
{
    Simbolo simbolo ;
    Simbolo simaux ;
    tablaSimbolos * tabla = recorrido1->tabla;
    QString ambito = getAmbitoActual();
    int linea = 0;
    int columna = 0;
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        simaux = recorrido1->tabla->listaSimbolos->value(i);
        if(
           simaux.nombre ==nombreVariable&&
           simaux.ambito == ambito)
        {
            simaux.listaDimensiones->append(temporal);
            recorrido1->tabla->listaSimbolos->replace(i, simaux);
            return;
        }
        if(simaux.ambito == ambito)
        {
            linea = simaux.linea;
            columna = simaux.columna;
        }
    }
    errorT * error = new errorT("Semantico", "No se ha encontrado la variable "+ nombreVariable + " en el ambito "+ambito
                                ,linea, columna);
    listaErrores->append(*error);
}




