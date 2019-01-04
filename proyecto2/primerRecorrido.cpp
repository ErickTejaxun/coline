#include "primerRecorrido.h"
extern QList<nodo> *listaArboles;
extern QList<errorT> *listaErrores;
/*Elementos del parseo*/
extern int yyparse();
extern nodo *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

primerRecorrido::primerRecorrido()
{    

}

QString primerRecorrido::generarTemporal()
{
    QString temporal = "t" + QString::number(this->contT);
    this->contT++;
    return temporal;
}

QString primerRecorrido::generarEtiqueta()
{
    QString temporal = "L" + QString::number(this->contE);
    this->contE++;
    return temporal;
}


void primerRecorrido:: interpretar(QList<nodo> * listaArboless)
{
    listaArboles = listaArboless;
    for(int i = 0 ; i<listaArboles->count(); i++)
    {        
        nodo hijo = listaArboles->first();
        listaArboles->removeFirst();
        interpretar(hijo);
    }
}


void primerRecorrido:: interpretar(nodo raiz)
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
        SETENTENCIASG = 61 // Setnencias globales. Raiz del archivo
    };
    // Empezamos a recorrer la lista de arboles.
    for(int i = 0 ; i<raiz.hijos.count(); i++)
    {
        nodo hijo = raiz.hijos[i];
        switch (hijo.tipo_)
        {
            case Choice::IMPORTAR_:
            importar(hijo);
            break;
            case CLASE_:
            break;
        }

    }

}


void primerRecorrido:: importar(nodo raiz)
{    
    QString path = escapar(raiz.hijos[0].valor);
    QFile file(path);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         errorT *error = new errorT("Semantico", "El archivo "+path+ " no existe.",raiz.linea,raiz.columna);
         listaErrores->append(*error);
         return;
     }
    QString contenido = file.readAll(); // Contenido del archivo
    file.close();

    YY_BUFFER_STATE buffer = yy_scan_string(contenido.toUtf8().constData());
    linea =0;
    columna =0;
    yylineno = 0;
    if(yyparse()==0)
    {
        primerRecorrido *inter = new primerRecorrido();
        listaArboles->append(raiz);        
    }
    else
    {
        //ui->txtConsola->setText("Errores sintacticos en la entrada");
    }
    yy_delete_buffer(buffer);
}

QString primerRecorrido::escapar(QString cadena)
{
    cadena = cadena.replace("\"", "");
    //cadena = cadena.replace("\"", "\\\"");
    return cadena;
}
