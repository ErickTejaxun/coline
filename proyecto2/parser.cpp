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


#line 93 "parser.cpp" /* yacc.c:339  */

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
#line 32 "sintactico.yy" /* yacc.c:355  */

//se especifican los tipo de valores para los no terminales y lo terminales
char TEXT [256];
class nodo *nodito;

#line 227 "parser.cpp" /* yacc.c:355  */
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

#line 258 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   3028

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  489

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
       0,   203,   203,   205,   206,   210,   211,   214,   219,   226,
     233,   242,   252,   257,   265,   266,   272,   273,   274,   275,
     284,   285,   288,   289,   290,   291,   292,   293,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     310,   319,   327,   335,   343,   354,   365,   374,   380,   391,
     397,   401,   407,   413,   422,   429,   436,   446,   451,   457,
     465,   472,   478,   485,   491,   502,   503,   504,   506,   512,
     521,   523,   529,   534,   541,   547,   556,   563,   570,   580,
     589,   597,   606,   616,   625,   637,   642,   647,   654,   660,
     668,   676,   690,   697,   706,   714,   722,   733,   734,   735,
     736,   737,   742,   748,   758,   765,   772,   786,   794,   802,
     813,   814,   822,   828,   837,   848,   849,   854,   855,   856,
     859,   860,   861,   862,   863,   869,   878,   879,   880,   881,
     884,   885,   886,   887,   888,   889,   890,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   913,   919,   924,   929,   934,   943,
     948,   956,   962,   970,   981,   992,   993,   996,  1002,  1009,
    1015,  1023,  1024,  1032,  1038,  1044,  1051,  1058,  1064,  1070,
    1077
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
  "EXPR", "EXPA", "LPAR", "LLAMADA", "UNARIOS", "ACCESO", "ACC", YY_NULLPTR
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

#define YYPACT_NINF -242

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-242)))

