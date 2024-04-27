%{
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

%}

    %union{
        struct SymbolTableEntry *symEntry;
        struct TreeNode* node;
    };

    %define parse.error verbose
    %debug
    
    

    %token<symEntry> INT DOUBLE BOOLEAN CHAR ID FLOAT VOID STRING 
    %token<symEntry> PUBLIC PRIVATE PROTECTED CLASS STATIC FINAL
    %token<symEntry> IF ELSE WHILE FOR RETURN MAIN ARGS CHARACTER NUMBER ERROR INC DEC
    %token<symEntry> SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE
    %token<symEntry> AND OR NOT DOT LBRACKET RBRACKET EQ NE LT GT LE GE TRUE FALSE
    %token<symEntry>  TIMES PLUS MINUS  DIVIDE MOD  PLUSASG MINUSASG TIMESASG DIVIDEASG ASSIGN

    %type<node> program member_decl_list member_decl member_second_part class_decl class_decl_list
    %type<node> mdfr arg_list arg decl_ids decl_id stmt_list stmt
    %type<node> if_stmt while_stmt for_stmt return_stmt decl_stmt
    %type<node> expr asg_expr arm_expr log_expr literal relop
    %type<node> armop asg_op brackets mem_access array_acess diff_ids
    %type<node> method_call pass_args empty_brackets TYPE
    %type<node> TYPES access_modfr  M N

    %start program

%%

program : class_decl_list {
            root=$$ = create_tree_node("program",st_program, 1, $1);
            printf("Parsing completed\n");
            // inorder_traversal(root,0);
        }
        | error RBRACE { yyerror("Syntax error"); $$ = NULL; } 
        ;
class_decl_list : class_decl { $$ = $1; }
        | class_decl_list class_decl {
            $$=$1;
            add_children($$,1,$2);
        };

class_decl : access_modfr CLASS ID { check_and_set_dType($3, dt_class); } LBRACE member_decl_list RBRACE {
            struct TreeNode *n2=copy_entry_to_node($2);
            struct TreeNode *n3=copy_entry_to_node($3);
            $$ = create_tree_node("class_decl",st_class, 4, $1, n2, n3, $6);
        };
member_decl_list : member_decl { $$ = $1; }
        | member_decl_list member_decl {
            $$ = create_tree_node("member_decl_list",st_member_list, 2, $1, $2);
        };

member_decl : access_modfr mdfr TYPES ID { 
                check_and_set_dType($4,$3->dataType);
                set_dimension($4,$3->dimen);
            } member_second_part {
            struct TreeNode *n4 = copy_entry_to_node($4);
            $$ = create_tree_node("member_decl",st_member, 5, $1, $2, $3, $4,$6);
        };
member_second_part : SEMICOLON { $$ = NULL;  }
        | LPAREN arg_list RPAREN
        LBRACE {
            set_member_method_values(peek_scope(scopeStack),$<symEntry>-1, $<node>-2->dataType, $2);
        } stmt_list RBRACE {
            
            $$ = create_tree_node("member_second_part",st_member_second, 2, $2, $6);
            
        }
        | error RBRACE { yyerror("Syntax error"); $$ = NULL; } 
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; }
        ;
mdfr    : { $$ = NULL;}| STATIC { $$=copy_entry_to_node($1);} |FINAL { $$=copy_entry_to_node($1);} ;

arg_list :arg {
            $$ = create_tree_node("arg_list", st_args, 1, $1);
        }
        | arg_list COMMA arg {
            // Add the new arg as a child of the existing arg_list node
            add_children($1, 1, $3);
            $$ = $1; // Set the result to the updated arg_list node
        }
        |arg_list COMMA /* empty */ {
                // This rule ensures that a comma without an argument following it is not accepted
                yyerror("Unexpected comma in argument list");
        }
        | /* empty */ {
            $$ = create_tree_node("arg_list", st_args, 0);
        }
        ;


arg         : TYPES ID { 
                check_and_set_dType($2,$1->dataType);
                struct TreeNode *n2=copy_entry_to_node($2);
                $$ = create_tree_node("arg", st_args,2, $1, n2);
                setDimension($$, $1->dimen);            
                setDataType($$, $1->dataType);
            }
            | TYPES {
                $$ = $1;
            }
            ;

access_modfr: PUBLIC {  $$=copy_entry_to_node($1); } | PRIVATE {  $$=copy_entry_to_node($1); }
            | PROTECTED {  $$=copy_entry_to_node($1); } ;
