/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"

	#include "hw3_output.hpp"
	#include <iostream>
	#include <stdlib.h>
    #include "symbol_table.hpp"
    #include "types.hpp"
    using namespace output;

	extern int yylex();
    extern int yylineno;

	int yyerror(const char * message);
    //void deleteAll();

    TableStack* tables = &(TableStack::Instance());
    //vector<Node*> nodes;

#line 89 "parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_BYTE = 5,                       /* BYTE  */
  YYSYMBOL_B = 6,                          /* B  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_OVERRIDE = 8,                   /* OVERRIDE  */
  YYSYMBOL_TRUE = 9,                       /* TRUE  */
  YYSYMBOL_FALSE = 10,                     /* FALSE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 15,                  /* CONTINUE  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_NUM = 20,                       /* NUM  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_RELOP = 25,                     /* RELOP  */
  YYSYMBOL_PLUSMINUS = 26,                 /* PLUSMINUS  */
  YYSYMBOL_MULTDIV = 27,                   /* MULTDIV  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 30,                    /* RPAREN  */
  YYSYMBOL_SC = 31,                        /* SC  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_Program = 34,                   /* Program  */
  YYSYMBOL_Funcs = 35,                     /* Funcs  */
  YYSYMBOL_FuncDecl = 36,                  /* FuncDecl  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_OverRide = 38,                  /* OverRide  */
  YYSYMBOL_RetType = 39,                   /* RetType  */
  YYSYMBOL_Formals = 40,                   /* Formals  */
  YYSYMBOL_FormalsList = 41,               /* FormalsList  */
  YYSYMBOL_FormalDecl = 42,                /* FormalDecl  */
  YYSYMBOL_Statements = 43,                /* Statements  */
  YYSYMBOL_Statement = 44,                 /* Statement  */
  YYSYMBOL_Call = 45,                      /* Call  */
  YYSYMBOL_ExpList = 46,                   /* ExpList  */
  YYSYMBOL_Type = 47,                      /* Type  */
  YYSYMBOL_Exp = 48,                       /* Exp  */
  YYSYMBOL_IsExpBool = 49,                 /* IsExpBool  */
  YYSYMBOL_OpenScope = 50,                 /* OpenScope  */
  YYSYMBOL_WhileScope = 51,                /* WhileScope  */
  YYSYMBOL_CloseScope = 52                 /* CloseScope  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    34,    34,    44,    45,    47,    47,    82,    83,    85,
      90,    95,    96,    98,   104,   113,   124,   125,   127,   128,
     138,   156,   173,   174,   181,   189,   190,   191,   192,   199,
     207,   231,   244,   250,   257,   258,   259,   261,   262,   274,
     286,   297,   298,   299,   309,   310,   311,   312,   322,   333,
     344,   355,   368,   376,   377,   378
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "BYTE",
  "B", "BOOL", "OVERRIDE", "TRUE", "FALSE", "RETURN", "IF", "WHILE",
  "BREAK", "CONTINUE", "COMMA", "LBRACE", "RBRACE", "ID", "NUM", "STRING",
  "ASSIGN", "OR", "AND", "RELOP", "PLUSMINUS", "MULTDIV", "NOT", "LPAREN",
  "RPAREN", "SC", "ELSE", "$accept", "Program", "Funcs", "FuncDecl", "$@1",
  "OverRide", "RetType", "Formals", "FormalsList", "FormalDecl",
  "Statements", "Statement", "Call", "ExpList", "Type", "Exp", "IsExpBool",
  "OpenScope", "WhileScope", "CloseScope", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -80,    14,   -80,     3,   174,   -80,   -80,   -80,   -80,
     -80,   -80,     8,   -80,     1,   182,   -80,   -80,    17,    31,
      30,   182,   -80,    41,   -80,   112,    28,    37,    43,    45,
      65,   -80,    48,    80,   -80,    71,    85,   -80,   -80,    76,
     100,   -80,    54,     0,   -80,   -80,   119,    54,    54,   -80,
     -80,   112,    54,    15,   -80,   -80,   -80,    -9,   -80,   -80,
      82,   146,    54,    54,    54,    54,    54,   -80,   109,    88,
      90,    96,   128,   -80,    91,   114,    54,   -80,    54,   -80,
     158,    63,   -10,    95,   -80,   -80,   -80,   -80,   -80,   -80,
      54,   137,   -80,   112,   112,   -80,   -80,   -80,   -80,   -80,
     115,   -80,   -80,   112,   -80,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     8,     0,     2,     7,     0,     1,     4,    10,    34,
      35,    36,     0,     9,     0,    11,     5,    12,    13,     0,
       0,     0,    15,     0,    14,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    16,     0,     0,    45,    46,    40,
      42,    44,     0,     0,    23,    41,     0,     0,     0,    28,
      29,     0,     0,     0,     6,    17,    22,     0,    43,    47,
       0,     0,     0,     0,     0,     0,     0,    24,    52,     0,
       0,     0,     0,    31,     0,    32,     0,    19,     0,    37,
      49,    48,    50,    38,    39,    53,    54,    55,    21,    30,
       0,     0,    51,     0,     0,    18,    33,    20,    55,    55,
      25,    27,    53,     0,    55,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   124,   -80,   -80,   -80,   -80,   -80,   127,   -80,
      98,   -32,   -25,    66,    -3,   -11,   110,   -79,   -80,   -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    20,     5,    12,    16,    17,    18,
      33,    34,    45,    74,    36,    68,    69,    51,    94,    95
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    55,    13,    -3,     9,    10,    93,    11,    35,    37,
      38,     1,    19,    76,     6,    46,    65,    66,    19,    39,
      40,    41,    77,   103,    37,    38,    35,    14,    42,    43,
      15,    59,    61,    21,    39,    40,    41,    37,    38,    55,
      60,    72,    75,    42,    43,    73,    35,    39,    40,    41,
      22,    80,    81,    82,    83,    84,    42,    43,    25,    44,
      23,    98,    99,    37,    38,    91,    47,    92,    35,    35,
      52,   104,    48,    39,    40,    41,    49,    53,    35,    75,
     100,   101,    42,    43,     9,    10,   105,    11,    64,    65,
      66,    26,    27,    28,    29,    30,    50,    31,    54,    32,
       9,    10,    56,    11,    57,    53,    58,    26,    27,    28,
      29,    30,    78,    31,    87,    32,     9,    10,    85,    11,
      86,    89,    66,    26,    27,    28,    29,    30,     7,    31,
      90,    32,    62,    63,    64,    65,    66,    62,    63,    64,
      65,    66,    62,    63,    64,    65,    66,   102,    24,    71,
      67,    62,    63,    64,    65,    66,    96,     0,    70,    88,
      62,    63,    64,    65,    66,     0,     0,     0,    97,    62,
      63,    64,    65,    66,     0,     0,    79,     8,     9,    10,
       0,    11,    63,    64,    65,    66,     9,    10,     0,    11
};

static const yytype_int8 yycheck[] =
{
      25,    33,     5,     0,     4,     5,    85,     7,    33,     9,
      10,     8,    15,    22,     0,    26,    26,    27,    21,    19,
      20,    21,    31,   102,     9,    10,    51,    19,    28,    29,
      29,    42,    43,    16,    19,    20,    21,     9,    10,    71,
      43,    52,    53,    28,    29,    30,    71,    19,    20,    21,
      19,    62,    63,    64,    65,    66,    28,    29,    17,    31,
      30,    93,    94,     9,    10,    76,    29,    78,    93,    94,
      22,   103,    29,    19,    20,    21,    31,    29,   103,    90,
      98,    99,    28,    29,     4,     5,   104,     7,    25,    26,
      27,    11,    12,    13,    14,    15,    31,    17,    18,    19,
       4,     5,    31,     7,    19,    29,     6,    11,    12,    13,
      14,    15,    30,    17,    18,    19,     4,     5,    30,     7,
      30,    30,    27,    11,    12,    13,    14,    15,     4,    17,
      16,    19,    23,    24,    25,    26,    27,    23,    24,    25,
      26,    27,    23,    24,    25,    26,    27,    32,    21,    51,
      31,    23,    24,    25,    26,    27,    90,    -1,    48,    31,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    23,
      24,    25,    26,    27,    -1,    -1,    30,     3,     4,     5,
      -1,     7,    24,    25,    26,    27,     4,     5,    -1,     7
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    34,    35,    36,    38,     0,    35,     3,     4,
       5,     7,    39,    47,    19,    29,    40,    41,    42,    47,
      37,    16,    19,    30,    41,    17,    11,    12,    13,    14,
      15,    17,    19,    43,    44,    45,    47,     9,    10,    19,
      20,    21,    28,    29,    31,    45,    48,    29,    29,    31,
      31,    50,    22,    29,    18,    44,    31,    19,     6,    48,
      47,    48,    23,    24,    25,    26,    27,    31,    48,    49,
      49,    43,    48,    30,    46,    48,    22,    31,    30,    30,
      48,    48,    48,    48,    48,    30,    30,    18,    31,    30,
      16,    48,    48,    50,    51,    52,    46,    31,    44,    44,
      52,    52,    32,    50,    44,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    37,    36,    38,    38,    39,
      39,    40,    40,    41,    41,    42,    43,    43,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      45,    45,    46,    46,    47,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    50,    51,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,    10,     0,     1,     1,
       1,     0,     1,     1,     3,     2,     1,     2,     5,     3,
       5,     4,     2,     2,     3,     7,    11,     7,     2,     2,
       4,     3,     1,     3,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     2,     1,     1,     1,     2,     3,     3,
       3,     4,     1,     0,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: Funcs  */
