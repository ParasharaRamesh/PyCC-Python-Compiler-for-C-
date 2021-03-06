/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yaccrule.y" /* yacc.c:339  */

  #include "codegen.cpp"
  #define EMPTY -1
  using namespace std;
  extern FILE* yyin;
  extern int lineno;
  extern int colum;
  extern char *stream;
  int yylex(void);
  void yyerror(const char *);
  extern int nextInstr;
  int type;
  vector<YYSTYPE::BackpatchList*> breaklist;
  vector<YYSTYPE::BackpatchList*> continuelist;
  int break_current    = -1;
  int continue_current = -1;
  extern bool assign ;

#line 85 "rule.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "rule.h".  */
#ifndef YY_YY_RULE_H_INCLUDED
# define YY_YY_RULE_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    SWITCH = 261,
    CASE = 262,
    DEFAULT = 263,
    INT = 264,
    FLOAT = 265,
    BOOL = 266,
    UNSIGNED = 267,
    SIGNED = 268,
    ASSIGN = 269,
    PLUSEQ = 270,
    MINUSEQ = 271,
    TIMESEQ = 272,
    DIVIDEQ = 273,
    PLUS = 274,
    MINUS = 275,
    TIMES = 276,
    DIVIDE = 277,
    EXP = 278,
    IOR = 279,
    IAND = 280,
    INOT = 281,
    XOR = 282,
    OR = 283,
    AND = 284,
    NOT = 285,
    EQ = 286,
    NEQ = 287,
    LT = 288,
    LEQ = 289,
    GT = 290,
    GEQ = 291,
    LP = 292,
    RP = 293,
    LB = 294,
    RB = 295,
    COMMA = 296,
    SEMICOLON = 297,
    COLON = 298,
    DOUBLENUM = 299,
    INTNUM = 300,
    TRUE = 301,
    FALSE = 302,
    ID = 303,
    PLUSPLUS = 304,
    MINUSMINUS = 305,
    CONTINUE = 306,
    BREAK = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "yaccrule.y" /* yacc.c:355  */

  int type;
  struct marks{
    int instr;
  }mark;
  struct BackpatchList{
    int ins;
    BackpatchList *next;
  };
  struct info{
    char *addr;
    short  type;
    BackpatchList *tlist;
    BackpatchList *flist;
  }exp;
  struct nextL{
      int instr; /**Instruction number */
      BackpatchList *nextList; /**Linked list of Backpatch*/
  }List;
  /**
    Linked list of switch instruction which have to backpatch
  */
  struct switchL{
    int instr;     /**Instruction number*/
    int lineno;    /**Line number where this list was found*/
    switchL *next; /**Next pointer of switch list*/
    bool stype;    /**default or case statement*/
    char *val;     /**Case value*/
  };
  switchL *switchList;
  char *str;

