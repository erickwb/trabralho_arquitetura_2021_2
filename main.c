#include <stdio.h>
#include <stdlib.h>
#include "heade.h"



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
     //   printf("%s\n", frase); //printando o conteudo da linha

        ConvertChar(frase); 
        
        Decodifica(frase); // 4 primeiros bytes

    };


    return 0;
}