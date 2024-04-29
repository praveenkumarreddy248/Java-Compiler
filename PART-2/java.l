%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"
#include "TreeNode.h"
#include "java.tab.h" 
struct TreeNode; 
struct SymbolTableEntry;
extern union YYSTYPE yylval;
extern struct TreeNode *create_node(struct SymbolTableEntry **head, char *name, enum entry_type type, enum datatype dtype,int lineno );
extern struct SymbolTableEntry* symbolTable;
extern int yylineno;
%}
%option yylineno
%%
\/\/.*$     {printf("comment");}
\/\*(?:.|\n)*?\*\/ {printf("comment");}
"public"    { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return PUBLIC; }
"private"   { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return PRIVATE; }
"protected" { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return PROTECTED; }
"class"     { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return CLASS; }
"void"      { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return VOID; }
"static"    { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return STATIC; }
"main"      { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return MAIN; }
"if"        { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return IF; }     
"else"      { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return ELSE; }   
"while"     { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return WHILE; }  
"for"       { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return FOR; }    
"return"    { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return RETURN; } 
"true"      { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return TRUE; }
"false"     { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return FALSE; }
"{"         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return LBRACE; }
"}"         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return RBRACE; }
"("         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return LPAREN; }
")"         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return RPAREN; }
"["         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return LBRACKET; }
"]"         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return RBRACKET; }
";"         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return SEMICOLON; }
"+="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return PLUSASG; }
"-="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return MINUSASG; }
"*="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return TIMESASG; }
"/="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return DIVIDEASG; }
"++"        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return INC; }
"--"        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return DEC; }
"+"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return PLUS; }
"-"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return MINUS; }
"*"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return TIMES; }
"/"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return DIVIDE; }
"%"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return MOD; }
"&&"        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return AND; }
"||"        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return OR; }
"!"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return NOT; }
"="         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return ASSIGN; }
"."         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return DOT; }
"=="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return EQ; }
"!="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return NE; }
"<"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return LT; }
">"         { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return GT; }
"<="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return LE; }
">="        { yylval.node=create_node(&symbolTable,yytext,Operator,unknown,yylineno); return GE; }
","         { yylval.node=create_node(&symbolTable,yytext,keyword,unknown,yylineno); return COMMA; }
'[^'\\]'    { yylval.node=create_node(&symbolTable,yytext,character,literal,yylineno); return CHARACTER; }
\"([^"\\]|\\.)*\" { yylval.node=create_node(&symbolTable,yytext,string,literal,yylineno); return STRING; }
[0-9]+      { yylval.node=create_node(&symbolTable,yytext,integer,literal,yylineno); return NUMBER; } // Integer literals
[0-9]+"."[0-9]+([eE][-+]?[0-9]+)? { yylval.node=create_node(&symbolTable,yytext,real,literal,yylineno); return NUMBER; } // Floating-point literals
[a-zA-Z_][a-zA-Z0-9_]*  {  yylval.node=create_node(&symbolTable,yytext,identifier,unknown,yylineno);  return ID; }
[ \t]     {} // Ignore whitespace
[\n]    {}
.           { printf("error-%s\n",yytext); };

%%