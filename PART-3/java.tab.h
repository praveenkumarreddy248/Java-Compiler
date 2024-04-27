
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 101 "java.y"

        struct SymbolTableEntry *symEntry;
        struct TreeNode* node;
    


/* Line 1676 of yacc.c  */
#line 117 "java.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


