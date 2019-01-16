#include "generadorcodigo.h"
#include <primerRecorrido.h>
#include <qdebug.h>
#include <codigo3d.h>
#include <operaciones.h>
#include <resultado.h>

extern primerRecorrido *recorrido1;
extern QList<nodo> * listaArboles;
extern Codigo3d *code;
extern QList<errorT> * listaErrores;

GeneradorCodigo::GeneradorCodigo()
{  
    this->pilaAmbitos = new QList<QString>();
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
                generarCodigoClase(hijo);
                break;
            case CONSTRUCTOR_:
                generarConstructor(hijo);
                break;
            case DECLATRIB_:
                crearAtributo(hijo);
                break;
            case PARAMETROS_:
                crearParametros(hijo);
                break;
            case FUNCION_:
                generarConstructor(hijo);
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
            case 99:
                //generarCodigoAsignacion(hijo);
                break;
        }
    }
}
void GeneradorCodigo::generarCodigoClase(nodo raizActual)
{    
    QString nombreClase = raizActual.valor.toLower();
    code->apilarMetodo(nombreClase);
    generarCodigo(raizActual.hijos.value(2)); //
    code->desapilarMetodo();
}




QString GeneradorCodigo:: obtenerIdMetodo(nodo raizActual)
{
    QString id = raizActual.valor.toLower();
    for(int i=0 ; i < raizActual.hijos.value(4).hijos.count() ; i++)
    {
        id += "$"+raizActual.hijos.value(4).hijos.value(i).tipo;
        if(raizActual.hijos.value(4).hijos.value(i).hijos.count()==1)
        {
            for(int j = 0 ; j < raizActual.hijos.value(4).hijos.value(i).hijos.value(0).hijos.count(); j++)
            {
                id += "[]";
            }
        }
    }
    return id;
}


