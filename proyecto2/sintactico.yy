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
    std::cout << mens <<"----"<<yytext<< "En la linea:" << yylineno  << "Columna:" << columna<<std::endl;
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
%token<TEXT> seleccionar;
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
%type<nodito> SENTENCIAS;
%type<nodito> DECLARACIONARRAY;
%type<nodito> DIMENSIONES;
%type<nodito> VALORESA; // VALORES ARRAY
%type<nodito> LVALORES;
%type<nodito> VALORES;
%type<nodito> INSTRUCCION;
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
%type<nodito> INSCLASE;
%type<nodito> IMPORTAR;
%type<nodito> TIPOR; // TIPO DE RETORNO
%type<nodito> FUNCION;
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
INICIO : SENTENCIAS {$$=$1; raiz = $$;};

SENTENCIAS:   SENTENCIAS INSTRUCCION{ $$ = $1; $$->add(*$2);}
            | INSTRUCCION { nodo *nuevo = new nodo("sentencias","sentencias",@1.first_line, @1.first_column); nuevo->add(*$1); $$ = nuevo;}
;

INSTRUCCION:
              DECLARACION puntoComa { $$ = $1;}
            | DECLARACIONARRAY puntoComa{ $$ = $1;}
            | ASIGNACION puntoComa {$$ = $1;}
            | CONCATENAR puntoComa {$$ = $1;}
            | IMPRIMIR puntoComa {$$ = $1;}
            | IMPORTAR puntoComa{$$=$1;}
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
INSCLASE :INSCLASE ATRIBUTO
              {
                 $$=$1;
                 $$->hijos.append(*$2);
              }
        |INSCLASE FUNCION
              {
                 $$=$1;
                 $$->hijos.append(*$2);
              }
         |ATRIBUTO
              {
                 $$ = new nodo("instrucciones","instrucciones",@1.first_line,@1.first_column);
                 $$->hijos.append(*$1);
              }
         | FUNCION
              {
                 $$ = new nodo("instrucciones","instrucciones",@1.first_line,@1.first_column);
                 $$->hijos.append(*$1);
              };


  ATRIBUTO:  VISIBILIDAD DECLARACION puntoComa
                {
                    $$ = $2;
                    $$->hijos.prepend(*$1);
                    $$->tipo = "declatrib";
                }
            |DECLARACION puntoComa
                {
                    $$ = $1;
                    nodo *nod = new nodo("visibilidad","publico",@1.first_line, @1.first_column);
                    $$->hijos.prepend(*nod);
                    $$->tipo = "declatrib";
                };

  VISIBILIDAD:
                publico {$$ = new nodo("visibilidad",$1,@1.first_line, @1.first_column);}
               |privado {$$ = new nodo("visibilidad",$1,@1.first_line, @1.first_column);}
               |protegido{$$ = new nodo("visibilidad",$1,@1.first_line, @1.first_column);}
                ;


// METODOS

FUNCION: VISIBILIDAD TIPOR id parA parC illave fllave
            {
                $$ = new nodo("funcion",$3,@1.first_line,@1.first_column);
                $$->hijos.append(*$1); // visibilidad
                $$->hijos.append(*$2); // tipo
            };


TIPOR:
          TIPO{$$=$1;}
        | vacio {$$= new nodo("tipo",$1,@1.first_line,@1.first_column);};


CLASE: VISIBILIDAD clase id illave INSCLASE fllave
              {
                  $$ = new nodo("clase",$3,@1.first_line, @1.first_column);
                  $$->hijos.append(*$1);
                  $$->hijos.append(*$5);
              }
        |clase id illave  INSCLASE fllave
              {
                  $$ = new nodo("clase",$2,@1.first_line, @1.first_column);
                  nodo *nod = new nodo("visibilidad","publico",@1.first_line, @1.first_column);
                  $$->hijos.append(*nod);
                  $$->hijos.append(*$4);
              }
         // Con herencia
        |VISIBILIDAD clase id heredade id illave INSCLASE fllave
              {
                  $$ = new nodo("clase",$3,@1.first_line, @1.first_column);
                  $$->hijos.append(*$1);
                  nodo *padre = new nodo("herencia",$5,@5.first_line,@5.first_column);
                  $$->hijos.append(*padre);
                  $$->hijos.append(*$7);
              }
        |clase id  heredade id illave  INSCLASE fllave
              {
                  $$ = new nodo("clase",$2,@1.first_line, @1.first_column);
                  nodo *nod = new nodo("visibilidad","publico",@1.first_line, @1.first_column);
                  $$->hijos.append(*nod);
                  nodo *padre = new nodo("herencia",$4,@4.first_line,@4.first_column);
                  $$->hijos.append(*padre);
                  $$->hijos.append(*$6);
              }
              ;
