%{
#include "scanner.h"//se importa el header del analisis sintactico
#include <iostream> //libreria para imprimir en cosola de C
#include <QString> //libreria para manejo de STRINGS de QT
#include <QList>
#include "nodo.h"
#include <QTextEdit> //libreria QTextEdit de QT para poder mostrar el resultado en pantalla

extern int yylineno; //linea actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern int columna; //columna actual donde se encuentra el parser (analisis lexico) lo maneja BISON
extern char *yytext; //lexema actual donde esta el parser (analisis lexico) lo maneja BISON
extern nodo *raiz; // Raiz del arbol

int yyerror(const char* mens)
{
    //metodo que se llama al haber un error sintactico
    //SE IMPRIME EN CONSOLA EL ERROR
    //std::cout <<mens<<"-----"<<yytext<< std::endl;
    std::cout << mens <<"----"<<yytext<< " En la linea:" << yylineno  << "Columna:" << columna<<std::endl;
    return 0;
}


QTextEdit * salida;

%}
//error-verbose si se especifica la opcion los errores sintacticos son especificados por BISON
%defines "parser.h"
%output "parser.cpp"
%error-verbose

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
%type<nodito> ACC;
//LOS NO TERMINALES PUEDEN SER DE DIFERENTE TIPO, LOS TERMINALES SIEMPRE SON STRINGS O NO SE ESPECIFICA TIPO
//PRECEDENCIA DE LOS OPERADORES PARA QUITAR LA AMBIGUEDAD DEN LA GRAMTICA
%left suma menos
%left multi division
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
            | INSTRUCCIONG { nodo *nuevo = new nodo("sentenciasg","sentenciasg",@1.first_line, @1.first_column); nuevo->add(*$1); $$ = nuevo;}
;

INSTRUCCIONG:
              IMPORTAR puntoComa{$$=$1;}
            | CLASE{$$ = $1;}
              ;

IMPRIMIR: imprimir parA EXPL parC
              {
                  $$ = new nodo("imprimir",$1,@1.first_line,@1.first_column);
                  $$->hijos.append(*$3);
              }
            |imprimir parA CONCATENAR parC
              {
                  $$ = new nodo("imprimir",$1,@1.first_line,@1.first_column);
                  $$->hijos.append(*$3);
              };

CONCATENAR:
              concatenar parA EXPL coma EXPL parC
              {
                  $$ = new nodo("concatenar",$1, @1.first_line, @1.first_column);
                  $$->hijos.append(*$3);
                  $$->hijos.append(*$5);
              }
              //Concatenar (identificador,cadena,Expresion);
              |concatenar parA EXPL coma EXPL  coma EXPL parC
              {
                  $$ = new nodo("concatenar",$1, @1.first_line, @1.first_column);
                  $$->hijos.append(*$3);
                  $$->hijos.append(*$5);
                  $$->hijos.append(*$7);
              }
              ;

IMPORTAR : importar parA cadena parC
              {
                $$ = new nodo("importar",$1,@1.first_line,@1.first_column);
                nodo *ruta = new nodo("path",$3,@3.first_line,@3.first_column);
                $$->hijos.append(*ruta);
              };

// Clases----------------------------------------------------------------------

// INSTRUCCIONES DE CLASE
ICLASES :ICLASES ICLASE
              {
                 $$=$1;
                 $$->hijos.append(*$2);
              }
        |ICLASE
              {
                 $$ = new nodo("instrucciones","instrucciones",@1.first_line,@1.first_column);
                 $$->hijos.append(*$1);
              }
        ;

ICLASE:
        FUNCION {$$=$1;} // Estas van en la cabecera. O bien no dentro de algún metodo.
       |sobreescribir FUNCION
       {
            $$=$2;
            nodo *sobre = new nodo("sobrescribir","sobrescribir",@1.first_line,@1.first_column);
            $$->hijos.prepend(*sobre);
       } // Estas van en la cabecera. O bien no dentro de algún metodo.
       |ATRIBUTO{$$=$1;}
       | PRINCIPAL {$$= $1;}
       | CONSTRUCTOR {$$=$1;}
       | sobreescribir CONSTRUCTOR
        {
             $$=$2;
             nodo *sobre = new nodo("sobrescribir","sobrescribir",@1.first_line,@1.first_column);
             $$->hijos.prepend(*sobre);
        } // Estas van en la cabecera. O bien no dentro de algún metodo.
        ;


