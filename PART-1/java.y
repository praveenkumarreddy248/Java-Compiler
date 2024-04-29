%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "TreeNode.h"
#define MAX_CHILDREN 10
// Tree node structure
extern int yylineno;
int yylex(void);
void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

// Define a function to handle parse errors and continue parsing
void yyparse_error(const char *message) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, message);
}
void inorder_traversal(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    // Visit children nodes
    for (int i = 0; i < root->num_children; ++i) {
        inorder_traversal(root->children[i]);
    }
    // Print current node
    printf("%s\n", root->name);
}
typedef struct QueueNode {
    struct TreeNode *data;
    struct QueueNode *next;
} QueueNode;

// Define the structure of a queue
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

// Function to enqueue a node to the queue
void enqueue(Queue *queue, TreeNode *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = node;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node from the queue
TreeNode* dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    
    QueueNode *temp = queue->front;
    TreeNode *data = temp->data;
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return data;
}

// Function to perform breadth-first search
void bfs(TreeNode *root) {
    if (root == NULL) return;

    // Create a queue for BFS
    Queue *queue = createQueue();
    printf("/////////start////////////////\n");
    // Enqueue the root node
    enqueue(queue, root);
    int r=0;
    // Iterate over the nodes in the queue
    int width=1;
    while (!isEmpty(queue)) {
        int w=0;
        // Dequeue a node and print its name
        for(int j=0;j<width;j++){
            TreeNode *current = dequeue(queue);
            
                printf("%d. %s\t", r, current->name);
                r++;
            

            // Enqueue all children of the dequeued node
            for (int i = 0; i < current->num_children; ++i) {
                w++;
                enqueue(queue, current->children[i]);
            }
        }
        printf("\n");
        width=w;
        
    }
    printf("\n");

    // Free memory allocated for the queue
    free(queue);
    printf("//////////end/////////////////\n");
}
// Function to create a tree node
struct TreeNode *create_tree_node(char *name, int num_children, ...) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->name = (char*)malloc(strlen(name) ); // Allocate memory for the name string
    strcpy(node->name, name); // Copy the name string
    node->num_children = num_children;
    node->nodetype = non_terminal;
    
    // Print debug information
    // printf("Creating node: name = %s, num_children = %d\n", node->name, node->num_children);

    if (num_children < 1)
        return node;

    va_list args;
    va_start(args, num_children);

    // Allocate memory for children array
    node->children = (struct TreeNode**)malloc(num_children * sizeof(struct TreeNode*));
    for (int i = 0; i < num_children; ++i) {
        // Retrieve each child from variable arguments
        node->children[i] = va_arg(args, struct TreeNode *);
        if(node->children[i]){
            // printf("%d. %s  ",i,node->children[i]->name);
        }
    }
    va_end(args);
    // printf("\n");
    return node;
}

int yywrap(void){
	return 1;
}


struct TreeNode *root=NULL;


// Tree node structure


%}
%union{
    struct TreeNode* node;

};

%define parse.error verbose

%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left TIMES DIVIDE MOD
%right NOT
%left DOT


%token INT DOUBLE BOOLEAN CHAR ID FLOAT VOID 
%token PUBLIC PRIVATE PROTECTED CLASS STATIC FINAL
%token IF ELSE WHILE FOR RETURN MAIN ARGS CHARACTER NUMBER ERROR
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
%token PLUS MINUS TIMES DIVIDE MOD AND OR NOT ASSIGN DOT LBRACKET RBRACKET EQ NE LT GT LE GE TRUE FALSE STRING

%type<node> INT DOUBLE BOOLEAN CHAR ID FLOAT VOID 
%type<node> PUBLIC PRIVATE PROTECTED CLASS STATIC FINAL
%type<node> IF ELSE WHILE FOR RETURN MAIN ARGS CHARACTER NUMBER ERROR
%type<node> SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
%type<node> PLUS MINUS TIMES DIVIDE MOD AND OR NOT ASSIGN DOT LBRACKET RBRACKET EQ NE LT GT LE GE TRUE FALSE STRING


