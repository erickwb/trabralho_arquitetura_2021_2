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

void Store_memory_data(int address, int conteudo, int memoria_de_dados_address[], int memoria_de_dados_conteudo[], int cont_m){
    int aux = 1;
    //Verificando se o endereço já foi usado no programa. Se sim, atualiza-se somente o conteúdo
    for(int n = 0; n <= 100; n++){
        if(memoria_de_dados_address[n] == address){
           memoria_de_dados_conteudo[n] = conteudo; 
           aux = 0;
        }
    }
    
    //Se for um novo endereço a ser usado no programa
    if(aux == 1){
        //criando "nova" posição para o novo endereço
        cont_m += 1;
        memoria_de_dados_address[cont_m] = address;
        memoria_de_dados_conteudo[cont_m] = conteudo;
        
        //alinhando endereços em forma crescente 
        for(int n = 0; n <= cont_m; n++){
            if(memoria_de_dados_address[n] > memoria_de_dados_address[cont_m]){
                aux = memoria_de_dados_address[n];
                memoria_de_dados_address[n] = memoria_de_dados_address[cont_m]; 
                memoria_de_dados_address[cont_m] = aux;
                
                aux = memoria_de_dados_conteudo[n];
                memoria_de_dados_conteudo[n] = memoria_de_dados_conteudo[cont_m]; 
                memoria_de_dados_conteudo[cont_m] = aux;
            }
        }
    }
   
}

int Load_memory_data(int address, int memoria_de_dados_address[], int memoria_de_dados_conteudo[], int cont_m){
    for(int n = 0; n <= cont_m; n++){
        if(address == memoria_de_dados_address[n]){
            return memoria_de_dados_conteudo[n];
        }
    }
    return 0;
}