SENTENCIAS: SENTENCIAS INSTRUCCION{ $$ = $1; $$->add(*$2);}
              |INSTRUCCION { nodo *nuevo = new nodo("sentencias","sentencias",@1.first_line, @1.first_column); nuevo->add(*$1); $$ = nuevo;}
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
              | detener puntoComa{ $$ = new nodo("detener","detener",@1.first_line,@1.first_column);}
              | continuar puntoComa{ $$ = new nodo("continuar","continuar",@1.first_line,@1.first_column);}
              | DECESTRUCTURAS puntoComa{$$=$1;}
              | mostraredd parA id parC puntoComa{ $$ = new nodo("mostraredd",$3,@1.first_line,@1.first_column);}
              |LEER puntoComa{ $$=$1;}
              ;


LEER: leer_teclado parA EXPL  coma EXPL parC
         {
            $$= new nodo("leer","leer",@1.first_line,@1.first_column);
            $$->hijos.append(*$3);
            $$->hijos.append(*$5);
         }
         ;

//para (entero cuenta = 0; cuenta <= 10; cuenta++) {
PARA: para parA ASIGNACION puntoComa EXPL puntoComa ASIGNACION parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",@1.first_line,@1.first_column);
            $$->hijos.append(*$3);// Asignacion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // Asignacion
            $$->hijos.append(*$10); // Sentencias
        }
        | para parA DECLARACION puntoComa EXPL puntoComa ASIGNACION parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",@1.first_line,@1.first_column);
            $$->hijos.append(*$3);// Declaracion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // Asignacion
            $$->hijos.append(*$10); // Sentencias
        }
        |para parA ASIGNACION puntoComa EXPL puntoComa UNARIOS parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",@1.first_line,@1.first_column);
            $$->hijos.append(*$3);// Asignacion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // decremento / aumento
            $$->hijos.append(*$10); // Sentencias
        }
        | para parA DECLARACION puntoComa EXPL puntoComa UNARIOS  parC illave SENTENCIAS fllave
        {
            $$ = new nodo("para","para",@1.first_line,@1.first_column);
            $$->hijos.append(*$3);// Declaracion
            $$->hijos.append(*$5); // Condicion
            $$->hijos.append(*$7); // Asignacion
            $$->hijos.append(*$10); // Sentencias
        }
        ;


HACER: hacer illave SENTENCIAS fllave
        mientras parA EXPL parC
        {
            $$ = new nodo("hacer","hacer",@1.first_line,@1.first_column);
            $$->hijos.append(*$3);// sentencias
            $$->hijos.append(*$7);// condicion;
        }
        ;

MIENTRAS:
//mientras (cuenta <= 10) { si (cuenta == 5) { detener; } cuenta++; }
         mientras parA EXPL parC illave SENTENCIAS fllave
         {
           $$ = new nodo("mientras","mientras",@1.first_line,@1.first_column);
           $$->hijos.append(*$3); // Condicion
           $$->hijos.append(*$6);
         };


SI:
         si parA EXPL parC illave  SENTENCIAS fllave
         {
             $$ = new nodo("si","si",@1.first_line,@1.first_column);
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
           $$= new nodo("sinosi","sinosi",@1.first_line,@1.first_column);
           $$->hijos.append(*$3); // condicion
           $$->hijos.append(*$6); // Sentenencias
         };


SELECCIONAR:
         selecciona parA EXPL parC illave CASOS fllave
         {
             $$ = new nodo("selecciona",$1,@1.first_line,@1.first_column);
             $$->hijos.append(*$3);
             $$->hijos.append(*$6);
         }
         ;
CASOS: LCASOS defecto dosP illave SENTENCIAS fllave
     {
        $$=$1;
        nodo *def = new nodo("defecto","defecto",@2.first_line,@2.first_column);
        def->hijos.append(*$5);
        $$->hijos.append(*def);
     }
     |defecto dosP illave SENTENCIAS fllave
     {
        $$= new nodo("casos","casos",@1.first_line,@1.first_column);
        nodo *def = new nodo("caso","defecto",@1.first_line,@1.first_column);
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
           $$= new nodo("casos","casos",@1.first_line,@1.first_column);
           $$->hijos.append(*$1);
         }

