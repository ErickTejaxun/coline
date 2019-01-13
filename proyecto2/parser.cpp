/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sintactico.yy" /* yacc.c:339  */

#include "scanner.h"//se importa el header del analisis sintactico
#include <iostream> //libreria para imprimir en cosola de C
#include <QString> //libreria para manejo de STRINGS de QT
#include "nodo.h"
#include <QTextEdit> //libreria QTextEdit de QT para poder mostrar el resultado en pantalla
#include <errorT.h>
#include "qlist.h"
#include <QtDebug>

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

#line 97 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    entero = 258,
    decimal = 259,
    caracter = 260,
    booleano = 261,
    cadena = 262,
    id = 263,
    parA = 264,
    parC = 265,
    illave = 266,
    fllave = 267,
    iCor = 268,
    fCor = 269,
    dosP = 270,
    coma = 271,
    aumento = 272,
    decremento = 273,
    masigual = 274,
    porigual = 275,
    menosigual = 276,
    divigual = 277,
    suma = 278,
    menos = 279,
    multi = 280,
    division = 281,
    potencia = 282,
    mayor = 283,
    menor = 284,
    mayorigual = 285,
    menorigual = 286,
    igualigual = 287,
    desigual = 288,
    o = 289,
    y = 290,
    igual = 291,
    no = 292,
    interrogacion = 293,
    tipoBooleano = 294,
    tipoEntero = 295,
    tipoCaracter = 296,
    tipoDecimal = 297,
    imprimir = 298,
    concatenar = 299,
    tamanio = 300,
    verdadero = 301,
    falso = 302,
    convertirAcadena = 303,
    convertirAentero = 304,
    clase = 305,
    este = 306,
    publico = 307,
    privado = 308,
    protegido = 309,
    vacio = 310,
    heredade = 311,
    retornar = 312,
    importar = 313,
    sobreescribir = 314,
    principal = 315,
    nuevo = 316,
    nada = 317,
    detener = 318,
    continuar = 319,
    si = 320,
    sinosi = 321,
    sino = 322,
    selecciona = 323,
    caso = 324,
    defecto = 325,
    mientras = 326,
    hacer = 327,
    para = 328,
    lista = 329,
    insertar = 330,
    obtener = 331,
    buscar = 332,
    pila = 333,
    apilar = 334,
    desapilar = 335,
    cola = 336,
    encolar = 337,
    desencolar = 338,
    mostraredd = 339,
    leer_teclado = 340,
    puntoComa = 341,
    punto = 342,
    modulo = 343
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 37 "sintactico.yy" /* yacc.c:355  */

//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class nodo *nodito;

#line 232 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  492

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   209,   209,   211,   212,   216,   217,   220,   225,   232,
     239,   248,   259,   264,   272,   278,   284,   285,   286,   292,
     301,   302,   305,   306,   307,   308,   309,   310,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     327,   336,   344,   352,   360,   371,   382,   391,   397,   408,
     414,   418,   424,   430,   439,   446,   453,   463,   468,   474,
     482,   489,   496,   504,   511,   523,   524,   525,   527,   537,
     550,   552,   558,   563,   570,   576,   585,   601,   619,   630,
     644,   653,   663,   674,   686,   697,   711,   716,   721,   728,
     768,   810,   850,   896,   905,   915,   936,   961,   973,   974,
     975,   976,   977,   982,   990,  1002,  1009,  1016,  1030,  1039,
    1047,  1058,  1059,  1067,  1073,  1082,  1093,  1094,  1099,  1100,
    1103,  1104,  1105,  1106,  1107,  1113,  1122,  1123,  1124,  1125,
    1128,  1129,  1130,  1131,  1132,  1133,  1134,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,  1149,  1156,  1157,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1171,  1172,  1181,  1189,  1194,
    1199,  1208,  1213,  1223,  1234,  1246,  1256,  1265,  1277,  1278,
    1282,  1290,  1300,  1309,  1319,  1327,  1337,  1346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "entero", "decimal", "caracter",
  "booleano", "cadena", "id", "parA", "parC", "illave", "fllave", "iCor",
  "fCor", "dosP", "coma", "aumento", "decremento", "masigual", "porigual",
  "menosigual", "divigual", "suma", "menos", "multi", "division",
  "potencia", "mayor", "menor", "mayorigual", "menorigual", "igualigual",
  "desigual", "o", "y", "igual", "no", "interrogacion", "tipoBooleano",
  "tipoEntero", "tipoCaracter", "tipoDecimal", "imprimir", "concatenar",
  "tamanio", "verdadero", "falso", "convertirAcadena", "convertirAentero",
  "clase", "este", "publico", "privado", "protegido", "vacio", "heredade",
  "retornar", "importar", "sobreescribir", "principal", "nuevo", "nada",
  "detener", "continuar", "si", "sinosi", "sino", "selecciona", "caso",
  "defecto", "mientras", "hacer", "para", "lista", "insertar", "obtener",
  "buscar", "pila", "apilar", "desapilar", "cola", "encolar", "desencolar",
  "mostraredd", "leer_teclado", "puntoComa", "punto", "modulo", "$accept",
  "INICIO", "SENTENCIASG", "INSTRUCCIONG", "IMPRIMIR", "CONCATENAR",
  "IMPORTAR", "ICLASES", "ICLASE", "SENTENCIAS", "INSTRUCCION", "LEER",
  "PARA", "HACER", "MIENTRAS", "SI", "ELSE", "SINOSI", "SELECCIONAR",
  "CASOS", "LCASOS", "CASO", "RETORNO", "ATRIBUTO", "VISIBILIDAD",
  "INSTANCIA", "LPARAMETROS", "PARAMETROS", "PARAMETRO", "PRINCIPAL",
  "CONSTRUCTOR", "FUNCION", "DIMS", "DIM", "CLASE", "ASIGNACION",
  "TIPOASIG", "DECLARACION", "DECESTRUCTURAS", "DECLARACIONARRAY",
  "DIMENSIONES", "VALORESA", "LVALORES", "VALORES", "VALAS", "TIPO",
  "SENTSELEC", "EXPL", "EXPR", "EXPA", "LPAR", "LLAMADA", "UNARIOS",
  "ACCESO", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

#define YYPACT_NINF -265

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-265)))

