#include "primerRecorrido.h"
#include <qdebug.h>
extern QList<nodo> *listaArboles;
extern QList<errorT> *listaErrores;  //
/*Elementos del parseo*/
extern int yyparse();
extern nodo *raiz; // Raiz del arbol
extern int linea; // Linea del token
extern int columna; // Columna de los tokens
extern int yylineno;

primerRecorrido::primerRecorrido()
{    
    listaClases = new QList<Clase>();
    tabla = new tablaSimbolos();
    pilaAmbitos = new QList<QString>();
    pilaAmbitos->append("global");
    ambitoActual = "global";
    contadorSimbolos = 0;
    tamanoActual = 0;
    contadorClase=0;
    contadorFuncion=0;
    contadorIf= 0;
    contadorWhile=0;
    contadorElseIf=0;
    contadorElse = 0;
    contadorPara=0;
    contadorDoWhile =0;
    contadorSeleccionar=0;
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
    int numeroArboles = listaArboles->count();
    for(int i = 0 ; i < numeroArboles; i++)
    {
        interpretar(listaArboles->value(i));
        numeroArboles = listaArboles->count();
    }
    qDebug()<<"Saliendo";
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
        TDECIMAL_ = 80
    };
    // Empezamos a recorrer la lista de arboles.
    for(int i = 0 ; i<raiz.hijos.count(); i++)
    {        
        nodo hijo = raiz.hijos[i];        
        switch (hijo.tipo_)
        {
            case IMPORTAR_:
                importar(hijo);
                break;
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
                interpretar(hijo);
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

void primerRecorrido::crearClase(nodo raizActual)
{    
    contadorClase = 0;
    Clase *nuevaClase = new Clase();
    nuevaClase->raiz = raizActual;
    nuevaClase->nombre = raizActual.valor;        
    nuevaClase->visibilidad = raizActual.hijos[0].tipo;
    nuevaClase->padre  = raizActual.hijos[1].valor;
    nuevaClase->ambito = ambitoActual;
    nuevaClase->linea = raizActual.linea;
    nuevaClase->columna = raizActual.columna;
    nuevaClase->rol = "clase";
    nuevaClase->tamano = 1;
    nuevaClase->dimension = 0;
    nuevaClase->direccionGlobal = contadorSimbolos;
    nuevaClase->direccionLocal = contadorClase;
    nuevaClase->id = ambitoActual + "$" + nuevaClase->nombre;
    int resultado = this->tabla->agregarClase(*nuevaClase, raizActual);
    if(resultado ==1 ) // Inserción con exito
    {
        pilaAmbitos->append(nuevaClase->nombre);        
        getAmbitoActual();
        contadorClase = 0;
        interpretar(raizActual.hijos[2]);
        nuevaClase->tamano = contadorClase;
        actualizarTamano(*nuevaClase);

        /*Buscamos si se definió el constructor() por el usuario
        int existeConstructor = 0;
        for(int i = 0; i < this->tabla->listaSimbolos->count();i++)
        {
            Simbolo simbolo = this->tabla->listaSimbolos->value(i);
            if(simbolo.nombre == nuevaClase->nombre
             &&simbolo.id == nuevaClase->nombre
             &&simbolo.rol == "constructor"
             )
            {
                existeConstructor = 1;
                break;
            }
        }
        if(!existeConstructor)
        {
            nodo * nodoConstructor = new nodo("constructor",nuevaClase->nombre,0,0);
            nodo * nodoVisibilidad = new nodo("visibilidad","publico",0,0);
            nodo * nodoParametros = new nodo("parametros","parametros",0,0);
            nodo * nodoSentencias  = new nodo("sentencias","sentencias",0,0);
            nodoConstructor->hijos.append(*nodoVisibilidad);
            nodoConstructor->hijos.append(*nodoParametros);
            nodoConstructor->hijos.append(*nodoSentencias);
            crearConstructor(*nodoConstructor);
        }
        */
        pilaAmbitos->pop_back();
        getAmbitoActual();                
    }
}

void primerRecorrido:: actualizarTamano(Simbolo sim)
{
    for(int i=0;i<this->tabla->listaSimbolos->count(); i++)
    {
        if(this->tabla->listaSimbolos->value(i).id.toLower() == sim.id.toLower()&&
                this->tabla->listaSimbolos->value(i).ambito.toLower() == sim.ambito.toLower()
                )
        {
            this->tabla->listaSimbolos->replace(i, sim);
            return;
        }
    }
}

void primerRecorrido:: getAmbitoActual()
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

QString primerRecorrido:: getClaseActual()
{
    return this->pilaAmbitos->value(this->pilaAmbitos->count()-1);
}



void primerRecorrido:: crearFuncion(nodo raizActual)
{    
    getAmbitoActual();
    contadorFuncion=0;
    Simbolo *funcion = new Simbolo();
    funcion->raiz = raizActual;
    funcion->rol = "metodo";
    /*sobrescrito*/
    if(raizActual.hijos.value(0).valor.toLower() != "no"){funcion->sobrescrito = 1;}
    funcion->visibilidad = raizActual.hijos.value(1).valor.toLower();
    funcion->tipo = raizActual.hijos.value(2).valor.toLower();
    funcion->nombre = raizActual.valor.toLower();    
    funcion->linea = raizActual.linea;
    funcion->columna = raizActual.columna;
    funcion->ambito = ambitoActual;
    funcion->dimension = raizActual.hijos.value(3).hijos.count();
    funcion->tamano = 0;
    funcion->direccionGlobal = contadorSimbolos;
    funcion->direccionLocal = contadorFuncion;
    /*Obtenemos el id según el numero de parametros.*/
    QString id = funcion->nombre;
    for(int i = 0; i<raizActual.hijos.value(4).hijos.count(); i++)
    {
        id = id + "$" + raizActual.hijos.value(4).hijos.value(i).tipo.toLower();
    }
    funcion->id = /*ambitoActual + "$" + */ id;
    int resultado = this->tabla->agregarFuncion(*funcion, raizActual);
    if(resultado == 1)
    {

        /*Agregamos la referencia al objeto (this)*/
        pilaAmbitos->append(funcion->id);
        getAmbitoActual();
        Simbolo *este = new Simbolo();
        este->nombre = "este";
        este->id = ambitoActual+ "$"+ este->nombre;
        este->direccionLocal = 0;
        este->direccionGlobal = contadorSimbolos;
        este->rol = "variable";
        este->tamano  = 1;
        este->ambito = ambitoActual;
        este->visibilidad = funcion->visibilidad;
        este->linea = funcion->linea;
        este->columna = funcion->columna;
        este->tipo = funcion->tipo;
        este->dimension = 0;
        this->tabla->agregarVariable(*este, raizActual);
        /*Actualizar los contadores*/
        actualizarContadores(1);
        /*Agregamos el returno*/
        Simbolo *retorno = new Simbolo();        
        retorno->nombre = "retorno";
        retorno->id =ambitoActual+ "$"+  retorno->nombre;
        retorno->direccionLocal = 1;
        retorno->direccionGlobal = contadorSimbolos;
        retorno->rol = "variable";
        retorno->tamano  = 1;
        retorno->ambito = ambitoActual;
        retorno->visibilidad = funcion->visibilidad;
        retorno->linea = funcion->linea;
        retorno->columna = funcion->columna;
        retorno->tipo = funcion->tipo;
        retorno->dimension = 0;
        this->tabla->agregarVariable(*retorno, raizActual);
        /*Actualizamos contadores*/
        actualizarContadores(1);
        /*Agregamos los parametros a la tabla de símbolos*/
        getAmbitoActual();        
        crearParametros(raizActual.hijos[4]); // Parametros
        interpretar(raizActual.hijos[5]); // Encontrar variables
        /*Actualizamos el tamano de la funcion*/
        funcion->tamano = contadorFuncion;
        actualizarTamano(*funcion);
        pilaAmbitos->pop_back();
        getAmbitoActual();
    }

}

void primerRecorrido:: crearConstructor(nodo raizActual)
{
    contadorFuncion = 0;
    Simbolo *constructor = new Simbolo();
    constructor->raiz = raizActual;
    constructor->rol = "constructor";
    constructor->visibilidad = raizActual.hijos.value(0).valor.toLower();
    constructor->nombre = raizActual.valor.toLower();
    if(constructor->nombre != getClaseActual())
    {
        errorT * error = new errorT("Semantico",
                                    "No se puede crear un constructor de la clase "+ constructor->nombre + " en la clase " + getClaseActual(),
                                    raizActual.linea, raizActual.columna);
        listaErrores->append(*error);
        return;
    }
    constructor->tipo =getClaseActual();
    constructor->linea = raizActual.linea;
    constructor->columna = raizActual.columna;
    constructor->ambito = ambitoActual;
    constructor->dimension = 0;
    constructor->direccionGlobal = contadorSimbolos;
    constructor->direccionLocal = contadorFuncion;
    /*Obtenemos el id según el numero de parametros.*/
    QString id = constructor->nombre;
    for(int i = 0; i<raizActual.hijos.value(1).hijos.count(); i++)
    {
        id = id + "$" + raizActual.hijos.value(1).hijos.value(i).tipo.toLower();
    }
    constructor->id = /*ambitoActual + "$"  + */id;
    int resultado = this->tabla->agregarFuncion(*constructor, raizActual);
    if(resultado == 1)
    {
        /*Agregamos los parametros a la tabla de símbolos*/
        pilaAmbitos->append(constructor->id);
        getAmbitoActual();
        /*Agregamos la referencia al objeto (this)*/
        Simbolo *este = new Simbolo();
        este->nombre = "este";
        este->id =ambitoActual;
        este->direccionLocal = 0;
        este->direccionGlobal = constructor->direccionGlobal;
        este->rol = "variable";
        este->tamano  = 1;
        este->ambito = ambitoActual  + "$" + este->nombre;
        este->visibilidad = constructor->visibilidad;
        este->linea = constructor->linea;
        este->columna = constructor->columna;
        este->tipo = constructor->tipo;
        este->dimension = 0;
        nodo *n = new nodo();
        this->tabla->agregarVariable(*este, *n);
        /*Actualizar los contadores*/
        actualizarContadores(1);
        /*Agregamos el returno*/
        Simbolo *retorno = new Simbolo();
        retorno->nombre = "retorno";
        retorno->id =ambitoActual;
        retorno->direccionLocal = 1;
        retorno->direccionGlobal = constructor->direccionGlobal+1;
        retorno->rol = "variable";
        retorno->tamano  = 1;
        retorno->ambito = ambitoActual + "$" + retorno->nombre;
        retorno->visibilidad = constructor->visibilidad;
        retorno->linea = constructor->linea;
        retorno->columna = constructor->columna;
        retorno->tipo = constructor->tipo;        
        this->tabla->agregarVariable(*retorno, *n);
        /*Actualizamos contadores*/
        actualizarContadores(1);
        /*Obtenemos los parametros*/
        crearParametros(raizActual.hijos[1]);
        /*Obtenemos las variables locales*/
        interpretar(raizActual.hijos[2]);
        constructor->tamano = contadorFuncion;
        actualizarTamano(*constructor);
        pilaAmbitos->pop_back();
        getAmbitoActual();
    }
}


void primerRecorrido:: declararSi(nodo raizActual)
{    
    pilaAmbitos->append("si"+QString::number(contadorIf));
    getAmbitoActual();
    contadorIf++;
    interpretar(raizActual.hijos.value(1));
    pilaAmbitos->pop_back();    
    getAmbitoActual();

    int final = raizActual.hijos.count();
    int existeSino = 0;
    if(raizActual.hijos.count()%2 == 1)
    {
        final = raizActual.hijos.count() - 1;
        existeSino  =1;
    }
    // Recorremos cada uno de los sino si
    for(int i = 2; i < final ; i++)
    {
        i++;
        pilaAmbitos->append("sinosi"+QString::number(contadorElseIf));
        getAmbitoActual();
        contadorElseIf++;
        interpretar(raizActual.hijos.value(i));
        pilaAmbitos->pop_back();
        getAmbitoActual();
    }
    // Si hay un sino
    if(existeSino==1)
    {
        pilaAmbitos->append("sino"+QString::number(contadorElse));
        getAmbitoActual();
        contadorElse++;
        interpretar(raizActual.hijos.value(raizActual.hijos.count()-1));
        pilaAmbitos->pop_back();
        getAmbitoActual();
    }
}


void primerRecorrido:: declararSeleccionar(nodo raizActual)
{
    nodo nodocasos = raizActual.hijos.value(1);
    pilaAmbitos->append("seleccionar"+QString::number(contadorSeleccionar));
    getAmbitoActual();
    contadorSeleccionar++;
    for(int i = 0 ; i < nodocasos.hijos.count(); i++)
    {        
        nodo nodocaso = nodocasos.hijos.value(i);
        if(nodocaso.valor.toLower()=="defecto")
        {
            interpretar(nodocaso.hijos.value(0));
        }
        else
        {
            interpretar(nodocaso.hijos.value(1));
        }

    }
    pilaAmbitos->pop_back();
    getAmbitoActual();
}


void primerRecorrido:: declararHacer(nodo raizActual)
{
    //contadorFuncion = 0;
    pilaAmbitos->append("hacer"+QString::number(contadorDoWhile));
    contadorDoWhile++;
    getAmbitoActual();
    // Vemos si no hay una declaración en la declaración del ciclo
    interpretar(raizActual.hijos.value(0));
    // Sentencias
    interpretar(raizActual.hijos.value(3));
    pilaAmbitos->pop_back();
    getAmbitoActual();
}

void primerRecorrido:: declararMientras(nodo raizActual)
{
    //contadorFuncion = 0;
    pilaAmbitos->append("mientras"+QString::number(contadorWhile));
    contadorWhile++;
    getAmbitoActual();
    interpretar(raizActual.hijos.value(1));
    pilaAmbitos->pop_back();
    getAmbitoActual();
}

void primerRecorrido:: declararPara(nodo raizActual)
{
    //contadorFuncion = 0;
    pilaAmbitos->append("para"+QString::number(contadorPara));
    contadorPara++;
    getAmbitoActual();
    // Inicio
    nodo * auxiliar = new nodo();
    auxiliar->hijos.append(raizActual.hijos.value(0));
    interpretar(*auxiliar);
    //interpretar(raizActual.hijos.value(0));
    //Sentencias
    interpretar(raizActual.hijos.value(3));
    pilaAmbitos->pop_back();
    getAmbitoActual();
}

void primerRecorrido:: crearParametros(nodo raizActual)
{
    for(int i = 0; i<raizActual.hijos.count(); i++)
    {
        nodo nodoPar = raizActual.hijos.value(i);
        Simbolo *parametro = new Simbolo();
        parametro->raiz = nodoPar;
        parametro->id =ambitoActual +"$" + nodoPar.valor;
        parametro->nombre = nodoPar.valor;
        parametro->tipo = nodoPar.tipo;
        parametro->rol = "parametro";
        parametro->ambito = ambitoActual;
        parametro->dimension = nodoPar.hijos.value(0).hijos.count();
        parametro->tamano = 1;
        parametro->direccionGlobal = contadorSimbolos;
        parametro->direccionLocal = contadorFuncion;
        nodo puntero = raizActual.hijos.value(i);
        nodo *pt = & puntero;
        int resultado = this->tabla->agregarVariable(*parametro,* pt);
        if(resultado==1)
        {
            actualizarContadores(parametro->tamano);
        }

    }
}

void primerRecorrido:: actualizarContadores(int tamano)
{
    contadorSimbolos+=tamano;
    //contadorClase+=tamano;
    contadorFuncion+=tamano;
}


void primerRecorrido:: crearVariable(nodo raizActual)
{
    Simbolo *variable = new Simbolo();
    variable->raiz = raizActual;
    variable->ambito = ambitoActual;
    variable->rol = "variable";    
    variable->nombre = raizActual.hijos.value(2).valor.toLower();
    variable->id = ambitoActual + "$" + variable->nombre;
    variable->visibilidad = raizActual.hijos.value(0).valor.toLower();
    variable->tipo = raizActual.hijos.value(1).valor.toLower();
    variable->dimension = 0;
    variable->tamano = 1;
    variable->direccionGlobal = contadorSimbolos;
    variable->direccionLocal = contadorFuncion;
    int resultado = this->tabla->agregarVariable(*variable, raizActual);
    if(resultado==1)
    {
        actualizarContadores(variable->tamano);
    }
    contadorClase++;
}

void primerRecorrido:: declararArreglo(nodo raizActual) // Declaración sin valor
{
    Simbolo *variable = new Simbolo();
    variable->raiz = raizActual;
    variable->ambito = ambitoActual;
    variable->rol = "variable";
    variable->nombre = raizActual.hijos.value(1).valor.toLower();
    variable->id = ambitoActual + "$" +variable->nombre ;
    variable->visibilidad = "";
    variable->tipo = raizActual.hijos.value(0).valor.toLower();
    variable->dimension = raizActual.hijos.value(2).hijos.count();
    variable->tamano = 1;
    variable->direccionGlobal = contadorSimbolos;
    variable->direccionLocal = contadorFuncion;    
    int resultado = this->tabla->agregarVariable(*variable, raizActual);
    if(resultado==1)
    {
        actualizarContadores(variable->tamano);
    }
}

void primerRecorrido:: declararParametro(nodo raizActual) // Declaración sin valor
{
    Simbolo *variable = new Simbolo();
    variable->raiz =  raizActual;
    variable->ambito = ambitoActual;    
    variable->rol = "variable";
    variable->nombre = raizActual.valor.toLower();
    variable->id = ambitoActual + "$" +variable->nombre ;
    variable->visibilidad = "";
    variable->tipo = raizActual.hijos.value(0).valor.toLower();
    variable->dimension = 0;
    variable->tamano = 1;
    variable->direccionGlobal = contadorSimbolos;
    variable->direccionLocal = contadorFuncion;
    int resultado = this->tabla->agregarVariable(*variable, raizActual);
    if(resultado==1)
    {
        actualizarContadores(variable->tamano);
    }
}

void primerRecorrido:: declararVariable(nodo raizActual) // Declaración sin valor
{
    Simbolo *variable = new Simbolo();
    variable->raiz = raizActual;
    variable->ambito = ambitoActual;
    variable->rol = "variable";
    variable->nombre = raizActual.valor.toLower();
    variable->id = ambitoActual + "$" +variable->nombre ;
    variable->visibilidad = "";
    variable->tipo = raizActual.hijos.value(0).valor.toLower();
    variable->dimension = 0;
    variable->tamano = 1;
    variable->direccionGlobal = contadorSimbolos;
    variable->direccionLocal = contadorFuncion;
    int resultado = this->tabla->agregarVariable(*variable, raizActual);
    if(resultado==1)
    {
        actualizarContadores(variable->tamano);
    }
}



void primerRecorrido:: importar(nodo raizActual)
{    
    QString path = escapar(raizActual.hijos[0].valor);
    QFile file(path);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         errorT *error = new errorT("Semantico", "El archivo "+path+ " no existe.",raizActual.linea,raizActual.columna);
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
        listaArboles->append(*raiz);
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
