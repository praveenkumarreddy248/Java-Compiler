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
#line 1 "java.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "SymbolTable.h"
    #include "TreeNode.h"
    #include "java.tab.h"
    #include "Code.h"

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

    extern struct ThreeAddressCode* newThreeAddressCode(char* result, char* operation, char* operand1, char* operand2);
    extern List* newList(int i);
    extern List* mergeLists(List* l1, List* l2);
    int labelNo=1;
    int tempNo=1;
    struct TreeNode *root=NULL;
    struct SymbolTable* symbolTable=NULL;
    struct ThreeAddressCode* icg[10000];
    int indx=0;

    //fun for new label
    char* new_label(){
        char *label = malloc(10);
        sprintf(label, "L%d", labelNo++);
        return label;
    }
    //fun for new temp
    char* new_temp(){
        char *temp = malloc(10);
        sprintf(temp, "t%d", tempNo++);
        return temp;
    }
    void codeGen(char*operation, char*arg1, char*arg2, char*result){
        icg[indx++]=newThreeAddressCode(result,operation,arg1,arg2);
    }
    void backpatch(List* list, int label){
        // printf("backpatching %d\n",label);
        List* temp=list;
        while(temp){
            char *x=malloc(10);
            sprintf(x,"L%d",label);
            icg[temp->current]->result=x;
            temp=temp->next;
        }  
    }
    //fun to print icg
    void print_icg(){
        printf("Intermediate Code Generation\n");
        // printf("Index Operation   Operand1   Operand2     Result\n");
        for(int i=0;i<indx;i++){
            if(icg[i]->operation[0]=='g'){
                printf("%2d %s %s\n",i,icg[i]->operation,icg[i]->result);
            }else if(icg[i]->operation[0]=='='){
                printf("%2d %s = %s\n",i,icg[i]->result,icg[i]->operand1);
            }else if(icg[i]->operation[0]=='i'){
                printf("%2d %s %s %s %s\n",i,icg[i]->operation,icg[i]->operand1,icg[i]->operand2,icg[i]->result);
            }else if(icg[i]->operation[0]=='p'){
                printf("%2d %s %s\n",i,icg[i]->operation,icg[i]->operand1);
            }else if(icg[i]->operation[0]=='c'){
                printf("%2d %s %s %s\n",i,icg[i]->operation,icg[i]->operand1,icg[i]->operand2);
            }else
            printf("%2d %s = %s %s %s\n",i,icg[i]->result,icg[i]->operand1,icg[i]->operation,icg[i]->operand2);
        }
    }

    



#line 192 "java.tab.c"

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