#define YYTABLE_NINF -125

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     416,    12,  -265,  -265,  -265,    25,    53,   416,  -265,    -6,
      10,  -265,    39,   110,  -265,  -265,  -265,   122,  1152,   153,
     144,    56,   123,  -265,  -265,  -265,  -265,   156,   497,   205,
     473,  -265,  -265,   269,  -265,  -265,  -265,   120,   154,   292,
     213,  -265,  1152,   244,   202,   274,   410,  -265,  -265,   307,
     330,  -265,  -265,   293,   338,   348,   281,   289,   315,  -265,
    -265,   172,   387,   340,  -265,  1152,   642,   401,  -265,   413,
     418,  -265,   440,   202,   342,   417,   456,   202,   462,   463,
    -265,  -265,   180,   400,   202,  3071,  3071,   138,  -265,   467,
    -265,   986,  -265,  1152,   466,   202,   469,   477,   470,  2920,
     478,   202,   482,   202,   480,   484,  -265,  -265,  -265,  -265,
    -265,     0,  3071,   794,  3071,   486,   489,   412,   492,  -265,
     412,   186,  -265,   237,  -265,  -265,  -265,  -265,   398,  3071,
     290,   202,  -265,  1069,  2920,  -265,   490,   491,    22,   495,
     499,   412,  3071,   420,   425,   511,   512,   513,   518,   514,
     516,   522,   523,   531,   532,   457,   458,   928,  -265,   459,
    -265,   460,  -265,  -265,  -265,   468,   479,   488,   496,   500,
     540,    74,   217,   503,   544,   553,  2920,   558,   202,   565,
     435,   575,    -5,   504,    84,   170,  -265,  3071,  3071,   504,
     585,   504,  -265,  3071,  3071,  -265,  -265,   794,   794,   794,
     794,   794,   794,   794,   794,   794,   794,   794,   794,  3071,
     363,   586,  -265,   298,   590,  -265,  1011,  2920,  -265,  -265,
    -265,  -265,  -265,  3071,   136,   616,  3071,    -3,   298,  -265,
    -265,  3071,  3071,  3071,  2920,   240,   560,   579,   580,   593,
    3071,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,   146,  -265,  3071,  -265,  2920,   607,  1094,   615,
     617,  2920,   412,   298,   174,   262,   504,   621,  -265,   106,
     132,   855,   597,  -265,   170,   170,   229,   229,   392,    74,
      74,    74,    74,    74,    74,   229,    37,  -265,  3071,   273,
     622,  -265,  1177,  -265,  3071,    -3,   624,   143,   216,  3071,
     184,   192,   302,  1260,   114,   412,   549,   557,   631,   559,
     581,   583,   587,   636,   372,  -265,  1343,  2920,  -265,  2920,
     638,  1426,   504,   412,  3071,  3003,   490,   317,  -265,  -265,
    -265,   182,  3071,   408,   298,  -265,   641,  2920,  -265,  -265,
    3071,  -265,  -265,  3071,  -265,   644,   645,   646,   576,   136,
      -3,  3071,  3071,   625,   584,   588,   582,   601,  3071,  -265,
    1509,  1592,  2920,  -265,   504,   298,  -265,   197,  3011,   490,
    -265,   298,  -265,  3071,  3071,  1675,  -265,    29,  2920,   345,
    2920,   660,    -3,   -12,     3,   662,   663,   664,  -265,   308,
    -265,  -265,  1758,  -265,  -265,   268,   298,   442,  -265,  -265,
    3071,  1841,  3071,   659,   667,   377,  -265,  1924,  3071,  3078,
    3078,   202,   202,   202,  -265,  -265,  -265,  -265,   325,   389,
     329,   677,  -265,   674,  -265,  -265,   352,   114,   680,   559,
     681,   682,   690,   693,   695,   696,  -265,   698,   697,  -265,
     397,   699,  2920,   700,  -265,   701,   702,   703,   704,  -265,
    -265,  -265,  3071,  2920,   707,   706,  2920,  2007,  2920,  2920,
    2920,  2920,  2920,   356,  2090,  3071,  2920,  2173,  -265,  2256,
    2339,  2422,  2505,  2588,   710,  -265,   370,  2671,  -265,  -265,
    -265,  -265,  -265,  -265,  2920,   711,  -265,  2754,  2920,  -265,
    2837,  -265
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    65,    66,    67,     0,     0,     2,     4,     0,
       0,     6,     0,     0,     1,     3,     5,     0,     0,     0,
       0,     0,   124,   120,   121,   122,   123,     0,     0,     0,
       0,    13,    16,     0,    17,    18,    14,     0,     0,     0,
       0,    11,     0,     0,    71,     0,     0,    19,    15,     0,
       0,    90,    12,   124,     0,     0,     0,     0,     0,    62,
      64,   103,     0,     0,    87,     0,     0,     0,   124,     0,
      70,    73,     0,    71,     0,     0,     0,    71,     0,     0,
      61,    63,   103,     0,    71,     0,     0,   108,    88,     0,
      86,     0,    89,     0,     0,     0,    74,     0,     0,     0,
       0,    71,     0,    71,     0,     0,   148,   150,   149,   151,
     152,   144,     0,     0,     0,     0,     0,     0,     0,   153,
     146,     0,   129,   136,   160,   154,   104,   119,   118,     0,
       0,    71,    92,     0,     0,    72,    75,     0,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      34,     0,    29,    30,    32,     0,     0,     0,     0,     0,
       0,     0,   160,   154,     0,     0,     0,     0,    71,     0,
       0,     0,   145,   167,     0,   143,   128,     0,     0,   157,
       0,   147,   112,     0,     0,   168,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   109,     0,    91,     0,     0,    98,    99,
     100,   101,   102,     0,   145,     0,     0,   157,    60,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    25,    76,    20,    39,    33,    27,    24,    22,
      37,    23,   103,    28,     0,    31,     0,     0,     0,     0,
       0,     0,   163,   162,     0,   174,   156,     0,   155,     0,
       0,     0,   127,   126,   137,   138,   139,   140,   141,   133,
     132,   135,   134,   130,   131,   142,     0,   111,     0,     0,
       0,    79,     0,    93,     0,   156,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,    77,     0,
       0,     0,   165,   164,     0,     0,   177,   170,   158,   159,
      69,     0,     0,     0,   117,   113,     0,     0,    85,    94,
       0,     8,     7,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,    78,
       0,     0,     0,    84,   166,   161,   175,     0,     0,   173,
      68,   125,   115,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
      82,    81,     0,   176,   171,     0,   116,     0,    83,     9,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,    40,    80,   172,   114,     0,    47,
       0,     0,    54,     0,    57,    46,     0,   144,     0,   160,
     154,     0,   154,     0,     0,     0,    10,     0,     0,    48,
      50,     0,     0,     0,    45,     0,     0,     0,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,     0,     0,     0,     0,    51,     0,     0,    59,    55,
      41,    43,    42,    44,     0,     0,    49,     0,     0,    53,
       0,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -265,  -265,  -265,   716,  -265,   493,  -265,    28,   -26,   -31,
     359,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,   304,  -265,  -265,   124,  -265,   -52,  -265,   629,  -265,
     705,   712,     4,    23,  -265,  -234,  -170,    72,  -265,    78,
     -82,  -265,  -265,   351,  -218,   -18,  -265,   556,  -265,   405,
    -264,   -88,   100,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,   155,   156,     9,    30,    31,   157,
     158,   159,   160,   161,   162,   163,   439,   440,   164,   404,
     405,   406,   165,    32,    33,   120,    69,    70,    71,    34,
      35,    36,    63,    64,    11,   166,   223,   167,   168,   169,
      87,   212,   289,   333,   126,   170,   127,   128,   122,   171,
     264,   124,   125,   183
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   306,   254,   189,    52,   293,   191,   331,   129,   180,
      49,   172,    39,    85,   136,    58,   218,   219,   220,   221,
      12,    97,   193,   194,    39,   100,    72,   227,    74,   182,
    -124,   180,   105,   222,    13,    85,   315,   193,   194,   399,
      52,   218,   219,   220,   221,   400,   172,    39,    39,   175,
      18,   177,   332,    14,   294,    72,   224,   299,   222,    72,
      17,   367,    83,   193,   194,    52,    72,    42,   266,   172,
      66,   193,   194,    39,   409,    39,   339,    72,    83,   214,
      16,   344,   181,    72,   267,    72,    90,   181,   172,   410,
      37,   195,   196,    91,   268,    19,    38,   197,   198,   199,
     200,   201,    37,   216,   395,    56,    90,    52,    38,   181,
     295,    57,    43,    72,    37,    39,   328,    20,   193,   194,
      38,   133,   376,   180,    10,   340,   260,    85,   172,   172,
      21,    10,    44,   218,   219,   220,   221,    37,    37,   254,
     193,   194,   329,    38,    38,   258,   172,   309,   322,   129,
     222,   129,    46,   342,    41,   218,   219,   220,   221,    85,
      72,    40,   208,    37,    45,    37,   193,   194,   172,    38,
     172,    38,   222,   172,   130,   428,   431,   193,   194,   294,
     299,    84,    86,   326,   323,    85,   292,   195,   196,   103,
     324,   350,   370,    85,   345,   199,   200,   201,   324,   173,
     192,   181,   346,   303,   172,    37,    59,   393,    86,   364,
      68,    38,   340,   324,    50,   172,    86,   308,   193,   194,
     193,   194,   349,   181,    65,   316,   193,   194,   172,   172,
     321,   172,   343,   172,   173,   382,   218,   219,   220,   221,
      60,    23,    24,    25,    26,   369,   195,   196,   304,   172,
     193,   194,    67,   222,   195,   196,   201,   173,   208,   254,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   325,   172,   172,   172,    85,   173,    53,   416,    23,
      24,    25,    26,    73,   324,   335,   360,   172,   361,   336,
     172,   305,   172,   106,   107,   108,   109,   110,   111,   112,
      61,   211,    77,   253,   172,    62,   375,   307,    23,    24,
      25,    26,   347,   172,   113,    75,   173,   173,   414,   172,
      62,   429,   429,    82,    54,   208,   368,   114,    62,    55,
      85,   392,   193,   194,   173,   436,   193,   194,   115,   116,
      76,   117,   193,   194,   441,   224,    78,   401,    89,   407,
      98,   118,   119,    62,   172,    62,   173,    79,   173,   193,
     194,   173,   444,   193,   194,   172,   474,    80,   172,   172,
     172,   172,   172,   172,   172,    81,   172,   287,   172,   172,
     485,   172,   172,   172,   172,   172,   193,   194,   358,   172,
     193,   194,   173,   433,   434,   435,   172,   193,   194,   172,
     172,    88,   172,   173,   193,   194,   193,   194,   104,   195,
     196,   457,    93,    62,   402,   403,   173,   173,    53,   173,
     372,   173,   464,    94,   373,   467,    84,   469,   470,   471,
     472,   473,   193,   194,    95,   477,   209,   173,   106,   107,
     108,   109,   110,   111,   112,   262,   402,   423,    96,    23,
      24,    25,    26,   487,   417,   437,   438,   490,   373,   113,
     173,   173,   173,   454,   455,    54,     1,    99,     2,     3,
       4,   101,   114,   102,     5,   173,   131,   134,   173,   103,
     173,    22,    85,   115,   116,    51,   117,   137,   174,   178,
     123,   123,   173,   176,   179,   187,   118,   119,   188,   181,
     190,   173,   217,   129,   225,    22,   229,   173,   226,   430,
     432,   230,    23,    24,    25,    26,   244,   123,   185,   123,
     231,   232,   233,   235,   236,     2,     3,     4,    27,   234,
     237,   238,    28,    29,   123,   123,    23,    24,    25,    26,
     239,   240,   173,   241,   242,   245,   246,   123,   252,     2,
       3,     4,    27,   173,   247,   256,   173,   173,   173,   173,
     173,   173,   173,   257,   173,   248,   173,   173,   259,   173,
     173,   173,   173,   173,   249,   244,   261,   173,   218,   219,
     220,   221,   250,   265,   173,   123,   251,   173,   173,   255,
     173,   267,   123,   123,   271,   222,   310,   288,   123,   123,
     290,   313,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   123,   311,   312,   244,   317,   106,
     107,   108,   109,   110,   111,   112,   319,   320,   123,   327,
     123,   123,   194,   337,   341,   351,   123,   123,   123,   353,
     113,   121,   354,   352,   355,   123,   357,   381,   356,   362,
      22,   244,   374,   114,    92,   378,   379,   380,   385,   123,
     140,    86,   244,   387,   115,   116,   386,   117,   184,   408,
     186,   411,   412,   413,   421,   244,   123,   118,   119,   422,
     244,    23,    24,    25,    26,   210,   213,   388,   442,   443,
     445,   446,   447,   123,     2,     3,     4,    27,   228,   123,
     448,    28,    29,   449,   123,   450,   451,   452,   453,   424,
     456,   458,   459,   460,   461,   462,   465,   466,   296,   244,
     244,   484,   488,    15,   135,   397,     0,     0,     0,   123,
     123,     0,     0,    47,   244,     0,   263,   123,     0,     0,
      48,     0,     0,   269,   270,   123,     0,     0,   123,   272,
     273,   244,     0,     0,     0,     0,   123,   123,     0,     0,
     244,     0,     0,   123,     0,   286,   244,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,   123,   123,
       0,   297,   298,     0,     0,     0,     0,   300,   301,   302,
       0,     0,     0,     0,     0,     0,   314,   106,   107,   108,
     109,   110,   111,   112,     0,   123,     0,   123,     0,     0,
       0,     0,     0,   123,     0,     0,   244,     0,   113,     0,
       0,     0,     0,   244,     0,     0,   244,   263,   244,   244,
     244,   244,   244,     0,     0,     0,   244,     0,     0,     0,
       0,     0,   115,   116,   334,   117,   244,     0,     0,   244,
       0,     0,     0,     0,     0,   118,   119,   123,   106,   107,
     108,   109,   110,   111,   112,   330,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,   113,
     365,   263,     0,     0,     0,     0,     0,     0,   371,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,   377,
       0,     0,     0,   115,   116,     0,   117,   383,   384,     0,
       0,     0,     0,     0,   389,     0,   118,   119,     0,     0,
       0,     0,     0,     0,   263,     0,     0,     0,     0,   396,
     334,   106,   107,   108,   109,   110,   138,   112,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,   418,     0,   420,     0,
       0,     0,     0,     0,   426,     0,     0,    23,    24,    25,
      26,   139,   140,     0,     0,     0,   115,   116,     0,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,   118,
     119,   143,   144,   145,    22,     0,   146,     0,   132,   147,
     148,   149,   150,     0,     0,     0,   151,     0,   463,   152,
       0,     0,   153,   154,   106,   107,   108,   109,   110,   138,
     112,   476,     0,   291,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     2,     3,
       4,    27,     0,     0,     0,    28,    29,     0,     0,     0,
      23,    24,    25,    26,   139,   140,     0,     0,     0,   115,
     116,     0,   141,     0,     0,     0,     0,     0,   142,     0,
       0,     0,   118,   119,   143,   144,   145,    22,     0,   146,
       0,   215,   147,   148,   149,   150,     0,     0,     0,   151,
       0,     0,   152,     0,     0,   153,   154,   106,   107,   108,
     109,   110,   138,   112,     0,     0,   318,     0,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     2,     3,     4,    27,     0,     0,     0,    28,    29,
       0,     0,     0,    23,    24,    25,    26,   139,   140,     0,
       0,     0,   115,   116,     0,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,   118,   119,   143,   144,   145,
      22,     0,   146,     0,     0,   147,   148,   149,   150,     0,
       0,     0,   151,     0,     0,   152,     0,     0,   153,   154,
     106,   107,   108,   109,   110,   138,   112,     0,     0,   338,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     2,     3,     4,    27,     0,     0,
       0,    28,    29,     0,     0,     0,    23,    24,    25,    26,
     139,   140,     0,     0,     0,   115,   116,     0,   141,     0,
       0,     0,     0,     0,   142,     0,     0,     0,   118,   119,
     143,   144,   145,     0,     0,   146,     0,     0,   147,   148,
     149,   150,     0,     0,     0,   151,     0,     0,   152,     0,
       0,   153,   154,   106,   107,   108,   109,   110,   138,   112,
       0,     0,   348,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   139,   140,     0,     0,     0,   115,   116,
       0,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,   118,   119,   143,   144,   145,     0,     0,   146,     0,
       0,   147,   148,   149,   150,     0,     0,     0,   151,     0,
       0,   152,     0,     0,   153,   154,   106,   107,   108,   109,
     110,   138,   112,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   139,   140,     0,     0,
       0,   115,   116,     0,   141,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   118,   119,   143,   144,   145,     0,
       0,   146,     0,     0,   147,   148,   149,   150,     0,     0,
       0,   151,     0,     0,   152,     0,     0,   153,   154,   106,
     107,   108,   109,   110,   138,   112,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   139,
     140,     0,     0,     0,   115,   116,     0,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,   118,   119,   143,
     144,   145,     0,     0,   146,     0,     0,   147,   148,   149,
     150,     0,     0,     0,   151,     0,     0,   152,     0,     0,
     153,   154,   106,   107,   108,   109,   110,   138,   112,     0,
       0,   390,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   139,   140,     0,     0,     0,   115,   116,     0,
     141,     0,     0,     0,     0,     0,   142,     0,     0,     0,
     118,   119,   143,   144,   145,     0,     0,   146,     0,     0,
     147,   148,   149,   150,     0,     0,     0,   151,     0,     0,
     152,     0,     0,   153,   154,   106,   107,   108,   109,   110,
     138,   112,     0,     0,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   139,   140,     0,     0,     0,
     115,   116,     0,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,   118,   119,   143,   144,   145,     0,     0,
     146,     0,     0,   147,   148,   149,   150,     0,     0,     0,
     151,     0,     0,   152,     0,     0,   153,   154,   106,   107,
     108,   109,   110,   138,   112,     0,     0,   398,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   139,   140,
       0,     0,     0,   115,   116,     0,   141,     0,     0,     0,
       0,     0,   142,     0,     0,     0,   118,   119,   143,   144,
     145,     0,     0,   146,     0,     0,   147,   148,   149,   150,
       0,     0,     0,   151,     0,     0,   152,     0,     0,   153,
     154,   106,   107,   108,   109,   110,   138,   112,     0,     0,
     415,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   139,   140,     0,     0,     0,   115,   116,     0,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,   118,
     119,   143,   144,   145,     0,     0,   146,     0,     0,   147,
     148,   149,   150,     0,     0,     0,   151,     0,     0,   152,
       0,     0,   153,   154,   106,   107,   108,   109,   110,   138,
     112,     0,     0,   419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   139,   140,     0,     0,     0,   115,
     116,     0,   141,     0,     0,     0,     0,     0,   142,     0,
       0,     0,   118,   119,   143,   144,   145,     0,     0,   146,
       0,     0,   147,   148,   149,   150,     0,     0,     0,   151,
       0,     0,   152,     0,     0,   153,   154,   106,   107,   108,
     109,   110,   138,   112,     0,     0,   425,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   139,   140,     0,
       0,     0,   115,   116,     0,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,   118,   119,   143,   144,   145,
       0,     0,   146,     0,     0,   147,   148,   149,   150,     0,
       0,     0,   151,     0,     0,   152,     0,     0,   153,   154,
     106,   107,   108,   109,   110,   138,   112,     0,     0,   468,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     139,   140,     0,     0,     0,   115,   116,     0,   141,     0,
       0,     0,     0,     0,   142,     0,     0,     0,   118,   119,
     143,   144,   145,     0,     0,   146,     0,     0,   147,   148,
     149,   150,     0,     0,     0,   151,     0,     0,   152,     0,
       0,   153,   154,   106,   107,   108,   109,   110,   138,   112,
       0,     0,   475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   139,   140,     0,     0,     0,   115,   116,
       0,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,   118,   119,   143,   144,   145,     0,     0,   146,     0,
       0,   147,   148,   149,   150,     0,     0,     0,   151,     0,
       0,   152,     0,     0,   153,   154,   106,   107,   108,   109,
     110,   138,   112,     0,     0,   478,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   139,   140,     0,     0,
       0,   115,   116,     0,   141,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   118,   119,   143,   144,   145,     0,
       0,   146,     0,     0,   147,   148,   149,   150,     0,     0,
       0,   151,     0,     0,   152,     0,     0,   153,   154,   106,
     107,   108,   109,   110,   138,   112,     0,     0,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   139,
     140,     0,     0,     0,   115,   116,     0,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,   118,   119,   143,
     144,   145,     0,     0,   146,     0,     0,   147,   148,   149,
     150,     0,     0,     0,   151,     0,     0,   152,     0,     0,
     153,   154,   106,   107,   108,   109,   110,   138,   112,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   139,   140,     0,     0,     0,   115,   116,     0,
     141,     0,     0,     0,     0,     0,   142,     0,     0,     0,
     118,   119,   143,   144,   145,     0,     0,   146,     0,     0,
     147,   148,   149,   150,     0,     0,     0,   151,     0,     0,
     152,     0,     0,   153,   154,   106,   107,   108,   109,   110,
     138,   112,     0,     0,   481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   139,   140,     0,     0,     0,
     115,   116,     0,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,   118,   119,   143,   144,   145,     0,     0,
     146,     0,     0,   147,   148,   149,   150,     0,     0,     0,
     151,     0,     0,   152,     0,     0,   153,   154,   106,   107,
     108,   109,   110,   138,   112,     0,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   139,   140,
       0,     0,     0,   115,   116,     0,   141,     0,     0,     0,
       0,     0,   142,     0,     0,     0,   118,   119,   143,   144,
     145,     0,     0,   146,     0,     0,   147,   148,   149,   150,
       0,     0,     0,   151,     0,     0,   152,     0,     0,   153,
     154,   106,   107,   108,   109,   110,   138,   112,     0,     0,
     483,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   139,   140,     0,     0,     0,   115,   116,     0,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,   118,
     119,   143,   144,   145,     0,     0,   146,     0,     0,   147,
     148,   149,   150,     0,     0,     0,   151,     0,     0,   152,
       0,     0,   153,   154,   106,   107,   108,   109,   110,   138,
     112,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   139,   140,     0,     0,     0,   115,
     116,     0,   141,     0,     0,     0,     0,     0,   142,     0,
       0,     0,   118,   119,   143,   144,   145,     0,     0,   146,
       0,     0,   147,   148,   149,   150,     0,     0,     0,   151,
       0,     0,   152,     0,     0,   153,   154,   106,   107,   108,
     109,   110,   138,   112,     0,     0,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   139,   140,     0,
       0,     0,   115,   116,     0,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,   118,   119,   143,   144,   145,
       0,     0,   146,     0,     0,   147,   148,   149,   150,     0,
       0,     0,   151,     0,     0,   152,     0,     0,   153,   154,
     106,   107,   108,   109,   110,   138,   112,     0,     0,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     139,   140,     0,     0,     0,   115,   116,     0,   141,     0,
       0,     0,     0,     0,   142,     0,     0,     0,   118,   119,
     143,   144,   145,     0,     0,   146,     0,     0,   147,   148,
     149,   150,     0,     0,     0,   151,     0,     0,   152,     0,
       0,   153,   154,   106,   107,   108,   109,   110,   138,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   139,   140,     0,     0,     0,   115,   116,
       0,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,   118,   119,   143,   144,   145,     0,     0,   146,     0,
       0,   147,   148,   149,   150,     0,     0,     0,   151,     0,
       0,   152,     0,     0,   153,   154,   106,   107,   108,   109,
     110,   111,   112,   366,   106,   107,   108,   109,   110,   111,
     112,   394,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,   115,   116,     0,   117,     0,     0,     0,     0,   115,
     116,     0,   117,     0,   118,   119,     0,     0,     0,     0,
       0,     0,   118,   119,   106,   107,   108,   109,   110,   111,
     112,   106,   107,   108,   109,   110,   427,   112,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,     0,   117,     0,     0,     0,   115,   116,     0,   141,
       0,     0,   118,   119,     0,     0,     0,     0,     0,   118,
     119
};

