#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
void execult(char buffer1 [], char buffer2[], int registradores[], char CPSR[]){
    ConvertChar(buffer1); 
    Decodifica(buffer1, registradores, CPSR); // 4 primeiros bytes
        //
    ConvertChar(buffer2); 
    Decodifica(buffer2, registradores, CPSR); // 4 primeiros bytes
}
*/

void ConvertChar(char vet[]){
    
    for (int i = 0; i < 4; i++){ 
        //caso seja de 0 a 9
        if((vet[i] >= '0') && (vet[i] <= '9')){
            vet[i] = vet[i] - '0'; //operacao para trasforma de char p/ int

        }
        //caso seja de a - f
        if((vet[i] >= 'a') && (vet[i] <= 'f')){
            vet[i] = vet[i] - 'W'; //operacao para trasforma de char p/ int
 
        }
        else if (vet[i] > 'f'){ //corrigir tal caso
            printf("O digito invalido, digite um digito em hexadecimal\n");
        }
    }
}



//parametros: vetor de char, arquivo de destino
void Decodifica(char vet[], int registradores[], char CPSR[]){

    //primeiro digito = 4bits primeiros da instruçao thumb
    switch (vet[0]){
    case 0:
        if((vet[1] >> 3) == 0){
            //caso LSL
            LSL(vet, registradores, CPSR);
        }
        if((vet[1] >> 3) == 1){
            //caso LSR
            LSR(vet, registradores, CPSR);
        } 
    case 1:
         //instruçao ASR
        if((vet[1] >> 3) == 0){
            ASR(vet, registradores, CPSR);
        }
        //instruçoes ADD / SUB com LM
        if ((vet[1] >> 1) == 4 ){
            //instruçao ADD com LM
            ADD_com_LM(vet, registradores, CPSR);

        }
       
        break;
        
    }
}

