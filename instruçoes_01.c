#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void LSL(char vet[], int registradores[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
        
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    

    // adicionando nos registradores

   // printf("\n%d lm \n", Lm);
   // printf("%d ld  \n", Ld);
   // printf("%d imedia  \n", imediato);

    registradores[Ld] = (registradores[Lm] << imediato); // atualiza os registradores
    printf("%dlll\n",registradores[Ld] );

}

void LSR(char vet[],int registradores[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); // 3 primeiros bits do quarto digito ;
    
    
    // adicionando nos registradores
    //printf("\n%d lm \n", Lm);
    //printf("%d ld  \n", Ld);
    //printf("%d imedia  \n", imediato);

    registradores[Ld] = (registradores[Lm] >> imediato);
    printf("%dlll\n",registradores[Ld] );

}

void ASR(char vet[],int registradores[]){

    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
    //deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    
    // adicionando nos registradores
    //printf("\n%d lm \n", Lm);
    //printf("%d ld  \n", Ld);
    //printf("%d imedia  \n", imediato);

    //registradores[Ld] = 


  
}

void ADD_com_LM(char vet[],int registradores[]){

    int Lm = 0;
    Lm = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do LM
    // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do LM
    //Assim teremos os 3 bits do LM
    Lm = Lm | ((vet[2] & 12) >> 2);
    int Ln = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Ln = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Ln = (Ln| (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 

        // adicionando nos registradores
   // printf("\n%d lm \n", Lm);
   // printf("%d ld  \n", Ld);
   // printf("%d Ln \n", Ln);

    registradores[Ld] = Ln + Lm;
    printf("%dlll\n",registradores[Ld] );

}