/*
ATRIBUTOS: ATRIBUTOS ATRIBUTO
              {
                $$=$1;
                $$->hijos.append(*$2);
              }
           |ATRIBUTO
              {
                  $$ = new nodo("atributos","atributos",@1.first_line, @1.first_column);
                  $$->hijos.append(*$1);
              };*/


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
               |id DIMENSIONES ACCESO  TIPOASIG VALAS
                           {
                           $$=$4;
                           nodo *nod = new nodo("id",$1,@1.first_line, @1.first_column);
                           nod->hijos.append(*$2);
                           $$->hijos.prepend(*nod);
                           $$->hijos.append(*$5);
                           };
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
            nodo *nuevo = new nodo("d","d",@1.first_line, @1.first_column);
            nuevo->add(*$1);
            nodo *nodoid =  new nodo("id",$2,@2.first_line,@2.first_column);
            nuevo->add(*nodoid);
            $$ = nuevo;
         }
        |TIPO id igual VALAS {
             nodo *nuevo = new nodo("da","da",@1.first_line, @1.first_column);
             nuevo->add(*$1);
             nodo *nodoid =  new nodo("id",$2,@2.first_line,@2.first_column);
             nuevo->add(*nodoid);
             nuevo->add(*$4);
             $$ = nuevo;}
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
            | iCor EXPL fCor  {  $$= new nodo("dim","dim",@1.first_line, @1.first_column); $$->add(*$2);}
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
       ;

TIPO: tipoBooleano  {$$= new nodo("tipo",$1,@1.first_line,@1.first_column);}
    | tipoEntero    {$$= new nodo("tipo",$1,@1.first_line,@1.first_column);}
    | tipoCaracter  {$$= new nodo("tipo",$1,@1.first_line,@1.first_column);}
    | tipoDecimal   {$$= new nodo("tipo",$1,@1.first_line,@1.first_column);}
    | id {$$= new nodo("tipo",$1,@1.first_line,@1.first_column);}
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
         //| parA EXPL parC {$$ = new nodo("expl","expl",@1.first_line,@1.first_column); $$->add(*$2);}
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
        //|parA EXPA parC{ $$ = $2;} // (E)
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
         ;
        // LLAMADAS funciones
        // ACCESOS a objetos
         //resultado_op = 5 - (9 + variable)*14;
        //   vector[4] ,  vector.vad.vector[3]

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
         }



/*
E:   E suma T{nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column);  nod->add(*$1); nod->add(*$3); $$=nod;}
    |E menos T{nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1); nod->add(*$3); $$=nod;}
    |T{ $$=$1;};



T:   T multi F {nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1); nod->add(*$3); $$=nod;}
    |T division F {nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1); nod->add(*$3); $$=nod;}
    |F{$$=$1;};



F:    F potencia PRIM { nodo *nod = new nodo("expa",$2,@2.first_line, @2.first_column); nod->add(*$1);  nod->add(*$3);  $$=nod ;  }
     |PRIM{$$=$1;}

PRIM: id { $$ = new nodo("var",$1,@1.first_line, @1.first_column);}
     |entero { $$ = new nodo("entero",$1,@1.first_line, @1.first_column);}
     |caracter { $$ = new nodo("caracter",$1,@1.first_line, @1.first_column);}
     |booleano { $$ = new nodo("booleano",$1,@1.first_line, @1.first_column);}
     |E{$$=$1;};
*/







/*
EXPA:    EXPA suma EXPA{nodo nodo = new nodo("+"); nod->add(*$1); nod->add(*$3); $$= nodo;}
        |EXPA resta EXPA{nodo nodo = new nodo("-"); nod->add(*$1); nod->add(*$3); $$= nodo;}
        |EXPA multi EXPA{nodo nodo = new nodo("*"); nod->add(*$1); nod->add(*$3); $$= nodo;}
        |EXPA div EXPA{nodo nodo = new nodo("/"); nod->add(*$1); nod->add(*$3); $$= nodo;}
        |EXPA potencia EXPA{nodo nodo = new nodo("^"); nod->add(*$1); nod->add(*$3); $$= nodo;}
        |menos EXPA {nodo  nodo = new nodo("-"); nod->add(*$2); $$ = nodo;}
        |parA EXPA parC{$$ = $2;}
        |entero {$$ = new nodo("entero",$1);}
        |id {$$ = new nodo("variable",$1);};
        |llamada
 *      |acceso a objetos y metodos
*/
%%