void GeneradorCodigo::generarFuncion(nodo raizActual)
{
    QString nombreClase = raizActual.valor.toLower();
    Simbolo sim = code->getSimboloPorNombre("id");

    code->apilarMetodo(nombreClase);
    QList<Simbolo> listaAtributos = obtenerListaAtributos(nombreClase);
    QString idFuncion = obtenerIdMetodo(raizActual);
    code->cadena3d += "void " + idFuncion + "(){ // Constructor" + "\n" ;
    code->cadena3d += "h = h + " + QString::number(listaAtributos.count()) + "; // Reservar espacio en el heap para este objeto.\n" ;
    for(int i = 0; i < listaAtributos.count(); i++)
    {
        QString direccionInstancia = generarTemporal();
        QString direccionThis = generarTemporal();
        code->cadena3d += direccionThis + " = p + 0;  // Direccion este objeto en el heap\n";
        QString direccionHeap = generarTemporal();
        code->cadena3d += direccionHeap + " = stack[" + direccionThis +"];  // Direccion del objeto en el heap\n" ;
        Simbolo atributo = listaAtributos.value(i);
        if(atributo.raiz.hijos.count()==3) // Parametros no inicializados y de tipo no array.
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
                    QString direccionPuntero = generarTemporal();
                    code->cadena3d += direccionPuntero + " =  h ; // Dirección del puntero hacia la cadena \n";
                    code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+";// Puntero hacia la posición de la cadena.\n";
                    code->cadena3d += "heap[" + direccionAtributo + "] =  "+QString::number(code->NADA_)+" ; // Valor por defecto para cadenas\n" ;
                    break;
                }
                case TDECIMAL_:
                {
                    code->cadena3d += "heap[" + direccionAtributo + "] =  0.00 ; // Valor por defecto para decimales\n" ;
                    break;
                }
                case TOBJETO_:
                {
                    QString direccionPuntero = generarTemporal();
                    code->cadena3d += direccionPuntero + " =  h ; // Dirección del puntero hacia el objeto \n";
                    code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+";// Puntero hacia la posición del objeto.\n";
                    code->cadena3d += "heap[" + direccionAtributo + "] =  "+QString::number(code->NADA_)+" ; // Valor por defecto para cadenas\n" ;
                    //code->cadena3d += "heap[" + direccionAtributo + "] = "+QString::number(code->NADA_)+"  ; // Objeto nulo \n" ;
                    break;
                }
            }
        }
        else
                // Se han definido un valor de inicio. No son arrays y tampoco son llamadas metodos
                if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo!="dim") && (atributo.raiz.hijos.value(3).tipo!="acceso"))
                {
                    QString direccionAtributo = generarTemporal();
                    code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
                    Operaciones *operacion = new Operaciones();
                    nodo nodoRaiz = atributo.raiz.hijos.value(3);
                    Resultado *resultado = operacion->aritmetica(&nodoRaiz);

                    if(
                        atributo.tipo==resultado->tipo
                     ||(atributo.tipo == "entero" && resultado->tipo == "booleano")
                     ||(atributo.tipo == "entero" && resultado->tipo == "caracter")
                     ||(atributo.tipo == "decimal" && resultado->tipo == "entero")
                     )
                    {
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + resultado->valor +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else if(atributo.tipo =="entero" && resultado->tipo =="decimal")
                    {
                        // Hacer casteo implicito.
                        QString valorResiduo = generarTemporal();
                        code->cadena3d += valorResiduo + " = "+resultado->valor + " %  1 ; // Residuo: double % 1 \n";
                        QString valorCasteado = generarTemporal();
                        code->cadena3d += valorCasteado + " = " + resultado->valor + " - " + valorResiduo +";// Valor - residuo = entero \n";
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + valorCasteado +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else if(atributo.tipo == "booleano"  && resultado->tipo =="entero")
                    {
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + resultado->valor +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else if(atributo.tipo == "booleano"  && resultado->tipo =="decimal")
                    {
                        QString valorResiduo = generarTemporal();
                        code->cadena3d += valorResiduo + " = "+resultado->valor + " %  1 ; // Residuo: double % 1 \n";
                        QString valorCasteado = generarTemporal();
                        code->cadena3d += valorCasteado + " = " + resultado->valor + " - " + valorResiduo +";// Valor - residuo = entero \n";
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + resultado->valor +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else
                    {
                        errorT *error = new errorT("Semantico","No se puede asignar un valor " + resultado->tipo + " a una variable de tipo "+ atributo.nombre,
                                                   atributo.linea, atributo.columna);
                        listaErrores->append(*error);
                    }
                }else
                /*Declaracion de arrays. sin asignación*/
                if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo=="dim"))
                {
                    QString direccionAtributo = generarTemporal();
                    code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
                    code->cadena3d += "heap["+direccionAtributo+"] = h; // Asigna el puntero hacia el heap\n";
                    QString temporalTamano = generarTemporal();
                    code->cadena3d += temporalTamano +" = 1 ; // Tamano inicial del arreglo\n";
                    for(int j = 0 ; j<atributo.raiz.hijos.value(3).hijos.count(); j++)
                    {
                        Operaciones *operacion = new Operaciones();
                        nodo nodoRaiz = atributo.raiz.hijos.value(3).hijos.value(j);
                        Resultado *resultado = operacion->aritmetica(&nodoRaiz);
                        /*Comprobamos el tipo del resultado*/
                        QString valorDimensionProvisional = generarTemporal();
                        code->cadena3d += valorDimensionProvisional + " = " + resultado->valor + " ; //\n";
                        switch (resultado->tipo_)
                        {
                            case TENTERO_:
                            case TBOOLEANO_:
                            case TDECIMAL_ :
                            case TCARACTER_:
                                //code->cadena3d += generarEtiqueta() + ": \n";
                                QString temporalDecimal = generarTemporal();
                                code->cadena3d += temporalDecimal + " = " + valorDimensionProvisional + " % 1 ; // Obtenemos la parte decimal\n";
                                QString temporalEntero = generarTemporal();
                                code->cadena3d += temporalEntero + " = " + valorDimensionProvisional  + "-" + temporalDecimal + "; // Casteo Implicito.\n";
                                QString etqTamano = generarTemporal();
                                code->cadena3d += etqTamano + " = " +  temporalTamano +" * " +temporalEntero +";// Se actualiza el tamaño total del array\n" ;
                                temporalTamano = etqTamano;
                            break;
                        }
                    }
                    code->cadena3d += "h = h + " + temporalTamano + "; // Reservamos el tamaño del array en el heap.\n" ;
                }else
                // Declaración con instanción de un objeto como atributo
                if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo=="acceso") )
                {
                    // Comprobamos si se está llamando a un constructor
                    if(atributo.raiz.hijos.value(3).hijos.value(0).tipo=="constructor")
                    {
                        QString direccionAtributo = generarTemporal();
                        code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
                        code->cadena3d += "heap["+direccionAtributo+"] = h; // Asigna el puntero hacia el heap\n";
                        /*Pasamos cada uno de los parametros*/
                        int tamanoAmbitoActual = code->getTamanoAmbitoActual();
                        int numeroParametros = atributo.raiz.hijos.value(3).hijos.value(0).hijos.value(1).hijos.count();
                        QString nombreMetodoALlamar = atributo.raiz.hijos.value(3).hijos.value(0).hijos.value(0).valor;
                        QString idMetodoALlamar = nombreMetodoALlamar;
                        for(int i = 0; i< numeroParametros;i++)// Generamos el valor ímplicito de cada uno de los parametros.
                        {
                            QString temporalVirtual = generarTemporal();
                            code->cadena3d += temporalVirtual + " =  p  + " +QString::number(tamanoAmbitoActual) +"; // Simulación de cambio de ambito\n";
                            QString direccionAtributoHeap = generarTemporal();
                            code->cadena3d += direccionAtributoHeap + " =  "+temporalVirtual+"+ "+QString::number(i+2)+"; //Dirección del parametro "+QString::number(i)+"\n";
                            Operaciones * operacion = new Operaciones();
                            Resultado *resultado = new Resultado();
                            nodo nodoParametro = atributo.raiz.hijos.value(3).hijos.value(0).hijos.value(1).hijos.value(i);
                            nodo *ptr = &nodoParametro;
                            resultado = operacion->aritmetica(ptr);
                            QString temporalDireccion = generarTemporal();
                            code->cadena3d += "stack["+direccionAtributoHeap+"] = "+resultado->valor+"  ; // Asignación del puntero a la nueva instancia.\n";
                            idMetodoALlamar += "$"+resultado->tipo;
                        }
                        code->cadena3d += "p = p + " +QString::number(tamanoAmbitoActual) +"; // Cambio de ambito\n";
                        /*Verificamos que exista el metodo*/
                        int existe = existeMetodo(idMetodoALlamar);

                        if(existe)
                        {
                         code->cadena3d += idMetodoALlamar+"(); // Llamamos la metodo \n";
                        }
                        else
                        {
                            QList<Simbolo> listaPosiblesFunciones = getListaConstructores(nombreMetodoALlamar);
                            for(int i =0 ; i < listaPosiblesFunciones.count();i++)
                            {
                                QStringList lista1 = listaPosiblesFunciones.value(i).id.split("$");
                                QStringList lista2 = idMetodoALlamar.split("$");
                                if(lista1.count() == lista2.count())
                                {
                                    existe = 1;
                                }
                            }
                            if(!existe)
                            {
                                errorT * error = new errorT("Semantico","No se ha encontrado a la función " + idMetodoALlamar + "().",atributo.linea, atributo.columna);
                                listaErrores->append(*error);
                            }
                        }
                        code->cadena3d += "p = p - " +QString::number(tamanoAmbitoActual) +"; // Retomamos el ambito\n";
                    }

                }
    }//--Fin de inicilización de atributos
    // Recorrido y generación de código de las instrucciones
    generarCodigo(raizActual.hijos.value(5));
    code->cadena3d += "} // Fin Constructor\n" ;
    code->desapilarMetodo();// Desapilamos El ambito
}

