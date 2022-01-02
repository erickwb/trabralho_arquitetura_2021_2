#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//variaveis de saida do simulador
int registradores[8] = {0,1,2,3,4,5,6,7};
char CPSR[9] = {'n','z','c','v','q','j','i','f','T'};
int memoria_dados;
int memoria_programa = 0x80000000;

int main(){

    FILE *file;
    file = fopen("input.txt", "r"); //lendo o arquivo input.txt

    char frase[4]; //buffer

    if(file == NULL){
        printf("Nao e possivel abrir o arquivo:");
        getchar();
        exit(0);

    }

    while (fgets(frase,5, file) != NULL){
        ConvertChar(frase); 
        Decodifica(frase, registradores, CPSR); // 4 primeiros bytes

    };

    Mostra_Registrador(registradores);
    Mostra_CPSR(CPSR);
    
    return 0;
}