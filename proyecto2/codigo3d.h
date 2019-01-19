#ifndef CODIGO3D_H
#define CODIGO3D_H
#include <QString>
#include <simbolo.h>
#include <resultado.h>

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
    Simbolo getSimboloDeclaracion(QString nombre);
    QString getMetodoActual();
    void apilarTamanoDimension(QString idVariable , QString temporal);
    void copiarPila(QList<QString> *actual,QList<QString> *nueva);
    int getIndiceAtributo(QString nombre,QString clase);
    QList<Simbolo> obtenerListaAtributos(QString nombreClase);
    Simbolo getAtributoClase(QString nombre,QString clase);
    Simbolo getClase(QString nombre);
    QString  getClaseActual();
    int NADA_;
    int ID_ = 0 ;
    int SENTENCIAS_ = 1;
    int IMPRIMIR_ = 2;
    int CONCATENAR_ =3;
    int IMPORTAR_ = 4;
    int PATH_ = 5;
    int INSTRUCCIONES_ = 6;
    int SOBRESCRIBIR_ = 7;
    int DETENER_ =8;
    int CONTINUAR_ = 9;
    int MOSTRAREDD_ = 10;
    int LEER_ = 11;
    int PARA_ = 12;
    int HACER_ = 13;
    int MIENTRAS_ = 14;
    int SELECCION_ = 15;
    int SI_ = 16;
    int SINOSI_ = 17;
    int SELECCIONA_ = 18;
    int CASO_ = 19;
    int DEFECTO_ = 20;
    int CASOS_  = 21;
    int RETORNO_ = 22;
    int DECLATRIB_ = 23;
    int PUBLICO_ = 24;
    int PRIVADO_ = 25;
    int PROTEGIDO_ = 26;
    int CONSTRUCTOR_ = 27;
    int LPAR_ = 28;
    int PARAMETROS_ = 29;
    int PRINCIPAL_ = 30;
    int FUNCION_ = 31;
    int DIMS_ = 32;
    int DIM_ = 33;
    int CLASE_ = 34;
    int HERENCIA_ = 35;
    int VARIABLE_ = 36;
    int ASIGA_ = 37;
    int ASIG_ = 38;
    int D_ = 38; // declaración
    int DA_= 39; // declaración con asignacion.
    int DAR_ = 40; // declaración array
    int DARA_ = 41; // declaración array con asignación para cadenas
    int LVALORES_ = 42; // Lista de valores funcion(1;3;4;arg5)
    int VALORES_ = 43;
    int DARAR_ = 44; //  darar declaracion array asignacion -- para arrays
    int TBOOLEANO_ = 45;
    int TENTERO_ = 46;
    int TCARACTER_ = 47;
    int TOBJETO_ = 48;
    int SS_ = 49; //       expl?  valor1:valor2;
    int EXPL_ = 50;
    int EXPR_ = 51;
    int EXPA_ = 52;
    int CONVERTIRACADENA_ = 53;
    int CONVERTIRAENTERO_ = 54;
    int LLAMADA_ = 55;
    int AUMENTO_ = 56;
    int DECREMENTO_ = 57;
    int IDV_ = 58;
    int ACCESO_ =59;
    //int NADA_ = 60;
    int SETENTENCIASG = 61; // Setnencias globales. Raiz del archivo
    int SUMA_ = 62;
    int RESTA_ = 63;
    int MULTIPLICACION_ = 64;
    int DIVISION_ = 65;
    int MODULO_ = 66;
    int POTENCIA_ = 67;
    int MAYORQUE_ = 68;
    int MENORQUE_ = 69;
    int MENORIGUAL_ = 70;
    int MAYORIGUAL_ = 71;
    int IGUAL_ = 72;
    int DESIGUAL_ = 73;
    int AND_ = 74;
    int OR_ = 75;
    int NO_ = 76;
    int TCADENA_ = 77;
    int TNADA_ = 78;
    int ACCESOARRAY_ = 79;
    int TDECIMAL_=80;
    int LACCESO_ = 81;
};

#endif // CODIGO3D_H
