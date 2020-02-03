#ifndef rbt_h
#define rbt_h

// Implementing Red-Black Tree in C
#include <stdio.h>
#include <stdlib.h>

enum nodeColor
{
    RED,
    BLACK
};
struct rbNode
{
    unsigned long data, color;
    struct rbNode *link[2];
};
struct rbNode *root;

unsigned long *rbt_counter;

struct rbNode *createNode(unsigned long data);

void insertion(unsigned long data);

void deletion(unsigned long data);

void inorderTraversal(struct rbNode *node);

struct rbNode *rbt_search(struct rbNode *node, unsigned long data);

void reset_rbt(struct rbNode *rbt);

#endif