#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//variaveis de saida do simulador
int registradores[11] = {1,1,1,1,1,1,1,1,0,0,0}; // falta o Ls
char CPSR[9] = {'n','z','c','v','q','j','i','f','T'}; //falta o modo
int memoria_dados = 0;
unsigned int memoria_programa = 0x80000000;
char aux_memoria [200];
char Cond_parada[] = "0000";

int cont_m = -1;
unsigned int memoria_de_dados_address[100];
int memoria_de_dados_conteudo[100];


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

    while (fgets(frase, sizeof(frase), file) != NULL){

        Copia_conteudo(frase, buffer1, buffer2);
        ConvertChar(buffer1); 
        Decodifica(buffer1, registradores, CPSR, memoria_de_dados_address, memoria_de_dados_conteudo, cont_m); // 4 primeiros bytes
        //segunda instrução
        ConvertChar(buffer2); 
        Decodifica(buffer2, registradores, CPSR, memoria_de_dados_address, memoria_de_dados_conteudo, cont_m); // 4 ultimos bytes
        // atualizando PC
        registradores[9] = (registradores[9] + 8);

        fflush(file);
    };
    fclose(file); //fechando o arquivo 

    Mostra_Registrador(registradores);
    Mostra_CPSR(CPSR);
    //Mostra_memory_program(frase,buffer1,buffer2 ,file, memoria_programa); //com erro

 
   // fclose(file); //fechando o arquivo 
    return 0;
}