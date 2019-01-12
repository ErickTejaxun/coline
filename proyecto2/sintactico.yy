%{
#include "scanner.h"//se importa el header del analisis sintactico
#include <iostream> //libreria para imprimir en cosola de C
#include <QString> //libreria para manejo de STRINGS de QT
#include "nodo.h"
#include <QTextEdit> //libreria QTextEdit de QT para poder mostrar el resultado en pantalla
#include <errorT.h>
#include "qlist.h"


extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern nodo *raiz; // Raiz del arbol
extern QList<errorT> *listaErrores;
int yyerror(const char* mens)
{
    //metodo que se llama al haber un error sintactico
    //SE IMPRIME EN CONSOLA EL ERROR
    //std::cout <<mens<<"-----"<<yytext<< std::endl;
    std::cout << mens <<"----"<<yytext<< " En la linea:" << yylineno  << "columna:" << columna<<std::endl;
    errorT * nuevo = new errorT("Sintactico",mens,yylineno, columna);
    listaErrores->append(*nuevo);
    //Error(QString tipo, QString desc, int linea, int columna);
    return 0;
}


QTextEdit * salida;
%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%error-verbose
%locations

%union{
//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class nodo *nodito;
}

//TERMINALES DE TIPO TEXT, SON STRINGS
%token<TEXT> entero;
%token<TEXT> decimal;
%token<TEXT> caracter;
%token<TEXT> booleano;
%token<TEXT> cadena;
%token<TEXT> id;
%token<TEXT> parA;
%token<TEXT> parC;
%token<TEXT> illave;
%token<TEXT> fllave;
%token<TEXT> iCor;
%token<TEXT> fCor;
%token<TEXT> dosP;
%token<TEXT> coma;
%token<TEXT> aumento;
%token<TEXT> decremento;
%token<TEXT> masigual;
%token<TEXT> porigual;
%token<TEXT> menosigual;
%token<TEXT> divigual;
%token<TEXT> suma;
%token<TEXT> menos;
%token<TEXT> multi;
%token<TEXT> division;
%token<TEXT> potencia;
%token<TEXT> mayor;
%token<TEXT> menor;
%token<TEXT> mayorigual;
%token<TEXT> menorigual;
%token<TEXT> igualigual;
%token<TEXT> desigual;
%token<TEXT> o;
%token<TEXT> y;
%token<TEXT> igual;
%token<TEXT> no;
%token<TEXT> interrogacion;
%token<TEXT> tipoBooleano;
%token<TEXT> tipoEntero;
%token<TEXT> tipoCaracter;
%token<TEXT> tipoDecimal;
%token<TEXT> imprimir;
%token<TEXT> concatenar;
%token<TEXT> tamanio;
%token<TEXT> verdadero;
%token<TEXT> falso;
%token<TEXT> convertirAcadena;
%token<TEXT> convertirAentero;
%token<TEXT> clase;
%token<TEXT> este;
%token<TEXT> publico;
%token<TEXT> privado;
%token<TEXT> protegido;
%token<TEXT> vacio;
%token<TEXT> heredade;
%token<TEXT> retornar;
%token<TEXT> importar;
%token<TEXT> sobreescribir;
%token<TEXT> principal;
%token<TEXT> nuevo;
%token<TEXT> nada;
%token<TEXT> detener;
%token<TEXT> continuar;
%token<TEXT> si;
%token<TEXT> sinosi;
%token<TEXT> sino;
%token<TEXT> selecciona;
%token<TEXT> caso;
%token<TEXT> defecto;
%token<TEXT> mientras;
%token<TEXT> hacer;
%token<TEXT> para;
%token<TEXT> lista;
%token<TEXT> insertar;
%token<TEXT> obtener;
%token<TEXT> buscar;
%token<TEXT> pila;
%token<TEXT> apilar;
%token<TEXT> desapilar;
%token<TEXT> cola;
%token<TEXT> encolar;
%token<TEXT> desencolar;
%token<TEXT> mostraredd;
%token<TEXT> leer_teclado;
%token<TEXT> puntoComa;
%token<TEXT> punto;
%token<TEXT> modulo;


%start INICIO

//NO TERMINALES DE TIPO VAL, POSEEN ATRIBUTOS INT VALOR, Y QSTRING TEXTO


//no terminales de tipo objeto

%type<nodito> INICIO;//
%type<nodito> EXPA; // Aritmetica
%type<nodito> EXPR; // Relacional
%type<nodito> EXPL; // Logica
%type<nodito> UNARIOS;
%type<nodito> DECLARACION;
%type<nodito> TIPO;
%type<nodito> SENTENCIASG;  // Lista de sentencias en la raíz del documento
%type<nodito> SENTENCIAS;   // Lista de sentencias dentro de un método.
%type<nodito> DECLARACIONARRAY;
%type<nodito> DIMENSIONES;
%type<nodito> VALORESA; // VALORES ARRAY
%type<nodito> LVALORES;
%type<nodito> VALORES;
%type<nodito> INSTRUCCIONG; // Instrucción global
%type<nodito> INSTRUCCION; // Instrucción dentro de los métodos;
%type<nodito> ASIGNACION;
%type<nodito> TIPOASIG;
%type<nodito> SENTSELEC;
%type<nodito> ACCESO;
%type<nodito> VALAS; // Valor a asignar. Puede ser una expl o bien una sentencia de selccion a==10? 10:20;
%type<nodito> CONCATENAR;
%type<nodito> IMPRIMIR;
%type<nodito> VISIBILIDAD;
%type<nodito> ATRIBUTO;
//%type<nodito> ATRIBUTOS; // LISTA DE ATRIBUTOS
%type<nodito> CLASE;
%type<nodito> ICLASE; // Instruccion clase
%type<nodito> ICLASES; // Lista de instrucciones
%type<nodito> IMPORTAR;
//%type<nodito> TIPOR; // TIPO DE RETORNO
%type<nodito> FUNCION;
%type<nodito> PARAMETRO;
%type<nodito> PARAMETROS;
%type<nodito> LPARAMETROS; // Auxiliar, porque puede venir vacia
%type<nodito> RETORNO;
%type<nodito> DIM; //[]
%type<nodito> DIMS; //[][][]... para el tipo de función.
%type<nodito> LLAMADA;
%type<nodito> LPAR;
%type<nodito> PRINCIPAL;
%type<nodito> CONSTRUCTOR;
%type<nodito> INSTANCIA;
%type<nodito> MIENTRAS;
%type<nodito> SI;
%type<nodito> ELSE;
%type<nodito> SINOSI;
%type<nodito> SELECCIONAR;
%type<nodito> CASO;
%type<nodito> LCASOS;
%type<nodito> CASOS;
%type<nodito> HACER;
%type<nodito> PARA;
%type<nodito> DECESTRUCTURAS;
%type<nodito> LEER;
//%type<nodito> ACC;
//LOS NO TERMINALES PUEDEN SER DE DIFERENTE TIPO, LOS TERMINALES SIEMPRE SON STRINGS O NO SE ESPECIFICA TIPO
//PRECEDENCIA DE LOS OPERADORES PARA QUITAR LA AMBIGUEDAD DEN LA GRAMTICA
%left suma menos
%left multi division modulo
%left potencia
%left aumento decremento
%left igualigual desigual menor mayor menorigual mayorigual
%left o
%left y
%left no
//%left parA parC
%%

/*INICIO: EXPA{ $$ = $1;};*/
INICIO : SENTENCIASG {$$=$1; raiz = $$;};

SENTENCIASG:   SENTENCIASG INSTRUCCIONG{ $$ = $1; $$->add(*$2);}
            | INSTRUCCIONG { nodo *nuevo = new nodo("sentenciasg","sentenciasg",yylineno, columna); nuevo->add(*$1); $$ = nuevo;}
;

INSTRUCCIONG:
              IMPORTAR puntoComa{$$=$1;}
            | CLASE{$$ = $1;}
              ;

IMPRIMIR: imprimir parA EXPL parC
              {
                  $$ = new nodo("imprimir",$1,yylineno,columna);
                  $$->hijos.append(*$3);
              }
            |imprimir parA CONCATENAR parC
              {
                  $$ = new nodo("imprimir",$1,yylineno,columna);
                  $$->hijos.append(*$3);
              };

CONCATENAR:
              concatenar parA EXPL coma EXPL parC
              {
                  $$ = new nodo("concatenar",$1, yylineno, columna);
                  $$->hijos.append(*$3);
                  $$->hijos.append(*$5);
              }
              //Concatenar (identificador,cadena,Expresion);
              |concatenar parA EXPL coma EXPL  coma EXPL parC
              {
                  $$ = new nodo("concatenar",$1, yylineno, columna);
                  $$->hijos.append(*$3);
                  $$->hijos.append(*$5);
                  $$->hijos.append(*$7);
              }
              ;

IMPORTAR : importar parA cadena parC
              {
                $$ = new nodo("importar",$1,yylineno,columna);
                nodo *ruta = new nodo("path",$3,yylineno,columna);
                $$->hijos.append(*ruta);
              };

// Clases----------------------------------------------------------------------

// INSTRUCCIONES DE CLASE
ICLASES :
        ICLASES ICLASE
        {
         $$=$1;
         $$->hijos.append(*$2);
        }
        |ICLASE
          {
             $$ = new nodo("instrucciones","instrucciones",yylineno,columna);
             $$->hijos.append(*$1);
          }
        ;

ICLASE:
        FUNCION
        {
            $$=$1;
            nodo *sobre = new nodo("sobrescribir","no",yylineno,columna);
            $$->hijos.prepend(*sobre);
        } // Estas van en la cabecera. O bien no dentro de algún metodo.
       |sobreescribir FUNCION
       {
            $$=$2;
            nodo *sobre = new nodo("sobrescribir","sobrescribir",yylineno,columna);
            $$->hijos.prepend(*sobre);
       } // Estas van en la cabecera. O bien no dentro de algún metodo.
       |ATRIBUTO{$$=$1;}
       | PRINCIPAL {$$= $1;}
       | CONSTRUCTOR {$$=$1;}
       | sobreescribir CONSTRUCTOR
        {
             $$=$2;
             nodo *sobre = new nodo("sobrescribir","sobrescribir",yylineno,columna);
             $$->hijos.prepend(*sobre);
        } // Estas van en la cabecera. O bien no dentro de algún metodo.
        ;


SENTENCIAS: SENTENCIAS INSTRUCCION{ $$ = $1; $$->add(*$2);}
              |INSTRUCCION { nodo *nuevo = new nodo("sentencias","sentencias",yylineno, columna); nuevo->add(*$1); $$ = nuevo;}
              ;

INSTRUCCION:    DECLARACION puntoComa { $$ = $1;}
              | DECLARACIONARRAY puntoComa{ $$ = $1;}
              | ASIGNACION puntoComa {$$ = $1;}
              | CONCATENAR puntoComa {$$ = $1;}
              | IMPRIMIR puntoComa {$$ = $1;}
              | RETORNO puntoComa {$$=$1;}
              //| INSTANCIA puntoComa{$$=$1;}
              | LLAMADA puntoComa {$$=$1;}
              | MIENTRAS {$$=$1;}
              | SI {$$=$1;}
              | UNARIOS puntoComa{$$=$1;}
              |SELECCIONAR {$$=$1;}
              | HACER puntoComa {$$=$1;}
              | PARA {$$=$1;}
              | detener puntoComa{ $$ = new nodo("detener","detener",yylineno,columna);}
              | continuar puntoComa{ $$ = new nodo("continuar","continuar",yylineno,columna);}
              | DECESTRUCTURAS puntoComa{$$=$1;}
              | mostraredd parA id parC puntoComa{ $$ = new nodo("mostraredd",$3,yylineno,columna);}
              |LEER puntoComa{ $$=$1;}
              ;


LEER: leer_teclado parA EXPL  coma EXPL parC
         {
            $$= new nodo("leer","leer",yylineno,columna);
            $$->hijos.append(*$3);
            $$->hijos.append(*$5);
         }
         ;

//para (entero cuenta = 0; cuenta <= 10; cuenta++) {
PARA: para parA ASIGNACION puntoComa EXPL puntoComa ASIGNACION parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",yylineno,columna);
            $$->hijos.append(*$3);// Asignacion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // Asignacion
            $$->hijos.append(*$10); // Sentencias
        }
        | para parA DECLARACION puntoComa EXPL puntoComa ASIGNACION parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",yylineno,columna);
            $$->hijos.append(*$3);// Declaracion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // Asignacion
            $$->hijos.append(*$10); // Sentencias
        }
        |para parA ASIGNACION puntoComa EXPL puntoComa UNARIOS parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",yylineno,columna);
            $$->hijos.append(*$3);// Asignacion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // decremento / aumento
            $$->hijos.append(*$10); // Sentencias
        }
        | para parA DECLARACION puntoComa EXPL puntoComa UNARIOS  parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",yylineno,columna);
            $$->hijos.append(*$3);// Declaracion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // Asignacion
            $$->hijos.append(*$10); // Sentencias
        }
        ;


