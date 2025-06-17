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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast_c.h"

ASTNode* root;

int yylex(void);
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

#line 85 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_FLOATNUM = 4,                   /* FLOATNUM  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_WRITE = 15,                     /* WRITE  */
  YYSYMBOL_FUNCTION = 16,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NEQ = 19,                       /* NEQ  */
  YYSYMBOL_LEQ = 20,                       /* LEQ  */
  YYSYMBOL_GEQ = 21,                       /* GEQ  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_GT = 23,                        /* GT  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_LOWER_THAN_ELSE = 29,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_30_ = 30,                       /* ';'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_stmt_list = 39,                 /* stmt_list  */
  YYSYMBOL_stmt = 40,                      /* stmt  */
  YYSYMBOL_func_def = 41,                  /* func_def  */
  YYSYMBOL_param_list_opt = 42,            /* param_list_opt  */
  YYSYMBOL_param_list = 43,                /* param_list  */
  YYSYMBOL_param_decl = 44,                /* param_decl  */
  YYSYMBOL_return_stmt = 45,               /* return_stmt  */
  YYSYMBOL_func_call = 46,                 /* func_call  */
  YYSYMBOL_arg_list_opt = 47,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 48,                  /* arg_list  */
  YYSYMBOL_expr = 49                       /* expr  */
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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


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
       2,     2,     2,     2,     2,     2,     2,    28,     2,     2,
      32,    33,    26,    24,    36,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    49,    58,    69,    70,    71,    72,    73,
      74,    75,    77,    79,    80,    81,    83,    84,    88,    96,
      97,   101,   106,   114,   115,   116,   120,   124,   130,   131,
     135,   140,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "FLOATNUM",
  "ID", "STRING_LITERAL", "INT", "FLOAT", "STRING", "IF", "ELSE", "WHILE",
  "FOR", "PRINT", "WRITE", "FUNCTION", "RETURN", "EQ", "NEQ", "LEQ", "GEQ",
  "LT", "GT", "'+'", "'-'", "'*'", "'/'", "'%'", "LOWER_THAN_ELSE", "';'",
  "'='", "'('", "')'", "'{'", "'}'", "','", "$accept", "program",
  "stmt_list", "stmt", "func_def", "param_list_opt", "param_list",
  "param_decl", "return_stmt", "func_call", "arg_list_opt", "arg_list",
  "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-26)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,   -25,     3,    14,    16,    -9,    -4,     2,     7,    30,
      31,    67,    37,    67,   -26,   -26,     9,     7,     7,    23,
      26,    28,     7,     7,     7,   -26,   -26,   -14,   -26,   132,
      35,    41,    17,   -26,   -26,   -26,   145,    45,    48,   197,
     -26,   -26,   -26,    84,   100,   158,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,   -26,
     -26,    -5,   -26,   -26,   -26,     7,    67,    67,     7,   197,
      52,   -26,   -26,   -26,   -26,   -26,   -26,   208,   208,   219,
     219,   219,    82,    85,    90,    56,    60,   -26,   197,    86,
     -26,   171,   -26,   -26,   -26,   -26,    65,    -5,    67,     7,
      67,   -26,   -26,   116,    54,    67,     7,    78,   -26,   184,
     -26,   -26
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,    17,     0,     0,    28,     0,
       0,     0,     0,     0,     0,    45,    47,    46,    48,     0,
       0,     0,     0,     1,     4,    16,     0,     0,    29,    30,
       5,     6,     7,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    19,    14,     8,    27,     0,     0,     0,     0,    43,
       0,    37,    38,    39,    40,    41,    42,    32,    33,    34,
      35,    36,     0,     0,     0,     0,    20,    21,    31,    11,
      13,     0,    44,    23,    24,    25,     0,     0,     0,     0,
       0,    22,    12,     0,     0,     0,     0,     0,    15,     0,
      18,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,    -6,   -12,   -26,   -26,   -26,    18,   -26,   -26,
      53,   -26,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    85,    86,    87,   107,    16,
      37,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    34,    82,    83,    84,    32,    17,    18,    19,    36,
      25,    26,    27,    28,    43,    44,    45,    46,    47,    20,
      34,    21,     1,    22,     2,     3,     4,     5,    23,     6,
       7,     8,     9,    10,    24,    30,    31,    33,    69,    35,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    11,    62,    40,    89,    90,    41,    88,    42,     1,
      91,     2,     3,     4,     5,    60,     6,     7,     8,     9,
      10,   106,     1,    61,     2,     3,     4,     5,    64,     6,
       7,     8,     9,    10,    65,    92,   102,    93,    11,    96,
      94,   103,    34,   108,   104,    95,    97,    98,   109,   100,
      70,    11,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   110,     0,   101,     0,    66,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
       0,     0,     0,    67,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,   105,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    59,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,    63,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,    68,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,    99,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,   111,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    48,    49,    50,    51,
      52,    53,     0,     0,    56,    57,    58,    48,    49,    50,
      51,    52,    53
};

