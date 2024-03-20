%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "java.tab.h"
#include "TreeNode.h"
struct TreeNode *create_node(char *name) {
    //  printf("leaf %s  ",name);
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode*));
    node->num_children = 0;
    node->nodetype=terminal;
    node->name=(char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(node->name,name);
    node->children=NULL;
     printf("leaf %s\n",node->name);
    // if(node)printf("%d ok\n",node->nodetype);
    return node;
}


%}

%%
"public"    { yylval.node=create_node(yytext); return PUBLIC; }
"private"   { yylval.node=create_node(yytext); return PRIVATE; }
"protected" { yylval.node=create_node(yytext); return PROTECTED; }
"class"     { yylval.node=create_node(yytext); printf("%s\n////////////\n",yylval.node->name); return CLASS; }
"void"      { yylval.node=create_node(yytext); return VOID; }
"static"    { yylval.node=create_node(yytext); return STATIC; }
"main"      { yylval.node=create_node(yytext); return MAIN; }
"if"        { yylval.node=create_node(yytext); return IF; }     
"else"      { yylval.node=create_node(yytext); return ELSE; }   
"while"     { yylval.node=create_node(yytext); return WHILE; }  
"for"       { yylval.node=create_node(yytext); return FOR; }    
"return"    { yylval.node=create_node(yytext); return RETURN; } 
"true"      { yylval.node=create_node(yytext); return TRUE; }
"false"     { yylval.node=create_node(yytext); return FALSE; }
"{"         { yylval.node=create_node(yytext); return LBRACE; }
"}"         { yylval.node=create_node(yytext); return RBRACE; }
"("         { yylval.node=create_node(yytext); return LPAREN; }
")"         { yylval.node=create_node(yytext); return RPAREN; }
"["         { yylval.node=create_node(yytext); return LBRACKET; }
"]"         { yylval.node=create_node(yytext); return RBRACKET; }
";"         { yylval.node=create_node(yytext); return SEMICOLON; }
"+"         { yylval.node=create_node(yytext); return PLUS; }
"-"         { yylval.node=create_node(yytext); return MINUS; }
"*"         { yylval.node=create_node(yytext); return TIMES; }
"/"         { yylval.node=create_node(yytext); return DIVIDE; }
"%"         { yylval.node=create_node(yytext); return MOD; }
"&&"        { yylval.node=create_node(yytext); return AND; }
"||"        { yylval.node=create_node(yytext); return OR; }
"!"         { yylval.node=create_node(yytext); return NOT; }
"="         { yylval.node=create_node(yytext); return ASSIGN; }
"."         { yylval.node=create_node(yytext); return DOT; }
"=="        { yylval.node=create_node(yytext); return EQ; }
"!="        { yylval.node=create_node(yytext); return NE; }
"<"         { yylval.node=create_node(yytext); return LT; }
">"         { yylval.node=create_node(yytext); return GT; }
"<="        { yylval.node=create_node(yytext); return LE; }
">="        { yylval.node=create_node(yytext); return GE; }
","         { yylval.node=create_node(yytext); return COMMA; }
\"([^"\\]|\\.)*\" { yylval.node=create_node(yytext); return STRING; } // Corrected string literal regex
'[^'\\]'    { yylval.node=create_node(yytext); return CHARACTER; }
[0-9]+      { yylval.node=create_node(yytext); return NUMBER; } // Integer literals
[0-9]+"."[0-9]+([eE][-+]?[0-9]+)? { yylval.node=create_node(yytext); return NUMBER; } // Floating-point literals
[a-zA-Z_][a-zA-Z0-9_]*  {  yylval.node=create_node(yytext);  return ID; }
[ \t]     {} // Ignore whitespace
[\n]    {}
.           { return ERROR; }

%%

