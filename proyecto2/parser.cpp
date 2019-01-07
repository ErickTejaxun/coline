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
    punto = 342
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

#line 231 "parser.cpp" /* yacc.c:355  */
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

#line 262 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   2973

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  483

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

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
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   208,   208,   210,   211,   215,   216,   219,   224,   231,
     238,   247,   258,   263,   271,   272,   278,   279,   280,   281,
     290,   291,   294,   295,   296,   297,   298,   299,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     316,   325,   333,   341,   349,   360,   371,   380,   386,   397,
     403,   407,   413,   419,   428,   435,   442,   452,   457,   463,
     471,   478,   485,   493,   500,   512,   513,   514,   516,   522,
     531,   533,   539,   544,   551,   557,   566,   577,   584,   594,
     603,   611,   620,   630,   639,   651,   656,   661,   668,   676,
     686,   694,   708,   715,   724,   742,   762,   773,   774,   775,
     776,   777,   782,   790,   802,   809,   816,   830,   839,   847,
     858,   859,   867,   873,   882,   893,   894,   899,   900,   901,
     904,   905,   906,   907,   908,   914,   923,   924,   925,   926,
     929,   930,   931,   932,   933,   934,   935,   937,   938,   939,
     940,   941,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,   953,   959,   965,   970,   975,   984,   989,
     999,  1004,  1012,  1018,  1025,  1035,  1036,  1040,  1046,  1052,
    1059,  1066,  1072,  1078,  1085
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
  "mostraredd", "leer_teclado", "puntoComa", "punto", "$accept", "INICIO",
  "SENTENCIASG", "INSTRUCCIONG", "IMPRIMIR", "CONCATENAR", "IMPORTAR",
  "ICLASES", "ICLASE", "SENTENCIAS", "INSTRUCCION", "LEER", "PARA",
  "HACER", "MIENTRAS", "SI", "ELSE", "SINOSI", "SELECCIONAR", "CASOS",
  "LCASOS", "CASO", "RETORNO", "ATRIBUTO", "VISIBILIDAD", "INSTANCIA",
  "LPARAMETROS", "PARAMETROS", "PARAMETRO", "PRINCIPAL", "CONSTRUCTOR",
  "FUNCION", "DIMS", "DIM", "CLASE", "ASIGNACION", "TIPOASIG",
  "DECLARACION", "DECESTRUCTURAS", "DECLARACIONARRAY", "DIMENSIONES",
  "VALORESA", "LVALORES", "VALORES", "VALAS", "TIPO", "SENTSELEC", "EXPL",
  "EXPR", "EXPA", "LPAR", "LLAMADA", "UNARIOS", "ACCESO", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -276

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-276)))

