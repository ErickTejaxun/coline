#include "resultado.h"

Resultado::Resultado()
{

}

Resultado::Resultado(QString tipo,int tipo_,QString valor)
{
    this->tipo=tipo;
    this->valor=valor;
    this->tipo_=tipo_;

}


Resultado::Resultado(QString tipo,int tipo_,QString valor,QString etiV,QString etiF)
{
    this->tipo=tipo;
    this->valor=valor;
    this->tipo_=tipo_;
    this->etiV=etiV;
    this->etiF=etiF;

}


