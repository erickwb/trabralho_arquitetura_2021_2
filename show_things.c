#include <stdio.h>
#include <stdlib.h>
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
}