#define YYTABLE_NINF -125

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     433,    13,  -242,  -242,  -242,     9,    29,   433,  -242,   -55,
       2,  -242,    -6,    78,  -242,  -242,  -242,    88,   303,    97,
     104,    14,    98,  -242,  -242,  -242,  -242,   109,   394,   134,
     420,  -242,  -242,   401,  -242,  -242,  -242,   108,   125,   295,
     163,  -242,   303,   210,   247,   234,   401,  -242,  -242,   316,
     235,  -242,  -242,   263,   249,   195,   197,   359,  -242,  -242,
     152,   281,   372,  -242,   303,   816,   302,  -242,   311,   318,
    -242,   329,   247,   387,   345,   341,   247,   357,  -242,  -242,
     174,   395,   247,  2958,   550,    -4,  -242,   373,  -242,   964,
    -242,   303,   402,   247,   386,   396,   407,  2815,   427,   247,
     247,   416,   435,  -242,  -242,  -242,  -242,  -242,    10,  2958,
     415,  2958,   441,   456,   381,  -242,   257,  -242,   908,  -242,
    -242,   468,  -242,  -242,  -242,   376,  2958,   613,   247,  -242,
    1047,  2815,  -242,   471,   470,    47,   479,   481,   381,  2958,
     413,   418,   492,   503,   507,   506,   509,   513,   514,   517,
     520,   521,   447,   460,   906,  -242,   462,  -242,   463,  -242,
    -242,  -242,   465,   466,   474,   476,   477,   526,   565,   480,
     482,   556,   559,   567,   247,   564,   714,   572,    -9,    -3,
     494,    85,   622,  -242,  2958,  2958,   497,  -242,  2958,  2958,
    -242,  -242,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   576,  2958,   306,   575,  -242,   106,   585,
    -242,   989,  2815,  -242,  -242,  -242,  -242,  -242,   550,   220,
     176,   763,  2958,   102,   106,  -242,  -242,  2958,  2958,  2958,
    2815,   140,   560,   561,   566,   592,  2958,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,    17,  -242,
    -242,  2815,   594,   596,   593,  2815,  -242,   106,   141,    52,
     497,   840,   600,   601,  -242,    92,   129,   578,  -242,   622,
     622,    82,    82,   351,   565,   565,   565,   565,   565,   565,
    2898,   188,  -242,  2958,   160,   599,  -242,  1072,  -242,   550,
     102,   550,   604,   182,    56,   550,   194,   214,   227,  1155,
     246,   381,   529,   539,   619,   568,   569,   570,   618,   330,
    1238,  2815,  2815,   624,  1321,  -242,  2958,  2906,   471,  -242,
     199,   386,   288,  -242,  -242,  -242,   248,  2958,   439,   106,
    -242,   625,  2815,  -242,  -242,   550,  -242,  -242,  -242,  2958,
    -242,   630,   631,   633,   562,   220,   102,   102,  2958,  2958,
     609,   579,   580,   582,   571,  2958,  -242,  1404,  1487,  2815,
    -242,   106,  -242,   260,  -242,   471,  2966,   471,  -242,   106,
    -242,  2958,  2958,  1570,  -242,   192,  2815,   361,  2815,   637,
     102,     0,     8,   656,   657,   658,  -242,   250,  -242,  -242,
    1653,  -242,  -242,   265,   106,   455,  -242,  -242,  2958,  1736,
    2958,   653,   661,   388,  -242,  1819,  2958,  2822,  2822,   247,
     247,   247,  -242,  -242,  -242,  -242,   270,   444,   239,   663,
    -242,   654,  -242,  -242,   296,   133,   666,   667,   669,   670,
     671,   673,   674,  -242,   676,   675,  -242,   448,   679,  2815,
     688,  -242,   689,   690,   691,   693,  -242,  -242,  -242,  2958,
    2815,   678,   694,  2815,  1902,  2815,  2815,  2815,  2815,  2815,
     313,  1985,  2958,  2815,  2068,  -242,  2151,  2234,  2317,  2400,
    2483,   695,  -242,   326,  2566,  -242,  -242,  -242,  -242,  -242,
    -242,  2815,   696,  -242,  2649,  2815,  -242,  2732,  -242
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
       0,     0,     0,     0,     0,   150,     0,   129,   136,   158,
     151,     0,   119,   103,   118,   117,     0,     0,    71,    91,
       0,     0,    72,    75,     0,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    34,     0,    29,
      30,    32,     0,     0,     0,     0,     0,     0,     0,   158,
     151,     0,     0,     0,    71,     0,     0,     0,   144,   153,
     171,     0,   142,   128,     0,     0,   155,   111,     0,     0,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   108,     0,
      90,     0,     0,    97,    98,    99,   100,   101,     0,   144,
     153,     0,     0,   155,    60,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    25,    76,
      20,    39,    33,    27,    24,    22,    37,    23,   102,    28,
      31,     0,     0,     0,     0,     0,   161,   160,     0,   169,
     154,     0,     0,     0,   152,     0,     0,   127,   126,   137,
     138,   139,   140,   141,   133,   132,   135,   134,   130,   131,
       0,     0,   110,     0,     0,     0,    78,     0,    92,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,   170,   164,
       0,   167,   172,   156,   157,    69,     0,     0,     0,   116,
     112,     0,     0,    84,    93,     0,    94,     8,     7,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     102,     0,     0,     0,     0,     0,    77,     0,     0,     0,
      83,   159,   178,     0,   163,   168,     0,   176,    68,   125,
     114,     0,     0,     0,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    81,    80,
       0,   179,   174,     0,   115,     0,    82,     9,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,    40,    79,   175,   113,     0,    47,     0,     0,
      54,     0,    57,    46,     0,   143,     0,   151,     0,   151,
       0,     0,     0,    10,     0,     0,    48,    50,     0,     0,
       0,    45,     0,     0,     0,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,    51,     0,     0,    59,    55,    41,    43,    42,
      44,     0,     0,    49,     0,     0,    53,     0,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -242,  -242,  -242,   701,  -242,   489,  -242,   -28,   -27,   442,
    -152,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,   308,  -242,  -242,   101,  -242,    16,  -242,   620,  -242,
     684,   697,   -46,    68,  -242,  -230,  -179,    15,  -242,    95,
     -86,  -242,  -242,   344,  -202,   -18,  -242,   467,  -242,   343,
    -241,    39,   -80,  -101,  -242
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,   152,   153,     9,    30,    31,   154,
     155,   156,   157,   158,   159,   160,   436,   437,   161,   402,
     403,   404,   162,    32,    33,   122,    68,    69,    70,    34,
      35,    36,    62,    63,    11,   163,   218,   164,   165,   166,
      85,   207,   284,   328,   123,   167,   124,   125,   117,   168,
     258,   119,   120,   220,   180
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   302,   240,    52,   126,    18,   261,   179,   133,   126,
      49,    81,    39,   186,    65,    57,   288,   170,    13,   176,
     320,    12,   178,    83,    39,    42,    71,    81,    73,    14,
      83,    16,   127,    37,   188,   189,    89,   223,    52,   326,
     289,   291,   188,   189,   295,    37,    39,    39,    55,   219,
      19,   170,    17,    84,    71,  -124,   176,    37,    71,   240,
      83,   317,    52,   130,    71,    83,   213,   214,   215,   216,
      43,    39,   339,    39,   170,    71,   363,   260,   177,    37,
      37,    71,    71,   217,   262,    20,   407,   334,    95,   336,
     188,   189,    98,   340,   408,   264,    21,   177,   102,   190,
     191,    10,   323,    52,    37,    40,    37,    44,    10,   196,
      71,   335,    39,    38,    41,   172,   173,    45,   290,   188,
     189,   213,   214,   215,   216,    38,   188,   189,    56,    46,
      88,   170,   170,   374,   177,   240,   169,    38,   217,   324,
     188,   189,   176,    50,   209,    37,    83,   240,   300,    88,
     170,   315,   213,   214,   215,   216,    71,   316,   240,    38,
      38,    82,   240,   188,   189,    83,   289,   291,   295,   217,
     169,   170,   330,   318,    64,   170,   331,   426,   428,    23,
      24,    25,    26,   100,    38,   261,    38,    83,    84,   262,
     254,   301,   338,   169,    58,   213,   214,   215,   216,   346,
     347,   335,   397,   327,   341,   240,   240,   170,   398,   364,
      84,    59,   217,   304,   345,   316,   188,   189,    66,   170,
     177,   240,   188,   189,   342,    38,   188,   189,   188,   189,
     170,   170,   170,   126,   170,   365,   367,   343,   240,   213,
     214,   215,   216,    72,   380,    75,   303,   240,   188,   189,
     169,   169,   170,   240,   438,    67,   217,    77,   368,    83,
     412,   188,   189,   262,   316,   213,   214,   215,   216,   169,
     391,   187,    76,   188,   189,   414,   316,   170,   170,   170,
     433,    78,   217,    79,   188,   189,    23,    24,    25,    26,
     169,   188,   189,   170,   169,    86,   170,   366,   170,   188,
     189,    83,   240,    60,   188,   189,   441,   177,    61,   240,
     170,    22,   240,    91,   240,   240,   240,   240,   240,   170,
     282,    92,   240,   471,    74,   170,   169,   427,   429,    61,
     188,   189,   240,   177,    93,   240,   482,    94,   169,   219,
     188,   189,    23,    24,    25,    26,   355,   188,   189,   169,
     169,   169,    97,   169,    82,     2,     3,     4,    27,   170,
     188,   189,    28,    29,   188,   189,    99,    80,   190,   191,
     170,   169,    61,   170,   170,   170,   170,   170,   170,   170,
      87,   170,   128,   170,   170,    61,   170,   170,   170,   170,
     170,   430,   431,   432,   170,    96,   169,   169,   169,    83,
      61,   170,    22,   101,   170,   170,   134,   170,    61,    53,
     188,   189,   169,   131,   204,   169,   100,   169,   103,   104,
     105,   106,   107,   108,   109,   174,   118,   118,    22,   169,
     400,   401,    51,    23,    24,    25,    26,   171,   169,   110,
      23,    24,    25,    26,   169,   175,     2,     3,     4,    27,
     184,   370,   118,   182,   118,   371,    54,   400,   421,    23,
      24,    25,    26,   112,   113,   185,   114,   415,   177,   118,
     118,   371,     2,     3,     4,    27,   203,   115,   169,    28,
      29,   212,   118,     1,   126,     2,     3,     4,   221,   169,
     222,     5,   169,   169,   169,   169,   169,   169,   169,   225,
     169,   227,   169,   169,   226,   169,   169,   169,   169,   169,
     434,   435,   228,   169,   451,   452,   229,   230,   231,   118,
     169,   232,   233,   169,   169,   234,   169,   118,   118,   235,
     236,   118,   118,   237,   248,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   238,   118,   241,   242,
     116,   243,   244,   103,   104,   105,   106,   107,   108,   109,
     245,   118,   246,   247,   118,   118,   249,   251,   250,   252,
     118,   118,   118,   211,   110,   255,   181,   253,   183,   118,
     259,   263,   190,   191,   262,   280,   283,   111,   192,   193,
     194,   195,   196,   205,   208,   285,   305,   306,   112,   113,
     308,   114,   307,   313,   118,   311,   224,   312,   321,   322,
     332,   121,   115,   189,   337,   348,   103,   104,   105,   106,
     107,   108,   109,   118,   206,   349,   118,   350,   354,   351,
     352,   353,   118,   379,   118,   359,   372,   110,   118,   190,
     191,   376,   377,   257,   378,    84,   406,   194,   195,   196,
     111,   265,   266,   383,   287,   267,   268,   386,   384,   118,
     118,   112,   113,   385,   114,   409,   410,   411,   419,   440,
     118,   281,   299,   420,   439,   115,   442,   443,   118,   444,
     445,   446,   118,   447,   448,   449,   450,   462,   293,   294,
     453,   118,   118,   310,   296,   297,   298,   314,   118,   455,
     456,   457,   458,   309,   459,   463,   481,   485,    15,   118,
     292,   422,    47,   132,   118,   118,   395,   103,   104,   105,
     106,   107,   108,   109,   256,    48,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,   118,     0,   118,     0,     0,     0,   257,     0,   118,
     329,   111,     0,   357,   358,     0,     0,     0,     0,     0,
       0,     0,   112,   113,     0,   114,   103,   104,   105,   106,
     107,   108,   109,     0,   373,     0,   115,     0,     0,     0,
       0,     0,     0,   361,   257,     0,     0,   110,     0,     0,
       0,     0,   118,     0,   369,     0,     0,     0,     0,     0,
     111,   390,     0,     0,     0,   118,   375,   137,     0,     0,
       0,   112,   113,     0,   114,   381,   382,     0,   399,     0,
     405,     0,   387,     0,    22,   115,     0,     0,    90,     0,
       0,     0,     0,   393,     0,     0,     0,     0,   394,   329,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     319,     0,     0,     0,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,   110,   416,     0,   418,     2,     3,
       4,    27,     0,   424,     0,    28,    29,   111,     0,     0,
       0,   454,     0,     0,     0,     0,     0,     0,   112,   113,
       0,   114,   461,     0,     0,   464,     0,   466,   467,   468,
     469,   470,   115,     0,     0,   474,     0,     0,     0,   103,
     104,   105,   106,   107,   135,   109,   460,     0,   239,     0,
       0,     0,     0,   484,     0,   190,   191,   487,     0,   473,
     110,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,     0,     0,     0,    23,    24,    25,    26,   136,
     137,     0,     0,     0,   112,   113,     0,   138,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,   115,   140,
     141,   142,    22,     0,   143,     0,   129,   144,   145,   146,
     147,     0,     0,     0,   148,     0,     0,   149,     0,     0,
     150,   151,   103,   104,   105,   106,   107,   135,   109,     0,
       0,   286,     0,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     2,     3,     4,    27,
       0,     0,     0,    28,    29,     0,     0,     0,    23,    24,
      25,    26,   136,   137,     0,     0,     0,   112,   113,     0,
     138,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,   115,   140,   141,   142,    22,     0,   143,     0,   210,
     144,   145,   146,   147,     0,     0,     0,   148,     0,     0,
     149,     0,     0,   150,   151,   103,   104,   105,   106,   107,
     135,   109,     0,     0,   333,     0,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     2,
       3,     4,    27,     0,     0,     0,    28,    29,     0,     0,
       0,    23,    24,    25,    26,   136,   137,     0,     0,     0,
     112,   113,     0,   138,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,   115,   140,   141,   142,     0,     0,
     143,     0,     0,   144,   145,   146,   147,     0,     0,     0,
     148,     0,     0,   149,     0,     0,   150,   151,   103,   104,
     105,   106,   107,   135,   109,     0,     0,   344,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   136,   137,
       0,     0,     0,   112,   113,     0,   138,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,   115,   140,   141,
     142,     0,     0,   143,     0,     0,   144,   145,   146,   147,
       0,     0,     0,   148,     0,     0,   149,     0,     0,   150,
     151,   103,   104,   105,   106,   107,   135,   109,     0,     0,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   136,   137,     0,     0,     0,   112,   113,     0,   138,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
     115,   140,   141,   142,     0,     0,   143,     0,     0,   144,
     145,   146,   147,     0,     0,     0,   148,     0,     0,   149,
       0,     0,   150,   151,   103,   104,   105,   106,   107,   135,
     109,     0,     0,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   136,   137,     0,     0,     0,   112,
     113,     0,   138,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   115,   140,   141,   142,     0,     0,   143,
       0,     0,   144,   145,   146,   147,     0,     0,     0,   148,
       0,     0,   149,     0,     0,   150,   151,   103,   104,   105,
     106,   107,   135,   109,     0,     0,   388,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   136,   137,     0,
       0,     0,   112,   113,     0,   138,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,   115,   140,   141,   142,
       0,     0,   143,     0,     0,   144,   145,   146,   147,     0,
       0,     0,   148,     0,     0,   149,     0,     0,   150,   151,
     103,   104,   105,   106,   107,   135,   109,     0,     0,   389,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     136,   137,     0,     0,     0,   112,   113,     0,   138,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,   115,
     140,   141,   142,     0,     0,   143,     0,     0,   144,   145,
     146,   147,     0,     0,     0,   148,     0,     0,   149,     0,
       0,   150,   151,   103,   104,   105,   106,   107,   135,   109,
       0,     0,   396,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   136,   137,     0,     0,     0,   112,   113,
       0,   138,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,   115,   140,   141,   142,     0,     0,   143,     0,
       0,   144,   145,   146,   147,     0,     0,     0,   148,     0,
       0,   149,     0,     0,   150,   151,   103,   104,   105,   106,
     107,   135,   109,     0,     0,   413,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   136,   137,     0,     0,
       0,   112,   113,     0,   138,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,   115,   140,   141,   142,     0,
       0,   143,     0,     0,   144,   145,   146,   147,     0,     0,
       0,   148,     0,     0,   149,     0,     0,   150,   151,   103,
     104,   105,   106,   107,   135,   109,     0,     0,   417,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   136,
     137,     0,     0,     0,   112,   113,     0,   138,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,   115,   140,
     141,   142,     0,     0,   143,     0,     0,   144,   145,   146,
     147,     0,     0,     0,   148,     0,     0,   149,     0,     0,
     150,   151,   103,   104,   105,   106,   107,   135,   109,     0,
       0,   423,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   136,   137,     0,     0,     0,   112,   113,     0,
     138,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,   115,   140,   141,   142,     0,     0,   143,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   148,     0,     0,
     149,     0,     0,   150,   151,   103,   104,   105,   106,   107,
     135,   109,     0,     0,   465,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   136,   137,     0,     0,     0,
     112,   113,     0,   138,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,   115,   140,   141,   142,     0,     0,
     143,     0,     0,   144,   145,   146,   147,     0,     0,     0,
     148,     0,     0,   149,     0,     0,   150,   151,   103,   104,
     105,   106,   107,   135,   109,     0,     0,   472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   136,   137,
       0,     0,     0,   112,   113,     0,   138,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,   115,   140,   141,
     142,     0,     0,   143,     0,     0,   144,   145,   146,   147,
       0,     0,     0,   148,     0,     0,   149,     0,     0,   150,
     151,   103,   104,   105,   106,   107,   135,   109,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   136,   137,     0,     0,     0,   112,   113,     0,   138,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
     115,   140,   141,   142,     0,     0,   143,     0,     0,   144,
     145,   146,   147,     0,     0,     0,   148,     0,     0,   149,
       0,     0,   150,   151,   103,   104,   105,   106,   107,   135,
     109,     0,     0,   476,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   136,   137,     0,     0,     0,   112,
     113,     0,   138,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,   115,   140,   141,   142,     0,     0,   143,
       0,     0,   144,   145,   146,   147,     0,     0,     0,   148,
       0,     0,   149,     0,     0,   150,   151,   103,   104,   105,
     106,   107,   135,   109,     0,     0,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   136,   137,     0,
       0,     0,   112,   113,     0,   138,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,   115,   140,   141,   142,
       0,     0,   143,     0,     0,   144,   145,   146,   147,     0,
       0,     0,   148,     0,     0,   149,     0,     0,   150,   151,
     103,   104,   105,   106,   107,   135,   109,     0,     0,   478,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     136,   137,     0,     0,     0,   112,   113,     0,   138,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,   115,
     140,   141,   142,     0,     0,   143,     0,     0,   144,   145,
     146,   147,     0,     0,     0,   148,     0,     0,   149,     0,
       0,   150,   151,   103,   104,   105,   106,   107,   135,   109,
       0,     0,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   136,   137,     0,     0,     0,   112,   113,
       0,   138,     0,     0,     0,     0,     0,   139,     0,     0,
       0,     0,   115,   140,   141,   142,     0,     0,   143,     0,
       0,   144,   145,   146,   147,     0,     0,     0,   148,     0,
       0,   149,     0,     0,   150,   151,   103,   104,   105,   106,
     107,   135,   109,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   136,   137,     0,     0,
       0,   112,   113,     0,   138,     0,     0,     0,     0,     0,
     139,     0,     0,     0,     0,   115,   140,   141,   142,     0,
       0,   143,     0,     0,   144,   145,   146,   147,     0,     0,
       0,   148,     0,     0,   149,     0,     0,   150,   151,   103,
     104,   105,   106,   107,   135,   109,     0,     0,   483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   136,
     137,     0,     0,     0,   112,   113,     0,   138,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,   115,   140,
     141,   142,     0,     0,   143,     0,     0,   144,   145,   146,
     147,     0,     0,     0,   148,     0,     0,   149,     0,     0,
     150,   151,   103,   104,   105,   106,   107,   135,   109,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   136,   137,     0,     0,     0,   112,   113,     0,
     138,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,   115,   140,   141,   142,     0,     0,   143,     0,     0,
     144,   145,   146,   147,     0,     0,     0,   148,     0,     0,
     149,     0,     0,   150,   151,   103,   104,   105,   106,   107,
     135,   109,     0,     0,   488,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   136,   137,     0,     0,     0,
     112,   113,     0,   138,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,   115,   140,   141,   142,     0,     0,
     143,     0,     0,   144,   145,   146,   147,     0,     0,     0,
     148,     0,     0,   149,     0,     0,   150,   151,   103,   104,
     105,   106,   107,   135,   109,   103,   104,   105,   106,   107,
     425,   109,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   136,   137,
       0,     0,     0,   112,   113,     0,   138,     0,     0,     0,
     112,   113,   139,   138,     0,     0,     0,   115,   140,   141,
     142,     0,     0,   143,   115,     0,   144,   145,   146,   147,
       0,     0,     0,   148,     0,     0,   149,     0,     0,   150,
     151,   103,   104,   105,   106,   107,   108,   109,   325,   103,
     104,   105,   106,   107,   108,   109,   362,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,   112,   113,     0,   114,
       0,     0,     0,     0,   112,   113,     0,   114,     0,     0,
     115,   103,   104,   105,   106,   107,   108,   109,   115,   103,
     104,   105,   106,   107,   108,   109,   392,     0,     0,     0,
       0,     0,   110,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,   112,   113,     0,   114,
       0,     0,     0,     0,   112,   113,     0,   114,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,   115
};

