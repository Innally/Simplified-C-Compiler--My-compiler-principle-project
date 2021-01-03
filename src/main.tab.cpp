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
#line 1 "src/main.y" /* yacc.c:339  */

    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    int yylex();
    int yyerror( char const * );

    extern symbol_table symtbl;

#line 77 "src/main.tab.cpp" /* yacc.c:339  */

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
   by #include "main.tab.h".  */
#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
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
    RETURN = 261,
    FOR = 262,
    T_CHAR = 263,
    T_INT = 264,
    T_STRING = 265,
    T_BOOL = 266,
    T_VOID = 267,
    LOP_ASSIGN = 268,
    ADDSELF = 269,
    MINUSSELF = 270,
    SEMICOLON = 271,
    LPAREN = 272,
    RPAREN = 273,
    LBRACE = 274,
    RBRACE = 275,
    COMMA = 276,
    IDENTIFIER = 277,
    INTEGER = 278,
    CHAR = 279,
    BOOL = 280,
    STRING = 281,
    TRUE = 282,
    FALSE = 283,
    ADD = 284,
    MINUS = 285,
    MULT = 286,
    DIV = 287,
    MOD = 288,
    ADDADD = 289,
    MINUSMINUS = 290,
    EQUAL = 291,
    NOT = 292,
    NOTEQUAL = 293,
    GREATER = 294,
    SMALLER = 295,
    GORE = 296,
    SORE = 297,
    OR = 298,
    AND = 299,
    PRINTF = 300,
    SCANF = 301,
    REFERENCE = 302,
    POINTER = 303,
    LOWER_THEN_ELSE = 304,
    UMINUS = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 179 "src/main.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    51,    52,    57,    58,    59,    60,    61,
      62,    63,    67,    68,    69,    70,    71,    72,    76,   103,
     137,   141,   166,   167,   171,   179,   188,   197,   205,   216,
     223,   230,   233,   236,   239,   242,   252,   262,   271,   280,
     290,   291,   292,   298,   299,   300,   301,   302,   307,   315,
     325,   335,   346,   353,   361,   370,   371,   372,   382,   383,
     384,   393,   400,   408,   417,   426,   435,   444,   454,   463,
     471,   479,   487,   496,   504,   514,   523
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "RETURN", "FOR",
  "T_CHAR", "T_INT", "T_STRING", "T_BOOL", "T_VOID", "LOP_ASSIGN",
  "ADDSELF", "MINUSSELF", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "COMMA", "IDENTIFIER", "INTEGER", "CHAR", "BOOL", "STRING",
  "TRUE", "FALSE", "ADD", "MINUS", "MULT", "DIV", "MOD", "ADDADD",
  "MINUSMINUS", "EQUAL", "NOT", "NOTEQUAL", "GREATER", "SMALLER", "GORE",
  "SORE", "OR", "AND", "PRINTF", "SCANF", "REFERENCE", "POINTER",
  "LOWER_THEN_ELSE", "UMINUS", "$accept", "program", "statements",
  "statement", "instruction", "declaration", "block",
  "fucntion_declaration", "IDENTIFIERS", "assign", "expr", "T", "if_else",
  "while", "for", "return", "bool_statment", "bool_expr", "printf",
  "scanf", YY_NULLPTR
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
     305
};
# endif

