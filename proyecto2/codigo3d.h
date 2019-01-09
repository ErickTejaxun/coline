#ifndef CODIGO3D_H
#define CODIGO3D_H
#include <QString>

class Codigo3d
{
public:
    Codigo3d();
    QString cadena3d;
    int etiqueta;
    int temporal;
    QString genTemp();
    QString genEti();
};

#endif // CODIGO3D_H