HACER: hacer illave SENTENCIAS fllave
        mientras parA EXPL parC
        {
            $$ = new nodo("hacer","hacer",yylineno,columna);
            $$->hijos.append(*$3);// sentencias
            $$->hijos.append(*$7);// condicion;
        }
        ;

MIENTRAS:
//mientras (cuenta <= 10) { si (cuenta == 5) { detener; } cuenta++; }
         mientras parA EXPL parC illave SENTENCIAS fllave
         {
           $$ = new nodo("mientras","mientras",yylineno,columna);
           $$->hijos.append(*$3); // Condicion
           $$->hijos.append(*$6);
         };


SI:
         si parA EXPL parC illave  SENTENCIAS fllave
         {
             $$ = new nodo("si","si",yylineno,columna);
             $$->hijos.append(*$3);// condicion
             $$->hijos.append(*$6); // Sentencias
         }
        |si parA EXPL parC illave  SENTENCIAS fllave ELSE
         {
             $$=$8;
             $$->tipo = "si";
             $$->valor = "si";
             $$->hijos.prepend(*$6); // Sentencias
             $$->hijos.prepend(*$3);// condicion
         }
         ;

ELSE:
         SINOSI
         sino illave SENTENCIAS fllave
          {
             $$=$1;
             $$->hijos.append(*$4);
          }
         |SINOSI
         {
             $$=$1;
         }
         |sino illave SENTENCIAS fllave
         {
            $$= $3;
         }
         ;

