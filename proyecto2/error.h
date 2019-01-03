#ifndef ERROR_H
#define ERROR_H
#include <QString>

class Error
{
public:
    Error();
    Error(QString tipo, QString desc, int linea, int columna);
    QString tipo;
    QString desc;
    int linea;
    int columna;
};



#endif // ERROR_H
