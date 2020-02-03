#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "rbt.h"
#include "../huffman/code/tree.h"



void inserir( unsigned long n)
{
    srand(time(NULL));
    unsigned long g;
    for(int i=0; i<n; i++)
    {
        g = rand() % n;
        //printf("random %ld\n", g);
        
        bst_root = insert(bst_root, g);
        insertion(g);
    }
    bst* s_bst = bst_search(bst_root, g);
    //print_pre_order(bst_root);
    //printf("s1\n");
    struct rbNode *s_rbt = rbt_search(root, g);
    //printf("s2\n");
}

int main()
{
    bst_root = NULL;
    root = NULL;
    bst_counter = allocate_counter();
    rbt_counter = allocate_counter();
    FILE* fp = fopen("plot_points.txt", "w");
    for(unsigned long i = 1; i<=1000000; i+=2500)
    {
        inserir(i);
        fprintf(fp, "%ld;%ld;%ld\n", i, *bst_counter, *rbt_counter);
        *bst_counter = 0;
        *rbt_counter = 0;
        reset_bst(bst_root);
        reset_rbt(root);
        bst_root = NULL;
        root = NULL;
    }
}