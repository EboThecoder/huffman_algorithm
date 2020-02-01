#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct by_tree
{
	int item;
	struct by_tree* left;
	struct by_tree* right;
} by_tree;

by_tree* create_empty_by_tree()
{
	return NULL;
}

by_tree* create_by_tree(int item, by_tree* left, by_tree* right)
{
	by_tree* new_by_tree = (by_tree*) malloc(sizeof(by_tree));
	new_by_tree->item = item;
	new_by_tree->left = left;
	new_by_tree->right = right;
	return new_by_tree;
}

by_tree* by_search(by_tree* bt, int item)
{
	if(bt->item == item || bt== NULL) return bt;
	else if(bt->item < item)
	{
		return by_search(bt->right, item);
	}
	else 
	{
		return by_search(bt->left, item);	
	}
}

by_tree* insert(by_tree* bt, int item)
{
	if(bt == NULL) bt= create_by_tree(item , NULL, NULL);
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

int node_degree(by_tree* bt)
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

by_tree* remove_node(by_tree* bt, int item)
{
	if(bt == NULL) return bt;
	if(bt->item > item) bt->left= remove_node(bt->left, item);
	else if(bt->item < item) bt->right= remove_node(bt->right, item);
	else
	{
		if(node_degree(bt)==0)
		{
			by_tree* aux = bt;
			bt= NULL;
			free(aux);
		}
		else if(node_degree(bt)==1)
		{
			by_tree* aux= bt;
			if(bt->left == NULL) bt= bt->right;
			else bt= bt->left;
			free(aux);
		}
		else
		{
			by_tree* left_side= bt->left;
			while(left_side->right!=NULL) left_side= left_side->right;
			bt->item = left_side->item;
			left_side= remove_node(left_side, item);
		}
		return bt;	
	}
	
}

void print_pre_order(by_tree* bt)
{	
	if(bt!=NULL)
	{
		printf("%d(", bt->item);
		print_pre_order(bt->left);
		printf(")(");
		print_pre_order(bt->right);
		printf(")");
	}
}


void print_in_order(by_tree* bt)
{	
	if(bt!=NULL)
	{
		print_in_order(bt->left);
		printf("%d ", bt->item);
		print_in_order(bt->right);
	}
}

int main()
{
	by_tree* bt= create_empty_by_tree();
	bt= insert(bt, 1);
	bt= insert(bt, 2);
	bt= insert(bt, 3);
	bt= insert(bt, 4);
	bt= insert(bt, 5);
	bt= insert(bt, 6);
	bt= insert(bt, 7);
	bt= insert(bt, 8);
	printf("   (");
	print_pre_order(bt);
	printf(") \n");
	printf("\n\n");
	bt= remove_node(bt, 1);
	printf("   (");
	print_pre_order(bt);
	printf(") \n");
}