SINOSI: SINOSI sinosi parA EXPL parC illave SENTENCIAS fllave
         {
           $$=$1;
           $$->hijos.append(*$4); // condicion
           $$->hijos.append(*$7); // Sentenencias
         }
        |sinosi parA EXPL parC illave SENTENCIAS fllave
         {
           $$= new nodo("sinosi","sinosi",yylineno,columna);
           $$->hijos.append(*$3); // condicion
           $$->hijos.append(*$6); // Sentenencias
         };


SELECCIONAR:
         selecciona parA EXPL parC illave CASOS fllave
         {
             $$ = new nodo("selecciona",$1,yylineno,columna);
             $$->hijos.append(*$3);
             $$->hijos.append(*$6);
         }
         ;
CASOS: LCASOS defecto dosP illave SENTENCIAS fllave
     {
        $$=$1;
        nodo *def = new nodo("defecto","defecto",yylineno,columna);
        def->hijos.append(*$5);
        $$->hijos.append(*def);
     }
     |defecto dosP illave SENTENCIAS fllave
     {
        $$= new nodo("casos","casos",yylineno,columna);
        nodo *def = new nodo("caso","defecto",yylineno,columna);
        def->hijos.append(*$4);
        $$->hijos.append(*def);
     }
     ;


LCASOS:   LCASOS CASO
         {
             $$=$1;
             $$->hijos.append(*$2);
         }
         |CASO
         {
           $$= new nodo("casos","casos",yylineno,columna);
           $$->hijos.append(*$1);
         }