#define YYTABLE_NINF -125

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     457,    22,  -276,  -276,  -276,    -4,    59,   457,  -276,   -25,
      35,  -276,    33,    86,  -276,  -276,  -276,    95,   849,   103,
     104,    52,   126,  -276,  -276,  -276,  -276,   141,   572,   151,
     420,  -276,  -276,    28,  -276,  -276,  -276,    88,    93,   210,
     171,  -276,   849,   183,   230,   184,    28,  -276,  -276,   238,
     193,  -276,  -276,   201,   211,   148,   191,   254,  -276,  -276,
      29,   280,   276,  -276,   849,   646,   297,  -276,   314,   320,
    -276,   322,   230,   324,   329,   333,   230,   332,  -276,  -276,
      92,   326,   230,   446,   439,   118,  -276,   357,  -276,   932,
    -276,   849,   336,   230,   339,   347,   359,  2700,   361,   230,
     230,   395,   397,  -276,  -276,  -276,  -276,  -276,     4,   446,
    2707,   446,   406,   408,   335,  -276,    60,  -276,  1125,  -276,
    -276,   427,  -276,  -276,  -276,   396,   446,   537,   230,  -276,
    1015,  2700,  -276,   425,   447,   266,   459,   462,   335,   446,
     391,   403,   482,   484,   487,   501,   507,   511,   512,   524,
     525,   526,   450,   451,   788,  -276,   452,  -276,   465,  -276,
    -276,  -276,   466,   467,   472,   473,   474,   546,   545,   131,
     489,   562,   566,   569,   230,   570,   704,   576,     5,   500,
     108,   575,  -276,   446,   446,   500,  -276,   446,   446,  -276,
    -276,  2707,  2707,  2707,  2707,  2707,  2707,  2707,  2707,  2707,
    2707,  2707,   580,   446,   219,   585,  -276,   343,   581,  -276,
     874,  2700,  -276,  -276,  -276,  -276,  -276,   439,    77,  2783,
     446,     1,   343,  -276,  -276,   446,   446,   446,  2700,   186,
     561,   567,   568,   590,   446,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,   119,  -276,   439,  -276,
    2700,   594,   595,   598,  2700,   335,   343,    23,   116,   500,
     601,  -276,   155,   174,   582,  -276,   575,   575,   232,   232,
     371,   545,   545,   545,   545,   545,   545,  2791,   166,  -276,
     446,   338,   604,  -276,   957,  -276,   439,     1,   608,   196,
     287,   439,   256,   258,   263,  1040,   125,   335,   533,   534,
     614,   445,   574,   577,   586,   613,   386,  -276,  1123,  2700,
    2700,   617,  1206,   500,   335,   446,  2851,   425,   235,  -276,
    -276,  -276,   105,   446,   421,   343,  -276,   618,  2700,  -276,
    -276,   439,  -276,  -276,   446,  -276,   619,   620,   625,   571,
      77,     1,   446,   446,   605,   563,   573,   579,   564,   446,
    -276,  1289,  1372,  2700,  -276,   500,   343,  -276,   245,  2859,
     425,  -276,   343,  -276,   446,   446,  1455,  -276,   153,  2700,
     355,  2700,   640,     1,    14,    21,   643,   647,   648,  -276,
     272,  -276,  -276,  1538,  -276,  -276,   295,   343,   470,  -276,
    -276,   446,  1621,   446,   651,   650,   415,  -276,  1704,   446,
    2911,  2911,   230,   230,   230,  -276,  -276,  -276,  -276,   308,
     432,   281,   644,  -276,   652,  -276,  -276,   348,   125,   653,
     445,   658,   659,   660,   661,   667,   668,  -276,   675,   680,
    -276,   438,   681,  2700,   682,  -276,   685,   686,   691,   692,
    -276,  -276,  -276,   446,  2700,   695,   705,  2700,  1787,  2700,
    2700,  2700,  2700,  2700,   384,  1870,   446,  2700,  1953,  -276,
    2036,  2119,  2202,  2285,  2368,   706,  -276,   468,  2451,  -276,
    -276,  -276,  -276,  -276,  -276,  2700,   707,  -276,  2534,  2700,
    -276,  2617,  -276
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
       0,    89,    12,   124,     0,     0,     0,     0,    62,    64,
     102,     0,     0,    86,     0,     0,     0,   124,     0,    70,
      73,     0,    71,     0,     0,     0,    71,     0,    61,    63,
     102,     0,    71,     0,     0,   107,    87,     0,    85,     0,
      88,     0,     0,     0,    74,     0,     0,     0,     0,    71,
      71,     0,     0,   145,   147,   146,   148,   149,   143,     0,
       0,     0,     0,     0,     0,   150,     0,   129,   136,   157,
     151,     0,   119,   103,   118,   117,     0,     0,    71,    91,
       0,     0,    72,    75,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    34,     0,    29,
      30,    32,     0,     0,     0,     0,     0,     0,     0,   157,
     151,     0,     0,     0,    71,     0,     0,     0,   144,   164,
       0,   142,   128,     0,     0,   154,   111,     0,     0,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   108,     0,    90,
       0,     0,    97,    98,    99,   100,   101,     0,   144,     0,
       0,   154,    60,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    25,    76,    20,    39,
      33,    27,    24,    22,    37,    23,   102,    28,     0,    31,
       0,     0,     0,     0,     0,   160,   159,     0,   171,   153,
       0,   152,     0,     0,   127,   126,   137,   138,   139,   140,
     141,   133,   132,   135,   134,   130,   131,     0,     0,   110,
       0,     0,     0,    78,     0,    92,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,     0,     0,
       0,     0,     0,   162,   161,     0,     0,   174,   167,   155,
     156,    69,     0,     0,     0,   116,   112,     0,     0,    84,
      93,     0,     8,     7,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,     0,     0,     0,
      77,     0,     0,     0,    83,   163,   158,   172,     0,     0,
     170,    68,   125,   114,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,    81,    80,     0,   173,   168,     0,   115,     0,    82,
       9,     0,     0,     0,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,    40,    79,   169,   113,     0,
      47,     0,     0,    54,     0,    57,    46,     0,   143,     0,
     157,   151,     0,   151,     0,     0,     0,    10,     0,     0,
      48,    50,     0,     0,     0,    45,     0,     0,     0,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,    51,     0,     0,    59,
      55,    41,    43,    42,    44,     0,     0,    49,     0,     0,
      53,     0,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -276,  -276,  -276,   708,  -276,   503,  -276,   -13,    -3,  -124,
     282,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,   323,  -276,  -276,   109,  -276,   -68,  -276,   627,  -276,
     696,   697,   -38,    -5,  -276,  -223,  -168,   150,  -276,   106,
     -83,  -276,  -276,   362,  -214,   -18,  -276,   456,  -276,   330,
    -275,   -88,   -52,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,   152,   153,     9,    30,    31,   154,
     155,   156,   157,   158,   159,   160,   430,   431,   161,   395,
     396,   397,   162,    32,    33,   122,    68,    69,    70,    34,
      35,    36,    62,    63,    11,   163,   217,   164,   165,   166,
      85,   206,   281,   324,   123,   167,   124,   125,   117,   168,
     257,   119,   120,   179
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   248,   322,   285,    95,    13,   298,   210,    98,   169,
      49,   133,    39,   176,   102,    57,   185,    83,   126,    81,
     212,   213,   214,   215,    39,   178,    71,    52,    73,    65,
      12,   172,   173,   314,   307,    81,    53,   216,    82,   315,
     221,   358,    83,   169,    18,   170,    39,    39,   187,   188,
     286,    89,   218,   291,    71,   187,   188,    88,    71,    14,
     208,    16,    52,    42,    71,    84,   169,    23,    24,    25,
      26,    39,   330,    39,   186,    71,    88,   335,   130,   170,
     259,    71,    71,    54,   386,    17,    52,   284,   260,    19,
     126,   177,   177,    20,   187,   188,   212,   213,   214,   215,
     400,   100,   170,    21,   295,    83,   253,   401,    43,    10,
      71,    40,    39,   216,    41,   361,    10,   367,   261,   331,
     287,   315,   169,   169,    38,   316,   308,    52,    84,    83,
     312,   126,    83,   248,   176,    44,    38,    46,    83,    56,
     169,   301,   187,   188,   212,   213,   214,   215,    38,    45,
     212,   213,   214,   215,   127,    84,    71,   313,   170,   170,
      50,   216,   169,   390,   177,   319,   169,   216,    37,   391,
      38,    38,   286,   291,    58,   317,   170,   419,   422,    59,
      37,   323,    64,    55,   320,   351,   352,   187,   188,   187,
     188,    66,    37,    72,   296,    38,   169,    38,   170,   341,
     187,   188,   170,    75,   366,   331,   333,   169,   187,   188,
      76,   300,   177,   340,    37,    37,   355,   247,    60,    77,
     169,   169,   169,    61,   169,    23,    24,    25,    26,   383,
     187,   188,   170,   279,    78,   360,    38,   297,    67,    37,
     169,    37,   373,   170,   359,   392,    74,   398,    83,   189,
     190,    61,   248,   187,   188,   384,   170,   170,   170,   195,
     170,   315,    80,   169,   169,   169,   336,    61,   337,    23,
      24,    25,    26,   338,  -124,   176,   170,    79,   169,    83,
      37,   169,   405,   169,    87,   212,   213,   214,   215,    61,
     187,   188,   187,   188,    86,   169,   432,   187,   188,   170,
     170,   170,   216,   334,   169,   407,   187,   188,    91,   448,
     169,   315,   420,   420,   170,   187,   188,   170,   427,   170,
     455,   187,   188,   458,    92,   460,   461,   462,   463,   464,
      94,   170,    96,   468,   101,   218,    93,    61,    82,    61,
     170,    99,   187,   188,    97,   169,   170,   131,   421,   423,
     326,   478,    83,   177,   327,   481,   169,   134,   435,   169,
     169,   169,   169,   169,   169,   169,   128,   169,   100,   169,
     169,   171,   169,   169,   169,   169,   169,   187,   188,   299,
     169,   170,   187,   188,   424,   425,   426,   169,   189,   190,
     169,   169,   170,   169,   465,   170,   170,   170,   170,   170,
     170,   170,   349,   170,   174,   170,   170,   175,   170,   170,
     170,   170,   170,   118,   118,   183,   170,   184,   187,   188,
     187,   188,   177,   170,   393,   394,   170,   170,    22,   170,
     187,   188,    51,   363,   203,   202,   238,   364,   126,   118,
     181,   118,   103,   104,   105,   106,   107,   108,   109,   103,
     104,   105,   106,   107,   108,   109,   118,   118,   211,    23,
      24,    25,    26,   110,   212,   213,   214,   215,   219,   118,
     110,   220,     2,     3,     4,    27,   111,   223,   476,    28,
      29,   216,   408,   111,   393,   414,   364,   112,   113,   224,
     114,   225,   238,   226,   112,   113,   227,   114,   428,   429,
     121,   115,   187,   188,   445,   446,   118,     1,   115,     2,
       3,     4,   228,   118,   118,     5,   229,   118,   118,   230,
     231,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   232,   118,   233,   234,   235,   236,   239,   116,
     103,   104,   105,   106,   107,   108,   109,   118,   205,   118,
     118,   240,   241,   242,   246,   118,   118,   118,   243,   244,
     245,   110,   189,   190,   118,   180,   238,   182,   191,   192,
     193,   194,   195,   250,   111,   249,   251,   238,   118,   252,
      22,   254,   204,   207,   258,   112,   113,   260,   114,   277,
     238,   282,   189,   190,   238,   222,   280,   302,   305,   115,
     193,   194,   195,   303,   304,   309,   310,   118,   311,   318,
     118,    23,    24,    25,    26,   328,   118,   188,   332,   342,
     343,   118,   344,   348,     2,     3,     4,    27,   353,   365,
     369,   370,   256,   238,   238,   345,   371,   376,   346,   262,
     263,    84,   372,   264,   265,   118,   118,   347,   238,   399,
     379,   377,   402,   118,    22,   433,   403,   404,    90,   278,
     378,   118,   413,   436,   118,   238,   412,   434,   437,   438,
     439,   440,   118,   118,   238,   289,   290,   441,   442,   118,
     238,   292,   293,   294,   443,    23,    24,    25,    26,   118,
     306,   444,   447,   449,   118,   118,   450,   451,     2,     3,
       4,    27,   452,   453,   456,    28,    29,   103,   104,   105,
     106,   107,   108,   109,   255,    15,   457,   475,   479,   415,
     132,   118,   288,   118,    47,    48,     0,   388,   110,   118,
     238,     0,     0,   256,     0,     0,   325,   238,     0,     0,
     238,   111,   238,   238,   238,   238,   238,     0,     0,     0,
     238,     0,   112,   113,     0,   114,     0,     0,     0,     0,
     238,     0,     0,   238,     0,     0,   115,     0,     0,     0,
       0,   356,   256,   118,     0,     0,     0,     0,     0,   362,
       0,     0,     0,     0,     0,     0,   118,     0,     0,     0,
     368,   103,   104,   105,   106,   107,   135,   109,   374,   375,
     237,     0,     0,     0,     0,   380,     0,     0,     0,     0,
       0,     0,   110,     0,     0,   256,     0,     0,     0,     0,
     387,   325,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   136,   137,     0,     0,     0,   112,   113,     0,   138,
       0,     0,     0,     0,     0,   139,     0,   409,     0,   411,
     115,   140,   141,   142,     0,   417,   143,    22,     0,   144,
     145,   146,   147,     0,     0,     0,   148,     0,     0,   149,
       0,     0,   150,   151,     0,     0,     0,   103,   104,   105,
     106,   107,   135,   109,     0,     0,   283,     0,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,   110,   454,
       0,     2,     3,     4,    27,     0,     0,     0,    28,    29,
       0,     0,   467,    23,    24,    25,    26,   136,   137,     0,
       0,     0,   112,   113,     0,   138,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,   115,   140,   141,   142,
      22,     0,   143,     0,   129,   144,   145,   146,   147,     0,
       0,     0,   148,     0,     0,   149,     0,     0,   150,   151,
     103,   104,   105,   106,   107,   135,   109,     0,     0,   329,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     2,     3,     4,    27,     0,     0,
       0,    28,    29,     0,     0,     0,    23,    24,    25,    26,
     136,   137,     0,     0,     0,   112,   113,     0,   138,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,   115,
     140,   141,   142,    22,     0,   143,     0,   209,   144,   145,
     146,   147,     0,     0,     0,   148,     0,     0,   149,     0,
       0,   150,   151,   103,   104,   105,   106,   107,   135,   109,
       0,     0,   339,     0,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     2,     3,     4,
      27,     0,     0,     0,    28,    29,     0,     0,     0,    23,
      24,    25,    26,   136,   137,     0,     0,     0,   112,   113,
       0,   138,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,   115,   140,   141,   142,     0,     0,   143,     0,
       0,   144,   145,   146,   147,     0,     0,     0,   148,     0,
       0,   149,     0,     0,   150,   151,   103,   104,   105,   106,
     107,   135,   109,     0,     0,   350,     0,     0,     0,     0,
       0,     0,   189,   190,     0,     0,     0,   110,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
       0,     0,    23,    24,    25,    26,   136,   137,     0,     0,
       0,   112,   113,     0,   138,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,   115,   140,   141,   142,     0,
       0,   143,     0,     0,   144,   145,   146,   147,     0,     0,
       0,   148,     0,     0,   149,     0,     0,   150,   151,   103,
     104,   105,   106,   107,   135,   109,     0,     0,   354,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   136,
     137,     0,     0,     0,   112,   113,     0,   138,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,   115,   140,
     141,   142,     0,     0,   143,     0,     0,   144,   145,   146,
     147,     0,     0,     0,   148,     0,     0,   149,     0,     0,
     150,   151,   103,   104,   105,   106,   107,   135,   109,     0,
       0,   381,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   136,   137,     0,     0,     0,   112,   113,     0,
     138,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,   115,   140,   141,   142,     0,     0,   143,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   148,     0,     0,
     149,     0,     0,   150,   151,   103,   104,   105,   106,   107,
     135,   109,     0,     0,   382,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   136,   137,     0,     0,     0,
     112,   113,     0,   138,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,   115,   140,   141,   142,     0,     0,
     143,     0,     0,   144,   145,   146,   147,     0,     0,     0,
     148,     0,     0,   149,     0,     0,   150,   151,   103,   104,
     105,   106,   107,   135,   109,     0,     0,   389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   136,   137,
       0,     0,     0,   112,   113,     0,   138,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,   115,   140,   141,
     142,     0,     0,   143,     0,     0,   144,   145,   146,   147,
       0,     0,     0,   148,     0,     0,   149,     0,     0,   150,
     151,   103,   104,   105,   106,   107,   135,   109,     0,     0,
     406,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   136,   137,     0,     0,     0,   112,   113,     0,   138,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
     115,   140,   141,   142,     0,     0,   143,     0,     0,   144,
     145,   146,   147,     0,     0,     0,   148,     0,     0,   149,
       0,     0,   150,   151,   103,   104,   105,   106,   107,   135,
     109,     0,     0,   410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   136,   137,     0,     0,     0,   112,
     113,     0,   138,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   115,   140,   141,   142,     0,     0,   143,
       0,     0,   144,   145,   146,   147,     0,     0,     0,   148,
       0,     0,   149,     0,     0,   150,   151,   103,   104,   105,
     106,   107,   135,   109,     0,     0,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   136,   137,     0,
       0,     0,   112,   113,     0,   138,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,   115,   140,   141,   142,
       0,     0,   143,     0,     0,   144,   145,   146,   147,     0,
       0,     0,   148,     0,     0,   149,     0,     0,   150,   151,
     103,   104,   105,   106,   107,   135,   109,     0,     0,   459,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     136,   137,     0,     0,     0,   112,   113,     0,   138,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,   115,
     140,   141,   142,     0,     0,   143,     0,     0,   144,   145,
     146,   147,     0,     0,     0,   148,     0,     0,   149,     0,
       0,   150,   151,   103,   104,   105,   106,   107,   135,   109,
       0,     0,   466,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   136,   137,     0,     0,     0,   112,   113,
       0,   138,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,   115,   140,   141,   142,     0,     0,   143,     0,
       0,   144,   145,   146,   147,     0,     0,     0,   148,     0,
       0,   149,     0,     0,   150,   151,   103,   104,   105,   106,
     107,   135,   109,     0,     0,   469,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   136,   137,     0,     0,
       0,   112,   113,     0,   138,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,   115,   140,   141,   142,     0,
       0,   143,     0,     0,   144,   145,   146,   147,     0,     0,
       0,   148,     0,     0,   149,     0,     0,   150,   151,   103,
     104,   105,   106,   107,   135,   109,     0,     0,   470,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   136,
     137,     0,     0,     0,   112,   113,     0,   138,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,   115,   140,
     141,   142,     0,     0,   143,     0,     0,   144,   145,   146,
     147,     0,     0,     0,   148,     0,     0,   149,     0,     0,
     150,   151,   103,   104,   105,   106,   107,   135,   109,     0,
       0,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   136,   137,     0,     0,     0,   112,   113,     0,
     138,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,   115,   140,   141,   142,     0,     0,   143,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   148,     0,     0,
     149,     0,     0,   150,   151,   103,   104,   105,   106,   107,
     135,   109,     0,     0,   472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   136,   137,     0,     0,     0,
     112,   113,     0,   138,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,   115,   140,   141,   142,     0,     0,
     143,     0,     0,   144,   145,   146,   147,     0,     0,     0,
     148,     0,     0,   149,     0,     0,   150,   151,   103,   104,
     105,   106,   107,   135,   109,     0,     0,   473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   136,   137,
       0,     0,     0,   112,   113,     0,   138,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,   115,   140,   141,
     142,     0,     0,   143,     0,     0,   144,   145,   146,   147,
       0,     0,     0,   148,     0,     0,   149,     0,     0,   150,
     151,   103,   104,   105,   106,   107,   135,   109,     0,     0,
     474,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   136,   137,     0,     0,     0,   112,   113,     0,   138,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
     115,   140,   141,   142,     0,     0,   143,     0,     0,   144,
     145,   146,   147,     0,     0,     0,   148,     0,     0,   149,
       0,     0,   150,   151,   103,   104,   105,   106,   107,   135,
     109,     0,     0,   477,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   136,   137,     0,     0,     0,   112,
     113,     0,   138,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   115,   140,   141,   142,     0,     0,   143,
       0,     0,   144,   145,   146,   147,     0,     0,     0,   148,
       0,     0,   149,     0,     0,   150,   151,   103,   104,   105,
     106,   107,   135,   109,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   136,   137,     0,
       0,     0,   112,   113,     0,   138,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,   115,   140,   141,   142,
       0,     0,   143,     0,     0,   144,   145,   146,   147,     0,
       0,     0,   148,     0,     0,   149,     0,     0,   150,   151,
     103,   104,   105,   106,   107,   135,   109,     0,     0,   482,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     136,   137,     0,     0,     0,   112,   113,     0,   138,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,   115,
     140,   141,   142,     0,     0,   143,     0,     0,   144,   145,
     146,   147,     0,     0,     0,   148,     0,     0,   149,     0,
       0,   150,   151,   103,   104,   105,   106,   107,   135,   109,
     103,   104,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   136,   137,     0,     0,     0,   112,   113,
       0,   138,     0,     0,     0,   112,   113,   139,   114,     0,
       0,     0,   115,   140,   141,   142,     0,     0,   143,   115,
       0,   144,   145,   146,   147,     0,     0,     0,   148,     0,
       0,   149,     0,     0,   150,   151,   103,   104,   105,   106,
     107,   108,   109,     0,   103,   104,   105,   106,   107,   108,
     109,   321,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,   137,   111,     0,
       0,   112,   113,     0,   114,     0,     0,     0,     0,   112,
     113,     0,   114,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,   115,   103,   104,   105,   106,   107,   108,
     109,   357,   103,   104,   105,   106,   107,   108,   109,   385,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,   112,
     113,     0,   114,     0,     0,     0,     0,   112,   113,     0,
     114,     0,     0,   115,   103,   104,   105,   106,   107,   418,
     109,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     113,     0,   138,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115
};

