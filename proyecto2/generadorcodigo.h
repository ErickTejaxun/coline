#ifndef GENERADORCODIGO_H
#define GENERADORCODIGO_H
#include <qstring.h>
#include <nodo.h>
#include <simbolo.h>
enum Choice
{
    ID_ = 0 ,
    SENTENCIAS_ = 1,
    IMPRIMIR_ = 2,
    CONCATENAR_ =3,
    IMPORTAR_ = 4,
    PATH_ = 5,
    INSTRUCCIONES_ = 6,
    SOBRESCRIBIR_ = 7,
    DETENER_ =8,
    CONTINUAR_ = 9,
    MOSTRAREDD_ = 10,
    LEER_ = 11,
    PARA_ = 12,
    HACER_ = 13,
    MIENTRAS_ = 14,
    SELECCION_ = 15,
    SI_ = 16,
    SINOSI_ = 17,
    SELECCIONA_ = 18,
    CASO_ = 19,
    DEFECTO_ = 20,
    CASOS_  = 21,
    RETORNO_ = 22,
    DECLATRIB_ = 23,
    PUBLICO_ = 24,
    PRIVADO_ = 25,
    PROTEGIDO_ = 26,
    CONSTRUCTOR_ = 27,
    LPAR_ = 28,
    PARAMETROS_ = 29,
    PRINCIPAL_ = 30,
    FUNCION_ = 31,
    DIMS_ = 32,
    DIM_ = 33,
    CLASE_ = 34,
    HERENCIA_ = 35,
    VARIABLE_ = 36,
    ASIGA_ = 37,
    ASIG_ = 38,
    D_ = 38, // declaración
    DA_= 39, // declaración con asignacion.
    DAR_ = 40, // declaración array
    DARA_ = 41, // declaración array con asignación para cadenas
    LVALORES_ = 42, // Lista de valores funcion(1,3,4,arg5)
    VALORES_ = 43,
    DARAR_ = 44, //  darar declaracion array asignacion -- para arrays
    TBOOLEANO_ = 45,
    TENTERO_ = 46,
    TCARACTER_ = 47,
    TOBJETO_ = 48,
    SS_ = 49, //       expl?  valor1:valor2;
    EXPL_ = 50,
    EXPR_ = 51,
    EXPA_ = 52,
    CONVERTIRACADENA_ = 53,
    CONVERTIRAENTERO_ = 54,
    LLAMADA_ = 55,
    AUMENTO_ = 56,
    DECREMENTO_ = 57,
    IDV_ = 58,
    ACCESO_ =59,
    NADA_ = 60,
    SETENTENCIASG = 61, // Setnencias globales. Raiz del archivo
    SUMA_ = 62,
    RESTA_ = 63,
    MULTIPLICACION_ = 64,
    DIVISION_ = 65,
    MODULO_ = 66,
    POTENCIA_ = 67,
    MAYORQUE_ = 68,
    MENORQUE_ = 69,
    MENORIGUAL_ = 70,
    MAYORIGUAL_ = 71,
    IGUAL_ = 72,
    DESIGUAL_ = 73,
    AND_ = 74,
    OR_ = 75,
    NO_ = 76,
    TCADENA_ = 77,
    TNADA_ = 78,
    ACCESOARRAY_ = 79,
    TDECIMAL_ = 80,
    LACCESO_ = 81,
};

class GeneradorCodigo
{
public:
    GeneradorCodigo();    
    void Init();
    void generarCodigo(nodo raiz);
    QString generarEtiqueta();
    QString generarTemporal();
    Simbolo getConstructor(QString id);
    int existeConstructor(QString nombreClase);
    void generarCodigoClase(nodo raiz);
    void crearAtributo(nodo raiz);
    void crearConstructor(nodo raiz);
    void crearParametros(nodo raiz);
    void crearFuncion(nodo raiz);
    void getAmbitoActual();
    void actualizarTamano(Simbolo sim);
    void actualizarContadores(int tamano);
    void declararArreglo(nodo raiz);
    void declararSi(nodo raiz);
    void declararSeleccionar(nodo raiz);
    void declararVariable(nodo raiz);
    void declararMientras(nodo raiz);
    void declararHacer(nodo raiz);
    void declararPara(nodo raiz);
    void declararParametro(nodo raiz);
    void generarCodigoLlamadaAConstructor(QString direccionHeap, int i, Simbolo atributo);
    void generarCodigoAcceso(QString direccionHeap, int indice, Simbolo atributo);
    void generarCodigoDeclaracion(nodo raizActual);
    QString getClaseActual();
    void generarConstructor(nodo raizActual);
    QString obtenerIdMetodo(nodo raizActual);
    void generarLlamada(nodo raizActual);
    void generarFuncion(nodo raizActual);
    QString escapar(QString cadena);
    QString ambitoActual;
    QList<Simbolo> obtenerListaAtributos(QString nombreClase);
    QList<Simbolo> getListaConstructores(QString nombreFunciones);
    Simbolo getClase(QString nombre);
    Simbolo getMetodo(QString nombre);
    int existeMetodo(QString idMetodo);
    QList<QString> *pilaAmbitos;
    int contadorIf;
    int contadorPara;
    int contadorElseIf;
    int contadorElse;
    int contadorWhile;
    int contadorDoWhile;
    int contadorSeleccionar;
    int contadorSimbolos; // para contar los simbolos totales
    int contadorFuncion; // para contar funicon
    int contadorClase; // Tamaño de la clase
    int tamanoActual;
};

#endif // GENERADORCODIGO_H