#line 34 "parser.ypp"
                      { 
                    if(!tables->containsMain()) {
                        errorMainMissing();
                        //deleteAll();
                        exit(1);
                    }
                    tables->closeScope();
                    //deleteAll();
                    exit(0);
                }
#line 1215 "parser.tab.cpp"
    break;

  case 3: /* Funcs: %empty  */
#line 44 "parser.ypp"
                      { }
#line 1221 "parser.tab.cpp"
    break;

  case 4: /* Funcs: FuncDecl Funcs  */
#line 45 "parser.ypp"
                               { }
#line 1227 "parser.tab.cpp"
    break;

  case 5: /* $@1: %empty  */
#line 47 "parser.ypp"
                                                   {
                    std::cout << "test1 ";
                    OverrideNode* override = (OverrideNode*)yyvsp[-4];
                    RetTypeNode* ret_type = (RetTypeNode*)yyvsp[-3];
                    IdNode* id = (IdNode*)yyvsp[-2];
                    FormalsNode* formals = (FormalsNode*)yyvsp[0];
                    
                    vector<string> params_types;
                    vector<FormalDeclNode*> vec = formals->GetList();
                    for(int i = 0; i < vec.size(); i++) {
                        params_types.push_back(vec[i]->GetType());
                    }
                    int res = tables->Insert(id->GetName(), ret_type->GetType(), 0, params_types, override->CheckIsOverride(), true);
                    switch(res) {
                        case ERROR_DEF:
                            errorDef(yylineno, id->GetName());
                            break;
                        case ERROR_NO_OVERRIDE:
                            errorFuncNoOverride(yylineno, id->GetName());
                            break;
                        case ERROR_OVERRIDE_NO_DECL:
                            errorOverrideWithoutDeclaration(yylineno, id->GetName());
                            break;
                        case ERROR_MAIN_OVERRIDE:
                            errorMainOverride(yylineno);
                            break;
                    }

                    if(res != SUCCESS) { /*deleteAll();*/ exit(1); }
                    // should add $$ = new FuncDeclNode* ?

                }
