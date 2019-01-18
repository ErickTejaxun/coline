#include "generadorcodigo.h"
#include <primerRecorrido.h>
#include <qdebug.h>
#include <codigo3d.h>
#include <operaciones.h>
#include <resultado.h>
#include <nativas3d.h>

enum Choice
{
    ID_ = 0 ,
    SENTENCIAS_ = 1,
    IMPRIMIR_ = 2,
    CONCATENAR_ =3,
    IMPORTAR_ = 4,
    PATH_ = 5,
    INSTRUCCIONES_ = 6,
    SOBRESCRIBIR_ = 7,
    DETENER_ =8,
    CONTINUAR_ = 9,
    MOSTRAREDD_ = 10,
    LEER_ = 11,
    PARA_ = 12,
    HACER_ = 13,
    MIENTRAS_ = 14,
    SELECCION_ = 15,
    SI_ = 16,
    SINOSI_ = 17,
    SELECCIONA_ = 18,
    CASO_ = 19,
    DEFECTO_ = 20,
    CASOS_  = 21,
    RETORNO_ = 22,
    DECLATRIB_ = 23,
    PUBLICO_ = 24,
    PRIVADO_ = 25,
    PROTEGIDO_ = 26,
    CONSTRUCTOR_ = 27,
    LPAR_ = 28,
    PARAMETROS_ = 29,
    PRINCIPAL_ = 30,
    FUNCION_ = 31,
    DIMS_ = 32,
    DIM_ = 33,
    CLASE_ = 34,
    HERENCIA_ = 35,
    VARIABLE_ = 36,
    ASIGA_ = 37,
    ASIG_ = 38,
    D_ = 38, // declaración
    DA_= 39, // declaración con asignacion.
    DAR_ = 40, // declaración array
    DARA_ = 41, // declaración array con asignación para cadenas
    LVALORES_ = 42, // Lista de valores funcion(1,3,4,arg5)
    VALORES_ = 43,
    DARAR_ = 44, //  darar declaracion array asignacion -- para arrays
    TBOOLEANO_ = 45,
    TENTERO_ = 46,
    TCARACTER_ = 47,
    TOBJETO_ = 48,
    SS_ = 49, //       expl?  valor1:valor2;
    EXPL_ = 50,
    EXPR_ = 51,
    EXPA_ = 52,
    CONVERTIRACADENA_ = 53,
    CONVERTIRAENTERO_ = 54,
    LLAMADA_ = 55,
    AUMENTO_ = 56,
    DECREMENTO_ = 57,
    IDV_ = 58,
    ACCESO_ =59,
    NADA_ = 60,
    SETENTENCIASG = 61, // Setnencias globales. Raiz del archivo
    SUMA_ = 62,
    RESTA_ = 63,
    MULTIPLICACION_ = 64,
    DIVISION_ = 65,
    MODULO_ = 66,
    POTENCIA_ = 67,
    MAYORQUE_ = 68,
    MENORQUE_ = 69,
    MENORIGUAL_ = 70,
    MAYORIGUAL_ = 71,
    IGUAL_ = 72,
    DESIGUAL_ = 73,
    AND_ = 74,
    OR_ = 75,
    NO_ = 76,
    TCADENA_ = 77,
    TNADA_ = 78,
    ACCESOARRAY_ = 79,
    TDECIMAL_ = 80,
    LACCESO_ = 81,
};


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
    Nativas3d *nativa = new Nativas3d();

    for(int i = 0; i < listaArboles->count(); i++)
    {
        generarCodigo(listaArboles->value(i));
    }
}

