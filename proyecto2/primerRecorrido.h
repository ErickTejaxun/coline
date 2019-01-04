#ifndef INTERPRETE_H
#define INTERPRETE_H
#include <nodo.h>
#include <QFile>
#include <mainwindow.h>
#include <nodo.h>
#include <errorT.h>
#include <parser.h>
#include <scanner.h>

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
    QString escapar(QString cadena);
    nodo raiz;
};

#endif // INTERPRETE_H
