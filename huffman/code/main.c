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
    system("clear");
    char ch = 0;
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
    printf("||_______________Pressione qualquer tecla para continuar:__________________||\n\n");
    getc(stdin);
    system("clear");
    printf("-------------------------MENU-------------------------\n\n");
    printf("Digite [1] para compactar.\nDigite [2] para descompactar.\nDigite [3] para sair.\n\n");
    printf("Digite: ");
    do
    {
        ch = getc(stdin);;
        if(ch - '0' == 1)
        {
            compact();
            printf("Retornando para o menu...\n\n");
        }
        if (ch - '0' == 2)
        {
            descompact();
            printf("Retornando para o menu...\n\n");
        }
        if(ch - '0' == 1 || ch - '0'==2)
        {
            printf("-------------------------MENU-------------------------\n\n");
            printf("Digite [1] para compactar.\nDigite [2] para descompactar.\nDigite [3] para sair.\n\n");
            printf("Digite: ");
        }
        //else system("clear");
    } while (ch - '0' != 3);
    return 0;
}