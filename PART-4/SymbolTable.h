#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_YELLOW  "\033[0;33m"
#define COLOR_BLUE    "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"

// Union to store different types of values in the symbol table entry
typedef union Value{
    int val_int;
    float val_float;
    char *val_string;
} Value;

// Enum to represent the data type of a symbol
typedef enum DataType {
    dt_unknown,
    dt_none,
    dt_integer,
    dt_real,
    dt_string,
    dt_character,
    dt_boolean,
    dt_Void,
    dt_class,
    dt_class_obj
} DataType;


// Enum to represent the type of symbol table entry
typedef enum SymbolType {
    keyword,
    function,
    literal,
    identifier,
    Operator,
    classobj
    // Add more types as needed
}SymbolType;

typedef enum Token {
    tok_int,
    tok_double,
    tok_boolean,
    tok_char,
    tok_id,
    tok_float,
    tok_void,
    tok_string,
    tok_public,
    tok_private,
    tok_protected,
    tok_class,
    tok_static,
    tok_final,
    tok_if,
    tok_else,
    tok_while,
    tok_for,
    tok_return,
    tok_main,
    tok_args,
    tok_character,
    tok_number,
    tok_error,
    tok_inc,
    tok_dec,
    tok_semicolon,
    tok_comma,
    tok_lparen,
    tok_rparen,
    tok_lbrace,
    tok_rbrace,
    tok_plus,
    tok_minus,
    tok_times,
    tok_divide,
    tok_mod,
    tok_plusasg,
    tok_minusasg,
    tok_timesasg,
    tok_divideasg,
    tok_assign,
    tok_and,
    tok_or,
    tok_not,
    tok_dot,
    tok_lbracket,
    tok_rbracket,
    tok_eq,
    tok_ne,
    tok_lt,
    tok_gt,
    tok_le,
    tok_ge,
    tok_true,
    tok_false
}Token;

typedef enum AccessModifier {
    acm_public,
    acm_private,
    acm_protected
} AccessModifier;
typedef enum Modifier {
    md_static,
    md_final,
    md_constant
} Modifier;

typedef enum SemanticType{
    st_unknown, st_keyword, st_program,
    st_parameter, st_variable, st_tempvar,
    st_constant, st_method, st_member_second,
    st_method_call, st_member_list,st_array_access,
    st_pass_args, st_decl_id,st_decl_ids,st_member,
    st_class, st_literal, st_operator,st_class_list,
    st_for, st_while, st_if, st_else,
    st_return, st_main, st_args,
    st_stmt, st_block, st_expression,
    st_assignment, st_declaration,
    st_stmt_list, st_expr, st_log_expr,
    st_mem_access,st_types,st_dimension
}SemanticType;

typedef struct Method{
    int numArgs;
    enum DataType *argType;
    int *argDimen;
    enum DataType returnType;
}Method;

typedef struct Class{
    int numMembers;
    int *type;
    union Member *members;
}Class;

typedef union Member{
    Method *method;
    Class *class;
}Member;

// Symbol Table Entry structure
typedef struct SymbolTableEntry {
    char *lexeme;                    // Lexeme associated with the symbol
    enum SymbolType symbolType;    // Type of the symbol table entry
    enum Token token;
    enum DataType dataType; 
    enum SemanticType semanticType; 
    Member member;        // Data type of the symbol
    Value value;                     // Value of the symbol (using a union)
    int lineNo;  
    int dimen;   
    struct SymbolTableEntry *next;
    // Add any other relevant fields as needed
} SymbolTableEntry;

typedef struct SymbolTable{
    SymbolTableEntry *start;
    struct SymbolTable *innerScope;
    struct SymbolTable *nextScope;
    struct SymbolTable *outerScope;
}SymbolTable;