void GeneradorCodigo:: generarCodigo(nodo raiz)
{

    for(int i = 0 ; i < raiz.hijos.count(); i++)
    {
        nodo hijo = raiz.hijos.value(i);
        switch (hijo.tipo_)
        {
            case CLASE_:                
                generarCodigoClase(hijo);
                break;
            case CONSTRUCTOR_:
                generarConstructor(hijo);
                break;
            case DECLATRIB_:
                //crearAtributo(hijo);
                break;
            case PARAMETROS_:
                //crearParametros(hijo);
                break;
            case FUNCION_:
                generarFuncion(hijo);
                break;
            case SENTENCIAS_:
                generarCodigo(hijo);
                break;
            case D_:
                declararVariable(hijo);
                break;
            case DA_:
                declararVariableAsignacion(hijo);
                break;
            case DARA_:
            case DARAR_:
                 declararArregloAsignar(hijo);
                break;
            case DAR_:
                declararArreglo(hijo);
                break;
            case SI_:
            case SINOSI_:
                //declararSi(hijo);
                break;
            case MIENTRAS_:
                //declararMientras(hijo);
                break;
            case HACER_:
                //declararHacer(hijo);
                break;
            case SELECCIONA_:
                //declararSeleccionar(hijo);
                break;
            case PARA_:
                //declararPara(hijo);
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
    /*Primero ponemos valores por default a los atributos de la clase.*/
    QString nombreFuncion = raizActual.valor.toLower();
    //QList<Simbolo> listaAtributos = obtenerListaAtributos(nombreFuncion);
    QString idFuncion = obtenerIdMetodo(raizActual);
    code->cadena3d += "\nvoid " + idFuncion + "(){ // " + "\n" ;
    code->apilarMetodo(idFuncion);
    generarCodigo(raizActual);
    code->desapilarMetodo();
    code->cadena3d += "} // fin función "+nombreFuncion+"\n";
}

void GeneradorCodigo::generarConstructor(nodo raizActual)
{       
   /*Primero ponemos valores por default a los atributos de la clase.*/
    generarCodigoAtributos(raizActual);
   /*Ahora Generamos el código de las instrucciones*/
    QString nombreFuncion = raizActual.valor.toLower();
    QString idFuncion = obtenerIdMetodo(raizActual);
    code->apilarMetodo(idFuncion);
    generarCodigoInstrucciones(raizActual);
    code->desapilarMetodo();// Desapilamos El ambito
    code->cadena3d += "} // Fin Constructor\n" ;

}

void GeneradorCodigo::generarCodigoInstrucciones(nodo raizActual)
{
    QString nombreClase = raizActual.valor.toLower();          
    generarCodigo(raizActual);
}

void GeneradorCodigo:: generarCodigoAtributos(nodo raizActual)
{
    QString nombreClase = raizActual.valor.toLower();
    //Simbolo sim = code->getSimboloPorNombre("id");
    //code->apilarMetodo(nombreClase);
    QString idFuncion = obtenerIdMetodo(raizActual);
    code->cadena3d += "\nvoid " + idFuncion + "(){ // Constructor" + "\n" ;
    QList<Simbolo> listaAtributos = obtenerListaAtributos(nombreClase);

    code->cadena3d += "h = h + " + QString::number(listaAtributos.count()) + "; // Reservar espacio en el heap para este objeto.\n" ;
    for(int i = 0; i < listaAtributos.count(); i++)
    {
        QString direccionInstancia = generarTemporal();
        QString direccionThis = generarTemporal();
        QString direccionHeap = generarTemporal();
        code->cadena3d += direccionThis + " = p + 0;  // Direccion este objeto en el heap\n";
        code->cadena3d += direccionHeap + " = stack[" + direccionThis +"];  // Direccion del objeto en el heap\n" ;
        Simbolo atributo = listaAtributos.value(i);
        if(atributo.raiz.hijos.count()==3) // Parametros no inicializados y de tipo no array.-------------------------------------------------------------------------------------
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
                    code->cadena3d += "heap["+direccionAtributo+"] = "+QString::number(code->NADA_)+";// Puntero hacia la posición de la cadena.\n";
                    break;
                }
                case TDECIMAL_:
                {
                    code->cadena3d += "heap[" + direccionAtributo + "] =  0.00 ; // Valor por defecto para decimales\n" ;
                    break;
                }
                case TOBJETO_:
                {
                    code->cadena3d += "heap["+direccionAtributo+"] = "+QString::number(code->NADA_)+";// Puntero hacia la posición del objeto.\n";
                    break;
                }
            }
        }
        else
        // ATRIBUTO = EXPL-------------------------------------------------------------------------------------------------------------------------------------------------------------
        if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo!="dim") && (atributo.raiz.hijos.value(3).tipo!="acceso"))
        {
            QString direccionAtributo = generarTemporal();
            code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
            Operaciones *operacion = new Operaciones();
            nodo nodoRaiz = atributo.raiz.hijos.value(3);
            Resultado *resultado = operacion->logica(&nodoRaiz,0);
            QString etiquetaContinuar = generarEtiqueta();
            if(resultado->tipo_ ==TBOOLEANO_)
            {
                if
                (atributo.tipo == "entero"|| atributo.tipo == "decimal" || atributo.tipo == "booleano" || atributo.tipo == "caracter"
                )
                {
                    code->cadena3d += resultado->etiV + ": \n";
                    code->cadena3d += direccionAtributo + " =  1 ; // Verdadero \n";
                    code->cadena3d += "goto " + etiquetaContinuar + "; \n";

                    code->cadena3d += resultado->etiF + ": \n";
                    code->cadena3d += direccionAtributo + " =  0 ; // Falso \n";
                    code->cadena3d += "goto " + etiquetaContinuar + "; \n";
                    code->cadena3d += etiquetaContinuar +":\n";
                }
            }
            else
            if
             (
                atributo.tipo==resultado->tipo
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
        //Declaracion de arrays. sin asignación---------------------------------------------------------------------------------------------------------------------------------------------
        if((atributo.raiz.hijos.count()==4) && (atributo.raiz.hijos.value(3).tipo=="dim"))
        {
            QString direccionAtributo = generarTemporal();
            QString direccionPuntero = generarTemporal();
            QString inicioArray = generarTemporal();
            code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
            code->cadena3d += direccionPuntero  + " =  h ; //Direccion real del inicio del array. \n" ;
            code->cadena3d += "h = h + 1; // Se reserva espacio en el heap para el puntero.\n";
            code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+"; // Asigna el puntero hacia el heap\n";
            code->cadena3d += inicioArray + " = h; // Asigna el puntero hacia el inicio del array\n";
            code->cadena3d += "h = h + 1; // Se reserva espacio en el heap para el puntero.\n";
            code->cadena3d += "heap["+direccionPuntero+"] = "+inicioArray+"; // Puntero hacia el valor del objeto.\n";
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
                        QString temporalDecimal = generarTemporal();
                        code->cadena3d += temporalDecimal + " = " + valorDimensionProvisional + " % 1 ; // Obtenemos la parte decimal\n";
                        QString temporalEntero = generarTemporal();
                        code->cadena3d += temporalEntero + " = " + valorDimensionProvisional  + "-" + temporalDecimal + "; // Casteo Implicito.\n";
                        QString etqTamano = generarTemporal();
                        code->cadena3d += etqTamano + " = " +  temporalTamano +" * " +temporalEntero +";// Se actualiza el tamaño total del array\n" ;
                        temporalTamano = etqTamano;
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
            //if(atributo.tipo != "caracter")
            if(1)
            {
                QString etiquetaCiclo = generarEtiqueta();
                QString etiquetaFinCiclo = generarEtiqueta();
                QString etiquetaSetear = generarEtiqueta();
                QString temporalContador = generarTemporal();
                code->cadena3d += temporalContador +" = 0 ; // Inicio del contador\n";
                code->cadena3d += etiquetaCiclo +": // Ciclo de llenado de array.\n";
                code->cadena3d += "if("+temporalContador+"<"+temporalTamano+") goto " + etiquetaSetear + "; // \n";
                code->cadena3d += "goto " + etiquetaFinCiclo + "; \n";
                code->cadena3d += etiquetaSetear +":// Setear valores por defecto\n";
                QString posicionRelativa = generarTemporal();
                code->cadena3d += ""+posicionRelativa +" =  " +inicioArray+ " + " + temporalContador+ "; // Direción del indice actual\n";
                switch (atributo.raiz.hijos.value(1).tipo_)
                {
                    case TENTERO_:
                    case TBOOLEANO_:
                    case TDECIMAL_:
                    {
                        code->cadena3d +="heap["+posicionRelativa+"] = 0; //Valor por defecto\n";
                        break;
                    }
                    case TOBJETO_:
                    {
                        code->cadena3d +="heap["+posicionRelativa+"] ="+QString::number(code->NADA_) +"; //Valor por defecto NULL \n";
                        break;
                    }

                }
                code->cadena3d += ""+ temporalContador + " = " + temporalContador + " + 1; // Siguiente indice\n";
                code->cadena3d += "goto " + etiquetaCiclo + ";//Retorno a ciclo\n";
                code->cadena3d += ""+etiquetaFinCiclo +":// \n";
                //code->cadena3d += "h = h + " + temporalTamano + "; // Reservamos el tamaño del array en el heap.\n" ;
            }
            else
            {
                code->cadena3d += "heap[" + inicioArray+"] = "+QString::number(code->NADA_)+";// Apuntador NULL por defecto\n";
            }
        }
        else
        // Declaración con instanción de un objeto como atributo con instanciación------------------------------------------------------------------------------------------------------------------------
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
                    default: // Si es llamada a otra cosa.
                    {

                        QString direccionAtributo = generarTemporal();
                        code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(indice) +"; // Direccion del atributo " + atributo.nombre +"\n";
                        code->cadena3d += "heap["+direccionAtributo+"] = h; // Asigna el puntero hacia el heap\n";
                        /*Generar código de operación*/
                        Operaciones * operacion = new Operaciones();
                        nodo nodo = atributo.raiz.hijos.value(3);
                        Resultado *resultado = operacion->aritmetica(&nodo);
                        //generarCodigoAcceso(direccionHeap, indice,atributo);
                    }// Fin case default.
                }// Fin switch
            }// Fin for
        }// Fin if de caso de operación.
        else
        if(atributo.raiz.hijos.count()==5) // Arreglos con asignación----------------------------------------------------------
        {
            QString direccionAtributo = generarTemporal();
            QString direccionPuntero = generarTemporal();
            QString inicioArray = generarTemporal();
            code->cadena3d += direccionAtributo  +  " = " + direccionHeap + " + " + QString::number(i) +"; // Direccion del atributo " + atributo.nombre +"\n";
            code->cadena3d += direccionPuntero  + " =  h ; //Direccion real del inicio del array. \n" ;
            code->cadena3d += "h = h + 1; // Se reserva espacio en el heap para el puntero.\n";
            code->cadena3d += "heap["+direccionAtributo+"] = "+direccionPuntero+"; // Asigna el puntero hacia el heap\n";
            code->cadena3d += inicioArray + " = h; // Asigna el puntero hacia el inicio del array\n";
            code->cadena3d += "h = h + 1; // Se reserva espacio en el heap para el puntero.\n";
            code->cadena3d += "heap["+direccionPuntero+"] = "+inicioArray+"; // Puntero hacia el valor del objeto.\n";
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
                        QString temporalDecimal = generarTemporal();
                        code->cadena3d += temporalDecimal + " = " + valorDimensionProvisional + " % 1 ; // Obtenemos la parte decimal\n";
                        QString temporalEntero = generarTemporal();
                        code->cadena3d += temporalEntero + " = " + valorDimensionProvisional  + "-" + temporalDecimal + "; // Casteo Implicito.\n";
                        QString etqTamano = generarTemporal();
                        code->cadena3d += etqTamano + " = " +  temporalTamano +" * " +temporalEntero +";// Se actualiza el tamaño total del array\n" ;
                        temporalTamano = etqTamano;
                    }
                    default: // Error
                    {
                        errorT * error = new errorT("Semantico","Se esperaba un número númerico para definir el tamaño de la dimensión."
                                                    ,atributo.linea, atributo.columna);
                        listaErrores->append(*error);
                    }
                }
            }
            if(atributo.raiz.hijos.value(4).tipo != "lvalores")
            {
                Operaciones *operacion =  new Operaciones();
                Resultado *resultado = new Resultado();
                nodo nodoAOperar = atributo.raiz.hijos.value(4);
                nodo *ptr =  &nodoAOperar;
                resultado = operacion->logica(ptr,0);
                /*Comprobación de tipos.*/
                if(atributo.tipo  == "caracter" && resultado->tipo == "caracter"||
                   atributo.tipo  == "caracter" && resultado->tipo == "entero"||
                   atributo.tipo  == "caracter" && resultado->tipo == "decimal")
                {
                    code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
                }
                if(atributo.tipo  == "entero" && resultado->tipo == "caracter"||
                   atributo.tipo  == "entero" && resultado->tipo == "entero"||
                   atributo.tipo  == "entero" && resultado->tipo == "decimal")
                {
                    code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
                }
                if(atributo.tipo  == "double" && resultado->tipo == "caracter"||
                   atributo.tipo  == "double" && resultado->tipo == "entero"||
                   atributo.tipo  == "double" && resultado->tipo == "decimal")
                {
                    code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
                }
                else if (atributo.tipo  == "caracter" && resultado->tipo == "cadena")
                {
                    code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
                }
                else if(atributo.tipo == resultado->tipo) // Objetos
                {
                    code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
                }
                else
                {
                    errorT * error = new errorT("Semantico","No se puede asignar un arreglo de tipo " + resultado->tipo + " a un arreglo de tipo " + atributo.tipo,
                                                atributo.linea, atributo.columna);
                    listaErrores->append(*error);
                }
            }
            else
            {
                QString temporalTamanoIngreso = generarTemporal();
                QString etiquetaAsignacion = generarEtiqueta();
                QString etiquetaError = generarEtiqueta();
                //QString temporalContador = generarTemporal();
                QString temporalPosicion = generarTemporal();
                code->cadena3d += temporalTamano + "= "+ QString::number(atributo.raiz.hijos.value(4).hijos.count())+" ;// Tamaño de los datos a ingresar.\n";
                code->cadena3d += "if("+temporalTamano+"== "+temporalTamanoIngreso+")goto "+etiquetaAsignacion+";\n";
                code->cadena3d += "goto "+ etiquetaError+ "; // Stack over flow perros.\n";
                code->cadena3d += etiquetaAsignacion +":\n";
                //code->cadena3d += temporalContador + " = 0 ; // Inicio de contador\n";
                for(int iObjeto = 0 ; iObjeto < atributo.raiz.hijos.value(4).hijos.count();iObjeto++)
                {
                    code->cadena3d += temporalPosicion + "= "+inicioArray + " + " + QString::number(iObjeto) +"; // Posicion absoluta del elemento del array\n";
                    Operaciones * operacionObjeto = new Operaciones();
                    Resultado * resultadoObjeto = new Resultado();
                    nodo nodoIndice = atributo.raiz.hijos.value(4).hijos.value(iObjeto);
                    resultadoObjeto = operacionObjeto->logica(&nodoIndice,0);
                    switch (resultadoObjeto->tipo_)
                    {
                        case TENTERO_:
                        case TDECIMAL_:
                        case TCARACTER_:
                        case TBOOLEANO_:
                        {
                            if(atributo.tipo == "decimal")
                            {
                                code->cadena3d += temporalPosicion + "= "+inicioArray + " + " + temporalPosicion +"; // Posicion absoluta del elemento del array\n";
                                code->cadena3d += "heap[" + temporalPosicion +"] = " + resultadoObjeto->valor + "; // Valor del elemento\n";
                            }
                            else // Hay que hacer casteo implicito.
                            {
                                QString tmpDecimal = generarTemporal();
                                QString tmpEntera = generarTemporal();
                                code->cadena3d += tmpDecimal + " = " + resultadoObjeto->valor + " %  1 ; // Quitando parte decimal\n";
                                code->cadena3d += tmpEntera + " = " + resultadoObjeto->valor  + " - " + tmpDecimal + ";// Casteo Implicito. \n";
                                code->cadena3d += "heap[" + temporalPosicion +"] = " + tmpEntera + "; // Valor del elemento\n";
                            }
                            break;
                        }
                        default:
                        {
                            if(resultadoObjeto->tipo == atributo.tipo)
                            {
                                code->cadena3d += "heap[" + temporalPosicion +"] = " + resultadoObjeto->valor + "; // Valor del elemento\n";
                            }
                            else
                            {
                                errorT * error = new errorT("Semantico","No se puede asignar un valor de tipo "+resultadoObjeto->tipo + " a un objeto de tipo " + atributo.tipo,
                                                            atributo.linea, atributo.columna);
                                listaErrores->append(*error);
                            }
                        }
                    }
                }
            }
            /*Ponemos los valores por defeto*/
        }
    }        
}

