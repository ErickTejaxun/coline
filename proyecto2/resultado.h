#ifndef RESULTADO_H
#define RESULTADO_H
#include <QString>
#include <nodo.h>

class Resultado
{
public:
    Resultado();
    Resultado(QString tipo,int tipo_,QString valor);
    QString valor;
    QString tipo;
    int tipo_;
    int ref;

};

#endif // RESULTADO_H
