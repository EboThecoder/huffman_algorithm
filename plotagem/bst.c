#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "../huffman/code/tree.h"


bst* create_empty_by_tree()
{
	return NULL;
}

bst* create_by_tree(unsigned long item, bst* left, bst* right)
{
	bst* new_by_tree = (bst*) malloc(sizeof(bst));
	new_by_tree->item = item;
	new_by_tree->left = left;
	new_by_tree->right = right;
	return new_by_tree;
}

bst* bst_search(bst* bt, unsigned long item)
{
	*bst_counter += 1;
	if (bt == NULL || bt->item == item) return bt;
	else if(bt->item < item)
	{
		return bst_search(bt->right, item);
	}
	else 
	{
		return bst_search(bt->left, item);	
	}
}

bst* insert(bst* bt, unsigned long item)
{
	if(bt == NULL)
	{
		bt= create_by_tree(item , NULL, NULL);
		return bt;	
	}
	else if(bt->item <= item)
	{
		bt->right = insert(bt->right, item);
	}
	else 
	{
		bt->left = insert(bt->left, item);	
	}
	return bt;
}

unsigned long node_degree(bst* bt)
{
	if(bt->left == NULL)
	{
		if(bt->right == NULL)
		{
			return 0;
		}
		return 1;
	}
	if(bt->right == NULL) return 1;
	return 2;
}

bst* remove_node(bst* bt, unsigned long item)
{
	if(bt == NULL) return bt;
	if(bt->item > item) bt->left= remove_node(bt->left, item);
	else if(bt->item < item) bt->right= remove_node(bt->right, item);
	else
	{
		if(node_degree(bt)==0)
		{
			bst* aux = bt;
			bt= NULL;
			free(aux);
		}
		else if(node_degree(bt)==1)
		{
			bst* aux= bt;
			if(bt->left == NULL) bt= bt->right;
			else bt= bt->left;
			free(aux);
		}
		else
		{
			bst* left_side= bt->left;
			while(left_side->right!=NULL) left_side= left_side->right;
			bt->item = left_side->item;
			left_side= remove_node(left_side, item);
		}
		return bt;	
	}
	
}

void print_pre_order(bst* bt)
{	
	if(bt!=NULL)
	{
		printf("%ld(", bt->item);
		print_pre_order(bt->left);
		printf(")(");
		print_pre_order(bt->right);
		printf(")");
	}
}

void reset_bst(bst *bt)
{
	if (bt != NULL)
	{
		reset_bst(bt->left);
		reset_bst(bt->right);
		free(bt);
	}
}

void print_in_order(bst* bt)
{	
	if(bt!=NULL)
	{
		print_in_order(bt->left);
		printf("%ld ", bt->item);
		print_in_order(bt->right);
	}
}


/*int main()
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
}*/