#ifndef GRAFICADOR_H
#define GRAFICADOR_H
#include "nodo.h"
#include <fstream>
#include <iostream>
class graficador
{
public:
    graficador();
    graficador(nodo *raiz);
    nodo *raiz;
    int contador;
    QString grafo;
    QString graficar();
    void recorrerAST(QString padre, nodo *hijo);
    QString escapar(QString cadena);
    void generarImagen();

};

#endif // GRAFICADOR_H