Resultado GeneradorCodigo:: generarAcceso(nodo raiz)
{
/*    Resultado *resultado = new Resultado();
    for()
    {

    }
*/
}


void GeneradorCodigo:: declararArregloAsignar(nodo raizActual)
{
    //QString direccionInstancia = generarTemporal();
    QString direccionAtributo = generarTemporal();
    QString direccionPuntero = generarTemporal();
    QString inicioArray = generarTemporal();
    QString temporalTamano = generarTemporal();


    QString nombreVariable = raizActual.hijos.value(1).valor;
    QString ambitoActual = code->getAmbitoActual();
    Simbolo simbolo = code->getSimboloPorNombre(nombreVariable);
    if(simbolo.id =="")
    {
        errorT * error = new errorT("Semantico","No existe la variable "+ nombreVariable +  " en la función "+ ambitoActual,
                                    raizActual.linea, raizActual.columna);
        listaErrores->append(*error);
        return;
    }
    code->cadena3d +=  direccionAtributo + " = p + "+ QString::number(simbolo.direccionLocal) + "; // Dirección del array en el ambito actual.\n";
    code->cadena3d +=  direccionPuntero + " = stack[" + direccionAtributo + "]; // Direccion del arreglo "+simbolo.nombre+" en el heap\n";
    code->cadena3d +=  "heap["+direccionPuntero + "] = h; // Inicio del arreglo en el heap\n" ;
    code->cadena3d += inicioArray + "= h ; // Apuntador al inicio del arreglo.\n";
    code->cadena3d += temporalTamano +" = 1 ; // Tamano inicial del arreglo\n";
    for(int j = 0 ; j<raizActual.hijos.value(2).hijos.count(); j++)
    {
        Operaciones *operacion = new Operaciones();
        nodo nodoRaiz = raizActual.hijos.value(2).hijos.value(j);
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
                QString temporalDecimal = generarTemporal();
                code->cadena3d += temporalDecimal + " = " + valorDimensionProvisional + " % 1 ; // Obtenemos la parte decimal\n";
                QString temporalEntero = generarTemporal();
                code->cadena3d += temporalEntero + " = " + valorDimensionProvisional  + "-" + temporalDecimal + "; // Casteo Implicito.\n";
                QString etqTamano = generarTemporal();
                code->cadena3d += etqTamano + " = " +  temporalTamano +" * " +temporalEntero +";// Se actualiza el tamaño total del array\n" ;
                temporalTamano = etqTamano;
            }
            default: // Error
            {
                errorT * error = new errorT("Semantico","Se esperaba un número númerico para definir el tamaño de la dimensión."
                                            ,raizActual.linea, raizActual.columna);
                listaErrores->append(*error);
            }
        }// Fin switch
    }// Fin
    if(raizActual.hijos.value(3).tipo != "lvalores")
    {
        Operaciones *operacion =  new Operaciones();
        Resultado *resultado = new Resultado();
        nodo nodoAOperar = raizActual.hijos.value(3);
        nodo *ptr =  &nodoAOperar;
        resultado = operacion->logica(ptr,0);
        /*Comprobación de tipos.*/
        if((raizActual.hijos.value(0).tipo  == "caracter" && resultado->tipo == "caracter")||
           (raizActual.hijos.value(0).tipo  == "caracter" && resultado->tipo == "entero")||
           (raizActual.hijos.value(0).tipo  == "caracter" && resultado->tipo == "decimal")
          )
        {
            code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
        }
        if(
           (raizActual.hijos.value(0).tipo  == "entero" && resultado->tipo == "caracter")||
           (raizActual.hijos.value(0).tipo  == "entero" && resultado->tipo == "entero")||
           (raizActual.hijos.value(0).tipo  == "entero" && resultado->tipo == "decimal")
          )
        {
            code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
        }
        if(
           (raizActual.hijos.value(0).tipo  == "double" && resultado->tipo == "caracter")||
           (raizActual.hijos.value(0).tipo  == "double" && resultado->tipo == "entero")||
           (raizActual.hijos.value(0).tipo  == "double" && resultado->tipo == "decimal")
          )
        {
            code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
        }
        else if (raizActual.hijos.value(0).tipo  == "caracter" && resultado->tipo == "cadena")
        {
            code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
        }
        else if(raizActual.hijos.value(0).tipo == resultado->tipo) // Objetos
        {
            code->cadena3d += "heap["+ inicioArray+"] = "+ resultado->valor +"; //Dirección del arreglo.\n";
        }
        else
        {
            errorT * error = new errorT("Semantico","No se puede asignar un arreglo de tipo " + resultado->tipo + " a un arreglo de tipo " + raizActual.hijos.value(0).tipo,
                                        raizActual.hijos.value(0).linea, raizActual.hijos.value(0).columna);
            listaErrores->append(*error);
        }
    }
    else
    {
        QString temporalTamanoIngreso = generarTemporal();
        QString etiquetaAsignacion = generarEtiqueta();
        QString etiquetaError = generarEtiqueta();
        //QString temporalContador = generarTemporal();
        QString temporalPosicion = generarTemporal();
        code->cadena3d += temporalTamano + "= "+ QString::number(raizActual.hijos.value(3).hijos.count())+" ;// Tamaño de los datos a ingresar.\n";
        code->cadena3d += "if("+temporalTamano+"== "+temporalTamanoIngreso+")goto "+etiquetaAsignacion+";\n";
        code->cadena3d += "goto "+ etiquetaError+ "; // Stack over flow perros.\n";
        code->cadena3d += etiquetaAsignacion +":\n";
        //code->cadena3d += temporalContador + " = 0 ; // Inicio de contador\n";
        for(int iObjeto = 0 ; iObjeto < raizActual.hijos.value(3).hijos.count();iObjeto++)
        {
            code->cadena3d += temporalPosicion + "= "+inicioArray + " + " + QString::number(iObjeto) +"; // Posicion absoluta del elemento del array\n";
            Operaciones * operacionObjeto = new Operaciones();
            Resultado * resultadoObjeto = new Resultado();
            nodo nodoIndice = raizActual.hijos.value(3).hijos.value(iObjeto);
            resultadoObjeto = operacionObjeto->logica(&nodoIndice,0);
            switch (resultadoObjeto->tipo_)
            {
                case TENTERO_:
                case TDECIMAL_:
                case TCARACTER_:
                case TBOOLEANO_:
                {
                    if(raizActual.hijos.value(0).tipo != "decimal")
                    {
                        code->cadena3d += temporalPosicion + "= "+inicioArray + " + " + temporalPosicion +"; // Posicion absoluta del elemento del array\n";
                        code->cadena3d += "heap[" + temporalPosicion +"] = " + resultadoObjeto->valor + "; // Valor del elemento\n";
                    }
                    else // Hay que hacer casteo implicito.
                    {
                        QString tmpDecimal = generarTemporal();
                        QString tmpEntera = generarTemporal();
                        code->cadena3d += tmpDecimal + " = " + resultadoObjeto->valor + " %  1 ; // Quitando parte decimal\n";
                        code->cadena3d += tmpEntera + " = " + resultadoObjeto->valor  + " - " + tmpDecimal + ";// Casteo Implicito. \n";
                        code->cadena3d += "heap[" + temporalPosicion +"] = " + tmpEntera + "; // Valor del elemento\n";
                    }
                    break;
                }
                default:
                {
                    if(resultadoObjeto->tipo == raizActual.hijos.value(0).tipo)
                    {
                        code->cadena3d += "heap[" + temporalPosicion +"] = " + resultadoObjeto->valor + "; // Valor del elemento\n";
                    }
                    else
                    {
                        errorT * error = new errorT("Semantico","No se puede asignar un valor de tipo "+resultadoObjeto->tipo + " a un objeto de tipo " + raizActual.hijos.value(0).tipo,
                                                    raizActual.hijos.value(0).linea, raizActual.hijos.value(0).columna);
                        listaErrores->append(*error);
                    }
                }
            }
        }
    }
    /*Ponemos los valores por defeto*/
}


