#ifndef CODIGO3D_H
#define CODIGO3D_H
#include <QString>
#include <simbolo.h>

class Codigo3d
{
public:
    Codigo3d();
    QString cadena3d;
    int etiqueta;
    int temporal;
    QString metodoActual;
    QList<QString> *pilaAmbitos;
    /*Metodos*/
    void apilarMetodo(QString nombreMetodo);
    void desapilarMetodo();
    QString genTemp();
    QString genEti();        
    QString getAmbitoActual();
    int getTamanoAmbitoActual();
    int getTamanoAmbitoActual(QString actual);
    Simbolo getSimboloPorId(QString id);
    Simbolo getSimboloPorNombre(QString nombre);
    QString getMetodoActual();
    int NADA_;
};

#endif // CODIGO3D_H