CASO: caso EXPL dosP illave SENTENCIAS fllave
         {
            $$ = new nodo("caso","caso",@1.first_line,@1.first_column);
            $$->hijos.append(*$2);
            $$->hijos.append(*$5);
         }
         ;

RETORNO: retornar EXPL
              {
                $$=new nodo("retorno","retorno",@1.first_line,@1.first_column);
                $$->hijos.append(*$2);
              }
              ;

ATRIBUTO:  VISIBILIDAD DECLARACION puntoComa
            {
                $$ = $2;
                $$->hijos.prepend(*$1);
                $$->tipo = "declatrib";
            }
        |DECLARACION puntoComa
            {
                $$ = $1;
                nodo *nod = new nodo("publico","publico",@1.first_line, @1.first_column);
                $$->hijos.prepend(*nod);
                $$->tipo = "declatrib";
            }
         |VISIBILIDAD DECLARACIONARRAY puntoComa
            {
             $$ = $2;
             $$->hijos.prepend(*$1);
             $$->tipo = "declatrib";
            }
        |DECLARACIONARRAY puntoComa
        {
         $$ = $1;
         nodo *nod = new nodo("publico","publico",@1.first_line, @1.first_column);
         $$->hijos.prepend(*nod);
         $$->tipo = "declatrib";
        }
         ;


VISIBILIDAD:
            publico {$$ = new nodo("publico",$1,@1.first_line, @1.first_column);}
           |privado {$$ = new nodo("privado",$1,@1.first_line, @1.first_column);}
           |protegido{$$ = new nodo("protegido",$1,@1.first_line, @1.first_column);}
            ;
INSTANCIA: nuevo id parA LPAR parC
            {
                 nodo *cons = new nodo("constructor",$2,@2.first_line,@2.first_column);
                 cons->hijos.append(*$4); // LISTA DE PARAMETROS
                 $$ = cons;
            }
            |nuevo id parA parC
            {
                 nodo *cons = new nodo("constructor",$2,@2.first_line,@2.first_column);
                 nodo *lpar = new nodo("lpar","lpar",@1.first_line,@1.first_column);
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
                $$ = new nodo("parametros","parametros",@1.first_line, @1.first_column);
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
                $$ = new nodo("principal",$1, @1.first_line, @1.first_column);
                $$->hijos.append(*$5);
           };


CONSTRUCTOR: VISIBILIDAD id  parA  LPARAMETROS parC illave  SENTENCIAS fllave
                {
                    $$ = new nodo("constructor",$2,@1.first_line,@1.first_column);
                    $$->hijos.append(*$1); // visibilidad
                    $$->hijos.append(*$4); // parametros
                    $$->hijos.append(*$7); // instrucciones
                }
                |id parA  LPARAMETROS parC illave  SENTENCIAS fllave
                {
                    $$ = new nodo("constructor",$1,@1.first_line,@1.first_column);
                    nodo *vis = new nodo("visibilidad","publico",@1.first_line,@1.first_column);
                    $$->hijos.append(*vis); // visibilidad
                    $$->hijos.append(*$3);  // parametros
                    $$->hijos.append(*$6); // instrucciones
                }
                ;