#define YYPACT_NINF -110

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-110)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     207,   129,   129,   286,   -11,  -110,  -110,  -110,  -110,  -110,
    -110,   302,   207,  -110,  -110,  -110,  -110,  -110,  -110,   314,
     174,   314,   314,   -15,     9,   207,  -110,  -110,    -5,  -110,
    -110,    -6,    -3,   257,     2,  -110,  -110,  -110,  -110,    -8,
     389,     1,    12,   358,   117,   117,  -110,   326,    -4,   238,
    -110,   342,    -2,   162,    88,     4,   374,   200,    16,    16,
    -110,  -110,  -110,  -110,     7,  -110,   314,   314,   314,   314,
     314,   314,   314,   314,   314,  -110,  -110,   314,   314,   314,
     314,   314,   314,   314,    10,    -6,  -110,   174,   174,   174,
     174,   174,   174,   174,  -110,  -110,    26,   207,  -110,  -110,
     238,  -110,  -110,  -110,   390,  -110,    16,    16,    16,    16,
       4,     4,     4,     4,     4,   248,   248,   248,   248,   248,
     248,    16,   314,   405,   389,    61,  -110,  -110,  -110,  -110,
     200,   207,   314,    16,  -110,  -110,    33,    29,   207,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    44,    43,    46,    45,    47,
       5,     0,     0,    22,    32,    33,    34,    58,    59,     0,
       0,     0,     0,     0,     0,     2,     3,     6,     0,     9,
      17,    29,     0,     0,     0,     7,     8,    10,    11,     0,
      56,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      42,     0,     0,     0,     0,    30,    62,    61,    75,    76,
      31,     1,     4,    12,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,     0,
       0,     0,     0,     0,    22,    19,    16,     0,     0,     0,
       0,     0,     0,     0,    13,    14,    48,    50,    53,    54,
       0,    41,    55,    20,     0,    23,    24,    25,    26,    40,
      35,    36,    37,    38,    39,    60,    63,    64,    65,    66,
      67,    68,     0,     0,    57,    74,    69,    70,    71,    72,
      73,     0,     0,    18,    21,    49,     0,     0,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,    -7,   -22,   -45,  -110,  -109,  -110,    18,   -78,
      -1,  -110,  -110,  -110,  -110,  -110,   147,     6,  -110,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    43,    47,    62,   100,    53,    49,    60,    86,    61,
      51,    63,    99,    65,   134,    64,   102,    94,    55,    56,
      58,    59,    96,   122,    84,    69,    57,    54,    95,   105,
     131,    62,    13,    14,    15,    87,    16,    69,    97,    87,
      19,    87,    66,    67,    68,    70,    71,    72,    73,    74,
      69,   138,    85,   104,   136,   132,     0,    23,    70,    71,
      72,    73,    74,    75,    76,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,    62,   115,   116,   117,   118,
     119,   120,   121,   123,     0,     0,    43,    43,    43,    43,
      43,    43,    43,   124,   125,   126,   127,   128,   129,   130,
      89,    90,    91,    92,     0,    54,    50,     0,     0,   135,
      13,    14,    15,     0,    16,     0,   139,     0,    19,     0,
       1,   133,     2,     3,     4,     5,     6,     7,     8,     9,
       0,   137,     0,    10,    11,    23,    12,     0,     0,    13,
      14,    15,     0,    16,    17,    18,    11,    19,    44,    45,
      48,    13,    14,    15,    20,    16,    17,    18,    52,    19,
      87,     0,    21,    22,    23,     1,    20,     2,     3,     4,
       5,     6,     7,     8,     9,     0,    23,     0,    10,    11,
       0,    12,   103,     0,    13,    14,    15,     0,    16,    17,
      18,    54,    19,     0,     0,     0,    13,    14,    15,    20,
      16,    17,    18,     0,    19,     0,     0,    21,    22,    23,
       1,    20,     2,     3,     4,     5,     6,     7,     8,     9,
       0,    23,     0,    10,    11,     0,    12,     0,     0,    13,
      14,    15,     0,    16,    17,    18,    88,    19,     0,    89,
      90,    91,    92,     0,    20,     0,     5,     6,     7,     8,
       9,     0,    21,    22,    23,    11,     0,     0,     0,     0,
      13,    14,    15,     0,    16,    17,    18,     0,    19,    69,
      66,    67,    68,     0,     0,    20,     0,    70,    69,    72,
      73,    74,     0,    21,    22,    23,    70,    71,    72,    73,
      74,    75,    76,    77,     0,    78,    79,    80,    81,    82,
       0,    83,    46,    11,     0,     0,     0,     0,    13,    14,
      15,     0,    16,    17,    18,     0,    19,     0,     0,    11,
      50,     0,     0,    20,    13,    14,    15,     0,    16,    17,
      18,    54,    19,    23,     0,     0,    13,    14,    15,    20,
      16,     0,    98,     0,    19,     0,     0,    69,     0,    23,
       0,     0,     0,     0,     0,    70,    71,    72,    73,    74,
     101,    23,    77,    69,    78,    79,    80,    81,    82,     0,
      83,    70,    71,    72,    73,    74,     0,     0,    77,    69,
      78,    79,    80,    81,    82,     0,    83,    70,    71,    72,
      73,    74,     0,     0,    77,    69,    78,    79,    80,    81,
      82,     0,    83,    70,    71,    72,    73,    74,   101,     0,
      77,    69,    78,    79,    80,    81,    82,     0,     0,    70,
      71,    72,    73,    74,    12,    88,    69,     0,    89,    90,
      91,    92,     0,    93,    70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    25,    49,    12,    17,    22,    16,     0,
      11,    16,    16,    16,   123,    21,    18,    16,    19,    20,
      21,    22,    44,    13,    22,    21,    20,    17,    16,    22,
       4,    53,    22,    23,    24,    43,    26,    21,    45,    43,
      30,    43,    13,    14,    15,    29,    30,    31,    32,    33,
      21,    18,    34,    54,   132,   100,    -1,    47,    29,    30,
      31,    32,    33,    34,    35,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    97,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    -1,    87,    88,    89,    90,
      91,    92,    93,    87,    88,    89,    90,    91,    92,    93,
      39,    40,    41,    42,    -1,    17,    18,    -1,    -1,   131,
      22,    23,    24,    -1,    26,    -1,   138,    -1,    30,    -1,
       3,   122,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,   132,    -1,    16,    17,    47,    19,    -1,    -1,    22,
      23,    24,    -1,    26,    27,    28,    17,    30,     1,     2,
       3,    22,    23,    24,    37,    26,    27,    28,    11,    30,
      43,    -1,    45,    46,    47,     3,    37,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    47,    -1,    16,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    27,
      28,    17,    30,    -1,    -1,    -1,    22,    23,    24,    37,
      26,    27,    28,    -1,    30,    -1,    -1,    45,    46,    47,
       3,    37,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    47,    -1,    16,    17,    -1,    19,    -1,    -1,    22,
      23,    24,    -1,    26,    27,    28,    36,    30,    -1,    39,
      40,    41,    42,    -1,    37,    -1,     8,     9,    10,    11,
      12,    -1,    45,    46,    47,    17,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    21,
      13,    14,    15,    -1,    -1,    37,    -1,    29,    21,    31,
      32,    33,    -1,    45,    46,    47,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      -1,    44,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    17,
      18,    -1,    -1,    37,    22,    23,    24,    -1,    26,    27,
      28,    17,    30,    47,    -1,    -1,    22,    23,    24,    37,
      26,    -1,    16,    -1,    30,    -1,    -1,    21,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      18,    47,    36,    21,    38,    39,    40,    41,    42,    -1,
      44,    29,    30,    31,    32,    33,    -1,    -1,    36,    21,
      38,    39,    40,    41,    42,    -1,    44,    29,    30,    31,
      32,    33,    -1,    -1,    36,    21,    38,    39,    40,    41,
      42,    -1,    44,    29,    30,    31,    32,    33,    18,    -1,
      36,    21,    38,    39,    40,    41,    42,    -1,    -1,    29,
      30,    31,    32,    33,    19,    36,    21,    -1,    39,    40,
      41,    42,    -1,    44,    29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      16,    17,    19,    22,    23,    24,    26,    27,    28,    30,
      37,    45,    46,    47,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    61,    67,    67,    16,    61,    67,    17,
      18,    61,    67,    53,    17,    61,    61,    68,    61,    61,
      22,     0,    54,    16,    21,    16,    13,    14,    15,    21,
      29,    30,    31,    32,    33,    34,    35,    36,    38,    39,
      40,    41,    42,    44,    22,    59,    16,    43,    36,    39,
      40,    41,    42,    44,    16,    16,    54,    53,    16,    16,
      55,    18,    18,    20,    61,    22,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    13,    61,    68,    68,    68,    68,    68,    68,
      68,     4,    55,    61,    57,    54,    60,    61,    18,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      57,    58,    59,    59,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    63,    63,
      64,    65,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     4,     2,
       3,     4,     1,     3,     3,     3,     3,     2,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     3,     5,
       3,     7,     2,     3,     3,     3,     1,     3,     1,     1,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2
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
#line 47 "src/main.y" /* yacc.c:1646  */
    {root = new TreeNode(0, NODE_PROG); root->addChild((yyvsp[0]));}