static inline void set_method_values(SymbolTableEntry *entry, int numArgs, enum DataType *argType, enum DataType returnType) {
    if (entry != NULL) {
        if (entry->semanticType == st_method) {
            entry->member.method->numArgs = numArgs;
            entry->member.method->returnType = returnType;
            
            // Allocate memory for the array of argument types
            entry->member.method->argType = (enum DataType *)malloc(numArgs * sizeof(enum DataType));
            if (entry->member.method->argType == NULL) {
                exit(EXIT_FAILURE);
            }
            
            // Copy the argument types
            for (int i = 0; i < numArgs; i++) {
                entry->member.method->argType[i] = argType[i];
            }
        }
    }
}



static inline struct SymbolTable *new_table(struct SymbolTable *parent) {


    // Allocate memory for the new table
    struct SymbolTable *table = malloc(sizeof(struct SymbolTable));
    table->start = NULL;
    table->innerScope = NULL;
    table->nextScope = NULL;
    table->outerScope = parent;
    if(!parent)return table;
    struct SymbolTable *current=parent->innerScope;
    if(current==NULL){
        parent->innerScope=table;
        return table;
    }
    int i=0;
    while(current->nextScope!=NULL){
        i++;
        current->nextScope=current->nextScope->nextScope;
    }
    current->nextScope=table;
    return table;
}

static inline struct SymbolTableEntry* new_entry(char *lexeme, int lineNo, SymbolType symbolType, Token token, DataType dataType, Value value) {
    SymbolTableEntry* entry = (SymbolTableEntry*)malloc(sizeof(SymbolTableEntry));
    if (entry == NULL) {
        exit(EXIT_FAILURE);
    }
    
    entry->lexeme = strdup(lexeme);
    entry->token = token;
    entry->dataType = dataType;
    entry->symbolType = symbolType;
    entry->semanticType = st_unknown;
    entry->dimen = 0;
    entry->lineNo = lineNo;
    entry->value = value;
    entry->next = NULL;

    return entry;
}

static inline struct SymbolTableEntry *lookup(struct SymbolTable *table, char *lexeme) {
    if(!table)return NULL;
    SymbolTableEntry *current = table->start;

    // Keep looking up the lexeme in the current table and its outer scopes
    while (current != NULL) {
            if (strcmp(current->lexeme, lexeme) == 0) {
                return current;
            }
            current = current->next;
    }
    // check in outer scope
    return lookup(table->outerScope,lexeme);
}

static inline struct SymbolTableEntry* add_entry(struct SymbolTable *table, char *lexeme, int lineNo, SymbolType symbolType, DataType dataType, Value value) {
    // The new entry will point to the current start of the list
    SymbolTableEntry *entry = lookup(table,lexeme);
    if(entry){
        return entry;
    }
    entry=new_entry(lexeme, lineNo, symbolType, tok_id,dataType, value);
    entry->next = table->start;
    table->start = entry;
    return table->start;
}

//Function to print symbol table
static inline void print_table(SymbolTable *table) {
    if (table == NULL) {
        return;
    }
    SymbolTableEntry *current = table->start;
    printf("Symbol Table\n");
    printf("Lexeme\t\tType\t\tData Type\tdimension\tValue\t\tLine No.\n");
    while (current != NULL) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t", current->lexeme, current->symbolType, current->dataType,current->dimen);
        
        // Switch statement to print the value based on the data type
        switch (current->dataType) {
            case dt_integer:
                printf("%d\t\t", current->value.val_int);
                break;
            case dt_real:
                printf("%f\t\t", current->value.val_float);
                break;
            case dt_string:
                printf("%s\t\t", current->value.val_string);
                break;
            default:
                printf("Unknown\t\t");
        }

        printf("%d\n", current->lineNo);
        current = current->next;
    }
    print_table(table->innerScope);
    print_table(table->nextScope);
}


