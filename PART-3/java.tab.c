
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "java.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "SymbolTable.h"
    #include "TreeNode.h"
    #include "java.tab.h"

    extern int yylineno;
    int yylex(void);
    extern struct TreeNode *create_tree_node(char *name, enum SemanticType stype,int num_children, ...);
    extern struct TreeNode* copy_entry_to_node(struct SymbolTableEntry *entry);
    extern void add_children(struct TreeNode *node, int num_children, ...);
    extern void setDataType(struct TreeNode *node,enum DataType dtype);
    extern void inorder_traversal(struct TreeNode *root, int depth);
    extern void setDimension(struct TreeNode *node,int dimen);
    extern void free_tree(struct TreeNode *root);
    extern int checkType(struct TreeNode *node1,struct TreeNode *node2,int lineNo);
    extern int checkdType(struct TreeNode *node,enum DataType dtype,int dimen,int lineNo);
    extern int check_method_args(SymbolTableEntry *entry,struct TreeNode* pass_args,int lineNo);
    extern int yyrestart(void*);

    /*extern void print_table(struct SymbolTableEntry*head);
    extern void setType(struct TreeNode* node,enum datatype dtype);
    extern int checkType(struct TreeNode* n1, struct TreeNode*n2);
    extern int checkdType(TreeNode*n1,enum datatype);
    extern int isdefined(TreeNode*);*/
    struct SymbolTableEntry* reservedKeywords[100];
    struct SymbolTable *constants;
    void yyerror(const char *s) {
        fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
    }
    struct ScopeStack *scopeStack;

    extern struct SymbolTableEntry* new_entry(char *lexeme, int lineNo, SymbolType symbolType, Token token, DataType dataType, Value value);
    extern struct SymbolTableEntry *lookup(struct SymbolTable *table, char *lexeme);
    extern struct SymbolTableEntry* add_entry(struct SymbolTable *table, char *lexeme, int lineNo, SymbolType symbolType, DataType dataType, Value value);

    extern struct SymbolTableEntry* check_and_add(struct SymbolTable *table, char *lexeme, int lineNo, SymbolType symbolType, DataType dataType, Value value);
    extern void set_data_type(SymbolTableEntry *entry, DataType dataType);
    extern void set_value(SymbolTableEntry *entry, Value value);
    extern void set_line_no(SymbolTableEntry *entry, int lineNo);
    extern void set_dimension(struct SymbolTableEntry *entry, int dimen);
    extern void set_symbol_type(SymbolTableEntry *entry, SymbolType symbolType);
    extern void set_semantic_type(SymbolTableEntry *entry, enum SemanticType semanticType);
    extern void store_keywords(SymbolTableEntry** reservedKeywords);
    extern struct SymbolTableEntry* store_literals(SymbolTable *table, char *lexeme, int lineNo, DataType dataType, Value value);
    extern void push_scope(ScopeStack *stack, struct SymbolTable *table);
    extern struct SymbolTable *pop_scope(ScopeStack *stack);
    extern struct SymbolTable *peek_scope(ScopeStack *stack);
    extern struct SymbolTable *new_table(struct SymbolTable *parent);
    extern int check_and_set_dType(SymbolTableEntry *entry,DataType dtype);
    extern void set_member_method_values(SymbolTable *stable,SymbolTableEntry *entry, DataType returnType, struct TreeNode *arg_list);
    extern int is_defined(SymbolTableEntry *entry);
    extern int is_method(struct SymbolTableEntry *entry);
    extern int is_class(struct SymbolTableEntry *entry);
    extern int check_dimension(struct SymbolTableEntry *entry, int dimen, int lineNo);
    extern int check_array_access(struct SymbolTableEntry *entry, int dimen, int lineNo);

    // Define a function to handle parse errors and continue parsing
    void yyparse_error(const char *message) {
        fprintf(stderr, "Parse error at line %d: %s\n", yylineno, message);
    }
    int yywrap(void){ return 1; }

    struct TreeNode *root=NULL;
    struct SymbolTable* symbolTable=NULL;
    /*int checkType(struct TreeNode* n1, struct TreeNode*n2){
        if(n1->dtype==n2->dtype)return 1;
        printf("error: Type mismatch at line %d\n",yylineno);
        return 0;
    }
    int checkdType(TreeNode*n, datatype dtype){
        if(n->dtype==dtype)return 1;
        printf("error: Type mismatch at line %d\n",yylineno);
        return 0;
    }
    int isdefined(TreeNode*n1){
        if(n1->dtype!=unknown)return 1;
        printf("error: undeclared variable %s at line %d\n",n1->name,yylineno);
        return 0;
    }
    void setType(TreeNode*node, datatype dtype){
        // printf("setting up for %s at %d---- %d\n",node->name,yylineno,dtype);
        
            if(node->dtype==unknown){
                node->dtype=dtype;
                if(node->nodetype==terminal)
                node->this->datatype=dtype;
                // printf("setting up at %d---- %d\n",yylineno,dtype);
            }
            else printf("error: redeclaration of %s at line %d\n",node->name,yylineno);
        
        // printf("%d is setted to %s\n",dtype,node->name);
    }
    */



