#include "errorT.h"


errorT::errorT()
{
    tipo = "";
    this->desc="";
    this->linea=0;
    this->columna =0 ;
}


errorT::errorT(QString tipo, QString desc, int linea, int columna)
{
    this->tipo = tipo;
    this->desc=desc;
    this->linea= linea;
    this->columna = columna;
}
