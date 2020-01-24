#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tree.h"
#include "heap.h"
#include "hash.h"
#include "compactor.h"
#include "descompactor.h"

int main()
{
    int a;
    printf("_____________________________________________________________________________\n");
    printf("||                                                                         ||\n");
    printf("||                                                                         ||\n");
    printf("||                                                                         ||\n");
    printf("||                                                                         ||\n");
    printf("||                                                                         ||\n");
    printf("||                                                                         ||\n");
    printf("||      ██╗  ██╗██╗   ██╗███████╗███████╗███╗   ███╗ █████╗ ███╗   ██╗     ||\n"); 
    printf("||      ██║  ██║██║   ██║██╔════╝██╔════╝████╗ ████║██╔══██╗████╗  ██║     ||\n"); 
    printf("||      ███████║██║   ██║█████╗  █████╗  ██╔████╔██║███████║██╔██╗ ██║     ||\n"); 
    printf("||      ██╔══██║██║   ██║██╔══╝  ██╔══╝  ██║╚██╔╝██║██╔══██║██║╚██╗██║     ||\n");
    printf("||      ██║  ██║╚██████╔╝██║     ██║     ██║ ╚═╝ ██║██║  ██║██║ ╚████║     ||\n");
    printf("||      ╚═╝  ╚═╝ ╚═════╝ ╚═╝     ╚═╝     ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝     ||\n");
    printf("||                                                                         ||\n");
    printf("||                                                                         ||\n");
    printf("||                                                                         ||\n");     
    printf("||                                                                         ||\n");         
    printf("||                                                                         ||\n");                 
    printf("||   Ebert Henrique - Rafael Anacleto - Tiago Beltrão - Ronaldo Cândido    ||\n");         
    printf("||                                                                         ||\n");    
    printf("||_________________________________________________________________________||\n\n");

    while(a != 3)
    {
        printf("Menu:\n\nDigite [1] para compactar.\nDigite [2] para descompactar.\nDigite [3] para sair.\n\n");
        printf("Digite: ");
        scanf("%d", &a);
        if(a == 1)
        {
            if(compact())
            {
                printf("Retornando para o menu...\n\n");
            }
        }
        if(a == 2)
        {
            if (descompact())
            {
                printf("Retornando para o menu...\n\n");
            }
        }
    }
    return 0;
}