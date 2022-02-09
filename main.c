#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//variaveis de saida do simulador
int registradores[9] = {1,1,1,1,1,1,1,1,0};
char CPSR[9] = {'n','z','c','v','q','j','i','f','T'}; //falta o modo
int memoria_dados = 0;
unsigned int memoria_programa = 0x80000000;
char aux_memoria [200];
char Cond_parada[] = "0000";

int cont_m = -1;
unsigned int memoria_de_dados_address[100];
int memoria_de_dados_conteudo[100];

void Store_memory_data(int address, int conteudo){
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

int Load_memory_data(int address){
    for(int n = 0; n <= cont_m; n++){
        if(address == memoria_de_dados_address[n]){
            return memoria_de_dados_conteudo[n];
        }
    }
    return 0;
}

int main(){

    FILE *file;
    file = fopen("input.txt", "r"); //lendo o arquivo input.txt

    char frase[11]; //buffer da linha

    char buffer1[4]; //buffer das 4 primeiras strings
    char buffer2[4]; //buffer das 4 ultimas strings

    if(file == NULL){
        printf("Nao e possivel abrir o arquivo:");
        getchar();
        exit(0);
    }

    while (fgets(frase,12, file) != NULL){
        Copia_conteudo(frase, buffer1, buffer2);
        ConvertChar(buffer1); 
        Decodifica(buffer1, registradores, CPSR); // 4 primeiros bytes
        //segunda instrução
        ConvertChar(buffer2); 
        Decodifica(buffer2, registradores, CPSR); // 4 ultimos bytes
    };

    Mostra_Registrador(registradores);
    Mostra_CPSR(CPSR);
    Mostra_memory_program(frase,buffer1,buffer2 ,file, memoria_programa); //com erro
    Mostra_memory_data(memoria_de_dados_address, memoria_de_dados_conteudo, cont_m);
 
    fclose(file); //fechando o arquivo 
    return 0;
}