#include "java.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_DOUBLE = 4,                     /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_PUBLIC = 11,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 12,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 13,                 /* PROTECTED  */
  YYSYMBOL_CLASS = 14,                     /* CLASS  */
  YYSYMBOL_STATIC = 15,                    /* STATIC  */
  YYSYMBOL_FINAL = 16,                     /* FINAL  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_MAIN = 22,                      /* MAIN  */
  YYSYMBOL_ARGS = 23,                      /* ARGS  */
  YYSYMBOL_CHARACTER = 24,                 /* CHARACTER  */
  YYSYMBOL_NUMBER = 25,                    /* NUMBER  */
  YYSYMBOL_ERROR = 26,                     /* ERROR  */
  YYSYMBOL_INC = 27,                       /* INC  */
  YYSYMBOL_DEC = 28,                       /* DEC  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_LPAREN = 31,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 32,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 33,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 34,                    /* RBRACE  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_LBRACKET = 39,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 40,                  /* RBRACKET  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_NE = 42,                        /* NE  */
  YYSYMBOL_LT = 43,                        /* LT  */
  YYSYMBOL_GT = 44,                        /* GT  */
  YYSYMBOL_LE = 45,                        /* LE  */
  YYSYMBOL_GE = 46,                        /* GE  */
  YYSYMBOL_TRUE = 47,                      /* TRUE  */
  YYSYMBOL_FALSE = 48,                     /* FALSE  */
  YYSYMBOL_TIMES = 49,                     /* TIMES  */
  YYSYMBOL_PLUS = 50,                      /* PLUS  */
  YYSYMBOL_MINUS = 51,                     /* MINUS  */
  YYSYMBOL_DIVIDE = 52,                    /* DIVIDE  */
  YYSYMBOL_MOD = 53,                       /* MOD  */
  YYSYMBOL_PLUSASG = 54,                   /* PLUSASG  */
  YYSYMBOL_MINUSASG = 55,                  /* MINUSASG  */
  YYSYMBOL_TIMESASG = 56,                  /* TIMESASG  */
  YYSYMBOL_DIVIDEASG = 57,                 /* DIVIDEASG  */
  YYSYMBOL_ASSIGN = 58,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_class_decl_list = 61,           /* class_decl_list  */
  YYSYMBOL_class_decl = 62,                /* class_decl  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_member_decl_list = 64,          /* member_decl_list  */
  YYSYMBOL_member_decl = 65,               /* member_decl  */
  YYSYMBOL_66_2 = 66,                      /* $@2  */
  YYSYMBOL_member_second_part = 67,        /* member_second_part  */
  YYSYMBOL_68_3 = 68,                      /* $@3  */
  YYSYMBOL_mdfr = 69,                      /* mdfr  */
  YYSYMBOL_arg_list = 70,                  /* arg_list  */
  YYSYMBOL_arg = 71,                       /* arg  */
  YYSYMBOL_access_modfr = 72,              /* access_modfr  */
  YYSYMBOL_TYPES = 73,                     /* TYPES  */
  YYSYMBOL_empty_brackets = 74,            /* empty_brackets  */
  YYSYMBOL_TYPE = 75,                      /* TYPE  */
  YYSYMBOL_stmt_list = 76,                 /* stmt_list  */
  YYSYMBOL_stmt = 77,                      /* stmt  */
  YYSYMBOL_if_stmt = 78,                   /* if_stmt  */
  YYSYMBOL_N = 79,                         /* N  */
  YYSYMBOL_M = 80,                         /* M  */
  YYSYMBOL_while_stmt = 81,                /* while_stmt  */
  YYSYMBOL_for_stmt = 82,                  /* for_stmt  */
  YYSYMBOL_return_stmt = 83,               /* return_stmt  */
  YYSYMBOL_decl_stmt = 84,                 /* decl_stmt  */
  YYSYMBOL_decl_ids = 85,                  /* decl_ids  */
  YYSYMBOL_decl_id = 86,                   /* decl_id  */
  YYSYMBOL_87_4 = 87,                      /* $@4  */
  YYSYMBOL_expr = 88,                      /* expr  */
  YYSYMBOL_asg_expr = 89,                  /* asg_expr  */
  YYSYMBOL_asg_op = 90,                    /* asg_op  */
  YYSYMBOL_arm_expr = 91,                  /* arm_expr  */
  YYSYMBOL_log_expr = 92,                  /* log_expr  */
  YYSYMBOL_relop = 93,                     /* relop  */
  YYSYMBOL_armop = 94,                     /* armop  */
  YYSYMBOL_literal = 95,                   /* literal  */
  YYSYMBOL_diff_ids = 96,                  /* diff_ids  */
  YYSYMBOL_mem_access = 97,                /* mem_access  */
  YYSYMBOL_array_acess = 98,               /* array_acess  */
  YYSYMBOL_method_call = 99,               /* method_call  */
  YYSYMBOL_pass_args = 100,                /* pass_args  */
  YYSYMBOL_brackets = 101                  /* brackets  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   156,   158,   159,   164,   164,   169,   170,
     174,   174,   181,   183,   182,   190,   191,   193,   193,   193,
     195,   198,   203,   207,   213,   220,   225,   225,   226,   227,
     232,   233,   239,   242,   242,   243,   243,   244,   244,   245,
     247,   250,   257,   260,   261,   261,   261,   262,   262,   262,
     265,   270,   279,   280,   281,   293,   307,   312,   319,   320,
     322,   325,   329,   332,   336,   336,   346,   348,   348,   349,
     349,   350,   352,   359,   368,   377,   377,   378,   378,   379,
     381,   386,   388,   397,   406,   414,   434,   437,   438,   441,
     441,   441,   442,   442,   442,   443,   444,   444,   445,   445,
     446,   446,   446,   447,   447,   447,   449,   450,   451,   453,
     468,   482,   490,   494,   495,   497,   503
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "DOUBLE",
  "BOOLEAN", "CHAR", "ID", "FLOAT", "VOID", "STRING", "PUBLIC", "PRIVATE",
  "PROTECTED", "CLASS", "STATIC", "FINAL", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "MAIN", "ARGS", "CHARACTER", "NUMBER", "ERROR", "INC", "DEC",
  "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "AND",
  "OR", "NOT", "DOT", "LBRACKET", "RBRACKET", "EQ", "NE", "LT", "GT", "LE",
  "GE", "TRUE", "FALSE", "TIMES", "PLUS", "MINUS", "DIVIDE", "MOD",
  "PLUSASG", "MINUSASG", "TIMESASG", "DIVIDEASG", "ASSIGN", "$accept",
  "program", "class_decl_list", "class_decl", "$@1", "member_decl_list",
  "member_decl", "$@2", "member_second_part", "$@3", "mdfr", "arg_list",
  "arg", "access_modfr", "TYPES", "empty_brackets", "TYPE", "stmt_list",
  "stmt", "if_stmt", "N", "M", "while_stmt", "for_stmt", "return_stmt",
  "decl_stmt", "decl_ids", "decl_id", "$@4", "expr", "asg_expr", "asg_op",
  "arm_expr", "log_expr", "relop", "armop", "literal", "diff_ids",
  "mem_access", "array_acess", "method_call", "pass_args", "brackets", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-109)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -30,  -121,  -121,  -121,    14,    99,  -121,    19,  -121,
    -121,  -121,    36,  -121,    17,    99,     5,  -121,    88,  -121,
    -121,  -121,  -121,   354,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,    52,    12,  -121,    34,    33,     0,  -121,    42,    35,
    -121,   354,  -121,  -121,  -121,  -121,    49,  -121,    69,   354,
      65,  -121,  -121,  -121,   127,    66,    72,  -121,  -121,   162,
      84,    29,     8,    89,  -121,    91,     1,  -121,  -121,   166,
     127,   166,  -121,  -121,    20,  -121,  -121,  -121,  -121,  -121,
    -121,   175,  -121,  -121,    82,  -121,  -121,    77,  -121,    86,
    -121,  -121,  -121,    30,   166,  -121,  -121,  -121,  -121,  -121,
     166,    90,   166,   112,   166,  -121,  -121,   193,   226,   106,
     111,   282,    61,   110,   101,   126,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,   166,
     166,  -121,  -121,   142,  -121,   282,    62,   255,   282,   166,
     118,   166,   211,  -121,  -121,  -121,  -121,  -121,  -121,   104,
    -121,    45,   282,   282,   166,   166,   146,    77,  -121,   166,
    -121,  -121,   269,  -121,   153,   166,   166,   148,  -121,   307,
     316,   282,  -121,   162,  -121,    73,   282,  -121,   162,  -121,
     139,  -121,   166,  -121,   241,   162,   162,  -121,  -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    26,    27,    28,     0,     2,     4,     0,     3,
       1,     5,     0,     6,     0,     0,     0,     8,    17,     7,
       9,    18,    19,     0,    33,    34,    35,    36,    37,    38,
      39,     0,     0,    10,     0,    29,     0,    32,     0,     0,
      12,    23,    11,    31,    16,    15,     0,    20,    25,    22,
       0,    24,    21,    13,     0,     0,    53,    42,    14,     0,
       0,   107,   101,     0,    53,     0,     0,   102,   100,     0,
       0,     0,    87,    88,     0,    41,    45,    46,    47,    48,
      49,     0,    67,    68,    69,    81,    71,   103,   104,   105,
      59,    73,    74,   114,     0,    75,    76,    77,    78,    79,
       0,   109,     0,     0,     0,   101,    57,     0,     0,    69,
      53,     0,    69,     0,    63,     0,    60,    44,    89,    90,
      91,    92,    93,    94,    95,    98,    99,    96,    97,     0,
       0,    53,    53,     0,   111,   113,     0,     0,    72,     0,
      69,     0,     0,    56,    70,    86,    43,    62,    66,     0,
      58,     0,    85,    80,     0,     0,   107,   106,   108,     0,
     110,   116,     0,    53,    69,     0,     0,     0,    61,    69,
      69,   112,   115,     0,    53,    69,    65,    50,     0,    53,
       0,    54,     0,    53,     0,     0,     0,    51,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,   174,  -121,  -121,   168,  -121,  -121,  -121,
    -121,  -121,   143,   185,   -21,  -121,  -121,   124,  -120,  -121,
    -121,   -58,  -121,  -121,  -121,  -121,  -121,    47,  -121,   -59,
    -121,  -121,  -121,   -66,  -121,  -121,  -121,  -121,    63,  -121,
      74,  -121,  -121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    14,    16,    17,    36,    42,    54,
      23,    46,    47,     8,    74,    35,    32,    56,    75,    76,
     180,    59,    77,    78,    79,    80,   115,   116,   149,   111,
      82,   100,    83,    84,   129,   130,    85,    86,    87,    88,
      89,   136,   101
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    39,    31,   109,     9,   112,   103,   107,    61,   -39,
     108,   105,     1,    34,    10,   -39,     2,     3,     4,   -30,
      48,   113,     2,     3,     4,    67,    68,   114,    48,    40,
     106,    41,    69,    12,   135,   137,   140,    61,    71,    19,
     105,   138,   -30,    13,   -30,   142,   167,   -39,    72,    73,
      15,   -30,   114,   177,    67,    68,    91,    92,   181,    33,
      93,    69,   134,    37,    44,   187,   188,    71,    94,    45,
     152,   153,    38,   154,   155,   164,    51,    72,    73,    49,
     162,    50,    43,    95,    96,    97,    98,    99,   169,   170,
     -84,   -84,   159,   -84,   160,    57,   131,   132,    53,   175,
     171,   -84,   179,    21,    22,   173,    58,   176,   131,   132,
       2,     3,     4,    90,    81,   133,   178,   131,   132,    81,
     102,   182,   104,   184,  -108,   185,    81,    81,    55,   139,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   145,   147,
     148,   131,   132,   141,   -40,   146,   -40,   -40,   -40,   156,
     163,   -40,   -40,   131,   132,   150,   151,   183,   -40,   -64,
     -40,   -40,   166,    60,   -40,    24,    25,    26,    27,    61,
      28,    29,    62,    61,   -40,   -40,   105,    93,   148,    63,
      11,    64,    65,    66,    20,   174,    67,    68,   131,   132,
      67,    68,    52,    69,   110,    70,   157,    69,   168,    71,
      18,    18,     0,    71,   117,     0,     0,   158,     0,    72,
      73,     0,     0,    72,    73,     0,   118,   119,   120,   121,
     122,   123,   143,     0,   124,   125,   126,   127,   128,     0,
       0,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     165,     0,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   144,     0,
     124,   125,   126,   127,   128,     0,     0,   118,   119,   120,
     121,   122,   123,   186,     0,   124,   125,   126,   127,   128,
       0,     0,   118,   119,   120,   121,   122,   123,     0,     0,
     124,   125,   126,   127,   128,   161,   118,   119,   120,   121,
     122,   123,     0,     0,   124,   125,   126,   127,   128,   172,
     118,   119,   120,   121,   122,   123,     0,     0,   124,   125,
     126,   127,   128,   118,   119,   120,   121,   122,   123,     0,
       0,   124,   125,   126,   127,   128,   -82,   -82,     0,   -82,
       0,     0,   131,   132,     0,   -83,   -83,   -82,   -83,     0,
       0,   131,   132,     0,     0,     0,   -83,    24,    25,    26,
      27,     0,    28,    29,    30
};

static const yytype_int16 yycheck[] =
{
      59,     1,    23,    69,    34,    71,    64,    66,     7,     1,
      69,    10,     1,     1,     0,     7,    11,    12,    13,     7,
      41,     1,    11,    12,    13,    24,    25,     7,    49,    29,
      29,    31,    31,    14,    93,    94,   102,     7,    37,    34,
      10,   100,    30,     7,    32,   104,     1,    39,    47,    48,
      33,    39,     7,   173,    24,    25,    27,    28,   178,     7,
      31,    31,    32,    29,    29,   185,   186,    37,    39,    34,
     129,   130,    39,   131,   132,   141,     7,    47,    48,    30,
     139,    32,    40,    54,    55,    56,    57,    58,   154,   155,
      29,    30,    30,    32,    32,    29,    35,    36,    33,   165,
     159,    40,    29,    15,    16,   163,    34,   166,    35,    36,
      11,    12,    13,    29,   173,    38,   174,    35,    36,   178,
      31,   179,    31,   182,    38,   183,   185,   186,     1,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    32,    29,
      30,    35,    36,    31,    17,    34,    19,    20,    21,     7,
      32,    24,    25,    35,    36,    29,    30,    18,    31,    58,
      33,    34,    58,     1,    37,     3,     4,     5,     6,     7,
       8,     9,    10,     7,    47,    48,    10,    31,    30,    17,
       6,    19,    20,    21,    16,    32,    24,    25,    35,    36,
      24,    25,    49,    31,    70,    33,   133,    31,   151,    37,
      15,    16,    -1,    37,    29,    -1,    -1,   133,    -1,    47,
      48,    -1,    -1,    47,    48,    -1,    41,    42,    43,    44,
      45,    46,    29,    -1,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      29,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    32,    -1,
      49,    50,    51,    52,    53,    -1,    -1,    41,    42,    43,
      44,    45,    46,    32,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      49,    50,    51,    52,    53,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49,    50,    51,    52,    53,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    49,    50,
      51,    52,    53,    41,    42,    43,    44,    45,    46,    -1,
      -1,    49,    50,    51,    52,    53,    29,    30,    -1,    32,
      -1,    -1,    35,    36,    -1,    29,    30,    40,    32,    -1,
      -1,    35,    36,    -1,    -1,    -1,    40,     3,     4,     5,
       6,    -1,     8,     9,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    11,    12,    13,    60,    61,    62,    72,    34,
       0,    62,    14,     7,    63,    33,    64,    65,    72,    34,
      65,    15,    16,    69,     3,     4,     5,     6,     8,     9,
      10,    73,    75,     7,     1,    74,    66,    29,    39,     1,
      29,    31,    67,    40,    29,    34,    70,    71,    73,    30,
      32,     7,    71,    33,    68,     1,    76,    29,    34,    80,
       1,     7,    10,    17,    19,    20,    21,    24,    25,    31,
      33,    37,    47,    48,    73,    77,    78,    81,    82,    83,
      84,    88,    89,    91,    92,    95,    96,    97,    98,    99,
      29,    27,    28,    31,    39,    54,    55,    56,    57,    58,
      90,   101,    31,    80,    31,    10,    29,    88,    88,    92,
      76,    88,    92,     1,     7,    85,    86,    29,    41,    42,
      43,    44,    45,    46,    49,    50,    51,    52,    53,    93,
      94,    35,    36,    38,    32,    88,   100,    88,    88,    39,
      92,    31,    88,    29,    32,    32,    34,    29,    30,    87,
      29,    30,    88,    88,    80,    80,     7,    97,    99,    30,
      32,    40,    88,    32,    92,    29,    58,     1,    86,    92,
      92,    88,    40,    80,    32,    92,    88,    77,    80,    29,
      79,    77,    80,    18,    88,    80,    32,    77,    77
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    63,    62,    64,    64,
      66,    65,    67,    68,    67,    67,    67,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    73,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    79,    80,    81,    82,    83,    83,    84,    84,
      85,    85,    85,    86,    87,    86,    86,    88,    88,    88,
      88,    88,    89,    89,    89,    90,    90,    90,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    94,    94,
      95,    95,    95,    96,    96,    96,    97,    97,    97,    98,
      99,    99,   100,   100,   100,   101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     0,     7,     1,     2,
       0,     6,     1,     0,     7,     2,     2,     0,     1,     1,
       1,     3,     2,     0,     2,     1,     1,     1,     1,     2,
       0,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     2,     3,     2,     1,     1,     1,     1,     1,
       6,    10,     0,     0,     7,    10,     3,     2,     3,     2,
       1,     3,     2,     1,     0,     4,     2,     1,     1,     1,
       3,     1,     3,     2,     2,     1,     1,     1,     1,     1,
       3,     1,     4,     4,     2,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       4,     3,     3,     1,     0,     4,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: class_decl_list  */
