#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "rbt2.h"
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
        //printf("1\n");
        redBlackInsert(&Root, g);
        //printf("2\n");
    }
    //printf("q\n");
    bst* s_bst = bst_search(bst_root, g);
    //print_pre_order(bst_root);
    
    Node *s_rbt = rbt2_search(Root, g);
    
}

int main()
{
    bst_root = NULL;
    T_Nil = &T_Nil_Node;
    Root = T_Nil;

    bst_counter = allocate_counter();
    rbt_counter = allocate_counter();
    FILE* fp = fopen("plot_points2.txt", "w");
    for(unsigned long i = 1; i<=100000; i+=2500)
    {
        inserir(i);
        fprintf(fp, "%ld;%ld;%ld\n", i, *bst_counter, *rbt_counter);
        *bst_counter = 0;
        *rbt_counter = 0;
        reset_bst(bst_root);
        reset_rbt2(Root);
        bst_root = NULL;
        Root = T_Nil;
    }
}