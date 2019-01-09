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
#define YYLAST   3141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  491

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
     239,   248,   259,   264,   272,   278,   284,   285,   286,   287,
     296,   297,   300,   301,   302,   303,   304,   305,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     322,   331,   339,   347,   355,   366,   377,   386,   392,   403,
     409,   413,   419,   425,   434,   441,   448,   458,   463,   469,
     477,   484,   491,   499,   506,   518,   519,   520,   522,   528,
     537,   539,   545,   550,   557,   563,   572,   588,   605,   612,
     622,   631,   641,   652,   664,   675,   689,   694,   699,   706,
     714,   724,   732,   746,   755,   765,   786,   811,   823,   824,
     825,   826,   827,   832,   840,   852,   859,   866,   880,   889,
     897,   908,   909,   917,   923,   932,   943,   944,   949,   950,
     951,   954,   955,   956,   957,   958,   964,   973,   974,   975,
     976,   979,   980,   981,   982,   983,   984,   985,   987,   988,
     989,   990,   991,   992,   993,   994,  1000,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1024,  1032,  1037,  1042,
    1051,  1056,  1066,  1074,  1081,  1091,  1100,  1112,  1113,  1117,
    1125,  1135,  1144,  1154,  1162,  1172,  1181
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

#define YYPACT_NINF -276

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-276)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     495,    -1,  -276,  -276,  -276,    22,    80,   495,  -276,    15,
      61,  -276,    -3,   107,  -276,  -276,  -276,   115,  1145,   144,
     153,     6,   162,  -276,  -276,  -276,  -276,   175,   653,   168,
     630,  -276,  -276,   290,  -276,  -276,  -276,   106,   118,     8,
     199,  -276,  1145,   212,   225,   204,   301,  -276,  -276,   143,
     219,  -276,  -276,   226,   230,   238,   192,   202,   151,  -276,
    -276,    14,   297,   209,  -276,  1145,   910,   288,  -276,   304,
     310,  -276,   309,   225,   218,   327,   335,   225,   342,   344,
    -276,  -276,   145,   245,   225,   837,   276,    24,  -276,   353,
    -276,   982,  -276,  1145,   355,   225,   361,   366,   378,  2996,
     386,   225,   394,   225,   398,   407,  -276,  -276,  -276,  -276,
    -276,     9,   837,   489,   837,   410,   414,   339,  -276,   261,
    -276,   497,  -276,  -276,   420,  -276,  -276,  -276,   314,   837,
     616,   225,  -276,  1062,  2996,  -276,   419,   426,   165,   431,
     439,   339,   837,   364,   380,   459,   461,   469,   444,   473,
     491,   493,   496,   494,   498,   424,   425,  1004,  -276,   433,
    -276,   445,  -276,  -276,  -276,   450,   453,   456,   457,   458,
     504,    16,   112,   464,   521,   525,  2996,   544,   225,   551,
     776,   556,    -9,   418,   205,    82,  -276,   837,   837,   418,
    -276,   837,   837,  -276,  -276,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   558,   837,   273,
     562,  -276,   160,   564,  -276,  1087,  2996,  -276,  -276,  -276,
    -276,  -276,   276,   241,   405,   837,   169,   160,  -276,  -276,
     837,   837,   837,  2996,   102,   539,   541,   542,   571,   837,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,    66,  -276,   276,  -276,  2996,   569,  1170,   570,   572,
    2996,   339,   160,     3,   152,   418,   580,  -276,   215,   235,
     555,  -276,    82,    82,    99,    99,   119,    16,    16,    16,
      16,    16,    16,    99,   785,   324,  -276,   837,   239,   582,
    -276,  1253,  -276,   276,   169,   584,   258,   446,   276,   300,
     351,   369,  1336,   187,   339,   511,   512,   603,   466,   552,
     553,   554,   606,   449,  -276,  1419,  2996,  -276,  2996,   619,
    1502,   418,   339,   837,   906,   419,   281,  -276,  -276,  -276,
      54,   837,   285,   160,  -276,   620,  2996,  -276,  -276,   276,
    -276,  -276,   837,  -276,   621,   622,   626,   546,   241,   169,
     837,   837,   605,   565,   566,   567,   560,   837,  -276,  1585,
    1668,  2996,  -276,   418,   160,  -276,    74,  3079,   419,  -276,
     160,  -276,   837,   837,  1751,  -276,   208,  2996,   236,  2996,
     640,   169,    17,    52,   641,   642,   643,  -276,   387,  -276,
    -276,  1834,  -276,  -276,   108,   160,   307,  -276,  -276,   837,
    1917,   837,   639,   644,   320,  -276,  2000,   837,   845,   845,
     225,   225,   225,  -276,  -276,  -276,  -276,   390,   368,   437,
     647,  -276,   645,  -276,  -276,   396,   187,   649,   466,   656,
     658,   663,   666,   667,   669,  -276,   646,   670,  -276,   409,
     675,  2996,   676,  -276,   685,   687,   688,   689,  -276,  -276,
    -276,   837,  2996,   671,   690,  2996,  2083,  2996,  2996,  2996,
    2996,  2996,   423,  2166,   837,  2996,  2249,  -276,  2332,  2415,
    2498,  2581,  2664,   692,  -276,   429,  2747,  -276,  -276,  -276,
    -276,  -276,  -276,  2996,   693,  -276,  2830,  2996,  -276,  2913,
    -276
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    65,    66,    67,     0,     0,     2,     4,     0,
       0,     6,     0,     0,     1,     3,     5,     0,     0,     0,
       0,     0,   125,   121,   122,   123,   124,     0,     0,     0,
       0,    13,    16,     0,    17,    18,    14,     0,     0,     0,
       0,    11,     0,     0,    71,     0,     0,    19,    15,     0,
       0,    90,    12,   125,     0,     0,     0,     0,     0,    62,
      64,   103,     0,     0,    87,     0,     0,     0,   125,     0,
      70,    73,     0,    71,     0,     0,     0,    71,     0,     0,
      61,    63,   103,     0,    71,     0,     0,   108,    88,     0,
      86,     0,    89,     0,     0,     0,    74,     0,     0,     0,
       0,    71,     0,    71,     0,     0,   147,   149,   148,   150,
     151,   145,     0,     0,     0,     0,     0,     0,   152,     0,
     130,   137,   159,   153,     0,   120,   104,   119,   118,     0,
       0,    71,    92,     0,     0,    72,    75,     0,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      34,     0,    29,    30,    32,     0,     0,     0,     0,     0,
       0,     0,   159,   153,     0,     0,     0,     0,    71,     0,
       0,     0,   146,   166,     0,   144,   129,     0,     0,   156,
     112,     0,     0,   167,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,   109,     0,    91,     0,     0,    98,    99,   100,
     101,   102,     0,   146,     0,     0,   156,    60,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    25,    76,    20,    39,    33,    27,    24,    22,    37,
      23,   103,    28,     0,    31,     0,     0,     0,     0,     0,
       0,   162,   161,     0,   173,   155,     0,   154,     0,     0,
     128,   127,   138,   139,   140,   141,   142,   134,   133,   136,
     135,   131,   132,   143,     0,     0,   111,     0,     0,     0,
      79,     0,    93,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,    77,     0,     0,
       0,   164,   163,     0,     0,   176,   169,   157,   158,    69,
       0,     0,     0,   117,   113,     0,     0,    85,    94,     0,
       8,     7,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,     0,    78,     0,
       0,     0,    84,   165,   160,   174,     0,     0,   172,    68,
     126,   115,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,    82,
      81,     0,   175,   170,     0,   116,     0,    83,     9,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,     0,    40,    80,   171,   114,     0,    47,     0,
       0,    54,     0,    57,    46,     0,   145,     0,   159,   153,
       0,   153,     0,     0,     0,    10,     0,     0,    48,    50,
       0,     0,     0,    45,     0,     0,     0,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    59,    55,    41,
      43,    42,    44,     0,     0,    49,     0,     0,    53,     0,
      52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -276,  -276,  -276,   702,  -276,   486,  -276,    56,   -28,   -14,
     517,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,   308,  -276,  -276,   140,  -276,   -12,  -276,   623,  -276,
     683,   686,     0,   -38,  -276,  -233,  -169,     2,  -276,    64,
     -82,  -276,  -276,   343,  -217,   -18,  -276,   533,  -276,   404,
    -275,   -88,   100,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,   155,   156,     9,    30,    31,   157,
     158,   159,   160,   161,   162,   163,   438,   439,   164,   403,
     404,   405,   165,    32,    33,   125,    69,    70,    71,    34,
      35,    36,    63,    64,    11,   166,   222,   167,   168,   169,
      87,   211,   288,   332,   126,   170,   127,   128,   120,   171,
     263,   122,   123,   183
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   305,    52,   253,   129,   292,   189,    12,    18,   330,
      49,   172,    39,   322,   136,    58,    61,    42,   180,   323,
      37,    62,    85,    84,    39,    90,    72,    85,    74,   182,
     226,    13,    37,   193,   194,    56,   314,   129,    52,   195,
     196,   197,   198,   199,    37,    90,   172,    39,    39,   366,
      86,   191,   192,    19,   293,    72,   223,   298,    83,    72,
     130,    97,    43,    52,   369,   100,    72,    37,    37,   172,
     323,   265,   105,    39,    83,    39,   338,    72,   181,    85,
      14,   343,    38,    72,   392,    72,   191,   192,   172,   175,
     323,   177,   394,    37,    38,    37,   181,    57,    66,   193,
     194,    16,    86,   408,   206,    52,    38,   197,   198,   199,
     303,    17,   294,    72,    20,    39,   193,   194,   415,   213,
     215,    91,   375,    21,   323,   339,   199,   172,   172,    38,
      38,   217,   218,   219,   220,    37,   193,   194,   409,   253,
      10,    23,    24,    25,    26,   172,   308,    10,   221,   133,
     321,    75,    40,   304,   103,    38,    62,    38,    85,    82,
      72,   324,   257,    41,    62,    85,   259,   172,    46,   172,
     206,    44,   172,  -125,   180,   427,   430,    50,    85,   293,
     298,    86,   325,    45,   217,   218,   219,   220,   217,   218,
     219,   220,    59,   349,   191,   192,   180,    38,   252,   173,
      85,   221,   291,   172,    60,   221,   217,   218,   219,   220,
      65,   363,   339,    73,   172,   267,   307,    89,   398,   302,
      67,   348,    62,   221,   399,   327,    98,   172,   172,    76,
     172,    62,   172,    68,   173,    77,   306,   381,    78,   191,
     192,   315,   191,   192,   368,   328,   320,    79,   172,   191,
     192,   334,   181,   104,   129,   335,   266,   173,    62,   253,
     217,   218,   219,   220,    23,    24,    25,    26,   341,   191,
     192,   172,   172,   172,   181,   190,   173,   221,    80,   106,
     107,   108,   109,   110,   111,   112,   172,   286,    81,   172,
     367,   172,   191,   192,    85,   191,   192,   371,    53,    93,
     113,   372,   359,   172,   360,   401,   402,   191,   192,    53,
     344,    88,   172,   114,    94,   173,   173,    96,   172,   416,
     428,   428,   374,   372,   115,   116,    95,   117,   181,    23,
      24,    25,    26,   173,   191,   192,    84,   124,   118,   331,
      23,    24,    25,    26,   223,    54,    99,   391,   191,   192,
      55,   101,   208,   172,   102,   173,    54,   173,   191,   192,
     173,   345,   131,   400,   172,   406,   134,   172,   172,   172,
     172,   172,   172,   172,    85,   172,   137,   172,   172,   346,
     172,   172,   172,   172,   172,   191,   192,   103,   172,   401,
     422,   173,   432,   433,   434,   172,   174,   413,   172,   172,
     435,   172,   173,   191,   192,   176,   443,   178,   106,   107,
     108,   109,   110,   111,   112,   173,   173,   179,   173,   187,
     173,   191,   192,   188,   191,   192,   181,   456,   207,   113,
     191,   192,   129,   473,   436,   437,   173,   216,   463,   484,
     224,   466,   114,   468,   469,   470,   471,   472,   225,   140,
     228,   476,   440,   115,   116,   233,   117,   191,   192,   173,
     173,   173,   342,   191,   192,   357,   229,   118,   230,   486,
     231,   191,   192,   489,   173,   453,   454,   173,   232,   173,
     191,   192,   234,   191,   192,   217,   218,   219,   220,   121,
     121,   173,   106,   107,   108,   109,   110,   111,   112,   235,
     173,   236,   221,   238,   237,   266,   173,   239,   429,   431,
     240,   241,   251,   113,   193,   194,   121,   185,   121,   244,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   245,   255,   121,   121,   256,   246,   115,   116,   247,
     117,   173,   248,   249,   250,     1,   121,     2,     3,     4,
     254,   118,   173,     5,   258,   173,   173,   173,   173,   173,
     173,   173,   260,   173,   264,   173,   173,   284,   173,   173,
     173,   173,   173,   287,   289,   309,   173,   310,   311,   312,
     316,   318,   319,   173,   121,   206,   173,   173,   326,   173,
     192,   121,   121,   336,   340,   121,   121,   350,   351,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   352,   121,   353,   354,   355,   356,   380,   119,   106,
     107,   108,   109,   110,   111,   112,   121,   210,   121,   121,
     361,   373,   377,   378,   121,   121,   121,   379,    22,   384,
     113,    86,    51,   121,   385,   184,   387,   186,   386,   407,
     410,   411,   412,   114,   420,   451,   421,   121,   441,   444,
     442,    22,   209,   212,   115,   116,   445,   117,   446,    23,
      24,    25,    26,   447,   243,   227,   448,   449,   118,   450,
     464,   452,     2,     3,     4,    27,   455,   457,   121,    28,
      29,   121,    23,    24,    25,    26,   458,   121,   459,   460,
     461,   465,   121,   483,   487,     2,     3,     4,    27,    15,
     295,    47,   423,   262,    48,     0,   396,     0,   135,     0,
     268,   269,     0,     0,   270,   271,     0,   121,   121,     0,
       0,     0,   243,     0,     0,   121,     0,     0,     0,     0,
       0,   285,     0,   121,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     0,   121,   121,     0,   296,   297,     0,
       0,   121,     0,   299,   300,   301,     0,     0,     0,     0,
       0,   121,   313,     0,   243,     0,   121,   121,     0,   106,
     107,   108,   109,   110,   111,   112,   261,     0,   106,   107,
     108,   109,   110,   111,   112,   329,     0,     0,     0,     0,
     113,     0,     0,   121,     0,   121,     0,     0,   243,   113,
       0,   121,     0,   114,     0,     0,     0,   262,     0,   243,
     333,     0,   114,     0,   115,   116,     0,   117,     0,     0,
       0,     0,   243,   115,   116,     0,   117,   243,   118,     0,
     106,   107,   108,   109,   110,   111,   112,   118,   106,   107,
     108,   109,   110,   426,   112,   121,   364,   262,     0,     0,
       0,   113,     0,     0,   370,     0,     0,     0,   121,   113,
       0,     0,     0,     0,   114,   376,   243,   243,     0,     0,
       0,     0,     0,   382,   383,   115,   116,     0,   117,     0,
     388,   243,     0,   115,   116,     0,   141,     0,     0,   118,
     262,     0,     0,     0,     0,   395,   333,   118,   243,   106,
     107,   108,   109,   110,   111,   112,   365,   243,    22,     0,
       0,     0,    92,   243,     0,     0,     0,     0,     0,     0,
     113,     0,   417,     0,   419,     0,     0,     0,     0,     0,
     425,     0,     0,   114,     0,     0,     0,     0,     0,    23,
      24,    25,    26,     0,   115,   116,     0,   117,     0,     0,
       0,     0,     2,     3,     4,    27,     0,     0,   118,    28,
      29,     0,     0,   243,     0,     0,     0,     0,     0,     0,
     243,     0,     0,   243,   462,   243,   243,   243,   243,   243,
      22,     0,     0,   243,   132,     0,     0,   475,     0,     0,
       0,     0,     0,   243,     0,     0,   243,   106,   107,   108,
     109,   110,   138,   112,     0,     0,   242,     0,     0,     0,
       0,    23,    24,    25,    26,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     2,     3,     4,    27,     0,     0,
       0,    28,    29,    23,    24,    25,    26,   139,   140,     0,
       0,     0,   115,   116,     0,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,   118,   143,   144,   145,
      22,     0,   146,     0,   214,   147,   148,   149,   150,     0,
       0,     0,   151,     0,     0,   152,     0,     0,   153,   154,
     106,   107,   108,   109,   110,   138,   112,     0,     0,   290,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     2,     3,     4,    27,     0,     0,
       0,    28,    29,     0,     0,     0,    23,    24,    25,    26,
     139,   140,     0,     0,     0,   115,   116,     0,   141,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,   118,
     143,   144,   145,    22,     0,   146,     0,     0,   147,   148,
     149,   150,     0,     0,     0,   151,     0,     0,   152,     0,
       0,   153,   154,   106,   107,   108,   109,   110,   138,   112,
       0,     0,   317,     0,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     2,     3,     4,
      27,     0,     0,     0,    28,    29,     0,     0,     0,    23,
      24,    25,    26,   139,   140,     0,     0,     0,   115,   116,
       0,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,   118,   143,   144,   145,     0,     0,   146,     0,
       0,   147,   148,   149,   150,     0,     0,     0,   151,     0,
       0,   152,     0,     0,   153,   154,   106,   107,   108,   109,
     110,   138,   112,     0,     0,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   139,   140,     0,     0,
       0,   115,   116,     0,   141,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   118,   143,   144,   145,     0,
       0,   146,     0,     0,   147,   148,   149,   150,     0,     0,
       0,   151,     0,     0,   152,     0,     0,   153,   154,   106,
     107,   108,   109,   110,   138,   112,     0,     0,   347,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   139,
     140,     0,     0,     0,   115,   116,     0,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,   118,   143,
     144,   145,     0,     0,   146,     0,     0,   147,   148,   149,
     150,     0,     0,     0,   151,     0,     0,   152,     0,     0,
     153,   154,   106,   107,   108,   109,   110,   138,   112,     0,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   139,   140,     0,     0,     0,   115,   116,     0,
     141,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,   118,   143,   144,   145,     0,     0,   146,     0,     0,
     147,   148,   149,   150,     0,     0,     0,   151,     0,     0,
     152,     0,     0,   153,   154,   106,   107,   108,   109,   110,
     138,   112,     0,     0,   362,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   139,   140,     0,     0,     0,
     115,   116,     0,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,   118,   143,   144,   145,     0,     0,
     146,     0,     0,   147,   148,   149,   150,     0,     0,     0,
     151,     0,     0,   152,     0,     0,   153,   154,   106,   107,
     108,   109,   110,   138,   112,     0,     0,   389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   139,   140,
       0,     0,     0,   115,   116,     0,   141,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,   118,   143,   144,
     145,     0,     0,   146,     0,     0,   147,   148,   149,   150,
       0,     0,     0,   151,     0,     0,   152,     0,     0,   153,
     154,   106,   107,   108,   109,   110,   138,   112,     0,     0,
     390,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   139,   140,     0,     0,     0,   115,   116,     0,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
     118,   143,   144,   145,     0,     0,   146,     0,     0,   147,
     148,   149,   150,     0,     0,     0,   151,     0,     0,   152,
       0,     0,   153,   154,   106,   107,   108,   109,   110,   138,
     112,     0,     0,   397,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   139,   140,     0,     0,     0,   115,
     116,     0,   141,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,   118,   143,   144,   145,     0,     0,   146,
       0,     0,   147,   148,   149,   150,     0,     0,     0,   151,
       0,     0,   152,     0,     0,   153,   154,   106,   107,   108,
     109,   110,   138,   112,     0,     0,   414,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   139,   140,     0,
       0,     0,   115,   116,     0,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,   118,   143,   144,   145,
       0,     0,   146,     0,     0,   147,   148,   149,   150,     0,
       0,     0,   151,     0,     0,   152,     0,     0,   153,   154,
     106,   107,   108,   109,   110,   138,   112,     0,     0,   418,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     139,   140,     0,     0,     0,   115,   116,     0,   141,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,   118,
     143,   144,   145,     0,     0,   146,     0,     0,   147,   148,
     149,   150,     0,     0,     0,   151,     0,     0,   152,     0,
       0,   153,   154,   106,   107,   108,   109,   110,   138,   112,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   139,   140,     0,     0,     0,   115,   116,
       0,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,   118,   143,   144,   145,     0,     0,   146,     0,
       0,   147,   148,   149,   150,     0,     0,     0,   151,     0,
       0,   152,     0,     0,   153,   154,   106,   107,   108,   109,
     110,   138,   112,     0,     0,   467,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   139,   140,     0,     0,
       0,   115,   116,     0,   141,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   118,   143,   144,   145,     0,
       0,   146,     0,     0,   147,   148,   149,   150,     0,     0,
       0,   151,     0,     0,   152,     0,     0,   153,   154,   106,
     107,   108,   109,   110,   138,   112,     0,     0,   474,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   139,
     140,     0,     0,     0,   115,   116,     0,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,   118,   143,
     144,   145,     0,     0,   146,     0,     0,   147,   148,   149,
     150,     0,     0,     0,   151,     0,     0,   152,     0,     0,
     153,   154,   106,   107,   108,   109,   110,   138,   112,     0,
       0,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   139,   140,     0,     0,     0,   115,   116,     0,
     141,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,   118,   143,   144,   145,     0,     0,   146,     0,     0,
     147,   148,   149,   150,     0,     0,     0,   151,     0,     0,
     152,     0,     0,   153,   154,   106,   107,   108,   109,   110,
     138,   112,     0,     0,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   139,   140,     0,     0,     0,
     115,   116,     0,   141,     0,     0,     0,     0,     0,   142,
       0,     0,     0,     0,   118,   143,   144,   145,     0,     0,
     146,     0,     0,   147,   148,   149,   150,     0,     0,     0,
     151,     0,     0,   152,     0,     0,   153,   154,   106,   107,
     108,   109,   110,   138,   112,     0,     0,   479,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   139,   140,
       0,     0,     0,   115,   116,     0,   141,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,   118,   143,   144,
     145,     0,     0,   146,     0,     0,   147,   148,   149,   150,
       0,     0,     0,   151,     0,     0,   152,     0,     0,   153,
     154,   106,   107,   108,   109,   110,   138,   112,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   139,   140,     0,     0,     0,   115,   116,     0,   141,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
     118,   143,   144,   145,     0,     0,   146,     0,     0,   147,
     148,   149,   150,     0,     0,     0,   151,     0,     0,   152,
       0,     0,   153,   154,   106,   107,   108,   109,   110,   138,
     112,     0,     0,   481,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   139,   140,     0,     0,     0,   115,
     116,     0,   141,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,   118,   143,   144,   145,     0,     0,   146,
       0,     0,   147,   148,   149,   150,     0,     0,     0,   151,
       0,     0,   152,     0,     0,   153,   154,   106,   107,   108,
     109,   110,   138,   112,     0,     0,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,   139,   140,     0,
       0,     0,   115,   116,     0,   141,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,   118,   143,   144,   145,
       0,     0,   146,     0,     0,   147,   148,   149,   150,     0,
       0,     0,   151,     0,     0,   152,     0,     0,   153,   154,
     106,   107,   108,   109,   110,   138,   112,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     139,   140,     0,     0,     0,   115,   116,     0,   141,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,   118,
     143,   144,   145,     0,     0,   146,     0,     0,   147,   148,
     149,   150,     0,     0,     0,   151,     0,     0,   152,     0,
       0,   153,   154,   106,   107,   108,   109,   110,   138,   112,
       0,     0,   488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,   139,   140,     0,     0,     0,   115,   116,
       0,   141,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,   118,   143,   144,   145,     0,     0,   146,     0,
       0,   147,   148,   149,   150,     0,     0,     0,   151,     0,
       0,   152,     0,     0,   153,   154,   106,   107,   108,   109,
     110,   138,   112,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    26,   139,   140,     0,     0,
       0,   115,   116,     0,   141,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,   118,   143,   144,   145,     0,
       0,   146,     0,     0,   147,   148,   149,   150,     0,     0,
       0,   151,     0,     0,   152,     0,     0,   153,   154,   106,
     107,   108,   109,   110,   138,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   139,
     140,     0,     0,     0,   115,   116,     0,   141,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,   118,   143,
     144,   145,     0,     0,   146,     0,     0,   147,   148,   149,
     150,     0,     0,     0,   151,     0,     0,   152,     0,     0,
     153,   154,   106,   107,   108,   109,   110,   111,   112,   393,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,   116,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118
};

