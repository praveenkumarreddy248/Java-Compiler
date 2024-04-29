%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"
#include "TreeNode.h"
#include "java.tab.h"

extern int yylineno;
int yylex(void);
extern Queue* createQueue();
extern int isEmpty(Queue *queue);
extern void enqueue(Queue *queue, TreeNode *node);
extern TreeNode* dequeue(Queue *queue);
extern void bfs(TreeNode *root);
extern struct TreeNode *create_tree_node(char *name, int num_children, ...);
extern void inorder_traversal(struct TreeNode *root, int depth);
extern void free_tree(struct TreeNode *root);
extern int yyrestart(void*);
extern void print_table(struct SymbolTableEntry*head);
void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

// Define a function to handle parse errors and continue parsing
void yyparse_error(const char *message) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, message);
}

int yywrap(void){ return 1; }

struct TreeNode *root=NULL;
struct SymbolTableEntry* symbolTable=NULL;


%}
%union{
    struct TreeNode* node;

};

%define parse.error verbose
%debug

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE MOD
%right NOT
%left DOT
%start program

%token INT DOUBLE BOOLEAN CHAR ID FLOAT VOID 
%token PUBLIC PRIVATE PROTECTED CLASS STATIC FINAL
%token IF ELSE WHILE FOR RETURN MAIN ARGS CHARACTER NUMBER ERROR INC DEC
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
%token PLUS MINUS TIMES DIVIDE PLUSASG MINUSASG TIMESASG DIVIDEASG MOD AND OR NOT ASSIGN DOT LBRACKET RBRACKET EQ NE LT GT LE GE TRUE FALSE STRING

    %type<node> INT DOUBLE BOOLEAN CHAR ID FLOAT VOID 
    %type<node> PUBLIC PRIVATE PROTECTED CLASS STATIC FINAL
    %type<node> IF ELSE WHILE FOR RETURN MAIN ARGS CHARACTER NUMBER ERROR INC DEC
    %type<node> SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
    %type<node> PLUS MINUS TIMES DIVIDE PLUSASG MINUSASG TIMESASG DIVIDEASG MOD AND OR NOT ASSIGN DOT LBRACKET RBRACKET EQ NE LT GT LE GE TRUE FALSE STRING

%type<node> program class_decl_list class_decl member_decl_list member_decl method_decl field_decl decl_ids par_list par stmt_list decl_stmt stmt if_stmt while_stmt for_stmt return_stmt expr asg_expr arm_expr log_expr literal
%type<node> ACCESS_MODIFIER TYPE TYPES empty_brackets relop armop modifiers diff_ids mem_access array_acess method_call pass_args BRACKETS   asg_op 

%%

program : class_decl_list {
            root=$$ = create_tree_node("program", 1, $1);
            inorder_traversal(root,0);
        }
        | error RBRACE { yyerror("Syntax error"); $$ = NULL; } 
        ;

class_decl_list : class_decl { $$ = $1;}
        | class_decl_list class_decl {
            $$ = create_tree_node("class_decl_list", 2, $1, $2);
        }
        | error RBRACE { yyerror("Syntax error"); $$ = NULL; } 
        ;