CASO: caso EXPL dosP illave SENTENCIAS fllave
         {
            $$ = new nodo("caso","caso",yylineno,columna);
            $$->hijos.append(*$2);
            $$->hijos.append(*$5);
         }
         ;

RETORNO: retornar EXPL
              {
                $$=new nodo("retorno","retorno",yylineno,columna);
                $$->hijos.append(*$2);
              }
              ;

ATRIBUTO:  VISIBILIDAD DECLARACION puntoComa
            {
                $$ = $2;
                $$->hijos.prepend(*$1);
                $$->tipo = "declatrib";
                $$->tipo_ = $$->getTipo();
            }
        |DECLARACION puntoComa
            {
                $$ = $1;
                nodo *nod = new nodo("publico","publico",yylineno, columna);
                $$->hijos.prepend(*nod);
                $$->tipo = "declatrib";
                $$->tipo_ = $$->getTipo();
            }
         |VISIBILIDAD DECLARACIONARRAY puntoComa
            {
             $$ = $2;
             $$->hijos.prepend(*$1);
             $$->tipo = "declatrib";
             $$->tipo_ = $$->getTipo();
            }
        |DECLARACIONARRAY puntoComa
        {
         $$ = $1;
         nodo *nod = new nodo("publico","publico",yylineno, columna);
         $$->hijos.prepend(*nod);
         $$->tipo = "declatrib";
         $$->tipo_ = $$->getTipo();
        }
         ;


VISIBILIDAD:
            publico {$$ = new nodo("publico",$1,yylineno, columna);}
           |privado {$$ = new nodo("privado",$1,yylineno, columna);}
           |protegido{$$ = new nodo("protegido",$1,yylineno, columna);}
            ;
INSTANCIA: nuevo id parA LPAR parC
            {
                 nodo *cons = new nodo("llamada",$2,yylineno,columna);
                 cons->hijos.append(*$4); // LISTA DE PARAMETROS
                 $$ = cons;
            }
            |nuevo id parA parC
            {
                 nodo *cons = new nodo("llamada",$2,yylineno,columna);
                 nodo *lpar = new nodo("lpar","lpar",yylineno,columna);
                 cons->hijos.append(*lpar); // LISTA DE PARAMETROS
                 $$ = cons;
            };

// METODOS
LPARAMETROS: PARAMETROS{$$=$1;}
            |
            {
                $$ = new nodo("parametros","parametros",0,0);
            }
            ;


PARAMETROS : PARAMETROS coma PARAMETRO
            {
                $$=$1;
                $$->hijos.append(*$3);
            }
            |PARAMETRO
            {
                $$ = new nodo("parametros","parametros",yylineno, columna);
                $$->hijos.append(*$1);
            }
            ;

PARAMETRO: TIPO id
            {
                $1->tipo = $1->valor;
                $1->valor = $2;
                $$ = $1;
            }
            |TIPO id DIMENSIONES
            {
                $1->tipo = $1->valor;
                $1->valor = $2;
                $$ = $1;
                $$->hijos.append(*$3);
            }
            ;

PRINCIPAL: principal parA parC illave SENTENCIAS fllave
           {

                $$ = new nodo("funcion",$1, yylineno, columna);
                nodo *sobre = new nodo("sobrescribir","no",yylineno,columna);
                $$->hijos.prepend(*sobre);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                $$->hijos.append(*vis);
                nodo *tipo = new nodo("tipo","",yylineno,columna);
                $$->hijos.prepend(*tipo);
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                $$->hijos.append(*dims);
                nodo *param = new nodo("parametros","parametros",0,0);
                $$->hijos.append(*param);
                $$->hijos.append(*$5);
           }
           |VISIBILIDAD principal parA parC illave SENTENCIAS fllave
                {

                     $$ = new nodo("funcion",$2, yylineno, columna);
                     nodo *sobre = new nodo("sobrescribir","no",yylineno,columna);
                     $$->hijos.prepend(*sobre);
                     $$->hijos.append(*$1);
                     nodo *tipo = new nodo("tipo","",yylineno,columna);
                     $$->hijos.prepend(*tipo);
                     nodo *dims= new nodo("dims","dims",yylineno, columna);
                     $$->hijos.append(*dims);
                     nodo *param = new nodo("parametros","parametros",0,0);
                     $$->hijos.append(*param);
                     $$->hijos.append(*$6);
                }                ;


