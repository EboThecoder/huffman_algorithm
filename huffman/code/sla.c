#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "tree.h"

int is_bit_i_set(unsigned char c, int i)
{
    unsigned char mask = 1 << 7 - i;
    return mask & c;
}

//void print_byte

void read_first_two_bytes(FILE *file, unsigned short *trash_size, unsigned short *tree_size)
{
    unsigned char ch[2];
    fscanf(file, "%c%c", &ch[0], &ch[1]);
    printf("chars %d %d\n", ch[0], ch[1]);
    if (is_bit_i_set(ch[0], 0)) *trash_size += 4;
    if (is_bit_i_set(ch[0], 1)) *trash_size += 2;
    if (is_bit_i_set(ch[0], 2)) *trash_size += 1;
    ch[0] <<= 3;
    *tree_size += ch[0];
    *tree_size <<= 5;
    *tree_size += ch[1];
}

int main()
{
    FILE* fp = fopen("../files/m.mp3", "r");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp), sla;
    printf("tamnho %ld\n", size);
    fseek(fp, 0, SEEK_SET);
    while(feof(fp)!= 1)
    {
        getc(fp);
        sla = ftell(fp);
        
        printf("%f %% \n", 100.0*sla/size);
    }
}