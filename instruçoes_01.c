#include <stdio.h>
#include <stdlib.h>
#include "heade.h"

int registradores[8];

void LSL(char vet[], FILE *file2){
    //printf("caso LSL\n");
        int imediato = 0; 
        imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
        //deslocado 2 vez para <-
        imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
        
        int registrador_origem = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
        registrador_origem = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
        registrador_origem = (registrador_origem | (vet[3] & 8)) >> 3;
        int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
        //adicionando no arquivo de destino 
        file2 = fopen("output.txt", "a");
        fprintf(file2,"\nLSL ");
        fprintf(file2,"r%d ,", registrador_origem);
        fprintf(file2,"r%d ,", registrador_destino);
        fprintf(file2,"#%d", imediato);
        fclose(file2);

}

void LSR(char vet[], FILE *file2){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
    //deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int registrador_origem = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    registrador_origem = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    registrador_origem = (registrador_origem | (vet[3] & 8)) >> 3;
    int registrador_destino = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    //adicionando no arquivo de destino 
    file2 = fopen("output.txt", "a");
    fprintf(file2,"\nLSR ");
    fprintf(file2,"r%d ,", registrador_origem);
    fprintf(file2,"r%d ,", registrador_destino);
    fprintf(file2,"#%d", imediato);
    fclose(file2);




}