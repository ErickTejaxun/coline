#include "primerRecorrido.h"
#include <qdebug.h>
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
    listaClases = new QList<Clase>();
    tabla = new tablaSimbolos();
    pilaAmbitos = new QList<QString>();
    pilaAmbitos->append("global");
    ambitoActual = "global";
    contadorSimbolos = 0;
    tamanoActual = 0;
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
    int i =0;
    QVector<nodo> vector =  listaArboles->toVector();
    while(!listaArboles->empty())
    //for(i = 0; i<vector.count();i++)
    {        
        //nodo hijo = vector[i];
        nodo hijo = listaArboles->first();
        listaArboles->pop_back();
        interpretar(hijo);
        //vector =  listaArboles->toVector();
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
        qDebug() << "tipo nodo:" << hijo.tipo_;
        switch (hijo.tipo_)
        {
            case Choice::IMPORTAR_:
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
        }        
    }

}

void primerRecorrido::crearClase(nodo raizActual)
{    

    Clase *nuevaClase = new Clase();
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
    int resultado = this->tabla->agregarClase(*nuevaClase, &raizActual);
    if(resultado ==1 ) // Inserción con exito
    {
        pilaAmbitos->append(nuevaClase->nombre);        
        getAmbitoActual();
        contadorClase = 0;
        interpretar(raizActual.hijos[2]);
        nuevaClase->tamano = contadorClase;
        actualizarTamano(*nuevaClase);
        pilaAmbitos->pop_back();
        getAmbitoActual();
    }
}

void primerRecorrido:: actualizarTamano(Simbolo sim)
{
    for(int i=0;i<this->tabla->tabla->count(); i++)
    {
        if(this->tabla->tabla->value(i).nombre.toLower() == sim.nombre.toLower()&&
                this->tabla->tabla->value(i).ambito.toLower() == sim.ambito.toLower()
                )
        {
            this->tabla->tabla->replace(i, sim);
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
            ambitoActual = ambitoActual + "," + this->pilaAmbitos->value(i);
        }
    }
}

QString primerRecorrido:: getClaseActual()
{
    return this->pilaAmbitos->value(this->pilaAmbitos->count()-1);
}



void primerRecorrido:: crearFuncion(nodo raizActual)
{    
    Simbolo *funcion = new Simbolo();
    funcion->rol = "metodo";
    funcion->visibilidad = raizActual.hijos.value(0).valor.toLower();
    funcion->tipo = raizActual.hijos.value(1).valor.toLower();
    funcion->nombre = raizActual.valor.toLower();
    funcion->linea = raizActual.linea;
    funcion->columna = raizActual.columna;
    funcion->ambito = ambitoActual;
    funcion->dimension = 0;
    funcion->tamano = 0;
    funcion->direccionGlobal = contadorSimbolos;
    /*Obtenemos el id según el numero de parametros.*/
    QString id = funcion->nombre;
    for(int i = 0; i<raizActual.hijos.value(2).hijos.count(); i++)
    {
        id = id + "$" + raizActual.hijos.value(2).hijos.value(i).tipo.toLower();
    }
    funcion->id = id;
    int resultado = this->tabla->agregarFuncion(*funcion, &raizActual);
    if(resultado == 1)
    {
        /*Agregamos los parametros a la tabla de símbolos*/
        pilaAmbitos->append(funcion->id);
        getAmbitoActual();
        contadorFuncion = 0;
        if(raizActual.hijos.count()==4)
        {
            crearParametros(raizActual.hijos[2]); // Parametros
            interpretar(raizActual.hijos[3]);
        }
        if(raizActual.hijos.count()==5)
        {
            crearParametros(raizActual.hijos[3]); // Parametros
            interpretar(raizActual.hijos[4]);
        }
        funcion->tamano = contadorFuncion;
        actualizarTamano(*funcion);
        pilaAmbitos->pop_back();
        getAmbitoActual();
    }

}

