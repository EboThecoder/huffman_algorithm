#ifndef heap_h
#define heap_h

#include "tree.h"

#include <stdlib.h>
#include <limits.h>

/**
 * @brief
 * 
 */
typedef struct heap
{
    int size; 
    node *nodes[256];
} heap;
/**
 * @brief Create a heap object
 * 
 * @return heap* 
 */
heap *create_heap();
/**
 * @brief Get the parent index object
 * 
 * @param heap 
 * @param i 
 * @return int 
 */
int get_parent_index(heap *heap, int i);
/**
 * @brief Get the left index object
 * 
 * @param heap 
 * @param i 
 * @return int 
 */
int get_left_index(heap *heap, int i);
/**
 * @brief Get the right index object
 * 
 * @param heap 
 * @param i 
 * @return int 
 */
int get_right_index(heap *heap, int i);
/**
 * @brief 
 * 
 * @param u 
 * @param v 
 * @param len 
 */
void swap(void *u, void *v, size_t len);
/**
 * @brief 
 * 
 * @param heap 
 */
void print_heap(heap *heap);
/**
 * @brief 
 * 
 * @param heap 
 * @param i 
 */
void min_heapify(heap *heap, int i);
/**
 * @brief 
 * 
 * @param heap 
 * @param item 
 * @return int 
 */
int is_in_heap(heap *heap, void *item);
/**
 * @brief 
 * 
 * @param heap 
 * @param new_node 
 */
void enqueue(heap *heap, node *new_node);
/**
 * @brief 
 * 
 * @param heap 
 * @return node* 
 */
node *dequeue(heap *heap);
/**
 * @brief 
 * 
 * @param heap 
 */
void deallocate_heap(heap *heap);

#endif