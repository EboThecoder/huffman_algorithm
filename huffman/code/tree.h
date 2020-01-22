#ifndef tree_h
#define tree_h

#include <stdio.h>
/**
 * @brief 
 * 
 */
typedef struct node
{
    void *item;
    int frequency;
    struct node *left;
    struct node *right;
} node;
/**
 * @brief Create a node object
 * 
 * @return node* 
 */

node *create_node();
/**
 * @brief Create a tree object
 * 
 * @param item 
 * @param left 
 * @param right 
 * @return node* 
 */

node *create_tree(void *item, node *left, node *right);
/**
 * @brief 
 * 
 * @param tree 
 */

void print_tree(node *tree);
/**
 * @brief 
 * 
 * @param tree 
 * @param compacted_file 
 */
void save_tree(node *tree, FILE *compacted_file);
/**
 * @brief 
 * 
 * @return unsigned short* 
 */
unsigned short *allocate_counter();
/**
 * @brief 
 * 
 * @param tree 
 */
void deallocate_tree(node *tree);
/**
 * @brief 
 * 
 */

#endif