#line 211 "rule.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RULE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "rule.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    90,    91,    95,    96,    97,   102,   114,
     118,   122,   123,   129,   132,   135,   138,   141,   144,   153,
     154,   161,   162,   165,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   179,   182,   186,   189,   197,   243,   244,
     247,   250,   255,   260,   263,   274,   283,   282,   309,   315,
     324,   336,   352,   354,   360,   366,   377,   391,   405,   420,
     437,   443,   443,   464,   470,   470,   492,   499,   510,   516,
     526,   532,   542,   548,   554,   563,   569,   579,   580,   581,
     582,   586,   592,   599,   609,   615,   622,   632,   638,   649,
     654,   661,   668,   673,   679,   685,   699,   704,   711,   721,
     735,   740,   751,   761,   766,   779,   795
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "SWITCH", "CASE",
  "DEFAULT", "INT", "FLOAT", "BOOL", "UNSIGNED", "SIGNED", "ASSIGN",
  "PLUSEQ", "MINUSEQ", "TIMESEQ", "DIVIDEQ", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "EXP", "IOR", "IAND", "INOT", "XOR", "OR", "AND", "NOT", "EQ",
  "NEQ", "LT", "LEQ", "GT", "GEQ", "LP", "RP", "LB", "RB", "COMMA",
  "SEMICOLON", "COLON", "DOUBLENUM", "INTNUM", "TRUE", "FALSE", "ID",
  "PLUSPLUS", "MINUSMINUS", "CONTINUE", "BREAK", "$accept", "Program",
  "translation-unit", "external-declaration", "function",
  "compound-statement", "statement-list", "statement", "expression-list",
  "declaration-list", "declaration", "var-type", "init-declarator-list",
  "selection-statement", "switch-statement", "default-statement",
  "case-list", "Next", "iteration-statement", "$@1", "break-marker",
  "continue-marker", "jump-statement", "expression",
  "assignment-expression", "logical-OR-expression", "$@2",
  "logical-AND-expression", "$@3", "inclusive-OR-expression",
  "exclusive-OR-expression", "inclusive-AND-expression",
  "equality-expression", "relational-expression", "RELOP",
  "additive-expression", "multiplicative-expression",
  "exponentiation-expression", "unary-expression", "postfix-expression",
  "primary-expression", "Literals", "marker", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,  -144,  -144,  -144,    57,    67,   108,   108,   108,   108,
     108,  -144,  -144,  -144,  -144,  -144,  -144,   108,   108,    20,
      -5,  -144,  -144,  -144,    79,  -144,   -25,    60,    81,     1,
      29,    23,    33,    37,    78,   126,    95,   111,  -144,    41,
      86,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,   125,  -144,  -144,  -144,  -144,  -144,    21,    -4,   127,
     108,  -144,   108,   108,   108,   108,   108,    46,    76,   108,
     108,   108,   108,   108,  -144,  -144,  -144,  -144,   108,   108,
     108,   108,   108,   108,  -144,  -144,  -144,    89,   108,    69,
      96,  -144,    81,    81,    81,    81,    81,    81,  -144,  -144,
      33,    37,    78,   126,   126,    95,   111,   111,  -144,  -144,
    -144,    81,    73,   115,   108,   108,    74,  -144,   108,    29,
      23,  -144,    80,   109,   137,  -144,    97,  -144,  -144,    79,
    -144,  -144,  -144,    81,   143,  -144,  -144,  -144,  -144,    74,
     108,   108,  -144,    81,   132,   144,   142,  -144,  -144,  -144,
     164,    74,   120,   140,   145,   177,   166,  -144,   146,  -144,
    -144,   179,   120,   177,  -144,    74,  -144,   147,   179,    74,
       6,  -144,     9,    74,    19
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    24,    29,    32,    27,    25,     0,     0,     0,     0,
       0,    19,   103,   102,   104,   105,    99,     0,     0,     0,
       2,     3,     5,     7,     6,    21,     0,     0,    52,    54,
      60,    63,    66,    68,    70,    72,    75,    81,    84,    87,
      89,    96,   100,    28,    31,    26,    30,    92,    93,    94,
      95,     0,    90,    91,     1,     4,    22,     0,    33,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    77,    78,     0,     0,
       0,     0,     0,     0,    97,    98,   101,    33,     0,     0,
       0,    23,    53,    55,    56,    57,    58,    59,   106,   106,
      67,    69,    71,    73,    74,    76,    82,    83,    85,    86,
      88,    34,     0,    35,     0,     0,    12,     8,     0,    62,
      65,    49,     0,     0,     0,    15,   106,    11,    13,    14,
      16,    17,    18,    36,     0,    45,    51,    50,     9,     0,
       0,     0,    10,    46,     0,     0,     0,   106,    48,    48,
       0,     0,     0,     0,     0,     0,    38,    47,     0,   106,
      45,    40,     0,    39,   106,    12,    37,     0,    41,    12,
     106,   106,   106,    12,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,   167,  -144,    82,  -108,  -127,    11,    18,
     -23,    28,  -144,  -144,  -144,    32,  -133,    31,  -144,  -144,
      43,  -144,  -144,  -144,   -10,  -144,  -144,    83,  -144,    84,
     124,   128,   129,   103,  -144,   117,    98,   -47,    64,  -144,
    -144,  -143,   -96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,   125,   126,   127,   128,   129,
      25,    57,    59,   130,   154,   155,   156,   141,   131,   145,
     150,   134,   132,    27,    28,    29,    67,    30,    68,    31,
      32,    33,    34,    35,    78,    36,    37,    38,    39,    40,
      41,    42,   139
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    56,   114,   115,     1,     2,     3,     4,     5,   158,
      88,    23,   142,   -42,     6,     7,   -43,   -43,    24,   167,
      54,     8,   161,    58,   157,     9,   -44,   -44,    26,   -61,
     168,    23,    10,    89,   108,   109,   110,    11,    24,    12,
      13,    14,    15,    16,    17,    18,   -42,    69,    26,   -43,
      92,   149,    93,    94,    95,    96,    97,   170,   -64,   -44,
      70,   172,    71,   165,    83,   174,    43,    44,   169,    87,
      47,    48,    49,    50,    98,   173,    45,    46,   111,   121,
     122,    52,    53,     1,     2,     3,     4,     5,     1,     2,
       3,     4,     5,     6,     7,    62,    63,    64,    65,    66,
       8,    60,    61,    88,     9,    99,    56,   112,   133,    72,
      73,    10,   116,   116,    79,    80,    11,   135,    12,    13,
      14,    15,    16,    17,    18,   123,   124,     6,     7,   118,
     143,   144,    81,    82,     8,    84,    85,   138,     9,    62,
      63,    64,    65,    66,   113,    10,    62,    63,    64,    65,
      66,   136,    12,    13,    14,    15,    16,    17,    18,    74,
      75,    76,    77,    86,    12,    13,    14,    15,    90,    91,
     146,   152,   153,   162,   153,   103,   104,   106,   107,   137,
     140,   148,   147,   159,   152,   160,   162,    55,   163,   164,
     171,   166,   151,   100,   117,   105,     0,   119,   101,   120,
     102
};

