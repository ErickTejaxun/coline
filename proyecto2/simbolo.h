#ifndef SIMBOLO_H
#define SIMBOLO_H
#include <qstring.h>
#include <nodo.h>

class Simbolo
{
public:
    Simbolo();
    Simbolo(QString nombre, QString tipo, QString rol, QString ambito, int direccionGlobal, int tamanio, int dim, int ref);
    Simbolo(QString nombre, QString tipo, QString rol, QString ambito, int direccionGlobal, int tamanio, int dim, int ref, int linea, int columna, nodo * raiz, int inicializacion);
    void setValores(QString nombre, QString id, QString ambito, QString nivel, QString tipo, QString rol, int tamanio, QString visibilidad, int hereado, int sobrescribir);
    void setValores(QString nombre,QString id,QString ambito,QString nivel, int posicion,QString tipo, QString rol, int tamano,QString visibilidad,int heredado,int sobreescribir,int dimensiones);
    QString nombre;
    QString id;
    QString nivel;
    QString visibilidad;
    int sobrescribir; // 0 falso, 1 verdadero
    int heredado; //  0 falso, 1 verdadero
    QString tipo;
    QString rol;
    QString ambito;
    int inicializado;
    int direccionGlobal; // dentro del ambito
    int direccionLocal;
    int dimension;
    int referencia; // 0 es por valor, 1 es por referencia.
    int linea;
    int columna;
    int tamano;
    int isArray; // 0 No, 1 yes.
    QString padre;
    int herencia;
    int sobrescrito;
    nodo raiz;
    QList<QString> listaDimensiones;
    int getTipo();
};

#endif // SIMBOLO_H