#line 151 "java.y"
                          {
            root=(yyval.node) = create_tree_node("program",st_program, 1, (yyvsp[0].node));
            printf("Parsing completed\n");
            // inorder_traversal(root,0);
        }
#line 1726 "java.tab.c"
    break;

  case 3: /* program: error RBRACE  */
#line 156 "java.y"
                       { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 1732 "java.tab.c"
    break;

  case 4: /* class_decl_list: class_decl  */
#line 158 "java.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1738 "java.tab.c"
    break;

  case 5: /* class_decl_list: class_decl_list class_decl  */
#line 159 "java.y"
                                     {
            (yyval.node)=(yyvsp[-1].node);
            add_children((yyval.node),1,(yyvsp[0].node));
        }
#line 1747 "java.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 164 "java.y"
                                   { check_and_set_dType((yyvsp[0].symEntry), dt_class); }
#line 1753 "java.tab.c"
    break;

  case 7: /* class_decl: access_modfr CLASS ID $@1 LBRACE member_decl_list RBRACE  */
#line 164 "java.y"
                                                                                                         {
            struct TreeNode *n2=copy_entry_to_node((yyvsp[-5].symEntry));
            struct TreeNode *n3=copy_entry_to_node((yyvsp[-4].symEntry));
            (yyval.node) = create_tree_node("class_decl",st_class, 4, (yyvsp[-6].node), n2, n3, (yyvsp[-1].node));
        }
#line 1763 "java.tab.c"
    break;

  case 8: /* member_decl_list: member_decl  */
#line 169 "java.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1769 "java.tab.c"
    break;

  case 9: /* member_decl_list: member_decl_list member_decl  */
#line 170 "java.y"
                                       {
            (yyval.node) = create_tree_node("member_decl_list",st_member_list, 2, (yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1777 "java.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 174 "java.y"
                                         { 
                check_and_set_dType((yyvsp[0].symEntry),(yyvsp[-1].node)->dataType);
                set_dimension((yyvsp[0].symEntry),(yyvsp[-1].node)->dimen);
            }
#line 1786 "java.tab.c"
    break;

  case 11: /* member_decl: access_modfr mdfr TYPES ID $@2 member_second_part  */
#line 177 "java.y"
                                 {
            struct TreeNode *n4 = copy_entry_to_node((yyvsp[-2].symEntry));
            (yyval.node) = create_tree_node("member_decl",st_member, 5, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].symEntry),(yyvsp[0].node));
        }
#line 1795 "java.tab.c"
    break;

  case 12: /* member_second_part: SEMICOLON  */
#line 181 "java.y"
                               { (yyval.node) = NULL;  }
#line 1801 "java.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 183 "java.y"
               {
            set_member_method_values(peek_scope(scopeStack),(yyvsp[(-1) - (4)].symEntry), (yyvsp[(-2) - (4)].node)->dataType, (yyvsp[-2].node));
        }
#line 1809 "java.tab.c"
    break;

  case 14: /* member_second_part: LPAREN arg_list RPAREN LBRACE $@3 stmt_list RBRACE  */
#line 185 "java.y"
                           {
            
            (yyval.node) = create_tree_node("member_second_part",st_member_second, 2, (yyvsp[-5].node), (yyvsp[-1].node));
            
        }
#line 1819 "java.tab.c"
    break;

  case 15: /* member_second_part: error RBRACE  */
#line 190 "java.y"
                       { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 1825 "java.tab.c"
    break;

  case 16: /* member_second_part: error SEMICOLON  */
#line 191 "java.y"
                          { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 1831 "java.tab.c"
    break;

  case 17: /* mdfr: %empty  */
#line 193 "java.y"
          { (yyval.node) = NULL;}
#line 1837 "java.tab.c"
    break;

  case 18: /* mdfr: STATIC  */
#line 193 "java.y"
                                { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry));}
#line 1843 "java.tab.c"
    break;

  case 19: /* mdfr: FINAL  */
#line 193 "java.y"
                                                                     { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry));}