static const yytype_int16 yycheck[] =
{
      10,    24,    98,    99,     9,    10,    11,    12,    13,   152,
      14,     0,   139,     7,    19,    20,     7,     8,     0,   162,
       0,    26,   155,    48,   151,    30,     7,     8,     0,    28,
     163,    20,    37,    37,    81,    82,    83,    42,    20,    44,
      45,    46,    47,    48,    49,    50,    40,    24,    20,    40,
      60,   147,    62,    63,    64,    65,    66,   165,    29,    40,
      27,   169,    25,   159,    23,   173,     9,    10,   164,    48,
       6,     7,     8,     9,    28,   171,     9,    10,    88,     5,
       6,    17,    18,     9,    10,    11,    12,    13,     9,    10,
      11,    12,    13,    19,    20,    14,    15,    16,    17,    18,
      26,    41,    42,    14,    30,    29,   129,    38,   118,    31,
      32,    37,    39,    39,    19,    20,    42,    37,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    19,    20,    14,
     140,   141,    21,    22,    26,    49,    50,    40,    30,    14,
      15,    16,    17,    18,    48,    37,    14,    15,    16,    17,
      18,    42,    44,    45,    46,    47,    48,    49,    50,    33,
      34,    35,    36,    38,    44,    45,    46,    47,    41,    42,
      38,     7,     8,     7,     8,    72,    73,    79,    80,    42,
      37,    39,    38,    43,     7,    40,     7,    20,   156,    43,
      43,   160,   149,    69,   112,    78,    -1,   114,    70,   115,
      71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    19,    20,    26,    30,
      37,    42,    44,    45,    46,    47,    48,    49,    50,    54,
      55,    56,    57,    61,    62,    63,    64,    76,    77,    78,
      80,    82,    83,    84,    85,    86,    88,    89,    90,    91,
      92,    93,    94,     9,    10,     9,    10,    91,    91,    91,
      91,    77,    91,    91,     0,    56,    63,    64,    48,    65,
      41,    42,    14,    15,    16,    17,    18,    79,    81,    24,
      27,    25,    31,    32,    33,    34,    35,    36,    87,    19,
      20,    21,    22,    23,    49,    50,    38,    48,    14,    37,
      41,    42,    77,    77,    77,    77,    77,    77,    28,    29,
      83,    84,    85,    86,    86,    88,    89,    89,    90,    90,
      90,    77,    38,    48,    95,    95,    39,    58,    14,    80,
      82,     5,     6,    51,    52,    58,    59,    60,    61,    62,
      66,    71,    75,    77,    74,    37,    42,    42,    40,    95,
      37,    70,    60,    77,    77,    72,    38,    38,    39,    95,
      73,    73,     7,     8,    67,    68,    69,    60,    94,    43,
      40,    69,     7,    68,    43,    95,    70,    94,    69,    95,
      59,    43,    59,    95,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    57,    58,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    66,    67,    67,
      67,    67,    68,    69,    69,    70,    72,    71,    73,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      78,    79,    78,    80,    81,    80,    82,    82,    83,    83,
      84,    84,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    88,    88,    88,    89,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    92,    93,
      93,    93,    94,    94,    94,    94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     5,     3,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     3,     1,     1,     2,     1,     2,     1,
       2,     2,     1,     1,     3,     3,     5,    10,     1,     2,
       2,     3,     4,     5,     6,     0,     0,     9,     0,     0,
       2,     2,     1,     3,     1,     3,     3,     3,     3,     3,
       1,     0,     5,     1,     0,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     1,
       1,     3,     1,     1,     1,     1,     0
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 86 "yaccrule.y" /* yacc.c:1646  */
    {}
#line 1450 "rule.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "yaccrule.y" /* yacc.c:1646  */
    {}
#line 1456 "rule.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "yaccrule.y" /* yacc.c:1646  */
    {}
#line 1462 "rule.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "yaccrule.y" /* yacc.c:1646  */
    {/**Function definition*/}
#line 1468 "rule.c" /* yacc.c:1646  */
    break;

  case 6:
#line 96 "yaccrule.y" /* yacc.c:1646  */
    {/** Global declaration*/}
#line 1474 "rule.c" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "yaccrule.y" /* yacc.c:1646  */
    {/*Gloabal initiliazation*/}
#line 1480 "rule.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "yaccrule.y" /* yacc.c:1646  */
    {
  	  /*ResetSymbolTable();*/
	  backpatch((yyvsp[0].List).nextList,nextInstr);
	  genCode("ret",0);
  }
#line 1490 "rule.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.List).nextList = (yyvsp[-1].List).nextList;}
#line 1496 "rule.c" /* yacc.c:1646  */
    break;

  case 10:
#line 118 "yaccrule.y" /* yacc.c:1646  */
    {
    backpatch((yyvsp[-2].List).nextList,(yyvsp[-1].mark).instr);
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1505 "rule.c" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.List).nextList = (yyvsp[0].List).nextList;}
#line 1511 "rule.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "yaccrule.y" /* yacc.c:1646  */
    {/**Suffice for empty block statement*/
       (yyval.List).nextList = NULL;
  }
#line 1519 "rule.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.List).nextList=NULL;
  }
#line 1527 "rule.c" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.List).nextList=NULL;
  }
#line 1535 "rule.c" /* yacc.c:1646  */
    break;

  case 15:
#line 135 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1543 "rule.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1551 "rule.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.List).nextList = (yyvsp[0].List).nextList;
  }
#line 1559 "rule.c" /* yacc.c:1646  */
    break;

  case 18:
#line 144 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.List).nextList = NULL;
  }
