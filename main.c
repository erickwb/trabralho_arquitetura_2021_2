#include <stdio.h>
#include <stdlib.h>
#include "heade.h"

//variaveis 
int registradores[8] = {0,1,2,3,4,5,6,7};

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
        Decodifica(frase, registradores); // 4 primeiros bytes

    };

    Mostra_Registrador(registradores);
    
    return 0;
}