#line 1849 "java.tab.c"
    break;

  case 20: /* arg_list: arg  */
#line 195 "java.y"
              {
            (yyval.node) = create_tree_node("arg_list", st_args, 1, (yyvsp[0].node));
        }
#line 1857 "java.tab.c"
    break;

  case 21: /* arg_list: arg_list COMMA arg  */
#line 198 "java.y"
                             {
            // Add the new arg as a child of the existing arg_list node
            add_children((yyvsp[-2].node), 1, (yyvsp[0].node));
            (yyval.node) = (yyvsp[-2].node); // Set the result to the updated arg_list node
        }
#line 1867 "java.tab.c"
    break;

  case 22: /* arg_list: arg_list COMMA  */
#line 203 "java.y"
                                    {
                // This rule ensures that a comma without an argument following it is not accepted
                yyerror("Unexpected comma in argument list");
        }
#line 1876 "java.tab.c"
    break;

  case 23: /* arg_list: %empty  */
#line 207 "java.y"
                      {
            (yyval.node) = create_tree_node("arg_list", st_args, 0);
        }
#line 1884 "java.tab.c"
    break;

  case 24: /* arg: TYPES ID  */
#line 213 "java.y"
                       { 
                check_and_set_dType((yyvsp[0].symEntry),(yyvsp[-1].node)->dataType);
                struct TreeNode *n2=copy_entry_to_node((yyvsp[0].symEntry));
                (yyval.node) = create_tree_node("arg", st_args,2, (yyvsp[-1].node), n2);
                setDimension((yyval.node), (yyvsp[-1].node)->dimen);            
                setDataType((yyval.node), (yyvsp[-1].node)->dataType);
            }
#line 1896 "java.tab.c"
    break;

  case 25: /* arg: TYPES  */
#line 220 "java.y"
                    {
                (yyval.node) = (yyvsp[0].node);
            }
#line 1904 "java.tab.c"
    break;

  case 26: /* access_modfr: PUBLIC  */