void GeneradorCodigo::declararArreglo(nodo raizActual)
{
    //QString direccionInstancia = generarTemporal();
    QString direccionAtributo = generarTemporal();
    QString direccionPuntero = generarTemporal();
    QString inicioArray = generarTemporal();
    QString temporalTamano = generarTemporal();


    QString nombreVariable = raizActual.hijos.value(1).valor;
    QString ambitoActual = code->getAmbitoActual();
    Simbolo simbolo = code->getSimboloPorNombre(nombreVariable);
    if(simbolo.id ==""){return;}
    code->cadena3d +=  direccionAtributo + " = p + "+ QString::number(simbolo.direccionLocal) + "; // Dirección del array en el ambito actual.\n";
    code->cadena3d +=  direccionPuntero + " = stack[" + direccionAtributo + "]; // Direccion del arreglo "+simbolo.nombre+" en el heap\n";
    code->cadena3d +=  "heap["+direccionPuntero + "] = h; // Inicio del arreglo en el heap\n" ;
    code->cadena3d += inicioArray + "= h ; // Apuntador al inicio del arreglo.\n";
    code->cadena3d += temporalTamano +" = 1 ; // Tamano inicial del arreglo\n";
    for(int j = 0 ; j<raizActual.hijos.value(2).hijos.count(); j++)
    {
        Operaciones *operacion = new Operaciones();
        nodo nodoRaiz = raizActual.hijos.value(2).hijos.value(j);
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
                QString temporalDecimal = generarTemporal();
                code->cadena3d += temporalDecimal + " = " + valorDimensionProvisional + " % 1 ; // Obtenemos la parte decimal\n";
                QString temporalEntero = generarTemporal();
                code->cadena3d += temporalEntero + " = " + valorDimensionProvisional  + "-" + temporalDecimal + "; // Casteo Implicito.\n";
                QString etqTamano = generarTemporal();
                code->cadena3d += etqTamano + " = " +  temporalTamano +" * " +temporalEntero +";// Se actualiza el tamaño total del array\n" ;
                temporalTamano = etqTamano;
            }
            default: // Error
            {
                errorT * error = new errorT("Semantico","Se esperaba un número númerico para definir el tamaño de la dimensión."
                                            ,raizActual.linea, raizActual.columna);
                listaErrores->append(*error);
            }
        }// Fin switch
    }// Fin
    /*Ponemos los valores por defeto*/
    //if(atributo.tipo != "caracter")
    if(1)
    {
        QString etiquetaCiclo = generarEtiqueta();
        QString etiquetaFinCiclo = generarEtiqueta();
        QString etiquetaSetear = generarEtiqueta();
        QString temporalContador = generarTemporal();
        code->cadena3d += temporalContador +" = 0 ; // Inicio del contador\n";
        code->cadena3d += etiquetaCiclo +": // Ciclo de llenado de array.\n";
        code->cadena3d += "if("+temporalContador+"<"+temporalTamano+") goto " + etiquetaSetear + "; // \n";
        code->cadena3d += "goto " + etiquetaFinCiclo + "; \n";
        code->cadena3d += etiquetaSetear +":// Setear valores por defecto\n";
        QString posicionRelativa = generarTemporal();
        code->cadena3d += ""+posicionRelativa +" =  " +inicioArray+ " + " + temporalContador+ "; // Direción del indice actual\n";
        switch (raizActual.hijos.value(0).tipo_)
        {
            case TENTERO_:
            case TBOOLEANO_:
            case TDECIMAL_:
            {
                code->cadena3d +="heap["+posicionRelativa+"] = 0; //Valor por defecto\n";
                break;
            }
            case TOBJETO_:
            {
                code->cadena3d +="heap["+posicionRelativa+"] ="+QString::number(code->NADA_) +"; //Valor por defecto NULL \n";
                break;
            }

        }
        code->cadena3d += ""+ temporalContador + " = " + temporalContador + " + 1; // Siguiente indice\n";
        code->cadena3d += "goto " + etiquetaCiclo + ";//Retorno a ciclo\n";
        code->cadena3d += ""+etiquetaFinCiclo +":// \n";
        //code->cadena3d += "h = h + " + temporalTamano + "; // Reservamos el tamaño del array en el heap.\n" ;
    }
    else
    {
        code->cadena3d += "heap[" + inicioArray+"] = "+QString::number(code->NADA_)+";// Apuntador NULL por defecto\n";
    }
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
            errorT * error = new errorT("Semantico","No existe la clase "+claseActual,linea, columna);
            listaErrores->append(*error);
