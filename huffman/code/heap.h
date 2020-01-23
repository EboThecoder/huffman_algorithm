#ifndef heap_h
#define heap_h

#include "tree.h"

#include <stdlib.h>
#include <limits.h>

/**
 * @brief Struct da Heap
 * 
 */
typedef struct heap
{
    int size; 
    node *nodes[256];
} heap;
/**
 * @brief Monta a Heap
 * 
 * @return Retorna o ponteiro pra Heap 
 */
heap *create_heap();
/**
 * @brief Pega o índice do nó Pai
 * 
 * @param heap 
 * @param i 
 * @return Retorna o índice do nó Pai 
 */
int get_parent_index(heap *heap, int i);
/**
 * @brief Pega o índice do filho da esquerda
 * 
 * @param heap 
 * @param i 
 * @return Retorna o índice do filho da esquerda  
 */
int get_left_index(heap *heap, int i);
/**
 * @brief Pega o índice do filho da direita
 * 
 * @param heap 
 * @param i 
 * @return Retorna o índice do filho da direita 
 */
int get_right_index(heap *heap, int i);
/**
 * @brief Troca os valores de dois ponteiros pra void
 * 
 * @param u 
 * @param v 
 * @param len 
 */
void swap(void *u, void *v, size_t len);
/**
 * @brief Imprime a Heap
 * 
 * @param heap 
 */
void print_heap(heap *heap);
/**
 * @brief Ajeita a estrutura da Heap retornando suas propriedades
 * 
 * @param heap 
 * @param i 
 */
void min_heapify(heap *heap, int i);
/**
 * @brief Verifica se o item está na Heap
 * 
 * @param heap 
 * @param item 
 * @return Retorna a posição do item na Heap
 */
int is_in_heap(heap *heap, void *item);
/**
 * @brief Enfileira o nó na Heap enquanto não estiver cheia
 * 
 * @param heap 
 * @param new_node 
 */
void enqueue(heap *heap, node *new_node);
/**
 * @brief Desenfileira o primeiro nó da Heap
 * 
 * @param heap 
 * @return Retorna o item desnfileirado e quando a Heap está vazia retorna NULL 
 */
node *dequeue(heap *heap);
/**
 * @brief 
 * 
 * @param heap 
 */
void deallocate_heap(heap *heap);

#endif