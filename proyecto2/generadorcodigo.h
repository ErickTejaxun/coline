#ifndef GENERADORCODIGO_H
#define GENERADORCODIGO_H
#include <qstring.h>
#include <nodo.h>
#include <simbolo.h>
#include <resultado.h>


class GeneradorCodigo
{
public:
    GeneradorCodigo();    
    void Init();
    void generarCodigo(nodo raiz);
    QString generarEtiqueta();
    QString generarTemporal();
    Simbolo getConstructor(QString id);
    int existeConstructor(QString nombreClase);
    void generarCodigoClase(nodo raiz);
    void crearAtributo(nodo raiz);
    void crearConstructor(nodo raiz);
    void crearParametros(nodo raiz);
    void crearFuncion(nodo raiz);
    void getAmbitoActual();
    void actualizarTamano(Simbolo sim);
    void actualizarContadores(int tamano);    
    void declararSi(nodo raiz);
    void declararSeleccionar(nodo raiz);
    void declararVariableAsignacion(nodo raiz);
    void declararArregloAsignar(nodo raizActual);
    void declararVariable(nodo raiz);
    void declararArreglo(nodo raiz);
    void declararMientras(nodo raiz);
    void declararHacer(nodo raiz);
    void declararPara(nodo raiz);
    void declararParametro(nodo raiz);
    void generarCodigoLlamadaAConstructor(QString direccionHeap, int i, Simbolo atributo);
    void generarCodigoAcceso(QString direccionHeap, int indice, Simbolo atributo);
    void generarCodigoDeclaracion(nodo raizActual);
    void generarCodigoAtributos(nodo raizActual);
    void generarCodigoInstrucciones(nodo raizActual);
    QString getClaseActual();
    void generarConstructor(nodo raizActual);
    QString obtenerIdMetodo(nodo raizActual);
    void generarLlamada(nodo raizActual);
    void generarFuncion(nodo raizActual);
    QString escapar(QString cadena);
    QString ambitoActual;
    QList<Simbolo> obtenerListaAtributos(QString nombreClase);
    QList<Simbolo> getListaConstructores(QString nombreFunciones);
    Simbolo getClase(QString nombre);
    Simbolo getMetodo(QString nombre);
    int existeMetodo(QString idMetodo);
    QList<QString> *pilaAmbitos;
    int contadorIf;
    int contadorPara;
    int contadorElseIf;
    int contadorElse;
    int contadorWhile;
    int contadorDoWhile;
    int contadorSeleccionar;
    int contadorSimbolos; // para contar los simbolos totales
    int contadorFuncion; // para contar funicon
    int contadorClase; // Tamaño de la clase
    int tamanoActual;




    Resultado generarAcceso(nodo raiz);

};

#endif // GENERADORCODIGO_H