TYPES       : TYPE empty_brackets {  
                $$ = create_tree_node("TYPE", st_types, 0);
                setDataType($$, $1->dataType);
                setDimension($$, $2->dimen);
            } ;
empty_brackets : { $$ = create_tree_node("dimension",st_dimension,0); }  // Initialize dimen to 0
            | empty_brackets LBRACKET RBRACKET { 
                //if(!$1)
                $$ = $1;
                setDimension($$, $1->dimen + 1);  // Increase dimen by 1
                // printf("dimen: %d\n", $1->dimen);
            }
            | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
            ;

TYPE        : INT { $$=copy_entry_to_node($1); }| DOUBLE { $$=copy_entry_to_node($1); }
            | BOOLEAN { $$=copy_entry_to_node($1); }| CHAR { $$=copy_entry_to_node($1); }
            | FLOAT { $$=copy_entry_to_node($1);  } | VOID { $$=copy_entry_to_node($1); } 
            | STRING {$$=copy_entry_to_node($1);};

stmt_list : /* empty */ {
            $$ = create_tree_node("stmt_list", st_stmt_list, 0); // If the statement list is empty, set the result to NULL
        }
        | stmt_list M stmt {
            add_children($1, 1, $2);
            $$ = $1; // Set the result to the updated stmt_list node
            backpatch($1->nextList,$2->nextList->current);
            $$->nextList=$3->nextList;
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

stmt : LBRACE stmt_list RBRACE {  $$ = create_tree_node("stmt",st_stmt_list, 1, $2); $$->nextList=$2->nextList;}
        | expr SEMICOLON { $$=$1;}| if_stmt {  $$ = $1; }| while_stmt {  $$ = $1; }
        | for_stmt {  $$ = $1; }| return_stmt {  $$ = $1; }| decl_stmt {  $$ = $1; }
        ;

if_stmt : IF LPAREN log_expr RPAREN M stmt {
            struct TreeNode *n1=copy_entry_to_node($1);
            $$ = create_tree_node("if_stmt", st_if, 3, n1, $3, $6);
            backpatch($3->trueList,$5->nextList->current);
            $$->nextList=mergeLists($3->falseList,$6->nextList);
        }| IF LPAREN log_expr RPAREN M stmt N ELSE M stmt {
            struct TreeNode *n1=copy_entry_to_node($1);
            $$ = create_tree_node("if_stmt", st_if, 4, n1, $3, $6, $10);
            printf("else is there\n ");
            backpatch($3->trueList,$5->nextList->current);
            backpatch($3->falseList,$9->nextList->current);
            $$->nextList=mergeLists(mergeLists($6->nextList,$7->nextList),$10->nextList);
        }
        ;
N          : { $$=create_tree_node("N",st_if,0); $$->nextList=newList(indx); codeGen("goto", "", "", "");} ;    
M          : { $$=create_tree_node("M",st_if,0); $$->nextList=newList(indx); } ;
while_stmt : WHILE M LPAREN log_expr RPAREN M stmt {
            struct TreeNode *n1=copy_entry_to_node($1);
            $$ = create_tree_node("while_stmt", st_while, 3, n1, $4, $7);
            backpatch($7->nextList,$2->nextList->current);
            backpatch($4->trueList,$6->nextList->current);
            $$->nextList=$4->falseList;
            char *x=malloc(10);
            sprintf(x,"L%d",$2->nextList->current);
            codeGen("goto", "", "", x);
        }
        ;

for_stmt : FOR LPAREN expr SEMICOLON log_expr SEMICOLON M expr RPAREN stmt {
            struct TreeNode *n1=copy_entry_to_node($1);
            $$ = create_tree_node("for_stmt", st_for, 5, n1, $3, $5, $8, $10);

            backpatch($8->nextList,$2->nextList->current);
            backpatch($5->trueList,$9->nextList->current);
            // backpatch($5->falseList,$10->nextList->current);
            // $$->nextList=$5->falseList;
            // char *x=malloc(10);
            // sprintf(x,"L%d",$2->nextList->current);
            // codeGen("goto", "", "", x);

        };

return_stmt : RETURN expr SEMICOLON {
            struct TreeNode *n1=copy_entry_to_node($1);
            $$ = create_tree_node("return_stmt", st_return, 2, n1, $2);
            codeGen("return","", "", $2->name);
        }
        | RETURN SEMICOLON {
            struct TreeNode *n1=copy_entry_to_node($1);
            $$ = create_tree_node("return_stmt", st_return, 1, $1);
            codeGen("return","", "", "");
        }
        ;

decl_stmt : TYPES decl_ids SEMICOLON {  $$ = create_tree_node("decl_stmt",st_stmt, 2, $1, $2); }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;
decl_ids : decl_id {
            $$ = create_tree_node("decl_ids", st_decl_ids, 1, $1);
        }
        | decl_ids COMMA decl_id {
            add_children($1, 1, $3);
            $$ = $1; // Set the result to the updated decl_ids node
        }
        | error SEMICOLON { yyerror("Syntax error"); $$ = NULL; } 
        ;

decl_id : ID {
            check_and_set_dType($1,$<node>0->dataType);
            set_dimension($1,$<node>0->dimen);
            $$=copy_entry_to_node($1);
        }| ID {
            check_and_set_dType($1,$<node>0->dataType);
            set_dimension($1,$<node>0->dimen);
            //printf("----------------------------->dimension :%d\n",$1->dimen);
        } ASSIGN expr {
            struct TreeNode *n1=copy_entry_to_node($1);
            struct TreeNode *n3= copy_entry_to_node($3);
            codeGen("=", $1->lexeme, $4->name, "");
            $$ = create_tree_node("assign_expr",st_expr, 3, n3, n1, $4);
        }
        | error COMMA { yyerror("Syntax error"); $$ = NULL; } 
        ;
expr    : asg_expr { $$=$1; } | arm_expr { $$=$1; } 
        | log_expr { $$=$1; } | LPAREN expr RPAREN { $$=$2; } 
        | diff_ids { $$=$1; } ;

asg_expr : ID asg_op expr {
            is_defined($1);
            struct TreeNode *n1=copy_entry_to_node($1);
            checkType(n1,$3,yylineno);
            $$ = create_tree_node($1->lexeme,st_expr, 3, $2, n1, $3);
            codeGen($2->name, $3->name,"", $$->name);
        }
        | ID INC {
            is_defined($1);
            struct TreeNode *n1=copy_entry_to_node($1);
            checkdType(n1,dt_integer,0,yylineno);
            struct TreeNode *n2=copy_entry_to_node($2);
            codeGen("+", $1->lexeme,  "1", $1->lexeme);
            $$ = create_tree_node(new_temp(),st_expr, 2, n2, n1);

        }
        | ID DEC {
            is_defined($1);
            struct TreeNode *n1=copy_entry_to_node($1);
            checkdType(n1,dt_integer,0,yylineno);
            struct TreeNode *n2=copy_entry_to_node($2);
            codeGen("-", $1->lexeme, "1", $1->lexeme);
            $$ = create_tree_node(new_temp(),st_expr, 2, $2, n1);
        }
        ;
asg_op      : PLUSASG { $$=copy_entry_to_node($1); } |MINUSASG { $$=copy_entry_to_node($1); } 
            | TIMESASG { $$=copy_entry_to_node($1); } | DIVIDEASG { $$=copy_entry_to_node($1); } 
            | ASSIGN { $$=copy_entry_to_node($1); };

arm_expr    : expr armop expr {
                checkType($1,$3,yylineno);
                $$ = create_tree_node(new_temp(),st_expr, 3, $2, $1, $3);
                setDataType($$, $1->dataType);
                codeGen($2->name, $1->name, $3->name, $$->name);
            }| literal { $$=$1; } ;

log_expr    : log_expr AND M log_expr {
                checkType($1,$4,yylineno);
                struct TreeNode *n2=copy_entry_to_node($2);
                $$ = create_tree_node(new_temp(),st_log_expr, 3, n2, $1, $4);
                setDataType($$, $1->dataType);
                backpatch($1->trueList,$3->nextList->current);
                $$->trueList=$4->trueList;
                $$->falseList=mergeLists($1->falseList,$4->falseList);
            }
            | log_expr OR M log_expr {
                checkType($1,$4,yylineno);
                struct TreeNode *n2=copy_entry_to_node($2);
                $$ = create_tree_node(new_temp(),st_log_expr, 3, n2, $1, $4);
                setDataType($$, $1->dataType);
                backpatch($1->falseList,$3->nextList->current);
                $$->trueList=mergeLists($1->trueList,$4->trueList);
                $$->falseList=$4->falseList;
            }
            | NOT log_expr {
                checkdType($2,dt_boolean,0,yylineno);
                struct TreeNode *n1=copy_entry_to_node($1);
                $$ = create_tree_node(new_temp(),st_log_expr, 2, n1, $2);
                setDataType($$, $2->dataType);
                $$->trueList=$2->falseList;
                $$->falseList=$2->trueList;
            }
            | expr relop expr {  
                checkType($1,$3,yylineno);         
                $$ = create_tree_node(new_temp(),st_log_expr, 3, $2, $1, $3);
                setDataType($$, dt_boolean);
                $$->trueList=newList(indx);
                $$->falseList=newList(indx+1);
                char *x=malloc(strlen($2->name)+strlen($1->name)+strlen($3->name)+1);
                int k=0;
                for(int i=0;i<strlen($1->name);i++){
                    x[k++]=($1->name)[i];
                }
                for(int i=0;i<strlen($2->name);i++){
                    x[k++]=($2->name)[i];
                }
                for(int i=0;i<strlen($3->name);i++){
                    x[k++]=($3->name)[i];
                }
                codeGen("if", x,"goto", "");
                codeGen("goto", "", "", "");
            }
            | LPAREN log_expr RPAREN {
                checkdType($2,dt_boolean,0,yylineno);
                $$ = $2;
            }| TRUE { $$=copy_entry_to_node($1); $$->trueList=newList(indx); codeGen("goto", "", "", ""); } 
            | FALSE { $$=copy_entry_to_node($1); $$->trueList=newList(indx); codeGen("goto", "", "", ""); } ;


relop       : EQ { $$=copy_entry_to_node($1); }| NE{ $$=copy_entry_to_node($1); }| LT{ $$=copy_entry_to_node($1); }
            | GT{ $$=copy_entry_to_node($1); }| LE{ $$=copy_entry_to_node($1); }| GE { $$=copy_entry_to_node($1); };
armop       :  TIMES{ $$=copy_entry_to_node($1); }
            | DIVIDE{ $$=copy_entry_to_node($1); }| MOD{ $$=copy_entry_to_node($1); }
            | PLUS{ $$=copy_entry_to_node($1); }| MINUS{ $$=copy_entry_to_node($1); };
literal     : NUMBER { $$=copy_entry_to_node($1); }| STRING{ $$=copy_entry_to_node($1); }| CHARACTER { $$=copy_entry_to_node($1); };
diff_ids    : mem_access  { $$=$1; } | array_acess { $$ = $1; } | method_call { $$ = $1; };

mem_access  : mem_access DOT mem_access { $$ = create_tree_node("mem_access",st_mem_access, 3, $2, $1, $3); }
            | ID { is_defined($1); $$=copy_entry_to_node($1); }
            | method_call { $$ = $1; };

array_acess : ID brackets { 
                is_defined($1);
                check_array_access($1,$2->dimen,yylineno);
                struct TreeNode *n1=copy_entry_to_node($1);
                $$ = create_tree_node(new_temp(),st_array_access, 2, n1, $2); 
                setDataType($$, $1->dataType);
                setDimension($$, $1->dimen-$2->dimen);
                char*t=new_temp(); 
                codeGen("*", $2->children[0]->name, "4", t);
                char *x=malloc(strlen($1->lexeme)+2+1);
                sprintf(x,"(%s)", $1->lexeme);
                codeGen("+", t, x, $$->name);
                // Set dimension to the difference of the two dimensions

            };
method_call : ID LPAREN pass_args RPAREN { 
                is_defined($1);
                is_method($1);
                check_method_args($1,$3,yylineno);
                struct TreeNode *n1=copy_entry_to_node($1); 
                $$ = create_tree_node("method_call",st_method_call, 2, n1, $3);
                setDataType($$, $1->dataType);
                setDimension($$, 0);
                for(int i=0;i<$3->num_children;i++){
                    codeGen("param", $3->children[i]->name, "", "");
                } 
                codeGen("call", $1->lexeme, "", "");

                 }
            | ID LPAREN RPAREN { 
                is_defined($1);
                is_method($1);
                check_method_args($1,NULL,yylineno);
                struct TreeNode *n1=copy_entry_to_node($1);
                $$ = create_tree_node("method_call", st_method_call,1,n1); 
            };

pass_args   : pass_args COMMA expr { 
                $$ = $1;
                add_children($$, 1, $3);
            }
            | expr { $$ = create_tree_node("pass_args",st_pass_args, 1, $1); }
            | { $$ = NULL; };

brackets :   brackets LBRACKET expr RBRACKET {
                $$ = $1;
                checkdType($1,dt_integer,0,yylineno);
                add_children($$, 1, $3);
                setDimension($$,$$->dimen + 1); // Increment dimension by 1
            }
            | LBRACKET expr RBRACKET {
                checkdType($2,dt_integer,0,yylineno);
                $$ = create_tree_node("brackets", st_expr, 1, $2);
                setDimension($$, 1); // Set dimension to 1 for single brackets
            };

%%

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