#line 225 "java.y"
                     {  (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1910 "java.tab.c"
    break;

  case 27: /* access_modfr: PRIVATE  */
#line 225 "java.y"
                                                               {  (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1916 "java.tab.c"
    break;

  case 28: /* access_modfr: PROTECTED  */
#line 226 "java.y"
                        {  (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1922 "java.tab.c"
    break;

  case 29: /* TYPES: TYPE empty_brackets  */
#line 227 "java.y"
                                  {  
                (yyval.node) = create_tree_node("TYPE", st_types, 0);
                setDataType((yyval.node), (yyvsp[-1].node)->dataType);
                setDimension((yyval.node), (yyvsp[0].node)->dimen);
            }
#line 1932 "java.tab.c"
    break;

  case 30: /* empty_brackets: %empty  */
#line 232 "java.y"
                 { (yyval.node) = create_tree_node("dimension",st_dimension,0); }
#line 1938 "java.tab.c"
    break;

  case 31: /* empty_brackets: empty_brackets LBRACKET RBRACKET  */
#line 233 "java.y"
                                               { 
                //if(!$1)
                (yyval.node) = (yyvsp[-2].node);
                setDimension((yyval.node), (yyvsp[-2].node)->dimen + 1);  // Increase dimen by 1
                // printf("dimen: %d\n", $1->dimen);
            }
#line 1949 "java.tab.c"
    break;

  case 32: /* empty_brackets: error SEMICOLON  */
#line 239 "java.y"
                              { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 1955 "java.tab.c"
    break;

  case 33: /* TYPE: INT  */
#line 242 "java.y"
                  { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1961 "java.tab.c"
    break;

  case 34: /* TYPE: DOUBLE  */
#line 242 "java.y"
                                                         { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1967 "java.tab.c"
    break;

  case 35: /* TYPE: BOOLEAN  */
#line 243 "java.y"
                      { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1973 "java.tab.c"
    break;

  case 36: /* TYPE: CHAR  */
#line 243 "java.y"
                                                           { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1979 "java.tab.c"
    break;

  case 37: /* TYPE: FLOAT  */
#line 244 "java.y"
                    { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry));  }
#line 1985 "java.tab.c"
    break;

  case 38: /* TYPE: VOID  */
#line 244 "java.y"
                                                           { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 1991 "java.tab.c"
    break;

  case 39: /* TYPE: STRING  */
#line 245 "java.y"
                     {(yyval.node)=copy_entry_to_node((yyvsp[0].symEntry));}
#line 1997 "java.tab.c"
    break;

  case 40: /* stmt_list: %empty  */
#line 247 "java.y"
                        {
            (yyval.node) = create_tree_node("stmt_list", st_stmt_list, 0); // If the statement list is empty, set the result to NULL
        }
#line 2005 "java.tab.c"
    break;

  case 41: /* stmt_list: stmt_list M stmt  */
#line 250 "java.y"
                           {
            add_children((yyvsp[-2].node), 1, (yyvsp[-1].node));
            (yyval.node) = (yyvsp[-2].node); // Set the result to the updated stmt_list node
            backpatch((yyvsp[-2].node)->nextList,(yyvsp[-1].node)->nextList->current);
            (yyval.node)->nextList=(yyvsp[0].node)->nextList;

        }
#line 2017 "java.tab.c"
    break;

  case 42: /* stmt_list: error SEMICOLON  */
#line 257 "java.y"
                          { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 2023 "java.tab.c"
    break;

  case 43: /* stmt: LBRACE stmt_list RBRACE  */
#line 260 "java.y"
                               {  (yyval.node) = create_tree_node("stmt",st_stmt_list, 1, (yyvsp[-1].node)); (yyval.node)->nextList=(yyvsp[-1].node)->nextList;}
#line 2029 "java.tab.c"
    break;

  case 44: /* stmt: expr SEMICOLON  */
#line 261 "java.y"
                         { (yyval.node)=(yyvsp[-1].node);}
#line 2035 "java.tab.c"
    break;

  case 45: /* stmt: if_stmt  */
#line 261 "java.y"
                                            {  (yyval.node) = (yyvsp[0].node); }
#line 2041 "java.tab.c"
    break;

  case 46: /* stmt: while_stmt  */
#line 261 "java.y"
                                                                      {  (yyval.node) = (yyvsp[0].node); }
#line 2047 "java.tab.c"
    break;

  case 47: /* stmt: for_stmt  */
#line 262 "java.y"
                   {  (yyval.node) = (yyvsp[0].node); }
#line 2053 "java.tab.c"
    break;

  case 48: /* stmt: return_stmt  */
#line 262 "java.y"
                                              {  (yyval.node) = (yyvsp[0].node); }
#line 2059 "java.tab.c"
    break;

  case 49: /* stmt: decl_stmt  */
#line 262 "java.y"
                                                                       {  (yyval.node) = (yyvsp[0].node); }
#line 2065 "java.tab.c"
    break;

  case 50: /* if_stmt: IF LPAREN log_expr RPAREN M stmt  */
#line 265 "java.y"
                                           {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-5].symEntry));
            (yyval.node) = create_tree_node("if_stmt", st_if, 3, n1, (yyvsp[-3].node), (yyvsp[0].node));
            backpatch((yyvsp[-3].node)->trueList,(yyvsp[-1].node)->nextList->current);
            (yyval.node)->nextList=mergeLists((yyvsp[-3].node)->falseList,(yyvsp[0].node)->nextList);
        }
#line 2076 "java.tab.c"
    break;

  case 51: /* if_stmt: IF LPAREN log_expr RPAREN M stmt N ELSE M stmt  */
#line 270 "java.y"
                                                          {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-9].symEntry));
            (yyval.node) = create_tree_node("if_stmt", st_if, 4, n1, (yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[0].node));
            printf("else is there\n ");
            backpatch((yyvsp[-7].node)->trueList,(yyvsp[-5].node)->nextList->current);
            backpatch((yyvsp[-7].node)->falseList,(yyvsp[-1].node)->nextList->current);
            (yyval.node)->nextList=mergeLists(mergeLists((yyvsp[-4].node)->nextList,(yyvsp[-3].node)->nextList),(yyvsp[0].node)->nextList);
        }
#line 2089 "java.tab.c"
    break;

  case 52: /* N: %empty  */
#line 279 "java.y"
             { (yyval.node)=create_tree_node("N",st_if,0); (yyval.node)->nextList=newList(indx); codeGen("goto", "", "", "");}
#line 2095 "java.tab.c"
    break;

  case 53: /* M: %empty  */
#line 280 "java.y"
             { (yyval.node)=create_tree_node("M",st_if,0); (yyval.node)->nextList=newList(indx); }
#line 2101 "java.tab.c"
    break;

  case 54: /* while_stmt: WHILE M LPAREN log_expr RPAREN M stmt  */
#line 281 "java.y"
                                                   {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-6].symEntry));
            (yyval.node) = create_tree_node("while_stmt", st_while, 3, n1, (yyvsp[-3].node), (yyvsp[0].node));
            backpatch((yyvsp[0].node)->nextList,(yyvsp[-5].node)->nextList->current);
            backpatch((yyvsp[-3].node)->trueList,(yyvsp[-1].node)->nextList->current);
            (yyval.node)->nextList=(yyvsp[-3].node)->falseList;
            char *x=malloc(10);
            sprintf(x,"L%d",(yyvsp[-5].node)->nextList->current);
            codeGen("goto", "", "", x);
        }
#line 2116 "java.tab.c"
    break;

  case 55: /* for_stmt: FOR LPAREN expr SEMICOLON log_expr SEMICOLON M expr RPAREN stmt  */
#line 293 "java.y"
                                                                           {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-9].symEntry));
            (yyval.node) = create_tree_node("for_stmt", st_for, 5, n1, (yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));

            // backpatch($8->nextList,$2->nextList->current);
            // backpatch($5->trueList,$9->nextList->current);
            // backpatch($5->falseList,$10->nextList->current);
            // $$->nextList=$5->falseList;
            // char *x=malloc(10);
            // sprintf(x,"L%d",$2->nextList->current);
            // codeGen("goto", "", "", x);

        }