//            if( claseActual != "principal")
//            {
//                errorT * error = new errorT("Semantico","No existe la clase "+claseActual,linea, columna);
//                listaErrores->append(*error);
//            }
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
    return this->pilaAmbitos->value(1);
}

void GeneradorCodigo:: actualizarContadores(int tamano)
{
    contadorSimbolos+=tamano;
    contadorClase+=tamano;
    contadorFuncion+=tamano;
}

void GeneradorCodigo:: declararVariable(nodo raizActual)
{
    QString nombreVariable = raizActual.hijos.value(1).valor;
    QString ambitoActual = code->getAmbitoActual();
    Simbolo simbolo = code->getSimboloPorNombre(nombreVariable);
    if(simbolo.id == "")
    {
        errorT * error = new errorT("Semantico","No existe la variable en el ambito " + code->getAmbitoActual(),
                                    raizActual.linea,raizActual.columna);
        listaErrores->append(*error);
        return;
    }
    QString direccionVariable = generarTemporal();
    code->cadena3d += direccionVariable + " = p + " + QString::number(simbolo.direccionLocal) + ";// Dirección de la variable  "+nombreVariable+"\n";
    switch (raizActual.hijos.value(0).tipo_)
    {
        case TENTERO_:
        {
            code->cadena3d += "stack[" + direccionVariable + "] =  0 ; // Valor por defecto para enteros" +"\n";
            break;
        }
        case TCARACTER_ :
        {
            code->cadena3d += "stack[" + direccionVariable + "] =  0 ; // Valor por defecto para caracter\n" ;
            break;
        }
        case TBOOLEANO_ :
        {
            code->cadena3d += "stack[" + direccionVariable + "] = 0 ; // Valor por defecto para booleano\n" ;
            break;
        }
        case TCADENA_:
        {
            code->cadena3d += "stack["+direccionVariable+"] = "+QString::number(code->NADA_)+";// Puntero hacia la posición de la cadena.\n";
            break;
        }
        case TDECIMAL_:
        {
            code->cadena3d += "stack[" + direccionVariable + "] =  0.00 ; // Valor por defecto para decimales\n" ;
            break;
        }
        case TOBJETO_:
        {
            code->cadena3d += "stack["+direccionVariable+"] = "+QString::number(code->NADA_)+";// Puntero hacia la posición del objeto.\n";
            break;
        }
    }
}