static const yytype_int16 yycheck[] =
{
      18,   169,   277,   217,    72,     9,   229,   131,    76,    97,
      28,    94,    30,     9,    82,    33,   114,    13,    13,    57,
      19,    20,    21,    22,    42,   108,    44,    30,    46,    42,
       8,    99,   100,    10,   248,    73,     8,    36,     9,    16,
     138,   316,    13,   131,    11,    97,    64,    65,    34,    35,
     218,    64,   135,   221,    72,    34,    35,    62,    76,     0,
     128,    86,    65,    11,    82,    36,   154,    39,    40,    41,
      42,    89,   286,    91,    14,    93,    81,   291,    91,   131,
     178,    99,   100,    55,   359,    50,    89,   211,    87,    56,
      13,    87,    87,     7,    34,    35,    19,    20,    21,    22,
      86,     9,   154,     8,   228,    13,   174,    86,    56,     0,
     128,     8,   130,    36,    10,    10,     7,   331,    10,   287,
     218,    16,   210,   211,    18,     9,   250,   130,    36,    13,
     254,    13,    13,   301,     9,     9,    30,    28,    13,    33,
     228,   229,    34,    35,    19,    20,    21,    22,    42,     8,
      19,    20,    21,    22,    36,    36,   174,   255,   210,   211,
       9,    36,   250,    10,    87,    10,   254,    36,    18,    16,
      64,    65,   340,   341,    86,   258,   228,   400,   401,    86,
      30,    15,    11,    33,    10,   309,   310,    34,    35,    34,
      35,     8,    42,     9,     8,    89,   284,    91,   250,   297,
      34,    35,   254,    10,   328,   373,    10,   295,    34,    35,
       9,   229,    87,   296,    64,    65,   314,    86,     8,     8,
     308,   309,   310,    13,   312,    39,    40,    41,    42,   353,
      34,    35,   284,    14,    86,   318,   130,    51,     8,    89,
     328,    91,   340,   295,     9,   369,     8,   371,    13,    17,
      18,    13,   420,    34,    35,    10,   308,   309,   310,    27,
     312,    16,     8,   351,   352,   353,    10,    13,    10,    39,
      40,    41,    42,    10,     8,     9,   328,    86,   366,    13,
     130,   369,    10,   371,     8,    19,    20,    21,    22,    13,
      34,    35,    34,    35,    14,   383,    15,    34,    35,   351,
     352,   353,    36,    16,   392,    10,    34,    35,    11,   433,
     398,    16,   400,   401,   366,    34,    35,   369,    10,   371,
     444,    34,    35,   447,    10,   449,   450,   451,   452,   453,
       8,   383,     8,   457,     8,   418,    16,    13,     9,    13,
     392,     9,    34,    35,    11,   433,   398,    11,   400,   401,
      12,   475,    13,    87,    16,   479,   444,    10,    10,   447,
     448,   449,   450,   451,   452,   453,     9,   455,     9,   457,
     458,    10,   460,   461,   462,   463,   464,    34,    35,   229,
     468,   433,    34,    35,   402,   403,   404,   475,    17,    18,
     478,   479,   444,   481,    10,   447,   448,   449,   450,   451,
     452,   453,    16,   455,     9,   457,   458,    10,   460,   461,
     462,   463,   464,    83,    84,     9,   468,     9,    34,    35,
      34,    35,    87,   475,    69,    70,   478,   479,     8,   481,
      34,    35,    12,    12,    38,     8,   154,    16,    13,   109,
     110,   111,     3,     4,     5,     6,     7,     8,     9,     3,
       4,     5,     6,     7,     8,     9,   126,   127,    11,    39,
      40,    41,    42,    24,    19,    20,    21,    22,     9,   139,
      24,     9,    52,    53,    54,    55,    37,    86,    10,    59,
      60,    36,    12,    37,    69,    70,    16,    48,    49,    86,
      51,     9,   210,     9,    48,    49,     9,    51,    66,    67,
      61,    62,    34,    35,    66,    67,   176,    50,    62,    52,
      53,    54,    11,   183,   184,    58,     9,   187,   188,     8,
       8,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,     8,   203,     9,     9,    86,    86,    86,    83,
       3,     4,     5,     6,     7,     8,     9,   217,    11,   219,
     220,    86,    86,    86,     8,   225,   226,   227,    86,    86,
      86,    24,    17,    18,   234,   109,   284,   111,    23,    24,
      25,    26,    27,    11,    37,    86,    10,   295,   248,    10,
       8,    11,   126,   127,     8,    48,    49,    87,    51,     9,
     308,    10,    17,    18,   312,   139,    11,    36,     8,    62,
      25,    26,    27,    36,    36,    11,    11,   277,    10,     8,
     280,    39,    40,    41,    42,    11,   286,    35,    10,    86,
      86,   291,     8,    10,    52,    53,    54,    55,    11,    11,
      11,    11,   176,   351,   352,    61,    11,    74,    61,   183,
     184,    36,    71,   187,   188,   315,   316,    61,   366,     9,
      86,    78,     9,   323,     8,    11,     9,     9,    12,   203,
      81,   331,    12,    10,   334,   383,    15,    15,    10,    10,
      10,    10,   342,   343,   392,   219,   220,    10,    10,   349,
     398,   225,   226,   227,     9,    39,    40,    41,    42,   359,
     234,    11,    11,    11,   364,   365,    11,    11,    52,    53,
      54,    55,    11,    11,     9,    59,    60,     3,     4,     5,
       6,     7,     8,     9,    10,     7,    11,    11,    11,   396,
      93,   391,   219,   393,    28,    28,    -1,   365,    24,   399,
     448,    -1,    -1,   277,    -1,    -1,   280,   455,    -1,    -1,
     458,    37,   460,   461,   462,   463,   464,    -1,    -1,    -1,
     468,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
     478,    -1,    -1,   481,    -1,    -1,    62,    -1,    -1,    -1,
      -1,   315,   316,   443,    -1,    -1,    -1,    -1,    -1,   323,
      -1,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,
     334,     3,     4,     5,     6,     7,     8,     9,   342,   343,
      12,    -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,   359,    -1,    -1,    -1,    -1,
     364,   365,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,   391,    -1,   393,
      62,    63,    64,    65,    -1,   399,    68,     8,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    85,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    24,   443,
      -1,    52,    53,    54,    55,    -1,    -1,    -1,    59,    60,
      -1,    -1,   456,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
       8,    -1,    68,    -1,    12,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,     8,    -1,    68,    -1,    12,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    52,    53,    54,
      55,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    24,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    85,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    85,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    85,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    68,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    85,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    85,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    84,    85,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      -1,    -1,    81,    -1,    -1,    84,    85,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,    85,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,     9,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,    51,    -1,    -1,    -1,    48,    49,    57,    51,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    68,    62,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,
      -1,    81,    -1,    -1,    84,    85,     3,     4,     5,     6,
       7,     8,     9,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    37,    -1,
      -1,    48,    49,    -1,    51,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,     3,     4,     5,     6,     7,     8,
       9,    10,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    -1,    -1,    62,     3,     4,     5,     6,     7,     8,
       9,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    52,    53,    54,    58,    89,    90,    91,    94,
     112,   122,     8,     9,     0,    91,    86,    50,    11,    56,
       7,     8,     8,    39,    40,    41,    42,    55,    59,    60,
      95,    96,   111,   112,   117,   118,   119,   125,   127,   133,
       8,    10,    11,    56,     9,     8,   112,   118,   119,   133,
       9,    12,    96,     8,    55,   125,   127,   133,    86,    86,
       8,    13,   120,   121,    11,    95,     8,     8,   114,   115,
     116,   133,     9,   133,     8,    10,     9,     8,    86,    86,
       8,   120,     9,    13,    36,   128,    14,     8,   121,    95,
      12,    11,    10,    16,     8,   114,     8,    11,   114,     9,
       9,     8,   114,     3,     4,     5,     6,     7,     8,     9,
      24,    37,    48,    49,    51,    62,   135,   136,   137,   139,
     140,    61,   113,   132,   134,   135,    13,    36,     9,    12,
      95,    11,   116,   128,    10,     8,    43,    44,    51,    57,
      63,    64,    65,    68,    71,    72,    73,    74,    78,    81,
      84,    85,    92,    93,    97,    98,    99,   100,   101,   102,
     103,   106,   110,   123,   125,   126,   127,   133,   137,   139,
     140,    10,   114,   114,     9,    10,     9,    87,   128,   141,
     135,   137,   135,     9,     9,   141,    14,    34,    35,    17,
      18,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     8,    38,   135,    11,   129,   135,   114,    12,
      97,    11,    19,    20,    21,    22,    36,   124,   128,     9,
       9,   141,   135,    86,    86,     9,     9,     9,    11,     9,
       8,     8,     8,     9,     9,    86,    86,    12,    98,    86,
      86,    86,    86,    86,    86,    86,     8,    86,   124,    86,
      11,    10,    10,   114,    11,    10,   135,   138,     8,   141,
      87,    10,   135,   135,   135,   135,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,     9,   135,    14,
      11,   130,    10,    12,    97,   132,   124,   141,    93,   135,
     135,   124,   135,   135,   135,    97,     8,    51,   123,   125,
     133,   139,    36,    36,    36,     8,   135,   132,    97,    11,
      11,    10,    97,   141,    10,    16,     9,   128,     8,    10,
      10,    10,   138,    15,   131,   135,    12,    16,    11,    12,
     132,   124,    10,    10,    16,   132,    10,    10,    10,    12,
     128,   141,    86,    86,     8,    61,    61,    61,    10,    16,
      12,    97,    97,    11,    12,   141,   135,    10,   138,     9,
     128,    10,   135,    12,    16,    11,    97,   132,   135,    11,
      11,    11,    71,   141,   135,   135,    74,    78,    81,    86,
     135,    12,    12,    97,    10,    10,   138,   135,   131,    12,
      10,    16,    97,    69,    70,   107,   108,   109,    97,     9,
      86,    86,     9,     9,     9,    10,    12,    10,    12,   135,
      12,   135,    15,    12,    70,   109,    12,   135,     8,   123,
     139,   140,   123,   140,   133,   133,   133,    10,    66,    67,
     104,   105,    15,    11,    15,    10,    10,    10,    10,    10,
      10,    10,    10,     9,    11,    66,    67,    11,    97,    11,
      11,    11,    11,    11,   135,    97,     9,    11,    97,    12,
      97,    97,    97,    97,    97,    10,    12,   135,    97,    12,
      12,    12,    12,    12,    12,    11,    10,    12,    97,    11,
      12,    97,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    95,    95,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,   100,   100,   100,   100,   101,   102,   103,   103,   104,
     104,   104,   105,   105,   106,   107,   107,   108,   108,   109,
     110,   111,   111,   111,   111,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   118,   118,   119,
     119,   119,   119,   119,   119,   120,   120,   121,   122,   122,
     122,   122,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   127,
     128,   128,   129,   130,   130,   131,   131,   132,   132,   132,
     133,   133,   133,   133,   133,   134,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   138,   138,
     139,   139,   139,   139,   139,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141
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
       1,     0,     3,     1,     2,     3,     6,     8,     7,    10,
       9,     9,     9,     8,     8,     2,     1,     2,     6,     5,
       8,     7,     3,     4,     3,     4,     5,     1,     1,     1,
       1,     1,     2,     4,     8,     8,     8,     3,     5,     5,
       4,     3,     3,     5,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     4,     4,     1,     3,     1,
       3,     4,     4,     5,     2,     2,     2,     3,     5,     6,
       4,     2,     4,     5,     3
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
#line 208 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito); raiz = (yyval.nodito);}
#line 2261 "parser.cpp" /* yacc.c:1651  */
    break;

  case 3:
#line 210 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2267 "parser.cpp" /* yacc.c:1651  */
    break;

  case 4:
#line 211 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nuevo = new nodo("sentenciasg","sentenciasg",yylineno, columna); nuevo->add(*(yyvsp[0].nodito)); (yyval.nodito) = nuevo;}
#line 2273 "parser.cpp" /* yacc.c:1651  */
    break;

  case 5:
#line 215 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2279 "parser.cpp" /* yacc.c:1651  */
    break;

  case 6:
#line 216 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[0].nodito);}
#line 2285 "parser.cpp" /* yacc.c:1651  */
    break;

  case 7:
#line 220 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("imprimir",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2294 "parser.cpp" /* yacc.c:1651  */
    break;

  case 8:
#line 225 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("imprimir",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2303 "parser.cpp" /* yacc.c:1651  */
    break;

  case 9:
#line 232 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("concatenar",(yyvsp[-5].TEXT), yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2313 "parser.cpp" /* yacc.c:1651  */
    break;

  case 10:
#line 239 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("concatenar",(yyvsp[-7].TEXT), yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2324 "parser.cpp" /* yacc.c:1651  */
    break;

  case 11:
#line 248 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("importar",(yyvsp[-3].TEXT),yylineno,columna);
                nodo *ruta = new nodo("path",(yyvsp[-1].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*ruta);
              }
#line 2334 "parser.cpp" /* yacc.c:1651  */
    break;

  case 12:
#line 259 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito)=(yyvsp[-1].nodito);
         (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 2343 "parser.cpp" /* yacc.c:1651  */
    break;

  case 13:
#line 264 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("instrucciones","instrucciones",yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
          }
#line 2352 "parser.cpp" /* yacc.c:1651  */
    break;

  case 14:
#line 271 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2358 "parser.cpp" /* yacc.c:1651  */
    break;

  case 15:
#line 273 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
            nodo *sobre = new nodo("sobrescribir","sobrescribir",yylineno,columna);
            (yyval.nodito)->hijos.prepend(*sobre);
       }