%type<node> program class_declaration_list class_declaration member_declaration_list member_declaration method_declaration field_declaration declaration_ids parameter_list parameter statement_list decl_statement decl_ids statement if_statement while_statement for_statement return_statement expression_statement expression assignment_expression arithmetic_expression logical_expression literal
%type<node> ACCESS_MODIFIER TYPE TYPES empty_brackets



%start program


%%

program : class_declaration_list {

    root=$$ = create_tree_node("program", 1, $1);
    // printf("%s\n",$$->name);
    bfs(root);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

class_declaration_list : class_declaration {
    $$ = $1;
    // inorder_traversal($$);
}
| class_declaration_list class_declaration {
    
    $$ = create_tree_node("class_declaration_list", 2, $1, $2);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

class_declaration : ACCESS_MODIFIER CLASS ID LBRACE member_declaration_list RBRACE {
    $$ = create_tree_node("class_declaration", 6, $1, $2, $3, $4, $5, $6);
    // printf("%s\n",$2->name);
    // printf("%s\n",$4->name);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

member_declaration_list : /* empty */ {
    $$ = create_tree_node("member_declaration_list", 0);
}
| member_declaration_list member_declaration {
    $$ = create_tree_node("member_declaration_list", 2, $1, $2);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

member_declaration : method_declaration {
    $$ = $1;
}
| field_declaration {
    $$ = $1;
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

method_declaration : ACCESS_MODIFIER TYPES ID LPAREN parameter_list RPAREN LBRACE statement_list RBRACE {
    $$ = create_tree_node("method_declaration", 9, $1, $2, $3, $4, $5, $6, $7, $8,$9);
}
| ACCESS_MODIFIER TYPES MAIN LPAREN parameter_list RPAREN LBRACE statement_list RBRACE {
    $$ = create_tree_node("method_declaration", 9, $1, $2, $3, $4, $5, $6, $7, $8, $9);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

field_declaration : ACCESS_MODIFIER TYPES declaration_ids SEMICOLON {
    $$ = create_tree_node("field_declaration", 4, $1, $2, $3, $4);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

declaration_ids : declaration_ids COMMA declaration_ids {
    $$ = create_tree_node("declaration_ids", 3, $1, $2, $3);
}
| ID {
    $$ = $1;
}
| ID ASSIGN expression {
    $$ = create_tree_node("declaration_ids", 3, $1, $2, $3);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

parameter_list : /* empty */ {
    $$ = create_tree_node("parameter_list", 0);
}
| parameter {
    $$ = $1;
}
| parameter_list COMMA parameter {
    $$ = create_tree_node("parameter_list", 3, $1, $2, $3);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

parameter : TYPES ID {
    $$ = create_tree_node("parameter", 2, $1, $2);
}
| TYPES {
    $$ = create_tree_node("parameter", 1, $1);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

statement_list : /* empty */ {
    $$ = create_tree_node("statement_list", 0);
}
| statement {
    $$ = $1;
}
| statement_list statement {
    $$ = create_tree_node("statement_list", 2, $1, $2);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

decl_statement : TYPES decl_ids SEMICOLON {
    $$ = create_tree_node("decl_statement", 3, $1, $2, $3);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;
ACCESS_MODIFIER : PUBLIC {
  $$ = $1; 
//   printf("%s\n",$1->name);
}
| PRIVATE {
  $$ = $1;
}
| PROTECTED {
  $$ = $1;
}
| STATIC {
  $$ = $1; }
| FINAL {
  $$ = $1 ;
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

TYPES : TYPE empty_brackets {
  $$ = create_tree_node("TYPES", 2, $1, $2);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

empty_brackets : /* empty */ {
  $$ = create_tree_node("no_empty_brackets", 0);
}
| LBRACKET RBRACKET {
  $$ = create_tree_node("empty_brackets", 2,$1,$2);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

TYPE : INT {
  $$ = $1;
//   printf(" node %s\n",$$->name);
}
| DOUBLE {
  $$ = $1;
}
| BOOLEAN {
  $$ = $1;
}
| CHAR {
    $$=$1;
}
| FLOAT {
  $$ = $1;
}
| ID {
  $$ = $1;
}
| VOID {
  $$ = $1;
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;




decl_ids : declaration_ids COMMA decl_ids {
    $$ = create_tree_node("decl_ids", 3, $1, $2, $3);
}
| ID ASSIGN expression {
    $$ = create_tree_node("decl_ids", 3, $1, $2, $3);
}
| ID {
    $$ = create_tree_node("decl_ids", 1, $1);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

statement : LBRACE statement_list RBRACE {
    $$ = create_tree_node("statement", 2, $1, $2);
}
| expression_statement SEMICOLON {
    $$ = $1;
}
| if_statement {
    $$ = $1;
}
| while_statement {
    $$ = $1;
}
| for_statement {
    $$ = $1;
}
| return_statement {
    $$ = $1;
}
| decl_statement {
    $$ = $1;
}
| logical_expression SEMICOLON {
    $$ = create_tree_node("statement", 1, $1);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } // Error recovery
;

if_statement : IF LPAREN logical_expression RPAREN statement {
    $$ = create_tree_node("if_statement", 5, $1, $2, $3, $4, $5);
}
| IF LPAREN logical_expression RPAREN statement ELSE statement {
    $$ = create_tree_node("if_statement", 7, $1, $2, $3, $4, $5, $6, $7);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

while_statement : WHILE LPAREN logical_expression RPAREN statement {
    $$ = create_tree_node("while_statement", 5, $1, $2, $3, $4, $5);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

for_statement : FOR LPAREN expression SEMICOLON logical_expression SEMICOLON expression RPAREN statement {
    $$ = create_tree_node("for_statement", 9, $1, $2, $3, $4, $5, $6, $7,$8, $9);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

return_statement : RETURN expression SEMICOLON{
    $$ = create_tree_node("return_statement", 3, $1, $2, $3);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

expression_statement : expression {
    $$ = create_tree_node("expression_statement", 1, $1);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

expression : assignment_expression {
    $$ = $1;
}
| arithmetic_expression {
    $$ = $1;
}
| logical_expression {
    $$ = $1;
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

assignment_expression : ID ASSIGN expression {
    $$ = create_tree_node("assignment_expression", 3, $1, $2, $3);
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

arithmetic_expression : expression PLUS expression {
    $$ = create_tree_node("arithmetic_expression", 3, $1, $2, $3);
}
| expression MINUS expression {
    $$ = create_tree_node("arithmetic_expression", 3, $1, $2, $3);
}
| expression TIMES expression {
    $$ = create_tree_node("arithmetic_expression", 3, $1, $2, $3);
}
| expression DIVIDE expression {
    $$ = create_tree_node("arithmetic_expression", 3, $1, $2, $3);
}
| expression MOD expression {
    $$ = create_tree_node("arithmetic_expression", 3, $1, $2, $3);
}
| LPAREN expression RPAREN {
    $$ = $1;
}
| literal {
    $$ = $1;
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

logical_expression : logical_expression AND logical_expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| logical_expression OR logical_expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| NOT logical_expression {
    $$ = create_tree_node("logical_expression", 2, $1, $2);
}
| expression EQ expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| expression NE expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| expression LT expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| expression GT expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| expression LE expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| expression GE expression {
    $$ = create_tree_node("logical_expression", 3, $1, $2, $3);
}
| LPAREN logical_expression RPAREN {
    $$ = $1;
}
| TRUE {
    $$ =$1;
}
| FALSE {
    $$ = $1;
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

literal : NUMBER {
    $$ = $1;
}
| STRING {
    $$ = $1;
}
| CHARACTER {
    $$ = $1;
}
| error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
;

%%


// Main function (entry point)
int main(int argc, char *argv[]) {
    
    
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

    // Parse the input
    yyparse();

    // Close input file
    fclose(input_file);
    
    return 0;
}