static const yytype_int16 yycheck[] =
{
      18,   234,    30,   172,    13,   222,   117,     8,    11,   284,
      28,    99,    30,    10,    96,    33,     8,    11,     9,    16,
      18,    13,    13,     9,    42,    63,    44,    13,    46,   111,
     141,     9,    30,    17,    18,    33,   253,    13,    66,    23,
      24,    25,    26,    27,    42,    83,   134,    65,    66,   324,
      36,    34,    35,    56,   223,    73,   138,   226,    58,    77,
      36,    73,    56,    91,    10,    77,    84,    65,    66,   157,
      16,   182,    84,    91,    74,    93,   293,    95,    87,    13,
       0,   298,    18,   101,    10,   103,    34,    35,   176,   101,
      16,   103,   367,    91,    30,    93,    87,    33,    42,    17,
      18,    86,    36,    86,    88,   133,    42,    25,    26,    27,
       8,    50,   223,   131,     7,   133,    17,    18,    10,   131,
     134,    65,   339,     8,    16,   294,    27,   215,   216,    65,
      66,    19,    20,    21,    22,   133,    17,    18,    86,   308,
       0,    39,    40,    41,    42,   233,   234,     7,    36,    93,
     261,     8,     8,    51,     9,    91,    13,    93,    13,     8,
     178,     9,   176,    10,    13,    13,   178,   255,    28,   257,
      88,     9,   260,     8,     9,   408,   409,     9,    13,   348,
     349,    36,   264,     8,    19,    20,    21,    22,    19,    20,
      21,    22,    86,   304,    34,    35,     9,   133,    86,    99,
      13,    36,   216,   291,    86,    36,    19,    20,    21,    22,
      11,   322,   381,     9,   302,    10,   234,     8,    10,   233,
       8,   303,    13,    36,    16,    10,     8,   315,   316,    10,
     318,    13,   320,     8,   134,     9,   234,   348,     8,    34,
      35,   255,    34,    35,   326,    10,   260,     9,   336,    34,
      35,    12,    87,     8,    13,    16,    87,   157,    13,   428,
      19,    20,    21,    22,    39,    40,    41,    42,    10,    34,
      35,   359,   360,   361,    87,    14,   176,    36,    86,     3,
       4,     5,     6,     7,     8,     9,   374,    14,    86,   377,
       9,   379,    34,    35,    13,    34,    35,    12,     8,    11,
      24,    16,   316,   391,   318,    69,    70,    34,    35,     8,
      10,    14,   400,    37,    10,   215,   216,     8,   406,    12,
     408,   409,   336,    16,    48,    49,    16,    51,    87,    39,
      40,    41,    42,   233,    34,    35,     9,    61,    62,    15,
      39,    40,    41,    42,   426,    55,    11,   361,    34,    35,
      60,     9,    38,   441,    10,   255,    55,   257,    34,    35,
     260,    10,     9,   377,   452,   379,    11,   455,   456,   457,
     458,   459,   460,   461,    13,   463,    10,   465,   466,    10,
     468,   469,   470,   471,   472,    34,    35,     9,   476,    69,
      70,   291,   410,   411,   412,   483,    10,    10,   486,   487,
      10,   489,   302,    34,    35,    11,    10,     9,     3,     4,
       5,     6,     7,     8,     9,   315,   316,    10,   318,     9,
     320,    34,    35,     9,    34,    35,    87,   441,     8,    24,
      34,    35,    13,    10,    66,    67,   336,    11,   452,    10,
       9,   455,    37,   457,   458,   459,   460,   461,     9,    44,
      86,   465,    15,    48,    49,    11,    51,    34,    35,   359,
     360,   361,    16,    34,    35,    16,    86,    62,     9,   483,
       9,    34,    35,   487,   374,    66,    67,   377,     9,   379,
      34,    35,     9,    34,    35,    19,    20,    21,    22,    85,
      86,   391,     3,     4,     5,     6,     7,     8,     9,     8,
     400,     8,    36,     9,     8,    87,   406,     9,   408,   409,
      86,    86,     8,    24,    17,    18,   112,   113,   114,    86,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    86,    11,   129,   130,    10,    86,    48,    49,    86,
      51,   441,    86,    86,    86,    50,   142,    52,    53,    54,
      86,    62,   452,    58,    10,   455,   456,   457,   458,   459,
     460,   461,    11,   463,     8,   465,   466,     9,   468,   469,
     470,   471,   472,    11,    10,    36,   476,    36,    36,     8,
      11,    11,    10,   483,   180,    88,   486,   487,     8,   489,
      35,   187,   188,    11,    10,   191,   192,    86,    86,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     8,   208,    61,    61,    61,    10,    71,    85,     3,
       4,     5,     6,     7,     8,     9,   222,    11,   224,   225,
      11,    11,    11,    11,   230,   231,   232,    11,     8,    74,
      24,    36,    12,   239,    78,   112,    86,   114,    81,     9,
       9,     9,     9,    37,    15,     9,    12,   253,    11,    10,
      15,     8,   129,   130,    48,    49,    10,    51,    10,    39,
      40,    41,    42,    10,   157,   142,    10,    10,    62,    10,
       9,    11,    52,    53,    54,    55,    11,    11,   284,    59,
      60,   287,    39,    40,    41,    42,    11,   293,    11,    11,
      11,    11,   298,    11,    11,    52,    53,    54,    55,     7,
     224,    28,   404,   180,    28,    -1,   373,    -1,    95,    -1,
     187,   188,    -1,    -1,   191,   192,    -1,   323,   324,    -1,
      -1,    -1,   215,    -1,    -1,   331,    -1,    -1,    -1,    -1,
      -1,   208,    -1,   339,    -1,    -1,   342,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,   351,    -1,   224,   225,    -1,
      -1,   357,    -1,   230,   231,   232,    -1,    -1,    -1,    -1,
      -1,   367,   239,    -1,   257,    -1,   372,   373,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      24,    -1,    -1,   399,    -1,   401,    -1,    -1,   291,    24,
      -1,   407,    -1,    37,    -1,    -1,    -1,   284,    -1,   302,
     287,    -1,    37,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,   315,    48,    49,    -1,    51,   320,    62,    -1,
       3,     4,     5,     6,     7,     8,     9,    62,     3,     4,
       5,     6,     7,     8,     9,   451,   323,   324,    -1,    -1,
      -1,    24,    -1,    -1,   331,    -1,    -1,    -1,   464,    24,
      -1,    -1,    -1,    -1,    37,   342,   359,   360,    -1,    -1,
      -1,    -1,    -1,   350,   351,    48,    49,    -1,    51,    -1,
     357,   374,    -1,    48,    49,    -1,    51,    -1,    -1,    62,
     367,    -1,    -1,    -1,    -1,   372,   373,    62,   391,     3,
       4,     5,     6,     7,     8,     9,    10,   400,     8,    -1,
      -1,    -1,    12,   406,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,   399,    -1,   401,    -1,    -1,    -1,    -1,    -1,
     407,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    -1,    -1,    62,    59,
      60,    -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,
     463,    -1,    -1,   466,   451,   468,   469,   470,   471,   472,
       8,    -1,    -1,   476,    12,    -1,    -1,   464,    -1,    -1,
      -1,    -1,    -1,   486,    -1,    -1,   489,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    59,    60,    39,    40,    41,    42,    43,    44,    -1,
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
      63,    64,    65,     8,    -1,    68,    -1,    -1,    71,    72,
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
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    -1,    -1,    81,    -1,    -1,
      84,    85,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62
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
       7,     8,     9,    24,    37,    48,    49,    51,    62,   136,
     137,   138,   140,   141,    61,   114,   133,   135,   136,    13,
      36,     9,    12,    96,    11,   117,   129,    10,     8,    43,
      44,    51,    57,    63,    64,    65,    68,    71,    72,    73,
      74,    78,    81,    84,    85,    93,    94,    98,    99,   100,
     101,   102,   103,   104,   107,   111,   124,   126,   127,   128,
     134,   138,   140,   141,    10,   115,    11,   115,     9,    10,
       9,    87,   129,   142,   136,   138,   136,     9,     9,   142,
      14,    34,    35,    17,    18,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    88,     8,    38,   136,
      11,   130,   136,   115,    12,    98,    11,    19,    20,    21,
      22,    36,   125,   129,     9,     9,   142,   136,    86,    86,
       9,     9,     9,    11,     9,     8,     8,     8,     9,     9,
      86,    86,    12,    99,    86,    86,    86,    86,    86,    86,
      86,     8,    86,   125,    86,    11,    10,    98,    10,   115,
      11,    10,   136,   139,     8,   142,    87,    10,   136,   136,
     136,   136,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,     9,   136,    14,    11,   131,    10,
      12,    98,   133,   125,   142,    94,   136,   136,   125,   136,
     136,   136,    98,     8,    51,   124,   126,   134,   140,    36,
      36,    36,     8,   136,   133,    98,    11,    12,    11,    10,
      98,   142,    10,    16,     9,   129,     8,    10,    10,    10,
     139,    15,   132,   136,    12,    16,    11,    12,   133,   125,
      10,    10,    16,   133,    10,    10,    10,    12,   129,   142,
      86,    86,     8,    61,    61,    61,    10,    16,    12,    98,
      98,    11,    12,   142,   136,    10,   139,     9,   129,    10,
     136,    12,    16,    11,    98,   133,   136,    11,    11,    11,
      71,   142,   136,   136,    74,    78,    81,    86,   136,    12,
      12,    98,    10,    10,   139,   136,   132,    12,    10,    16,
      98,    69,    70,   108,   109,   110,    98,     9,    86,    86,
       9,     9,     9,    10,    12,    10,    12,   136,    12,   136,
      15,    12,    70,   110,    12,   136,     8,   124,   140,   141,
     124,   141,   134,   134,   134,    10,    66,    67,   105,   106,
      15,    11,    15,    10,    10,    10,    10,    10,    10,    10,
      10,     9,    11,    66,    67,    11,    98,    11,    11,    11,
      11,    11,   136,    98,     9,    11,    98,    12,    98,    98,
      98,    98,    98,    10,    12,   136,    98,    12,    12,    12,
      12,    12,    12,    11,    10,    12,    98,    11,    12,    98,
      12
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
     133,   134,   134,   134,   134,   134,   135,   136,   136,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     139,   139,   140,   140,   140,   140,   140,   141,   141,   142,
     142,   142,   142,   142,   142,   142,   142
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
       1,     1,     1,     1,     1,     1,     5,     3,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     4,     4,     1,
       3,     1,     3,     4,     4,     5,     2,     2,     2,     3,
       5,     6,     4,     2,     4,     5,     3
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
#line 286 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2429 "parser.cpp" /* yacc.c:1651  */
    break;

  case 19:
#line 288 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *sobre = new nodo("sobrescribir","sobrescribir",yylineno,columna);
             (yyval.nodito)->hijos.prepend(*sobre);
        }
