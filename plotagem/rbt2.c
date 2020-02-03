#include <stdio.h>
#include <stdlib.h>
#include "rbt2.h"

#define RED   'R'
#define BLACK 'B'




// A utility function to create a new BST node
Node* newNode(unsigned long key)
{
    Node *temp   = (Node*) malloc(sizeof(Node));
    temp->key    = key;
    temp->color  = RED;
    temp->left   = NULL;
    temp->right  = NULL;
    temp->parent = NULL;

    return temp;
}

void rotateLeft( Node** T, Node* x)
{
    Node *y  = x->right;    // set y
    x->right = y->left;     // turn y's left subtree into x's right subtree{
    if (y->left != T_Nil)
        y->left->parent = x;
    y->parent = x->parent;  // link x's parent to y
    if (x->parent == T_Nil)
        *T = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left   = x;            // put x on y's left
    x->parent = y;
}

void rotateRight(Node** T, Node* y)
{
    Node *x  = y->left;     // set x
    y->left  = x->right;    // turn x's right subtree into y's left subtree{
    if (x->right != T_Nil)
        x->right->parent = y;
    x->parent = y->parent;  // link y's parent to x
    if (y->parent == T_Nil)
        *T = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left  = x;
    x->right  = y;         // put y on x's right
    y->parent = x;
}

void redBlackInsertFixup(Node** Root, Node* New)
{
    Node* temp;
    while (New->parent->color == RED)
    {
        if (New->parent == New->parent->parent->left)
        {
            temp = New->parent->parent->right;
            if (temp->color == RED)
            {
                New->parent->color = BLACK;
                temp->color = BLACK;
                New->parent->parent->color = RED;
                New = New->parent->parent;
            }
            else {
                if (New == New->parent->right)
                {
                    New = New->parent;
                    rotateLeft(Root, New);
                }
                New->parent->color = BLACK;
                New->parent->parent->color = RED;
                rotateRight(Root, New->parent->parent);
            }
        }
        else
        {
            temp = New->parent->parent->left;
            if (temp->color == RED)
            {
                New->parent->color = BLACK;
                New->color = BLACK;
                New->parent->parent->color = RED;
                New = New->parent->parent;
            }
            else {
                if (New == New->parent->left)
                {
                    New = New->parent;
                    rotateRight(Root, New);
                }
                New->parent->color = BLACK;
                New->parent->parent->color = RED;
                rotateLeft(Root, New->parent->parent);
            }
        }
    }
    Root[0]->color = BLACK;
}
void redBlackInsert(Node** T, unsigned long key)
{
    Node* z =  newNode(key);
    Node* y =  T_Nil;
    Node* x = *T;

    // Find where to Insert new node Z into the binary search tree
    while (x != T_Nil) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == T_Nil)
        *T = z;
    else if (z->key < y->key)
        y->left  = z;
    else
        y->right = z;

    // Init z as a red leaf
    z->left  = T_Nil;
    z->right = T_Nil;
    z->color = RED;

    // Ensure the Red-Black property is maintained
    redBlackInsertFixup(T, z);
}

#define MAX(a,b) (((a)>(b))?(a):(b))

unsigned long height(Node* Root)
{
    unsigned long h = 0;

    if (Root != NULL) {
        if (Root == T_Nil)
            h = 1;
        else
        {
            unsigned long leftHeight  = height(Root->left);
            unsigned long rightHeight = height(Root->right);
            h = MAX(leftHeight, rightHeight) + 1;
        }
    }

    return h;
}


void printTree(Node* root)
{
    if (root->left != T_Nil)
        printTree(root->left);
    printf("%ld ", root->key);
    if (root->right != T_Nil)
        printTree(root->right);
}

void reset_rbt2(Node *rbt)
{
    if (rbt != T_Nil)
    {
        reset_rbt2(rbt->left);
        reset_rbt2(rbt->right);
        free(rbt);
    }
}

Node * rbt2_search(Node *node, unsigned long key)
{
    *rbt_counter+=1;
    if (node == NULL || node->key == key)
    {
        return node;
    }
    else if (node->key > key)
    {
        return rbt2_search(node->left, key);
    }
    else
    {
        return rbt2_search(node->right, key);
    }
}