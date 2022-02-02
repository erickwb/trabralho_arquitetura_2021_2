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
    printf("PC %X \n", registradores[9]);
}

void Mostra_CPSR(char CPSR[]){

    printf("\n####################### CPSR ########################\n");

    for(int i = 0; i < 9; i++){
        printf("%c",CPSR[i]);
    }
    printf("\n");
}

void Mostra_memory_program(char frase[], char buffer1[], char buffer2[], FILE *file, unsigned int memoria_programa){
    rewind(file); //reabrindo o arquivo
    char buffer_temp [8]; // buffer temporario
    int cont = 0;

    printf("\n####################### Memoria de programa ########################\n");

    if(file == NULL){
        printf("Nao e possivel abrir o arquivo:");
        getchar();
        exit(0);
    }
    
}