void GeneradorCodigo::generarConstructor(nodo raizActual)
{       
    QString nombreClase = raizActual.valor.toLower();
    Simbolo sim = code->getSimboloPorNombre("id");

    code->apilarMetodo(nombreClase);
    QList<Simbolo> listaAtributos = obtenerListaAtributos(nombreClase);
    QString idFuncion = obtenerIdMetodo(raizActual);
    code->cadena3d += "\nvoid " + idFuncion + "(){ // Constructor" + "\n" ;
    code->cadena3d += "h = h + " + QString::number(listaAtributos.count()) + "; // Reservar espacio en el heap para este objeto.\n" ;
    for(int i = 0; i < listaAtributos.count(); i++)
    {
        QString direccionInstancia = generarTemporal();
        QString direccionThis = generarTemporal();
        code->cadena3d += direccionThis + " = p + 0;  // Direccion este objeto en el heap\n";
        QString direccionHeap = generarTemporal();
        code->cadena3d += direccionHeap + " = stack[" + direccionThis +"];  // Direccion del objeto en el heap\n" ;
        Simbolo atributo = listaAtributos.value(i);
        if(atributo.raiz.hijos.count()==3) // Parametros no inicializados y de tipo no array.
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
                    QString direccionPuntero = generarTemporal();
                    code->cadena3d += direccionPuntero + " =  h ; // Dirección del puntero hacia la cadena \n";
                    code->cadena3d += "h  = h + 1 ; // Se reserva espacio para el puntero \n";
                    code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+";// Puntero hacia la posición de la cadena.\n";
                    code->cadena3d += "heap[" + direccionPuntero + "] =  "+QString::number(code->NADA_)+" ; // Valor por defecto para cadenas\n" ;
                    break;
                }
                case TDECIMAL_:
                {
                    code->cadena3d += "heap[" + direccionAtributo + "] =  0.00 ; // Valor por defecto para decimales\n" ;
                    break;
                }
                case TOBJETO_:
                {
                    QString direccionPuntero = generarTemporal();
                    code->cadena3d += direccionPuntero + " =  h ; // Dirección del puntero hacia el objeto \n";
                    code->cadena3d += "h  = h + 1 ; // Se reserva espacio para el puntero \n";
                    code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+";// Puntero hacia la posición del objeto.\n";
                    code->cadena3d += "heap[" + direccionPuntero + "] =  "+QString::number(code->NADA_)+" ; // Valor por defecto para cadenas\n" ;
                    break;
                }
            }
        }
        else
                // Se han definido un valor de inicio. No son arrays y tampoco son llamadas metodos
                if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo!="dim") && (atributo.raiz.hijos.value(3).tipo!="acceso"))
                {
                    QString direccionAtributo = generarTemporal();
                    code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
                    Operaciones *operacion = new Operaciones();
                    nodo nodoRaiz = atributo.raiz.hijos.value(3);
                    Resultado *resultado = operacion->aritmetica(&nodoRaiz);

                    if
                     (
                        atributo.tipo==resultado->tipo
                     ||(atributo.tipo == "entero" && resultado->tipo == "booleano")
                     ||(atributo.tipo == "entero" && resultado->tipo == "caracter")
                     ||(atributo.tipo == "decimal" && resultado->tipo == "entero")
                     )
                    {
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + resultado->valor +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else if(atributo.tipo =="entero" && resultado->tipo =="decimal")
                    {
                        // Hacer casteo implicito.
                        QString valorResiduo = generarTemporal();
                        code->cadena3d += valorResiduo + " = "+resultado->valor + " %  1 ; // Residuo: double % 1 \n";
                        QString valorCasteado = generarTemporal();
                        code->cadena3d += valorCasteado + " = " + resultado->valor + " - " + valorResiduo +";// Valor - residuo = entero \n";
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + valorCasteado +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else if(atributo.tipo == "booleano"  && resultado->tipo =="entero")
                    {
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + resultado->valor +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else if(atributo.tipo == "booleano"  && resultado->tipo =="decimal")
                    {
                        QString valorResiduo = generarTemporal();
                        code->cadena3d += valorResiduo + " = "+resultado->valor + " %  1 ; // Residuo: double % 1 \n";
                        QString valorCasteado = generarTemporal();
                        code->cadena3d += valorCasteado + " = " + resultado->valor + " - " + valorResiduo +";// Valor - residuo = entero \n";
                        code->cadena3d += "heap["+ direccionAtributo+ "] = " + resultado->valor +"; //Asignando valor inicial variable "+atributo.nombre+"\n";
                    }
                    else if(resultado->tipo=="nada")
                    {
                        QString direccionPuntero = generarTemporal();
                        code->cadena3d += direccionPuntero + " =  h ; // Dirección del puntero hacia el objeto \n";
                        code->cadena3d += "h  = h + 1 ; // Se reserva espacio para el puntero \n";
                        code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+";// Puntero hacia la posición del objeto.\n";
                        code->cadena3d += "heap[" + direccionPuntero + "] =  "+QString::number(code->NADA_)+" ; // Valor por defecto para cadenas\n" ;
                    }
                    else if(atributo.tipo == resultado->tipo)
                    {
                        QString direccionPuntero = generarTemporal();
                        code->cadena3d += direccionPuntero + " =  h ; // Dirección del puntero hacia el objeto \n";
                        code->cadena3d += "h  = h + 1 ; // Se reserva espacio para el puntero \n";
                        code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+";// Puntero hacia la posición del objeto.\n";
                        code->cadena3d += "heap[" + direccionPuntero + "] =  "+resultado->valor+" ; // Valor por defecto para cadenas\n" ;
                    }
                    else
                    {
                        errorT *error = new errorT("Semantico","No se puede asignar un valor " + resultado->tipo + " a una variable de tipo "+ atributo.nombre,
                                                   atributo.linea, atributo.columna);
                        listaErrores->append(*error);
                    }
                }
                else
                /*Declaracion de arrays. sin asignación*/
                if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo=="dim"))
                {
                    QString direccionAtributo = generarTemporal();
                    QString direccionPuntero = generarTemporal();
                    code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
                    code->cadena3d += "heap["+direccionAtributo+"] = h; // Asigna el puntero hacia el heap\n";
                    code->cadena3d += "h = h + 1; // Se reserva espacio en el heap para el puntero.\n";
                    code->cadena3d += "heap["+direccionPuntero+"] = "+direccionAtributo+"; // Puntero hacia el valor del objeto.\n";
                    QString temporalTamano = generarTemporal();
                    code->cadena3d += temporalTamano +" = 1 ; // Tamano inicial del arreglo\n";
                    for(int j = 0 ; j<atributo.raiz.hijos.value(3).hijos.count(); j++)
                    {
                        Operaciones *operacion = new Operaciones();
                        nodo nodoRaiz = atributo.raiz.hijos.value(3).hijos.value(j);
                        Resultado *resultado = operacion->aritmetica(&nodoRaiz);
                        /*Comprobamos el tipo del resultado*/
                        QString valorDimensionProvisional = generarTemporal();
                        code->cadena3d += valorDimensionProvisional + " = " + resultado->valor + " ; //\n";
                        switch (resultado->tipo_)
                        {
                            case TENTERO_:
                            case TBOOLEANO_:
                            case TDECIMAL_ :                                                        
                            {                                
                                QString temporalDecimal = generarTemporal();
                                code->cadena3d += temporalDecimal + " = " + valorDimensionProvisional + " % 1 ; // Obtenemos la parte decimal\n";
                                QString temporalEntero = generarTemporal();
                                code->cadena3d += temporalEntero + " = " + valorDimensionProvisional  + "-" + temporalDecimal + "; // Casteo Implicito.\n";
                                QString etqTamano = generarTemporal();
                                code->cadena3d += etqTamano + " = " +  temporalTamano +" * " +temporalEntero +";// Se actualiza el tamaño total del array\n" ;
                                temporalTamano = etqTamano;
                                break;
                            }
                            case TCARACTER_:
                            {

                            }
                            default: // Error
                            {
                                errorT * error = new errorT("Semantico","Se esperaba un número númerico para definir el tamaño de la dimensión."
                                                            ,atributo.linea, atributo.columna);
                                listaErrores->append(*error);
                            }
                        }
                    }
                    /*Ponemos los valores por defeto*/
                    QString etiquetaCiclo = generarEtiqueta();
                    QString etiquetaFinCiclo = generarEtiqueta();
                    QString etiquetaSetear = generarEtiqueta();
                    QString temporalContador = generarTemporal();
                    code->cadena3d += temporalContador +" = 0 ; // Inicio del contador\n";
                    code->cadena3d += etiquetaCiclo +": // Ciclo de llenado de array.\n";
                    code->cadena3d += "if("+temporalTamano+"<"+temporalTamano+") goto " + etiquetaSetear + "; // \n";
                    code->cadena3d += "goto " + etiquetaFinCiclo + "; \n";
                    code->cadena3d += "";



                    code->cadena3d += "h = h + " + temporalTamano + "; // Reservamos el tamaño del array en el heap.\n" ;
                }
                else
                // Declaración con instanción de un objeto como atributo con instanciación
                if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo=="acceso") )
                {
                    // Recorremos cada una de las llamadas a acceso
                    for(int indice = 0; indice < atributo.raiz.hijos.value(3).hijos.count(); indice++ )
                    {
                        switch (atributo.raiz.hijos.value(3).hijos.value(indice).tipo_)
                        {
                            case CONSTRUCTOR_:
                            {
                                generarCodigoLlamadaAConstructor(direccionHeap, indice,atributo);
                            }
                            default:
                            {

                                QString direccionAtributo = generarTemporal();
                                code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(indice) +"; // Direccion del atributo " + atributo.nombre +"\n";
                                code->cadena3d += "heap["+direccionAtributo+"] = h; // Asigna el puntero hacia el heap\n";
                                /*Generar código de operación*/
                                Operaciones * operacion = new Operaciones();
                                nodo nodo = atributo.raiz.hijos.value(3);
                                Resultado *resultado = operacion->aritmetica(&nodo);
                                generarCodigoAcceso(direccionHeap, indice,atributo);
                            }
                        }
                    }
                }
    }
    code->cadena3d += "} // Fin Constructor\n" ;
    code->desapilarMetodo();// Desapilamos El ambito    
}