void primerRecorrido:: crearConstructor(nodo raizActual)
{

    Simbolo *constructor = new Simbolo();
    constructor->rol = "metodo";
    constructor->visibilidad = raizActual.hijos.value(0).valor.toLower();
    constructor->id = raizActual.hijos.value(2).valor.toLower();
    constructor->nombre = raizActual.valor.toLower();
    constructor->tipo =getClaseActual();
    constructor->linea = raizActual.linea;
    constructor->columna = raizActual.columna;
    constructor->ambito = ambitoActual;
    constructor->dimension = 0;
    constructor->direccionGlobal = contadorSimbolos;
    /*Obtenemos el id según el numero de parametros.*/
    QString id = constructor->nombre;
    for(int i = 0; i<raizActual.hijos.value(1).hijos.count(); i++)
    {
        id = id + "$" + raizActual.hijos.value(1).hijos.value(i).tipo.toLower();
    }
    constructor->id = id;
    int resultado = this->tabla->agregarFuncion(*constructor, &raizActual);
    if(resultado == 1)
    {
        /*Agregamos los parametros a la tabla de símbolos*/
        pilaAmbitos->append(constructor->id);
        getAmbitoActual();
        crearParametros(raizActual.hijos[1]); // Parametros
        interpretar(raizActual.hijos[2]);
        constructor->tamano = contadorFuncion;
        actualizarTamano(*constructor);
        pilaAmbitos->pop_back();
        getAmbitoActual();
    }

}


void primerRecorrido:: crearParametros(nodo raizActual)
{
    for(int i = 0; i<raizActual.hijos.count(); i++)
    {
        nodo nodoPar = raizActual.hijos.value(i);
        Simbolo *parametro = new Simbolo();
        parametro->id =ambitoActual +"$" + nodoPar.valor;
        parametro->nombre = nodoPar.valor;
        parametro->tipo = nodoPar.tipo;
        parametro->rol = "parametro";
        parametro->ambito = ambitoActual;
        parametro->dimension = nodoPar.hijos.count();
        parametro->tamano = 1;
        parametro->direccionGlobal = contadorSimbolos;
        int tamano = 1;
        for(int j = 0; j<nodoPar.hijos.count(); j++) // para contar las dimensiones.
        {
            nodo nodoDim = nodoPar.hijos.value(j);
            if(nodoDim.hijos.value(0).tipo.toLower() == "entero")
            {
                tamano = tamano * nodoDim.hijos.value(0).tipo.toInt();
            }
            else
            {
                errorT *error = new errorT("Semantico", "Se esperaba un valor entero para esta dimensión.",nodoDim.hijos.value(0).linea,nodoDim.hijos.value(0).columna);
                listaErrores->append(*error);
            }
        }
        parametro->tamano  = tamano;
        nodo puntero = raizActual.hijos.value(i);
        nodo *pt = & puntero;
        int resultado = this->tabla->agregarVariable(*parametro, pt);
        contadorSimbolos++;
        contadorClase++;
        contadorFuncion++;
    }
}


void primerRecorrido:: crearVariable(nodo raizActual)
{
    Simbolo *variable = new Simbolo();
    variable->ambito = ambitoActual;
    variable->rol = "variable";
    variable->id = raizActual.hijos.value(2).valor.toLower();
    variable->nombre = raizActual.hijos.value(2).valor.toLower();
    variable->visibilidad = raizActual.hijos.value(0).valor.toLower();
    variable->tipo = raizActual.hijos.value(1).valor.toLower();
    variable->dimension = 0;
    variable->tamano = 1;
    variable->direccionGlobal = contadorSimbolos;
    if(raizActual.hijos.count()==4) // Es un array
    {
        variable->dimension = raizActual.hijos[3].hijos.count();
        for(int i=0; i < raizActual.hijos[3].hijos.count(); i++)
        {
            variable->tamano = variable->tamano * raizActual.hijos[3].hijos[i].valor.toInt();
        }
    }
    int resultado = this->tabla->agregarVariable(*variable, &raizActual);
    contadorSimbolos++;
    contadorClase++;
    contadorFuncion++;
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