CONSTRUCTOR: VISIBILIDAD id  parA  LPARAMETROS parC illave  SENTENCIAS fllave
                {
                    $$ = new nodo("constructor",$2,yylineno,columna);
                    $$->hijos.append(*$1); // visibilidad
                    $$->hijos.append(*$4); // parametros
                    $$->hijos.append(*$7); // instrucciones
                }
                |id parA  LPARAMETROS parC illave  SENTENCIAS fllave
                {
                    $$ = new nodo("constructor",$1,yylineno,columna);
                    nodo *vis = new nodo("visibilidad","publico",yylineno,columna);
                    $$->hijos.append(*vis); // visibilidad
                    $$->hijos.append(*$3);  // parametros
                    $$->hijos.append(*$6); // instrucciones
                }
                ;

FUNCION: VISIBILIDAD TIPO DIMS id  parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$4,yylineno,columna);
                $$->hijos.append(*$1); // visibilidad
                $$->hijos.append(*$2); // tipo
                $$->hijos.append(*$3); // dimensiones del retorno
                $$->hijos.append(*$6); // lista de parametros
                $$->hijos.append(*$9); // lista de instrucciones;
            }
            |VISIBILIDAD TIPO id  parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$3,yylineno,columna);
                $$->hijos.append(*$1); // visibilidad
                $$->hijos.append(*$2); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                $$->hijos.append(*dims);
                $$->hijos.append(*$5); // lista de parametros
                $$->hijos.append(*$8); // lista de instrucciones;
            }
            |VISIBILIDAD vacio id parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$3,yylineno,columna);
                $$->hijos.append(*$1); // visibilidad
                nodo *tipo = new nodo("tipo","vacio",yylineno,columna);
                $$->hijos.append(*tipo); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                $$->hijos.append(*dims);
                $$->hijos.append(*$5); // lista de parametros
                $$->hijos.append(*$8); // lista de instrucciones;
            }
            |TIPO  DIMS id   parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$3,yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                $$->hijos.append(*vis); // visibilidad
                $$->hijos.append(*$1); // tipo
                $$->hijos.append(*$2); // dimensiones del retorno
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                $$->hijos.append(*dims);
                $$->hijos.append(*$5); // lista de parametros
                $$->hijos.append(*$8); // lista de instrucciones;
            }
            |TIPO id   parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$2,yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                $$->hijos.append(*vis); // visibilidad
                $$->hijos.append(*$1); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                $$->hijos.append(*dims);
                $$->hijos.append(*$4); // lista de parametros
                $$->hijos.append(*$7); // lista de instrucciones;
            }
            |vacio id parA  LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$2,yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                $$->hijos.append(*vis); // visibilidad
                nodo *tipo = new nodo("tipo",$1,yylineno,columna);
                $$->hijos.append(*tipo); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                $$->hijos.append(*dims);
                $$->hijos.append(*$4); // lista de parametros.
                $$->hijos.append(*$7); // lista de instrucciones;
            }
            ;

DIMS: DIMS DIM
        {
             $$= $1;
             $$->hijos.append(*$2);
        }
     |DIM {
             $$= new nodo("dims","dims",yylineno, columna);
             $$->hijos.append(*$1);
          };

DIM: iCor fCor { $$ = new nodo("dim","dim",yylineno,columna);};

/*
TIPOR:  vacio {$$= new nodo("tipo",$1,yylineno,columna);}
       |TIPO {$$=$1;};*/


CLASE: VISIBILIDAD clase id illave ICLASES fllave
              {
                  $$ = new nodo("clase",$3,yylineno, columna);
                  $$->hijos.append(*$1);
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  $$->hijos.append(*her);
                  $$->hijos.append(*$5);
              }
        |clase id illave  ICLASES fllave
              {
                  $$ = new nodo("clase",$2,yylineno, columna);
                  nodo *nod = new nodo("visibilidad","publico",yylineno, columna);
                  $$->hijos.append(*nod);
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  $$->hijos.append(*her);
                  $$->hijos.append(*$4);
              }
         // Con herencia
        |VISIBILIDAD clase id heredade id illave ICLASES fllave
              {
                  $$ = new nodo("clase",$3,yylineno, columna);
                  $$->hijos.append(*$1);
                  nodo *padre = new nodo("herencia",$5,yylineno,columna);
                  $$->hijos.append(*padre);
                  $$->hijos.append(*$7);
              }
        |clase id  heredade id illave  ICLASES fllave
              {
                  $$ = new nodo("clase",$2,yylineno, columna);
                  nodo *nod = new nodo("publico","publico",yylineno, columna);
                  $$->hijos.append(*nod);
                  nodo *padre = new nodo("herencia",$4,yylineno,columna);
                  $$->hijos.append(*padre);
                  $$->hijos.append(*$6);
              }
              ;

// Clases-----------------------------------------------------------------------