#line 1264 "parser.tab.cpp"
    break;

  case 6: /* FuncDecl: OverRide RetType ID LPAREN Formals $@1 RPAREN LBRACE Statements RBRACE  */
#line 78 "parser.ypp"
                                                  {
                    tables->funcType = "";
                    tables->closeScope();    
                }
#line 1273 "parser.tab.cpp"
    break;

  case 7: /* OverRide: %empty  */
#line 82 "parser.ypp"
                      { std::cout << "test1 "; yyval = new OverrideNode(); /*nodes.push_back($$);*/ }
#line 1279 "parser.tab.cpp"
    break;

  case 8: /* OverRide: OVERRIDE  */
#line 83 "parser.ypp"
                         { yyval = new OverrideNode(true); /*nodes.push_back($$);*/ }
#line 1285 "parser.tab.cpp"
    break;

  case 9: /* RetType: Type  */
#line 85 "parser.ypp"
                     { 
                    TypeNode* type = (TypeNode*)yyvsp[0];
                    yyval = new RetTypeNode(type->GetType());
                    //nodes.push_back($$);
                }
#line 1295 "parser.tab.cpp"
    break;

  case 10: /* RetType: VOID  */
#line 90 "parser.ypp"
                     { 
                    yyval = new RetTypeNode("void");
                    //nodes.push_back($$);
                }