#line 2439 "parser.cpp" /* yacc.c:1651  */
    break;

  case 20:
#line 296 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 2445 "parser.cpp" /* yacc.c:1651  */
    break;

  case 21:
#line 297 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nuevo = new nodo("sentencias","sentencias",yylineno, columna); nuevo->add(*(yyvsp[0].nodito)); (yyval.nodito) = nuevo;}
#line 2451 "parser.cpp" /* yacc.c:1651  */
    break;

  case 22:
#line 300 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2457 "parser.cpp" /* yacc.c:1651  */
    break;

  case 23:
#line 301 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = (yyvsp[-1].nodito);}
#line 2463 "parser.cpp" /* yacc.c:1651  */
    break;

  case 24:
#line 302 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2469 "parser.cpp" /* yacc.c:1651  */
    break;

  case 25:
#line 303 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2475 "parser.cpp" /* yacc.c:1651  */
    break;

  case 26:
#line 304 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[-1].nodito);}
#line 2481 "parser.cpp" /* yacc.c:1651  */
    break;

  case 27:
#line 305 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2487 "parser.cpp" /* yacc.c:1651  */
    break;

  case 28:
#line 307 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2493 "parser.cpp" /* yacc.c:1651  */
    break;

  case 29:
#line 308 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2499 "parser.cpp" /* yacc.c:1651  */
    break;

  case 30:
#line 309 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2505 "parser.cpp" /* yacc.c:1651  */
    break;

  case 31:
#line 310 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2511 "parser.cpp" /* yacc.c:1651  */
    break;

  case 32:
#line 311 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2517 "parser.cpp" /* yacc.c:1651  */
    break;

  case 33:
#line 312 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2523 "parser.cpp" /* yacc.c:1651  */
    break;

  case 34:
#line 313 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2529 "parser.cpp" /* yacc.c:1651  */
    break;

  case 35:
#line 314 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("detener","detener",yylineno,columna);}
#line 2535 "parser.cpp" /* yacc.c:1651  */
    break;

  case 36:
#line 315 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("continuar","continuar",yylineno,columna);}
#line 2541 "parser.cpp" /* yacc.c:1651  */
    break;

  case 37:
#line 316 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 2547 "parser.cpp" /* yacc.c:1651  */
    break;

  case 38:
#line 317 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("mostraredd",(yyvsp[-2].TEXT),yylineno,columna);}
#line 2553 "parser.cpp" /* yacc.c:1651  */
    break;

  case 39:
#line 318 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito)=(yyvsp[-1].nodito);}
#line 2559 "parser.cpp" /* yacc.c:1651  */
    break;

  case 40:
#line 323 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= new nodo("leer","leer",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-3].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2569 "parser.cpp" /* yacc.c:1651  */
    break;

  case 41:
#line 332 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2581 "parser.cpp" /* yacc.c:1651  */
    break;

  case 42:
#line 340 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2593 "parser.cpp" /* yacc.c:1651  */
    break;

  case 43:
#line 348 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // decremento / aumento
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2605 "parser.cpp" /* yacc.c:1651  */
    break;

  case 44:
#line 356 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("para","para",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito));// Declaracion
            (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito)); // Condicion
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Asignacion
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
        }
#line 2617 "parser.cpp" /* yacc.c:1651  */
    break;

  case 45:
#line 368 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("hacer","hacer",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));// sentencias
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));// condicion;
        }
#line 2627 "parser.cpp" /* yacc.c:1651  */
    break;

  case 46:
#line 378 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito) = new nodo("mientras","mientras",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // Condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2637 "parser.cpp" /* yacc.c:1651  */
    break;

  case 47:
#line 387 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("si","si",yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));// condicion
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentencias
         }
#line 2647 "parser.cpp" /* yacc.c:1651  */
    break;

  case 48:
#line 393 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             (yyval.nodito)->tipo = "si";
             (yyval.nodito)->valor = "si";
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito)); // Sentencias
             (yyval.nodito)->hijos.prepend(*(yyvsp[-5].nodito));// condicion
         }
#line 2659 "parser.cpp" /* yacc.c:1651  */
    break;

  case 49:
#line 405 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
          }
#line 2668 "parser.cpp" /* yacc.c:1651  */
    break;

  case 50:
#line 410 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 2676 "parser.cpp" /* yacc.c:1651  */
    break;

  case 51:
#line 414 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito)= (yyvsp[-1].nodito);
         }
#line 2684 "parser.cpp" /* yacc.c:1651  */
    break;

  case 52:
#line 420 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)=(yyvsp[-7].nodito);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2694 "parser.cpp" /* yacc.c:1651  */
    break;

  case 53:
#line 426 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("sinosi","sinosi",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // condicion
           (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // Sentenencias
         }
#line 2704 "parser.cpp" /* yacc.c:1651  */
    break;

  case 54:
#line 435 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("selecciona",(yyvsp[-6].TEXT),yylineno,columna);
             (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2714 "parser.cpp" /* yacc.c:1651  */
    break;

  case 55:
#line 442 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-5].nodito);
        nodo *def = new nodo("defecto","defecto",yylineno,columna);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2725 "parser.cpp" /* yacc.c:1651  */
    break;

  case 56:
#line 449 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)= new nodo("casos","casos",yylineno,columna);
        nodo *def = new nodo("caso","defecto",yylineno,columna);
        def->hijos.append(*(yyvsp[-1].nodito));
        (yyval.nodito)->hijos.append(*def);
     }
#line 2736 "parser.cpp" /* yacc.c:1651  */
    break;

  case 57:
#line 459 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2745 "parser.cpp" /* yacc.c:1651  */
    break;

  case 58:
#line 464 "sintactico.yy" /* yacc.c:1651  */
    {
           (yyval.nodito)= new nodo("casos","casos",yylineno,columna);
           (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
         }
#line 2754 "parser.cpp" /* yacc.c:1651  */
    break;

  case 59:
#line 470 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("caso","caso",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 2764 "parser.cpp" /* yacc.c:1651  */
    break;

  case 60:
#line 478 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=new nodo("retorno","retorno",yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
              }
#line 2773 "parser.cpp" /* yacc.c:1651  */
    break;

  case 61:
#line 485 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
                (yyval.nodito)->tipo = "declatrib";
                (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2784 "parser.cpp" /* yacc.c:1651  */
    break;

  case 62:
#line 492 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = (yyvsp[-1].nodito);
                nodo *nod = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.prepend(*nod);
                (yyval.nodito)->tipo = "declatrib";
                (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2796 "parser.cpp" /* yacc.c:1651  */
    break;

  case 63:
#line 500 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.prepend(*(yyvsp[-2].nodito));
             (yyval.nodito)->tipo = "declatrib";
             (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
            }
#line 2807 "parser.cpp" /* yacc.c:1651  */
    break;

  case 64:
#line 507 "sintactico.yy" /* yacc.c:1651  */
    {
         (yyval.nodito) = (yyvsp[-1].nodito);
         nodo *nod = new nodo("publico","publico",yylineno, columna);
         (yyval.nodito)->hijos.prepend(*nod);
         (yyval.nodito)->tipo = "declatrib";
         (yyval.nodito)->tipo_ = (yyval.nodito)->getTipo();
        }
#line 2819 "parser.cpp" /* yacc.c:1651  */
    break;

  case 65:
#line 518 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("publico",(yyvsp[0].TEXT),yylineno, columna);}
#line 2825 "parser.cpp" /* yacc.c:1651  */
    break;

  case 66:
#line 519 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("privado",(yyvsp[0].TEXT),yylineno, columna);}
#line 2831 "parser.cpp" /* yacc.c:1651  */
    break;

  case 67:
#line 520 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo("protegido",(yyvsp[0].TEXT),yylineno, columna);}
#line 2837 "parser.cpp" /* yacc.c:1651  */
    break;

  case 68:
#line 523 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *cons = new nodo("constructor",(yyvsp[-3].TEXT),yylineno,columna);
                 cons->hijos.append(*(yyvsp[-1].nodito)); // LISTA DE PARAMETROS
                 (yyval.nodito) = cons;
            }
#line 2847 "parser.cpp" /* yacc.c:1651  */
    break;

  case 69:
#line 529 "sintactico.yy" /* yacc.c:1651  */
    {
                 nodo *cons = new nodo("constructor",(yyvsp[-2].TEXT),yylineno,columna);
                 nodo *lpar = new nodo("lpar","lpar",yylineno,columna);
                 cons->hijos.append(*lpar); // LISTA DE PARAMETROS
                 (yyval.nodito) = cons;
            }
#line 2858 "parser.cpp" /* yacc.c:1651  */
    break;

  case 70:
#line 537 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 2864 "parser.cpp" /* yacc.c:1651  */
    break;

  case 71:
#line 539 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",0,0);
            }
#line 2872 "parser.cpp" /* yacc.c:1651  */
    break;

  case 72:
#line 546 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=(yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2881 "parser.cpp" /* yacc.c:1651  */
    break;

  case 73:
#line 551 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("parametros","parametros",yylineno, columna);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2890 "parser.cpp" /* yacc.c:1651  */
    break;

  case 74:
#line 558 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-1].nodito)->tipo = (yyvsp[-1].nodito)->valor;
                (yyvsp[-1].nodito)->valor = (yyvsp[0].TEXT);
                (yyval.nodito) = (yyvsp[-1].nodito);
            }
#line 2900 "parser.cpp" /* yacc.c:1651  */
    break;

  case 75:
#line 564 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyvsp[-2].nodito)->tipo = (yyvsp[-2].nodito)->valor;
                (yyvsp[-2].nodito)->valor = (yyvsp[-1].TEXT);
                (yyval.nodito) = (yyvsp[-2].nodito);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
            }
#line 2911 "parser.cpp" /* yacc.c:1651  */
    break;

  case 76:
#line 573 "sintactico.yy" /* yacc.c:1651  */
    {

                (yyval.nodito) = new nodo("funcion",(yyvsp[-5].TEXT), yylineno, columna);
                nodo *sobre = new nodo("sobrescribir","no",yylineno,columna);
                (yyval.nodito)->hijos.prepend(*sobre);
                nodo *vis = new nodo("publico","publico",yylineno, columna);
                (yyval.nodito)->hijos.append(*vis);
                nodo *tipo = new nodo("tipo","",yylineno,columna);
                (yyval.nodito)->hijos.prepend(*tipo);
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);
                nodo *param = new nodo("parametros","parametros",0,0);
                (yyval.nodito)->hijos.append(*param);
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
           }
#line 2931 "parser.cpp" /* yacc.c:1651  */
    break;

  case 77:
#line 589 "sintactico.yy" /* yacc.c:1651  */
    {

                     (yyval.nodito) = new nodo("funcion",(yyvsp[-5].TEXT), yylineno, columna);
                     nodo *sobre = new nodo("sobrescribir","no",yylineno,columna);
                     (yyval.nodito)->hijos.prepend(*sobre);
                     (yyval.nodito)->hijos.append(*(yyvsp[-6].nodito));
                     nodo *tipo = new nodo("tipo","",yylineno,columna);
                     (yyval.nodito)->hijos.prepend(*tipo);
                     nodo *dims= new nodo("dims","dims",yylineno, columna);
                     (yyval.nodito)->hijos.append(*dims);
                     nodo *param = new nodo("parametros","parametros",0,0);
                     (yyval.nodito)->hijos.append(*param);
                     (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
                }
#line 2950 "parser.cpp" /* yacc.c:1651  */
    break;

  case 78:
#line 606 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("constructor",(yyvsp[-6].TEXT),yylineno,columna);
                    (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // visibilidad
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2961 "parser.cpp" /* yacc.c:1651  */
    break;

  case 79:
#line 613 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito) = new nodo("constructor",(yyvsp[-6].TEXT),yylineno,columna);
                    nodo *vis = new nodo("visibilidad","publico",yylineno,columna);
                    (yyval.nodito)->hijos.append(*vis); // visibilidad
                    (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito));  // parametros
                    (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // instrucciones
                }
#line 2973 "parser.cpp" /* yacc.c:1651  */
    break;

  case 80:
#line 623 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-9].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // tipo
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // dimensiones del retorno
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 2986 "parser.cpp" /* yacc.c:1651  */
    break;

  case 81:
#line 632 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("funcion",(yyvsp[-6].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*(yyvsp[-8].nodito)); // visibilidad
                (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito)); // tipo
                nodo *dims= new nodo("dims","dims",yylineno, columna);
                (yyval.nodito)->hijos.append(*dims);
                (yyval.nodito)->hijos.append(*(yyvsp[-4].nodito)); // lista de parametros
                (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito)); // lista de instrucciones;
            }
#line 3000 "parser.cpp" /* yacc.c:1651  */
    break;

  case 82:
#line 642 "sintactico.yy" /* yacc.c:1651  */
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
#line 3015 "parser.cpp" /* yacc.c:1651  */
    break;

  case 83:
#line 653 "sintactico.yy" /* yacc.c:1651  */
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
#line 3031 "parser.cpp" /* yacc.c:1651  */
    break;

  case 84:
#line 665 "sintactico.yy" /* yacc.c:1651  */
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
#line 3046 "parser.cpp" /* yacc.c:1651  */
    break;

  case 85:
#line 676 "sintactico.yy" /* yacc.c:1651  */
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
#line 3062 "parser.cpp" /* yacc.c:1651  */
    break;

  case 86:
#line 690 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= (yyvsp[-1].nodito);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 3071 "parser.cpp" /* yacc.c:1651  */
    break;

  case 87:
#line 694 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)= new nodo("dims","dims",yylineno, columna);
             (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
          }
#line 3080 "parser.cpp" /* yacc.c:1651  */
    break;

  case 88:
#line 699 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("dim","dim",yylineno,columna);}
#line 3086 "parser.cpp" /* yacc.c:1651  */
    break;

  case 89:
#line 707 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-5].nodito));
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  (yyval.nodito)->hijos.append(*her);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3098 "parser.cpp" /* yacc.c:1651  */
    break;

  case 90:
#line 715 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-3].TEXT),yylineno, columna);
                  nodo *nod = new nodo("visibilidad","publico",yylineno, columna);
                  (yyval.nodito)->hijos.append(*nod);
                  nodo *her = new nodo("herencia","nada",yylineno, columna);
                  (yyval.nodito)->hijos.append(*her);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3111 "parser.cpp" /* yacc.c:1651  */
    break;

  case 91:
#line 725 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),yylineno, columna);
                  (yyval.nodito)->hijos.append(*(yyvsp[-7].nodito));
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3123 "parser.cpp" /* yacc.c:1651  */
    break;

  case 92:
#line 733 "sintactico.yy" /* yacc.c:1651  */
    {
                  (yyval.nodito) = new nodo("clase",(yyvsp[-5].TEXT),yylineno, columna);
                  nodo *nod = new nodo("publico","publico",yylineno, columna);
                  (yyval.nodito)->hijos.append(*nod);
                  nodo *padre = new nodo("herencia",(yyvsp[-3].TEXT),yylineno,columna);
                  (yyval.nodito)->hijos.append(*padre);
                  (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
              }
#line 3136 "parser.cpp" /* yacc.c:1651  */
    break;

  case 93:
#line 747 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)=(yyvsp[-1].nodito);
                nodo *acceso = new nodo("acceso","acceso",yylineno, columna);
                nodo *nombre = new nodo("id",(yyvsp[-2].TEXT),yylineno, (yylsp[-2]).first_column);
                acceso->hijos.append(*nombre); // nombre
                (yyval.nodito)->add(*acceso);
                (yyval.nodito)->add(*(yyvsp[0].nodito));
              }
#line 3149 "parser.cpp" /* yacc.c:1651  */
    break;

  case 94:
#line 756 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);                    
                    nodo *acceso = new nodo("accesoarray","accesoarray",(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                    nodo *nombre = new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
                    acceso->hijos.append(*nombre);
                    acceso->hijos.append(*(yyvsp[-2].nodito));
                    (yyval.nodito)->hijos.append(*acceso);  // Destino
                    (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));      // Valor
               }
#line 3163 "parser.cpp" /* yacc.c:1651  */
    break;

  case 95:
#line 766 "sintactico.yy" /* yacc.c:1651  */
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
#line 3188 "parser.cpp" /* yacc.c:1651  */
    break;

  case 96:
#line 787 "sintactico.yy" /* yacc.c:1651  */
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
#line 3217 "parser.cpp" /* yacc.c:1651  */
    break;

  case 97:
#line 812 "sintactico.yy" /* yacc.c:1651  */
    {
                    (yyval.nodito)=(yyvsp[-1].nodito);
                    nodo *acceso = new nodo("accesoarray","accesoarray",(yylsp[-4]).first_line,(yylsp[-4]).first_column);
                    nodo *nombre = new nodo("id",(yyvsp[-4].TEXT),(yylsp[-4]).first_line,(yylsp[-4]).first_column);
                    acceso->hijos.append(*nombre); // id
                    acceso->hijos.append(*(yyvsp[-2].nodito));
                    (yyval.nodito)->hijos.append(*acceso);
                    (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
                }
#line 3231 "parser.cpp" /* yacc.c:1651  */
    break;

  case 98:
#line 823 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3237 "parser.cpp" /* yacc.c:1651  */
    break;

  case 99:
#line 824 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3243 "parser.cpp" /* yacc.c:1651  */
    break;

  case 100:
#line 825 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3249 "parser.cpp" /* yacc.c:1651  */
    break;

  case 101:
#line 826 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3255 "parser.cpp" /* yacc.c:1651  */
    break;

  case 102:
#line 827 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=new nodo("asig",(yyvsp[0].TEXT),yylineno, columna);}
#line 3261 "parser.cpp" /* yacc.c:1651  */
    break;

  case 103:
#line 833 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("d",(yyvsp[0].TEXT),yylineno, columna);
            nodo *nodoid =  new nodo("id",(yyvsp[0].TEXT),yylineno,columna);
            nuevo->add(*(yyvsp[-1].nodito)); // tipo
            nuevo->add(*nodoid);
            (yyval.nodito) = nuevo;
         }