static const yytype_int16 yycheck[] =
{
      18,   231,   154,    30,    13,    11,     9,   108,    94,    13,
      28,    57,    30,   114,    42,    33,   218,    97,     9,     9,
     261,     8,   108,    13,    42,    11,    44,    73,    46,     0,
      13,    86,    36,    18,    34,    35,    64,   138,    65,   280,
     219,   220,    34,    35,   223,    30,    64,    65,    33,   135,
      56,   131,    50,    36,    72,     8,     9,    42,    76,   211,
      13,     9,    89,    91,    82,    13,    19,    20,    21,    22,
      56,    89,    16,    91,   154,    93,   317,   178,    87,    64,
      65,    99,   100,    36,    87,     7,    86,   289,    72,   291,
      34,    35,    76,   295,    86,    10,     8,    87,    82,    17,
      18,     0,    10,   130,    89,     8,    91,     9,     7,    27,
     128,   290,   130,    18,    10,    99,   100,     8,   219,    34,
      35,    19,    20,    21,    22,    30,    34,    35,    33,    28,
      62,   211,   212,   335,    87,   287,    97,    42,    36,    10,
      34,    35,     9,     9,   128,   130,    13,   299,     8,    81,
     230,    10,    19,    20,    21,    22,   174,    16,   310,    64,
      65,     9,   314,    34,    35,    13,   345,   346,   347,    36,
     131,   251,    12,   259,    11,   255,    16,   407,   408,    39,
      40,    41,    42,     9,    89,     9,    91,    13,    36,    87,
     174,    51,    10,   154,    86,    19,    20,    21,    22,   300,
     301,   380,    10,    15,    10,   357,   358,   287,    16,    10,
      36,    86,    36,   231,   300,    16,    34,    35,     8,   299,
      87,   373,    34,    35,    10,   130,    34,    35,    34,    35,
     310,   311,   312,    13,   314,   321,   322,    10,   390,    19,
      20,    21,    22,     9,   345,    10,   231,   399,    34,    35,
     211,   212,   332,   405,    15,     8,    36,     8,    10,    13,
      10,    34,    35,    87,    16,    19,    20,    21,    22,   230,
      10,    14,     9,    34,    35,    10,    16,   357,   358,   359,
      10,    86,    36,    86,    34,    35,    39,    40,    41,    42,
     251,    34,    35,   373,   255,    14,   376,     9,   378,    34,
      35,    13,   454,     8,    34,    35,    10,    87,    13,   461,
     390,     8,   464,    11,   466,   467,   468,   469,   470,   399,
      14,    10,   474,    10,     8,   405,   287,   407,   408,    13,
      34,    35,   484,    87,    16,   487,    10,     8,   299,   425,
      34,    35,    39,    40,    41,    42,    16,    34,    35,   310,
     311,   312,    11,   314,     9,    52,    53,    54,    55,   439,
      34,    35,    59,    60,    34,    35,     9,     8,    17,    18,
     450,   332,    13,   453,   454,   455,   456,   457,   458,   459,
       8,   461,     9,   463,   464,    13,   466,   467,   468,   469,
     470,   409,   410,   411,   474,     8,   357,   358,   359,    13,
      13,   481,     8,     8,   484,   485,    10,   487,    13,     8,
      34,    35,   373,    11,    38,   376,     9,   378,     3,     4,
       5,     6,     7,     8,     9,     9,    83,    84,     8,   390,
      69,    70,    12,    39,    40,    41,    42,    10,   399,    24,
      39,    40,    41,    42,   405,    10,    52,    53,    54,    55,
       9,    12,   109,   110,   111,    16,    55,    69,    70,    39,
      40,    41,    42,    48,    49,     9,    51,    12,    87,   126,
     127,    16,    52,    53,    54,    55,     8,    62,   439,    59,
      60,    11,   139,    50,    13,    52,    53,    54,     9,   450,
       9,    58,   453,   454,   455,   456,   457,   458,   459,    86,
     461,     9,   463,   464,    86,   466,   467,   468,   469,   470,
      66,    67,     9,   474,    66,    67,     9,    11,     9,   176,
     481,     8,     8,   484,   485,     8,   487,   184,   185,     9,
       9,   188,   189,    86,     8,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    86,   204,    86,    86,
      83,    86,    86,     3,     4,     5,     6,     7,     8,     9,
      86,   218,    86,    86,   221,   222,    86,    11,    86,    10,
     227,   228,   229,   131,    24,    11,   109,    10,   111,   236,
       8,    87,    17,    18,    87,     9,    11,    37,    23,    24,
      25,    26,    27,   126,   127,    10,    36,    36,    48,    49,
       8,    51,    36,    10,   261,    11,   139,    11,     8,     8,
      11,    61,    62,    35,    10,    86,     3,     4,     5,     6,
       7,     8,     9,   280,    11,    86,   283,     8,    10,    61,
      61,    61,   289,    71,   291,    11,    11,    24,   295,    17,
      18,    11,    11,   176,    11,    36,     9,    25,    26,    27,
      37,   184,   185,    74,   212,   188,   189,    86,    78,   316,
     317,    48,    49,    81,    51,     9,     9,     9,    15,    15,
     327,   204,   230,    12,    11,    62,    10,    10,   335,    10,
      10,    10,   339,    10,    10,     9,    11,     9,   221,   222,
      11,   348,   349,   251,   227,   228,   229,   255,   355,    11,
      11,    11,    11,   236,    11,    11,    11,    11,     7,   366,
     221,   403,    28,    93,   371,   372,   372,     3,     4,     5,
       6,     7,     8,     9,    10,    28,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,   398,    -1,   400,    -1,    -1,    -1,   280,    -1,   406,
     283,    37,    -1,   311,   312,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    51,     3,     4,     5,     6,
       7,     8,     9,    -1,   332,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,   316,   317,    -1,    -1,    24,    -1,    -1,
      -1,    -1,   449,    -1,   327,    -1,    -1,    -1,    -1,    -1,
      37,   359,    -1,    -1,    -1,   462,   339,    44,    -1,    -1,
      -1,    48,    49,    -1,    51,   348,   349,    -1,   376,    -1,
     378,    -1,   355,    -1,     8,    62,    -1,    -1,    12,    -1,
      -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,   371,   372,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    24,   398,    -1,   400,    52,    53,
      54,    55,    -1,   406,    -1,    59,    60,    37,    -1,    -1,
      -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    51,   450,    -1,    -1,   453,    -1,   455,   456,   457,
     458,   459,    62,    -1,    -1,   463,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,   449,    -1,    12,    -1,
      -1,    -1,    -1,   481,    -1,    17,    18,   485,    -1,   462,
      24,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,     8,    -1,    68,    -1,    12,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    85,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    52,    53,    54,    55,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,     8,    -1,    68,    -1,    12,
      71,    72,    73,    74,    -1,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    84,    85,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
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
       5,     6,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,    -1,
      48,    49,    57,    51,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    68,    62,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,    84,
      85,     3,     4,     5,     6,     7,     8,     9,    10,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      62,     3,     4,     5,     6,     7,     8,     9,    62,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62
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
     142,   135,   137,   135,     9,     9,   141,    14,    34,    35,
      17,    18,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     8,    38,   135,    11,   129,   135,   114,
      12,    97,    11,    19,    20,    21,    22,    36,   124,   128,
     141,     9,     9,   141,   135,    86,    86,     9,     9,     9,
      11,     9,     8,     8,     8,     9,     9,    86,    86,    12,
      98,    86,    86,    86,    86,    86,    86,    86,     8,    86,
      86,    11,    10,    10,   114,    11,    10,   135,   138,     8,
     141,     9,    87,    87,    10,   135,   135,   135,   135,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
       9,   135,    14,    11,   130,    10,    12,    97,   132,   124,
     141,   124,    93,   135,   135,   124,   135,   135,   135,    97,
       8,    51,   123,   125,   133,    36,    36,    36,     8,   135,
      97,    11,    11,    10,    97,    10,    16,     9,   128,    10,
     138,     8,     8,    10,    10,    10,   138,    15,   131,   135,
      12,    16,    11,    12,   132,   124,   132,    10,    10,    16,
     132,    10,    10,    10,    12,   128,   141,   141,    86,    86,
       8,    61,    61,    61,    10,    16,    12,    97,    97,    11,
      12,   135,    10,   138,    10,   128,     9,   128,    10,   135,
      12,    16,    11,    97,   132,   135,    11,    11,    11,    71,
     141,   135,   135,    74,    78,    81,    86,   135,    12,    12,
      97,    10,    10,   135,   135,   131,    12,    10,    16,    97,
      69,    70,   107,   108,   109,    97,     9,    86,    86,     9,
       9,     9,    10,    12,    10,    12,   135,    12,   135,    15,
      12,    70,   109,    12,   135,     8,   123,   140,   123,   140,
     133,   133,   133,    10,    66,    67,   104,   105,    15,    11,
      15,    10,    10,    10,    10,    10,    10,    10,    10,     9,
      11,    66,    67,    11,    97,    11,    11,    11,    11,    11,
     135,    97,     9,    11,    97,    12,    97,    97,    97,    97,
      97,    10,    12,   135,    97,    12,    12,    12,    12,    12,
      12,    11,    10,    12,    97,    11,    12,    97,    12
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
     137,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     138,   139,   139,   139,   139,   140,   140,   141,   141,   141,
     141,   141,   141,   142,   142,   142,   142,   142,   142,   142,
     142
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
       8,     7,     3,     4,     4,     4,     5,     1,     1,     1,
       1,     1,     2,     4,     8,     8,     8,     3,     5,     5,
       4,     3,     3,     5,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     2,     4,     4,     1,     3,
       1,     3,     4,     5,     4,     2,     2,     3,     4,     2,
       3,     1,     3,     3,     5,     6,     4,     2,     4,     5,
       3
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
#line 203 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito); raiz = (yyval.nodito);}
#line 2270 "parser.cpp" /* yacc.c:1651  */
    break;

  case 3:
#line 205 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2276 "parser.cpp" /* yacc.c:1651  */
    break;

  case 4:
#line 206 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nuevo = new nodo("sentenciasg","sentenciasg",(yylsp[0]).first_line, (yylsp[0]).first_column); nuevo->add(*(yyvsp[0].nodito)); (yyval.nodito) = nuevo;}
#line 2282 "parser.cpp" /* yacc.c:1651  */
    break;

  case 5:
#line 210 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2288 "parser.cpp" /* yacc.c:1651  */
    break;

  case 6:
#line 211 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[0].nodito);}
#line 2294 "parser.cpp" /* yacc.c:1651  */
    break;

  case 7:
#line 215 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("imprimir",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2303 "parser.cpp" /* yacc.c:1651  */
    break;

  case 8:
#line 220 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("imprimir",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2312 "parser.cpp" /* yacc.c:1651  */
    break;

  case 9:
#line 227 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("concatenar",(yyvsp[-5].TEXT), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
                  (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2322 "parser.cpp" /* yacc.c:1651  */
    break;

  case 10:
#line 234 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("concatenar",(yyvsp[-7].TEXT), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
                  (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 2333 "parser.cpp" /* yacc.c:1651  */
    break;

  case 11:
#line 243 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("importar",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                nodo *ruta = new nodo("path",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column);
                (yyval.nodito)->hijos.append(*ruta);
              }
#line 2343 "parser.cpp" /* yacc.c:1651  */
    break;

  case 12:
#line 253 "sintactico.yy" /* yacc.c:1651  */
    {
                 (yyval.nodito)=(yyvsp[-1].nodito);
                 (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 2352 "parser.cpp" /* yacc.c:1651  */
    break;

  case 13:
#line 258 "sintactico.yy" /* yacc.c:1651  */
    {
                 (yyval.nodito) = new nodo("instrucciones","instrucciones",(yylsp[0]).first_line,(yylsp[0]).first_column);
                 (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 2361 "parser.cpp" /* yacc.c:1651  */
    break;

  case 14:
#line 265 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2367 "parser.cpp" /* yacc.c:1651  */
    break;

  case 15:
#line 267 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)=(yyvsp[0].nodito);
            nodo *sobre = new nodo("sobrescribir","sobrescribir",(yylsp[-1]).first_line,(yylsp[-1]).first_column);
            (yyval.nodito)->hijos.prepend(*sobre);
       }
#line 2377 "parser.cpp" /* yacc.c:1651  */
    break;

  case 16:
#line 272 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2383 "parser.cpp" /* yacc.c:1651  */
    break;

  case 17:
#line 273 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= (yyvsp[0].nodito);}
#line 2389 "parser.cpp" /* yacc.c:1651  */
    break;

  case 18:
#line 274 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2395 "parser.cpp" /* yacc.c:1651  */
    break;

  case 19:
#line 276 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *sobre = new nodo("sobrescribir","sobrescribir",(yylsp[-1]).first_line,(yylsp[-1]).first_column);
             (yyval.nodito)->hijos.prepend(*sobre);
        }
#line 2405 "parser.cpp" /* yacc.c:1651  */
    break;

  case 20:
#line 284 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2411 "parser.cpp" /* yacc.c:1651  */
    break;

  case 21:
#line 285 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nuevo = new nodo("sentencias","sentencias",(yylsp[0]).first_line, (yylsp[0]).first_column); nuevo->add(*(yyvsp[0].nodito)); (yyval.nodito) = nuevo;}
#line 2417 "parser.cpp" /* yacc.c:1651  */
    break;

  case 22:
#line 288 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2423 "parser.cpp" /* yacc.c:1651  */
    break;

  case 23:
#line 289 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2429 "parser.cpp" /* yacc.c:1651  */
    break;

  case 24:
#line 290 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2435 "parser.cpp" /* yacc.c:1651  */
    break;

  case 25:
#line 291 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2441 "parser.cpp" /* yacc.c:1651  */
    break;

  case 26:
#line 292 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2447 "parser.cpp" /* yacc.c:1651  */
    break;

  case 27:
#line 293 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2453 "parser.cpp" /* yacc.c:1651  */
    break;

  case 28:
#line 295 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2459 "parser.cpp" /* yacc.c:1651  */
    break;

  case 29:
#line 296 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2465 "parser.cpp" /* yacc.c:1651  */
    break;

  case 30:
#line 297 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2471 "parser.cpp" /* yacc.c:1651  */
    break;

  case 31:
#line 298 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2477 "parser.cpp" /* yacc.c:1651  */
    break;

  case 32:
#line 299 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2483 "parser.cpp" /* yacc.c:1651  */
    break;

  case 33:
#line 300 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2489 "parser.cpp" /* yacc.c:1651  */
    break;

  case 34:
#line 301 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2495 "parser.cpp" /* yacc.c:1651  */
    break;

  case 35:
#line 302 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("detener","detener",(yylsp[-1]).first_line,(yylsp[-1]).first_column);}
#line 2501 "parser.cpp" /* yacc.c:1651  */
    break;

  case 36:
#line 303 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("continuar","continuar",(yylsp[-1]).first_line,(yylsp[-1]).first_column);}
#line 2507 "parser.cpp" /* yacc.c:1651  */
    break;

  case 37:
#line 304 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2513 "parser.cpp" /* yacc.c:1651  */
    break;

  case 38:
#line 305 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("mostraredd",(yyvsp[-2].TEXT),(yylsp[-4]).first_line,(yylsp[-4]).first_column);}
#line 2519 "parser.cpp" /* yacc.c:1651  */
    break;

  case 39:
#line 306 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito)=(yyvsp[-1].nodito);}
#line 2525 "parser.cpp" /* yacc.c:1651  */
    break;

  case 40:
#line 311 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= new nodo("leer","leer",(yylsp[-5]).first_line,(yylsp[-5]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2535 "parser.cpp" /* yacc.c:1651  */
    break;

  case 41:
#line 320 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",(yylsp[-10]).first_line,(yylsp[-10]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2547 "parser.cpp" /* yacc.c:1651  */
    break;

  case 42:
#line 328 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",(yylsp[-10]).first_line,(yylsp[-10]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2559 "parser.cpp" /* yacc.c:1651  */
    break;

  case 43:
#line 336 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",(yylsp[-10]).first_line,(yylsp[-10]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // decremento / aumento
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2571 "parser.cpp" /* yacc.c:1651  */
    break;

  case 44:
#line 344 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",(yylsp[-10]).first_line,(yylsp[-10]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2583 "parser.cpp" /* yacc.c:1651  */
    break;

  case 45:
#line 356 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("hacer","hacer",(yylsp[-7]).first_line,(yylsp[-7]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));// sentencias
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));// condicion;
        }
#line 2593 "parser.cpp" /* yacc.c:1651  */
    break;

  case 46:
#line 366 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito) = new nodo("mientras","mientras",(yylsp[-6]).first_line,(yylsp[-6]).first_column);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2603 "parser.cpp" /* yacc.c:1651  */
    break;

  case 47:
#line 375 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("si","si",(yylsp[-6]).first_line,(yylsp[-6]).first_column);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));// condicion
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
         }
