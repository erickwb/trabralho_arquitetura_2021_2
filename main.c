#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//variaveis de saida do simulador
int registradores[8] = {1,1,1,1,1,1,1,1};
char CPSR[9] = {'n','z','c','v','q','j','i','f','T'}; //falta o modo
int memoria_dados;
unsigned int memoria_programa = 0x80000000;
char aux_memoria [200];


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
        //
        ConvertChar(buffer2); 
        Decodifica(buffer2, registradores, CPSR); // 4 primeiros bytes
    };

    fclose(file); //fechando o arquivo
    
    Mostra_Registrador(registradores);
    Mostra_CPSR(CPSR);
    Mostra_memory_data(frase, file); //com erro
    

    return 0;
}