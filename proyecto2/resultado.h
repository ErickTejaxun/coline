#ifndef RESULTADO_H
#define RESULTADO_H
#include <QString>
#include <nodo.h>

class Resultado
{
public:
    Resultado();
    Resultado(QString tipo,int tipo_,QString valor);
    Resultado(QString tipo,int tipo_,QString valor,QString etiV,QString etiF);
    QString valor;
    QString tipo;
    int tipo_;
    int ref;
    QString etiV;
    QString etiF;

};

#endif // RESULTADO_H