static const yytype_int16 yycheck[] =
{
      18,   235,   172,   117,    30,   223,   120,   271,    13,     9,
      28,    99,    30,    13,    96,    33,    19,    20,    21,    22,
       8,    73,    34,    35,    42,    77,    44,   141,    46,   111,
       8,     9,    84,    36,     9,    13,   254,    34,    35,    10,
      66,    19,    20,    21,    22,    16,   134,    65,    66,   101,
      11,   103,    15,     0,   224,    73,   138,   227,    36,    77,
      50,   325,    58,    34,    35,    91,    84,    11,   182,   157,
      42,    34,    35,    91,    86,    93,   294,    95,    74,   131,
      86,   299,    87,   101,    87,   103,    63,    87,   176,    86,
      18,    17,    18,    65,    10,    56,    18,    23,    24,    25,
      26,    27,    30,   134,   368,    33,    83,   133,    30,    87,
     224,    33,    56,   131,    42,   133,    10,     7,    34,    35,
      42,    93,   340,     9,     0,   295,   178,    13,   216,   217,
       8,     7,     9,    19,    20,    21,    22,    65,    66,   309,
      34,    35,    10,    65,    66,   176,   234,   235,   262,    13,
      36,    13,    28,    10,    10,    19,    20,    21,    22,    13,
     178,     8,    88,    91,     8,    93,    34,    35,   256,    91,
     258,    93,    36,   261,    36,   409,   410,    34,    35,   349,
     350,     9,    36,   265,    10,    13,   217,    17,    18,     9,
      16,   305,    10,    13,    10,    25,    26,    27,    16,    99,
      14,    87,    10,   234,   292,   133,    86,    10,    36,   323,
       8,   133,   382,    16,     9,   303,    36,   235,    34,    35,
      34,    35,   304,    87,    11,   256,    34,    35,   316,   317,
     261,   319,    16,   321,   134,   349,    19,    20,    21,    22,
      86,    39,    40,    41,    42,   327,    17,    18,     8,   337,
      34,    35,     8,    36,    17,    18,    27,   157,    88,   429,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     9,   360,   361,   362,    13,   176,     8,    10,    39,
      40,    41,    42,     9,    16,    12,   317,   375,   319,    16,
     378,    51,   380,     3,     4,     5,     6,     7,     8,     9,
       8,    11,     9,    86,   392,    13,   337,   235,    39,    40,
      41,    42,    10,   401,    24,     8,   216,   217,    10,   407,
      13,   409,   410,     8,    55,    88,     9,    37,    13,    60,
      13,   362,    34,    35,   234,    10,    34,    35,    48,    49,
      10,    51,    34,    35,    15,   427,     8,   378,     8,   380,
       8,    61,    62,    13,   442,    13,   256,     9,   258,    34,
      35,   261,    10,    34,    35,   453,    10,    86,   456,   457,
     458,   459,   460,   461,   462,    86,   464,    14,   466,   467,
      10,   469,   470,   471,   472,   473,    34,    35,    16,   477,
      34,    35,   292,   411,   412,   413,   484,    34,    35,   487,
     488,    14,   490,   303,    34,    35,    34,    35,     8,    17,
      18,   442,    11,    13,    69,    70,   316,   317,     8,   319,
      12,   321,   453,    10,    16,   456,     9,   458,   459,   460,
     461,   462,    34,    35,    16,   466,    38,   337,     3,     4,
       5,     6,     7,     8,     9,    10,    69,    70,     8,    39,
      40,    41,    42,   484,    12,    66,    67,   488,    16,    24,
     360,   361,   362,    66,    67,    55,    50,    11,    52,    53,
      54,     9,    37,    10,    58,   375,     9,    11,   378,     9,
     380,     8,    13,    48,    49,    12,    51,    10,    10,     9,
      85,    86,   392,    11,    10,     9,    61,    62,     9,    87,
       8,   401,    11,    13,     9,     8,    86,   407,     9,   409,
     410,    86,    39,    40,    41,    42,   157,   112,   113,   114,
       9,     9,     9,     9,     8,    52,    53,    54,    55,    11,
       8,     8,    59,    60,   129,   130,    39,    40,    41,    42,
       9,     9,   442,    86,    86,    86,    86,   142,     8,    52,
      53,    54,    55,   453,    86,    11,   456,   457,   458,   459,
     460,   461,   462,    10,   464,    86,   466,   467,    10,   469,
     470,   471,   472,   473,    86,   216,    11,   477,    19,    20,
      21,    22,    86,     8,   484,   180,    86,   487,   488,    86,
     490,    87,   187,   188,     9,    36,    36,    11,   193,   194,
      10,     8,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    36,    36,   258,    11,     3,
       4,     5,     6,     7,     8,     9,    11,    10,   223,     8,
     225,   226,    35,    11,    10,    86,   231,   232,   233,     8,
      24,    85,    61,    86,    61,   240,    10,    71,    61,    11,
       8,   292,    11,    37,    12,    11,    11,    11,    74,   254,
      44,    36,   303,    81,    48,    49,    78,    51,   112,     9,
     114,     9,     9,     9,    15,   316,   271,    61,    62,    12,
     321,    39,    40,    41,    42,   129,   130,    86,    11,    15,
      10,    10,    10,   288,    52,    53,    54,    55,   142,   294,
      10,    59,    60,    10,   299,    10,    10,     9,    11,   405,
      11,    11,    11,    11,    11,    11,     9,    11,   225,   360,
     361,    11,    11,     7,    95,   374,    -1,    -1,    -1,   324,
     325,    -1,    -1,    28,   375,    -1,   180,   332,    -1,    -1,
      28,    -1,    -1,   187,   188,   340,    -1,    -1,   343,   193,
     194,   392,    -1,    -1,    -1,    -1,   351,   352,    -1,    -1,
     401,    -1,    -1,   358,    -1,   209,   407,    -1,    -1,    -1,
      -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,   373,   374,
      -1,   225,   226,    -1,    -1,    -1,    -1,   231,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,   240,     3,     4,     5,
       6,     7,     8,     9,    -1,   400,    -1,   402,    -1,    -1,
      -1,    -1,    -1,   408,    -1,    -1,   457,    -1,    24,    -1,
      -1,    -1,    -1,   464,    -1,    -1,   467,   271,   469,   470,
     471,   472,   473,    -1,    -1,    -1,   477,    -1,    -1,    -1,
      -1,    -1,    48,    49,   288,    51,   487,    -1,    -1,   490,
      -1,    -1,    -1,    -1,    -1,    61,    62,   452,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
     465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
     324,   325,    -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,   343,
      -1,    -1,    -1,    48,    49,    -1,    51,   351,   352,    -1,
      -1,    -1,    -1,    -1,   358,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,   373,
     374,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,   400,    -1,   402,    -1,
      -1,    -1,    -1,    -1,   408,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,     8,    -1,    68,    -1,    12,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    -1,   452,    81,
      -1,    -1,    84,    85,     3,     4,     5,     6,     7,     8,
       9,   465,    -1,    12,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    52,    53,
      54,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    61,    62,    63,    64,    65,     8,    -1,    68,
      -1,    12,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    61,    62,    63,    64,    65,
       8,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    85,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    85,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    85,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    -1,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    85,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    85,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    85,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    -1,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    10,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,     3,     4,     5,     6,     7,     8,
       9,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    61,
      62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,    53,    54,    58,    90,    91,    92,    95,
     113,   123,     8,     9,     0,    92,    86,    50,    11,    56,
       7,     8,     8,    39,    40,    41,    42,    55,    59,    60,
      96,    97,   112,   113,   118,   119,   120,   126,   128,   134,
       8,    10,    11,    56,     9,     8,   113,   119,   120,   134,
       9,    12,    97,     8,    55,    60,   126,   128,   134,    86,
      86,     8,    13,   121,   122,    11,    96,     8,     8,   115,
     116,   117,   134,     9,   134,     8,    10,     9,     8,     9,
      86,    86,     8,   121,     9,    13,    36,   129,    14,     8,
     122,    96,    12,    11,    10,    16,     8,   115,     8,    11,
     115,     9,    10,     9,     8,   115,     3,     4,     5,     6,
       7,     8,     9,    24,    37,    48,    49,    51,    61,    62,
     114,   136,   137,   138,   140,   141,   133,   135,   136,    13,
      36,     9,    12,    96,    11,   117,   129,    10,     8,    43,
      44,    51,    57,    63,    64,    65,    68,    71,    72,    73,
      74,    78,    81,    84,    85,    93,    94,    98,    99,   100,
     101,   102,   103,   104,   107,   111,   124,   126,   127,   128,
     134,   138,   140,   141,    10,   115,    11,   115,     9,    10,
       9,    87,   129,   142,   136,   138,   136,     9,     9,   142,
       8,   142,    14,    34,    35,    17,    18,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    88,    38,
     136,    11,   130,   136,   115,    12,    98,    11,    19,    20,
      21,    22,    36,   125,   129,     9,     9,   142,   136,    86,
      86,     9,     9,     9,    11,     9,     8,     8,     8,     9,
       9,    86,    86,    12,    99,    86,    86,    86,    86,    86,
      86,    86,     8,    86,   125,    86,    11,    10,    98,    10,
     115,    11,    10,   136,   139,     8,   142,    87,    10,   136,
     136,     9,   136,   136,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   136,    14,    11,   131,
      10,    12,    98,   133,   125,   142,    94,   136,   136,   125,
     136,   136,   136,    98,     8,    51,   124,   126,   134,   140,
      36,    36,    36,     8,   136,   133,    98,    11,    12,    11,
      10,    98,   142,    10,    16,     9,   129,     8,    10,    10,
      10,   139,    15,   132,   136,    12,    16,    11,    12,   133,
     125,    10,    10,    16,   133,    10,    10,    10,    12,   129,
     142,    86,    86,     8,    61,    61,    61,    10,    16,    12,
      98,    98,    11,    12,   142,   136,    10,   139,     9,   129,
      10,   136,    12,    16,    11,    98,   133,   136,    11,    11,
      11,    71,   142,   136,   136,    74,    78,    81,    86,   136,
      12,    12,    98,    10,    10,   139,   136,   132,    12,    10,
      16,    98,    69,    70,   108,   109,   110,    98,     9,    86,
      86,     9,     9,     9,    10,    12,    10,    12,   136,    12,
     136,    15,    12,    70,   110,    12,   136,     8,   124,   140,
     141,   124,   141,   134,   134,   134,    10,    66,    67,   105,
     106,    15,    11,    15,    10,    10,    10,    10,    10,    10,
      10,    10,     9,    11,    66,    67,    11,    98,    11,    11,
      11,    11,    11,   136,    98,     9,    11,    98,    12,    98,
      98,    98,    98,    98,    10,    12,   136,    98,    12,    12,
      12,    12,    12,    12,    11,    10,    12,    98,    11,    12,
      98,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   101,   101,   101,   101,   102,   103,   104,   104,   105,
     105,   105,   106,   106,   107,   108,   108,   109,   109,   110,
     111,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   123,
     123,   123,   123,   124,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   127,   128,   128,
     128,   129,   129,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   134,   134,   134,   135,   136,   136,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   139,   140,   140,   140,   140,   140,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     4,     4,     6,
       8,     4,     2,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     2,     1,     2,     1,     2,     2,     2,     5,     2,
       6,    11,    11,    11,    11,     8,     7,     7,     8,     5,
       1,     4,     8,     7,     7,     6,     5,     2,     1,     6,
       2,     3,     2,     3,     2,     1,     1,     1,     5,     4,
       1,     0,     3,     1,     2,     3,     6,     7,     8,     7,
      10,     9,     9,     9,     8,     8,     2,     1,     2,     6,
       5,     8,     7,     3,     4,     3,     4,     5,     1,     1,
       1,     1,     1,     2,     4,     8,     8,     8,     3,     5,
       5,     4,     3,     3,     5,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     4,     4,
       1,     3,     1,     3,     4,     4,     5,     2,     2,     2,
       3,     5,     6,     4,     2,     4,     5,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 209 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito); raiz = (yyval.nodito);}