#line 1567 "rule.c" /* yacc.c:1646  */
    break;

  case 19:
#line 153 "yaccrule.y" /* yacc.c:1646  */
    { }
#line 1573 "rule.c" /* yacc.c:1646  */
    break;

  case 20:
#line 154 "yaccrule.y" /* yacc.c:1646  */
    {}
#line 1579 "rule.c" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "yaccrule.y" /* yacc.c:1646  */
    {}
#line 1585 "rule.c" /* yacc.c:1646  */
    break;

  case 22:
#line 162 "yaccrule.y" /* yacc.c:1646  */
    {}
#line 1591 "rule.c" /* yacc.c:1646  */
    break;

  case 23:
#line 165 "yaccrule.y" /* yacc.c:1646  */
    {}
#line 1597 "rule.c" /* yacc.c:1646  */
    break;

  case 24:
#line 168 "yaccrule.y" /* yacc.c:1646  */
    {type = 1;}
#line 1603 "rule.c" /* yacc.c:1646  */
    break;

  case 25:
#line 169 "yaccrule.y" /* yacc.c:1646  */
    {type = 2;}
#line 1609 "rule.c" /* yacc.c:1646  */
    break;

  case 26:
#line 170 "yaccrule.y" /* yacc.c:1646  */
    {type= 3;}
#line 1615 "rule.c" /* yacc.c:1646  */
    break;

  case 27:
#line 171 "yaccrule.y" /* yacc.c:1646  */
    {type = 4;}
#line 1621 "rule.c" /* yacc.c:1646  */
    break;

  case 28:
#line 172 "yaccrule.y" /* yacc.c:1646  */
    { type=5;}
#line 1627 "rule.c" /* yacc.c:1646  */
    break;

  case 29:
#line 173 "yaccrule.y" /* yacc.c:1646  */
    {type=6;}
#line 1633 "rule.c" /* yacc.c:1646  */
    break;

  case 30:
#line 174 "yaccrule.y" /* yacc.c:1646  */
    {type=7; }
#line 1639 "rule.c" /* yacc.c:1646  */
    break;

  case 31:
#line 175 "yaccrule.y" /* yacc.c:1646  */
    {type=8; }
#line 1645 "rule.c" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "yaccrule.y" /* yacc.c:1646  */
    { type=9;}
#line 1651 "rule.c" /* yacc.c:1646  */
    break;

  case 33:
#line 179 "yaccrule.y" /* yacc.c:1646  */
    {
  	InsertId((yyvsp[0].exp).addr,lineno,type);
  }
#line 1659 "rule.c" /* yacc.c:1646  */
    break;

  case 34:
#line 182 "yaccrule.y" /* yacc.c:1646  */
    {
  	InsertId((yyvsp[-2].exp).addr,lineno,type);
  	genCode((yyvsp[-2].exp).addr,(yyvsp[0].exp).addr);
  }
#line 1668 "rule.c" /* yacc.c:1646  */
    break;

  case 35:
#line 186 "yaccrule.y" /* yacc.c:1646  */
    {
  	InsertId((yyvsp[0].exp).addr,lineno,type);
  }
#line 1676 "rule.c" /* yacc.c:1646  */
    break;

  case 36:
#line 189 "yaccrule.y" /* yacc.c:1646  */
    {
  	InsertId((yyvsp[-2].exp).addr,lineno,type);
  	genCode((yyvsp[-2].exp).addr,(yyvsp[0].exp).addr);
  }
#line 1685 "rule.c" /* yacc.c:1646  */
    break;

  case 37:
#line 197 "yaccrule.y" /* yacc.c:1646  */
    {
	  YYSTYPE::switchL *l=NULL;
	  YYSTYPE::switchL *ll;
	  int in=nextInstr;
	  while((yyvsp[-2].switchList)!=NULL){
	    if((yyvsp[-2].switchList)->stype == true){
	      ll = (yyvsp[-2].switchList);
	      genCode("if",(yyvsp[-6].exp).addr," == ",(yyvsp[-2].switchList)->val,"goto",(yyvsp[-2].switchList)->instr);
	      delete ll;
	    }
	    else{
	       l = (yyvsp[-2].switchList);
	    }
	    (yyvsp[-2].switchList)=(yyvsp[-2].switchList)->next;
	  }
	  if(l!=NULL){
	    genCode("goto",l->instr);
	    delete l;
	  }
	  backpatch((yyvsp[-7].List).nextList,in); //Backpatch start of switch-statement
	  backpatch((yyvsp[0].List).nextList,nextInstr);//Backpatch end of switch-statement
	  backpatch(breaklist[break_current],nextInstr); //Backpatch break statement(s)
	  break_current--;
	}
#line 1714 "rule.c" /* yacc.c:1646  */
    break;

  case 38:
#line 243 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.switchList)=(yyvsp[0].switchList);}
#line 1720 "rule.c" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "yaccrule.y" /* yacc.c:1646  */
    {
  	(yyval.switchList) = mergeSwitchList((yyvsp[-1].switchList),(yyvsp[0].switchList));
  }
#line 1728 "rule.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "yaccrule.y" /* yacc.c:1646  */
    {
  	(yyval.switchList) = mergeSwitchList((yyvsp[-1].switchList),(yyvsp[0].switchList));
  }