ASIGNACION:
              id TIPOASIG VALAS
              {
                $$=$2;
                nodo *acceso = new nodo("acceso","acceso",yylineno, columna);
                nodo *nombre = new nodo("id",$1,yylineno, @1.first_column);
                acceso->hijos.append(*nombre); // nombre
                $$->add(*acceso);
                $$->add(*$3);
              }
              |id  DIMENSIONES TIPOASIG VALAS
               {
                    $$=$3;                    
                    nodo *acceso = new nodo("accesoarray","accesoarray",@1.first_line,@1.first_column);
                    nodo *nombre = new nodo("id",$1,@1.first_line,@1.first_column);
                    acceso->hijos.append(*nombre);
                    acceso->hijos.append(*$2);
                    $$->hijos.append(*acceso);  // Destino
                    $$->hijos.append(*$4);      // Valor
               }
              |LLAMADA TIPOASIG VALAS
              {
                  QString tipo = "";
                  int i=0;
                  for(i=0; i<$1->hijos.count();i++)
                  {
                    tipo = $1->hijos[i].tipo;
                  }
                  if(tipo == "llamada")
                  {
                     std::cout <<"-----------No se puede asignar un valor a una llamada."<<std::endl;
                     errorT *nuevoE = new errorT("Semantico","No se puede asignar un valor a una llamada.",$1->hijos[i-1].linea,$1->hijos[i-1].columna);
                     listaErrores->append(*nuevoE);
                  }
                  else
                  {
                        $$=$2; // Tipo asignación
                        $$->hijos.append(*$1);
                        $$->hijos.append(*$3);
                  }
              }
              |este ACCESO TIPOASIG VALAS
              {
                  QString tipo = "";
                  int i=0;
                  for(i=0; i<$2->hijos.count();i++)
                  {
                    tipo = $2->hijos[i].tipo;
                  }
                  if(tipo == "llamada")
                  {
                     std::cout <<"No se puede asignar un valor a una llamada."<<std::endl;
                    errorT *nuevoE = new errorT("Semantico","No se puede asignar un valor a una llamada.",$2->hijos[i-1].linea,$2->hijos[i-1].columna);
                    listaErrores->append(*nuevoE);
                  }
                  else
                  {
                      $$=$3; // Tipo asignacion
                      nodo *acceso = new nodo("acceso","acceso",@1.first_line,@1.first_column);
                      nodo *nombre = new nodo("id","este",@1.first_line,@1.first_column);
                      acceso->hijos.append(*nombre);
                      $2->hijos.prepend(*acceso);
                      $$->hijos.append(*$2); // destino
                      $$->hijos.append(*$4); // Valor
                  }
              }
               |id DIMENSIONES ACCESO  TIPOASIG VALAS
                {
                    $$=$4;
                    nodo *acceso = new nodo("accesoarray","accesoarray",@1.first_line,@1.first_column);
                    nodo *nombre = new nodo("id",$1,@1.first_line,@1.first_column);
                    acceso->hijos.append(*nombre); // id
                    acceso->hijos.append(*$3);
                    $$->hijos.append(*acceso);
                    $$->hijos.append(*$5);
                }
              ;
TIPOASIG:
              masigual{$$=new nodo("asig",$1,yylineno, columna);}
            | porigual{$$=new nodo("asig",$1,yylineno, columna);}
            | menosigual{$$=new nodo("asig",$1,yylineno, columna);}
            | divigual{$$=new nodo("asig",$1,yylineno, columna);}
            | igual {$$=new nodo("asig",$1,yylineno, columna);};
// da declaracion asignacion
// d  declaracion

DECLARACION:
         TIPO id
         {
            nodo *nuevo = new nodo("d",$2,yylineno, columna);
            nodo *nodoid =  new nodo("id",$2,yylineno,columna);
            nuevo->add(*$1); // tipo
            nuevo->add(*nodoid);
            $$ = nuevo;
         }
        |TIPO id igual VALAS
         {
             nodo *nuevo = new nodo("da",$2,yylineno, columna);
             nodo *nodoid =  new nodo("id",$2,yylineno,columna);
             nuevo->add(*$1); // tipo
             nuevo->add(*nodoid);
             nuevo->add(*$4); // valor
             $$ = nuevo;
         }
        ;

DECESTRUCTURAS:
        lista id igual nuevo lista parA TIPO parC
        {
          $$ = new nodo("d",$2,yylineno,columna);
          nodo *tipo = new nodo("tipo",$1,yylineno,columna);
          $$->hijos.append(*tipo);
          $$->hijos.append(*$7);
        }
        | pila id igual nuevo pila parA TIPO parC
        {
          $$ = new nodo("d",$2,yylineno,columna);
          nodo *tipo = new nodo("tipo",$1,yylineno,columna);
          $$->hijos.append(*tipo);
          $$->hijos.append(*$7);
        }
        |cola id igual nuevo cola parA TIPO parC
        {
          $$ = new nodo("d",$2,yylineno,columna);
          nodo *tipo = new nodo("tipo",$1,yylineno,columna);
          $$->hijos.append(*tipo);
          $$->hijos.append(*$7);
        }
        ;


// dar declarcion array
// dara declaracion array asignacion --E para cadenas
// darar declaracion array asignacion -- para arrays
DECLARACIONARRAY:
         TIPO id DIMENSIONES
         {
            nodo *nuevo = new nodo("dar","dar",yylineno, columna);
            nuevo->add(*$1);
            nodo *nodoid =  new nodo("id",$2,yylineno,columna);
            nuevo->add(*nodoid);
            nuevo->add(*$3);
            $$ = nuevo;
         }
        |TIPO id DIMENSIONES igual EXPL {
             nodo *nuevo = new nodo("dara","dara",yylineno, columna);
             nuevo->add(*$1);
             nodo *nodoid =  new nodo("id",$2,yylineno,columna);
             nuevo->add(*nodoid);
             nuevo->add(*$3);
             nuevo->add(*$5);
             $$ = nuevo;}
         |TIPO id DIMENSIONES igual VALORESA {
              nodo *nuevo = new nodo("darar","darar",yylineno, columna);
              nuevo->add(*$1);
              nodo *nodoid =  new nodo("id",$2,yylineno,columna);
              nuevo->add(*nodoid);
              nuevo->add(*$3);
              nuevo->add(*$5);
              $$ = nuevo;}
         ;

