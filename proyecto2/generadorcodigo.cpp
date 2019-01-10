#include "generadorcodigo.h"
#include <primerRecorrido.h>
#include <qdebug.h>
#include <codigo3d.h>
extern primerRecorrido *recorrido1;
extern QList<nodo> * listaArboles;
extern Codigo3d *code;

GeneradorCodigo::GeneradorCodigo()
{  
}

void GeneradorCodigo:: Init()
{
    for(int i = 0; i < listaArboles->count(); i++)
    {
        generarCodigo(listaArboles->value(i));
    }
}

void GeneradorCodigo:: generarCodigo(nodo raiz)
{

    for(int i = 0 ; i < raiz.hijos.count(); i++)
    {
        nodo hijo = raiz.hijos[i];
        switch (hijo.tipo_)
        {
            case CLASE_:                
                crearClase(hijo);
                break;
            case DECLATRIB_:
                crearVariable(hijo);
                break;
            case CONSTRUCTOR_:
                crearConstructor(hijo);
                break;
            case PARAMETROS_:
                crearParametros(hijo);
                break;
            case FUNCION_:
                crearFuncion(hijo);
                break;
            case SENTENCIAS_:
                generarCodigo(hijo);
                break;
            case D_:
            case DA_:
                declararVariable(hijo);
                break;
            case DARAR_:
            case DAR_:
                declararArreglo(hijo);
                break;
            case SI_:
            case SINOSI_:
                declararSi(hijo);
                break;
            case MIENTRAS_:
                declararMientras(hijo);
                break;
            case HACER_:
                declararHacer(hijo);
                break;
            case SELECCIONA_:
                declararSeleccionar(hijo);
                break;
            case PARA_:
                declararPara(hijo);
                break;
        }
    }

}


void GeneradorCodigo::crearClase(nodo raizActual)
{    
    /*Verificamos que exista un constructor constructor() si no se crea uno.*/
    QString nombrClase = raizActual.valor.toLower();
    int existeConstr = existeConstructor(nombrClase);
    if(existeConstr == 0) // Si no existe, nos creamos una.
    {
        QList<Simbolo> listaAtributos = obtenerListaAtributos(nombrClase);
        code->cadena3d += "void " + nombrClase + "(){ // Constructor" + "\n" ;
        QString direccionThis = generarTemporal();
        code->cadena3d += direccionThis + " = p + 0;  // Direccion este"+"\n";
        QString direccionHeap = generarTemporal();
        code->cadena3d += direccionHeap + " = heap[" + direccionThis +"];  // Direccion del objeto en el heap\n" ;
        for(int i = 0; i < listaAtributos.count(); i++)
        {
            Simbolo atributo = listaAtributos.value(i);
            if(atributo.raiz.hijos.count()==3) // No se ha definido valor por el usuario y no son array
            {
                QString direccionAtributo = generarTemporal();
                code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
                switch (atributo.raiz.hijos.value(1).tipo_)
                {
                    case TENTERO_:
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] =  0 ; // Valor por defecto para enteros" +"\n";
                        break;
                    }
                    case TCARACTER_ :
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] =  0 ; // Valor por defecto para caracter\n" ;
                        break;
                    }
                    case TBOOLEANO_ :
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] = 0 ; // Valor por defecto para booleano\n" ;
                        break;
                    }
                    case TCADENA_:
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] =  66666666666666666666 ; // Valor por defecto para cadenas\n" ;
                        break;
                    }
                    case TDECIMAL_:
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] =  0.00 ; // Valor por defecto para decimales\n" ;
                        break;
                    }
                    case TOBJETO_:
                    {
                        QString direcionObjeto  = generarTemporal();
                        code->cadena3d += direcionObjeto +" = " + direccionHeap + "+" + QString::number(listaAtributos.count()) + ";//Direccion del objeto "+atributo.tipo+" en h\n";
                        code->cadena3d += "heap[" + direccionAtributo + "] = "+direcionObjeto+"  ; // Dirección objeto en el heap \n" ;
                        break;
                    }
                }
            }
            if(atributo.raiz.hijos.count()==4) // No se ha definido valor por el usuario y no son array+
            {
                QString direccionAtributo = generarTemporal();
                code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
                switch (atributo.raiz.hijos.value(1).tipo_)
                {
                    case TENTERO_:
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] =  0 ; // Valor por defecto para enteros" +"\n";
                        break;
                    }
                    case TCARACTER_ :
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] =  0 ; // Valor por defecto para caracter" ;
                        break;
                    }
                    case TBOOLEANO_ :
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] = 0 ; // Valor por defecto para booleano" ;
                        break;
                    }
                    case TCADENA_:
                    {
                        code->cadena3d += "heap[" + direccionAtributo + "] =  66666666666666666666 ; // Valor por defecto para cadenas" ;
                        break;
                    }
                    case TOBJETO_:
                    {
                        QString direcionObjeto  = generarTemporal();
                        code->cadena3d += direcionObjeto +" = " + direccionHeap + "+" + QString::number(listaAtributos.count()) + "Direccion para la siguiente instancia.";
                        code->cadena3d += "heap[" + direccionAtributo + "] = "+direcionObjeto+"  ; // Valor por defecto para cadenas" ;
                        break;
                    }
                }
            }
        }
        code->cadena3d += " } // Fin Constructor\n" ;
    }
}