#line 2300 "parser.cpp" /* yacc.c:1651  */
    break;

  case 3:
#line 211 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2306 "parser.cpp" /* yacc.c:1651  */
    break;

  case 4:
#line 212 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nuevo = new nodo("sentenciasg","sentenciasg",yylineno, columna); nuevo->add(*(yyvsp[0].nodito)); (yyval.nodito) = nuevo;}
#line 2312 "parser.cpp" /* yacc.c:1651  */
    break;

  case 5:
#line 216 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2318 "parser.cpp" /* yacc.c:1651  */
    break;

  case 6:
#line 217 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[0].nodito);}
#line 2324 "parser.cpp" /* yacc.c:1651  */
    break;

  case 7:
#line 221 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("imprimir",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2333 "parser.cpp" /* yacc.c:1651  */
    break;

  case 8:
#line 226 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("imprimir",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2342 "parser.cpp" /* yacc.c:1651  */
    break;

  case 9:
#line 233 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("concatenar",(yyvsp[-5].TEXT), yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2352 "parser.cpp" /* yacc.c:1651  */
    break;

  case 10:
#line 240 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("concatenar",(yyvsp[-7].TEXT), yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2363 "parser.cpp" /* yacc.c:1651  */
    break;

  case 11:
#line 249 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("importar",(yyvsp[-3].TEXT),yylineno,columna);
                nodo *ruta = new nodo("path",(yyvsp[-1].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*ruta);
              }