static inline struct SymbolTableEntry* check_and_add(struct SymbolTable *table, char *lexeme, int lineNo, SymbolType symbolType, DataType dataType, Value value) {
    struct SymbolTableEntry *entry = lookup(table, lexeme);
    if (entry) {
        // printf("Error: Symbol '%s' already defined at line %d\n", lexeme, entry->lineNo);
        return entry;
    } else {
        // Entry does not exist, add it to the symbol table
        entry=add_entry(table, lexeme, lineNo, symbolType, dataType, value);
        //printf("Adding symbol '%s' to the symbol table\n", lexeme);
    }
    return entry;
}
static inline void set_data_type(SymbolTableEntry *entry, DataType dataType) {
    if (entry != NULL) {
        entry->dataType = dataType;
    }
}
static inline void set_dimension(SymbolTableEntry *entry, int dimen) {
    if (entry != NULL) {
        entry->dimen = dimen;
    }
}
static inline void set_value(SymbolTableEntry *entry, Value value) {
    if (entry != NULL) {
        entry->value = value;
    }
}
static inline void set_line_no(SymbolTableEntry *entry, int lineNo) {
    if (entry != NULL) {
        entry->lineNo = lineNo;
    }
}
static inline void set_symbol_type(SymbolTableEntry *entry, SymbolType symbolType) {
    if (entry != NULL) {
        entry->symbolType = symbolType;
    }
}
static inline void set_semantic_type(SymbolTableEntry *entry, enum SemanticType semanticType) {
    if (entry != NULL) {
        entry->semanticType = semanticType;
    }
}
static inline void store_keywords(SymbolTableEntry** reservedKeywords) {
    reservedKeywords[tok_boolean] = new_entry("boolean", 0, keyword, tok_boolean, dt_boolean, (Value){0});
    reservedKeywords[tok_char] = new_entry("char", 0, keyword, tok_char, dt_character, (Value){0});
    reservedKeywords[tok_class] = new_entry("class", 0, keyword, tok_class, dt_unknown, (Value){0});
    reservedKeywords[tok_double] = new_entry("double", 0, keyword, tok_double, dt_real, (Value){0});
    reservedKeywords[tok_else] = new_entry("else", 0, keyword, tok_else, dt_unknown, (Value){0});
    reservedKeywords[tok_false] = new_entry("false", 0, keyword, tok_false, dt_boolean, (Value){0});
    reservedKeywords[tok_float] = new_entry("float", 0, keyword, tok_float, dt_real, (Value){0});
    reservedKeywords[tok_for] = new_entry("for", 0, keyword, tok_for, dt_none, (Value){0});
    reservedKeywords[tok_if] = new_entry("if", 0, keyword, tok_if, dt_none, (Value){0});
    reservedKeywords[tok_int] = new_entry("int", 0, keyword, tok_int, dt_integer, (Value){0});
    reservedKeywords[tok_main] = new_entry("main", 0, keyword, tok_main, dt_none, (Value){0});
    reservedKeywords[tok_private] = new_entry("private", 0, keyword, tok_private, dt_none, (Value){0});
    reservedKeywords[tok_protected] = new_entry("protected", 0, keyword, tok_protected, dt_none, (Value){0});
    reservedKeywords[tok_public] = new_entry("public", 0, keyword, tok_public, dt_none, (Value){0});
    reservedKeywords[tok_return] = new_entry("return", 0, keyword, tok_return, dt_none, (Value){0});
    reservedKeywords[tok_static] = new_entry("static", 0, keyword, tok_static, dt_none, (Value){0});
    reservedKeywords[tok_string] = new_entry("String", 0, keyword, tok_string, dt_string, (Value){0});
    reservedKeywords[tok_true] = new_entry("true", 0, keyword, tok_true, dt_boolean, (Value){0});
    reservedKeywords[tok_void] = new_entry("void", 0, keyword, tok_void, dt_Void, (Value){0});
    reservedKeywords[tok_while] = new_entry("while", 0, keyword, tok_while, dt_none, (Value){0});

    reservedKeywords[tok_inc] = new_entry("++", 0, Operator, tok_inc, dt_none, (Value){0});
    reservedKeywords[tok_dec] = new_entry("--", 0, Operator, tok_dec, dt_none, (Value){0});
    reservedKeywords[tok_semicolon] = new_entry(";", 0, keyword, tok_semicolon, dt_none, (Value){0});
    reservedKeywords[tok_comma] = new_entry(",", 0, keyword, tok_comma, dt_none, (Value){0});
    reservedKeywords[tok_lparen] = new_entry("(", 0, keyword, tok_lparen, dt_none, (Value){0});
    reservedKeywords[tok_rparen] = new_entry(")", 0, keyword, tok_rparen, dt_none, (Value){0});
    reservedKeywords[tok_lbrace] = new_entry("{", 0, keyword, tok_lbrace, dt_none, (Value){0});
    reservedKeywords[tok_rbrace] = new_entry("}", 0, keyword, tok_rbrace, dt_none, (Value){0});
    reservedKeywords[tok_plus] = new_entry("+", 0, Operator, tok_plus, dt_none, (Value){0});
    reservedKeywords[tok_minus] = new_entry("-", 0, Operator, tok_minus, dt_none, (Value){0});
    reservedKeywords[tok_times] = new_entry("*", 0, Operator, tok_times, dt_none, (Value){0});
    reservedKeywords[tok_divide] = new_entry("/", 0, Operator, tok_divide, dt_none, (Value){0});
    reservedKeywords[tok_mod] = new_entry("%", 0, Operator, tok_mod, dt_none, (Value){0});
    reservedKeywords[tok_plusasg] = new_entry("+=", 0, Operator, tok_plusasg, dt_none, (Value){0});
    reservedKeywords[tok_minusasg] = new_entry("-=", 0, Operator, tok_minusasg, dt_none, (Value){0});
    reservedKeywords[tok_timesasg] = new_entry("*=", 0, Operator, tok_timesasg, dt_none, (Value){0});
    reservedKeywords[tok_divideasg] = new_entry("/=", 0, Operator, tok_divideasg, dt_none, (Value){0});
    reservedKeywords[tok_assign] = new_entry("=", 0, Operator, tok_assign, dt_none, (Value){0});
    reservedKeywords[tok_and] = new_entry("&&", 0, Operator, tok_and, dt_none, (Value){0});
    reservedKeywords[tok_or] = new_entry("||", 0, Operator, tok_or, dt_none, (Value){0});
    reservedKeywords[tok_not] = new_entry("!", 0, Operator, tok_not, dt_none, (Value){0});
    reservedKeywords[tok_dot] = new_entry(".", 0, Operator, tok_dot, dt_none, (Value){0});
    reservedKeywords[tok_lbracket] = new_entry("[", 0, keyword, tok_lbracket, dt_none, (Value){0});
    reservedKeywords[tok_rbracket] = new_entry("]", 0, keyword, tok_rbracket, dt_none, (Value){0});
    reservedKeywords[tok_eq] = new_entry("==", 0, Operator, tok_eq, dt_none, (Value){0});
    reservedKeywords[tok_ne] = new_entry("!=", 0, Operator, tok_ne, dt_none, (Value){0});
    reservedKeywords[tok_lt] = new_entry("<", 0, Operator, tok_lt, dt_none, (Value){0});
    reservedKeywords[tok_gt] = new_entry(">", 0, Operator, tok_gt, dt_none, (Value){0});
    reservedKeywords[tok_le] = new_entry("<=", 0, Operator, tok_le, dt_none, (Value){0});
    reservedKeywords[tok_ge] = new_entry(">=", 0, Operator, tok_ge, dt_none, (Value){0});
    reservedKeywords[tok_semicolon] = new_entry(";", 0, keyword, tok_semicolon, dt_none, (Value){0});
    reservedKeywords[tok_dot] = new_entry(".", 0, keyword, tok_dot, dt_none, (Value){0});

}
//Function to set member values for entry
static inline void set_member_values(SymbolTableEntry *entry, int numMembers, int *type, Member *members) {
    if (entry != NULL) {
        if (entry->semanticType == st_class) {
            entry->member.class->numMembers = numMembers;
            entry->member.class->members = members;
            entry->member.class->type = type;
        }
    }
}
//Function to check if the entry data type is already defined and setting if not defined other wise return 0 and print an error line number stating redeclaration
static inline int check_and_set_dType(SymbolTableEntry *entry,DataType dtype){
    if(entry->dataType==dt_unknown){
        entry->dataType=dtype;
        return 1;
    }
    else{
        printf(COLOR_RED "Error" COLOR_RESET": Redefinition of %s at line %d\n",entry->lexeme,entry->lineNo);
        return 0;
    }
}
static inline struct SymbolTableEntry* store_literals(SymbolTable *table, char *lexeme, int lineNo, DataType dataType, Value value) {
    SymbolTableEntry *entry = lookup(table, lexeme);
    if (entry) {
        return entry;
        
    } else {
        // Entry does not exist, create a new one
       // printf("Adding literal '%s %d' to the symbol table\n", lexeme,dataType);
        return  add_entry(table, lexeme, lineNo, literal, dataType, value);
    }
    return entry;
}
//fun to check isdefined
static inline int is_defined(SymbolTableEntry *entry){
    if(entry->dataType==dt_unknown){
        printf(COLOR_RED"Error: "COLOR_RESET "Line %d: %s is undeclared\n",entry->lineNo,entry->lexeme);
        return 0;
    }
    return 1;
}
//fun to check is_method
static inline int is_method(SymbolTableEntry *entry){
    if(entry->semanticType!=st_method){
        printf(COLOR_RED"Error: "COLOR_RESET "Line %d: %s is not a method\n",entry->lineNo,entry->lexeme);
        return 0;
    }
    return 1;
}
//fun to check is_class
static inline int is_class(SymbolTableEntry *entry){
    if(entry->semanticType!=st_class){
        printf(COLOR_RED"Error: "COLOR_RESET "Line %d: %s is not a class\n",entry->lineNo,entry->lexeme);
        return 0;
    }
    return 1;
}
//fun to check dimension
static inline int check_dimension(SymbolTableEntry *entry,int dimen,int lineNo){
    if(entry->dimen!=dimen){
        printf(COLOR_RED"Error: "COLOR_RESET "Line %d: %s is not a %d dimensional array\n",lineNo,entry->lexeme,dimen);
        return 0;
    }
    return 1;
}
//fun to check array access like when dimen is less than initialized dimension
static inline int check_array_access(SymbolTableEntry *entry,int dimen,int lineNo){
    if(entry->dimen<dimen){
        printf(COLOR_RED"Error: "COLOR_RESET "Line %d: %s is not a %d dimensional array\n",lineNo,entry->lexeme,dimen);
        printf(COLOR_RED"Error: "COLOR_RESET "expected %d dimension but %d found\n",entry->dimen,dimen);
        return 0;
    }
    return 1;
}
//fun to delete entry means unlinking that node from that table
static inline void delete_entry(SymbolTable *table,SymbolTableEntry *entry){
    SymbolTableEntry *current=table->start;
    SymbolTableEntry *prev=NULL;
    while(current!=NULL){
        if(strcmp(current->lexeme,entry->lexeme)==0){
            
            if(prev==NULL){
                table->start=current->next;
            }else{
                prev->next=current->next;
            }
            current->next=NULL;
            return;
        }
        prev=current;
        current=current->next;
    }
    return;
}

//fun to insert entry in the table
static inline void insert_entry(SymbolTable *table,SymbolTableEntry *entry){
    entry->next=table->start;
    table->start=entry;
}
//ScopeStack
typedef struct ScopeStack {
    struct SymbolTable *top;
} ScopeStack;
static inline void push_scope(ScopeStack *stack, struct SymbolTable *table) {
    //printf("Pushing scope\n");
    table->outerScope = stack->top;
    stack->top = table;
}
static inline struct SymbolTable *pop_scope(ScopeStack *stack) {
    struct SymbolTable *table = stack->top;
    if(table==NULL){
        //printf("Error: No scope to pop\n");
        return NULL;
    }
    stack->top = table->outerScope;

    return table;
}
static inline struct SymbolTable *peek_scope(ScopeStack *stack) {
    return stack->top;
}


#endif 