#line 1304 "parser.tab.cpp"
    break;

  case 11: /* Formals: %empty  */
#line 95 "parser.ypp"
                     { yyval = new FormalsNode(); /*nodes.push_back($$);*/ }
#line 1310 "parser.tab.cpp"
    break;

  case 12: /* Formals: FormalsList  */
#line 96 "parser.ypp"
                            { yyval = new FormalsNode((FormalsListNode*)yyvsp[0]); /*nodes.push_back($$);*/ }
#line 1316 "parser.tab.cpp"
    break;

  case 13: /* FormalsList: FormalDecl  */
#line 98 "parser.ypp"
                           { 
                    vector<FormalDeclNode*> vec;
                    vec.insert(vec.begin(), (FormalDeclNode*)yyvsp[0]);
                    yyval = new FormalsListNode(vec);
                    //nodes.push_back($$);
                }
#line 1327 "parser.tab.cpp"
    break;

  case 14: /* FormalsList: FormalDecl COMMA FormalsList  */
#line 104 "parser.ypp"
                                             { 
                    FormalDeclNode* decl = (FormalDeclNode*)yyvsp[-2];
                    FormalsListNode* list = (FormalsListNode*)yyvsp[0];
                    vector<FormalDeclNode*> vec = list->GetDecls();
                    vec.insert(vec.begin(), decl);
                    yyval = new FormalsListNode(vec);
                    //nodes.push_back($$);
                }
#line 1340 "parser.tab.cpp"
    break;

  case 15: /* FormalDecl: Type ID  */
