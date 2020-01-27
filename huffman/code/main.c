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
    printf("||_________________________________________________________________________||\n\n");
    printf("--------------------------------INSTRUÇÕES:----------------------------------\n");
    printf("(1) - Escreva o caminho do arquivo para compactar em \"path.txt\".\n");
    printf("(2) - O arquivo compactado será salvo em \"../compacted_files\" como \"compacted_file\".\n");
    printf("(3) - A opção \"descompactar\" utiliza o arquivo salvo em \"../compacted_files/compacted_file\" para descompactar\n");
    printf("(4) - O arquivo descompactado será salvo em \"../files\" como \"descompacted_file\".\n\n");
    printf("Digite qualquer tecla para continuar\n");
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
            system("clear");
            compact();
            printf("Retornando para o menu...\n\n");
        }
        if (ch - '0' == 2)
        {
            system("clear");
            descompact();
            printf("Retornando para o menu...\n\n");
        }
        if(ch - '0' == 1 || ch - '0'==2)
        {
            printf("-------------------------MENU-------------------------\n\n");
            printf("Digite [1] para compactar.\nDigite [2] para descompactar.\nDigite [3] para sair.\n\n");
            printf("Digite: ");
        }
    } while (ch - '0' != 3);
    return 0;
}