#line 2134 "java.tab.c"
    break;

  case 56: /* return_stmt: RETURN expr SEMICOLON  */
#line 307 "java.y"
                                    {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-2].symEntry));
            (yyval.node) = create_tree_node("return_stmt", st_return, 2, n1, (yyvsp[-1].node));
            codeGen("return","", "", (yyvsp[-1].node)->name);
        }
#line 2144 "java.tab.c"
    break;

  case 57: /* return_stmt: RETURN SEMICOLON  */
#line 312 "java.y"
                           {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-1].symEntry));
            (yyval.node) = create_tree_node("return_stmt", st_return, 1, (yyvsp[-1].symEntry));
            codeGen("return","", "", "");
        }
#line 2154 "java.tab.c"
    break;

  case 58: /* decl_stmt: TYPES decl_ids SEMICOLON  */
#line 319 "java.y"
                                     {  (yyval.node) = create_tree_node("decl_stmt",st_stmt, 2, (yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2160 "java.tab.c"
    break;

  case 59: /* decl_stmt: error SEMICOLON  */
#line 320 "java.y"
                          { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 2166 "java.tab.c"
    break;

  case 60: /* decl_ids: decl_id  */
#line 322 "java.y"
                   {
            (yyval.node) = create_tree_node("decl_ids", st_decl_ids, 1, (yyvsp[0].node));
        }
#line 2174 "java.tab.c"
    break;

  case 61: /* decl_ids: decl_ids COMMA decl_id  */
#line 325 "java.y"
                                 {
            add_children((yyvsp[-2].node), 1, (yyvsp[0].node));
            (yyval.node) = (yyvsp[-2].node); // Set the result to the updated decl_ids node
        }
#line 2183 "java.tab.c"
    break;

  case 62: /* decl_ids: error SEMICOLON  */
#line 329 "java.y"
                          { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 2189 "java.tab.c"
    break;

  case 63: /* decl_id: ID  */
#line 332 "java.y"
             {
            check_and_set_dType((yyvsp[0].symEntry),(yyvsp[-1].node)->dataType);
            set_dimension((yyvsp[0].symEntry),(yyvsp[-1].node)->dimen);
            (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry));
        }
#line 2199 "java.tab.c"
    break;

  case 64: /* $@4: %empty  */
#line 336 "java.y"
              {
            check_and_set_dType((yyvsp[0].symEntry),(yyvsp[-1].node)->dataType);
            set_dimension((yyvsp[0].symEntry),(yyvsp[-1].node)->dimen);
            //printf("----------------------------->dimension :%d\n",$1->dimen);
        }
#line 2209 "java.tab.c"
    break;

  case 65: /* decl_id: ID $@4 ASSIGN expr  */
#line 340 "java.y"
                      {
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-3].symEntry));
            struct TreeNode *n3= copy_entry_to_node((yyvsp[-1].symEntry));
            codeGen("=", (yyvsp[-3].symEntry)->lexeme, (yyvsp[0].node)->name, "");
            (yyval.node) = create_tree_node("assign_expr",st_expr, 3, n3, n1, (yyvsp[0].node));
        }
#line 2220 "java.tab.c"
    break;

  case 66: /* decl_id: error COMMA  */
#line 346 "java.y"
                      { yyerror("Syntax error"); (yyval.node) = NULL; }
#line 2226 "java.tab.c"
    break;

  case 67: /* expr: asg_expr  */
#line 348 "java.y"
                   { (yyval.node)=(yyvsp[0].node); }
#line 2232 "java.tab.c"
    break;

  case 68: /* expr: arm_expr  */
#line 348 "java.y"
                                         { (yyval.node)=(yyvsp[0].node); }
#line 2238 "java.tab.c"
    break;

  case 69: /* expr: log_expr  */
#line 349 "java.y"
                   { (yyval.node)=(yyvsp[0].node); }
#line 2244 "java.tab.c"
    break;

  case 70: /* expr: LPAREN expr RPAREN  */
#line 349 "java.y"
                                                   { (yyval.node)=(yyvsp[-1].node); }
#line 2250 "java.tab.c"
    break;

  case 71: /* expr: diff_ids  */
#line 350 "java.y"
                   { (yyval.node)=(yyvsp[0].node); }
#line 2256 "java.tab.c"
    break;

  case 72: /* asg_expr: ID asg_op expr  */
#line 352 "java.y"
                          {
            is_defined((yyvsp[-2].symEntry));
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-2].symEntry));
            checkType(n1,(yyvsp[0].node),yylineno);
            (yyval.node) = create_tree_node((yyvsp[-2].symEntry)->lexeme,st_expr, 3, (yyvsp[-1].node), n1, (yyvsp[0].node));
            codeGen((yyvsp[-1].node)->name, (yyvsp[0].node)->name,"", (yyval.node)->name);
        }
#line 2268 "java.tab.c"
    break;

  case 73: /* asg_expr: ID INC  */
#line 359 "java.y"
                 {
            is_defined((yyvsp[-1].symEntry));
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-1].symEntry));
            checkdType(n1,dt_integer,0,yylineno);
            struct TreeNode *n2=copy_entry_to_node((yyvsp[0].symEntry));
            codeGen("+", (yyvsp[-1].symEntry)->lexeme,  "1", (yyvsp[-1].symEntry)->lexeme);
            (yyval.node) = create_tree_node(new_temp(),st_expr, 2, n2, n1);

        }
#line 2282 "java.tab.c"
    break;

  case 74: /* asg_expr: ID DEC  */
