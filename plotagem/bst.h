#ifndef bst_h
#define bst_h

typedef struct bst
{
    unsigned long item;
    struct bst *left;
    struct bst *right;
} bst;

bst *bst_root;

unsigned long *bst_counter;

bst *create_empty_by_tree();

bst *create_by_tree(unsigned long item, bst *left, bst *right);

bst *bst_search(bst *bt, unsigned long item);

bst *insert(bst *bt, unsigned long item);

unsigned long node_degree(bst *bt);

bst *remove_node(bst *bt, unsigned long item);


void print_pre_order(bst *bt);

void reset_bst(bst *bt);

void print_in_order(bst *bt);

#endif