#line 2368 "parser.cpp" /* yacc.c:1651  */
    break;

  case 16:
#line 278 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2374 "parser.cpp" /* yacc.c:1651  */
    break;

  case 17:
#line 279 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= (yyvsp[0].nodito);}
#line 2380 "parser.cpp" /* yacc.c:1651  */
    break;

  case 18:
#line 280 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2386 "parser.cpp" /* yacc.c:1651  */
    break;

  case 19:
#line 282 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *sobre = new nodo("sobrescribir","sobrescribir",yylineno,columna);
             (yyval.nodito)->hijos.prepend(*sobre);
        }
#line 2396 "parser.cpp" /* yacc.c:1651  */
    break;

  case 20:
#line 290 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2402 "parser.cpp" /* yacc.c:1651  */
    break;

  case 21:
#line 291 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nuevo = new nodo("sentencias","sentencias",yylineno, columna); nuevo->add(*(yyvsp[0].nodito)); (yyval.nodito) = nuevo;}
#line 2408 "parser.cpp" /* yacc.c:1651  */
    break;

  case 22:
#line 294 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2414 "parser.cpp" /* yacc.c:1651  */
    break;

  case 23:
#line 295 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2420 "parser.cpp" /* yacc.c:1651  */
    break;

  case 24:
#line 296 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2426 "parser.cpp" /* yacc.c:1651  */
    break;

  case 25:
