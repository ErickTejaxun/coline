#include "nodo.h"


nodo::nodo()
{        
    tipo ="";
    valor = "";
    linea = 0;
    columna = 0;    
    hijos =  QList<nodo>();
}

nodo::nodo(QString etiqueta, QString valor)
{
    nodo();
    this->tipo = etiqueta;
    this->valor = valor;    
}

nodo::nodo(QString tipo, QString valor, int linea, int columna)
{
    nodo();
    this->tipo = tipo;
    this->valor = valor;
    this->columna = columna;
    this->linea = linea;
    this->tipo_ = getTipo();
}

nodo::nodo(int tipo, QString valor, int linea, int columna)
{
    nodo();
    this->tipo_ = tipo;
    this->valor = valor;
    this->columna = columna;
    this->linea = linea;
}

void nodo::add(nodo nd)
{
    this->hijos.append(nd);
}

nodo::nodo(QString etiqueta)
{
    nodo();
    this->tipo = etiqueta;    
}

int nodo::getTipo()
{
    if(this->tipo=="sentencias"){return 1;}
    if(this->tipo=="imprimir"){return 2;}
    if(this->tipo=="concatenar"){return 3;}
    if(this->tipo=="importar"){return 4;}
    if(this->tipo=="path"){return 5;}
    if(this->tipo=="instrucciones"){return 6;}
    if(this->tipo=="sobrescribir"){return 7;}
    if(this->tipo=="detener"){return 8;}
    if(this->tipo=="continuar"){return 9;}
    if(this->tipo=="mostraredd"){return 10;}
    if(this->tipo=="leer"){return 11;}
    if(this->tipo=="para"){return 12;}
    if(this->tipo=="hacer"){return 13;}
    if(this->tipo=="mientras"){return 14;}
    if(this->tipo=="seleccion"){return 15;}
    if(this->tipo=="si"){return 16;}
    if(this->tipo=="sinosi"){return 17;}
    if(this->tipo=="selecciona"){return 18;}
    if(this->tipo=="caso"){return 19;}
    if(this->tipo=="defecto"){return 20;}
    if(this->tipo=="casos"){return 21;}
    if(this->tipo=="retorno"){return 22;}
    if(this->tipo=="declatrib"){return 23;}
    if(this->tipo=="publico"){return 24;}
    if(this->tipo=="privado"){return 25;}
    if(this->tipo=="protegido"){return 26;}
    if(this->tipo=="constructor"){return 27;}
    if(this->tipo=="lpar"){return 28;}
    if(this->tipo=="parametros"){return 29;}
    if(this->tipo=="principal"){return 30;}
    if(this->tipo=="funcion"){return 31;}
    if(this->tipo=="dims"){return 32;}
    if(this->tipo=="dim"){return 33;}
    if(this->tipo=="clase"){return 34;}
    if(this->tipo=="herencia"){return 35;}
    if(this->tipo=="variable"){return 36;}
    if(this->tipo=="asig"){return 37;}
    if(this->tipo=="d"){return 38;}
    if(this->tipo=="da"){return 39;}
    if(this->tipo=="dar"){return 40;}
    if(this->tipo=="dara"){return 41;}
    if(this->tipo=="lvalores"){return 42;}
    if(this->tipo=="valores"){return 43;}
    if(this->tipo=="darar"){return 44;}
    if(this->tipo=="tipobooleano"){return 45;}
    if(this->tipo=="tipoentero"){return 46;}
    if(this->tipo=="tipocaracter"){return 47;}
    if(this->tipo=="tipoobjeto"){return 48;}
    if(this->tipo=="ss"){return 49;}
    if(this->tipo=="expl"){return 50;}
    if(this->tipo=="expr"){return 51;}
    if(this->tipo=="expa"){return 52;}
    if(this->tipo=="convertiracadena"){return 53;}
    if(this->tipo=="convertiraentero"){return 54;}
    if(this->tipo=="llamada"){return 55;}
    if(this->tipo=="aumento"){return 56;}
    if(this->tipo=="decremento"){return 57;}
    if(this->tipo=="idv"){return 58;}
    if(this->tipo=="acceso"){return 59;}
    if(this->tipo=="nada"){return 60;}
    if(this->tipo=="sentenciag"){return 61;}
     return 0;
}





















