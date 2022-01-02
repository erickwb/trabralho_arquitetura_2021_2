#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void Mostra_Registrador(int registradores[]){
 for(int i = 0; i < 8; i++){
        printf("\n###############################################\n");
        printf("R%d ",i);
        printf(" %d \n",registradores[i]);

    }

}