FUNCION: VISIBILIDAD TIPO DIMS id  parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$4,@1.first_line,@1.first_column);
                $$->hijos.append(*$1); // visibilidad
                $$->hijos.append(*$2); // tipo
                $$->hijos.append(*$3); // dimensiones del retorno
                $$->hijos.append(*$6); // lista de parametros
                $$->hijos.append(*$9); // lista de instrucciones;
            }
            |VISIBILIDAD TIPO id  parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$3,@1.first_line,@1.first_column);
                $$->hijos.append(*$1); // visibilidad
                $$->hijos.append(*$2); // tipo
                $$->hijos.append(*$5); // lista de parametros
                $$->hijos.append(*$8); // lista de instrucciones;
            }
            |VISIBILIDAD vacio id parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$3,@1.first_line,@1.first_column);
                $$->hijos.append(*$1); // visibilidad
                nodo *tipo = new nodo("tipo",$2,@2.first_line,@2.first_column);
                $$->hijos.append(*tipo); // tipo
                $$->hijos.append(*$5); // lista de parametros
                $$->hijos.append(*$8); // lista de instrucciones;
            }
            |TIPO  DIMS id   parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$3,@1.first_line,@1.first_column);
                nodo *vis = new nodo("publico","publico",@1.first_line, @1.first_column);
                $$->hijos.append(*vis); // visibilidad
                $$->hijos.append(*$1); // tipo
                $$->hijos.append(*$2); // dimensiones del retorno
                $$->hijos.append(*$5); // lista de parametros
                $$->hijos.append(*$8); // lista de instrucciones;
            }
            |TIPO id   parA LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$2,@1.first_line,@1.first_column);
                nodo *vis = new nodo("publico","publico",@1.first_line, @1.first_column);
                $$->hijos.append(*vis); // visibilidad
                $$->hijos.append(*$1); // tipo
                $$->hijos.append(*$4); // lista de parametros
                $$->hijos.append(*$7); // lista de instrucciones;
            }
            |vacio id parA  LPARAMETROS parC illave SENTENCIAS fllave
            {
                $$ = new nodo("funcion",$2,@1.first_line,@1.first_column);
                nodo *vis = new nodo("publico","publico",@1.first_line, @1.first_column);
                $$->hijos.append(*vis); // visibilidad
                nodo *tipo = new nodo("tipo",$1,@1.first_line,@1.first_column);
                $$->hijos.append(*tipo); // tipo
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
             $$= new nodo("dims","dims",@1.first_line, @1.first_column);
             $$->hijos.append(*$1);
          };

DIM: iCor fCor { $$ = new nodo("dim","dim",@1.first_line,@1.first_column);};

/*
TIPOR:  vacio {$$= new nodo("tipo",$1,@1.first_line,@1.first_column);}
       |TIPO {$$=$1;};*/


CLASE: VISIBILIDAD clase id illave ICLASES fllave
              {
                  $$ = new nodo("clase",$3,@1.first_line, @1.first_column);
                  $$->hijos.append(*$1);
                  $$->hijos.append(*$5);
              }
        |clase id illave  ICLASES fllave
              {
                  $$ = new nodo("clase",$2,@1.first_line, @1.first_column);
                  nodo *nod = new nodo("visibilidad","publico",@1.first_line, @1.first_column);
                  $$->hijos.append(*nod);
                  $$->hijos.append(*$4);
              }
         // Con herencia
        |VISIBILIDAD clase id heredade id illave ICLASES fllave
              {
                  $$ = new nodo("clase",$3,@1.first_line, @1.first_column);
                  $$->hijos.append(*$1);
                  nodo *padre = new nodo("herencia",$5,@5.first_line,@5.first_column);
                  $$->hijos.append(*padre);
                  $$->hijos.append(*$7);
              }
        |clase id  heredade id illave  ICLASES fllave
              {
                  $$ = new nodo("clase",$2,@1.first_line, @1.first_column);
                  nodo *nod = new nodo("publico","publico",@1.first_line, @1.first_column);
                  $$->hijos.append(*nod);
                  nodo *padre = new nodo("herencia",$4,@4.first_line,@4.first_column);
                  $$->hijos.append(*padre);
                  $$->hijos.append(*$6);
              }
              ;

// Clases-----------------------------------------------------------------------

ASIGNACION:
              id TIPOASIG VALAS
                          {
                            $$=$2;
                            nodo *idnodo = new nodo("variable",$1,@1.first_line, @1.first_column);
                            $$->add(*idnodo);
                            $$->add(*$3);
                           }
              |id  DIMENSIONES TIPOASIG VALAS
                          {
                            $$=$3;
                            $$->tipo= "asiga";
                            $$->add(*$2);
                            nodo *idnodo = new nodo("variable",$1,@1.first_line, @1.first_column);
                            $$->add(*idnodo);
                            $$->add(*$4);
                           }
              |id ACCESO TIPOASIG VALAS
                          {
                          $$=$3;
                          nodo *nod = new nodo("id",$1,@1.first_line, @1.first_column);
                          $2->hijos.prepend(*nod);
                          $$->hijos.append(*$2);
                          $$->hijos.append(*$4);
                          }
              |este ACCESO TIPOASIG VALAS
                          {
                          $$=$3;
                          nodo *nod = new nodo("id",$1,@1.first_line, @1.first_column);
                          $2->hijos.prepend(*nod);
                          $$->hijos.append(*$2);
                          $$->hijos.append(*$4);
                          }
               |id DIMENSIONES ACCESO  TIPOASIG VALAS
                           {
                           $$=$4;
                           nodo *nod = new nodo("id",$1,@1.first_line, @1.first_column);
                           nod->hijos.append(*$2);
                           $$->hijos.prepend(*nod);
                           $$->hijos.append(*$5);
                           }

              ;
