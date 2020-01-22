#ifndef hash_h
#define hash_h

#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEPTH 32
#define LEFT_JUMP 0
#define RIGHT_JUMP 1
#define START_JUMP -1

typedef struct hash_node
{
    void *key;
    int depth;
    int frequency;
    bool bits[MAX_DEPTH];
} hash_node;

typedef struct hash_table
{
    hash_node *table[256];
    int size;
} hash;

hash *create_hash_table();

void print_bits(bool *bits, int size);

void put(hash *hash, void *key, int depth, int frequency, bool *bits);

void build_map(node *tree, hash *map, int depth, bool *bits, int jump, unsigned short *tree_size);

//hash_node *get(hash *hash, void *key);

void print_map(hash *hash);

void deallocate_hash(hash *hash);

#endif