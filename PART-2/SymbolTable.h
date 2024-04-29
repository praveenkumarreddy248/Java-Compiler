#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


// Union to store different types of values in the symbol table entry
typedef union {
    int int_val;
    float float_val;
    char *string_val;
    // Add more types as needed
} Value;

// Enum to represent the data type of a symbol
typedef enum datatype {
    integer,
    real,
    string,
    unknown,
    class_obj
    // Add more types as needed
}datatype;

// Enum to represent the type of symbol table entry
typedef enum entry_type {
    keyword,
    function,
    character,
    literal,
    identifier,
    Operator,
    classobj
    // Add more types as needed
}entry_type;

typedef struct fun_args{
    int num_args;
    enum datatype **argtype;
}fun_args;

// Symbol Table Entry structure
typedef struct SymbolTableEntry {
    char *lexeme; // Lexeme associated with the symbol
    enum entry_type entry_type; // Type of the symbol table entry
    enum datatype datatype; // Data type of the symbol
    Value value;  // Value of the symbol (using a union)
    int lineno;   // Line number where the symbol was encountered
    int scope;
    struct fun_args *args;
    struct SymbolTableEntry *next;
    // Add any other relevant fields as needed
} SymbolTableEntry;

static inline void add_entry(SymbolTableEntry **head, const char *lexeme, enum entry_type type, enum datatype dtype, int lineno) {
    // Create a new symbol table entry
    SymbolTableEntry *new_entry = (SymbolTableEntry*)malloc(sizeof(SymbolTableEntry));
    if (new_entry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_entry->lexeme = (char*) malloc(strlen(lexeme)+1); 
    strcpy(new_entry->lexeme,lexeme);
    new_entry->lexeme[strlen(lexeme)]='\0';
    new_entry->entry_type = type;
    new_entry->datatype = dtype;
    new_entry->lineno = lineno;
    
    // Insert the new entry at the beginning of the linked list
    new_entry->next = *head;
    *head = new_entry;
}
static inline int cmp(char * a, char *b){
   
    if(strlen(a)!=strlen(b))return 0;
    for(int i=0;a[i];i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;
}
static inline SymbolTableEntry *lookup(SymbolTableEntry* start, char *lexeme) {
        
        // printf("lexeme-%ld\n",strlen(lexeme));
    SymbolTableEntry *current = start;
    while (current != NULL) {
        if (cmp(current->lexeme, lexeme)) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Entry not found
}
static inline void print_symbolTable(SymbolTableEntry *head) {
    if(!head)return;
    print_symbolTable(head->next);
    SymbolTableEntry *current = head;

    printf("| %-18s | %-11d | %-11d | %-11d | %-6d |\n", current->lexeme, current->entry_type, current->datatype, current->lineno, current->scope);
    current = current->next;
}

#endif 