QList<Simbolo> GeneradorCodigo::obtenerListaAtributos(QString nombreClase)
{
    QList<Simbolo> *listaAtributos = new QList<Simbolo>();
    QString claseActual = nombreClase; //
    tablaSimbolos *tablaActual = recorrido1->tabla;
    while(claseActual!="nada")
    {        
        Simbolo clase = getClase(claseActual);
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
                listaAtributos->append(tablaActual->listaSimbolos->value(i));
            }
        }
        claseActual = clase.padre; // Obtenemos el nombre del padre.
    }
    return  *listaAtributos;
}

Simbolo GeneradorCodigo::getClase(QString nombre)
{
    Simbolo simb;
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(nombre== recorrido1->tabla->listaSimbolos->value(i).nombre &&
           recorrido1->tabla->listaSimbolos->value(i).ambito == "global")
        {
            return recorrido1->tabla->listaSimbolos->value(i);
        }
    }
    return simb;
}

void GeneradorCodigo:: getAmbitoActual()
{
    ambitoActual = "";
    for(int i = 0 ; i< this->pilaAmbitos->count(); i++)
    {
        if(i==0)
        {
            ambitoActual = this->pilaAmbitos->value(i);
        }
        else
        {
            ambitoActual = ambitoActual + "$" + this->pilaAmbitos->value(i);
        }
    }
}

QString GeneradorCodigo:: getClaseActual()
{
    return this->pilaAmbitos->value(this->pilaAmbitos->count()-1);
}



void GeneradorCodigo:: crearFuncion(nodo raizActual)
{


}

void GeneradorCodigo:: crearConstructor(nodo raizActual)
{

}


void GeneradorCodigo:: declararSi(nodo raizActual)
{

}


void GeneradorCodigo:: declararSeleccionar(nodo raizActual)
{

}


void GeneradorCodigo:: declararHacer(nodo raizActual)
{

}

void GeneradorCodigo:: declararMientras(nodo raizActual)
{

}

void GeneradorCodigo:: declararPara(nodo raizActual)
{

}

void GeneradorCodigo:: crearParametros(nodo raizActual)
{

}

void GeneradorCodigo:: actualizarContadores(int tamano)
{
    contadorSimbolos+=tamano;
    contadorClase+=tamano;
    contadorFuncion+=tamano;
}


void GeneradorCodigo:: crearVariable(nodo raizActual)
{

}

void GeneradorCodigo:: declararArreglo(nodo raizActual) // Declaración sin valor
{

}

void GeneradorCodigo:: declararParametro(nodo raizActual) // Declaración sin valor
{

}

void GeneradorCodigo:: declararVariable(nodo raizActual) // Declaración sin valor
{

}



QString GeneradorCodigo::escapar(QString cadena)
{
    cadena = cadena.replace("\"", "");
    //cadena = cadena.replace("\"", "\\\"");
    return cadena;
}
QString GeneradorCodigo:: generarEtiqueta()
{
    return "L" + QString::number(code->etiqueta++);
}

QString GeneradorCodigo:: generarTemporal()
{
    return "t" + QString::number(code->temporal++);
}

int GeneradorCodigo::existeConstructor(QString nombreClase)
{
    Simbolo simb;
    for(int i = 0; i < recorrido1->tabla->listaSimbolos->count(); i++)
    {
        simb = recorrido1->tabla->listaSimbolos->value(i);
        if(simb.nombre == nombreClase && simb.id == nombreClase)
        {
            return 1;
        }
    }
    return 0;
}


Simbolo GeneradorCodigo::getConstructor(QString nombreClase)
{
    Simbolo simb;
    for(int i = 0; i < recorrido1->tabla->listaSimbolos->count(); i++)
    {
        simb = recorrido1->tabla->listaSimbolos->value(i);
        if(simb.nombre == nombreClase && simb.id == nombreClase)
        {
            return simb;
        }
    }
    return simb;
}
