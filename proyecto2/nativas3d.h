#ifndef NATIVAS3D_H
#define NATIVAS3D_H
#include <QString>

class Nativas3d
{
public:
    Nativas3d();
    QString genEti();
    QString genTemp();
    void concatenar();
    void coreIgualIgual();
    void coreNoIgual();
    void coreMayor();
    void coreMayorIgual();
    void imprimir();
    void booleanoToCadena();
    void numeroToCadena();
    void concatenarTipo2();
    void convertirAentero();
    void getPesoCadena();
    int temporal;
    int etiqueta;
    QString cadena3d;
};

#endif // NATIVAS3D_H
