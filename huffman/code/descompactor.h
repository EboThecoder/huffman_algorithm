#ifndef descompactor_h
#define descompactor_h

#include <stdio.h>
#include <stdlib.h>


#include "tree.h"

int is_bit_i_set(unsigned char c, int i);

void read_first_two_bytes(FILE *file, unsigned short *trash_size, unsigned short *tree_size);

node *read_tree(FILE *file);

void read_file(node *tree, unsigned short trash_size, FILE *file);

void descompact();

#endif