#ifndef OPERACIONES_H
#define OPERACIONES_H
#include <resultado.h>

class Operaciones
{
public:
    Operaciones();
    Resultado *aritmetica(nodo *raiz);
    Resultado *relacional(nodo *raiz,int flag);
    Resultado *logica(nodo *raiz,int flag);
    Resultado *acceso(nodo *raiz,QString);
    QString getCadena(Resultado *resultado);
    void addError(QString tipo, QString desc, int linea, int columna);
    QString almacenarCadena(QString cadena);
    Resultado *convertirAcadena(Resultado *resultado,nodo *raiz);
    QString concatenarNumeroCadena(Resultado *resultado1,Resultado *resultado2);
    QString concatenarCadenaNumero(Resultado *resultado1,Resultado *resultado2);
    Resultado *relacionalSimple(Resultado *resultado1,QString operador,Resultado *resultado2,QString tipos);
    Resultado *relacionalCadena(Resultado *resultado1,QString operador,Resultado *resultado2,QString tipos);


};

#endif // OPERACIONES_H
