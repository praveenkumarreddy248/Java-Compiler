%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"
#include "java.tab.h"
struct SymbolTableEntry;
extern union YYSTYPE yylval;
extern int yylineno;
extern struct SymbolTableEntry* check_and_add(struct SymbolTable *table, char *lexeme, int lineNo, SymbolType symbolType, DataType dataType, Value value);
extern struct SymbolTableEntry* store_literals(struct SymbolTable *table, char *lexeme, int lineNo, DataType dataType, Value value) ;
extern struct SymbolTable *new_table(struct SymbolTable *parent);
extern struct ScopeStack* scopeStack;
extern struct SymbolTable *constants;
extern struct SymbolTableEntry* reservedKeywords[100];
extern void push_scope(struct ScopeStack *stack, struct SymbolTable *table);
extern struct SymbolTable* pop_scope(struct ScopeStack *stack);
extern struct SymbolTable* peek_scope(struct ScopeStack *stack);
extern void print_table(struct SymbolTable *table);

%}
%option yylineno
%%

\/\/.*$     {/* Ignore single-line comments */}
\/\*(.|\n)*?\*\/ {/* Ignore multi-line comments */}

    "public"    { yylval.symEntry = reservedKeywords[tok_public]; return PUBLIC; }
    "private"   { yylval.symEntry = reservedKeywords[tok_private]; return PRIVATE; }
    "protected" { yylval.symEntry = reservedKeywords[tok_protected]; return PROTECTED; }
    "class"     { yylval.symEntry = reservedKeywords[tok_class]; return CLASS; }
    "void"      { yylval.symEntry = reservedKeywords[tok_void]; return VOID; }
    "static"    { yylval.symEntry = reservedKeywords[tok_static]; return STATIC; }
    "main"      { yylval.symEntry = reservedKeywords[tok_main]; return MAIN; }
    "if"        { yylval.symEntry = reservedKeywords[tok_if]; return IF; }     
    "else"      { yylval.symEntry = reservedKeywords[tok_else]; return ELSE; }   
    "while"     { yylval.symEntry = reservedKeywords[tok_while]; return WHILE; }  
    "for"       { yylval.symEntry = reservedKeywords[tok_for]; return FOR; }    
    "return"    { yylval.symEntry = reservedKeywords[tok_return]; return RETURN; } 
    "int"       { yylval.symEntry = reservedKeywords[tok_int]; return INT; }
    "float"     { yylval.symEntry = reservedKeywords[tok_float]; return FLOAT; }
    "double"    { yylval.symEntry = reservedKeywords[tok_double]; return DOUBLE; }
    "boolean"   { yylval.symEntry = reservedKeywords[tok_boolean]; return BOOLEAN; }
    "char"      { yylval.symEntry = reservedKeywords[tok_char]; return CHAR; }
    "String"    { yylval.symEntry = reservedKeywords[tok_string]; return STRING; }
    "true"      { yylval.symEntry = reservedKeywords[tok_true]; return TRUE; }
    "false"     { yylval.symEntry = reservedKeywords[tok_false]; return FALSE; }


    "++"        { yylval.symEntry = reservedKeywords[tok_inc]; return INC; }
    "--"        { yylval.symEntry = reservedKeywords[tok_dec]; return DEC; }
    "=="        { yylval.symEntry = reservedKeywords[tok_eq]; return EQ; }
    "!="        { yylval.symEntry = reservedKeywords[tok_ne]; return NE; }
    "<="        { yylval.symEntry = reservedKeywords[tok_le]; return LE; }
    ">="        { yylval.symEntry = reservedKeywords[tok_ge]; return GE; }
    "&&"        { yylval.symEntry = reservedKeywords[tok_and]; return AND; }
    "||"        { yylval.symEntry = reservedKeywords[tok_or]; return OR; }
    "!"         { yylval.symEntry = reservedKeywords[tok_not]; return NOT; }
    "."         { yylval.symEntry = reservedKeywords[tok_dot]; return DOT; }
    "+"         { yylval.symEntry = reservedKeywords[tok_plus]; return PLUS; }
    "-"         { yylval.symEntry = reservedKeywords[tok_minus]; return MINUS; }
    "*"         { yylval.symEntry = reservedKeywords[tok_times]; return TIMES; }
    "/"         { yylval.symEntry = reservedKeywords[tok_divide]; return DIVIDE; }
    "%"         { yylval.symEntry = reservedKeywords[tok_mod]; return MOD; }
    "+="        { yylval.symEntry = reservedKeywords[tok_plusasg]; return PLUSASG; }
    "-="        { yylval.symEntry = reservedKeywords[tok_minusasg]; return MINUSASG; }
    "*="        { yylval.symEntry = reservedKeywords[tok_timesasg]; return TIMESASG; }
    "/="        { yylval.symEntry = reservedKeywords[tok_divideasg]; return DIVIDEASG; }
    "="         { yylval.symEntry = reservedKeywords[tok_assign]; return ASSIGN; }
    "<"         { yylval.symEntry = reservedKeywords[tok_lt]; return LT; }
    ">"         { yylval.symEntry = reservedKeywords[tok_gt]; return GT; }
    "("         { yylval.symEntry = reservedKeywords[tok_lparen]; return LPAREN; }
    ")"         { yylval.symEntry = reservedKeywords[tok_rparen]; return RPAREN; }
    "["         { yylval.symEntry = reservedKeywords[tok_lbracket]; return LBRACKET; }
    "]"         { yylval.symEntry = reservedKeywords[tok_rbracket]; return RBRACKET; }
    ";"         { /*yylval.symEntry = reservedKeywords[tok_semicolon];*/ return SEMICOLON; }
    ","         { yylval.symEntry = reservedKeywords[tok_comma]; return COMMA; }
    "{"         { yylval.symEntry = reservedKeywords[tok_lbrace];
                    struct SymbolTable *table =new_table(scopeStack->top);
                    push_scope(scopeStack,table); return LBRACE; }
    "}"         { yylval.symEntry = reservedKeywords[tok_rbrace]; 
                    /*print_table(pop_scope(scopeStack)); */return RBRACE; }

'[^'\\]'    { yylval.symEntry=store_literals(constants,yytext,yylineno,dt_character,(Value)strdup(yytext));return CHARACTER; }
\"([^"\\]|\\.)*\" { yylval.symEntry=store_literals(constants,yytext,yylineno,dt_string,(Value)strdup(yytext)); return STRING; }
[0-9]+      {  yylval.symEntry=store_literals(constants,yytext,yylineno,dt_integer,(Value){ .val_int = atoi(yytext) }); return NUMBER; } // Integer literals
[0-9]+"."[0-9]+([eE][-+]?[0-9]+)? { yylval.symEntry=store_literals(constants,yytext,yylineno,dt_real,(Value){ .val_float = atof(yytext) }); return NUMBER; } // Floating-point literals
[a-zA-Z_][a-zA-Z0-9_]*  {yylval.symEntry=check_and_add(scopeStack->top,yytext,yylineno,identifier,dt_unknown,(Value)0);  return ID; }
[ \t]       { /* Ignore whitespace */ } 
[\n]        {}
.           { printf("error-%s\n",yytext); };

%%