#line 2373 "parser.cpp" /* yacc.c:1651  */
    break;

  case 12:
#line 260 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito)=(yyvsp[-1].nodito);
         (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 2382 "parser.cpp" /* yacc.c:1651  */
    break;

  case 13:
#line 265 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("instrucciones","instrucciones",yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
          }
#line 2391 "parser.cpp" /* yacc.c:1651  */
    break;

  case 14:
#line 273 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
            nodo *sobre = new nodo("sobrescribir","no",yylineno,columna);
            (yyval.nodito)->hijos.prepend(*sobre);
        }
#line 2401 "parser.cpp" /* yacc.c:1651  */
    break;

  case 15:
#line 279 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
            nodo *sobre = new nodo("sobrescribir","sobrescribir",yylineno,columna);
            (yyval.nodito)->hijos.prepend(*sobre);
       }
#line 2411 "parser.cpp" /* yacc.c:1651  */
    break;

  case 16:
#line 284 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2417 "parser.cpp" /* yacc.c:1651  */
    break;

  case 17:
#line 285 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= (yyvsp[0].nodito);}
#line 2423 "parser.cpp" /* yacc.c:1651  */
    break;

  case 18:
#line 287 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
            nodo * sobre = new nodo("sobrescribir","",yylineno, columna);
            (yyval.nodito)->hijos.prepend(*sobre);
        }
#line 2433 "parser.cpp" /* yacc.c:1651  */
    break;

  case 19:
#line 293 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *sobre = new nodo("sobrescribir","sobrescribir",yylineno,columna);
             (yyval.nodito)->hijos.prepend(*sobre);
        }
#line 2443 "parser.cpp" /* yacc.c:1651  */
    break;

  case 20:
#line 301 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2449 "parser.cpp" /* yacc.c:1651  */
    break;

  case 21:
#line 302 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nuevo = new nodo("sentencias","sentencias",yylineno, columna); nuevo->add(*(yyvsp[0].nodito)); (yyval.nodito) = nuevo;}
#line 2455 "parser.cpp" /* yacc.c:1651  */
    break;

  case 22:
#line 305 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2461 "parser.cpp" /* yacc.c:1651  */
    break;

  case 23:
#line 306 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2467 "parser.cpp" /* yacc.c:1651  */
    break;

  case 24:
#line 307 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2473 "parser.cpp" /* yacc.c:1651  */
    break;

  case 25:
#line 308 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2479 "parser.cpp" /* yacc.c:1651  */
    break;

  case 26:
#line 309 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2485 "parser.cpp" /* yacc.c:1651  */
    break;

  case 27:
#line 310 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2491 "parser.cpp" /* yacc.c:1651  */
    break;

  case 28:
#line 312 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2497 "parser.cpp" /* yacc.c:1651  */
    break;

  case 29:
#line 313 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2503 "parser.cpp" /* yacc.c:1651  */
    break;

  case 30:
#line 314 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2509 "parser.cpp" /* yacc.c:1651  */
    break;

  case 31:
#line 315 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2515 "parser.cpp" /* yacc.c:1651  */
    break;

  case 32:
#line 316 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2521 "parser.cpp" /* yacc.c:1651  */
    break;

  case 33:
#line 317 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2527 "parser.cpp" /* yacc.c:1651  */
    break;

  case 34:
#line 318 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2533 "parser.cpp" /* yacc.c:1651  */
    break;

  case 35:
#line 319 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("detener","detener",yylineno,columna);}
#line 2539 "parser.cpp" /* yacc.c:1651  */
    break;

  case 36:
#line 320 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("continuar","continuar",yylineno,columna);}
#line 2545 "parser.cpp" /* yacc.c:1651  */
    break;

  case 37:
#line 321 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2551 "parser.cpp" /* yacc.c:1651  */
    break;

  case 38:
#line 322 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("mostraredd",(yyvsp[-2].TEXT),yylineno,columna);}
#line 2557 "parser.cpp" /* yacc.c:1651  */
    break;

  case 39:
#line 323 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito)=(yyvsp[-1].nodito);}
#line 2563 "parser.cpp" /* yacc.c:1651  */
    break;

  case 40:
#line 328 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= new nodo("leer","leer",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2573 "parser.cpp" /* yacc.c:1651  */
    break;

  case 41:
#line 337 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2585 "parser.cpp" /* yacc.c:1651  */
    break;

  case 42:
#line 345 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2597 "parser.cpp" /* yacc.c:1651  */
    break;

  case 43:
#line 353 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // decremento / aumento
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2609 "parser.cpp" /* yacc.c:1651  */
    break;

  case 44:
#line 361 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2621 "parser.cpp" /* yacc.c:1651  */
    break;

  case 45:
#line 373 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("hacer","hacer",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));// sentencias
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));// condicion;
        }
#line 2631 "parser.cpp" /* yacc.c:1651  */
    break;

  case 46:
#line 383 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito) = new nodo("mientras","mientras",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2641 "parser.cpp" /* yacc.c:1651  */
    break;

  case 47:
#line 392 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("si","si",yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));// condicion
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
         }
#line 2651 "parser.cpp" /* yacc.c:1651  */
    break;

  case 48:
#line 398 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             (yyval.nodito)->tipo = "si";
             (yyval.nodito)->valor = "si";
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito)); // Sentencias
             (yyval.nodito)->hijos.prepend(*(yyvsp[-5].nodito));// condicion
         }
#line 2663 "parser.cpp" /* yacc.c:1651  */
    break;

  case 49:
#line 410 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
          }
#line 2672 "parser.cpp" /* yacc.c:1651  */
    break;

  case 50:
#line 415 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 2680 "parser.cpp" /* yacc.c:1651  */
    break;

  case 51:
#line 419 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= (yyvsp[-1].nodito);
         }
#line 2688 "parser.cpp" /* yacc.c:1651  */
    break;

  case 52:
#line 425 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)=(yyvsp[-7].nodito);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2698 "parser.cpp" /* yacc.c:1651  */
    break;

  case 53:
#line 431 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("sinosi","sinosi",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2708 "parser.cpp" /* yacc.c:1651  */
    break;

  case 54:
#line 440 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("selecciona",(yyvsp[-6].TEXT),yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2718 "parser.cpp" /* yacc.c:1651  */
    break;

  case 55:
#line 447 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-5].nodito);
        nodo *def = new nodo("defecto","defecto",yylineno,columna);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2729 "parser.cpp" /* yacc.c:1651  */
    break;

  case 56:
#line 454 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)= new nodo("casos","casos",yylineno,columna);
        nodo *def = new nodo("caso","defecto",yylineno,columna);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2740 "parser.cpp" /* yacc.c:1651  */
    break;

  case 57:
#line 464 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2749 "parser.cpp" /* yacc.c:1651  */
    break;

  case 58:
#line 469 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("casos","casos",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2758 "parser.cpp" /* yacc.c:1651  */
    break;

  case 59:
#line 475 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("caso","caso",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2768 "parser.cpp" /* yacc.c:1651  */
    break;

  case 60:
#line 483 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=new nodo("retorno","retorno",yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 2777 "parser.cpp" /* yacc.c:1651  */
    break;

  case 61:
#line 490 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
                (yyval.nodito)->tipo = "declatrib";
                (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2788 "parser.cpp" /* yacc.c:1651  */
    break;

  case 62:
#line 497 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                nodo *nod = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.prepend(*nod);
                (yyval.nodito)->tipo = "declatrib";
                (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2800 "parser.cpp" /* yacc.c:1651  */
    break;

  case 63:
#line 505 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
             (yyval.nodito)->tipo = "declatrib";
             (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2811 "parser.cpp" /* yacc.c:1651  */
    break;

  case 64:
#line 512 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito) = (yyvsp[-1].nodito);
         nodo *nod = new nodo("publico","publico",yylineno, columna);
         (yyval.nodito)->hijos.prepend(*nod);
         (yyval.nodito)->tipo = "declatrib";
         (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
        }
#line 2823 "parser.cpp" /* yacc.c:1651  */
    break;

  case 65:
#line 523 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("publico",(yyvsp[0].TEXT),yylineno, columna);}
#line 2829 "parser.cpp" /* yacc.c:1651  */
    break;

  case 66:
#line 524 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("privado",(yyvsp[0].TEXT),yylineno, columna);}
#line 2835 "parser.cpp" /* yacc.c:1651  */
    break;

  case 67:
#line 525 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("protegido",(yyvsp[0].TEXT),yylineno, columna);}
#line 2841 "parser.cpp" /* yacc.c:1651  */
    break;

  case 68:
#line 528 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *nodoA = new nodo("acceso","acceso",(yylsp[-4]).first_line,(yylsp[-4]).first_column);
                 nodo *cons = new nodo("llamada",(yyvsp[-3].TEXT),yylineno,columna);
                 nodo *nombre = new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                 cons->hijos.append(*nombre);
                 cons->hijos.append(*(yyvsp[-1].nodito)); // LISTA DE PARAMETROS
                 nodoA->hijos.append(*cons);
                 (yyval.nodito) = nodoA;
            }
#line 2855 "parser.cpp" /* yacc.c:1651  */
    break;

  case 69:
#line 538 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *nodoA = new nodo("acceso","acceso",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                 nodo *cons = new nodo("llamada",(yyvsp[-2].TEXT),yylineno,columna);
                 nodo *nombre = new nodo("id",(yyvsp[-2].TEXT),(yylsp[-2]).first_line,(yylsp[-2]).first_column);
                 cons->hijos.append(*nombre);
                 nodo *lpar = new nodo("lpar","lpar",yylineno,columna);
                 cons->hijos.append(*lpar); // LISTA DE PARAMETROS
                 nodoA->hijos.append(*cons);
                 (yyval.nodito) = nodoA;
            }
#line 2870 "parser.cpp" /* yacc.c:1651  */
    break;

  case 70:
#line 550 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2876 "parser.cpp" /* yacc.c:1651  */
    break;

  case 71:
#line 552 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",0,0);
            }
#line 2884 "parser.cpp" /* yacc.c:1651  */
    break;

  case 72:
#line 559 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=(yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2893 "parser.cpp" /* yacc.c:1651  */
    break;

  case 73:
#line 564 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",yylineno, columna);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2902 "parser.cpp" /* yacc.c:1651  */
    break;

  case 74:
#line 571 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-1].nodito)->tipo = (yyvsp[-1].nodito)->valor;
                (yyvsp[-1].nodito)->valor = (yyvsp[0].TEXT);
                (yyval.nodito) = (yyvsp[-1].nodito);
            }
