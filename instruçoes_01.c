#include <stdio.h>
#include <stdlib.h>
#include "heade.h"

int registradores[8];

void LSL(char vet[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
        
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    

    // adicionando nos registradores

    printf("\n%d lm \n", Lm);
    printf("%d ld  \n", Ld);
    printf("%d imedia  \n", imediato);


}

void LSR(char vet[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); // 3 primeiros bits do quarto digito ;
    
    
    // adicionando nos registradores
    printf("\n%d lm \n", Lm);
    printf("%d ld  \n", Ld);
    printf("%d imedia  \n", imediato);




}