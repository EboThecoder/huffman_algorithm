#ifndef rbt2_h
#define rbt2_h

#include<stdio.h>
#include<stdlib.h>

#define RED   'R'
#define BLACK 'B'


typedef struct Node {
    unsigned long key;
    char color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Based on CLRS algorithm, use T_Nil as a sentinel to simplify code
struct Node  T_Nil_Node;
Node* T_Nil;
Node* Root;
unsigned long *rbt_counter;

// A utility function to create a new BST node
Node* newNode(unsigned long key);


void rotateLeft( Node** T, Node* x);


void rotateRight(Node** T, Node* y);


void redBlackInsertFixup(Node** Root, Node* New);

void redBlackInsert(Node** T, unsigned long key);

#define MAX(a,b) (((a)>(b))?(a):(b))

unsigned long height(Node* Root);

void printTree(Node* root);

void reset_rbt2(Node *rbt);

Node * rbt2_search(Node *node, unsigned long key);


#endif