/* Line 189 of yacc.c  */
#line 173 "java.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OR = 258,
     AND = 259,
     NE = 260,
     EQ = 261,
     GE = 262,
     LE = 263,
     GT = 264,
     LT = 265,
     MINUS = 266,
     PLUS = 267,
     MOD = 268,
     DIVIDE = 269,
     TIMES = 270,
     NOT = 271,
     DOT = 272,
     INT = 273,
     DOUBLE = 274,
     BOOLEAN = 275,
     CHAR = 276,
     ID = 277,
     FLOAT = 278,
     VOID = 279,
     STRING = 280,
     PUBLIC = 281,
     PRIVATE = 282,
     PROTECTED = 283,
     CLASS = 284,
     STATIC = 285,
     FINAL = 286,
     IF = 287,
     ELSE = 288,
     WHILE = 289,
     FOR = 290,
     RETURN = 291,
     MAIN = 292,
     ARGS = 293,
     CHARACTER = 294,
     NUMBER = 295,
     ERROR = 296,
     INC = 297,
     DEC = 298,
     SEMICOLON = 299,
     COMMA = 300,
     LPAREN = 301,
     RPAREN = 302,
     LBRACE = 303,
     RBRACE = 304,
     PLUSASG = 305,
     MINUSASG = 306,
     TIMESASG = 307,
     DIVIDEASG = 308,
     ASSIGN = 309,
     LBRACKET = 310,
     RBRACKET = 311,
     TRUE = 312,
     FALSE = 313
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 101 "java.y"

        struct SymbolTableEntry *symEntry;
        struct TreeNode* node;
    