#line 1412 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1418 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 52 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]); (yyval)->addSibling((yyvsp[0]));}
#line 1424 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_STMT); (yyval)->stype = STMT_SKIP;}
#line 1430 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "src/main.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1436 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1442 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1448 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1454 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 62 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1460 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 63 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1466 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 67 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1472 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 68 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1478 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1484 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 70 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1490 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1496 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1502 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "src/main.y" /* yacc.c:1646  */
    {  // declare and init
    TreeNode* node = new TreeNode((yyvsp[-3])->lineno, NODE_STMT);
    node->stype=STMT_DECL;
    node->addChild((yyvsp[-3]));
    node->addChild((yyvsp[-2]));
    node->addChild((yyvsp[0]));
    (yyval) = node;


    TreeNode *t=(yyvsp[-2]);
    string type=(yyvsp[-3])->type->getTypeInfo();
    string tempname=t->var_name;
    int index=symtbl.lookup(tempname);
    if(index<=-1)
        {
            symtbl.insert(tempname,t->nodeID,type);
        }
        // else if(symtbl.get_type(index)!=type)
        // {
        //     symtbl.insert(tempname,t->nodeID,type);
        // }
    else
        {
            //double declarations in one scope, erro
            cerr<<"you already declared "<<tempname<<tempname<<" in this scope."<<endl; 
        }
}
#line 1534 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 103 "src/main.y" /* yacc.c:1646  */
    {
    TreeNode* node = new TreeNode((yyvsp[-1])->lineno, NODE_STMT);
    node->stype=STMT_DECL;
    node->addChild((yyvsp[-1]));
    node->addChild((yyvsp[0]));
    (yyval) = node;

    //give T's type to IDENTIFIERS
    TreeNode * t=(yyvsp[0]);
    // insert into symbol table
    string type=(yyvsp[-1])->type->getTypeInfo();
    while(t)
    {
        string tempname=t->var_name;
        int index=symtbl.lookup(tempname);
        if(index<=-1)
            {
                symtbl.insert(tempname,t->nodeID,type);
            }
        // else if(symtbl.get_type(index)!=type)
        // {
        //     symtbl.insert(tempname,t->nodeID,type);
        // }
        else
        {
            //double declarations in one scope, erro
            cerr<<"you already declared "<<tempname<<" in this scope."<<lineno<<endl; 
        }
        t=t->sibling;
    }     
}
#line 1570 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 137 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);(yyval)->stype=STMT_BLOCK;(yyvsp[-2])->addChild((yyvsp[-1]));}
#line 1576 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode* node= new TreeNode(lineno,NODE_FUNCTION);
        node->stype=STMT_DECL;
        node->addChild((yyvsp[-3]));
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[-1]));
        node->addChild((yyvsp[0]));
        (yyval)=node;

    // insert into symbol table
    string type=(yyvsp[-3])->type->getTypeInfo();
    TreeNode* t=(yyvsp[-2]);
        string tempname=t->var_name;
        int index=symtbl.lookup(tempname);
        if(index<=-1)
            symtbl.insert(tempname,t->nodeID,type);
        else
        {
            //double declarations in one scope, erro
            cerr<<"you already declared "<<tempname<<" in this scope."<<lineno<<endl; 
        }  
}
#line 1603 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 166 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1609 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 167 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]); (yyval)->addSibling((yyvsp[0]));}
#line 1615 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_ASSIGN;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->AS_typecheck(false);   
    }