TIPOASIG:
              masigual{$$=new nodo("asig",$1,@1.first_line, @1.first_column);}
            | porigual{$$=new nodo("asig",$1,@1.first_line, @1.first_column);}
            | menosigual{$$=new nodo("asig",$1,@1.first_line, @1.first_column);}
            | divigual{$$=new nodo("asig",$1,@1.first_line, @1.first_column);}
            | igual {$$=new nodo("asig",$1,@1.first_line, @1.first_column);};
// da declaracion asignacion
// d  declaracion

DECLARACION:
         TIPO id
         {
            nodo *nuevo = new nodo("d",$2,@1.first_line, @1.first_column);
            nuevo->add(*$1); // tipo
            $$ = nuevo;
         }
        |TIPO id igual VALAS
         {
             nodo *nuevo = new nodo("da",$2,@1.first_line, @1.first_column);
             nuevo->add(*$1); // tipo
             nuevo->add(*$4); // valor
             $$ = nuevo;
         }
        ;

DECESTRUCTURAS:
        lista id igual nuevo lista parA TIPO parC
        {
          $$ = new nodo("d",$2,@1.first_line,@1.first_column);
          nodo *tipo = new nodo("tipo",$1,@1.first_line,@1.first_column);
          $$->hijos.append(*tipo);
          $$->hijos.append(*$7);
        }
        | pila id igual nuevo pila parA TIPO parC
        {
          $$ = new nodo("d",$2,@1.first_line,@1.first_column);
          nodo *tipo = new nodo("tipo",$1,@1.first_line,@1.first_column);
          $$->hijos.append(*tipo);
          $$->hijos.append(*$7);
        }
        |cola id igual nuevo cola parA TIPO parC
        {
          $$ = new nodo("d",$2,@1.first_line,@1.first_column);
          nodo *tipo = new nodo("tipo",$1,@1.first_line,@1.first_column);
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
            nodo *nuevo = new nodo("dar","dar",@1.first_line, @1.first_column);
            nuevo->add(*$1);
            nodo *nodoid =  new nodo("id",$2,@2.first_line,@2.first_column);
            nuevo->add(*nodoid);
            $$ = nuevo;
         }
        |TIPO id DIMENSIONES igual EXPL {
             nodo *nuevo = new nodo("dara","dara",@1.first_line, @1.first_column);
             nuevo->add(*$1);
             nodo *nodoid =  new nodo("id",$2,@2.first_line,@2.first_column);
             nuevo->add(*nodoid);
             nuevo->add(*$3);
             nuevo->add(*$5);
             $$ = nuevo;}
         |TIPO id DIMENSIONES igual VALORESA {
              nodo *nuevo = new nodo("darar","darar",@1.first_line, @1.first_column);
              nuevo->add(*$1);
              nodo *nodoid =  new nodo("id",$2,@2.first_line,@2.first_column);
              nuevo->add(*nodoid);
              nuevo->add(*$3);
              nuevo->add(*$5);
              $$ = nuevo;}
         ;

// dim dimension
DIMENSIONES: DIMENSIONES iCor EXPL fCor {$$->add(*$3);}
            | iCor EXPL fCor
            {
                $$= new nodo("dim","dim",@1.first_line, @1.first_column);
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
             $$ = new nodo("lvalores","lvalores",@1.first_line, @2.first_column);
             for (int i =0 ; i< $2->hijos.count(); i++)
             {
                 nodo nod =  $2->hijos[i];
                 $$->add(nod);
             }
         }
         ;

VALORES: VALORES coma EXPL {$$=$1; $$->add(*$3);}
         | EXPL {$$= new nodo("valores","valores",@1.first_line,@1.first_column); $$->add(*$1);}
         ;


VALAS:
       EXPL {$$=$1;}
       |SENTSELEC{$$=$1;}
       |INSTANCIA{$$=$1;}
       ;