/* Line 214 of yacc.c  */
#line 274 "java.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 286 "java.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    14,    22,    24,
      27,    28,    35,    37,    38,    46,    49,    52,    53,    55,
      57,    59,    63,    66,    67,    70,    72,    74,    76,    78,
      81,    82,    86,    89,    91,    93,    95,    97,    99,   101,
     103,   104,   107,   110,   114,   117,   119,   121,   123,   125,
     127,   134,   137,   138,   144,   154,   158,   161,   165,   168,
     170,   174,   177,   179,   180,   185,   188,   190,   192,   194,
     198,   200,   204,   207,   210,   212,   214,   216,   218,   220,
     224,   226,   230,   234,   237,   241,   245,   247,   249,   251,
     253,   255,   257,   259,   261,   263,   265,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   287,   289,   291,   294,
     299,   303,   307,   309,   310,   315
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    -1,     1,    49,    -1,    62,    -1,
      61,    62,    -1,    -1,    72,    29,    22,    63,    48,    64,
      49,    -1,    65,    -1,    64,    65,    -1,    -1,    72,    69,
      73,    22,    66,    67,    -1,    44,    -1,    -1,    46,    70,
      47,    48,    68,    76,    49,    -1,     1,    49,    -1,     1,
      44,    -1,    -1,    30,    -1,    31,    -1,    71,    -1,    70,
      45,    71,    -1,    70,    45,    -1,    -1,    73,    22,    -1,
      73,    -1,    26,    -1,    27,    -1,    28,    -1,    75,    74,
      -1,    -1,    74,    55,    56,    -1,     1,    44,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    23,    -1,    24,
      -1,    25,    -1,    -1,    76,    77,    -1,     1,    44,    -1,
      48,    76,    49,    -1,    87,    44,    -1,    78,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    32,    46,    91,
      47,    77,    79,    -1,    33,    77,    -1,    -1,    34,    46,
      91,    47,    77,    -1,    35,    46,    87,    44,    91,    44,
      87,    47,    77,    -1,    36,    87,    44,    -1,    36,    44,
      -1,    73,    84,    44,    -1,     1,    44,    -1,    85,    -1,
      84,    45,    85,    -1,     1,    44,    -1,    22,    -1,    -1,
      22,    86,    54,    87,    -1,     1,    45,    -1,    88,    -1,
      90,    -1,    91,    -1,    46,    87,    47,    -1,    95,    -1,
      22,    89,    87,    -1,    22,    42,    -1,    22,    43,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,
      87,    93,    87,    -1,    94,    -1,    91,     4,    91,    -1,
      91,     3,    91,    -1,    16,    91,    -1,    87,    92,    87,
      -1,    46,    91,    47,    -1,    57,    -1,    58,    -1,     6,
      -1,     5,    -1,    10,    -1,     9,    -1,     8,    -1,     7,
      -1,    12,    -1,    11,    -1,    15,    -1,    14,    -1,    13,
      -1,    40,    -1,    25,    -1,    39,    -1,    96,    -1,    97,
      -1,    98,    -1,    96,    17,    96,    -1,    22,    -1,    98,
      -1,    95,   100,    -1,    22,    46,    99,    47,    -1,    22,
      46,    47,    -1,    99,    45,    87,    -1,    87,    -1,    -1,
     100,    55,    87,    56,    -1,    55,    87,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   140,   142,   143,   148,   148,   153,   154,
     158,   158,   165,   167,   166,   174,   175,   177,   177,   177,
     179,   182,   187,   191,   197,   204,   209,   209,   210,   211,
     216,   217,   223,   226,   226,   227,   227,   228,   228,   229,
     231,   234,   238,   241,   242,   242,   242,   243,   243,   243,
     246,   252,   255,   259,   265,   270,   274,   280,   281,   283,
     286,   290,   293,   297,   297,   306,   308,   308,   309,   309,
     310,   312,   318,   325,   333,   333,   334,   334,   335,   337,
     341,   343,   349,   355,   361,   366,   369,   369,   371,   371,
     371,   372,   372,   372,   373,   373,   373,   374,   374,   375,
     375,   375,   376,   376,   376,   378,   379,   380,   382,   390,
     398,   406,   410,   411,   413,   419
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR", "AND", "NE", "EQ", "GE", "LE",
  "GT", "LT", "MINUS", "PLUS", "MOD", "DIVIDE", "TIMES", "NOT", "DOT",
  "INT", "DOUBLE", "BOOLEAN", "CHAR", "ID", "FLOAT", "VOID", "STRING",
  "PUBLIC", "PRIVATE", "PROTECTED", "CLASS", "STATIC", "FINAL", "IF",
  "ELSE", "WHILE", "FOR", "RETURN", "MAIN", "ARGS", "CHARACTER", "NUMBER",
  "ERROR", "INC", "DEC", "SEMICOLON", "COMMA", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "PLUSASG", "MINUSASG", "TIMESASG", "DIVIDEASG",
  "ASSIGN", "LBRACKET", "RBRACKET", "TRUE", "FALSE", "$accept", "program",
  "class_decl_list", "class_decl", "$@1", "member_decl_list",
  "member_decl", "$@2", "member_second_part", "$@3", "mdfr", "arg_list",
  "arg", "access_modfr", "TYPES", "empty_brackets", "TYPE", "stmt_list",
  "stmt", "if_stmt", "else_part", "while_stmt", "for_stmt", "return_stmt",
  "decl_stmt", "decl_ids", "decl_id", "$@4", "expr", "asg_expr", "asg_op",
  "arm_expr", "log_expr", "relop", "armop", "literal", "diff_ids",
  "mem_access", "array_acess", "method_call", "pass_args", "brackets", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    63,    62,    64,    64,
      66,    65,    67,    68,    67,    67,    67,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    73,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      78,    79,    79,    80,    81,    82,    82,    83,    83,    84,
      84,    84,    85,    86,    85,    85,    87,    87,    87,    87,
      87,    88,    88,    88,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    93,    93,    94,
      94,    94,    95,    95,    95,    96,    96,    96,    97,    98,
      98,    99,    99,    99,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     0,     7,     1,     2,
       0,     6,     1,     0,     7,     2,     2,     0,     1,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     2,
       0,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     3,     2,     1,     1,     1,     1,     1,
       6,     2,     0,     5,     9,     3,     2,     3,     2,     1,
       3,     2,     1,     0,     4,     2,     1,     1,     1,     3,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     2,     4,
       3,     3,     1,     0,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    26,    27,    28,     0,     2,     4,     0,     3,
       1,     5,     0,     6,     0,     0,     0,     8,    17,     7,
       9,    18,    19,     0,    33,    34,    35,    36,    37,    38,
      39,     0,     0,    10,     0,    29,     0,    32,     0,     0,
      12,    23,    11,    31,    16,    15,     0,    20,    25,    22,
       0,    24,    21,    13,     0,     0,     0,    42,     0,     0,
     106,   100,     0,     0,     0,     0,   101,    99,     0,     0,
      14,    86,    87,     0,    41,    45,    46,    47,    48,    49,
       0,    66,    67,    68,    80,    70,   102,   103,   104,    58,
     100,     0,    68,    72,    73,   113,    74,    75,    76,    77,
      78,     0,     0,     0,     0,    56,     0,     0,    68,     0,
       0,    62,     0,    59,    89,    88,    93,    92,    91,    90,
      95,    94,    98,    97,    96,    44,     0,     0,     0,     0,
       0,   108,     0,   110,   112,     0,    71,    68,    68,     0,
      55,    69,    85,    43,    61,    65,     0,    57,     0,    84,
      79,    68,    68,     0,     0,   106,   105,   107,     0,   109,
       0,     0,     0,     0,     0,    60,   115,     0,   111,    52,
      53,    68,    64,   114,     0,    50,     0,    51,     0,     0,
      54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    14,    16,    17,    36,    42,    54,
      23,    46,    47,     8,    73,    35,    32,    56,    74,    75,
     175,    76,    77,    78,    79,   112,   113,   146,    80,    81,
     101,    82,    83,   126,   127,    84,    85,    86,    87,    88,
     135,   131
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int16 yypact[] =
{
       1,   -42,   -87,   -87,   -87,    24,    38,   -87,     5,   -87,
     -87,   -87,    27,   -87,     4,    38,    13,   -87,   -20,   -87,
     -87,   -87,   -87,   344,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,    57,     3,   -87,    56,    50,     7,   -87,    53,   -23,
     -87,   344,   -87,   -87,   -87,   -87,   -15,   -87,    91,   344,
      70,   -87,   -87,   -87,    62,    77,   106,   -87,    79,   315,
     306,     0,    90,    93,    97,   284,   -87,   -87,   315,    62,
     -87,   -87,   -87,    32,   -87,   -87,   -87,   -87,   -87,   -87,
     369,   -87,   -87,    73,   -87,    82,   117,   -87,   130,   -87,
     -87,   431,    88,   -87,   -87,   286,   -87,   -87,   -87,   -87,
     -87,   315,   315,   315,   315,   -87,   380,   271,    10,   149,
      -7,    94,    45,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   315,   315,   315,   315,
     315,    96,   127,   -87,   431,    67,   431,    12,    14,   391,
     -87,   -87,   -87,   -87,   -87,   -87,    99,   -87,    34,   431,
     431,   174,   197,   249,   315,   110,   -87,   -87,   315,   -87,
     192,   192,   315,   315,   112,   -87,   -87,   260,   431,   125,
     -87,    16,   431,   -87,   192,   -87,   315,   -87,   282,   192,
     -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   153,   -87,   -87,   144,   -87,   -87,   -87,
     -87,   -87,   113,   100,   -18,   -87,   -87,    92,   -86,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,    18,   -87,   -59,   -87,
     -87,   -87,   -56,   -87,   -87,   -87,   -87,    43,   -87,    44,
     -87,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
      91,   -39,     1,    92,    34,    31,   106,     9,    39,   107,
      21,    22,   108,   128,   129,   128,   129,   128,   129,   128,
     129,    44,   -39,    48,    10,   -30,    45,     2,     3,     4,
      49,    48,    50,   110,    12,   164,   134,   144,   145,     2,
       3,     4,   136,    91,    91,   139,   137,   138,   -30,    13,
     -30,    40,    15,    41,   111,   -39,   111,   142,   -30,   160,
     176,   161,    19,    55,     2,     3,     4,   149,   150,    91,
      91,   153,   151,   152,   169,   170,   128,   129,   -40,    33,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   177,   147,
     148,   -83,   -83,   180,   -40,   167,   -40,   -40,   -40,   168,
      37,   -40,   -40,    91,   172,    38,   171,    58,   -40,    43,
     -40,   -40,   158,    51,   159,    18,    18,   178,    53,   -40,
     -40,    57,    59,    89,    24,    25,    26,    27,    60,    28,
      29,    61,   -83,   -83,   132,   -83,   102,   130,    62,   103,
      63,    64,    65,   104,   -83,    66,    67,  -107,   -63,   155,
      58,   154,    68,   163,    69,    70,    95,   145,   174,    11,
      20,   109,    52,    71,    72,    59,   165,    24,    25,    26,
      27,    60,    28,    29,    61,   156,   157,   -82,   129,     0,
       0,    62,     0,    63,    64,    65,     0,     0,    66,    67,
       0,     0,     0,    58,     0,    68,     0,    69,   143,     0,
     -81,   -81,     0,     0,     0,     0,    71,    72,    59,     0,
      24,    25,    26,    27,    60,    28,    29,    61,   -82,   -82,
       0,   -82,     0,     0,    62,     0,    63,    64,    65,     0,
     -82,    66,    67,     0,     0,     0,     0,     0,    68,     0,
      69,   -81,   -81,     0,   -81,     0,     0,     0,     0,    71,
      72,     0,     0,   -81,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,     0,
      59,     0,    59,     0,     0,   166,    60,     0,    60,    90,
       0,    90,     0,     0,     0,     0,   173,     0,   141,     0,
       0,     0,     0,    66,    67,    66,    67,     0,   105,   179,
      68,    59,    68,   133,     0,     0,     0,    60,     0,     0,
      90,    71,    72,    71,    72,     0,     0,     0,    93,    94,
       0,     0,    95,     0,    66,    67,    96,    97,    98,    99,
     100,    68,    24,    25,    26,    27,     0,    28,    29,    30,
       0,     0,    71,    72,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124
};

