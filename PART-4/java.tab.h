/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_JAVA_TAB_H_INCLUDED
# define YY_YY_JAVA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    DOUBLE = 259,                  /* DOUBLE  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    CHAR = 261,                    /* CHAR  */
    ID = 262,                      /* ID  */
    FLOAT = 263,                   /* FLOAT  */
    VOID = 264,                    /* VOID  */
    STRING = 265,                  /* STRING  */
    PUBLIC = 266,                  /* PUBLIC  */
    PRIVATE = 267,                 /* PRIVATE  */
    PROTECTED = 268,               /* PROTECTED  */
    CLASS = 269,                   /* CLASS  */
    STATIC = 270,                  /* STATIC  */
    FINAL = 271,                   /* FINAL  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    WHILE = 274,                   /* WHILE  */
    FOR = 275,                     /* FOR  */
    RETURN = 276,                  /* RETURN  */
    MAIN = 277,                    /* MAIN  */
    ARGS = 278,                    /* ARGS  */
    CHARACTER = 279,               /* CHARACTER  */
    NUMBER = 280,                  /* NUMBER  */
    ERROR = 281,                   /* ERROR  */
    INC = 282,                     /* INC  */
    DEC = 283,                     /* DEC  */
    SEMICOLON = 284,               /* SEMICOLON  */
    COMMA = 285,                   /* COMMA  */
    LPAREN = 286,                  /* LPAREN  */
    RPAREN = 287,                  /* RPAREN  */
    LBRACE = 288,                  /* LBRACE  */
    RBRACE = 289,                  /* RBRACE  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    NOT = 292,                     /* NOT  */
    DOT = 293,                     /* DOT  */
    LBRACKET = 294,                /* LBRACKET  */
    RBRACKET = 295,                /* RBRACKET  */
    EQ = 296,                      /* EQ  */
    NE = 297,                      /* NE  */
    LT = 298,                      /* LT  */
    GT = 299,                      /* GT  */
    LE = 300,                      /* LE  */
    GE = 301,                      /* GE  */
    TRUE = 302,                    /* TRUE  */
    FALSE = 303,                   /* FALSE  */
    TIMES = 304,                   /* TIMES  */
    PLUS = 305,                    /* PLUS  */
    MINUS = 306,                   /* MINUS  */
    DIVIDE = 307,                  /* DIVIDE  */
    MOD = 308,                     /* MOD  */
    PLUSASG = 309,                 /* PLUSASG  */
    MINUSASG = 310,                /* MINUSASG  */
    TIMESASG = 311,                /* TIMESASG  */
    DIVIDEASG = 312,               /* DIVIDEASG  */
    ASSIGN = 313                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 122 "java.y"

        struct SymbolTableEntry *symEntry;
        struct TreeNode* node;
    

#line 128 "java.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_JAVA_TAB_H_INCLUDED  */
