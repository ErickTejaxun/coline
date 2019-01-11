#ifndef OPERACIONES_H
#define OPERACIONES_H
#include <resultado.h>

class Operaciones
{
public:
    Operaciones();
    Resultado *aritmetica(nodo *raiz);
    QString getCadena(Resultado *resultado);
    void addError(QString tipo, QString desc, int linea, int columna);
    QString almacenarCadena(QString cadena);
};

#endif // OPERACIONES_H