void GeneradorCodigo:: generarCodigoAcceso(QString direccionHeap, int indiceAcceso, Simbolo atributo)
{
    QString direccionAtributo = generarTemporal();
    code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(indiceAcceso) +"; // Direccion del atributo " + atributo.nombre +"\n";
    code->cadena3d += "heap["+direccionAtributo+"] = h; // Asigna el puntero hacia el heap\n";
    /*Pasamos cada uno de los parametros*/
    code->cadena3d += generarTemporal() + "= p + "+QString::number(indiceAcceso)+"; \n";
}


void GeneradorCodigo:: generarCodigoLlamadaAConstructor(QString direccionHeap, int indiceAcceso, Simbolo atributo)
{
    QString direccionAtributo = generarTemporal();
    code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(indiceAcceso) +"; // Direccion del atributo " + atributo.nombre +"\n";
    code->cadena3d += "heap["+direccionAtributo+"] = h; // Asigna el puntero hacia el heap\n";
    /*Pasamos cada uno de los parametros*/
    int tamanoAmbitoActual = code->getTamanoAmbitoActual();
    int numeroParametros = atributo.raiz.hijos.value(3).hijos.value(indiceAcceso).hijos.value(1).hijos.count();
    QString nombreMetodoALlamar = atributo.raiz.hijos.value(3).hijos.value(indiceAcceso).hijos.value(0).valor;
    QString idMetodoALlamar = nombreMetodoALlamar;
    for(int i = 0; i< numeroParametros;i++)// Generamos el valor ímplicito de cada uno de los parametros.
    {
        QString temporalVirtual = generarTemporal();
        code->cadena3d += temporalVirtual + " =  p  + " +QString::number(tamanoAmbitoActual) +"; // Simulación de cambio de ambito\n";
        QString direccionAtributoHeap = generarTemporal();
        code->cadena3d += direccionAtributoHeap + " =  "+temporalVirtual+"+ "+QString::number(i+2)+"; //Dirección del parametro "+QString::number(i)+"\n";
        Operaciones * operacion = new Operaciones();
        Resultado *resultado = new Resultado();
        nodo nodoParametro = atributo.raiz.hijos.value(3).hijos.value(indiceAcceso).hijos.value(1).hijos.value(i);
        nodo *ptr = &nodoParametro;
        resultado = operacion->aritmetica(ptr);
        QString temporalDireccion = generarTemporal();
        code->cadena3d += "stack["+direccionAtributoHeap+"] = "+resultado->valor+"  ; // Asignación del puntero a la nueva instancia.\n";
        idMetodoALlamar += "$"+resultado->tipo;
    }
    idMetodoALlamar.replace("cadena","caracter[]");
    code->cadena3d += "p = p + " +QString::number(tamanoAmbitoActual) +"; // Cambio de ambito\n";
    /*Verificamos que exista el metodo*/
    int existe = existeConstructor(idMetodoALlamar);
    if(existe)
    {
     code->cadena3d += idMetodoALlamar+"(); // Llamamos la metodo \n";
    }
    else
    {
        QList<Simbolo> listaPosiblesFunciones = getListaConstructores(nombreMetodoALlamar);
        for(int i =0 ; i < listaPosiblesFunciones.count();i++)
        {
            int flag = 0;
            QStringList lista1 = idMetodoALlamar.split("$");
            QStringList lista2 = listaPosiblesFunciones.value(i).id.split("$");
            if(lista1.count() == lista2.count())
            {
                for(int idim = 0; idim<lista1.count(); idim++)
                {
                    QStringList dimensiones1 = lista1.value(idim).split("[]");
                    QStringList dimensiones2 = lista2.value(idim).split("[]");
                    if(dimensiones1.count()==dimensiones2.count())
                    {
                        if(dimensiones1.value(0) == "caracter")
                        {
                            if(dimensiones2.value(0) == "caracter")
                            {
                                flag = 1;
                            }
                            else
                            {
                                flag = 0;
                            }
                        }else
                        if
                        (
                            dimensiones1.value(0)=="entero"||
                            dimensiones1.value(0)=="caracter"||
                            dimensiones1.value(0)=="decimal"||
                            dimensiones1.value(0)=="booleano"
                        )
                        {
                            if(
                               dimensiones2.value(0)=="entero"||
                               dimensiones2.value(0)=="caracter"||
                               dimensiones2.value(0)=="decimal"||
                               dimensiones2.value(0)=="booleano"
                               )
                            {
                                flag = 1;
                            }
                            else
                            {
                                flag = 0;
                            }
                        }
                        else
                        {
                            if(dimensiones1.value(0) == dimensiones2.value(0))
                            {
                                flag = 1;
                            }
                            else
                            {
                                flag  = 0;
                            }

                        }
                    }
                    else
                    {
                        flag =0;
                    }
                }
                if(flag) // Es la funcion que buscabamos
                {
                    idMetodoALlamar = listaPosiblesFunciones.value(i).id;
                    existe = 1;
                    break;
                }
            }
            qDebug()<<"Buscadon";
        }
        if(!existe)
        {
            errorT * error = new errorT("Semantico","No se ha encontrado a la función " + idMetodoALlamar + "().",atributo.linea, atributo.columna);
            listaErrores->append(*error);
        }
        else// Encontrasmo la función
        {
            code->cadena3d += idMetodoALlamar + "(); // LLamamos al constructor. \n";
        }
    }
    code->cadena3d += "p = p - " +QString::number(tamanoAmbitoActual) +"; // Retomamos el ambito\n";
}



