#ifndef CODE_H
#define CODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ThreeAddressCode{
    char* result;
    char* operation;
    char* operand1;
    char* operand2;
} ThreeAddressCode;
typedef struct List{
    int current;
    struct List* next;
} List;


static inline ThreeAddressCode* newThreeAddressCode(char* result, char* operation, char* operand1, char* operand2){
    ThreeAddressCode* code = (struct ThreeAddressCode*)malloc(sizeof(ThreeAddressCode));
    code->result=(char*)malloc(strlen(result));
    strcpy(code->result,result);
    code->operation=(char*)malloc(strlen(operation));
    strcpy(code->operation,operation);
    code->operand1=(char*)malloc(strlen(operand1));
    strcpy(code->operand1,operand1);
    code->operand2=(char*)malloc(strlen(operand2));
    strcpy(code->operand2,operand2);
    return code;
}
// Function to create a new List
static inline List* newList(int i){
    List* list = (struct List*)malloc(sizeof(List));
    list->current=i;
    list->next=NULL;
    return list;
}


// merge two lists and return the merged list
static inline List* mergeLists(List* list1, List* list2){
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    struct List* newList=(struct List*)malloc(sizeof(List));
    newList->current=list1->current;
    newList->next=mergeLists(list1->next,list2);
    return newList;
}

 
#endif