#line 113 "parser.ypp"
                        { 
                    TypeNode* type = (TypeNode*)yyvsp[-1];
                    IdNode* id = (IdNode*)yyvsp[0];
                    if(tables->isInCurrentScope(id->GetName())) {
                        errorDef(yylineno, id->GetName());
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new FormalDeclNode(type->GetType(), id->GetName());
                    //nodes.push_back($$);
                }
#line 1356 "parser.tab.cpp"
    break;

  case 16: /* Statements: Statement  */
#line 124 "parser.ypp"
                          { }
#line 1362 "parser.tab.cpp"
    break;

  case 17: /* Statements: Statements Statement  */
#line 125 "parser.ypp"
                                     { }
#line 1368 "parser.tab.cpp"
    break;

  case 18: /* Statement: LBRACE OpenScope Statements RBRACE CloseScope  */
#line 127 "parser.ypp"
                                                              { }
#line 1374 "parser.tab.cpp"
    break;

  case 19: /* Statement: Type ID SC  */
#line 128 "parser.ypp"
                           { 
                    TypeNode* type = (TypeNode*)yyvsp[-2];
                    IdNode* id = (IdNode*)yyvsp[-1];
                    int res = tables->Insert(id->GetName(), { type->GetType() }, tables->offsets.top());
                    if(res == ERROR_DEF) {
                        errorDef(yylineno, id->GetName());
                        //deleteAll();
                        exit(1);
                    }
                }
#line 1389 "parser.tab.cpp"
    break;

  case 20: /* Statement: Type ID ASSIGN Exp SC  */
#line 138 "parser.ypp"
                                      { 
                    TypeNode* type = (TypeNode*)yyvsp[-4];
                    IdNode* id = (IdNode*)yyvsp[-3];
                    ExpNode* exp = (ExpNode*)yyvsp[-1];
                    if(isLegalAssign(type->GetType(), exp->GetType())) {
                        int res = tables->Insert(id->GetName(), { type->GetType() }, tables->offsets.top());
                        if(res == ERROR_DEF) {
                            errorDef(yylineno, id->GetName());
                            //deleteAll();
                            exit(1);
                        }
                    }
                    else {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                }
#line 1412 "parser.tab.cpp"
    break;

  case 21: /* Statement: ID ASSIGN Exp SC  */
#line 156 "parser.ypp"
                                 { 
                    IdNode* id = (IdNode*)yyvsp[-3];
                    ExpNode* exp = (ExpNode*)yyvsp[-1];
                    if(!(tables->containsName(id->GetName()))) {
                        errorUndef(yylineno, id->GetName());
                        //deleteAll();
                        exit(1);
                    }
                    else {
                        string type = tables->getType(id->GetName());
                        if(!isLegalAssign(type, exp->GetType())) {
                            errorMismatch(yylineno);
                            //deleteAll();
                            exit(1);
                        }
                    }
                }
#line 1434 "parser.tab.cpp"
    break;

  case 22: /* Statement: Call SC  */
#line 173 "parser.ypp"
                        { }
#line 1440 "parser.tab.cpp"
    break;

  case 23: /* Statement: RETURN SC  */
#line 174 "parser.ypp"
                          { 
                    if(tables->funcType != "void") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                }
#line 1452 "parser.tab.cpp"
    break;

  case 24: /* Statement: RETURN Exp SC  */
#line 181 "parser.ypp"
                              { 
                    ExpNode* exp = (ExpNode*)yyvsp[-1];
                    if(!isLegalAssign(tables->funcType, exp->GetType())) {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                }
#line 1465 "parser.tab.cpp"
    break;

  case 25: /* Statement: IF LPAREN IsExpBool RPAREN OpenScope Statement CloseScope  */
#line 189 "parser.ypp"
                                                                          { }
#line 1471 "parser.tab.cpp"
    break;

  case 26: /* Statement: IF LPAREN IsExpBool RPAREN OpenScope Statement CloseScope ELSE OpenScope Statement CloseScope  */
#line 190 "parser.ypp"
                                                                                                              { }
#line 1477 "parser.tab.cpp"
    break;

  case 27: /* Statement: WHILE LPAREN IsExpBool RPAREN WhileScope Statement CloseScope  */
#line 191 "parser.ypp"
                                                                              { }
#line 1483 "parser.tab.cpp"
    break;

  case 28: /* Statement: BREAK SC  */
#line 192 "parser.ypp"
                         { 
                    if(!tables->isCurrentScopeWhile()) {
                        errorUnexpectedBreak(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                }
#line 1495 "parser.tab.cpp"
    break;

  case 29: /* Statement: CONTINUE SC  */
#line 199 "parser.ypp"
                            {
                    if(!tables->isCurrentScopeWhile()) {
                        errorUnexpectedContinue(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                }
#line 1507 "parser.tab.cpp"
    break;

  case 30: /* Call: ID LPAREN ExpList RPAREN  */
#line 207 "parser.ypp"
                                         {
                    IdNode* id = (IdNode*)yyvsp[-3];
                    ExpListNode* exp_list = (ExpListNode*)yyvsp[-1];
                    vector<string> types;
                    vector<ExpNode*> list = exp_list->GetExpsList();
                    for(int i = 0; i < list.size(); i++) {
                        types.push_back(list[i]->GetType());
                    }
                    int res = tables->containsFunction(id->GetName(), types);
                    switch(res) {
                        case ERROR_UNDEF_FUNC:
                            errorUndefFunc(yylineno, id->GetName());
                            break;
                        case ERROR_PROTOTYPE_MISMATCH:
                            errorPrototypeMismatch(yylineno, id->GetName());
                            break;
                        case ERROR_AMBIGUOUS_CALL:
                            errorAmbiguousCall(yylineno, id->GetName());
                            break;
                    }
                    if(res != SUCCESS) { /*deleteAll();*/ exit(1); }
                    yyval = new CallNode(tables->getType(id->GetName()), id->GetName());
                    //nodes.push_back($$);
                }
#line 1536 "parser.tab.cpp"
    break;

  case 31: /* Call: ID LPAREN RPAREN  */
#line 231 "parser.ypp"
                                 { 
                    IdNode* id = (IdNode*)yyvsp[-2];
                    int res = tables->containsFunction(id->GetName());
                    switch(res) {
                        case ERROR_UNDEF_FUNC:
                            errorUndefFunc(yylineno, id->GetName());
                            break;
                    }
                    if(res != SUCCESS) { /*deleteAll();*/ exit(1); }
                    yyval = new CallNode(tables->getType(id->GetName()), id->GetName());
                    //nodes.push_back($$);
                }
#line 1553 "parser.tab.cpp"
    break;

  case 32: /* ExpList: Exp  */
#line 244 "parser.ypp"
                    { 
                    vector<ExpNode*> exps;
                    exps.push_back((ExpNode*)yyvsp[0]);
                    yyval = new ExpListNode(exps);
                    //nodes.push_back($$);
                }
#line 1564 "parser.tab.cpp"
    break;

  case 33: /* ExpList: Exp COMMA ExpList  */
#line 250 "parser.ypp"
                                  { 
                    ExpListNode* list = (ExpListNode*)yyvsp[0];
                    list->GetExpsList().push_back((ExpNode*)yyvsp[-2]);
                    yyval = new ExpListNode(list->GetExpsList());
                    //nodes.push_back($$);
                }
#line 1575 "parser.tab.cpp"
    break;

  case 34: /* Type: INT  */
#line 257 "parser.ypp"
                    { yyval = new TypeNode("int"); /*nodes.push_back($$);*/ }
#line 1581 "parser.tab.cpp"
    break;

  case 35: /* Type: BYTE  */
#line 258 "parser.ypp"
                     { yyval = new TypeNode("byte"); /*nodes.push_back($$);*/ }
#line 1587 "parser.tab.cpp"
    break;

  case 36: /* Type: BOOL  */
#line 259 "parser.ypp"
                     { yyval = new TypeNode("bool"); /*nodes.push_back($$);*/ }
#line 1593 "parser.tab.cpp"
    break;

  case 37: /* Exp: LPAREN Exp RPAREN  */
#line 261 "parser.ypp"
                                  { yyval = new ExpNode(((ExpNode*)yyvsp[-1])->GetType()); /*nodes.push_back($$);*/ }
#line 1599 "parser.tab.cpp"
    break;

  case 38: /* Exp: Exp PLUSMINUS Exp  */
#line 262 "parser.ypp"
                                  { 
                    ExpNode* exp1 = (ExpNode*)yyvsp[-2];
                    ExpNode* exp2 = (ExpNode*)yyvsp[0];
                    string type = GetSumType(exp1->GetType(), exp2->GetType());
                    if(type == "") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode(type);
                    //nodes.push_back($$);
                }
#line 1616 "parser.tab.cpp"
    break;

  case 39: /* Exp: Exp MULTDIV Exp  */
#line 274 "parser.ypp"
                                { 
                    ExpNode* exp1 = (ExpNode*)yyvsp[-2];
                    ExpNode* exp2 = (ExpNode*)yyvsp[0];
                    string type = GetSumType(exp1->GetType(), exp2->GetType());
                    if(type == "") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode(type);
                    //nodes.push_back($$);
                }
#line 1633 "parser.tab.cpp"
    break;

  case 40: /* Exp: ID  */
#line 286 "parser.ypp"
                   { 
                    IdNode* id = (IdNode*)yyvsp[0];
                    string type = tables->getType(id->GetName());
                    if(type == "") {
                        errorUndef(yylineno, id->GetName());
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode(type);
                    //nodes.push_back($$);
                }
#line 1649 "parser.tab.cpp"
    break;

  case 41: /* Exp: Call  */
#line 297 "parser.ypp"
                     { yyval = new ExpNode(((CallNode*)yyvsp[0])->GetType()); /*nodes.push_back($$);*/ }
#line 1655 "parser.tab.cpp"
    break;

  case 42: /* Exp: NUM  */
#line 298 "parser.ypp"
                    { yyval = new ExpNode("int"); /*nodes.push_back($$);*/ }
#line 1661 "parser.tab.cpp"
    break;

  case 43: /* Exp: NUM B  */
#line 299 "parser.ypp"
                      { 
                    NumNode* num = (NumNode*)yyvsp[-1];
                    if(stoi(num->GetNumAsString()) > 255) {
                        errorByteTooLarge(yylineno, num->GetNumAsString());
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode("byte");
                    //nodes.push_back($$);
                }
#line 1676 "parser.tab.cpp"
    break;

  case 44: /* Exp: STRING  */
#line 309 "parser.ypp"
                       { yyval = new ExpNode("string"); /*nodes.push_back($$);*/ }
#line 1682 "parser.tab.cpp"
    break;

  case 45: /* Exp: TRUE  */
#line 310 "parser.ypp"
                     { yyval = new ExpNode("bool"); /*nodes.push_back($$);*/ }
#line 1688 "parser.tab.cpp"
    break;

  case 46: /* Exp: FALSE  */
#line 311 "parser.ypp"
                      { yyval = new ExpNode("bool"); /*nodes.push_back($$);*/ }
#line 1694 "parser.tab.cpp"
    break;

  case 47: /* Exp: NOT Exp  */
#line 312 "parser.ypp"
                        { 
                    ExpNode* exp = (ExpNode*)yyvsp[0];
                    if(exp->GetType() != "bool") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode("bool");
                    //nodes.push_back($$);
                }
#line 1709 "parser.tab.cpp"
    break;

  case 48: /* Exp: Exp AND Exp  */
#line 322 "parser.ypp"
                            { 
                    ExpNode* exp1 = (ExpNode*)yyvsp[-2];
                    ExpNode* exp2 = (ExpNode*)yyvsp[0];
                    if(exp1->GetType() != "bool" || exp2->GetType() != "bool") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode("bool");
                    //nodes.push_back($$);
                }
#line 1725 "parser.tab.cpp"
    break;

  case 49: /* Exp: Exp OR Exp  */
#line 333 "parser.ypp"
                           { 
                    ExpNode* exp1 = (ExpNode*)yyvsp[-2];
                    ExpNode* exp2 = (ExpNode*)yyvsp[0];
                    if(exp1->GetType() != "bool" || exp2->GetType() != "bool") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode("bool");
                    //nodes.push_back($$);
                }
#line 1741 "parser.tab.cpp"
    break;

  case 50: /* Exp: Exp RELOP Exp  */
#line 344 "parser.ypp"
                              {
                    ExpNode* exp1 = (ExpNode*)yyvsp[-2];
                    ExpNode* exp2 = (ExpNode*)yyvsp[0];
                    if(GetSumType(exp1->GetType(), exp2->GetType()) == "") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode("bool");
                    //nodes.push_back($$);
                }
#line 1757 "parser.tab.cpp"
    break;

  case 51: /* Exp: LPAREN Type RPAREN Exp  */
#line 355 "parser.ypp"
                                       {
                    TypeNode* type = (TypeNode*)yyvsp[-2];
                    ExpNode* exp = (ExpNode*)yyvsp[0];
                    if(!IsLegalConvertion(exp->GetType() ,type->GetType())) {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                    yyval = new ExpNode(type->GetType());
                    //nodes.push_back($$);
                }
#line 1773 "parser.tab.cpp"
    break;

  case 52: /* IsExpBool: Exp  */
#line 368 "parser.ypp"
                    {
                    ExpNode* exp = (ExpNode*)yyvsp[0];
                    if(exp->GetType() != "bool") {
                        errorMismatch(yylineno);
                        //deleteAll();
                        exit(1);
                    }
                }
#line 1786 "parser.tab.cpp"
    break;

  case 53: /* OpenScope: %empty  */
#line 376 "parser.ypp"
                { tables->newScope(); }
#line 1792 "parser.tab.cpp"
    break;

  case 54: /* WhileScope: %empty  */
#line 377 "parser.ypp"
                { tables->newScope(true); }
#line 1798 "parser.tab.cpp"
    break;

  case 55: /* CloseScope: %empty  */
#line 378 "parser.ypp"
                { tables->closeScope(); }
#line 1804 "parser.tab.cpp"
    break;


#line 1808 "parser.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 380 "parser.ypp"


int main()
{
    std::cout << "test1 ";
    tables->Init();
	yyparse();
}

int yyerror(const char * message)
{
	errorSyn(yylineno);
    //deleteAll();
	exit(1);
}

/*void deleteAll() {
    int size = nodes.size();
    delete tables;
    for(int i = 0; i < size; i++) {
        if(nodes[i]) delete nodes[i];
    }
    while(!nodes.empty()) nodes.pop_back();
}*/
