#ifndef ERROR_H
#define ERROR_H
#include <QString>

class errorT
{
public:
    errorT();
    errorT(QString tipo, QString desc, int linea, int columna);
    QString tipo;
    QString desc;
    int linea;
    int columna;
};



#endif // ERROR_H