QList<Simbolo> GeneradorCodigo :: getListaConstructores(QString nombreFuncion)
{
    QList<Simbolo> *listaFunciones = new QList<Simbolo>();       
    tablaSimbolos *tablaActual = recorrido1->tabla;
    QString ambitoBuscado = "global$"+nombreFuncion;
    for(int i = 0 ; i < tablaActual->listaSimbolos->count(); i++)
    {
        Simbolo simbolo = tablaActual->listaSimbolos->value(i);
        if
        (
         //simbolo.nombre == nombreFuncion &&
         simbolo.ambito == ambitoBuscado &&
         simbolo.rol == "constructor"
        )
        {
            listaFunciones->append(simbolo);
        }
    }    
    return  *listaFunciones;
}





QList<Simbolo> GeneradorCodigo::obtenerListaAtributos(QString nombreClase)
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

Simbolo GeneradorCodigo::getClase(QString nombre)
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

Simbolo GeneradorCodigo::getMetodo(QString idMetodo)
{
    Simbolo simb;
    getAmbitoActual();
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(
           idMetodo == recorrido1->tabla->listaSimbolos->value(i).id &&
           recorrido1->tabla->listaSimbolos->value(i).ambito == ambitoActual   &&
            (
                    recorrido1->tabla->listaSimbolos->value(i).rol == "metodo" ||
                    recorrido1->tabla->listaSimbolos->value(i).rol == "funcion" ||
                    recorrido1->tabla->listaSimbolos->value(i).rol == "constructor"
            )
           )
        {
            simb = recorrido1->tabla->listaSimbolos->value(i);
        }
    }
    return simb;
}

