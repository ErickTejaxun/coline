#ifndef INTERPRETE_H
#define INTERPRETE_H
#include <nodo.h>

class Interprete
{
public:
    Interprete();
    Interprete(nodo raiz);
    void interpretar();
    void interpretar(nodo * raiz);
    nodo raiz;
};

#endif // INTERPRETE_H