#line 1736 "rule.c" /* yacc.c:1646  */
    break;

  case 41:
#line 250 "yaccrule.y" /* yacc.c:1646  */
    {
  	(yyval.switchList) = mergeSwitchList(mergeSwitchList((yyvsp[-2].switchList),(yyvsp[-1].switchList)),(yyvsp[0].switchList));
  }
#line 1744 "rule.c" /* yacc.c:1646  */
    break;

  case 42:
#line 255 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.switchList)=makeList((yyvsp[-1].mark).instr,false,NULL,EMPTY);
  }
#line 1752 "rule.c" /* yacc.c:1646  */
    break;

  case 43:
#line 260 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.switchList)=makeList((yyvsp[-1].mark).instr,true,(yyvsp[-3].exp).addr,lineno);
  }
#line 1760 "rule.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.switchList) = makeList((yyvsp[-1].mark).instr,true,(yyvsp[-3].exp).addr,lineno);
    int line;
    if( (line=IsDuplicateCaseLabel((yyvsp[-5].switchList),(yyvsp[-3].exp).addr)) != -1 ){
      AddError("duplicate case label",lineno,ERROR);
      AddError("previously used here",line,ERROR);
    }
    (yyval.switchList) = mergeSwitchList((yyvsp[-5].switchList),(yyval.switchList));
  }
#line 1774 "rule.c" /* yacc.c:1646  */
    break;

  case 45:
#line 274 "yaccrule.y" /* yacc.c:1646  */
    {
  (yyval.List).nextList = makeList(nextInstr);
  genCode("goto",EMPTY);
  (yyval.List).instr = nextInstr;
}
#line 1784 "rule.c" /* yacc.c:1646  */
    break;

  case 46:
#line 283 "yaccrule.y" /* yacc.c:1646  */
    {
    /**
      Special case when programmar has used
      while(a)
      while(a+b)
    */
    if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist  ==  NULL ){
      (yyvsp[0].exp).tlist = makeList(nextInstr);
      genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
      (yyvsp[0].exp).flist = makeList(nextInstr);
      genCode("goto",EMPTY);
    }
  }
#line 1802 "rule.c" /* yacc.c:1646  */
    break;

  case 47:
#line 296 "yaccrule.y" /* yacc.c:1646  */
    {
    backpatch((yyvsp[0].List).nextList,(yyvsp[-7].mark).instr);
    backpatch((yyvsp[-5].exp).tlist,(yyvsp[-2].mark).instr);
    backpatch(continuelist[continue_current],(yyvsp[-7].mark).instr);
    (yyval.List).nextList = (yyvsp[-5].exp).flist;
    genCode("goto",(yyvsp[-7].mark).instr);
    backpatch(breaklist[break_current],nextInstr);
    break_current--;
    continue_current--;
}
#line 1817 "rule.c" /* yacc.c:1646  */
    break;

  case 48:
#line 309 "yaccrule.y" /* yacc.c:1646  */
    {
  break_current++;
  breaklist.push_back(NULL);
}
#line 1826 "rule.c" /* yacc.c:1646  */
    break;

  case 49:
#line 315 "yaccrule.y" /* yacc.c:1646  */
    {
(yyval.mark).instr = nextInstr;
continue_current++;
continuelist.push_back(NULL);
}
#line 1836 "rule.c" /* yacc.c:1646  */
    break;

  case 50:
#line 324 "yaccrule.y" /* yacc.c:1646  */
    {
    if(break_current!=EMPTY){
      genCode("goto",EMPTY);
      if( (breaklist.size() == 0) || ( (signed)breaklist.size() == break_current-1) )
        breaklist.push_back(makeList(nextInstr-1));
      else
        breaklist[break_current]=mergeList(makeList(nextInstr-1),breaklist[break_current]);
    }
    else{
      AddError("break is not in loop or switch statement",lineno,ERROR);
    }
  }
#line 1853 "rule.c" /* yacc.c:1646  */
    break;

  case 51:
#line 336 "yaccrule.y" /* yacc.c:1646  */
    {
    if(continue_current!=-1){
      genCode("goto",EMPTY);
      if( (continuelist.size() == 0) || ( (signed)continuelist.size() == continue_current-1) )
        continuelist.push_back(makeList(nextInstr-1));
      else
        continuelist[continue_current]=mergeList(makeList(nextInstr-1),continuelist[continue_current]);
    }
    else{
      AddError("continue is not in loop statement",lineno,ERROR);
    }
  }
#line 1870 "rule.c" /* yacc.c:1646  */
    break;

  case 52:
#line 352 "yaccrule.y" /* yacc.c:1646  */
    {
  }
#line 1877 "rule.c" /* yacc.c:1646  */
    break;

  case 53:
#line 354 "yaccrule.y" /* yacc.c:1646  */
    {
  }
#line 1884 "rule.c" /* yacc.c:1646  */
    break;

  case 54:
#line 360 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
  }
#line 1895 "rule.c" /* yacc.c:1646  */
    break;

  case 55:
#line 366 "yaccrule.y" /* yacc.c:1646  */
    {
        /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        genCode((yyvsp[-2].exp).addr,(yyvsp[0].exp).addr);
        (yyval.exp).flist = NULL;
        (yyval.exp).tlist = NULL;
  }