void GeneradorCodigo:: declararVariableAsignacion(nodo raizActual) // Declaración sin valor
{
    QString nombreVariable = raizActual.hijos.value(1).valor;
    QString ambitoActual = code->getAmbitoActual();
    Simbolo simbolo = code->getSimboloPorNombre(nombreVariable);
    if(simbolo.id == "")
    {
        errorT * error = new errorT("Semantico","No existe la variable en el ambito " + code->getAmbitoActual(),
                                    raizActual.linea,raizActual.columna);
        listaErrores->append(*error);
    }
    QString direccionEste = generarTemporal();
    QString direccionTemp = generarTemporal();
    QString direccionVariable = generarTemporal();
    if(simbolo.rol == "atributo") // Si es atributo hay que ir a traerlo en el heap
    {
        code->cadena3d += direccionEste + " = p + "+QString::number(simbolo.direccionLocal)+"; // Dirección este objeto\n";
        code->cadena3d += direccionVariable + " = "+direccionEste+" + " + QString::number(simbolo.direccionLocal) + ";// Dirección de la variable  "+nombreVariable+"\n";
    }
    else
    {
        code->cadena3d += direccionVariable + " = p + " + QString::number(simbolo.direccionLocal) + ";// Dirección de la variable  "+nombreVariable+"\n";
    }
    Operaciones *operacion = new Operaciones();
    Resultado *resultado = new Resultado();
    if(raizActual.hijos.count()==3) // Declaración asignación de variable no arreglo
    {
        nodo nodoExp = raizActual.hijos.value(2);
        nodo *ptr = &nodoExp;
        resultado = operacion->logica(ptr,0);
        code->desapilarMetodo();
        //ambitoActual = code->getAmbitoActual();
    }
    else // Declaradción asignación de un arreglo.
    {
        nodo nodoExp = raizActual.hijos.value(2);
        resultado = operacion->logica(&nodoExp,0);
        code->desapilarMetodo();
        //ambitoActual = code->getAmbitoActual();
    }
    /*Comprobación de tipos*/
    switch (raizActual.hijos.value(0).tipo_)
    {
        case TENTERO_:
        case TBOOLEANO_:
        case TCARACTER_:
        {
            if(resultado->tipo_ == TENTERO_ || resultado->tipo_ == TDECIMAL_ || resultado->tipo_ == TBOOLEANO_ || resultado->tipo_ == TCARACTER_)
            {
                QString et1 = generarTemporal();
                QString et2 = generarTemporal();
                code->cadena3d += et1 + " = " + resultado->valor + " % 1 ; // Obteniendo la parte decimal. \n";
                code->cadena3d += et2 + " = " + resultado->valor + " - " + et1  + "; // Casteo Implicito. \n" ;
                code->cadena3d += "stack["+ direccionVariable + "] =" + et2 + "; Seteando valor a variable "+ nombreVariable + " \n";
            }
            break;
        }
        case TDECIMAL_:
        {
            code->cadena3d += "stack["+ direccionVariable + "] =" + resultado->valor + "; Seteando valor a variable "+ nombreVariable + " \n";
            break;
        }
        case TOBJETO_:
        {
            if(raizActual.hijos.value(0).valor == resultado->valor)
            {
                code->cadena3d += "stack["+ direccionVariable + "] =" + resultado->valor + "; Seteando valor a variable "+ nombreVariable + " \n";
            }
            else
            {
                errorT * error = new errorT("Semantico","No existe la variable en el ambito " + code->getAmbitoActual(),
                                            raizActual.linea,raizActual.columna);
                listaErrores->append(*error);
            }
            break;
        }// Fin case tobjeto
    }// Fin Swtich
}// Fin metodo

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
