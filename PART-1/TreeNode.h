#ifndef TREENODE_H
#define TREENODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Enum to represent the type of a tree node
enum treetype {
    terminal,
    non_terminal
};

// Tree node structure
typedef struct TreeNode {
    char *str; // Data associated with the node
    char *name; // Name of the node
    enum treetype nodetype; // Type of the node
    int num_children; // Number of children nodes
    struct TreeNode **children; // Array of pointers to children nodes
} TreeNode;

// Function prototypes
TreeNode *create_tree_node(char *name, int num_children, ...);
TreeNode *create_node(char* name);
void inorder_traversal(TreeNode *root);
void free_tree(TreeNode *root);
void bfs(TreeNode *root);
    
#endif /* TREENODE_H */