#line 297 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2432 "parser.cpp" /* yacc.c:1651  */
    break;

  case 26:
#line 298 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2438 "parser.cpp" /* yacc.c:1651  */
    break;

  case 27:
#line 299 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2444 "parser.cpp" /* yacc.c:1651  */
    break;

  case 28:
#line 301 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2450 "parser.cpp" /* yacc.c:1651  */
    break;

  case 29:
#line 302 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2456 "parser.cpp" /* yacc.c:1651  */
    break;

  case 30:
#line 303 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2462 "parser.cpp" /* yacc.c:1651  */
    break;

  case 31:
#line 304 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2468 "parser.cpp" /* yacc.c:1651  */
    break;

  case 32:
#line 305 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2474 "parser.cpp" /* yacc.c:1651  */
    break;

  case 33:
#line 306 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2480 "parser.cpp" /* yacc.c:1651  */
    break;

  case 34:
#line 307 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2486 "parser.cpp" /* yacc.c:1651  */
    break;

  case 35:
#line 308 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("detener","detener",yylineno,columna);}
#line 2492 "parser.cpp" /* yacc.c:1651  */
    break;

  case 36:
#line 309 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("continuar","continuar",yylineno,columna);}
#line 2498 "parser.cpp" /* yacc.c:1651  */
    break;

  case 37:
#line 310 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2504 "parser.cpp" /* yacc.c:1651  */
    break;

  case 38:
#line 311 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("mostraredd",(yyvsp[-2].TEXT),yylineno,columna);}
#line 2510 "parser.cpp" /* yacc.c:1651  */
    break;

  case 39:
#line 312 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito)=(yyvsp[-1].nodito);}
#line 2516 "parser.cpp" /* yacc.c:1651  */
    break;

  case 40:
#line 317 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= new nodo("leer","leer",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2526 "parser.cpp" /* yacc.c:1651  */
    break;

  case 41:
#line 326 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2538 "parser.cpp" /* yacc.c:1651  */
    break;

  case 42:
#line 334 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2550 "parser.cpp" /* yacc.c:1651  */
    break;

  case 43:
#line 342 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // decremento / aumento
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2562 "parser.cpp" /* yacc.c:1651  */
    break;

  case 44:
#line 350 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2574 "parser.cpp" /* yacc.c:1651  */
    break;

  case 45:
#line 362 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("hacer","hacer",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));// sentencias
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));// condicion;
        }
#line 2584 "parser.cpp" /* yacc.c:1651  */
    break;

  case 46:
#line 372 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito) = new nodo("mientras","mientras",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2594 "parser.cpp" /* yacc.c:1651  */
    break;

  case 47:
#line 381 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("si","si",yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));// condicion
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
         }
#line 2604 "parser.cpp" /* yacc.c:1651  */
    break;

  case 48:
#line 387 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             (yyval.nodito)->tipo = "si";
             (yyval.nodito)->valor = "si";
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito)); // Sentencias
             (yyval.nodito)->hijos.prepend(*(yyvsp[-5].nodito));// condicion
         }
