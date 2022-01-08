#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"



void Mostra_Registrador(int registradores[]){

    printf("\n####################### Registradores ########################\n");

    for(int i = 0; i < 8; i++){
        printf("R%d ",i);
        printf(" %d \n",registradores[i]);
    }
}

void Mostra_CPSR(char CPSR[]){

    printf("\n####################### CPSR ########################\n");

    for(int i = 0; i < 9; i++){
        printf("%c",CPSR[i]);
    }
    printf("\n");
}

void Mostra_memory_data(char buffer1[], FILE *file){

    printf("\n####################### Memoria de programa ########################\n");

    if(file == NULL){
        printf("Nao e possivel abrir o arquivo:");
        getchar();
        exit(0);
    }

    while (fgets(buffer1,12, file) != NULL){
        printf("%s", buffer1);
    }

}

