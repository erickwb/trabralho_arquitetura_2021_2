#include <stdio.h>
#include <stdlib.h>
#include "heade.h"



int main(){

    FILE *file;
    file = fopen("input.txt", "r"); //lendo o arquivo input.txt
    FILE *file2;
    file2 = fopen("output.txt", "w"); //arquivo de destino 

    char frase[100]; //buffer
    
    if(file == NULL){
        printf("Nao e possivel abrir o arquivo:");
        getchar();
        exit(0);
    }

    while (fgets(frase,100, file) != NULL){
     //   printf("%s\n", frase); //printando o conteudo da linha
        ConvertChar(frase); 
    
       // Decodifica(frase, file2);

    };
   
        

  
    return 0;
}