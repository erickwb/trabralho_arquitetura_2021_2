#include <stdio.h>
#include <stdlib.h>
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
    //verificaca o valor da carry flag
    //ideia and
    //ideia compara lm com o valor do shift
}