#line 368 "java.y"
                 {
            is_defined((yyvsp[-1].symEntry));
            struct TreeNode *n1=copy_entry_to_node((yyvsp[-1].symEntry));
            checkdType(n1,dt_integer,0,yylineno);
            struct TreeNode *n2=copy_entry_to_node((yyvsp[0].symEntry));
            codeGen("-", (yyvsp[-1].symEntry)->lexeme, "1", (yyvsp[-1].symEntry)->lexeme);
            (yyval.node) = create_tree_node(new_temp(),st_expr, 2, (yyvsp[0].symEntry), n1);
        }
#line 2295 "java.tab.c"
    break;

  case 75: /* asg_op: PLUSASG  */
#line 377 "java.y"
                      { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2301 "java.tab.c"
    break;

  case 76: /* asg_op: MINUSASG  */
#line 377 "java.y"
                                                               { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2307 "java.tab.c"
    break;

  case 77: /* asg_op: TIMESASG  */
#line 378 "java.y"
                       { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2313 "java.tab.c"
    break;

  case 78: /* asg_op: DIVIDEASG  */
#line 378 "java.y"
                                                                  { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2319 "java.tab.c"
    break;

  case 79: /* asg_op: ASSIGN  */
#line 379 "java.y"
                     { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2325 "java.tab.c"
    break;

  case 80: /* arm_expr: expr armop expr  */
#line 381 "java.y"
                              {
                checkType((yyvsp[-2].node),(yyvsp[0].node),yylineno);
                (yyval.node) = create_tree_node(new_temp(),st_expr, 3, (yyvsp[-1].node), (yyvsp[-2].node), (yyvsp[0].node));
                setDataType((yyval.node), (yyvsp[-2].node)->dataType);
                codeGen((yyvsp[-1].node)->name, (yyvsp[-2].node)->name, (yyvsp[0].node)->name, (yyval.node)->name);
            }
#line 2336 "java.tab.c"
    break;

  case 81: /* arm_expr: literal  */
#line 386 "java.y"
                       { (yyval.node)=(yyvsp[0].node); }
#line 2342 "java.tab.c"
    break;

  case 82: /* log_expr: log_expr AND M log_expr  */
#line 388 "java.y"
                                      {
                checkType((yyvsp[-3].node),(yyvsp[0].node),yylineno);
                struct TreeNode *n2=copy_entry_to_node((yyvsp[-2].symEntry));
                (yyval.node) = create_tree_node(new_temp(),st_log_expr, 3, n2, (yyvsp[-3].node), (yyvsp[0].node));
                setDataType((yyval.node), (yyvsp[-3].node)->dataType);
                backpatch((yyvsp[-3].node)->trueList,(yyvsp[-1].node)->nextList->current);
                (yyval.node)->trueList=(yyvsp[0].node)->trueList;
                (yyval.node)->falseList=mergeLists((yyvsp[-3].node)->falseList,(yyvsp[0].node)->falseList);
            }
#line 2356 "java.tab.c"
    break;

  case 83: /* log_expr: log_expr OR M log_expr  */
#line 397 "java.y"
                                     {
                checkType((yyvsp[-3].node),(yyvsp[0].node),yylineno);
                struct TreeNode *n2=copy_entry_to_node((yyvsp[-2].symEntry));
                (yyval.node) = create_tree_node(new_temp(),st_log_expr, 3, n2, (yyvsp[-3].node), (yyvsp[0].node));
                setDataType((yyval.node), (yyvsp[-3].node)->dataType);
                backpatch((yyvsp[-3].node)->falseList,(yyvsp[-1].node)->nextList->current);
                (yyval.node)->trueList=mergeLists((yyvsp[-3].node)->trueList,(yyvsp[0].node)->trueList);
                (yyval.node)->falseList=(yyvsp[0].node)->falseList;
            }
#line 2370 "java.tab.c"
    break;

  case 84: /* log_expr: NOT log_expr  */
#line 406 "java.y"
                           {
                checkdType((yyvsp[0].node),dt_boolean,0,yylineno);
                struct TreeNode *n1=copy_entry_to_node((yyvsp[-1].symEntry));
                (yyval.node) = create_tree_node(new_temp(),st_log_expr, 2, n1, (yyvsp[0].node));
                setDataType((yyval.node), (yyvsp[0].node)->dataType);
                (yyval.node)->trueList=(yyvsp[0].node)->falseList;
                (yyval.node)->falseList=(yyvsp[0].node)->trueList;
            }
#line 2383 "java.tab.c"
    break;

  case 85: /* log_expr: expr relop expr  */
#line 414 "java.y"
                              {  
                checkType((yyvsp[-2].node),(yyvsp[0].node),yylineno);         
                (yyval.node) = create_tree_node(new_temp(),st_log_expr, 3, (yyvsp[-1].node), (yyvsp[-2].node), (yyvsp[0].node));
                setDataType((yyval.node), dt_boolean);
                (yyval.node)->trueList=newList(indx);
                (yyval.node)->falseList=newList(indx+1);
                char *x=malloc(strlen((yyvsp[-1].node)->name)+strlen((yyvsp[-2].node)->name)+strlen((yyvsp[0].node)->name)+1);
                int k=0;
                for(int i=0;i<strlen((yyvsp[-2].node)->name);i++){
                    x[k++]=((yyvsp[-2].node)->name)[i];
                }
                for(int i=0;i<strlen((yyvsp[-1].node)->name);i++){
                    x[k++]=((yyvsp[-1].node)->name)[i];
                }
                for(int i=0;i<strlen((yyvsp[0].node)->name);i++){
                    x[k++]=((yyvsp[0].node)->name)[i];
                }
                codeGen("if", x,"goto", "");
                codeGen("goto", "", "", "");
            }
#line 2408 "java.tab.c"
    break;

  case 86: /* log_expr: LPAREN log_expr RPAREN  */
#line 434 "java.y"
                                     {
                checkdType((yyvsp[-1].node),dt_boolean,0,yylineno);
                (yyval.node) = (yyvsp[-1].node);
            }
#line 2417 "java.tab.c"
    break;

  case 87: /* log_expr: TRUE  */
#line 437 "java.y"
                    { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); (yyval.node)->trueList=newList(indx); codeGen("goto", "", "", ""); }
#line 2423 "java.tab.c"
    break;

  case 88: /* log_expr: FALSE  */
#line 438 "java.y"
                    { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); (yyval.node)->trueList=newList(indx); codeGen("goto", "", "", ""); }
#line 2429 "java.tab.c"
    break;

  case 89: /* relop: EQ  */
#line 441 "java.y"
                 { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2435 "java.tab.c"
    break;

  case 90: /* relop: NE  */
#line 441 "java.y"
                                                   { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2441 "java.tab.c"
    break;

  case 91: /* relop: LT  */
#line 441 "java.y"
                                                                                     { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2447 "java.tab.c"
    break;

  case 92: /* relop: GT  */
#line 442 "java.y"
                { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2453 "java.tab.c"
    break;

  case 93: /* relop: LE  */
#line 442 "java.y"
                                                  { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2459 "java.tab.c"
    break;

  case 94: /* relop: GE  */
#line 442 "java.y"
                                                                                     { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2465 "java.tab.c"
    break;

  case 95: /* armop: TIMES  */
#line 443 "java.y"
                    { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2471 "java.tab.c"
    break;

  case 96: /* armop: DIVIDE  */
#line 444 "java.y"
                    { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2477 "java.tab.c"
    break;

  case 97: /* armop: MOD  */
#line 444 "java.y"
                                                       { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2483 "java.tab.c"
    break;

  case 98: /* armop: PLUS  */
#line 445 "java.y"
                  { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2489 "java.tab.c"
    break;

  case 99: /* armop: MINUS  */
#line 445 "java.y"
                                                       { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2495 "java.tab.c"
    break;

  case 100: /* literal: NUMBER  */
#line 446 "java.y"
                     { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2501 "java.tab.c"
    break;

  case 101: /* literal: STRING  */
#line 446 "java.y"
                                                           { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2507 "java.tab.c"
    break;

  case 102: /* literal: CHARACTER  */
#line 446 "java.y"
                                                                                                     { (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2513 "java.tab.c"
    break;

  case 103: /* diff_ids: mem_access  */
#line 447 "java.y"
                          { (yyval.node)=(yyvsp[0].node); }
#line 2519 "java.tab.c"
    break;

  case 104: /* diff_ids: array_acess  */
#line 447 "java.y"
                                                   { (yyval.node) = (yyvsp[0].node); }
#line 2525 "java.tab.c"
    break;

  case 105: /* diff_ids: method_call  */
#line 447 "java.y"
                                                                              { (yyval.node) = (yyvsp[0].node); }
#line 2531 "java.tab.c"
    break;

  case 106: /* mem_access: mem_access DOT mem_access  */
#line 449 "java.y"
                                        { (yyval.node) = create_tree_node("mem_access",st_mem_access, 3, (yyvsp[-1].symEntry), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2537 "java.tab.c"
    break;

  case 107: /* mem_access: ID  */
#line 450 "java.y"
                 { is_defined((yyvsp[0].symEntry)); (yyval.node)=copy_entry_to_node((yyvsp[0].symEntry)); }
#line 2543 "java.tab.c"
    break;

  case 108: /* mem_access: method_call  */
#line 451 "java.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2549 "java.tab.c"
    break;

  case 109: /* array_acess: ID brackets  */
#line 453 "java.y"
                          { 
                is_defined((yyvsp[-1].symEntry));
                check_array_access((yyvsp[-1].symEntry),(yyvsp[0].node)->dimen,yylineno);
                struct TreeNode *n1=copy_entry_to_node((yyvsp[-1].symEntry));
                (yyval.node) = create_tree_node(new_temp(),st_array_access, 2, n1, (yyvsp[0].node)); 
                setDataType((yyval.node), (yyvsp[-1].symEntry)->dataType);
                setDimension((yyval.node), (yyvsp[-1].symEntry)->dimen-(yyvsp[0].node)->dimen);
                char*t=new_temp(); 
                codeGen("*", (yyvsp[0].node)->children[0]->name, "4", t);
                char *x=malloc(strlen((yyvsp[-1].symEntry)->lexeme)+2+1);
                sprintf(x,"(%s)", (yyvsp[-1].symEntry)->lexeme);
                codeGen("+", t, x, (yyval.node)->name);
                // Set dimension to the difference of the two dimensions

            }
#line 2569 "java.tab.c"
    break;

  case 110: /* method_call: ID LPAREN pass_args RPAREN  */
#line 468 "java.y"
                                         { 
                is_defined((yyvsp[-3].symEntry));
                is_method((yyvsp[-3].symEntry));
                check_method_args((yyvsp[-3].symEntry),(yyvsp[-1].node),yylineno);
                struct TreeNode *n1=copy_entry_to_node((yyvsp[-3].symEntry)); 
                (yyval.node) = create_tree_node("method_call",st_method_call, 2, n1, (yyvsp[-1].node));
                setDataType((yyval.node), (yyvsp[-3].symEntry)->dataType);
                setDimension((yyval.node), 0);
                for(int i=0;i<(yyvsp[-1].node)->num_children;i++){
                    codeGen("param", (yyvsp[-1].node)->children[i]->name, "", "");
                } 
                codeGen("call", (yyvsp[-3].symEntry)->lexeme, "", "");

                 }
#line 2588 "java.tab.c"
    break;

  case 111: /* method_call: ID LPAREN RPAREN  */
#line 482 "java.y"
                               { 
                is_defined((yyvsp[-2].symEntry));
                is_method((yyvsp[-2].symEntry));
                check_method_args((yyvsp[-2].symEntry),NULL,yylineno);
                struct TreeNode *n1=copy_entry_to_node((yyvsp[-2].symEntry));
                (yyval.node) = create_tree_node("method_call", st_method_call,1,n1); 
            }
#line 2600 "java.tab.c"
    break;

  case 112: /* pass_args: pass_args COMMA expr  */
#line 490 "java.y"
                                   { 
                (yyval.node) = (yyvsp[-2].node);
                add_children((yyval.node), 1, (yyvsp[0].node));
            }
#line 2609 "java.tab.c"
    break;

  case 113: /* pass_args: expr  */
#line 494 "java.y"
                   { (yyval.node) = create_tree_node("pass_args",st_pass_args, 1, (yyvsp[0].node)); }
#line 2615 "java.tab.c"
    break;

  case 114: /* pass_args: %empty  */
#line 495 "java.y"
              { (yyval.node) = NULL; }
#line 2621 "java.tab.c"
    break;

  case 115: /* brackets: brackets LBRACKET expr RBRACKET  */
#line 497 "java.y"
                                             {
                (yyval.node) = (yyvsp[-3].node);
                checkdType((yyvsp[-3].node),dt_integer,0,yylineno);
                add_children((yyval.node), 1, (yyvsp[-1].node));
                setDimension((yyval.node),(yyval.node)->dimen + 1); // Increment dimension by 1
            }
#line 2632 "java.tab.c"
    break;

  case 116: /* brackets: LBRACKET expr RBRACKET  */
#line 503 "java.y"
                                     {
                checkdType((yyvsp[-1].node),dt_integer,0,yylineno);
                (yyval.node) = create_tree_node("brackets", st_expr, 1, (yyvsp[-1].node));
                setDimension((yyval.node), 1); // Set dimension to 1 for single brackets
            }
#line 2642 "java.tab.c"
    break;


#line 2646 "java.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 509 "java.y"


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
    print_icg();
    // 
    // print_parse_table();
    // show_tree_view(root);
    // free_tree(root);
    fclose(input_file);
    
    return 0;
}