static const yytype_int16 yycheck[] =
{
      59,     1,     1,    59,     1,    23,    65,    49,     1,    68,
      30,    31,    68,     3,     4,     3,     4,     3,     4,     3,
       4,    44,    22,    41,     0,    22,    49,    26,    27,    28,
      45,    49,    47,     1,    29,     1,    95,    44,    45,    26,
      27,    28,   101,   102,   103,   104,   102,   103,    45,    22,
      47,    44,    48,    46,    22,    55,    22,    47,    55,    47,
      44,    47,    49,     1,    26,    27,    28,   126,   127,   128,
     129,   130,   128,   129,   160,   161,     3,     4,    16,    22,
      18,    19,    20,    21,    22,    23,    24,    25,   174,    44,
      45,     3,     4,   179,    32,   154,    34,    35,    36,   158,
      44,    39,    40,   162,   163,    55,   162,     1,    46,    56,
      48,    49,    45,    22,    47,    15,    16,   176,    48,    57,
      58,    44,    16,    44,    18,    19,    20,    21,    22,    23,
      24,    25,    44,    45,    17,    47,    46,    55,    32,    46,
      34,    35,    36,    46,    56,    39,    40,    17,    54,    22,
       1,    55,    46,    54,    48,    49,    46,    45,    33,     6,
      16,    69,    49,    57,    58,    16,   148,    18,    19,    20,
      21,    22,    23,    24,    25,   132,   132,     3,     4,    -1,
      -1,    32,    -1,    34,    35,    36,    -1,    -1,    39,    40,
      -1,    -1,    -1,     1,    -1,    46,    -1,    48,    49,    -1,
       3,     4,    -1,    -1,    -1,    -1,    57,    58,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    44,    45,
      -1,    47,    -1,    -1,    32,    -1,    34,    35,    36,    -1,
      56,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      48,    44,    45,    -1,    47,    -1,    -1,    -1,    -1,    57,
      58,    -1,    -1,    56,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      16,    -1,    16,    -1,    -1,    56,    22,    -1,    22,    25,
      -1,    25,    -1,    -1,    -1,    -1,    56,    -1,    47,    -1,
      -1,    -1,    -1,    39,    40,    39,    40,    -1,    44,    47,
      46,    16,    46,    47,    -1,    -1,    -1,    22,    -1,    -1,
      25,    57,    58,    57,    58,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,    -1,    39,    40,    50,    51,    52,    53,
      54,    46,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    -1,    57,    58,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    26,    27,    28,    60,    61,    62,    72,    49,
       0,    62,    29,    22,    63,    48,    64,    65,    72,    49,
      65,    30,    31,    69,    18,    19,    20,    21,    23,    24,
      25,    73,    75,    22,     1,    74,    66,    44,    55,     1,
      44,    46,    67,    56,    44,    49,    70,    71,    73,    45,
      47,    22,    71,    48,    68,     1,    76,    44,     1,    16,
      22,    25,    32,    34,    35,    36,    39,    40,    46,    48,
      49,    57,    58,    73,    77,    78,    80,    81,    82,    83,
      87,    88,    90,    91,    94,    95,    96,    97,    98,    44,
      25,    87,    91,    42,    43,    46,    50,    51,    52,    53,
      54,    89,    46,    46,    46,    44,    87,    87,    91,    76,
       1,    22,    84,    85,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    44,    92,    93,     3,     4,
      55,   100,    17,    47,    87,    99,    87,    91,    91,    87,
      44,    47,    47,    49,    44,    45,    86,    44,    45,    87,
      87,    91,    91,    87,    55,    22,    96,    98,    45,    47,
      47,    47,    44,    54,     1,    85,    56,    87,    87,    77,
      77,    91,    87,    56,    33,    79,    44,    77,    87,    47,
      77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 135 "java.y"
    {
            root=(yyval.node) = create_tree_node("program",st_program, 1, (yyvsp[(1) - (1)].node));
            printf("Parsing completed\n");
            inorder_traversal(root,0);
        ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 140 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 142 "java.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 143 "java.y"
    {
            (yyval.node)=(yyvsp[(1) - (2)].node);
            add_children((yyval.node),1,(yyvsp[(2) - (2)].node));
        ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 148 "java.y"
    { check_and_set_dType((yyvsp[(3) - (3)].symEntry), dt_class); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 148 "java.y"
    {
            struct TreeNode *n2=copy_entry_to_node((yyvsp[(2) - (7)].symEntry));
            struct TreeNode *n3=copy_entry_to_node((yyvsp[(3) - (7)].symEntry));
            (yyval.node) = create_tree_node("class_decl",st_class, 4, (yyvsp[(1) - (7)].node), n2, n3, (yyvsp[(6) - (7)].node));
        ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 153 "java.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 154 "java.y"
    {
            (yyval.node) = create_tree_node("member_decl_list",st_member_list, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 158 "java.y"
    { 
                check_and_set_dType((yyvsp[(4) - (4)].symEntry),(yyvsp[(3) - (4)].node)->dataType);
                set_dimension((yyvsp[(4) - (4)].symEntry),(yyvsp[(3) - (4)].node)->dimen);
            ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 161 "java.y"
    {
            struct TreeNode *n4 = copy_entry_to_node((yyvsp[(4) - (6)].symEntry));
            (yyval.node) = create_tree_node("member_decl",st_member, 5, (yyvsp[(1) - (6)].node), (yyvsp[(2) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(4) - (6)].symEntry),(yyvsp[(6) - (6)].node));
        ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 165 "java.y"
    { (yyval.node) = NULL;  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 167 "java.y"
    {
            set_member_method_values(peek_scope(scopeStack),(yyvsp[(-1) - (4)].symEntry), (yyvsp[(-2) - (4)].node)->dataType, (yyvsp[(2) - (4)].node));
        ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 169 "java.y"
    {
            
            (yyval.node) = create_tree_node("member_second_part",st_member_second, 2, (yyvsp[(2) - (7)].node), (yyvsp[(6) - (7)].node));
            
        ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 174 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 175 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 177 "java.y"
    { (yyval.node) = NULL;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 177 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 177 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 179 "java.y"
    {
            (yyval.node) = create_tree_node("arg_list", st_args, 1, (yyvsp[(1) - (1)].node));
        ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 182 "java.y"
    {
            // Add the new arg as a child of the existing arg_list node
            add_children((yyvsp[(1) - (3)].node), 1, (yyvsp[(3) - (3)].node));
            (yyval.node) = (yyvsp[(1) - (3)].node); // Set the result to the updated arg_list node
        ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 187 "java.y"
    {
                // This rule ensures that a comma without an argument following it is not accepted
                yyerror("Unexpected comma in argument list");
        ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 191 "java.y"
    {
            (yyval.node) = create_tree_node("arg_list", st_args, 0);
        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 197 "java.y"
    { 
                check_and_set_dType((yyvsp[(2) - (2)].symEntry),(yyvsp[(1) - (2)].node)->dataType);
                struct TreeNode *n2=copy_entry_to_node((yyvsp[(2) - (2)].symEntry));
                (yyval.node) = create_tree_node("arg", st_args,2, (yyvsp[(1) - (2)].node), n2);
                setDimension((yyval.node), (yyvsp[(1) - (2)].node)->dimen);            
                setDataType((yyval.node), (yyvsp[(1) - (2)].node)->dataType);
            ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 204 "java.y"
    {
                (yyval.node) = (yyvsp[(1) - (1)].node);
            ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 209 "java.y"
    {  (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 209 "java.y"
    {  (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 210 "java.y"
    {  (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 211 "java.y"
    {  
                (yyval.node) = create_tree_node("TYPE", st_types, 0);
                setDataType((yyval.node), (yyvsp[(1) - (2)].node)->dataType);
                setDimension((yyval.node), (yyvsp[(2) - (2)].node)->dimen);
            ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 216 "java.y"
    { (yyval.node) = create_tree_node("dimension",st_dimension,0); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 217 "java.y"
    { 
                //if(!$1)
                (yyval.node) = (yyvsp[(1) - (3)].node);
                setDimension((yyval.node), (yyvsp[(1) - (3)].node)->dimen + 1);  // Increase dimen by 1
                // printf("dimen: %d\n", $1->dimen);
            ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 223 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 226 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 226 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 227 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 227 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 228 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry));  ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 228 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 229 "java.y"
    {(yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 231 "java.y"
    {
            (yyval.node) = create_tree_node("stmt_list", st_stmt_list, 0); // If the statement list is empty, set the result to NULL
        ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 234 "java.y"
    {
            add_children((yyvsp[(1) - (2)].node), 1, (yyvsp[(2) - (2)].node));
            (yyval.node) = (yyvsp[(1) - (2)].node); // Set the result to the updated stmt_list node
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 238 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 241 "java.y"
    {  (yyval.node) = create_tree_node("stmt",st_stmt_list, 1, (yyvsp[(2) - (3)].node)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 242 "java.y"
    { (yyval.node)=(yyvsp[(1) - (2)].node); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 242 "java.y"
    {  (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 242 "java.y"
    {  (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 243 "java.y"
    {  (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 243 "java.y"
    {  (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 243 "java.y"
    {  (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 246 "java.y"
    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (6)].symEntry));
            (yyval.node) = create_tree_node("if_stmt", st_if, 4, n1, (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node), (yyvsp[(6) - (6)].node));
        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 252 "java.y"
    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (2)].symEntry));
            (yyval.node) = create_tree_node("else_part", st_else, 2, n1, (yyvsp[(2) - (2)].node));
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 255 "java.y"
    {
            (yyval.node) = NULL;
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 259 "java.y"
    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (5)].symEntry));
            (yyval.node) = create_tree_node("while_stmt", st_while, 3, n1, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
        ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 265 "java.y"
    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (9)].symEntry));
            (yyval.node) = create_tree_node("for_stmt", st_for, 5, n1, (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), (yyvsp[(9) - (9)].node));
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 270 "java.y"
    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (3)].symEntry));
            (yyval.node) = create_tree_node("return_stmt", st_return, 2, n1, (yyvsp[(2) - (3)].node));
        ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 274 "java.y"
    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (2)].symEntry));
            (yyval.node) = create_tree_node("return_stmt", st_return, 1, (yyvsp[(1) - (2)].symEntry));
        ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 280 "java.y"
    {  (yyval.node) = create_tree_node("decl_stmt",st_stmt, 2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 281 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 283 "java.y"
    {
            (yyval.node) = create_tree_node("decl_ids", st_decl_ids, 1, (yyvsp[(1) - (1)].node));
        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 286 "java.y"
    {
            add_children((yyvsp[(1) - (3)].node), 1, (yyvsp[(3) - (3)].node));
            (yyval.node) = (yyvsp[(1) - (3)].node); // Set the result to the updated decl_ids node
        ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 290 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 293 "java.y"
    {
            check_and_set_dType((yyvsp[(1) - (1)].symEntry),(yyvsp[(0) - (1)].node)->dataType);
            set_dimension((yyvsp[(1) - (1)].symEntry),(yyvsp[(0) - (1)].node)->dimen);
            (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry));
        ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 297 "java.y"
    {
            check_and_set_dType((yyvsp[(1) - (1)].symEntry),(yyvsp[(0) - (1)].node)->dataType);
            set_dimension((yyvsp[(1) - (1)].symEntry),(yyvsp[(0) - (1)].node)->dimen);
            //printf("----------------------------->dimension :%d\n",$1->dimen);
        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 301 "java.y"
    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (4)].symEntry));
            struct TreeNode *n3= copy_entry_to_node((yyvsp[(3) - (4)].symEntry));
            (yyval.node) = create_tree_node("assign_expr",st_expr, 3, n3, n1, (yyvsp[(4) - (4)].node));
        ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 306 "java.y"
    { yyerror("Syntax error"); (yyval.node) = NULL; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 308 "java.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 308 "java.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 309 "java.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 309 "java.y"
    { (yyval.node)=(yyvsp[(2) - (3)].node); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 310 "java.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 312 "java.y"
    {
            is_defined((yyvsp[(1) - (3)].symEntry));
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (3)].symEntry));
            checkType(n1,(yyvsp[(3) - (3)].node),yylineno);
            (yyval.node) = create_tree_node("asg_expr",st_expr, 3, (yyvsp[(2) - (3)].node), n1, (yyvsp[(3) - (3)].node));
        ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 318 "java.y"
    {
            is_defined((yyvsp[(1) - (2)].symEntry));
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (2)].symEntry));
            checkdType(n1,dt_integer,0,yylineno);
            struct TreeNode *n2=copy_entry_to_node((yyvsp[(2) - (2)].symEntry));
            (yyval.node) = create_tree_node("asg_expr",st_expr, 2, n2, n1);
        ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 325 "java.y"
    {
            is_defined((yyvsp[(1) - (2)].symEntry));
            struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (2)].symEntry));
            checkdType(n1,dt_integer,0,yylineno);
            struct TreeNode *n2=copy_entry_to_node((yyvsp[(2) - (2)].symEntry));
            (yyval.node) = create_tree_node("asg_expr",st_expr, 2, (yyvsp[(2) - (2)].symEntry), n1);
        ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 333 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 333 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 334 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 334 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 335 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 337 "java.y"
    {
                checkType((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),yylineno);
                (yyval.node) = create_tree_node("arm_expr",st_expr, 3, (yyvsp[(2) - (3)].node), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                setDataType((yyval.node), (yyvsp[(1) - (3)].node)->dataType);
            ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 341 "java.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 343 "java.y"
    {
                checkType((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),yylineno);
                struct TreeNode *n2=copy_entry_to_node((yyvsp[(2) - (3)].symEntry));
                (yyval.node) = create_tree_node("log_expr",st_log_expr, 3, n2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                setDataType((yyval.node), (yyvsp[(1) - (3)].node)->dataType);
            ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 349 "java.y"
    {
                checkType((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),yylineno);
                struct TreeNode *n2=copy_entry_to_node((yyvsp[(2) - (3)].symEntry));
                (yyval.node) = create_tree_node("log_expr",st_log_expr, 3, n2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                setDataType((yyval.node), (yyvsp[(1) - (3)].node)->dataType);
            ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 355 "java.y"
    {
                checkdType((yyvsp[(2) - (2)].node),dt_boolean,0,yylineno);
                struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (2)].symEntry));
                (yyval.node) = create_tree_node("log_expr",st_log_expr, 2, n1, (yyvsp[(2) - (2)].node));
                setDataType((yyval.node), (yyvsp[(2) - (2)].node)->dataType);
            ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 361 "java.y"
    {  
                checkType((yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node),yylineno);         
                (yyval.node) = create_tree_node("log_expr",st_log_expr, 3, (yyvsp[(2) - (3)].node), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                setDataType((yyval.node), dt_boolean);
            ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 366 "java.y"
    {
                checkdType((yyvsp[(2) - (3)].node),dt_boolean,0,yylineno);
                (yyval.node) = (yyvsp[(2) - (3)].node);
            ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 369 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 369 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 371 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 371 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 371 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 372 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 372 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 372 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 373 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 373 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 373 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 374 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 374 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 375 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 375 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 375 "java.y"
    { (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 376 "java.y"
    { (yyval.node)=(yyvsp[(1) - (1)].node); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 376 "java.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 376 "java.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 378 "java.y"
    { (yyval.node) = create_tree_node("mem_access",st_mem_access, 3, (yyvsp[(2) - (3)].symEntry), (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 379 "java.y"
    { is_defined((yyvsp[(1) - (1)].symEntry)); (yyval.node)=copy_entry_to_node((yyvsp[(1) - (1)].symEntry)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 380 "java.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 382 "java.y"
    { 
                is_defined((yyvsp[(1) - (2)].node)->entry);
                check_array_access((yyvsp[(1) - (2)].node)->entry,(yyvsp[(2) - (2)].node)->dimen,yylineno);
                (yyval.node) = create_tree_node("array_acess",st_array_access, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); 
                setDataType((yyval.node), (yyvsp[(1) - (2)].node)->entry->dataType);
                setDimension((yyval.node), (yyvsp[(1) - (2)].node)->entry->dimen-(yyvsp[(2) - (2)].node)->dimen); 
                printf("--------->dimesion : %d\n",(yyval.node)->dimen);// Set dimension to the difference of the two dimensions
            ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 390 "java.y"
    { 
                is_defined((yyvsp[(1) - (4)].symEntry));
                is_method((yyvsp[(1) - (4)].symEntry));
                check_method_args((yyvsp[(1) - (4)].symEntry),(yyvsp[(3) - (4)].node),yylineno);
                struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (4)].symEntry)); 
                (yyval.node) = create_tree_node("method_call",st_method_call, 2, n1, (yyvsp[(3) - (4)].node));
                setDataType((yyval.node), (yyvsp[(1) - (4)].symEntry)->dataType);
                setDimension((yyval.node), 0);  ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 398 "java.y"
    { 
                is_defined((yyvsp[(1) - (3)].symEntry));
                is_method((yyvsp[(1) - (3)].symEntry));
                check_method_args((yyvsp[(1) - (3)].symEntry),NULL,yylineno);
                struct TreeNode *n1=copy_entry_to_node((yyvsp[(1) - (3)].symEntry));
                (yyval.node) = create_tree_node("method_call", st_method_call,1,n1); 
            ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 406 "java.y"
    { 
                (yyval.node) = (yyvsp[(1) - (3)].node);
                add_children((yyval.node), 1, (yyvsp[(3) - (3)].node));
            ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 410 "java.y"
    { (yyval.node) = create_tree_node("pass_args",st_pass_args, 1, (yyvsp[(1) - (1)].node)); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 411 "java.y"
    { (yyval.node) = NULL; ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 413 "java.y"
    {
                (yyval.node) = (yyvsp[(1) - (4)].node);
                checkdType((yyvsp[(1) - (4)].node),dt_integer,0,yylineno);
                add_children((yyval.node), 1, (yyvsp[(3) - (4)].node));
                setDimension((yyval.node),(yyval.node)->dimen + 1); // Increment dimension by 1
            ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 419 "java.y"
    {
                checkdType((yyvsp[(2) - (3)].node),dt_integer,0,yylineno);
                (yyval.node) = create_tree_node("brackets", st_expr, 1, (yyvsp[(2) - (3)].node));
                setDimension((yyval.node), 1); // Set dimension to 1 for single brackets
            ;}
    break;



/* Line 1455 of yacc.c  */
#line 2680 "java.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 425 "java.y"


// Main function (entry point)
int main(int argc, char *argv[]) {
    store_keywords(reservedKeywords);
    printf("Starting...\n");
    FILE *input_file;
    // Ensure correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    // Open input file
    input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }
    // Redirect input to the file
    printf("Parsing...\n");
    symbolTable=new_table(NULL);
    constants=new_table(NULL);
    scopeStack = malloc(sizeof(struct ScopeStack));
    push_scope(scopeStack, symbolTable);
    yyrestart(input_file);
    yyparse();
    // print_table(symbolTable);
    // print_table(constants);
    // 
    // print_parse_table();
    // show_tree_view(root);
    // free_tree(root);
    fclose(input_file);
    
    return 0;
}