TIPO: tipoBooleano  {$$= new nodo("tipoboleano",$1,@1.first_line,@1.first_column);}
    | tipoEntero    {$$= new nodo("tipoentero",$1,@1.first_line,@1.first_column);}
    | tipoCaracter  {$$= new nodo("tipocaracter",$1,@1.first_line,@1.first_column);}
    | tipoDecimal   {$$= new nodo("tipodecimal",$1,@1.first_line,@1.first_column);}
    | id {$$= new nodo("tipoobjeto",$1,@1.first_line,@1.first_column);}
    ;


// tipo id =  var1==0? 12: 69;

SENTSELEC: EXPL interrogacion  EXPL dosP EXPL
         {
             $$ = new nodo("ss","ss",@1.first_line, @1.first_column);
             $$->add(*$1); // Condicion
             $$->add(*$3); // Valor verdadero
             $$->add(*$5); // Valor falso;
         }

EXPL :
           EXPL y EXPL {$$ = new nodo("expl",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);}
         | EXPL o EXPL {$$ = new nodo("expl",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);}
         | no EXPL {$$ = new nodo("expl",$1,@1.first_line,@1.first_column); $$->add(*$2);};
         | EXPR {$$ =$1;};


EXPR :     EXPA igualigual EXPA {$$ = new nodo("expr",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);}
         | EXPA desigual EXPA {$$ = new nodo("expr",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);}
         | EXPA menor EXPA {$$ = new nodo("expr",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);}
         | EXPA mayor EXPA {$$ = new nodo("expr",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);}
         | EXPA menorigual EXPA {$$ = new nodo("expr",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);}
         | EXPA mayorigual EXPA {$$ = new nodo("expr",$2,@2.first_line,@2.first_column); $$->add(*$1); $$->add(*$3);};
         | EXPA {$$ =$1;};
EXPA:
         EXPA suma EXPA {nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column);  nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA menos EXPA {nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA multi EXPA {nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA division EXPA{nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1); nod->add(*$3); $$=nod;}
        |EXPA potencia EXPA{ nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1);  nod->add(*$3);  $$=nod ;  }
        |menos EXPA { $$ = new nodo("expa",$1,@1.first_line, @1.first_column); $$->add(*$2);}
        |id { $$ = new nodo("variable",$1,@1.first_line, @1.first_column);}
        |id DIMENSIONES{$$ = new nodo("acceso",$1,@1.first_line,@1.first_column); $$->hijos.append(*$2);}
        |entero { $$ = new nodo("entero",$1,@1.first_line, @1.first_column);}
        |caracter { $$ = new nodo("caracter",$1,@1.first_line, @1.first_column);}
        |decimal { $$ = new nodo("caracter",$1,@1.first_line, @1.first_column);}
        |booleano { $$ = new nodo("booleano",$1,@1.first_line, @1.first_column);}
        |cadena { $$ = new nodo("cadena",$1,@1.first_line, @1.first_column);}
        |nada { $$ = new nodo("nada",$1,@1.first_line, @1.first_column);}
        |UNARIOS {$$ = $1;}
        |parA EXPL parC{$$=$2;}
        |id ACCESO {
                    $$=$2;
                    nodo *nod = new nodo("id",$1,@1.first_line, @1.first_column);
                    $$->hijos.prepend(*nod);
                    }
         |id DIMENSIONES ACCESO {
                     $$=$2;
                     nodo *nod = new nodo("id",$1,@1.first_line, @1.first_column);
                     $$->hijos.prepend(*nod);
                     }
        //----this
         |este ACCESO {
                     $$=$2;
                     nodo *nod = new nodo("id",$1,@1.first_line, @1.first_column);
                     $$->hijos.prepend(*nod);
                     }
         |convertirAcadena parA EXPL parC
         {
            $$ = new nodo("convertacadena","convertacadena",@1.first_line,@1.first_column);
            $$->hijos.append(*$3);
         }
         |convertirAentero parA EXPL parC
         {
            $$ = new nodo("convertaentero","convertaentero",@1.first_line,@1.first_column);
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
        $$ = new nodo("lpar","lpar",@1.first_line,@1.first_column);
        $$->hijos.append(*$1);
     }
     ;