#line 2613 "parser.cpp" /* yacc.c:1651  */
    break;

  case 48:
#line 381 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             (yyval.nodito)->tipo = "si";
             (yyval.nodito)->valor = "si";
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito)); // Sentencias
             (yyval.nodito)->hijos.prepend(*(yyvsp[-5].nodito));// condicion
         }
#line 2625 "parser.cpp" /* yacc.c:1651  */
    break;

  case 49:
#line 393 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
          }
#line 2634 "parser.cpp" /* yacc.c:1651  */
    break;

  case 50:
#line 398 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 2642 "parser.cpp" /* yacc.c:1651  */
    break;

  case 51:
#line 402 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= (yyvsp[-1].nodito);
         }
#line 2650 "parser.cpp" /* yacc.c:1651  */
    break;

  case 52:
#line 408 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)=(yyvsp[-7].nodito);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2660 "parser.cpp" /* yacc.c:1651  */
    break;

  case 53:
#line 414 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("sinosi","sinosi",(yylsp[-6]).first_line,(yylsp[-6]).first_column);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2670 "parser.cpp" /* yacc.c:1651  */
    break;

  case 54:
#line 423 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("selecciona",(yyvsp[-6].TEXT),(yylsp[-6]).first_line,(yylsp[-6]).first_column);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2680 "parser.cpp" /* yacc.c:1651  */
    break;

  case 55:
#line 430 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-5].nodito);
        nodo *def = new nodo("defecto","defecto",(yylsp[-4]).first_line,(yylsp[-4]).first_column);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2691 "parser.cpp" /* yacc.c:1651  */
    break;

  case 56:
#line 437 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)= new nodo("casos","casos",(yylsp[-4]).first_line,(yylsp[-4]).first_column);
        nodo *def = new nodo("caso","defecto",(yylsp[-4]).first_line,(yylsp[-4]).first_column);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2702 "parser.cpp" /* yacc.c:1651  */
    break;

  case 57:
#line 447 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2711 "parser.cpp" /* yacc.c:1651  */
    break;

  case 58:
#line 452 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("casos","casos",(yylsp[0]).first_line,(yylsp[0]).first_column);
           (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2720 "parser.cpp" /* yacc.c:1651  */
    break;

  case 59:
#line 458 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("caso","caso",(yylsp[-5]).first_line,(yylsp[-5]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2730 "parser.cpp" /* yacc.c:1651  */
    break;

  case 60:
#line 466 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=new nodo("retorno","retorno",(yylsp[-1]).first_line,(yylsp[-1]).first_column);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 2739 "parser.cpp" /* yacc.c:1651  */
    break;

  case 61:
#line 473 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
                (yyval.nodito)->tipo = "declatrib";
            }
#line 2749 "parser.cpp" /* yacc.c:1651  */
    break;

  case 62:
#line 479 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                nodo *nod = new nodo("publico","publico",(yylsp[-1]).first_line, (yylsp[-1]).first_column);
                (yyval.nodito)->hijos.prepend(*nod);
                (yyval.nodito)->tipo = "declatrib";
            }
#line 2760 "parser.cpp" /* yacc.c:1651  */
    break;

  case 63:
#line 486 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
             (yyval.nodito)->tipo = "declatrib";
            }
#line 2770 "parser.cpp" /* yacc.c:1651  */
    break;

  case 64:
#line 492 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito) = (yyvsp[-1].nodito);
         nodo *nod = new nodo("publico","publico",(yylsp[-1]).first_line, (yylsp[-1]).first_column);
         (yyval.nodito)->hijos.prepend(*nod);
         (yyval.nodito)->tipo = "declatrib";
        }
#line 2781 "parser.cpp" /* yacc.c:1651  */
    break;

  case 65:
#line 502 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("publico",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 2787 "parser.cpp" /* yacc.c:1651  */
    break;

  case 66:
#line 503 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("privado",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 2793 "parser.cpp" /* yacc.c:1651  */
    break;

  case 67:
#line 504 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("protegido",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 2799 "parser.cpp" /* yacc.c:1651  */
    break;

  case 68:
#line 507 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *cons = new nodo("constructor",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                 cons->hijos.append(*(yyvsp[-1].nodito)); // LISTA DE PARAMETROS
                 (yyval.nodito) = cons;
            }
#line 2809 "parser.cpp" /* yacc.c:1651  */
    break;

  case 69:
#line 513 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *cons = new nodo("constructor",(yyvsp[-2].TEXT),(yylsp[-2]).first_line,(yylsp[-2]).first_column);
                 nodo *lpar = new nodo("lpar","lpar",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                 cons->hijos.append(*lpar); // LISTA DE PARAMETROS
                 (yyval.nodito) = cons;
            }
#line 2820 "parser.cpp" /* yacc.c:1651  */
    break;

  case 70:
#line 521 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2826 "parser.cpp" /* yacc.c:1651  */
    break;

  case 71:
#line 523 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",0,0);
            }
#line 2834 "parser.cpp" /* yacc.c:1651  */
    break;

  case 72:
#line 530 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=(yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2843 "parser.cpp" /* yacc.c:1651  */
    break;

  case 73:
#line 535 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",(yylsp[0]).first_line, (yylsp[0]).first_column);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2852 "parser.cpp" /* yacc.c:1651  */
    break;

  case 74:
#line 542 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-1].nodito)->tipo = (yyvsp[-1].nodito)->valor;
                (yyvsp[-1].nodito)->valor = (yyvsp[0].TEXT);
                (yyval.nodito) = (yyvsp[-1].nodito);
            }
#line 2862 "parser.cpp" /* yacc.c:1651  */
    break;

  case 75:
#line 548 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-2].nodito)->tipo = (yyvsp[-2].nodito)->valor;
                (yyvsp[-2].nodito)->valor = (yyvsp[-1].TEXT);
                (yyval.nodito) = (yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2873 "parser.cpp" /* yacc.c:1651  */
    break;

  case 76:
#line 557 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("principal",(yyvsp[-5].TEXT), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
           }
#line 2882 "parser.cpp" /* yacc.c:1651  */
    break;

  case 77:
#line 564 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("constructor",(yyvsp[-6].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
                    (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // visibilidad
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2893 "parser.cpp" /* yacc.c:1651  */
    break;

  case 78:
#line 571 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("constructor",(yyvsp[-6].TEXT),(yylsp[-6]).first_line,(yylsp[-6]).first_column);
                    nodo *vis = new nodo("visibilidad","publico",(yylsp[-6]).first_line,(yylsp[-6]).first_column);
                    (yyval.nodito)->hijos.append(*vis); // visibilidad
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));  // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2905 "parser.cpp" /* yacc.c:1651  */
    break;

  case 79:
#line 581 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),(yylsp[-9]).first_line,(yylsp[-9]).first_column);
                (yyval.nodito)->hijos.append(*(yyvsp[-9].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // dimensiones del retorno
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2918 "parser.cpp" /* yacc.c:1651  */
    break;

  case 80:
#line 590 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),(yylsp[-8]).first_line,(yylsp[-8]).first_column);
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2930 "parser.cpp" /* yacc.c:1651  */
    break;

  case 81:
#line 598 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),(yylsp[-8]).first_line,(yylsp[-8]).first_column);
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // visibilidad
                nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
                (yyval.nodito)->hijos.append(*tipo); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2943 "parser.cpp" /* yacc.c:1651  */
    break;

  case 82:
#line 607 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),(yylsp[-8]).first_line,(yylsp[-8]).first_column);
                nodo *vis = new nodo("publico","publico",(yylsp[-8]).first_line, (yylsp[-8]).first_column);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // dimensiones del retorno
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2957 "parser.cpp" /* yacc.c:1651  */
    break;

  case 83:
#line 617 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
                nodo *vis = new nodo("publico","publico",(yylsp[-7]).first_line, (yylsp[-7]).first_column);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2970 "parser.cpp" /* yacc.c:1651  */
    break;

  case 84:
#line 626 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
                nodo *vis = new nodo("publico","publico",(yylsp[-7]).first_line, (yylsp[-7]).first_column);
                (yyval.nodito)->hijos.append(*vis); // visibilidad
                nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
                (yyval.nodito)->hijos.append(*tipo); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros.
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2984 "parser.cpp" /* yacc.c:1651  */
    break;

  case 85:
#line 638 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 2993 "parser.cpp" /* yacc.c:1651  */
    break;

  case 86:
#line 642 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= new nodo("dims","dims",(yylsp[0]).first_line, (yylsp[0]).first_column);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
          }
#line 3002 "parser.cpp" /* yacc.c:1651  */
    break;

  case 87:
#line 647 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("dim","dim",(yylsp[-1]).first_line,(yylsp[-1]).first_column);}
#line 3008 "parser.cpp" /* yacc.c:1651  */
    break;

  case 88:
#line 655 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),(yylsp[-5]).first_line, (yylsp[-5]).first_column);
                  (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3018 "parser.cpp" /* yacc.c:1651  */
    break;

  case 89:
#line 661 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),(yylsp[-4]).first_line, (yylsp[-4]).first_column);
                  nodo *nod = new nodo("visibilidad","publico",(yylsp[-4]).first_line, (yylsp[-4]).first_column);
                  (yyval.nodito)->hijos.append(*nod);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3029 "parser.cpp" /* yacc.c:1651  */
    break;

  case 90:
#line 669 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),(yylsp[-7]).first_line, (yylsp[-7]).first_column);
                  (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito));
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3041 "parser.cpp" /* yacc.c:1651  */
    break;

  case 91:
#line 677 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),(yylsp[-6]).first_line, (yylsp[-6]).first_column);
                  nodo *nod = new nodo("publico","publico",(yylsp[-6]).first_line, (yylsp[-6]).first_column);
                  (yyval.nodito)->hijos.append(*nod);
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3054 "parser.cpp" /* yacc.c:1651  */
    break;

  case 92:
#line 691 "sintactico.yy" /* yacc.c:1651  */
    {
                            (yyval.nodito)=(yyvsp[-1].nodito);
                            nodo *idnodo = new nodo("variable",(yyvsp[-2].TEXT),(yylsp[-2]).first_line, (yylsp[-2]).first_column);
                            (yyval.nodito)->add(*idnodo);
                            (yyval.nodito)->add(*(yyvsp[0].nodito));
                           }
#line 3065 "parser.cpp" /* yacc.c:1651  */
    break;

  case 93:
#line 698 "sintactico.yy" /* yacc.c:1651  */
    {
                            (yyval.nodito)=(yyvsp[-1].nodito);
                            (yyval.nodito)->tipo= "asiga";
                            (yyval.nodito)->add(*(yyvsp[-2].nodito));
                            nodo *idnodo = new nodo("variable",(yyvsp[-3].TEXT),(yylsp[-3]).first_line, (yylsp[-3]).first_column);
                            (yyval.nodito)->add(*idnodo);
                            (yyval.nodito)->add(*(yyvsp[0].nodito));
                           }
#line 3078 "parser.cpp" /* yacc.c:1651  */
    break;

  case 94:
#line 707 "sintactico.yy" /* yacc.c:1651  */
    {
                          (yyval.nodito)=(yyvsp[-1].nodito);
                          nodo *nod = new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line, (yylsp[-3]).first_column);
                          (yyvsp[-2].nodito)->hijos.prepend(*nod);
                          (yyval.nodito)->hijos.append(*(yyvsp[-2].nodito));
                          (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
                          }
#line 3090 "parser.cpp" /* yacc.c:1651  */
    break;

  case 95:
#line 715 "sintactico.yy" /* yacc.c:1651  */
    {
                          (yyval.nodito)=(yyvsp[-1].nodito);
                          nodo *nod = new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line, (yylsp[-3]).first_column);
                          (yyvsp[-2].nodito)->hijos.prepend(*nod);
                          (yyval.nodito)->hijos.append(*(yyvsp[-2].nodito));
                          (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
                          }
#line 3102 "parser.cpp" /* yacc.c:1651  */
    break;

  case 96:
#line 723 "sintactico.yy" /* yacc.c:1651  */
    {
                           (yyval.nodito)=(yyvsp[-1].nodito);
                           nodo *nod = new nodo("id",(yyvsp[-4].TEXT),(yylsp[-4]).first_line, (yylsp[-4]).first_column);
                           nod->hijos.append(*(yyvsp[-3].nodito));
                           (yyval.nodito)->hijos.prepend(*nod);
                           (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
                           }
#line 3114 "parser.cpp" /* yacc.c:1651  */
    break;

  case 97:
#line 733 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3120 "parser.cpp" /* yacc.c:1651  */
    break;

  case 98:
#line 734 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3126 "parser.cpp" /* yacc.c:1651  */
    break;

  case 99:
#line 735 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3132 "parser.cpp" /* yacc.c:1651  */
    break;

  case 100:
#line 736 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3138 "parser.cpp" /* yacc.c:1651  */
    break;

  case 101:
#line 737 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3144 "parser.cpp" /* yacc.c:1651  */
    break;

  case 102:
#line 743 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("d",(yyvsp[0].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
            nuevo->add(*(yyvsp[-1].nodito)); // tipo
            (yyval.nodito) = nuevo;
         }
#line 3154 "parser.cpp" /* yacc.c:1651  */
    break;

  case 103:
#line 749 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("da",(yyvsp[-2].TEXT),(yylsp[-3]).first_line, (yylsp[-3]).first_column);
             nuevo->add(*(yyvsp[-3].nodito)); // tipo
             nuevo->add(*(yyvsp[0].nodito)); // valor
             (yyval.nodito) = nuevo;
         }