// dim dimension
DIMENSIONES: DIMENSIONES iCor EXPL fCor {$$->add(*$3);}
            | iCor EXPL fCor
            {
                $$= new nodo("dim","dim",yylineno, columna);
                $$->add(*$2);
            }
            ;

// vala ueco
VALORESA: illave LVALORES fllave
         {
          $$ = $2;
         }
         ;

LVALORES:  LVALORES coma illave VALORES fllave
         {
             $$=$1;
             for (int i= 0 ; i< $4->hijos.count(); i++)
             {
                 nodo nod = $4->hijos[i];
                 $$->add(nod);
             }
         }
         | illave VALORES fllave
         {
             $$ = new nodo("lvalores","lvalores",yylineno, columna);
             for (int i =0 ; i< $2->hijos.count(); i++)
             {
                 nodo nod =  $2->hijos[i];
                 $$->add(nod);
             }
         }
         ;

VALORES: VALORES coma EXPL {$$=$1; $$->add(*$3);}
         | EXPL {$$= new nodo("valores","valores",yylineno,columna); $$->add(*$1);}
         ;


VALAS:
       EXPL {$$=$1;}
       |SENTSELEC{$$=$1;}
       ;

TIPO: tipoBooleano  {$$= new nodo("booleano",$1,yylineno,columna);}
    | tipoEntero    {$$= new nodo("entero",$1,yylineno,columna);}
    | tipoCaracter  {$$= new nodo("caracter",$1,yylineno,columna);}
    | tipoDecimal   {$$= new nodo("decimal",$1,yylineno,columna);}
    | id {$$= new nodo("objeto",$1,yylineno,columna);}
    ;


// tipo id =  var1==0? 12: 69;

SENTSELEC: EXPL interrogacion  EXPL dosP EXPL
         {
             $$ = new nodo("ss","ss",yylineno, columna);
             $$->add(*$1); // Condicion
             $$->add(*$3); // Valor verdadero
             $$->add(*$5); // Valor falso;
         }

EXPL :
           EXPL y EXPL {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);}
         | EXPL o EXPL {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);}
         | no EXPL {$$ = new nodo($1,$1,yylineno,columna); $$->add(*$2);};
         | EXPR {$$ =$1;};


EXPR :     EXPA igualigual EXPA {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);}
         | EXPA desigual EXPA {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);}
         | EXPA menor EXPA {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);}
         | EXPA mayor EXPA {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);}
         | EXPA menorigual EXPA {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);}
         | EXPA mayorigual EXPA {$$ = new nodo($2,$2,yylineno,columna); $$->add(*$1); $$->add(*$3);};
         | EXPA {$$ =$1;};