static const yytype_int8 yycheck[] =
{
       8,    13,     7,     8,     9,    11,    31,    32,     5,    17,
       3,     4,     5,     6,    22,    23,    24,    31,    32,     5,
      32,     5,     5,    32,     7,     8,     9,    10,    32,    12,
      13,    14,    15,    16,    32,     5,     5,     0,    46,    30,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    34,    35,    30,    66,    67,    30,    65,    30,     5,
      68,     7,     8,     9,    10,    30,    12,    13,    14,    15,
      16,    17,     5,    32,     7,     8,     9,    10,    33,    12,
      13,    14,    15,    16,    36,    33,    98,     5,    34,    33,
       5,    99,   104,   105,   100,     5,    36,    11,   106,    34,
      47,    34,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    35,    -1,    97,    -1,    33,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    33,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    27,    28,    18,    19,    20,
      21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,     8,     9,    10,    12,    13,    14,    15,
      16,    34,    38,    39,    40,    41,    46,    31,    32,     5,
       5,     5,    32,    32,    32,     3,     4,     5,     6,    49,
       5,     5,    39,     0,    40,    30,    49,    47,    48,    49,
      30,    30,    30,    49,    49,    49,    31,    32,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      30,    32,    35,    30,    33,    36,    33,    33,    30,    49,
      47,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,     7,     8,     9,    42,    43,    44,    49,    40,
      40,    49,    33,     5,     5,     5,    33,    36,    11,    30,
      34,    44,    40,    49,    39,    33,    17,    45,    40,    49,
      35,    30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    41,    42,
      42,    43,    43,    44,    44,    44,    45,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     3,     3,     4,     3,
       3,     5,     7,     5,     3,     9,     2,     1,     9,     0,
       1,     1,     3,     2,     2,     2,     3,     4,     0,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     1,     1,     1,     1
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
  case 2: /* program: stmt_list  */
#line 45 "parser.y"
                            { root = (ASTNode*)(yyvsp[0].node); }
#line 1210 "parser.tab.c"
    break;

  case 3: /* stmt_list: stmt  */
#line 49 "parser.y"
                           {
                            ASTNode** stmts = malloc(sizeof(ASTNode*));
                            stmts[0] = (ASTNode*)(yyvsp[0].node);
                            ASTNode* block = malloc(sizeof(ASTNode));
                            block->type = NODE_BLOCK;
                            block->block.stmts = stmts;
                            block->block.stmt_count = 1;
                            (yyval.node) = block;
                          }
#line 1224 "parser.tab.c"
    break;

  case 4: /* stmt_list: stmt_list stmt  */
#line 58 "parser.y"
                           {
                            ASTNode* block = (ASTNode*)(yyvsp[-1].node);
                            int n = block->block.stmt_count + 1;
                            block->block.stmts = realloc(block->block.stmts, n * sizeof(ASTNode*));
                            block->block.stmts[n-1] = (ASTNode*)(yyvsp[0].node);
                            block->block.stmt_count = n;
                            (yyval.node) = block;
                          }
#line 1237 "parser.tab.c"
    break;

  case 5: /* stmt: INT ID ';'  */
#line 69 "parser.y"
                               { add_symbol((yyvsp[-1].id), NODE_INT); (yyval.node) = make_decl_node((yyvsp[-1].id), NODE_INT); }
#line 1243 "parser.tab.c"
    break;

  case 6: /* stmt: FLOAT ID ';'  */
#line 70 "parser.y"
                               { add_symbol((yyvsp[-1].id), NODE_FLOAT); (yyval.node) = make_decl_node((yyvsp[-1].id), NODE_FLOAT); }
#line 1249 "parser.tab.c"
    break;

  case 7: /* stmt: STRING ID ';'  */
#line 71 "parser.y"
                               { add_symbol((yyvsp[-1].id), NODE_STRING); (yyval.node) = make_decl_node((yyvsp[-1].id), NODE_STRING); }
#line 1255 "parser.tab.c"
    break;

  case 8: /* stmt: ID '=' expr ';'  */
#line 72 "parser.y"
                               { (yyval.node) = make_assign_node((yyvsp[-3].id), (ASTNode*)(yyvsp[-1].node)); }
#line 1261 "parser.tab.c"
    break;

  case 9: /* stmt: PRINT expr ';'  */
#line 73 "parser.y"
                               { (yyval.node) = make_print_node((ASTNode*)(yyvsp[-1].node)); }
#line 1267 "parser.tab.c"
    break;

  case 10: /* stmt: WRITE ID ';'  */
#line 74 "parser.y"
                               { (yyval.node) = make_read_node((yyvsp[-1].id), -1); }
#line 1273 "parser.tab.c"
    break;

  case 11: /* stmt: IF '(' expr ')' stmt  */
#line 76 "parser.y"
                                { (yyval.node) = make_if_node((ASTNode*)(yyvsp[-2].node), (ASTNode*)(yyvsp[0].node), NULL); }
#line 1279 "parser.tab.c"
    break;

  case 12: /* stmt: IF '(' expr ')' stmt ELSE stmt  */
#line 78 "parser.y"
                                { (yyval.node) = make_if_node((ASTNode*)(yyvsp[-4].node), (ASTNode*)(yyvsp[-2].node), (ASTNode*)(yyvsp[0].node)); }
#line 1285 "parser.tab.c"
    break;

  case 13: /* stmt: WHILE '(' expr ')' stmt  */
#line 79 "parser.y"
                               { (yyval.node) = make_while_node((ASTNode*)(yyvsp[-2].node), (ASTNode*)(yyvsp[0].node)); }
#line 1291 "parser.tab.c"
    break;

  case 14: /* stmt: '{' stmt_list '}'  */
#line 80 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1297 "parser.tab.c"
    break;

  case 15: /* stmt: FOR '(' expr ';' expr ';' expr ')' stmt  */
#line 82 "parser.y"
                                { (yyval.node) = make_for_node((ASTNode*)(yyvsp[-6].node), (ASTNode*)(yyvsp[-4].node), (ASTNode*)(yyvsp[-2].node), (ASTNode*)(yyvsp[0].node)); }
#line 1303 "parser.tab.c"
    break;

  case 16: /* stmt: func_call ';'  */
#line 83 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1309 "parser.tab.c"
    break;

  case 17: /* stmt: func_def  */
#line 84 "parser.y"
                               { (yyval.node) = NULL; }
#line 1315 "parser.tab.c"
    break;

  case 18: /* func_def: FUNCTION ID '(' param_list_opt ')' '{' stmt_list return_stmt '}'  */
#line 89 "parser.y"
    {
        (yyval.node) = make_funcdef_node((yyvsp[-7].id), (yyvsp[-5].node_list).list, (yyvsp[-5].node_list).count, (yyvsp[-2].node), (yyvsp[-1].node));
        add_function((yyvsp[-7].id), (yyvsp[-5].node_list).list, (yyvsp[-5].node_list).count, (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1324 "parser.tab.c"
    break;

  case 19: /* param_list_opt: %empty  */
#line 96 "parser.y"
                   { (yyval.node_list).list = NULL; (yyval.node_list).count = 0; }
#line 1330 "parser.tab.c"
    break;

  case 20: /* param_list_opt: param_list  */
#line 97 "parser.y"
                 { (yyval.node_list) = (yyvsp[0].node_list); }
#line 1336 "parser.tab.c"
    break;

  case 21: /* param_list: param_decl  */
#line 101 "parser.y"
                 {
        (yyval.node_list).list = malloc(sizeof(ASTNode*) * 1);
        (yyval.node_list).list[0] = (ASTNode*)(yyvsp[0].node);
        (yyval.node_list).count = 1;
    }
#line 1346 "parser.tab.c"
    break;

  case 22: /* param_list: param_list ',' param_decl  */
#line 106 "parser.y"
                                {
        (yyvsp[-2].node_list).list = realloc((yyvsp[-2].node_list).list, sizeof(ASTNode*) * ((yyvsp[-2].node_list).count + 1));
        (yyvsp[-2].node_list).list[(yyvsp[-2].node_list).count++] = (ASTNode*)(yyvsp[0].node);
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1356 "parser.tab.c"
    break;

  case 23: /* param_decl: INT ID  */
#line 114 "parser.y"
                { (yyval.node) = make_decl_node((yyvsp[0].id), NODE_INT); add_symbol((yyvsp[0].id), NODE_INT); }
#line 1362 "parser.tab.c"
    break;

  case 24: /* param_decl: FLOAT ID  */
#line 115 "parser.y"
                { (yyval.node) = make_decl_node((yyvsp[0].id), NODE_FLOAT); add_symbol((yyvsp[0].id), NODE_FLOAT); }
#line 1368 "parser.tab.c"
    break;

  case 25: /* param_decl: STRING ID  */
#line 116 "parser.y"
                { (yyval.node) = make_decl_node((yyvsp[0].id), NODE_STRING); add_symbol((yyvsp[0].id), NODE_STRING); }
#line 1374 "parser.tab.c"
    break;

  case 26: /* return_stmt: RETURN expr ';'  */
#line 120 "parser.y"
                    { (yyval.node) = make_return_node((yyvsp[-1].node)); }
#line 1380 "parser.tab.c"
    break;

  case 27: /* func_call: ID '(' arg_list_opt ')'  */
#line 124 "parser.y"
                            {
        (yyval.node) = make_funccall_node_with_args((yyvsp[-3].id), (yyvsp[-1].node_list).list, (yyvsp[-1].node_list).count);
    }
#line 1388 "parser.tab.c"
    break;

  case 28: /* arg_list_opt: %empty  */
#line 130 "parser.y"
                   { (yyval.node_list).list = NULL; (yyval.node_list).count = 0; }
#line 1394 "parser.tab.c"
    break;

  case 29: /* arg_list_opt: arg_list  */
#line 131 "parser.y"
               { (yyval.node_list) = (yyvsp[0].node_list); }
#line 1400 "parser.tab.c"
    break;

  case 30: /* arg_list: expr  */
#line 135 "parser.y"
           {
        (yyval.node_list).list = malloc(sizeof(ASTNode*) * 1);
        (yyval.node_list).list[0] = (ASTNode*)(yyvsp[0].node);
        (yyval.node_list).count = 1;
    }
#line 1410 "parser.tab.c"
    break;

  case 31: /* arg_list: arg_list ',' expr  */
#line 140 "parser.y"
                        {
        (yyvsp[-2].node_list).list = realloc((yyvsp[-2].node_list).list, sizeof(ASTNode*) * ((yyvsp[-2].node_list).count + 1));
        (yyvsp[-2].node_list).list[(yyvsp[-2].node_list).count++] = (ASTNode*)(yyvsp[0].node);
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1420 "parser.tab.c"
    break;

  case 32: /* expr: expr '+' expr  */
#line 148 "parser.y"
                         { (yyval.node) = make_binop_node("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1426 "parser.tab.c"
    break;

  case 33: /* expr: expr '-' expr  */
#line 149 "parser.y"
                         { (yyval.node) = make_binop_node("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1432 "parser.tab.c"
    break;

  case 34: /* expr: expr '*' expr  */
#line 150 "parser.y"
                         { (yyval.node) = make_binop_node("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1438 "parser.tab.c"
    break;

  case 35: /* expr: expr '/' expr  */
#line 151 "parser.y"
                         { (yyval.node) = make_binop_node("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1444 "parser.tab.c"
    break;

  case 36: /* expr: expr '%' expr  */
#line 152 "parser.y"
                         { (yyval.node) = make_binop_node("%", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1450 "parser.tab.c"
    break;

  case 37: /* expr: expr EQ expr  */
#line 153 "parser.y"
                         { (yyval.node) = make_binop_node("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1456 "parser.tab.c"
    break;

  case 38: /* expr: expr NEQ expr  */
#line 154 "parser.y"
                         { (yyval.node) = make_binop_node("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1462 "parser.tab.c"
    break;

  case 39: /* expr: expr LEQ expr  */
#line 155 "parser.y"
                         { (yyval.node) = make_binop_node("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1468 "parser.tab.c"
    break;

  case 40: /* expr: expr GEQ expr  */
#line 156 "parser.y"
                         { (yyval.node) = make_binop_node(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1474 "parser.tab.c"
    break;

  case 41: /* expr: expr LT expr  */
#line 157 "parser.y"
                         { (yyval.node) = make_binop_node("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1480 "parser.tab.c"
    break;

  case 42: /* expr: expr GT expr  */
#line 158 "parser.y"
                         { (yyval.node) = make_binop_node(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1486 "parser.tab.c"
    break;

  case 43: /* expr: ID '=' expr  */
#line 159 "parser.y"
                         { (yyval.node) = make_assign_node((yyvsp[-2].id), (ASTNode*)(yyvsp[0].node)); }
#line 1492 "parser.tab.c"
    break;

  case 44: /* expr: ID '(' arg_list_opt ')'  */
#line 160 "parser.y"
                              { (yyval.node) = make_funccall_node_with_args((yyvsp[-3].id), (yyvsp[-1].node_list).list, (yyvsp[-1].node_list).count); }
#line 1498 "parser.tab.c"
    break;

  case 45: /* expr: NUMBER  */
#line 161 "parser.y"
                         { (yyval.node) = make_int_node((yyvsp[0].ival)); }
#line 1504 "parser.tab.c"
    break;

  case 46: /* expr: ID  */
#line 162 "parser.y"
                         { (yyval.node) = make_id_node((yyvsp[0].id)); }
#line 1510 "parser.tab.c"
    break;

  case 47: /* expr: FLOATNUM  */
#line 163 "parser.y"
                         { (yyval.node) = make_float_node((yyvsp[0].fval)); }
#line 1516 "parser.tab.c"
    break;

  case 48: /* expr: STRING_LITERAL  */
#line 164 "parser.y"
                         { (yyval.node) = make_string_node((yyvsp[0].id)); }
#line 1522 "parser.tab.c"
    break;


#line 1526 "parser.tab.c"

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

#line 167 "parser.y"


int main() {
    if (yyparse() == 0) {
        FILE* out = fopen("output.c", "w");
        fprintf(out, "#include <stdio.h>\n");
        fprintf(out, "#include <string.h>\n");
        fprintf(out, "#include <stdlib.h>\n");

        generate_all_functions(out);

        fprintf(out, "int main() {\n");
        generate_code(out, root);
        fprintf(out, "return 0;\n}\n");
        fclose(out);
        printf("Código C generado en output.c\n");
    }
    return 0;
}