#line 1628 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 179 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_ADDSELF;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;   
        node->AS_typecheck(false);   

}
#line 1642 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 188 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_MINUSSELF;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->AS_typecheck(false);   
   
}
#line 1656 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 197 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_ADDADD;
        node->addChild((yyvsp[-1]));
        (yyval)=node;
        node->AS_typecheck(true);   
   
}
#line 1669 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->optype=OP_MINUSMINUS;
        
        node->addChild((yyvsp[-1]));
        (yyval)=node;   
        node->AS_typecheck(true);   
}
#line 1682 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 217 "src/main.y" /* yacc.c:1646  */
    {
    int ifexist=symtbl.lookup((yyvsp[0])->var_name);
    if(ifexist==-1)
        cerr<<"IDENTIFIER "<<(yyvsp[0])->var_name<<" not declared at line "<<(yyvsp[0])->lineno<<endl;
    (yyval) = (yyvsp[0]);
}
#line 1693 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "src/main.y" /* yacc.c:1646  */
    {
    
    (yyval)=(yyvsp[0]);
    (yyval)->negative=1;
    (yyval)->A_typecheck();// negative flag is 1 claims that this expr is negative expr,then check if it's char or string
    //remember to add minus atribute here.
}
#line 1705 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 230 "src/main.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1713 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 233 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1721 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 236 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1729 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 239 "src/main.y" /* yacc.c:1646  */
    {
    (yyval) = (yyvsp[0]);
}
#line 1737 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 242 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_ADD;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        (yyval)->A_typecheck();
   
    }