#line 2616 "parser.cpp" /* yacc.c:1651  */
    break;

  case 49:
#line 399 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
          }
#line 2625 "parser.cpp" /* yacc.c:1651  */
    break;

  case 50:
#line 404 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 2633 "parser.cpp" /* yacc.c:1651  */
    break;

  case 51:
#line 408 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= (yyvsp[-1].nodito);
         }
#line 2641 "parser.cpp" /* yacc.c:1651  */
    break;

  case 52:
#line 414 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)=(yyvsp[-7].nodito);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2651 "parser.cpp" /* yacc.c:1651  */
    break;

  case 53:
#line 420 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("sinosi","sinosi",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2661 "parser.cpp" /* yacc.c:1651  */
    break;

  case 54:
#line 429 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("selecciona",(yyvsp[-6].TEXT),yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2671 "parser.cpp" /* yacc.c:1651  */
    break;

  case 55:
#line 436 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-5].nodito);
        nodo *def = new nodo("defecto","defecto",yylineno,columna);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2682 "parser.cpp" /* yacc.c:1651  */
    break;

  case 56:
#line 443 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)= new nodo("casos","casos",yylineno,columna);
        nodo *def = new nodo("caso","defecto",yylineno,columna);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2693 "parser.cpp" /* yacc.c:1651  */
    break;

  case 57:
#line 453 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2702 "parser.cpp" /* yacc.c:1651  */
    break;

  case 58:
#line 458 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("casos","casos",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2711 "parser.cpp" /* yacc.c:1651  */
    break;

  case 59:
#line 464 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("caso","caso",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2721 "parser.cpp" /* yacc.c:1651  */
    break;

  case 60:
#line 472 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=new nodo("retorno","retorno",yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 2730 "parser.cpp" /* yacc.c:1651  */
    break;

  case 61:
#line 479 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
                (yyval.nodito)->tipo = "declatrib";
                (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2741 "parser.cpp" /* yacc.c:1651  */
    break;

  case 62:
#line 486 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                nodo *nod = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.prepend(*nod);
                (yyval.nodito)->tipo = "declatrib";
                (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2753 "parser.cpp" /* yacc.c:1651  */
    break;

  case 63:
#line 494 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
             (yyval.nodito)->tipo = "declatrib";
             (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2764 "parser.cpp" /* yacc.c:1651  */
    break;

  case 64:
#line 501 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito) = (yyvsp[-1].nodito);
         nodo *nod = new nodo("publico","publico",yylineno, columna);
         (yyval.nodito)->hijos.prepend(*nod);
         (yyval.nodito)->tipo = "declatrib";
         (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
        }
#line 2776 "parser.cpp" /* yacc.c:1651  */
    break;

  case 65:
#line 512 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("publico",(yyvsp[0].TEXT),yylineno, columna);}
#line 2782 "parser.cpp" /* yacc.c:1651  */
    break;

  case 66:
#line 513 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("privado",(yyvsp[0].TEXT),yylineno, columna);}
#line 2788 "parser.cpp" /* yacc.c:1651  */
    break;

  case 67:
#line 514 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("protegido",(yyvsp[0].TEXT),yylineno, columna);}
#line 2794 "parser.cpp" /* yacc.c:1651  */
    break;

  case 68:
#line 517 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *cons = new nodo("constructor",(yyvsp[-3].TEXT),yylineno,columna);
                 cons->hijos.append(*(yyvsp[-1].nodito)); // LISTA DE PARAMETROS
                 (yyval.nodito) = cons;
            }
#line 2804 "parser.cpp" /* yacc.c:1651  */
    break;

  case 69:
#line 523 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *cons = new nodo("constructor",(yyvsp[-2].TEXT),yylineno,columna);
                 nodo *lpar = new nodo("lpar","lpar",yylineno,columna);
                 cons->hijos.append(*lpar); // LISTA DE PARAMETROS
                 (yyval.nodito) = cons;
            }
#line 2815 "parser.cpp" /* yacc.c:1651  */
    break;

  case 70:
#line 531 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2821 "parser.cpp" /* yacc.c:1651  */
    break;

  case 71:
#line 533 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",0,0);
            }
#line 2829 "parser.cpp" /* yacc.c:1651  */
    break;

  case 72:
#line 540 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=(yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2838 "parser.cpp" /* yacc.c:1651  */
    break;

  case 73:
#line 545 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",yylineno, columna);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2847 "parser.cpp" /* yacc.c:1651  */
    break;

  case 74:
#line 552 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-1].nodito)->tipo = (yyvsp[-1].nodito)->valor;
                (yyvsp[-1].nodito)->valor = (yyvsp[0].TEXT);
                (yyval.nodito) = (yyvsp[-1].nodito);
            }
#line 2857 "parser.cpp" /* yacc.c:1651  */
    break;

  case 75:
#line 558 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-2].nodito)->tipo = (yyvsp[-2].nodito)->valor;
                (yyvsp[-2].nodito)->valor = (yyvsp[-1].TEXT);
                (yyval.nodito) = (yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2868 "parser.cpp" /* yacc.c:1651  */
    break;

  case 76:
#line 567 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-5].TEXT), yylineno, columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis);
                nodo *param = new nodo("parametros","parametros",0,0);
                (yyval.nodito)->hijos.append(*param);
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
           }
#line 2881 "parser.cpp" /* yacc.c:1651  */
    break;

  case 77:
#line 578 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("constructor",(yyvsp[-6].TEXT),yylineno,columna);
                    (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // visibilidad
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2892 "parser.cpp" /* yacc.c:1651  */
    break;

  case 78:
#line 585 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("constructor",(yyvsp[-6].TEXT),yylineno,columna);
                    nodo *vis = new nodo("visibilidad","publico",yylineno,columna);
                    (yyval.nodito)->hijos.append(*vis); // visibilidad
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));  // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2904 "parser.cpp" /* yacc.c:1651  */
    break;

  case 79:
#line 595 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-9].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // dimensiones del retorno
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2917 "parser.cpp" /* yacc.c:1651  */
    break;

  case 80:
#line 604 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2929 "parser.cpp" /* yacc.c:1651  */
    break;

  case 81:
#line 612 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // visibilidad
                nodo *tipo = new nodo("tipo","vacio",yylineno,columna);
                (yyval.nodito)->hijos.append(*tipo); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2942 "parser.cpp" /* yacc.c:1651  */
    break;

  case 82:
#line 621 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // dimensiones del retorno
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2956 "parser.cpp" /* yacc.c:1651  */
    break;

  case 83:
#line 631 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2969 "parser.cpp" /* yacc.c:1651  */
    break;

  case 84:
#line 640 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*tipo); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros.
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2983 "parser.cpp" /* yacc.c:1651  */
    break;

  case 85:
#line 652 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 2992 "parser.cpp" /* yacc.c:1651  */
    break;

  case 86:
#line 656 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= new nodo("dims","dims",yylineno, columna);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
          }
#line 3001 "parser.cpp" /* yacc.c:1651  */
    break;

  case 87:
#line 661 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("dim","dim",yylineno,columna);}
#line 3007 "parser.cpp" /* yacc.c:1651  */
    break;

  case 88:
#line 669 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  (yyval.nodito)->hijos.append(*her);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3019 "parser.cpp" /* yacc.c:1651  */
    break;

  case 89:
#line 677 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),yylineno, columna);
                  nodo *nod = new nodo("visibilidad","publico",yylineno, columna);
                  (yyval.nodito)->hijos.append(*nod);
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  (yyval.nodito)->hijos.append(*her);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3032 "parser.cpp" /* yacc.c:1651  */
    break;

  case 90:
#line 687 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito));
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3044 "parser.cpp" /* yacc.c:1651  */
    break;

  case 91:
#line 695 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),yylineno, columna);
                  nodo *nod = new nodo("publico","publico",yylineno, columna);
                  (yyval.nodito)->hijos.append(*nod);
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3057 "parser.cpp" /* yacc.c:1651  */
    break;

  case 92:
#line 709 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=(yyvsp[-1].nodito);
                nodo *idnodo = new nodo("variable",(yyvsp[-2].TEXT),yylineno, columna);
                (yyval.nodito)->add(*idnodo);
                (yyval.nodito)->add(*(yyvsp[0].nodito));
              }
#line 3068 "parser.cpp" /* yacc.c:1651  */
    break;

  case 93:
#line 716 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    (yyval.nodito)->tipo= "asiga";
                    (yyval.nodito)->add(*(yyvsp[-2].nodito));
                    nodo *idnodo = new nodo("variable",(yyvsp[-3].TEXT),yylineno, columna);
                    (yyval.nodito)->add(*idnodo);
                    (yyval.nodito)->add(*(yyvsp[0].nodito));
                }