EXPA:
         EXPA suma EXPA {nodo *nod = new nodo($2,$2,yylineno, columna);  nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA menos EXPA {nodo *nod = new nodo($2,$2,yylineno, columna); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA multi EXPA {nodo *nod = new nodo($2,$2,yylineno, columna); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA division EXPA{nodo *nod = new nodo($2,$2,yylineno, columna); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA potencia EXPA{ nodo *nod = new nodo($2,$2,yylineno, columna); nod->add(*$1);  nod->add(*$3);  $$=nod ;  }
        |EXPA modulo EXPA{ nodo *nod = new nodo($2,$2,yylineno, columna); nod->add(*$1);  nod->add(*$3);  $$=nod ;  }
        |menos EXPA { $$ = new nodo($1,$1,yylineno, columna); $$->add(*$2);}
        |id
        {
             $$ = new nodo("acceso","acceso",yylineno, columna);
             nodo *nombre = new nodo("id",$1,yylineno,columna);
             $$->hijos.append(*nombre);
        }
        |id DIMENSIONES
        {
                $$ = new nodo("accesoarray","accesoarray",yylineno,columna);
                nodo *nombre = new nodo("id",$1,yylineno,columna);
                $$->hijos.append(*nombre);
                $$->hijos.append(*$2);
        }
         |INSTANCIA{$$=$1;}
         |INSTANCIA ACCESO
         {
              $$=$2;
              nodo *nod = new nodo("acceso","acceso",yylineno, columna);
              nod->hijos.append(*$1);
              $$->hijos.prepend(*nod);
         }
        |entero { $$ = new nodo("entero",$1,yylineno, columna);}
        |caracter { $$ = new nodo("caracter",$1,yylineno, columna);}
        |decimal { $$ = new nodo("decimal",$1,yylineno, columna);}
        |booleano { $$ = new nodo("booleano",$1,yylineno, columna);}
        |cadena { $$ = new nodo("cadena",$1,yylineno, columna);}
        |nada { $$ = new nodo("nada",$1,yylineno, columna);}
        |UNARIOS {$$ = $1;}
        |parA EXPL parC{$$=$2;}
        |id DIMENSIONES ACCESO
         {
             $$=$2;
             nodo *nod = new nodo("accesoarray","accesoarray",yylineno, columna);
             nodo *nombre = new nodo("id",$1,@1.first_line,@1.first_column);
             nod->hijos.append(*nombre);
             nod->hijos.append(*$2);
             $$->hijos.prepend(*nod);
         }
        |este ACCESO
         {
             $$=$2;
             nodo *nod = new nodo("acceso","acceso",yylineno, columna);
             nodo*nombre = new nodo("id","este",yylineno,columna);
             nod->hijos.append(*nombre);
             $$->hijos.prepend(*nod);
         }
         |convertirAcadena parA EXPL parC
         {
            $$ = new nodo("convertiracadena","convertiracadena",yylineno,columna);
            $$->hijos.append(*$3);
         }
         |convertirAentero parA EXPL parC
         {
            $$ = new nodo("convertiraentero","convertiraentero",yylineno,columna);
            $$->hijos.append(*$3);
         }
         | LLAMADA
         {
             $$=$1;
         }
         ;
        // LLAMADAS funciones



LPAR: LPAR coma EXPL
     {
        $$=$1;
        $$->hijos.append(*$3);
     }
     |EXPL
     {
        $$ = new nodo("lpar","lpar",yylineno,columna);
        $$->hijos.append(*$1);
     }
     ;


LLAMADA:

         id parA parC
         {
             $$ = new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",$1,yylineno, columna);
             $$->hijos.append(*nombre); // nodo nombre
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             $$->hijos.append(*par);
         }
         |id parA LPAR parC
         {
             $$ = new nodo("llamada","llamada",yylineno,columna);
             nodo * nombre = new nodo("id",$1,@1.first_line,@1.first_column);
             $$->hijos.append(*nombre);
             $$->hijos.append(*$3);
         }
         |id parA parC ACCESO
         {
             $$=$4;
             nodo *f= new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",$1,yylineno,columna);
             f->hijos.append(*nombre); //Nodo id
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             f->hijos.append(*par);
             $$->hijos.prepend(*f);
         }
         |id parA LPAR parC ACCESO
         {
             $$ = $5;
             nodo *f= new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",$1,yylineno, columna);
             f->hijos.append(*nombre); // Nodo nombre
             f->hijos.append(*$3);     // Parametors
             $$->hijos.prepend(*f);
         }
        |id ACCESO
        {
             $$ =$2;             
             nodo *f= new nodo("acceso","acceso",yylineno,columna);
             nodo *id = new nodo("id",$1,yylineno, columna);
             f->hijos.append(*id);
             $$->hijos.prepend(*f);
        }
        ;


UNARIOS :
         EXPA aumento {nodo *nod = new nodo("aumento","++",yylineno, columna); nod->add(*$1); $$= nod;}
        |EXPA decremento {nodo *nod = new nodo("decremento","--",yylineno, columna); nod->add(*$1); $$= nod;};



ACCESO : ACCESO punto id
         {
             $$ = $1;
             nodo *nod= new nodo("acceso","acceso",yylineno, columna);
             nodo * nombre = new nodo("id",$2,yylineno, columna);
             nod->hijos.append(*nombre);
             $$->hijos.append(*nod);
         }
        | ACCESO punto id parA parC
        {
            $$ = $1;
            nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
            nodo *nod= new nodo("id",$3,yylineno, columna);
            acceso->hijos.append(*nod); // Add nodo con el id
            nodo *par = new nodo("lpar","lpar",yylineno,columna);
            acceso->hijos.append(*par); // Add lista parametros
            $$->hijos.append(*acceso);
        }
         | ACCESO punto id parA LPAR parC
         {
             $$ = $1;
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",$3,yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*$5); // Add lista parametros
             $$->hijos.append(*acceso);
         }
         |ACCESO punto id DIMENSIONES
         {
            $$ = $1;
            nodo *acceso = new nodo("accesoarray","accesoarray",yylineno, columna);
            nodo *nod= new nodo("id",$3,yylineno, columna);
            acceso->hijos.append(*nod); // Add nodo con el id
            acceso->hijos.append(*$4); // Add dimensiones
            $$->hijos.append(*acceso);

         }
         | punto id
         {
             $$ = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *nod= new nodo("acceso","acceso",yylineno, columna);
             nodo * nombre = new nodo("id",$2,yylineno, columna);
             nod->hijos.append(*nombre);
             $$->hijos.append(*nod);
         }
         | punto id parA parC
         {
             $$ = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",$2,yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             acceso->hijos.append(*par); // Add lista parametros
             $$->hijos.append(*acceso);
         }
         | punto id parA LPAR parC
         {
             $$ = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",$2,yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*$4); // Add lista parametros
             $$->hijos.append(*acceso);
         }
        |punto id DIMENSIONES
         {
             $$ = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("accesoarray","accesoarray",yylineno, columna);
             nodo *nod= new nodo("id",$2,yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*$3); // Add dimensiones
             $$->hijos.append(*acceso);
         };
%%