#line 2912 "parser.cpp" /* yacc.c:1651  */
    break;

  case 75:
#line 577 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-2].nodito)->tipo = (yyvsp[-2].nodito)->valor;
                (yyvsp[-2].nodito)->valor = (yyvsp[-1].TEXT);
                (yyval.nodito) = (yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2923 "parser.cpp" /* yacc.c:1651  */
    break;

  case 76:
#line 586 "sintactico.yy" /* yacc.c:1651  */
    {

                (yyval.nodito) = new nodo("funcion",(yyvsp[-5].TEXT), yylineno, columna);
                nodo *sobre = new nodo("sobrescribir","",yylineno,columna);
                (yyval.nodito)->hijos.append(*sobre);// sobrescritura
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                nodo *tipo = new nodo("tipo","",yylineno,columna);
                (yyval.nodito)->hijos.append(*tipo);// tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);// dimensiones
                nodo *param = new nodo("parametros","parametros",0,0);
                (yyval.nodito)->hijos.append(*param);// parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));  // sentencias
           }
#line 2943 "parser.cpp" /* yacc.c:1651  */
    break;

  case 77:
#line 602 "sintactico.yy" /* yacc.c:1651  */
    {

                     (yyval.nodito) = new nodo("funcion",(yyvsp[-5].TEXT), yylineno, columna);
                     nodo *sobre = new nodo("sobrescribir","no",yylineno,columna);
                     (yyval.nodito)->hijos.append(*sobre);// sobrescribir
                     (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito));// visibilidad
                     nodo *tipo = new nodo("tipo","",yylineno,columna);
                     (yyval.nodito)->hijos.append(*tipo);// tipo
                     nodo *dims= new nodo("dims","dims",yylineno, columna);
                     (yyval.nodito)->hijos.append(*dims);// dimensiones
                     nodo *param = new nodo("parametros","parametros",0,0);
                     (yyval.nodito)->hijos.append(*param);// parametros
                     (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // sentencias
                }
#line 2962 "parser.cpp" /* yacc.c:1651  */
    break;

  case 78:
#line 620 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                    (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // visibilidad
                    nodo *tipo = new nodo("tipo",(yyvsp[-6].TEXT),(yylsp[-6]).first_line,(yylsp[-6]).first_column);
                    (yyval.nodito)->hijos.append(*tipo);// tipo
                    nodo *dims= new nodo("dims","dims",(yylsp[-7]).first_line,(yylsp[-7]).first_column);
                    (yyval.nodito)->hijos.append(*dims);// dimensiones
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2977 "parser.cpp" /* yacc.c:1651  */
    break;

  case 79:
#line 631 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                    nodo *vis = new nodo("visibilidad","publico",yylineno,columna);
                    (yyval.nodito)->hijos.append(*vis); // visibilidad
                    nodo *tipo = new nodo("tipo",(yyvsp[-6].TEXT),(yylsp[-6]).first_line,(yylsp[-6]).first_column);
                    (yyval.nodito)->hijos.append(*tipo);// tipo
                    nodo *dims= new nodo("dims","dims",(yylsp[-6]).first_line,(yylsp[-6]).first_column);
                    (yyval.nodito)->hijos.append(*dims);// dimensiones
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));  // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2993 "parser.cpp" /* yacc.c:1651  */
    break;

  case 80:
#line 645 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-9].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // dimensiones del retorno
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 3006 "parser.cpp" /* yacc.c:1651  */
    break;

  case 81:
#line 654 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 3020 "parser.cpp" /* yacc.c:1651  */
    break;

  case 82:
#line 664 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // visibilidad
                nodo *tipo = new nodo("tipo","vacio",yylineno,columna);
                (yyval.nodito)->hijos.append(*tipo); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 3035 "parser.cpp" /* yacc.c:1651  */
    break;

  case 83:
#line 675 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // dimensiones del retorno
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 3051 "parser.cpp" /* yacc.c:1651  */
    break;

  case 84:
#line 687 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 3066 "parser.cpp" /* yacc.c:1651  */
    break;

  case 85:
#line 698 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*tipo); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros.
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 3082 "parser.cpp" /* yacc.c:1651  */
    break;

  case 86:
#line 712 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 3091 "parser.cpp" /* yacc.c:1651  */
    break;

  case 87:
#line 716 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= new nodo("dims","dims",yylineno, columna);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
          }
#line 3100 "parser.cpp" /* yacc.c:1651  */
    break;

  case 88:
#line 721 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("dim","dim",yylineno,columna);}
#line 3106 "parser.cpp" /* yacc.c:1651  */
    break;

  case 89:
#line 729 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito)); // Visibilidad
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  (yyval.nodito)->hijos.append(*her); // Herencia
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));  // Sentencias
                  // Verificamos que exista el constructor por defecto
                  int existeConstructor = 0 ;
                  for(int i = 0 ; i < (yyval.nodito)->hijos.value(2).hijos.count(); i++)
                  {
                      nodo nodito = (yyval.nodito)->hijos.value(2).hijos.value(i);
                      qDebug() << nodito.valor <<"=="<< (yyval.nodito)->valor ;
                      if(
                         (nodito.tipo == "funcion"||nodito.tipo == "metodo"||nodito.tipo == "constructor") &&
                         nodito.valor == (yyval.nodito)->valor
                        )
                      {
                          if(nodito.hijos.value(4).hijos.count()==0)
                          {
                              existeConstructor = 1;
                              break;
                          }
                      }
                  }
                  qDebug()<<"Verificamos que si existe el constructor.";
                  qDebug()<<"Resultado de la búsqueda " << QString::number(existeConstructor);
                  if(existeConstructor==0)
                  {
                      nodo * nodoConstructor = new nodo("constructor",(yyval.nodito)->valor,0,0);
                      nodo * nodoVisibilidad = new nodo("visibilidad","publico",0,0);
                      nodo * nodoParametros = new nodo("parametros","parametros",0,0);
                      nodo * nodoSentencias  = new nodo("sentencias","sentencias",0,0);
                      nodoConstructor->hijos.append(*nodoVisibilidad);
                      nodoConstructor->hijos.append(*nodoParametros);
                      nodoConstructor->hijos.append(*nodoSentencias);
                      (yyvsp[-1].nodito)->hijos.append(*nodoConstructor);
                      (yyval.nodito)->hijos.replace(2,*(yyvsp[-1].nodito));
                  }
              }
#line 3150 "parser.cpp" /* yacc.c:1651  */
    break;

  case 90:
#line 769 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),yylineno, columna);
                  nodo *nod = new nodo("visibilidad","publico",yylineno, columna);
                  (yyval.nodito)->hijos.append(*nod);
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  (yyval.nodito)->hijos.append(*her);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
                  // Verificamos que exista el constructor por defecto
                  int existeConstructor = 0 ;
                  for(int i = 0 ; i < (yyval.nodito)->hijos.value(2).hijos.count(); i++)
                  {
                      nodo nodito = (yyval.nodito)->hijos.value(2).hijos.value(i);
                      qDebug() << nodito.valor <<"=="<< (yyval.nodito)->valor ;
                      if(
                         (nodito.tipo == "funcion"||nodito.tipo == "metodo"||nodito.tipo == "constructor") &&
                         nodito.valor == (yyval.nodito)->valor
                        )
                      {
                          if(nodito.hijos.value(4).hijos.count()==0)
                          {
                              existeConstructor = 1;
                              break;
                          }
                      }
                  }
                  qDebug()<<"Verificamos que si existe el constructor.";
                  qDebug()<<"Resultado de la búsqueda " << QString::number(existeConstructor);
                  if(existeConstructor==0)
                  {
                      nodo * nodoConstructor = new nodo("constructor",(yyval.nodito)->valor,0,0);
                      nodo * nodoVisibilidad = new nodo("visibilidad","publico",0,0);
                      nodo * nodoParametros = new nodo("parametros","parametros",0,0);
                      nodo * nodoSentencias  = new nodo("sentencias","sentencias",0,0);
                      nodoConstructor->hijos.append(*nodoVisibilidad);
                      nodoConstructor->hijos.append(*nodoParametros);
                      nodoConstructor->hijos.append(*nodoSentencias);
                      (yyvsp[-1].nodito)->hijos.append(*nodoConstructor);
                      (yyval.nodito)->hijos.replace(2,*(yyvsp[-1].nodito));
                  }
              }
#line 3195 "parser.cpp" /* yacc.c:1651  */
    break;

  case 91:
#line 811 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito));
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
                  // Verificamos que exista el constructor por defecto                  
                  int existeConstructor = 0 ;
                  for(int i = 0 ; i < (yyval.nodito)->hijos.value(2).hijos.count(); i++)
                  {
                      nodo nodito = (yyval.nodito)->hijos.value(2).hijos.value(i);
                      qDebug() << nodito.valor <<"=="<< (yyval.nodito)->valor ;
                      if(
                         (nodito.tipo == "funcion"||nodito.tipo == "metodo"||nodito.tipo == "constructor") &&
                         nodito.valor == (yyval.nodito)->valor
                        )
                      {
                          if(nodito.hijos.value(4).hijos.count()==0)
                          {
                              existeConstructor = 1;
                              break;
                          }
                      }
                  }
                  qDebug()<<"Verificamos que si existe el constructor.";
                  qDebug()<<"Resultado de la búsqueda " << QString::number(existeConstructor);
                  if(existeConstructor==0)
                  {
                      nodo * nodoConstructor = new nodo("constructor",(yyval.nodito)->valor,0,0);
                      nodo * nodoVisibilidad = new nodo("visibilidad","publico",0,0);
                      nodo * nodoParametros = new nodo("parametros","parametros",0,0);
                      nodo * nodoSentencias  = new nodo("sentencias","sentencias",0,0);
                      nodoConstructor->hijos.append(*nodoVisibilidad);
                      nodoConstructor->hijos.append(*nodoParametros);
                      nodoConstructor->hijos.append(*nodoSentencias);
                      (yyvsp[-1].nodito)->hijos.append(*nodoConstructor);
                      (yyval.nodito)->hijos.replace(2,*(yyvsp[-1].nodito));
                  }
              }
#line 3239 "parser.cpp" /* yacc.c:1651  */
    break;

  case 92:
#line 851 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),yylineno, columna);
                  nodo *nod = new nodo("publico","publico",yylineno, columna);
                  (yyval.nodito)->hijos.append(*nod);
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
                  // Verificamos que exista el constructor por defecto
                  int existeConstructor = 0 ;
                  for(int i = 0 ; i < (yyval.nodito)->hijos.value(2).hijos.count(); i++)
                  {
                      nodo nodito = (yyval.nodito)->hijos.value(2).hijos.value(i);
                      qDebug() << nodito.valor <<"=="<< (yyval.nodito)->valor ;
                      if(
                         (nodito.tipo == "funcion"||nodito.tipo == "metodo"||nodito.tipo == "constructor") &&
                         nodito.valor == (yyval.nodito)->valor
                        )
                      {
                          if(nodito.hijos.value(4).hijos.count()==0)
                          {
                              existeConstructor = 1;
                              break;
                          }
                      }
                  }
                  qDebug()<<"Verificamos que si existe el constructor.";
                  qDebug()<<"Resultado de la búsqueda " << QString::number(existeConstructor);
                  if(existeConstructor==0)
                  {
                      nodo * nodoConstructor = new nodo("constructor",(yyval.nodito)->valor,0,0);
                      nodo * nodoVisibilidad = new nodo("visibilidad","publico",0,0);
                      nodo * nodoParametros = new nodo("parametros","parametros",0,0);
                      nodo * nodoSentencias  = new nodo("sentencias","sentencias",0,0);
                      nodoConstructor->hijos.append(*nodoVisibilidad);
                      nodoConstructor->hijos.append(*nodoParametros);
                      nodoConstructor->hijos.append(*nodoSentencias);
                      (yyvsp[-1].nodito)->hijos.append(*nodoConstructor);
                      (yyval.nodito)->hijos.replace(2,*(yyvsp[-1].nodito));
                  }
              }
#line 3284 "parser.cpp" /* yacc.c:1651  */
    break;

  case 93:
#line 897 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=(yyvsp[-1].nodito);
                nodo *acceso = new nodo("acceso","acceso",yylineno, columna);
                nodo *nombre = new nodo("id",(yyvsp[-2].TEXT),yylineno, (yylsp[-2]).first_column);
                acceso->hijos.append(*nombre); // nombre
                (yyval.nodito)->add(*acceso);
                (yyval.nodito)->add(*(yyvsp[0].nodito));
              }
#line 3297 "parser.cpp" /* yacc.c:1651  */
    break;

  case 94:
#line 906 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);                    
                    nodo *acceso = new nodo("accesoarray","accesoarray",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                    nodo *nombre = new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                    acceso->hijos.append(*nombre);
                    acceso->hijos.append(*(yyvsp[-2].nodito));
                    (yyval.nodito)->hijos.append(*acceso);  // Destino
                    (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));      // Valor
               }
#line 3311 "parser.cpp" /* yacc.c:1651  */
    break;

  case 95:
#line 916 "sintactico.yy" /* yacc.c:1651  */
    {
                  QString tipo = "";
                  int i=0;
                  for(i=0; i<(yyvsp[-2].nodito)->hijos.count();i++)
                  {
                    tipo = (yyvsp[-2].nodito)->hijos[i].tipo;
                  }
                  if(tipo == "llamada")
                  {
                     std::cout <<"-----------No se puede asignar un valor a una llamada."<<std::endl;
                     errorT *nuevoE = new errorT("Semantico","No se puede asignar un valor a una llamada.",(yyvsp[-2].nodito)->hijos[i-1].linea,(yyvsp[-2].nodito)->hijos[i-1].columna);
                     listaErrores->append(*nuevoE);
                  }
                  else
                  {
                        (yyval.nodito)=(yyvsp[-1].nodito); // Tipo asignación
                        (yyval.nodito)->hijos.append(*(yyvsp[-2].nodito));
                        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
                  }
              }
#line 3336 "parser.cpp" /* yacc.c:1651  */
    break;

  case 96:
#line 937 "sintactico.yy" /* yacc.c:1651  */
    {
                  QString tipo = "";
                  int i=0;
                  for(i=0; i<(yyvsp[-2].nodito)->hijos.count();i++)
                  {
                    tipo = (yyvsp[-2].nodito)->hijos[i].tipo;
                  }
                  if(tipo == "llamada")
                  {
                     std::cout <<"No se puede asignar un valor a una llamada."<<std::endl;
                    errorT *nuevoE = new errorT("Semantico","No se puede asignar un valor a una llamada.",(yyvsp[-2].nodito)->hijos[i-1].linea,(yyvsp[-2].nodito)->hijos[i-1].columna);
                    listaErrores->append(*nuevoE);
                  }
                  else
                  {
                      (yyval.nodito)=(yyvsp[-1].nodito); // Tipo asignacion
                      nodo *acceso = new nodo("acceso","acceso",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                      nodo *nombre = new nodo("id","este",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                      acceso->hijos.append(*nombre);
                      (yyvsp[-2].nodito)->hijos.prepend(*acceso);
                      (yyval.nodito)->hijos.append(*(yyvsp[-2].nodito)); // destino
                      (yyval.nodito)->hijos.append(*(yyvsp[0].nodito)); // Valor
                  }
              }
#line 3365 "parser.cpp" /* yacc.c:1651  */
    break;

  case 97:
#line 962 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    nodo *acceso = new nodo("accesoarray","accesoarray",(yylsp[-4]).first_line,(yylsp[-4]).first_column);
                    nodo *nombre = new nodo("id",(yyvsp[-4].TEXT),(yylsp[-4]).first_line,(yylsp[-4]).first_column);
                    acceso->hijos.append(*nombre); // id
                    acceso->hijos.append(*(yyvsp[-2].nodito));
                    (yyval.nodito)->hijos.append(*acceso);
                    (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
                }
#line 3379 "parser.cpp" /* yacc.c:1651  */
    break;

  case 98:
#line 973 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3385 "parser.cpp" /* yacc.c:1651  */
    break;

  case 99:
#line 974 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3391 "parser.cpp" /* yacc.c:1651  */
    break;

  case 100:
#line 975 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3397 "parser.cpp" /* yacc.c:1651  */
    break;

  case 101:
#line 976 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3403 "parser.cpp" /* yacc.c:1651  */
    break;

  case 102:
#line 977 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3409 "parser.cpp" /* yacc.c:1651  */
    break;

  case 103:
#line 983 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("d",(yyvsp[0].TEXT),yylineno, columna);
            nodo *nodoid =  new nodo("id",(yyvsp[0].TEXT),yylineno,columna);
            nuevo->add(*(yyvsp[-1].nodito)); // tipo
            nuevo->add(*nodoid);
            (yyval.nodito) = nuevo;
         }
#line 3421 "parser.cpp" /* yacc.c:1651  */
    break;

  case 104:
#line 991 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("da",(yyvsp[-2].TEXT),yylineno, columna);
             nodo *nodoid =  new nodo("id",(yyvsp[-2].TEXT),yylineno,columna);
             nuevo->add(*(yyvsp[-3].nodito)); // tipo
             nuevo->add(*nodoid);
             nuevo->add(*(yyvsp[0].nodito)); // valor
             (yyval.nodito) = nuevo;
         }
#line 3434 "parser.cpp" /* yacc.c:1651  */
    break;

  case 105:
#line 1003 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3445 "parser.cpp" /* yacc.c:1651  */
    break;

  case 106:
#line 1010 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3456 "parser.cpp" /* yacc.c:1651  */
    break;

  case 107:
#line 1017 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3467 "parser.cpp" /* yacc.c:1651  */
    break;

  case 108:
#line 1031 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("dar","dar",yylineno, columna);
            nuevo->add(*(yyvsp[-2].nodito));
            nodo *nodoid =  new nodo("id",(yyvsp[-1].TEXT),yylineno,columna);
            nuevo->add(*nodoid);
            nuevo->add(*(yyvsp[0].nodito));
            (yyval.nodito) = nuevo;
         }
#line 3480 "parser.cpp" /* yacc.c:1651  */
    break;

  case 109:
#line 1039 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("dara","dara",yylineno, columna);
             nuevo->add(*(yyvsp[-4].nodito));
             nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
             nuevo->add(*nodoid);
             nuevo->add(*(yyvsp[-2].nodito));
             nuevo->add(*(yyvsp[0].nodito));
             (yyval.nodito) = nuevo;}
#line 3493 "parser.cpp" /* yacc.c:1651  */
    break;

  case 110:
#line 1047 "sintactico.yy" /* yacc.c:1651  */
    {
              nodo *nuevo = new nodo("darar","darar",yylineno, columna);
              nuevo->add(*(yyvsp[-4].nodito));
              nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
              nuevo->add(*nodoid);
              nuevo->add(*(yyvsp[-2].nodito));
              nuevo->add(*(yyvsp[0].nodito));
              (yyval.nodito) = nuevo;}
#line 3506 "parser.cpp" /* yacc.c:1651  */
    break;

  case 111:
#line 1058 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)->add(*(yyvsp[-1].nodito));}
#line 3512 "parser.cpp" /* yacc.c:1651  */
    break;

  case 112:
#line 1060 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)= new nodo("dim","dim",yylineno, columna);
                (yyval.nodito)->add(*(yyvsp[-1].nodito));
            }
#line 3521 "parser.cpp" /* yacc.c:1651  */
    break;

  case 113:
#line 1068 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = (yyvsp[-1].nodito);
         }
#line 3529 "parser.cpp" /* yacc.c:1651  */
    break;

  case 114:
#line 1074 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             for (int i= 0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod = (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3542 "parser.cpp" /* yacc.c:1651  */
    break;

  case 115:
#line 1083 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lvalores","lvalores",yylineno, columna);
             for (int i =0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod =  (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3555 "parser.cpp" /* yacc.c:1651  */
    break;

  case 116:
#line 1093 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-2].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3561 "parser.cpp" /* yacc.c:1651  */
    break;

  case 117:
#line 1094 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("valores","valores",yylineno,columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3567 "parser.cpp" /* yacc.c:1651  */
    break;

  case 118:
#line 1099 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3573 "parser.cpp" /* yacc.c:1651  */
    break;

  case 119:
#line 1100 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3579 "parser.cpp" /* yacc.c:1651  */
    break;

  case 120:
#line 1103 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("booleano",(yyvsp[0].TEXT),yylineno,columna);}
#line 3585 "parser.cpp" /* yacc.c:1651  */
    break;

  case 121:
#line 1104 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("entero",(yyvsp[0].TEXT),yylineno,columna);}
#line 3591 "parser.cpp" /* yacc.c:1651  */
    break;

  case 122:
#line 1105 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("caracter",(yyvsp[0].TEXT),yylineno,columna);}
#line 3597 "parser.cpp" /* yacc.c:1651  */
    break;

  case 123:
#line 1106 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("decimal",(yyvsp[0].TEXT),yylineno,columna);}
#line 3603 "parser.cpp" /* yacc.c:1651  */
    break;

  case 124:
#line 1107 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("objeto",(yyvsp[0].TEXT),yylineno,columna);}
#line 3609 "parser.cpp" /* yacc.c:1651  */
    break;

  case 125:
#line 1114 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("ss","ss",yylineno, columna);
             (yyval.nodito)->add(*(yyvsp[-4].nodito)); // Condicion
             (yyval.nodito)->add(*(yyvsp[-2].nodito)); // Valor verdadero
             (yyval.nodito)->add(*(yyvsp[0].nodito)); // Valor falso;
         }
#line 3620 "parser.cpp" /* yacc.c:1651  */
    break;

  case 126:
#line 1122 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3626 "parser.cpp" /* yacc.c:1651  */
    break;

  case 127:
#line 1123 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3632 "parser.cpp" /* yacc.c:1651  */
    break;

  case 128:
#line 1124 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3638 "parser.cpp" /* yacc.c:1651  */
    break;

  case 129:
#line 1125 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3644 "parser.cpp" /* yacc.c:1651  */
    break;

  case 130:
#line 1128 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3650 "parser.cpp" /* yacc.c:1651  */
    break;

  case 131:
#line 1129 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3656 "parser.cpp" /* yacc.c:1651  */
    break;

  case 132:
#line 1130 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3662 "parser.cpp" /* yacc.c:1651  */
    break;

  case 133:
#line 1131 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3668 "parser.cpp" /* yacc.c:1651  */
    break;

  case 134:
#line 1132 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3674 "parser.cpp" /* yacc.c:1651  */
    break;

  case 135:
#line 1133 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3680 "parser.cpp" /* yacc.c:1651  */
    break;

  case 136:
#line 1134 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3686 "parser.cpp" /* yacc.c:1651  */
    break;

  case 137:
#line 1136 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna);  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3692 "parser.cpp" /* yacc.c:1651  */
    break;

  case 138:
#line 1137 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3698 "parser.cpp" /* yacc.c:1651  */
    break;

  case 139:
#line 1138 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3704 "parser.cpp" /* yacc.c:1651  */
    break;

  case 140:
#line 1139 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3710 "parser.cpp" /* yacc.c:1651  */
    break;

  case 141:
#line 1140 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito));  nod->add(*(yyvsp[0].nodito));  (yyval.nodito)=nod ;  }
#line 3716 "parser.cpp" /* yacc.c:1651  */
    break;

  case 142:
#line 1141 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito));  nod->add(*(yyvsp[0].nodito));  (yyval.nodito)=nod ;  }
#line 3722 "parser.cpp" /* yacc.c:1651  */
    break;

  case 143:
#line 1142 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3728 "parser.cpp" /* yacc.c:1651  */
    break;

  case 144:
#line 1144 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",yylineno, columna);
             nodo *nombre = new nodo("id",(yyvsp[0].TEXT),yylineno,columna);
             (yyval.nodito)->hijos.append(*nombre);
        }
#line 3738 "parser.cpp" /* yacc.c:1651  */
    break;

  case 145:
#line 1150 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("accesoarray","accesoarray",yylineno,columna);
                nodo *nombre = new nodo("id",(yyvsp[-1].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*nombre);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 3749 "parser.cpp" /* yacc.c:1651  */
    break;

  case 146:
#line 1156 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3755 "parser.cpp" /* yacc.c:1651  */
    break;

  case 147:
#line 1158 "sintactico.yy" /* yacc.c:1651  */
    {
              (yyval.nodito)=(yyvsp[0].nodito);
              nodo *nod = new nodo("acceso","acceso",yylineno, columna);
              nod->hijos.append(*(yyvsp[-1].nodito));
              (yyval.nodito)->hijos.prepend(*nod);
         }
#line 3766 "parser.cpp" /* yacc.c:1651  */
    break;

  case 148:
#line 1164 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("entero",(yyvsp[0].TEXT),yylineno, columna);}
#line 3772 "parser.cpp" /* yacc.c:1651  */
    break;

  case 149:
#line 1165 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("caracter",(yyvsp[0].TEXT),yylineno, columna);}
#line 3778 "parser.cpp" /* yacc.c:1651  */
    break;

  case 150:
#line 1166 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("decimal",(yyvsp[0].TEXT),yylineno, columna);}
#line 3784 "parser.cpp" /* yacc.c:1651  */
    break;

  case 151:
#line 1167 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("booleano",(yyvsp[0].TEXT),yylineno, columna);}
#line 3790 "parser.cpp" /* yacc.c:1651  */
    break;

  case 152:
#line 1168 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("cadena",(yyvsp[0].TEXT),yylineno, columna);}
#line 3796 "parser.cpp" /* yacc.c:1651  */
    break;

  case 153:
#line 1169 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("nada",(yyvsp[0].TEXT),yylineno, columna);}
#line 3802 "parser.cpp" /* yacc.c:1651  */
    break;

  case 154:
#line 1170 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[0].nodito);}
#line 3808 "parser.cpp" /* yacc.c:1651  */
    break;

  case 155:
#line 1171 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 3814 "parser.cpp" /* yacc.c:1651  */
    break;

  case 156:
#line 1173 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-1].nodito);
             nodo *nod = new nodo("accesoarray","accesoarray",yylineno, columna);
             nodo *nombre = new nodo("id",(yyvsp[-2].TEXT),(yylsp[-2]).first_line,(yylsp[-2]).first_column);
             nod->hijos.append(*nombre);
             nod->hijos.append(*(yyvsp[-1].nodito));
             (yyval.nodito)->hijos.prepend(*nod);
         }
#line 3827 "parser.cpp" /* yacc.c:1651  */
    break;

  case 157:
#line 1182 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *nod = new nodo("acceso","acceso",yylineno, columna);
             nodo*nombre = new nodo("id","este",yylineno,columna);
             nod->hijos.append(*nombre);
             (yyval.nodito)->hijos.prepend(*nod);
         }
#line 3839 "parser.cpp" /* yacc.c:1651  */
    break;

  case 158:
#line 1190 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertiracadena","convertiracadena",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3848 "parser.cpp" /* yacc.c:1651  */
    break;

  case 159:
#line 1195 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertiraentero","convertiraentero",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3857 "parser.cpp" /* yacc.c:1651  */
    break;

  case 160:
#line 1200 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 3865 "parser.cpp" /* yacc.c:1651  */
    break;

  case 161:
#line 1209 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-2].nodito);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3874 "parser.cpp" /* yacc.c:1651  */
    break;

  case 162:
#line 1214 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito) = new nodo("lpar","lpar",yylineno,columna);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3883 "parser.cpp" /* yacc.c:1651  */
    break;

  case 163:
#line 1224 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nodoA = new nodo("acceso","acceso",(yylsp[-2]).first_line, (yylsp[-2]).first_column);
             nodo *nodollamada = new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",(yyvsp[-2].TEXT),yylineno, columna);
             nodollamada->hijos.append(*nombre); // nodo nombre
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             nodollamada->hijos.append(*par);
             nodoA->hijos.append(*nodollamada);
             (yyval.nodito) = nodoA;
         }
#line 3898 "parser.cpp" /* yacc.c:1651  */
    break;

  case 164:
#line 1235 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nodoA = new nodo("acceso","acceso",(yylsp[-3]).first_line, (yylsp[-3]).first_column);
             nodo *nodollamada = new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",(yyvsp[-3].TEXT),yylineno, columna);
             nodollamada->hijos.append(*nombre); // nodo nombre
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             par->hijos.append(*(yyvsp[-1].nodito));
             nodollamada->hijos.append(*par);
             nodoA->hijos.append(*nodollamada);
             (yyval.nodito) = nodoA;
         }
#line 3914 "parser.cpp" /* yacc.c:1651  */
    break;

  case 165:
#line 1247 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *f= new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
             f->hijos.append(*nombre); //Nodo id
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             f->hijos.append(*par);
             (yyval.nodito)->hijos.prepend(*f);
         }
#line 3928 "parser.cpp" /* yacc.c:1651  */
    break;

  case 166:
#line 1257 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[0].nodito);
             nodo *f= new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",(yyvsp[-4].TEXT),yylineno, columna);
             f->hijos.append(*nombre); // Nodo nombre
             f->hijos.append(*(yyvsp[-2].nodito));     // Parametors
             (yyval.nodito)->hijos.prepend(*f);
         }
#line 3941 "parser.cpp" /* yacc.c:1651  */
    break;

  case 167:
#line 1266 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) =(yyvsp[0].nodito);             
             nodo *f= new nodo("acceso","acceso",yylineno,columna);
             nodo *id = new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
             f->hijos.append(*id);
             (yyval.nodito)->hijos.prepend(*f);
        }
#line 3953 "parser.cpp" /* yacc.c:1651  */
    break;

  case 168:
#line 1277 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("aumento","++",yylineno, columna); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3959 "parser.cpp" /* yacc.c:1651  */
    break;

  case 169:
#line 1278 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("decremento","--",yylineno, columna); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3965 "parser.cpp" /* yacc.c:1651  */
    break;

  case 170:
#line 1283 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-2].nodito);
             nodo *nod= new nodo("acceso","acceso",yylineno, columna);
             nodo * nombre = new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
             nod->hijos.append(*nombre);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3977 "parser.cpp" /* yacc.c:1651  */
    break;

  case 171:
#line 1291 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = (yyvsp[-4].nodito);
            nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
            nodo *nod= new nodo("id",(yyvsp[-2].TEXT),yylineno, columna);
            acceso->hijos.append(*nod); // Add nodo con el id
            nodo *par = new nodo("lpar","lpar",yylineno,columna);
            acceso->hijos.append(*par); // Add lista parametros
            (yyval.nodito)->hijos.append(*acceso);
        }
#line 3991 "parser.cpp" /* yacc.c:1651  */
    break;

  case 172:
#line 1301 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-5].nodito);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-3].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*(yyvsp[-1].nodito)); // Add lista parametros
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 4004 "parser.cpp" /* yacc.c:1651  */
    break;

  case 173:
#line 1310 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = (yyvsp[-3].nodito);
            nodo *acceso = new nodo("accesoarray","accesoarray",yylineno, columna);
            nodo *nod= new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
            acceso->hijos.append(*nod); // Add nodo con el id
            acceso->hijos.append(*(yyvsp[0].nodito)); // Add dimensiones
            (yyval.nodito)->hijos.append(*acceso);

         }
#line 4018 "parser.cpp" /* yacc.c:1651  */
    break;

  case 174:
#line 1320 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *nod= new nodo("acceso","acceso",yylineno, columna);
             nodo * nombre = new nodo("id",(yyvsp[0].TEXT),yylineno, columna);
             nod->hijos.append(*nombre);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 4030 "parser.cpp" /* yacc.c:1651  */
    break;

  case 175:
#line 1328 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-2].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             acceso->hijos.append(*par); // Add lista parametros
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 4044 "parser.cpp" /* yacc.c:1651  */
    break;

  case 176:
#line 1338 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-3].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*(yyvsp[-1].nodito)); // Add lista parametros
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 4057 "parser.cpp" /* yacc.c:1651  */
    break;

  case 177:
#line 1347 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("accesoarray","accesoarray",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*(yyvsp[0].nodito)); // Add dimensiones
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 4070 "parser.cpp" /* yacc.c:1651  */
    break;


#line 4074 "parser.cpp" /* yacc.c:1651  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1355 "sintactico.yy" /* yacc.c:1910  */