#line 1752 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 252 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MINUS;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        (yyval)->A_typecheck();
   
    }
#line 1767 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 262 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MULT;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        (yyval)->A_typecheck();   
    }
#line 1781 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 271 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_DIV;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        (yyval)->A_typecheck();   
    }
#line 1795 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 280 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_EXPR);
        node->optype=OP_MOD;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        (yyval)->A_typecheck();   
}
#line 1809 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 290 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);(yyvsp[-2])->addSibling((yyvsp[0]));}
#line 1815 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 291 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1821 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 292 "src/main.y" /* yacc.c:1646  */
    {TreeNode *node=new TreeNode(lineno,NODE_EXPR);(yyval)=node; }
#line 1827 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 298 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE); (yyval)->type = TYPE_INT; }
#line 1833 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 299 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE);  (yyval)->type = TYPE_CHAR;}
#line 1839 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 300 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE);  (yyval)->type = TYPE_BOOL;}
#line 1845 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 301 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE);  (yyval)->type = TYPE_STRING;}
#line 1851 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 302 "src/main.y" /* yacc.c:1646  */
    {(yyval) = new TreeNode(lineno, NODE_TYPE);  (yyval)->type = TYPE_VOID;}
#line 1857 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 307 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_IF;
        node->addChild((yyvsp[-1]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        
    }
#line 1870 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 315 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_IF;
        node->addChild((yyvsp[-3]));
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 1883 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 325 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_WHILE;
        node->addChild((yyvsp[-1]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        
    }
#line 1896 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 335 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_FOR;
        node->addChild((yyvsp[-4]));
        node->addChild((yyvsp[-3]));
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        
    }
#line 1911 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 346 "src/main.y" /* yacc.c:1646  */
    {
        cout<<"test"<<endl;
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        (yyval)=node;
        
    }
#line 1923 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 353 "src/main.y" /* yacc.c:1646  */
    {
        cout<<"test"<<endl;
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        node->addChild((yyvsp[-1]));
        (yyval)=node;
        
    }
#line 1936 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 361 "src/main.y" /* yacc.c:1646  */
    {
        cout<<"test"<<endl;
        TreeNode* node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_RETURN;
        node->addChild((yyvsp[-1]));
        (yyval)=node;
        
    }
#line 1949 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 370 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1955 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 371 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1961 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 372 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_OR;
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        (yyval)->L_typecheck();
    }
#line 1974 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 382 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1980 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 383 "src/main.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1986 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 384 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2000 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 393 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOT;
        
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2012 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 400 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOT;
        
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2025 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 408 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_NOTEQUAL;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2039 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 417 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_GREATER;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2053 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 426 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SMALLER;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2067 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 435 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2081 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 444 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SORE;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2095 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 454 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_AND;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
        node->L_typecheck();
    }
#line 2109 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 463 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_GREATER;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2122 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 471 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SMALLER;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2135 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 479 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2148 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 487 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_SORE;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2161 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 496 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_AND;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2174 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 504 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_OP);
        node->optype=OP_EQUAL;
        
        node->addChild((yyvsp[-2]));
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2187 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 514 "src/main.y" /* yacc.c:1646  */
    {
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_PRINTF;
        node->addChild((yyvsp[0]));
        (yyval)=node;
        
    }
#line 2199 "src/main.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 523 "src/main.y" /* yacc.c:1646  */
    {
        
        TreeNode *node=new TreeNode(lineno,NODE_STMT);
        node->stype=STMT_SCANF;
        node->addChild((yyvsp[0]));
        (yyval)=node;
    }
#line 2211 "src/main.tab.cpp" /* yacc.c:1646  */
    break;


#line 2215 "src/main.tab.cpp" /* yacc.c:1646  */
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
#line 533 "src/main.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