#line 1911 "rule.c" /* yacc.c:1646  */
    break;

  case 56:
#line 377 "yaccrule.y" /* yacc.c:1646  */
    {
        /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).flist = NULL;
        (yyval.exp).tlist = NULL;
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"+",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 1930 "rule.c" /* yacc.c:1646  */
    break;

  case 57:
#line 391 "yaccrule.y" /* yacc.c:1646  */
    {
       (yyval.exp).flist = NULL;
       (yyval.exp).tlist = NULL;
        /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"-",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 1949 "rule.c" /* yacc.c:1646  */
    break;

  case 58:
#line 405 "yaccrule.y" /* yacc.c:1646  */
    {
       (yyval.exp).flist = NULL;
       (yyval.exp).tlist = NULL;

       /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"*",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 1969 "rule.c" /* yacc.c:1646  */
    break;

  case 59:
#line 420 "yaccrule.y" /* yacc.c:1646  */
    {
       (yyval.exp).flist = NULL;
       (yyval.exp).tlist = NULL;
       /**
          Check for temporary name if it's temp then raise an error
        */
        if((yyvsp[-2].exp).addr[0] == '_' && (yyvsp[-2].exp).addr[1] == '_'){
          AddError((char*)"lvalue required as left operand of assignment",lineno,ERROR);
        }
        (yyval.exp).addr  = newTemp();
        genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"/",(yyvsp[0].exp).addr);
        genCode((yyvsp[-2].exp).addr,(yyval.exp).addr );
        (yyval.exp).addr  = (yyvsp[-2].exp).addr;
  }
#line 1988 "rule.c" /* yacc.c:1646  */
    break;

  case 60:
#line 437 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 1999 "rule.c" /* yacc.c:1646  */
    break;

  case 61:
#line 443 "yaccrule.y" /* yacc.c:1646  */
    {
	    if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
	        genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
	            genCode("goto",EMPTY);
	            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
	            (yyvsp[0].exp).flist = makeList(nextInstr-1);
	    }
    }
#line 2012 "rule.c" /* yacc.c:1646  */
    break;

  case 62:
#line 450 "yaccrule.y" /* yacc.c:1646  */
    {
      if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
        genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
      }
      backpatch((yyvsp[-4].exp).flist,(yyvsp[-1].mark).instr);
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = mergeList((yyvsp[-4].exp).tlist,(yyvsp[0].exp).tlist);
  }
#line 2028 "rule.c" /* yacc.c:1646  */
    break;

  case 63:
#line 464 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 2039 "rule.c" /* yacc.c:1646  */
    break;

  case 64:
#line 470 "yaccrule.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
            genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
    	}

    }
#line 2053 "rule.c" /* yacc.c:1646  */
    break;

  case 65:
#line 478 "yaccrule.y" /* yacc.c:1646  */
    {
      if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
            genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
      }
      backpatch((yyvsp[-4].exp).tlist,(yyvsp[-1].mark).instr);
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
      (yyval.exp).flist = mergeList((yyvsp[-4].exp).flist,(yyvsp[0].exp).flist);
  }
#line 2069 "rule.c" /* yacc.c:1646  */
    break;

  case 66:
#line 492 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr  = (yyvsp[0].exp).addr;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).type  = (yyvsp[0].exp).type;
      (yyval.exp).flist = (yyvsp[0].exp).flist;
      (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 2081 "rule.c" /* yacc.c:1646  */
    break;

  case 67:
#line 499 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr  = newTemp();
      (yyval.exp).type  = (yyvsp[-2].exp).type;
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
      genCode((yyval.exp).addr ,(yyvsp[-2].exp).addr,"|",(yyvsp[0].exp).addr);
  }
#line 2093 "rule.c" /* yacc.c:1646  */
    break;

  case 68:
#line 510 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr  = (yyvsp[0].exp).addr;
    (yyval.exp).type  = (yyvsp[0].exp).type;
    (yyval.exp).flist = (yyvsp[0].exp).flist;
    (yyval.exp).tlist = (yyvsp[0].exp).tlist;
}
#line 2104 "rule.c" /* yacc.c:1646  */
    break;

  case 69:
#line 516 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr  = newTemp();
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
    genCode((yyval.exp).addr ,(yyvsp[-2].exp).addr,"XOR",(yyvsp[0].exp).addr);
}
#line 2115 "rule.c" /* yacc.c:1646  */
    break;

  case 70:
#line 526 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr  = (yyvsp[0].exp).addr;
    (yyval.exp).type  = (yyvsp[0].exp).type;
    (yyval.exp).flist = (yyvsp[0].exp).flist;
    (yyval.exp).tlist = (yyvsp[0].exp).tlist;
  }
#line 2126 "rule.c" /* yacc.c:1646  */
    break;

  case 71:
#line 532 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr  = newTemp();
      (yyval.exp).flist = NULL;
      (yyval.exp).tlist = NULL;
      genCode((yyval.exp).addr ,(yyvsp[-2].exp).addr,"&",(yyvsp[0].exp).addr);
  }
#line 2137 "rule.c" /* yacc.c:1646  */
    break;

  case 72:
#line 542 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).type   = (yyvsp[0].exp).type;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2148 "rule.c" /* yacc.c:1646  */
    break;

  case 73:
#line 548 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[-2].exp).addr," == ",(yyvsp[0].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
#line 2159 "rule.c" /* yacc.c:1646  */
    break;

  case 74:
#line 554 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[-2].exp).addr,"!=",(yyvsp[0].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
#line 2170 "rule.c" /* yacc.c:1646  */
    break;

  case 75:
#line 563 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).type   = (yyvsp[0].exp).type;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2181 "rule.c" /* yacc.c:1646  */
    break;

  case 76:
#line 569 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).tlist = makeList(nextInstr);
      (yyval.exp).flist = makeList(nextInstr+1);
      genCode("if",(yyvsp[-2].exp).addr,(yyvsp[-1].str),(yyvsp[0].exp).addr,"goto",EMPTY);
      genCode("goto",EMPTY);
  }
#line 2192 "rule.c" /* yacc.c:1646  */
    break;

  case 77:
#line 579 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.str)=(char*)">";}
#line 2198 "rule.c" /* yacc.c:1646  */
    break;

  case 78:
#line 580 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.str) =(char*)">=";}
#line 2204 "rule.c" /* yacc.c:1646  */
    break;

  case 79:
#line 581 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.str) =(char*)"<";}
#line 2210 "rule.c" /* yacc.c:1646  */
    break;

  case 80:
#line 582 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.str) =(char*)"<=";}
#line 2216 "rule.c" /* yacc.c:1646  */
    break;

  case 81:
#line 586 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).type   = (yyvsp[0].exp).type;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2227 "rule.c" /* yacc.c:1646  */
    break;

  case 82:
#line 592 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"+",(yyvsp[0].exp).addr);
  }
#line 2239 "rule.c" /* yacc.c:1646  */
    break;

  case 83:
#line 599 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"-",(yyvsp[0].exp).addr);
  }
#line 2251 "rule.c" /* yacc.c:1646  */
    break;

  case 84:
#line 609 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).type   = (yyvsp[0].exp).type;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2262 "rule.c" /* yacc.c:1646  */
    break;

  case 85:
#line 615 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"*",(yyvsp[0].exp).addr);
  }
#line 2274 "rule.c" /* yacc.c:1646  */
    break;

  case 86:
#line 622 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).type   = (yyvsp[-2].exp).type;
      (yyval.exp).tlist  = NULL;
      (yyval.exp).flist  = NULL;
      genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"/",(yyvsp[0].exp).addr);
  }
#line 2286 "rule.c" /* yacc.c:1646  */
    break;

  case 87:
#line 632 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).type   = (yyvsp[0].exp).type;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
  }
#line 2297 "rule.c" /* yacc.c:1646  */
    break;

  case 88:
#line 638 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).type   = (yyvsp[-2].exp).type;
    (yyval.exp).tlist  = NULL;
    (yyval.exp).flist  = NULL;
    genCode((yyval.exp).addr  ,(yyvsp[-2].exp).addr,"@",(yyvsp[0].exp).addr);
  }
#line 2309 "rule.c" /* yacc.c:1646  */
    break;

  case 89:
#line 649 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2319 "rule.c" /* yacc.c:1646  */
    break;

  case 90:
#line 654 "yaccrule.y" /* yacc.c:1646  */
    {
     (yyval.exp).addr   = newTemp();
     (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
     (yyval.exp).flist  = (yyvsp[0].exp).flist;
     genCode((yyval.exp).addr ,(yyvsp[0].exp).addr,"+","1");
     genCode((yyvsp[0].exp).addr,(yyval.exp).addr );
  }
#line 2331 "rule.c" /* yacc.c:1646  */
    break;

  case 91:
#line 661 "yaccrule.y" /* yacc.c:1646  */
    {
     (yyval.exp).addr   = newTemp();
     (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
     (yyval.exp).flist  = (yyvsp[0].exp).flist;
     genCode((yyval.exp).addr ,(yyvsp[0].exp).addr,"-","1");
     genCode((yyvsp[0].exp).addr,(yyval.exp).addr );
  }
#line 2343 "rule.c" /* yacc.c:1646  */
    break;

  case 92:
#line 668 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = (yyvsp[0].exp).addr;
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
    }
#line 2353 "rule.c" /* yacc.c:1646  */
    break;

  case 93:
#line 673 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
      genCode((yyval.exp).addr ,"-1","*",(yyvsp[0].exp).addr);
  }
#line 2364 "rule.c" /* yacc.c:1646  */
    break;

  case 94:
#line 679 "yaccrule.y" /* yacc.c:1646  */
    {
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
      (yyval.exp).flist  = (yyvsp[0].exp).flist;
      genCode((yyval.exp).addr ,"~",(yyvsp[0].exp).addr);
  }
#line 2375 "rule.c" /* yacc.c:1646  */
    break;

  case 95:
#line 685 "yaccrule.y" /* yacc.c:1646  */
    {
      if((yyvsp[0].exp).tlist  ==  NULL  && (yyvsp[0].exp).flist   ==  NULL ){
        genCode("if",(yyvsp[0].exp).addr,"!=","0","goto",EMPTY);
            genCode("goto",EMPTY);
            (yyvsp[0].exp).tlist = makeList(nextInstr-2);
            (yyvsp[0].exp).flist = makeList(nextInstr-1);
    }
      (yyval.exp).addr   = newTemp();
      (yyval.exp).tlist  = (yyvsp[0].exp).flist;
      (yyval.exp).flist  = (yyvsp[0].exp).tlist;
  }
#line 2391 "rule.c" /* yacc.c:1646  */
    break;

  case 96:
#line 699 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2401 "rule.c" /* yacc.c:1646  */
    break;

  case 97:
#line 704 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).tlist  = (yyvsp[-1].exp).tlist;
    (yyval.exp).flist  = (yyvsp[-1].exp).flist;
    genCode((yyval.exp).addr ,(yyvsp[-1].exp).addr);
    genCode((yyvsp[-1].exp).addr,(yyval.exp).addr ,"+","1");
  }
#line 2413 "rule.c" /* yacc.c:1646  */
    break;

  case 98:
#line 711 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = newTemp();
    (yyval.exp).tlist  = (yyvsp[-1].exp).tlist;
    (yyval.exp).flist  = (yyvsp[-1].exp).flist;
    genCode((yyval.exp).addr ,(yyvsp[-1].exp).addr);
    genCode((yyvsp[-1].exp).addr,(yyval.exp).addr ,"-","1");
  }
#line 2425 "rule.c" /* yacc.c:1646  */
    break;

  case 99:
#line 721 "yaccrule.y" /* yacc.c:1646  */
    {
  (yyval.exp).addr   = (yyvsp[0].exp).addr;
  (yyval.exp).tlist  = NULL;
  (yyval.exp).flist  = NULL;
  if(!IsPresent((yyvsp[0].exp).addr)){
    char *errmsg =  new char[256];
    strcpy(errmsg,"'");
    strcat(errmsg,(yyval.exp).addr);
    strcat(errmsg,"' was not declared");
    AddError(errmsg,lineno,ERROR);
    delete errmsg;
  }

 }
#line 2444 "rule.c" /* yacc.c:1646  */
    break;

  case 100:
#line 735 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr   = (yyvsp[0].exp).addr;
    (yyval.exp).tlist  = (yyvsp[0].exp).tlist;
    (yyval.exp).flist  = (yyvsp[0].exp).flist;
  }
#line 2454 "rule.c" /* yacc.c:1646  */
    break;

  case 101:
#line 740 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr  = (yyvsp[-1].exp).addr;
    (yyval.exp).flist  = (yyvsp[-1].exp).flist;
    (yyval.exp).tlist  = (yyvsp[-1].exp).tlist;
  }
#line 2464 "rule.c" /* yacc.c:1646  */
    break;

  case 102:
#line 751 "yaccrule.y" /* yacc.c:1646  */
    {
    /**
      This temp contains value of the const
      e.g. 5
      temp->5
    */
    (yyval.exp).type  = INTNUM;
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
  }
#line 2479 "rule.c" /* yacc.c:1646  */
    break;

  case 103:
#line 761 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).type  = DOUBLENUM;
    (yyval.exp).flist = NULL;
    (yyval.exp).tlist = NULL;
  }
#line 2489 "rule.c" /* yacc.c:1646  */
    break;

  case 104:
#line 766 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr = new char[2];
    (yyval.exp).addr = (char*)"1";
    (yyval.exp).type = BOOL;
    if(!assign){
    	 (yyval.exp).tlist = makeList(nextInstr);
	     (yyval.exp).flist = NULL;
	     genCode("goto",EMPTY);
    }
    else{
		assign = false;
	}
  }
#line 2507 "rule.c" /* yacc.c:1646  */
    break;

  case 105:
#line 779 "yaccrule.y" /* yacc.c:1646  */
    {
    (yyval.exp).addr = new char[2];
    (yyval.exp).addr = (char*)"0";
    (yyval.exp).type   = BOOL;
    if(!assign){
	    (yyval.exp).flist = makeList(nextInstr);
	    (yyval.exp).tlist = NULL;
	    genCode("goto",EMPTY);
	}
	else{
		assign = false;
	}
  }
#line 2525 "rule.c" /* yacc.c:1646  */
    break;

  case 106:
#line 795 "yaccrule.y" /* yacc.c:1646  */
    {(yyval.mark).instr = nextInstr;}
#line 2531 "rule.c" /* yacc.c:1646  */
    break;


#line 2535 "rule.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 797 "yaccrule.y" /* yacc.c:1906  */


void yyerror(const char *s){
  AddError((char*)" ... is missing",lineno,ERROR);
}

int main(int argc,char *argv[ ]){

  FILE* fp=NULL;
  if(argc<2){
    fprintf(stderr,"No input file\n");
    return 0;
  }
  if(argc == 2){
    fp=fopen(argv[1],"r");
  }
  if(fp==NULL){
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 0;
  }
  yyin=fp;
  InitializeSymbolTable();
  Error = NULL;

  while(!feof(yyin)){
    yyparse();
  }
  fclose(fp);

  DeleteSymbolTable();

  if(Error  ==  NULL ) printCode();
  else{
    printError();
  }
  return 0;
}