int GeneradorCodigo:: existeMetodo(QString idMetodo)
{
    QString ambitoActual = code->getAmbitoActual();
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(
           idMetodo == recorrido1->tabla->listaSimbolos->value(i).id &&
           recorrido1->tabla->listaSimbolos->value(i).ambito == ambitoActual   &&
            (
                    recorrido1->tabla->listaSimbolos->value(i).rol == "metodo" ||
                    recorrido1->tabla->listaSimbolos->value(i).rol == "funcion" ||
                    recorrido1->tabla->listaSimbolos->value(i).rol == "constructor"
            )
           )
        {
            return 1;
        }
    }
    return 0;
}

int GeneradorCodigo:: existeConstructor(QString id)
{
    for(int i = 0 ; i< recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(recorrido1->tabla->listaSimbolos->value(i).id == id)
        {
            return 1;
        }
    }
    return 0;
}

/*
int GeneradorCodigo:: existeMetodo(QString idMetodo)
{
    int resultado = 0;
    QString ambitoActual = code->getAmbitoActual();
    for(int i = 0; i <recorrido1->tabla->listaSimbolos->count(); i++)
    {
        if(
           recorrido1->tabla->listaSimbolos->value(i).id == idMetodo &&
           recorrido1->tabla->listaSimbolos->value(i).ambito == ambitoActual
          )
        {
            return 1;
        }
    }
    return 0;
}
*/


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


void GeneradorCodigo:: crearAtributo(nodo raizActual)
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
