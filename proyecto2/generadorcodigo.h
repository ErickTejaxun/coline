#ifndef GENERADORCODIGO_H
#define GENERADORCODIGO_H
#include <qstring.h>
#include <nodo.h>
#include <simbolo.h>

class GeneradorCodigo
{
public:
    GeneradorCodigo();    
    void Init();
    void generarCodigo(nodo raiz);
    QString generarEtiqueta();
    QString generarTemporal();
    Simbolo getConstructor(QString id);
    void crearClase(nodo raiz);
    void crearVariable(nodo raiz);
    void crearConstructor(nodo raiz);
    void crearParametros(nodo raiz);
    void crearFuncion(nodo raiz);
    void getAmbitoActual();
    void actualizarTamano(Simbolo sim);
    void actualizarContadores(int tamano);
    void declararArreglo(nodo raiz);
    void declararSi(nodo raiz);
    void declararSeleccionar(nodo raiz);
    void declararVariable(nodo raiz);
    void declararMientras(nodo raiz);
    void declararHacer(nodo raiz);
    void declararPara(nodo raiz);
    void declararParametro(nodo raiz);
    QString getClaseActual();
    QString escapar(QString cadena);
    QString ambitoActual;
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
};

#endif // GENERADORCODIGO_H
