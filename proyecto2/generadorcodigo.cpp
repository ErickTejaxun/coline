#include "generadorcodigo.h"
#include <tablasimbolos.h>
#include <qdebug.h>
#include <codigo3d.h>
extern tablaSimbolos *tabla;
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
        NO_ = 76
    };

    for(int i = 0 ; i < raiz.hijos.count(); i++)
    {
        nodo hijo = raiz.hijos[i];
        switch (hijo.tipo_)
        {
            case CLASE_:
                qDebug() << "Generando para clase :v" ;
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
    Simbolo constructor = getConstructor(nombrClase);
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
    return "L" + code->etiqueta++;
}

QString GeneradorCodigo:: generarTemporal()
{
    return "t" + code->temporal++;
}

Simbolo GeneradorCodigo::getConstructor(QString nombreClase)
{
    Simbolo simb;
    for(int i = 0; i < tabla->listaSimbolos->count(); i++)
    {
        simb = tabla->listaSimbolos->value(i);
        if(simb.nombre == nombreClase)
        {
            return simb;
        }
    }
    return simb;
}
