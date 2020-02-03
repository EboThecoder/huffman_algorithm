#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "rbt.h"
#include "../huffman/code/tree.h"

int main()
{
    bst *bt = create_empty_by_tree();
    bt = insert(bt, 1);
    bt = insert(bt, 2);
    bt = insert(bt, 3);
    bt = insert(bt, 4);
    bt = insert(bt, 5);
    bt = insert(bt, 6);
    bt = insert(bt, 7);
    bt = insert(bt, 8);
    printf("   (");
    print_pre_order(bt);
    printf(") \n");
    printf("\n\n");
    bt = remove_node(bt, 1);
    printf("   (");
    print_pre_order(bt);
    printf(") \n");
}