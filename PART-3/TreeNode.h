#ifndef TREENODE_H
#define TREENODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "SymbolTable.h"

typedef enum NodeType{
    terminal,
    nonterminal
}NodeType;
typedef struct TreeNode {
    char *name;
    enum DataType dataType;
    enum SemanticType stype;
    union Value value;
    int dimen;
    NodeType type;
    int num_children;
    struct SymbolTableEntry *entry;
    struct TreeNode **children;
} TreeNode;

/*void setType(TreeNode*, enum datatype dtype);
int checkType(TreeNode*,TreeNode*);
int checkdType(TreeNode*,enum datatype);
int isdefined(TreeNode*);*/

// Function to create a tree node
static inline struct TreeNode *create_tree_node( char *name, enum SemanticType stype, int num_children, ...) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->name = (char*)malloc(strlen(name)+1); // Allocate memory for the name string
    strcpy(node->name, name); // Copy the name string
    node->name[strlen(name)]='\0';
    node->num_children = num_children;
    node->stype=stype;
    node->type=nonterminal;
    node->dataType=dt_unknown;
    if (num_children < 1)
        return node;

    va_list args;
    va_start(args, num_children);

    // Allocate memory for children array
    node->children = (struct TreeNode**)malloc(num_children * sizeof(struct TreeNode*));
    for (int i = 0; i < num_children; ++i) {
        // Retrieve each child from variable arguments
        node->children[i] = va_arg(args, struct TreeNode *);
        if(!node->children[i]){
            node->children[i]=NULL;
            node->num_children--;
            i--;
        }
    }
    va_end(args);
    // printf("\n");
    return node;
}

// Function to add children to a tree node
static inline void add_children(struct TreeNode *node, int num_children, ...) {
    if (num_children < 1)
        return;

    va_list args;
    va_start(args, num_children);

    // Reallocate memory for children array
    node->children = (struct TreeNode**)realloc(node->children, (node->num_children + num_children) * sizeof(struct TreeNode*));
    for (int i = 0; i < num_children; ++i) {
        // Retrieve each child from variable arguments
        node->children[node->num_children + i] = va_arg(args, struct TreeNode *);
    }
    node->num_children += num_children;
    va_end(args);
}
static inline void inorder_traversal(struct TreeNode *root,int depth) {
    if (root == NULL) {
        return;
    }
    // Print indentation based on depth
    for (int i = 0; i < 2*depth; ++i) {
        printf("  ");
    }
        if(root->name){
        if(depth>0)
        printf("|--%s\n", root->name);
        else printf("%s\n",root->name);
        }
    // Visit children nodes
    for (int i = 0; i < root->num_children; ++i) {
        inorder_traversal(root->children[i], depth + 1);
    }
}

// Function to copy SymbolTableEntry to TreeNode
static inline struct TreeNode* copy_entry_to_node( struct SymbolTableEntry *entry) {
    if ( entry == NULL) {
        return NULL;
    }
    struct TreeNode *node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->name=entry->lexeme;
    node->dataType=entry->dataType;
    node->stype=entry->semanticType;
    node->value=entry->value;
    node->type=terminal;
    node->entry = entry;
    return node;
}

static inline void set_member_method_values(SymbolTable *symbolTable,SymbolTableEntry *entry,DataType returnType, struct TreeNode *arg_list){
    if(entry!=NULL){
            entry->semanticType=st_method;
            entry->member.method=(Method*)malloc(sizeof(Method));
            entry->member.method->returnType=returnType;
            entry->member.method->numArgs=arg_list->num_children;
            entry->member.method->argType=(enum DataType*)malloc(arg_list->num_children*sizeof(enum DataType));
            entry->member.method->argDimen=(int*)malloc(arg_list->num_children*sizeof(int));
            for(int i=0;i<arg_list->num_children;i++){
                entry->member.method->argType[i]=arg_list->children[i]->dataType;
                entry->member.method->argDimen[i]=arg_list->children[i]->dimen;
                if(arg_list->children[i]->num_children==2){
                    struct SymbolTableEntry *arg=arg_list->children[i]->children[1]->entry;
                    //printf("--------------->deleting %d\n",arg->dataType);
                    delete_entry(symbolTable->outerScope,arg);
                    insert_entry(symbolTable,arg);
                }
            }
    }           
}
//fun to check method arguments and return type return 0 on successful 1 on return type mismatch 2 on argument mismatch
static inline int check_method_args(SymbolTableEntry *entry,struct TreeNode* pass_args, int lineNo){
    if(entry!=NULL){
        int flag=0;
        if(entry->semanticType==st_method){
            if(pass_args->num_children!=entry->member.method->numArgs){
                printf(COLOR_RED"Error: "COLOR_RESET "Line %d: Insufficient Arguments \n",lineNo);
                return 1;
            }else {
                
                for(int i=0;i<pass_args->num_children;i++){
                    if(pass_args->children[i]->dataType!=entry->member.method->argType[i] || pass_args->children[i]->dimen!=entry->member.method->argDimen[i]){
                        printf(COLOR_RED"Error: "COLOR_RESET "Line %d: Argument %d type not matched\n",lineNo,i+1);
                        flag=1;
                    }
                }
            }
        }
        if(!flag)return 0;
    }
    return 0;
}
static inline void setDimension(struct TreeNode *node,int dimen){
    node->dimen=dimen;
}
//fun to set dataType and dimension
static inline void setDataType(struct TreeNode *node,enum DataType dtype){
    node->dataType=dtype;
}
static inline int checkType(struct TreeNode *node1,struct TreeNode *node2,int lineNo){
    if(!node1 || !node2)
        return 0;
    if(node1->dataType==node2->dataType){
        if(node1->dimen!=node2->dimen){
            printf(COLOR_RED"Error"COLOR_RESET "Line %d: Dimension mismatch\n",lineNo);
            return 0;
        }

        return 1;
    }
    printf(COLOR_RED"Error"COLOR_RESET "Line %d: Type mismatch%s\t,%s\n",lineNo,node1->name,node2->name);
    return 0;
}
//check node with given datatype and dimension
static inline int checkdType(struct TreeNode *node,enum DataType dtype,int dimen,int lineNo){
    if(!node)
        return 0;
    if(node->dataType==dtype){
        if(node->dimen!=dimen){
            printf(COLOR_RED"Error"COLOR_RESET "Line %d: Dimension mismatch\n",lineNo);
            return 0;
        }

        return 1;
    }
    printf(COLOR_RED"Error"COLOR_RESET "Line %d: Type mismatch\n",lineNo);
    return 0;
}

// Function to recursively free all nodes in the tree
static inline void free_tree_helper(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    // Free children nodes first
    for (int i = 0; i < root->num_children; ++i) {
        if(root->children[i])
        free_tree_helper(root->children[i]);
    }

    // Free node's name
    if(root->name)
    free(root->name);

    // Free node itself
    free(root);
}

// Function to free the entire tree
static inline void free_tree(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    // Start recursive freeing from the root
    free_tree_helper(root);
}
  
#endif /* TREENODE_H */