#line 3273 "parser.cpp" /* yacc.c:1651  */
    break;

  case 104:
#line 841 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("da",(yyvsp[-2].TEXT),yylineno, columna);
             nodo *nodoid =  new nodo("id",(yyvsp[-2].TEXT),yylineno,columna);
             nuevo->add(*(yyvsp[-3].nodito)); // tipo
             nuevo->add(*nodoid);
             nuevo->add(*(yyvsp[0].nodito)); // valor
             (yyval.nodito) = nuevo;
         }
#line 3286 "parser.cpp" /* yacc.c:1651  */
    break;

  case 105:
#line 853 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3297 "parser.cpp" /* yacc.c:1651  */
    break;

  case 106:
#line 860 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3308 "parser.cpp" /* yacc.c:1651  */
    break;

  case 107:
#line 867 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = new nodo("d",(yyvsp[-6].TEXT),yylineno,columna);
          nodo *tipo = new nodo("tipo",(yyvsp[-7].TEXT),yylineno,columna);
          (yyval.nodito)->hijos.append(*tipo);
          (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
        }
#line 3319 "parser.cpp" /* yacc.c:1651  */
    break;

  case 108:
#line 881 "sintactico.yy" /* yacc.c:1651  */
    {
            nodo *nuevo = new nodo("dar","dar",yylineno, columna);
            nuevo->add(*(yyvsp[-2].nodito));
            nodo *nodoid =  new nodo("id",(yyvsp[-1].TEXT),yylineno,columna);
            nuevo->add(*nodoid);
            nuevo->add(*(yyvsp[0].nodito));
            (yyval.nodito) = nuevo;
         }
#line 3332 "parser.cpp" /* yacc.c:1651  */
    break;

  case 109:
#line 889 "sintactico.yy" /* yacc.c:1651  */
    {
             nodo *nuevo = new nodo("dara","dara",yylineno, columna);
             nuevo->add(*(yyvsp[-4].nodito));
             nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
             nuevo->add(*nodoid);
             nuevo->add(*(yyvsp[-2].nodito));
             nuevo->add(*(yyvsp[0].nodito));
             (yyval.nodito) = nuevo;}
#line 3345 "parser.cpp" /* yacc.c:1651  */
    break;

  case 110:
#line 897 "sintactico.yy" /* yacc.c:1651  */
    {
              nodo *nuevo = new nodo("darar","darar",yylineno, columna);
              nuevo->add(*(yyvsp[-4].nodito));
              nodo *nodoid =  new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
              nuevo->add(*nodoid);
              nuevo->add(*(yyvsp[-2].nodito));
              nuevo->add(*(yyvsp[0].nodito));
              (yyval.nodito) = nuevo;}
#line 3358 "parser.cpp" /* yacc.c:1651  */
    break;

  case 111:
#line 908 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)->add(*(yyvsp[-1].nodito));}
#line 3364 "parser.cpp" /* yacc.c:1651  */
    break;

  case 112:
#line 910 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito)= new nodo("dim","dim",yylineno, columna);
                (yyval.nodito)->add(*(yyvsp[-1].nodito));
            }
#line 3373 "parser.cpp" /* yacc.c:1651  */
    break;

  case 113:
#line 918 "sintactico.yy" /* yacc.c:1651  */
    {
          (yyval.nodito) = (yyvsp[-1].nodito);
         }
#line 3381 "parser.cpp" /* yacc.c:1651  */
    break;

  case 114:
#line 924 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-4].nodito);
             for (int i= 0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod = (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3394 "parser.cpp" /* yacc.c:1651  */
    break;

  case 115:
#line 933 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lvalores","lvalores",yylineno, columna);
             for (int i =0 ; i< (yyvsp[-1].nodito)->hijos.count(); i++)
             {
                 nodo nod =  (yyvsp[-1].nodito)->hijos[i];
                 (yyval.nodito)->add(nod);
             }
         }
#line 3407 "parser.cpp" /* yacc.c:1651  */
    break;

  case 116:
#line 943 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-2].nodito); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3413 "parser.cpp" /* yacc.c:1651  */
    break;

  case 117:
#line 944 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("valores","valores",yylineno,columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3419 "parser.cpp" /* yacc.c:1651  */
    break;

  case 118:
#line 949 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3425 "parser.cpp" /* yacc.c:1651  */
    break;

  case 119:
#line 950 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3431 "parser.cpp" /* yacc.c:1651  */
    break;

  case 120:
#line 951 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[0].nodito);}
#line 3437 "parser.cpp" /* yacc.c:1651  */
    break;

  case 121:
#line 954 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("boleano",(yyvsp[0].TEXT),yylineno,columna);}
#line 3443 "parser.cpp" /* yacc.c:1651  */
    break;

  case 122:
#line 955 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("entero",(yyvsp[0].TEXT),yylineno,columna);}
#line 3449 "parser.cpp" /* yacc.c:1651  */
    break;

  case 123:
#line 956 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("caracter",(yyvsp[0].TEXT),yylineno,columna);}
#line 3455 "parser.cpp" /* yacc.c:1651  */
    break;

  case 124:
#line 957 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("decimal",(yyvsp[0].TEXT),yylineno,columna);}
#line 3461 "parser.cpp" /* yacc.c:1651  */
    break;

  case 125:
#line 958 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)= new nodo("objeto",(yyvsp[0].TEXT),yylineno,columna);}
#line 3467 "parser.cpp" /* yacc.c:1651  */
    break;

  case 126:
#line 965 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("ss","ss",yylineno, columna);
             (yyval.nodito)->add(*(yyvsp[-4].nodito)); // Condicion
             (yyval.nodito)->add(*(yyvsp[-2].nodito)); // Valor verdadero
             (yyval.nodito)->add(*(yyvsp[0].nodito)); // Valor falso;
         }
#line 3478 "parser.cpp" /* yacc.c:1651  */
    break;

  case 127:
#line 973 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3484 "parser.cpp" /* yacc.c:1651  */
    break;

  case 128:
#line 974 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3490 "parser.cpp" /* yacc.c:1651  */
    break;

  case 129:
#line 975 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3496 "parser.cpp" /* yacc.c:1651  */
    break;

  case 130:
#line 976 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3502 "parser.cpp" /* yacc.c:1651  */
    break;

  case 131:
#line 979 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3508 "parser.cpp" /* yacc.c:1651  */
    break;

  case 132:
#line 980 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3514 "parser.cpp" /* yacc.c:1651  */
    break;

  case 133:
#line 981 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3520 "parser.cpp" /* yacc.c:1651  */
    break;

  case 134:
#line 982 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3526 "parser.cpp" /* yacc.c:1651  */
    break;

  case 135:
#line 983 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3532 "parser.cpp" /* yacc.c:1651  */
    break;

  case 136:
#line 984 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno,columna); (yyval.nodito)->add(*(yyvsp[-2].nodito)); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3538 "parser.cpp" /* yacc.c:1651  */
    break;

  case 137:
#line 985 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) =(yyvsp[0].nodito);}
#line 3544 "parser.cpp" /* yacc.c:1651  */
    break;

  case 138:
#line 987 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna);  nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3550 "parser.cpp" /* yacc.c:1651  */
    break;

  case 139:
#line 988 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3556 "parser.cpp" /* yacc.c:1651  */
    break;

  case 140:
#line 989 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3562 "parser.cpp" /* yacc.c:1651  */
    break;

  case 141:
#line 990 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito)); nod->add(*(yyvsp[0].nodito)); (yyval.nodito)=nod;}
#line 3568 "parser.cpp" /* yacc.c:1651  */
    break;

  case 142:
#line 991 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito));  nod->add(*(yyvsp[0].nodito));  (yyval.nodito)=nod ;  }
#line 3574 "parser.cpp" /* yacc.c:1651  */
    break;

  case 143:
#line 992 "sintactico.yy" /* yacc.c:1651  */
    { nodo *nod = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); nod->add(*(yyvsp[-2].nodito));  nod->add(*(yyvsp[0].nodito));  (yyval.nodito)=nod ;  }
#line 3580 "parser.cpp" /* yacc.c:1651  */
    break;

  case 144:
#line 993 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo((yyvsp[-1].TEXT),(yyvsp[-1].TEXT),yylineno, columna); (yyval.nodito)->add(*(yyvsp[0].nodito));}
#line 3586 "parser.cpp" /* yacc.c:1651  */
    break;

  case 145:
#line 995 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("acceso","acceso",yylineno, columna);
             nodo *nombre = new nodo("id",(yyvsp[0].TEXT),yylineno,columna);
             (yyval.nodito)->hijos.append(*nombre);
        }
#line 3596 "parser.cpp" /* yacc.c:1651  */
    break;

  case 146:
#line 1001 "sintactico.yy" /* yacc.c:1651  */
    {
                (yyval.nodito) = new nodo("accesoarray","accesoarray",yylineno,columna);
                nodo *nombre = new nodo("id",(yyvsp[-1].TEXT),yylineno,columna);
                (yyval.nodito)->hijos.append(*nombre);
                (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
        }
#line 3607 "parser.cpp" /* yacc.c:1651  */
    break;

  case 147:
#line 1007 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("entero",(yyvsp[0].TEXT),yylineno, columna);}
#line 3613 "parser.cpp" /* yacc.c:1651  */
    break;

  case 148:
#line 1008 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("caracter",(yyvsp[0].TEXT),yylineno, columna);}
#line 3619 "parser.cpp" /* yacc.c:1651  */
    break;

  case 149:
#line 1009 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("decimal",(yyvsp[0].TEXT),yylineno, columna);}
#line 3625 "parser.cpp" /* yacc.c:1651  */
    break;

  case 150:
#line 1010 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("booleano",(yyvsp[0].TEXT),yylineno, columna);}
#line 3631 "parser.cpp" /* yacc.c:1651  */
    break;

  case 151:
#line 1011 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("cadena",(yyvsp[0].TEXT),yylineno, columna);}
#line 3637 "parser.cpp" /* yacc.c:1651  */
    break;

  case 152:
#line 1012 "sintactico.yy" /* yacc.c:1651  */
    { (yyval.nodito) = new nodo("nada",(yyvsp[0].TEXT),yylineno, columna);}
#line 3643 "parser.cpp" /* yacc.c:1651  */
    break;

  case 153:
#line 1013 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito) = (yyvsp[0].nodito);}
#line 3649 "parser.cpp" /* yacc.c:1651  */
    break;

  case 154:
#line 1014 "sintactico.yy" /* yacc.c:1651  */
    {(yyval.nodito)=(yyvsp[-1].nodito);}
#line 3655 "parser.cpp" /* yacc.c:1651  */
    break;

  case 155:
#line 1016 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[-1].nodito);
             nodo *nod = new nodo("accesoarray","accesoarray",yylineno, columna);
             nodo *nombre = new nodo("id",(yyvsp[-2].TEXT),(yylsp[-2]).first_line,(yylsp[-2]).first_column);
             nod->hijos.append(*nombre);
             nod->hijos.append(*(yyvsp[-1].nodito));
             (yyval.nodito)->hijos.prepend(*nod);
         }
#line 3668 "parser.cpp" /* yacc.c:1651  */
    break;

  case 156:
#line 1025 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *nod = new nodo("acceso","acceso",yylineno, columna);
             nodo*nombre = new nodo("id","este",yylineno,columna);
             nod->hijos.append(*nombre);
             (yyval.nodito)->hijos.prepend(*nod);
         }
#line 3680 "parser.cpp" /* yacc.c:1651  */
    break;

  case 157:
#line 1033 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertacadena","convertacadena",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3689 "parser.cpp" /* yacc.c:1651  */
    break;

  case 158:
#line 1038 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = new nodo("convertaentero","convertaentero",yylineno,columna);
            (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3698 "parser.cpp" /* yacc.c:1651  */
    break;

  case 159:
#line 1043 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
         }
#line 3706 "parser.cpp" /* yacc.c:1651  */
    break;

  case 160:
#line 1052 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito)=(yyvsp[-2].nodito);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3715 "parser.cpp" /* yacc.c:1651  */
    break;

  case 161:
#line 1057 "sintactico.yy" /* yacc.c:1651  */
    {
        (yyval.nodito) = new nodo("lpar","lpar",yylineno,columna);
        (yyval.nodito)->hijos.append(*(yyvsp[0].nodito));
     }
#line 3724 "parser.cpp" /* yacc.c:1651  */
    break;

  case 162:
#line 1067 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",(yyvsp[-2].TEXT),yylineno, columna);
             (yyval.nodito)->hijos.append(*nombre); // nodo nombre
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             (yyval.nodito)->hijos.append(*par);
         }
#line 3736 "parser.cpp" /* yacc.c:1651  */
    break;

  case 163:
#line 1075 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("llamada","llamada",yylineno,columna);
             nodo * nombre = new nodo("id",(yyvsp[-3].TEXT),(yylsp[-3]).first_line,(yylsp[-3]).first_column);
             (yyval.nodito)->hijos.append(*nombre);
             (yyval.nodito)->hijos.append(*(yyvsp[-1].nodito));
         }
#line 3747 "parser.cpp" /* yacc.c:1651  */
    break;

  case 164:
#line 1082 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito)=(yyvsp[0].nodito);
             nodo *f= new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",(yyvsp[-3].TEXT),yylineno,columna);
             f->hijos.append(*nombre); //Nodo id
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             f->hijos.append(*par);
             (yyval.nodito)->hijos.prepend(*f);
         }
#line 3761 "parser.cpp" /* yacc.c:1651  */
    break;

  case 165:
#line 1092 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[0].nodito);
             nodo *f= new nodo("llamada","llamada",yylineno,columna);
             nodo *nombre = new nodo("id",(yyvsp[-4].TEXT),yylineno, columna);
             f->hijos.append(*nombre); // Nodo nombre
             f->hijos.append(*(yyvsp[-2].nodito));     // Parametors
             (yyval.nodito)->hijos.prepend(*f);
         }
#line 3774 "parser.cpp" /* yacc.c:1651  */
    break;

  case 166:
#line 1101 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) =(yyvsp[0].nodito);             
             nodo *f= new nodo("acceso","acceso",yylineno,columna);
             nodo *id = new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
             f->hijos.append(*id);
             (yyval.nodito)->hijos.prepend(*f);
        }
#line 3786 "parser.cpp" /* yacc.c:1651  */
    break;

  case 167:
#line 1112 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("aumento","++",yylineno, columna); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3792 "parser.cpp" /* yacc.c:1651  */
    break;

  case 168:
#line 1113 "sintactico.yy" /* yacc.c:1651  */
    {nodo *nod = new nodo("decremento","--",yylineno, columna); nod->add(*(yyvsp[-1].nodito)); (yyval.nodito)= nod;}
#line 3798 "parser.cpp" /* yacc.c:1651  */
    break;

  case 169:
#line 1118 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-2].nodito);
             nodo *nod= new nodo("acceso","acceso",yylineno, columna);
             nodo * nombre = new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
             nod->hijos.append(*nombre);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3810 "parser.cpp" /* yacc.c:1651  */
    break;

  case 170:
#line 1126 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = (yyvsp[-4].nodito);
            nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
            nodo *nod= new nodo("id",(yyvsp[-2].TEXT),yylineno, columna);
            acceso->hijos.append(*nod); // Add nodo con el id
            nodo *par = new nodo("lpar","lpar",yylineno,columna);
            acceso->hijos.append(*par); // Add lista parametros
            (yyval.nodito)->hijos.append(*acceso);
        }
#line 3824 "parser.cpp" /* yacc.c:1651  */
    break;

  case 171:
#line 1136 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = (yyvsp[-5].nodito);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-3].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*(yyvsp[-1].nodito)); // Add lista parametros
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 3837 "parser.cpp" /* yacc.c:1651  */
    break;

  case 172:
#line 1145 "sintactico.yy" /* yacc.c:1651  */
    {
            (yyval.nodito) = (yyvsp[-3].nodito);
            nodo *acceso = new nodo("accesoarray","accesoarray",yylineno, columna);
            nodo *nod= new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
            acceso->hijos.append(*nod); // Add nodo con el id
            acceso->hijos.append(*(yyvsp[0].nodito)); // Add dimensiones
            (yyval.nodito)->hijos.append(*acceso);

         }
#line 3851 "parser.cpp" /* yacc.c:1651  */
    break;

  case 173:
#line 1155 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *nod= new nodo("acceso","acceso",yylineno, columna);
             nodo * nombre = new nodo("id",(yyvsp[0].TEXT),yylineno, columna);
             nod->hijos.append(*nombre);
             (yyval.nodito)->hijos.append(*nod);
         }
#line 3863 "parser.cpp" /* yacc.c:1651  */
    break;

  case 174:
#line 1163 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-2].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             nodo *par = new nodo("lpar","lpar",yylineno,columna);
             acceso->hijos.append(*par); // Add lista parametros
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 3877 "parser.cpp" /* yacc.c:1651  */
    break;

  case 175:
#line 1173 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("llamada","llamada",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-3].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*(yyvsp[-1].nodito)); // Add lista parametros
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 3890 "parser.cpp" /* yacc.c:1651  */
    break;

  case 176:
#line 1182 "sintactico.yy" /* yacc.c:1651  */
    {
             (yyval.nodito) = new nodo("lacceso","lacceso",yylineno, columna);
             nodo *acceso = new nodo("accesoarray","accesoarray",yylineno, columna);
             nodo *nod= new nodo("id",(yyvsp[-1].TEXT),yylineno, columna);
             acceso->hijos.append(*nod); // Add nodo con el id
             acceso->hijos.append(*(yyvsp[0].nodito)); // Add dimensiones
             (yyval.nodito)->hijos.append(*acceso);
         }
#line 3903 "parser.cpp" /* yacc.c:1651  */
    break;


#line 3907 "parser.cpp" /* yacc.c:1651  */
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
#line 1190 "sintactico.yy" /* yacc.c:1910  */