LLAMADA: id parA parC
         {
             $$ = new nodo("llamada",$1,@1.first_line,@1.first_column);
             /*nodo *params = new nodo("lpar","lpar",@2.first_line,@2.first_column);
             $$->hijos.append(*params);*/
         }
         | id parA LPAR parC
         {
             $$ = new nodo("llamada",$1,@1.first_line,@1.first_column);
             for(int i= 0; i<$3->hijos.count(); i++)
             {
                $$->hijos.append($3->hijos[i]);
             }
         }
        |id ACCESO parA LPAR parC
        {
          $$ = $2;
          $$->tipo = "llamada";
          nodo *id = new nodo("id",$1,@1.first_line,@1.first_column);
          $$->hijos.prepend(*id);
          for(int i=0; i<$4->hijos.count();i++)
          {
              $$->hijos.append($4->hijos[i]);
          }
        }
        |id ACCESO parA  parC
         {
           $$ = $2;
           $$->tipo = "llamada";
           nodo *id = new nodo("id",$1,@1.first_line,@1.first_column);
           $$->hijos.prepend(*id);
         }
 ;


UNARIOS :
         EXPA aumento {nodo *nod = new nodo("aumento","++",@2.first_line, @2.first_column); nod->add(*$1); $$= nod;}
        |EXPA decremento {nodo *nod = new nodo("decremento","--",@2.first_line, @2.first_column); nod->add(*$1); $$= nod;};


ACCESO : ACCESO punto id
         {
             $$ = $1;
             nodo *nod= new nodo("id",$3,@3.first_line, @3.first_column);
             $$->hijos.append(*nod);
         }
         |ACCESO punto id DIMENSIONES
         {
            $$ = $1;
            nodo *nod= new nodo("idv",$3,@3.first_line, @3.first_column);
            nod->hijos.append(*$4);
            $$->hijos.append(*nod);
         }
         | punto id
         {
             $$ = new nodo("acceso","acceso",@1.first_line, @1.first_column);
             nodo *nod= new nodo("id",$2,@1.first_line, @1.first_column);
             $$->hijos.append(*nod);
         }
        |punto id DIMENSIONES
         {
             $$ = new nodo("acceso","acceso",@1.first_line, @1.first_column);
             nodo *nod= new nodo("idv",$2,@2.first_line, @2.first_column);
             nod->hijos.append(*$3);
             $$->hijos.append(*nod);
         };

ACCESO: ACC{ $$=$1;}
       |ACC punto id
         {
             $$=$1;
             nodo *nod= new nodo("id",$3,@3.first_line, @3.first_column);
             $$->hijos.append(*nod);
         }
         ;

ACC: ACC punto id
      {
          $$ = $1;
          nodo *nod= new nodo("id",$3,@3.first_line, @3.first_column);
          $$->hijos.append(*nod);
      }
    |ACC punto id parA parC
    {
        $$ = $1;
        nodo *nod= new nodo("funcion",$3,@3.first_line, @3.first_column);
        $$->hijos.append(*nod);
    }
    |ACC punto id parA EXPL parC
    {
        $$ = $1;
        nodo *nod= new nodo("funcion",$3,@3.first_line, @3.first_column);
        nod->hijos.append(*$5);
        $$->hijos.append(*nod);
    }
      |ACC punto id DIMENSIONES
      {
         $$ = $1;
         nodo *nod= new nodo("idv",$3,@3.first_line, @3.first_column);
         nod->hijos.append(*$4);
         $$->hijos.append(*nod);
      }
      | punto id
      {
          $$ = new nodo("acceso","acceso",@1.first_line, @1.first_column);
          nodo *nod= new nodo("id",$2,@1.first_line, @1.first_column);
          $$->hijos.append(*nod);
      }
     | punto id parA parC
     {
         $$ = new nodo("acceso","acceso",@1.first_line, @1.first_column);
         nodo *nod= new nodo("funcion",$2,@1.first_line, @1.first_column);
         $$->hijos.append(*nod);
     }
     | punto id parA LPAR parC
     {
         $$ = new nodo("acceso","acceso",@1.first_line, @1.first_column);
         nodo *nod= new nodo("funcion",$2,@1.first_line, @1.first_column);
         nod->hijos.append(*$4);
         $$->hijos.append(*nod);
     }
     |punto id DIMENSIONES
      {
          $$ = new nodo("acceso","acceso",@1.first_line, @1.first_column);
          nodo *nod= new nodo("idv",$2,@2.first_line, @2.first_column);
          nod->hijos.append(*$3);
          $$->hijos.append(*nod);
      };
%%