#line 3165 "parser.cpp" /* yacc.c:1651  */
    break;

  case 104:
#line 759 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3176 "parser.cpp" /* yacc.c:1651  */
    break;

  case 105:
#line 766 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3187 "parser.cpp" /* yacc.c:1651  */
    break;

  case 106:
#line 773 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),(yylsp[-7]).first_line,(yylsp[-7]).first_column);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3198 "parser.cpp" /* yacc.c:1651  */
    break;

  case 107:
#line 787 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("dar","dar",(yylsp[-2]).first_line, (yylsp[-2]).first_column);
            nuevo->add(*(yyvsp[-2].nodito));
            nodo *nodoid =  new nodo("id",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column);
            nuevo->add(*nodoid);
            (yyval.nodito) = nuevo;
         }
#line 3210 "parser.cpp" /* yacc.c:1651  */
    break;

  case 108:
#line 794 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("dara","dara",(yylsp[-4]).first_line, (yylsp[-4]).first_column);
             nuevo->add(*(yyvsp[-4].nodito));
             nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
             nuevo->add(*nodoid);
             nuevo->add(*(yyvsp[-2].nodito));
             nuevo->add(*(yyvsp[0].nodito));
             (yyval.nodito) = nuevo;}
#line 3223 "parser.cpp" /* yacc.c:1651  */
    break;

  case 109:
#line 802 "sintactico.yy" /* yacc.c:1651  */
    {
              nodo *nuevo = new nodo("darar","darar",(yylsp[-4]).first_line, (yylsp[-4]).first_column);
              nuevo->add(*(yyvsp[-4].nodito));
              nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
              nuevo->add(*nodoid);
              nuevo->add(*(yyvsp[-2].nodito));
              nuevo->add(*(yyvsp[0].nodito));
              (yyval.nodito) = nuevo;}
#line 3236 "parser.cpp" /* yacc.c:1651  */
    break;

  case 110:
#line 813 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)->add(*(yyvsp[-1].nodito));}
#line 3242 "parser.cpp" /* yacc.c:1651  */
    break;

  case 111:
#line 815 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)= new nodo("dim","dim",(yylsp[-2]).first_line, (yylsp[-2]).first_column);
                (yyval.nodito)->add(*(yyvsp[-1].nodito));
            }
#line 3251 "parser.cpp" /* yacc.c:1651  */
    break;

  case 112:
#line 823 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = (yyvsp[-1].nodito);
         }
#line 3259 "parser.cpp" /* yacc.c:1651  */
    break;

  case 113:
#line 829 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             for (int i= 0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod = (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3272 "parser.cpp" /* yacc.c:1651  */
    break;

  case 114:
#line 838 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lvalores","lvalores",(yylsp[-2]).first_line, (yylsp[-1]).first_column);
             for (int i =0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod =  (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3285 "parser.cpp" /* yacc.c:1651  */
    break;

  case 115:
#line 848 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-2].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3291 "parser.cpp" /* yacc.c:1651  */
    break;

  case 116:
#line 849 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("valores","valores",(yylsp[0]).first_line,(yylsp[0]).first_column); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3297 "parser.cpp" /* yacc.c:1651  */
    break;

  case 117:
#line 854 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3303 "parser.cpp" /* yacc.c:1651  */
    break;

  case 118:
#line 855 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3309 "parser.cpp" /* yacc.c:1651  */
    break;

  case 119:
#line 856 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3315 "parser.cpp" /* yacc.c:1651  */
    break;

  case 120:
#line 859 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipoboleano",(yyvsp[0].TEXT),(yylsp[0]).first_line,(yylsp[0]).first_column);}
#line 3321 "parser.cpp" /* yacc.c:1651  */
    break;

  case 121:
#line 860 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipoentero",(yyvsp[0].TEXT),(yylsp[0]).first_line,(yylsp[0]).first_column);}
#line 3327 "parser.cpp" /* yacc.c:1651  */
    break;

  case 122:
#line 861 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipocaracter",(yyvsp[0].TEXT),(yylsp[0]).first_line,(yylsp[0]).first_column);}
#line 3333 "parser.cpp" /* yacc.c:1651  */
    break;

  case 123:
#line 862 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipodecimal",(yyvsp[0].TEXT),(yylsp[0]).first_line,(yylsp[0]).first_column);}
#line 3339 "parser.cpp" /* yacc.c:1651  */
    break;

  case 124:
#line 863 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("tipoobjeto",(yyvsp[0].TEXT),(yylsp[0]).first_line,(yylsp[0]).first_column);}
#line 3345 "parser.cpp" /* yacc.c:1651  */
    break;

  case 125:
#line 870 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("ss","ss",(yylsp[-4]).first_line, (yylsp[-4]).first_column);
             (yyval.nodito)->add(*(yyvsp[-4].nodito)); // Condicion
             (yyval.nodito)->add(*(yyvsp[-2].nodito)); // Valor verdadero
             (yyval.nodito)->add(*(yyvsp[0].nodito)); // Valor falso;
         }
#line 3356 "parser.cpp" /* yacc.c:1651  */
    break;

  case 126:
#line 878 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expl",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3362 "parser.cpp" /* yacc.c:1651  */
    break;

  case 127:
#line 879 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expl",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3368 "parser.cpp" /* yacc.c:1651  */
    break;

  case 128:
#line 880 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expl",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3374 "parser.cpp" /* yacc.c:1651  */
    break;

  case 129:
#line 881 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3380 "parser.cpp" /* yacc.c:1651  */
    break;

  case 130:
#line 884 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3386 "parser.cpp" /* yacc.c:1651  */
    break;

  case 131:
#line 885 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3392 "parser.cpp" /* yacc.c:1651  */
    break;

  case 132:
#line 886 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3398 "parser.cpp" /* yacc.c:1651  */
    break;

  case 133:
#line 887 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3404 "parser.cpp" /* yacc.c:1651  */
    break;

  case 134:
#line 888 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3410 "parser.cpp" /* yacc.c:1651  */
    break;

  case 135:
#line 889 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("expr",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3416 "parser.cpp" /* yacc.c:1651  */
    break;

  case 136:
#line 890 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3422 "parser.cpp" /* yacc.c:1651  */
    break;

  case 137:
#line 892 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3428 "parser.cpp" /* yacc.c:1651  */
    break;

  case 138:
#line 893 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3434 "parser.cpp" /* yacc.c:1651  */
    break;

  case 139:
#line 894 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3440 "parser.cpp" /* yacc.c:1651  */
    break;

  case 140:
#line 895 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3446 "parser.cpp" /* yacc.c:1651  */
    break;

  case 141:
#line 896 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nod = new nodo("expa",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column); nod->add(*(yyvsp[-2].nodito));  nod->add(*(yyvsp[0].nodito));  (yyval.nodito)=nod ;  }
#line 3452 "parser.cpp" /* yacc.c:1651  */
    break;

  case 142:
#line 897 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("expa",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3458 "parser.cpp" /* yacc.c:1651  */
    break;

  case 143:
#line 898 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("variable",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3464 "parser.cpp" /* yacc.c:1651  */
    break;

  case 144:
#line 899 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("acceso",(yyvsp[-1].TEXT),(yylsp[-1]).first_line,(yylsp[-1]).first_column); (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));}
#line 3470 "parser.cpp" /* yacc.c:1651  */
    break;

  case 145:
#line 900 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("entero",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3476 "parser.cpp" /* yacc.c:1651  */
    break;

  case 146:
#line 901 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("caracter",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3482 "parser.cpp" /* yacc.c:1651  */
    break;

  case 147:
#line 902 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("caracter",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3488 "parser.cpp" /* yacc.c:1651  */
    break;

  case 148:
#line 903 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("booleano",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3494 "parser.cpp" /* yacc.c:1651  */
    break;

  case 149:
#line 904 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("cadena",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3500 "parser.cpp" /* yacc.c:1651  */
    break;

  case 150:
#line 905 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("nada",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);}
#line 3506 "parser.cpp" /* yacc.c:1651  */
    break;

  case 151:
#line 906 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[0].nodito);}
#line 3512 "parser.cpp" /* yacc.c:1651  */
    break;

  case 152:
#line 907 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 3518 "parser.cpp" /* yacc.c:1651  */
    break;

  case 153:
#line 908 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito)=(yyvsp[0].nodito);
                    nodo *nod = new nodo("id",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
                    (yyval.nodito)->hijos.prepend(*nod);
                    }
#line 3528 "parser.cpp" /* yacc.c:1651  */
    break;

  case 154:
#line 913 "sintactico.yy" /* yacc.c:1651  */
    {
                     (yyval.nodito)=(yyvsp[-1].nodito);
                     nodo *nod = new nodo("id",(yyvsp[-2].TEXT),(yylsp[-2]).first_line, (yylsp[-2]).first_column);
                     (yyval.nodito)->hijos.prepend(*nod);
                     }
#line 3538 "parser.cpp" /* yacc.c:1651  */
    break;

  case 155:
#line 919 "sintactico.yy" /* yacc.c:1651  */
    {
                     (yyval.nodito)=(yyvsp[0].nodito);
                     nodo *nod = new nodo("id",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
                     (yyval.nodito)->hijos.prepend(*nod);
                     }
#line 3548 "parser.cpp" /* yacc.c:1651  */
    break;

  case 156:
#line 925 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertacadena","convertacadena",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3557 "parser.cpp" /* yacc.c:1651  */
    break;

  case 157:
#line 930 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertaentero","convertaentero",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3566 "parser.cpp" /* yacc.c:1651  */
    break;

  case 158:
#line 935 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 3574 "parser.cpp" /* yacc.c:1651  */
    break;

  case 159:
#line 944 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-2].nodito);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3583 "parser.cpp" /* yacc.c:1651  */
    break;

  case 160:
#line 949 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito) = new nodo("lpar","lpar",(yylsp[0]).first_line,(yylsp[0]).first_column);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3592 "parser.cpp" /* yacc.c:1651  */
    break;

  case 161:
#line 957 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("llamada",(yyvsp[-2].TEXT),(yylsp[-2]).first_line,(yylsp[-2]).first_column);
             /*nodo *params = new nodo("lpar","lpar",@2.first_line,@2.first_column);
             $$->hijos.append(*params);*/
         }
#line 3602 "parser.cpp" /* yacc.c:1651  */
    break;

  case 162:
#line 963 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("llamada",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
             for(int i= 0; i<(yyvsp[-1].nodito)->hijos.count(); i++)
             {
                (yyval.nodito)->hijos.append((yyvsp[-1].nodito)->hijos[i]);
             }
         }