#line 3081 "parser.cpp" /* yacc.c:1651  */
    break;

  case 94:
#line 725 "sintactico.yy" /* yacc.c:1651  */
    {
                  QString tipo = "";
                  int i=0;
                  for(i=0; i<(yyvsp[-2].nodito)->hijos.count();i++)
                  {
                    tipo = (yyvsp[-2].nodito)->hijos[i].tipo;
                  }
                  if(tipo == "funcion")
                  {
                     std::cout <<"-----------No se puede asignar un valor a una llamada."<<std::endl;
                     errorT *nuevoE = new errorT("Semantico","No se puede asignar un valor a una llamada.",(yyvsp[-2].nodito)->hijos[i-1].linea,(yyvsp[-2].nodito)->hijos[i-1].columna);
                     listaErrores->append(*nuevoE);
                  }
                  (yyval.nodito)=(yyvsp[-1].nodito);
                  (yyval.nodito)->hijos.append(*(yyvsp[-2].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 3103 "parser.cpp" /* yacc.c:1651  */
    break;

  case 95:
#line 743 "sintactico.yy" /* yacc.c:1651  */
    {
                  QString tipo = "";
                  int i=0;
                  for(i=0; i<(yyvsp[-2].nodito)->hijos.count();i++)
                  {
                    tipo = (yyvsp[-2].nodito)->hijos[i].tipo;
                  }
                  if(tipo == "funcion")
                  {
                     std::cout <<"No se puede asignar un valor a una llamada."<<std::endl;
                    errorT *nuevoE = new errorT("Semantico","No se puede asignar un valor a una llamada.",(yyvsp[-2].nodito)->hijos[i-1].linea,(yyvsp[-2].nodito)->hijos[i-1].columna);
                    listaErrores->append(*nuevoE);
                  }
                  (yyval.nodito)=(yyvsp[-1].nodito);
                  nodo *nod = new nodo("id",(yyvsp[-3].TEXT),yylineno, columna);
                  (yyvsp[-2].nodito)->hijos.prepend(*nod);
                  (yyval.nodito)->hijos.append(*(yyvsp[-2].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 3127 "parser.cpp" /* yacc.c:1651  */
    break;

  case 96:
#line 763 "sintactico.yy" /* yacc.c:1651  */
    {
                           (yyval.nodito)=(yyvsp[-1].nodito);
                           nodo *nod = new nodo("id",(yyvsp[-4].TEXT),yylineno, columna);
                           nod->hijos.append(*(yyvsp[-3].nodito));
                           (yyval.nodito)->hijos.prepend(*nod);
                           (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
                           }
#line 3139 "parser.cpp" /* yacc.c:1651  */
    break;

  case 97:
#line 773 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3145 "parser.cpp" /* yacc.c:1651  */
    break;

  case 98:
#line 774 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3151 "parser.cpp" /* yacc.c:1651  */
    break;

  case 99:
#line 775 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3157 "parser.cpp" /* yacc.c:1651  */
    break;

  case 100:
#line 776 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3163 "parser.cpp" /* yacc.c:1651  */
    break;

  case 101:
#line 777 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3169 "parser.cpp" /* yacc.c:1651  */
    break;

  case 102:
#line 783 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("d",(yyvsp[0].TEXT),yylineno, columna);
            nodo *nodoid =  new nodo("id",(yyvsp[0].TEXT),yylineno,columna);
            nuevo->add(*(yyvsp[-1].nodito)); // tipo
            nuevo->add(*nodoid);
            (yyval.nodito) = nuevo;
         }
#line 3181 "parser.cpp" /* yacc.c:1651  */
    break;

  case 103:
#line 791 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("da",(yyvsp[-2].TEXT),yylineno, columna);
             nodo *nodoid =  new nodo("id",(yyvsp[-2].TEXT),yylineno,columna);
             nuevo->add(*(yyvsp[-3].nodito)); // tipo
             nuevo->add(*nodoid);
             nuevo->add(*(yyvsp[0].nodito)); // valor
             (yyval.nodito) = nuevo;
         }
#line 3194 "parser.cpp" /* yacc.c:1651  */
    break;

  case 104:
#line 803 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3205 "parser.cpp" /* yacc.c:1651  */
    break;

  case 105:
#line 810 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3216 "parser.cpp" /* yacc.c:1651  */
    break;

  case 106:
#line 817 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3227 "parser.cpp" /* yacc.c:1651  */
    break;

  case 107:
#line 831 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("dar","dar",yylineno, columna);
            nuevo->add(*(yyvsp[-2].nodito));
            nodo *nodoid =  new nodo("id",(yyvsp[-1].TEXT),yylineno,columna);
            nuevo->add(*nodoid);
            nuevo->add(*(yyvsp[0].nodito));
            (yyval.nodito) = nuevo;
         }
#line 3240 "parser.cpp" /* yacc.c:1651  */
    break;

  case 108:
#line 839 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("dara","dara",yylineno, columna);
             nuevo->add(*(yyvsp[-4].nodito));
             nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
             nuevo->add(*nodoid);
             nuevo->add(*(yyvsp[-2].nodito));
             nuevo->add(*(yyvsp[0].nodito));
             (yyval.nodito) = nuevo;}
#line 3253 "parser.cpp" /* yacc.c:1651  */
    break;

  case 109:
#line 847 "sintactico.yy" /* yacc.c:1651  */
    {
              nodo *nuevo = new nodo("darar","darar",yylineno, columna);
              nuevo->add(*(yyvsp[-4].nodito));
              nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
              nuevo->add(*nodoid);
              nuevo->add(*(yyvsp[-2].nodito));
              nuevo->add(*(yyvsp[0].nodito));
              (yyval.nodito) = nuevo;}
#line 3266 "parser.cpp" /* yacc.c:1651  */
    break;

  case 110:
#line 858 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)->add(*(yyvsp[-1].nodito));}
#line 3272 "parser.cpp" /* yacc.c:1651  */
    break;

  case 111:
#line 860 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)= new nodo("dim","dim",yylineno, columna);
                (yyval.nodito)->add(*(yyvsp[-1].nodito));
            }
#line 3281 "parser.cpp" /* yacc.c:1651  */
    break;

  case 112:
#line 868 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = (yyvsp[-1].nodito);
         }
#line 3289 "parser.cpp" /* yacc.c:1651  */
    break;

  case 113:
#line 874 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             for (int i= 0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod = (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3302 "parser.cpp" /* yacc.c:1651  */
    break;

  case 114:
#line 883 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lvalores","lvalores",yylineno, columna);
             for (int i =0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod =  (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3315 "parser.cpp" /* yacc.c:1651  */
    break;

  case 115:
#line 893 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-2].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3321 "parser.cpp" /* yacc.c:1651  */
    break;

  case 116:
#line 894 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("valores","valores",yylineno,columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3327 "parser.cpp" /* yacc.c:1651  */
    break;

  case 117:
#line 899 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3333 "parser.cpp" /* yacc.c:1651  */
    break;

  case 118:
#line 900 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3339 "parser.cpp" /* yacc.c:1651  */
    break;

  case 119:
#line 901 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3345 "parser.cpp" /* yacc.c:1651  */
    break;

  case 120:
#line 904 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipoboleano",(yyvsp[0].TEXT),yylineno,columna);}
#line 3351 "parser.cpp" /* yacc.c:1651  */
    break;

  case 121:
#line 905 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipoentero",(yyvsp[0].TEXT),yylineno,columna);}
#line 3357 "parser.cpp" /* yacc.c:1651  */
    break;

  case 122:
#line 906 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipocaracter",(yyvsp[0].TEXT),yylineno,columna);}
#line 3363 "parser.cpp" /* yacc.c:1651  */
    break;

  case 123:
#line 907 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipodecimal",(yyvsp[0].TEXT),yylineno,columna);}
#line 3369 "parser.cpp" /* yacc.c:1651  */
    break;

  case 124:
#line 908 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipoobjeto",(yyvsp[0].TEXT),yylineno,columna);}
#line 3375 "parser.cpp" /* yacc.c:1651  */
    break;

  case 125:
#line 915 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("ss","ss",yylineno, columna);
             (yyval.nodito)->add(*(yyvsp[-4].nodito)); // Condicion
             (yyval.nodito)->add(*(yyvsp[-2].nodito)); // Valor verdadero
             (yyval.nodito)->add(*(yyvsp[0].nodito)); // Valor falso;
         }
#line 3386 "parser.cpp" /* yacc.c:1651  */
    break;

  case 126:
#line 923 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expl",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3392 "parser.cpp" /* yacc.c:1651  */
    break;

  case 127:
#line 924 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expl",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3398 "parser.cpp" /* yacc.c:1651  */
    break;

  case 128:
#line 925 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expl",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3404 "parser.cpp" /* yacc.c:1651  */
    break;

  case 129:
#line 926 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3410 "parser.cpp" /* yacc.c:1651  */
    break;

  case 130:
#line 929 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3416 "parser.cpp" /* yacc.c:1651  */
    break;

  case 131:
#line 930 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3422 "parser.cpp" /* yacc.c:1651  */
    break;

  case 132:
#line 931 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3428 "parser.cpp" /* yacc.c:1651  */
    break;

  case 133:
#line 932 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3434 "parser.cpp" /* yacc.c:1651  */
    break;

  case 134:
#line 933 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3440 "parser.cpp" /* yacc.c:1651  */
    break;

  case 135:
#line 934 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3446 "parser.cpp" /* yacc.c:1651  */
    break;

  case 136:
#line 935 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3452 "parser.cpp" /* yacc.c:1651  */
    break;

  case 137:
#line 937 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),yylineno, columna);  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3458 "parser.cpp" /* yacc.c:1651  */
    break;

  case 138:
#line 938 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3464 "parser.cpp" /* yacc.c:1651  */
    break;

  case 139:
#line 939 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3470 "parser.cpp" /* yacc.c:1651  */
    break;

  case 140:
#line 940 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3476 "parser.cpp" /* yacc.c:1651  */
    break;

  case 141:
#line 941 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito));  nod->add(*(yyvsp[0].nodito));  (yyval.nodito)=nod ;  }
#line 3482 "parser.cpp" /* yacc.c:1651  */
    break;

  case 142:
#line 942 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("expa",(yyvsp[-1].TEXT),yylineno, columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3488 "parser.cpp" /* yacc.c:1651  */
    break;

  case 143:
#line 943 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("variable",(yyvsp[0].TEXT),yylineno, columna);}
#line 3494 "parser.cpp" /* yacc.c:1651  */
    break;

  case 144:
#line 944 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("acceso",(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));}
#line 3500 "parser.cpp" /* yacc.c:1651  */
    break;

  case 145:
#line 945 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("entero",(yyvsp[0].TEXT),yylineno, columna);}
#line 3506 "parser.cpp" /* yacc.c:1651  */
    break;

  case 146:
#line 946 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("caracter",(yyvsp[0].TEXT),yylineno, columna);}
#line 3512 "parser.cpp" /* yacc.c:1651  */
    break;

  case 147:
#line 947 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("caracter",(yyvsp[0].TEXT),yylineno, columna);}
#line 3518 "parser.cpp" /* yacc.c:1651  */
    break;

  case 148:
#line 948 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("booleano",(yyvsp[0].TEXT),yylineno, columna);}
#line 3524 "parser.cpp" /* yacc.c:1651  */
    break;

  case 149:
#line 949 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("cadena",(yyvsp[0].TEXT),yylineno, columna);}
#line 3530 "parser.cpp" /* yacc.c:1651  */
    break;

  case 150:
#line 950 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("nada",(yyvsp[0].TEXT),yylineno, columna);}
#line 3536 "parser.cpp" /* yacc.c:1651  */
    break;

  case 151:
#line 951 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[0].nodito);}
#line 3542 "parser.cpp" /* yacc.c:1651  */
    break;

  case 152:
#line 952 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 3548 "parser.cpp" /* yacc.c:1651  */
    break;

  case 153:
#line 954 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-1].nodito);
             nodo *nod = new nodo("id",(yyvsp[-2].TEXT),yylineno, columna);
             (yyval.nodito)->hijos.prepend(*nod);
         }
#line 3558 "parser.cpp" /* yacc.c:1651  */
    break;

  case 154:
#line 960 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *nod = new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
             (yyval.nodito)->hijos.prepend(*nod);
         }
