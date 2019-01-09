#ifndef INTERPRETE_H
#define INTERPRETE_H
#include <nodo.h>
#include <QFile>
#include <mainwindow.h>
#include <nodo.h>
#include <errorT.h>
#include <parser.h>
#include <scanner.h>
#include <clase.h>
#include <tablasimbolos.h>

class primerRecorrido
{
public:
    primerRecorrido();
    int contT; // Temporales
    int contE; // Etiquetas
    void interpretar(QList<nodo> * listaArboles);
    void interpretar(nodo raiz);
    QString generarEtiqueta();
    QString generarTemporal();
    void importar(nodo raiz); // Funcion importar :v
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
    QList<Clase> *listaClases;
    tablaSimbolos *tabla;  
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
}
;

#endif // INTERPRETE_H