#line 3614 "parser.cpp" /* yacc.c:1651  */
    break;

  case 163:
#line 971 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = (yyvsp[-3].nodito);
          (yyval.nodito)->tipo = "llamada";
          nodo *id = new nodo("id",(yyvsp[-4].TEXT),(yylsp[-4]).first_line,(yylsp[-4]).first_column);
          (yyval.nodito)->hijos.prepend(*id);
          for(int i=0; i<(yyvsp[-1].nodito)->hijos.count();i++)
          {
              (yyval.nodito)->hijos.append((yyvsp[-1].nodito)->hijos[i]);
          }
        }
#line 3629 "parser.cpp" /* yacc.c:1651  */
    break;

  case 164:
#line 982 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito) = (yyvsp[-2].nodito);
           (yyval.nodito)->tipo = "llamada";
           nodo *id = new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
           (yyval.nodito)->hijos.prepend(*id);
         }
#line 3640 "parser.cpp" /* yacc.c:1651  */
    break;

  case 165:
#line 992 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("aumento","++",(yylsp[0]).first_line, (yylsp[0]).first_column); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3646 "parser.cpp" /* yacc.c:1651  */
    break;

  case 166:
#line 993 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("decremento","--",(yylsp[0]).first_line, (yylsp[0]).first_column); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3652 "parser.cpp" /* yacc.c:1651  */
    break;

  case 167:
#line 997 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-2].nodito);
             nodo *nod= new nodo("id",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3662 "parser.cpp" /* yacc.c:1651  */
    break;

  case 168:
#line 1003 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = (yyvsp[-3].nodito);
            nodo *nod= new nodo("idv",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
            nod->hijos.append(*(yyvsp[0].nodito));
            (yyval.nodito)->hijos.append(*nod);
         }
#line 3673 "parser.cpp" /* yacc.c:1651  */
    break;

  case 169:
#line 1010 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",(yylsp[-1]).first_line, (yylsp[-1]).first_column);
             nodo *nod= new nodo("id",(yyvsp[0].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3683 "parser.cpp" /* yacc.c:1651  */
    break;

  case 170:
#line 1016 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",(yylsp[-2]).first_line, (yylsp[-2]).first_column);
             nodo *nod= new nodo("idv",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
             nod->hijos.append(*(yyvsp[0].nodito));
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3694 "parser.cpp" /* yacc.c:1651  */
    break;

  case 171:
#line 1023 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito)=(yyvsp[0].nodito);}
#line 3700 "parser.cpp" /* yacc.c:1651  */
    break;

  case 172:
#line 1025 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-2].nodito);
             nodo *nod= new nodo("id",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3710 "parser.cpp" /* yacc.c:1651  */
    break;

  case 173:
#line 1033 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = (yyvsp[-2].nodito);
          nodo *nod= new nodo("id",(yyvsp[0].TEXT),(yylsp[0]).first_line, (yylsp[0]).first_column);
          (yyval.nodito)->hijos.append(*nod);
      }
#line 3720 "parser.cpp" /* yacc.c:1651  */
    break;

  case 174:
#line 1039 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito) = (yyvsp[-4].nodito);
        nodo *nod= new nodo("funcion",(yyvsp[-2].TEXT),(yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.nodito)->hijos.append(*nod);
    }
#line 3730 "parser.cpp" /* yacc.c:1651  */
    break;

  case 175:
#line 1045 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito) = (yyvsp[-5].nodito);
        nodo *nod= new nodo("funcion",(yyvsp[-3].TEXT),(yylsp[-3]).first_line, (yylsp[-3]).first_column);
        nod->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*nod);
    }
#line 3741 "parser.cpp" /* yacc.c:1651  */
    break;

  case 176:
#line 1052 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito) = (yyvsp[-3].nodito);
         nodo *nod= new nodo("idv",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
         nod->hijos.append(*(yyvsp[0].nodito));
         (yyval.nodito)->hijos.append(*nod);
      }
#line 3752 "parser.cpp" /* yacc.c:1651  */
    break;

  case 177:
#line 1059 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("acceso","acceso",(yylsp[-1]).first_line, (yylsp[-1]).first_column);
          nodo *nod= new nodo("id",(yyvsp[0].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
          (yyval.nodito)->hijos.append(*nod);
      }
#line 3762 "parser.cpp" /* yacc.c:1651  */
    break;

  case 178:
#line 1065 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito) = new nodo("acceso","acceso",(yylsp[-3]).first_line, (yylsp[-3]).first_column);
         nodo *nod= new nodo("funcion",(yyvsp[-2].TEXT),(yylsp[-3]).first_line, (yylsp[-3]).first_column);
         (yyval.nodito)->hijos.append(*nod);
     }
#line 3772 "parser.cpp" /* yacc.c:1651  */
    break;

  case 179:
#line 1071 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito) = new nodo("acceso","acceso",(yylsp[-4]).first_line, (yylsp[-4]).first_column);
         nodo *nod= new nodo("funcion",(yyvsp[-3].TEXT),(yylsp[-4]).first_line, (yylsp[-4]).first_column);
         nod->hijos.append(*(yyvsp[-1].nodito));
         (yyval.nodito)->hijos.append(*nod);
     }
#line 3783 "parser.cpp" /* yacc.c:1651  */
    break;

  case 180:
#line 1078 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("acceso","acceso",(yylsp[-2]).first_line, (yylsp[-2]).first_column);
          nodo *nod= new nodo("idv",(yyvsp[-1].TEXT),(yylsp[-1]).first_line, (yylsp[-1]).first_column);
          nod->hijos.append(*(yyvsp[0].nodito));
          (yyval.nodito)->hijos.append(*nod);
      }
#line 3794 "parser.cpp" /* yacc.c:1651  */
    break;


#line 3798 "parser.cpp" /* yacc.c:1651  */
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
#line 1084 "sintactico.yy" /* yacc.c:1910  */