class_decl : ACCESS_MODIFIER CLASS ID LBRACE member_decl_list RBRACE {
            $$ = create_tree_node("class_decl", 6, $1, $2, $3, $4, $5, $6);
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

member_decl_list : /* empty */ {
            $$ = create_tree_node("member_decl_list", 0);
        }
        | member_decl_list member_decl {
            $$ = create_tree_node("member_decl_list", 2, $1, $2);
        }
        ;

member_decl : modifiers method_decl { $$ = create_tree_node("method",2,$1,$2);} | modifiers field_decl { $$ = create_tree_node("field",2,$1,$2);} ;
modifiers          : { $$ = NULL;}| STATIC { $$ = $1;} |FINAL { $$ = $1;} ;
method_decl : ACCESS_MODIFIER TYPES ID LPAREN par_list RPAREN LBRACE stmt_list RBRACE {
            $$ = create_tree_node("method_decl", 9, $1, $2, $3, $4, $5, $6, $7, $8,$9);
        }
        | ACCESS_MODIFIER TYPES MAIN LPAREN par_list RPAREN LBRACE stmt_list RBRACE {
            $$ = create_tree_node("method_decl", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);
        }
        | error RBRACE { yyerror("Syntax error"); $$ = NULL; } 
        ;

field_decl : ACCESS_MODIFIER TYPES decl_ids SEMICOLON {
            $$ = create_tree_node("field_decl", 4, $1, $2, $3, $4);
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

decl_ids : decl_ids COMMA decl_ids {
            $$ = create_tree_node("decl_ids", 3, $1, $2, $3);
        }
        | ID {
            $$ = $1;
        }
        | ID ASSIGN expr {
            $$ = create_tree_node("decl_ids", 3, $1, $2, $3);
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

par_list : /* empty */ {
            $$ = create_tree_node("par_list", 0);
        }
        | par {
            $$ = $1;
        }
        | par_list COMMA par {
            $$ = create_tree_node("par_list", 3, $1, $2, $3);
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

par : TYPES ID {
            $$ = create_tree_node("par", 2, $1, $2);
        }
        | TYPES {
            $$ = create_tree_node("par", 1, $1);
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

stmt_list : /* empty */ {
            $$ = create_tree_node("stmt_list", 0);
        }
        | stmt {
            $$ = $1;
        }
        | stmt_list stmt {
            $$ = create_tree_node("stmt_list", 2, $1, $2);
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

decl_stmt : TYPES decl_ids SEMICOLON {  $$ = create_tree_node("decl_stmt", 3, $1, $2, $3);}
    | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
    ;
ACCESS_MODIFIER : PUBLIC {  $$ = $1; } | PRIVATE {  $$ = $1; }| PROTECTED {  $$ = $1; } ;
TYPES : TYPE empty_brackets {  $$ = create_tree_node("TYPES", 2, $1, $2);} ;
empty_brackets : { $$ = NULL;}| LBRACKET RBRACKET {  $$ = create_tree_node("empty_brackets", 2,$1,$2); }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

TYPE : INT { $$ = $1; }| DOUBLE { $$ = $1; }| BOOLEAN { $$ = $1; }| CHAR { $$ = $1; }
        | FLOAT { $$ = $1; }| ID { $$ = $1; }| VOID { $$ = $1; } ;


stmt : LBRACE stmt_list RBRACE {  $$ = create_tree_node("stmt", 2, $1, $2); }
        | expr SEMICOLON {  $$ = $1; }| if_stmt {  $$ = $1; }| while_stmt {  $$ = $1; }
        | for_stmt {  $$ = $1; }| return_stmt {  $$ = $1; }| decl_stmt {  $$ = $1; }
        ;

if_stmt : IF LPAREN log_expr RPAREN stmt {
            $$ = create_tree_node("if_stmt", 5, $1, $2, $3, $4, $5);
        }
        | IF LPAREN log_expr RPAREN stmt ELSE stmt {
            $$ = create_tree_node("if_stmt", 7, $1, $2, $3, $4, $5, $6, $7);
        }
        ;

while_stmt : WHILE LPAREN log_expr RPAREN stmt {
            $$ = create_tree_node("while_stmt", 5, $1, $2, $3, $4, $5);
        }
        ;

for_stmt : FOR LPAREN expr SEMICOLON log_expr SEMICOLON expr RPAREN stmt {
            $$ = create_tree_node("for_stmt", 9, $1, $2, $3, $4, $5, $6, $7,$8, $9);
        };

return_stmt : RETURN expr SEMICOLON {
            $$ = create_tree_node("return_stmt", 3, $1, $2, $3);
        }|
        RETURN SEMICOLON {
            $$ = create_tree_node("return_stmt", 1, $1);
        }
        ;

expr : asg_expr { $$=create_tree_node("expr",1,$1); } | arm_expr { $$=create_tree_node("expr",1,$1); } 
        |log_expr { $$=create_tree_node("expr",1,$1); } | LPAREN expr RPAREN { $$=$2; } 
        | diff_ids{ $$=$1; };

asg_expr : ID ASSIGN expr {
            $$ = create_tree_node("asg_expr", 3, $1, $2, $3);
        }
        | ID asg_op expr {
            $$ = create_tree_node("asg_expr", 3, $1, $2, $3);
        }
        | ID INC {
            $$ = create_tree_node("asg_expr", 2, $1, $2);
        }
        | ID DEC {
            $$ = create_tree_node("asg_expr", 2, $1, $2);
        }
        ;
asg_op   : PLUSASG { $$=$1; } |MINUSASG { $$=$1; } | TIMESASG { $$=$1; } | DIVIDEASG { $$=$1; };

arm_expr : expr armop expr {
            $$ = create_tree_node("arm_expr", 3, $1, $2, $3);
        } | literal { $$=$1; } ;

log_expr : log_expr AND log_expr {
            $$ = create_tree_node("log_expr", 3, $1, $2, $3);
        }
        | log_expr OR log_expr {
            $$ = create_tree_node("log_expr", 3, $1, $2, $3);
        }
        | NOT log_expr {
            $$ = create_tree_node("log_expr", 2, $1, $2);
        }
        | expr relop expr {
            $$ = create_tree_node("log_expr", 3, $1, $2, $3);
        }
        | LPAREN log_expr RPAREN {
            $$ = $1;
        }| TRUE { $$=$1; } | FALSE { $$=$1; } | diff_ids { $$=$1; };
relop : EQ { $$ = $1; }| NE{ $$ = $1; }| LT{ $$ = $1; }| GT{ $$ = $1; }| LE{ $$ = $1; }| GE { $$ = $1; };
armop : PLUS{ $$ = $1; }| MINUS{ $$ = $1; }| TIMES{ $$ = $1; }| DIVIDE{ $$ = $1; }| MOD{ $$ = $1; };
literal : NUMBER { $$ = $1; }| STRING{ $$ = $1; }| CHARACTER { $$ = $1; };
diff_ids    : mem_access  { $$=$1; } | array_acess { $$ = $1; } | method_call { $$ = $1; };

mem_access  : mem_access DOT mem_access { $$ = create_tree_node("mem_access", 3, $1, $2, $3); }
            | ID { $$ = create_tree_node("mem_access", 1, $1); }
            | method_call { $$ = $1; };

array_acess : diff_ids BRACKETS { $$ = create_tree_node("array_acess", 2, $1, $2); };
method_call : ID LPAREN pass_args RPAREN { $$ = create_tree_node("method_call", 4, $1, $2, $3, $4); }
            | ID LPAREN RPAREN { $$ = create_tree_node("method_call", 2, $1, $2); };

pass_args   : pass_args COMMA pass_args { $$ = create_tree_node("pass_args", 3, $1, $2, $3); }
            | expr { $$ = create_tree_node("pass_args", 1, $1); };

BRACKETS    : LBRACKET expr RBRACKET BRACKETS {
                $$ = create_tree_node("BRACKETS", 4, $1, $2, $3, $4);
            }
            | LBRACKET expr RBRACKET {
                $$ = create_tree_node("BRACKETS", 3, $1, $2, $3);
            };


%%

// Main function (entry point)
int main(int argc, char *argv[]) {
    symbolTable=NULL;

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
    yyrestart(input_file);
    yyparse();
    print_table(symbolTable);
    // 
    // print_parse_table();
    // show_tree_view(root);
    // free_tree(root);
    fclose(input_file);
    
    return 0;
}

