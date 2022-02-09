#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void Atualiza_CPSR(int registradores[],char CPSR[], int Ld){
    
    if((registradores[Ld] & 0x80000000) == 0x80000000){ //and para descobrir se o sinal do bit 31 esta em nivel alto
        CPSR[0] = 'N';
    }else{
       CPSR[0] = 'n'; 
    }
    //verifica se o resultado da operação e 0
    if(registradores[Ld] == 0){ 
        CPSR[1] = 'Z';
    }else{
        CPSR[1] = 'z';
    }

}
void Copia_conteudo(char origem[], char buffer1[], char buffer2[]){

    for (int i = 3; i < 7; i++){
        buffer1[i-3] = origem[i]; 
    }
    for (int i = 7; i < 11; i++){
        buffer2[i-7] = origem[i]; 
    }

   // printf("%s \n", destino);
}