#line 3568 "parser.cpp" /* yacc.c:1651  */
    break;

  case 155:
#line 966 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertacadena","convertacadena",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3577 "parser.cpp" /* yacc.c:1651  */
    break;

  case 156:
#line 971 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertaentero","convertaentero",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3586 "parser.cpp" /* yacc.c:1651  */
    break;

  case 157:
#line 976 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 3594 "parser.cpp" /* yacc.c:1651  */
    break;

  case 158:
#line 985 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-2].nodito);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3603 "parser.cpp" /* yacc.c:1651  */
    break;

  case 159:
#line 990 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito) = new nodo("lpar","lpar",yylineno,columna);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3612 "parser.cpp" /* yacc.c:1651  */
    break;

  case 160:
#line 1000 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("llamada",(yyvsp[-2].TEXT),yylineno,columna);
             //$$->hijos.append(*params);
         }
#line 3621 "parser.cpp" /* yacc.c:1651  */
    break;

  case 161:
#line 1005 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("llamada",(yyvsp[-3].TEXT),yylineno,columna);
             for(int i= 0; i<(yyvsp[-1].nodito)->hijos.count(); i++)
             {
                (yyval.nodito)->hijos.append((yyvsp[-1].nodito)->hijos[i]);
             }
         }
#line 3633 "parser.cpp" /* yacc.c:1651  */
    break;

  case 162:
#line 1013 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *f= new nodo("funcion",(yyvsp[-3].TEXT),yylineno,columna);
             (yyval.nodito)->hijos.prepend(*f);
         }
#line 3643 "parser.cpp" /* yacc.c:1651  */
    break;

  case 163:
#line 1019 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[0].nodito);
             nodo *f= new nodo("funcion",(yyvsp[-4].TEXT),yylineno,columna);
             f->hijos.append(*(yyvsp[-2].nodito));
             (yyval.nodito)->hijos.prepend(*f);
         }
#line 3654 "parser.cpp" /* yacc.c:1651  */
    break;

  case 164:
#line 1026 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) =(yyvsp[0].nodito);
             nodo *f= new nodo("id",(yyvsp[-1].TEXT),yylineno,columna);
             (yyval.nodito)->hijos.prepend(*f);
        }
#line 3664 "parser.cpp" /* yacc.c:1651  */
    break;

  case 165:
#line 1035 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("aumento","++",yylineno, columna); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3670 "parser.cpp" /* yacc.c:1651  */
    break;

  case 166:
#line 1036 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("decremento","--",yylineno, columna); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3676 "parser.cpp" /* yacc.c:1651  */
    break;

  case 167:
#line 1041 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-2].nodito);
             nodo *nod= new nodo("id",(yyvsp[0].TEXT),yylineno, columna);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3686 "parser.cpp" /* yacc.c:1651  */
    break;

  case 168:
#line 1047 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = (yyvsp[-4].nodito);
            nodo *nod= new nodo("funcion",(yyvsp[-2].TEXT),yylineno, columna);
            (yyval.nodito)->hijos.append(*nod);
        }
#line 3696 "parser.cpp" /* yacc.c:1651  */
    break;

  case 169:
#line 1053 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-5].nodito);
             nodo *nod= new nodo("funcion",(yyvsp[-3].TEXT),yylineno, columna);
             nod->hijos.append(*(yyvsp[-1].nodito));
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3707 "parser.cpp" /* yacc.c:1651  */
    break;

  case 170:
#line 1060 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = (yyvsp[-3].nodito);
            nodo *nod= new nodo("idv",(yyvsp[-1].TEXT),yylineno, columna);
            nod->hijos.append(*(yyvsp[0].nodito));
            (yyval.nodito)->hijos.append(*nod);
         }
#line 3718 "parser.cpp" /* yacc.c:1651  */
    break;

  case 171:
#line 1067 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[0].TEXT),yylineno, columna);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3728 "parser.cpp" /* yacc.c:1651  */
    break;

  case 172:
#line 1073 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",yylineno, columna);
             nodo *nod= new nodo("funcion",(yyvsp[-2].TEXT),yylineno, columna);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3738 "parser.cpp" /* yacc.c:1651  */
    break;

  case 173:
#line 1079 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",yylineno, columna);
             nodo *nod= new nodo("funcion",(yyvsp[-3].TEXT),yylineno, columna);
             nod->hijos.append(*(yyvsp[-1].nodito));
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3749 "parser.cpp" /* yacc.c:1651  */
    break;

  case 174:
#line 1086 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",yylineno, columna);
             nodo *nod= new nodo("idv",(yyvsp[-1].TEXT),yylineno, columna);
             nod->hijos.append(*(yyvsp[0].nodito));
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3760 "parser.cpp" /* yacc.c:1651  */
    break;


#line 3764 "parser.cpp" /* yacc.c:1651  */
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
#line 1092 "sintactico.yy" /* yacc.c:1910  */

