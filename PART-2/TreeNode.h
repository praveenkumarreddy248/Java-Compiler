#ifndef TREENODE_H
#define TREENODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "SymbolTable.h"

// Enum to represent the type of a tree node
enum treetype {
    terminal,
    non_terminal
};

// Tree node structure
typedef struct TreeNode {
    char *name; // Name of the node
    struct SymbolTableEntry *this;
    enum treetype nodetype; // Type of the node
    int num_children; // Number of children nodes
    struct TreeNode **children; // Array of pointers to children nodes
} TreeNode;
typedef struct QueueNode {
    struct TreeNode *data;
    struct QueueNode *next;
} QueueNode;

// Function prototypes
// Define the structure of a queue
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function to create an empty queue
static inline Queue* createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
static inline int isEmpty(Queue *queue) {
    return (queue->front == NULL);
}

// Function to enqueue a node to the queue
static inline void enqueue(Queue *queue, TreeNode *node) {
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
static inline TreeNode* dequeue(Queue *queue) {
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
    if(temp)
    free(temp);
    return data;
}

// Function to perform breadth-first search
static inline void bfs(TreeNode *root) {
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
                if(current)
                printf("%d. %s\t", r, current->name);
                r++;
            

            // Enqueue all children of the dequeued node
            for (int i = 0; i < current->num_children; ++i) {
                
                if(current->children[i]){
                    w++;
                    enqueue(queue, current->children[i]);
                }
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
static inline struct TreeNode *create_tree_node(char *name, int num_children, ...) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->name = (char*)malloc(strlen(name)+1); // Allocate memory for the name string
    strcpy(node->name, name); // Copy the name string
    node->name[strlen(name)]='\0';
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

static inline struct TreeNode *create_node(struct SymbolTableEntry **head, char *name, enum entry_type type, enum datatype dtype,int lineno ) {
    //  printf("leaf %s  ",name);
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode*));
    node->num_children = 0;
    node->nodetype=terminal;
    node->name=(char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(node->name,name);
    node->name[strlen(name)]='\0';
    node->children=NULL;
    struct SymbolTableEntry *new_entry=lookup(*head,name);
    // add_entry(head,name,type,dtype,lineno);
    if(new_entry==NULL){
        add_entry(head,node->name,type,dtype,lineno);
        node->this=*head;
    }
    else node->this=new_entry;
     printf("leaf %s\n",node->name);
    // if(node)printf("%d ok\n",node->nodetype);
    return node;
}
static inline void inorder_traversal(struct TreeNode *root,int depth) {
    if (root == NULL) {
        return;
    }

    // Print indentation based on depth
    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }

    // Print current node
    if(depth>0)
    printf("|--%s\n", root->name);
    else printf("%s\n",root->name);

    // Visit children nodes
    for (int i = 0; i < root->num_children; ++i) {
        inorder_traversal(root->children[i], depth + 1);
    }
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
static inline void print_table(SymbolTableEntry * head){

    printf("Symbol Table:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| Lexeme            | Entry Type  | Data Type   | Line Number | Scope |\n");
    printf("-----------------------------------------------------------------------------\n");
    print_symbolTable(head);
    printf("-----------------------------------------------------------------------------\n");
}
    
#endif /* TREENODE_H */
