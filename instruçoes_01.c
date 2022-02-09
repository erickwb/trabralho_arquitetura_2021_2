#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void LSL(char vet[], int registradores[], char CPSR[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); //2 ultimos bits do terceiro digito
        
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
  /* printf("\nLSL");
    printf("%d lm \n", Lm);
    printf("%d ld  \n", Ld);
    printf("%d imedia  \n", imediato);
  */
     // adicionando nos registradores
    registradores[Ld] = (registradores[Lm] << imediato); // atualiza os registradores
    //printf("%d result\n",registradores[Ld] );

    //atualizando CPSR
    Atualiza_CPSR(registradores, CPSR, Ld);

}

void LSR(char vet[], int registradores[], char CPSR[]){
    
    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda, deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); // 3 primeiros bits do quarto digito ;
    
    // adicionando nos registradores
    registradores[Ld] = (registradores[Lm] >> imediato);
    //atualizando CPSR
    Atualiza_CPSR(registradores, CPSR, Ld);

}

void ASR(char vet[], int registradores[], char CPSR[]){

    int imediato = 0; //imediado de 5bits
    imediato = (vet[1] & 7) << 2; //and com 7 para saber os 3primeiro bits do segundo digito da direita pra esquerda
    //deslocado 2 vez para <-
    imediato = imediato  | ((vet[2] & 12) >>2); // 2ultimos bits do terceiro digito
    
    int Lm = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
    Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
    Lm = (Lm | (vet[3] & 8)) >> 3;
    int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
    // adicionando nos registradores
    registradores[Ld] = (registradores [Lm] >> imediato);

    //atualizando CPSR
    Atualiza_CPSR(registradores, CPSR, Ld);
  
}

void ADD_com_LM(char vet[], int registradores[], char CPSR[]){

  int Lm = 0;
  Lm = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do LM
  // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do LM
  //Assim teremos os 3 bits do LM
  Lm = Lm | ((vet[2] & 12) >> 2);
  int Ln = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
  Ln = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
  Ln = (Ln| (vet[3] & 8)) >> 3;
  int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;
    
  // adicionando nos registradores
  registradores[Ld] = registradores[Ln] + registradores [Lm];

  //atualizando CPSR
  Atualiza_CPSR(registradores, CPSR, Ld);

}


void SUB_com_LM(char vet[], int registradores[], char CPSR[]){
  
  int Lm = 0;
  Lm = (vet[1] & 1) << 2; //pegando o ultimo bit do segundo numero, e deslocando-o para o que sera o 3bit do LM
  // descobrindo os 2 ultimos bits do terceiro bit, movendo o 2bits pra -> e adicionando com o 3bit do LM
  //Assim teremos os 3 bits do LM
  Lm = Lm | ((vet[2] & 12) >> 2);
  int Ln = 0; // 2priemiros bits do terceiro digito ultimo bit do quarto digito
  Ln = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito
  Ln = (Ln| (vet[3] & 8)) >> 3;
  int Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  // adicionando nos registradores
  registradores[Ld] = registradores[Ln] - registradores [Lm];

  //atualizando CPSR
  Atualiza_CPSR(registradores, CPSR, Ld);

}
// instruçoes de parada
void Undefined(char vet[], int registradores[], char CPSR[]){
  printf("\n Instrução Indefinida encontrada"); 
  
}

void BKPT(char vet[], int registradores[], char CPSR[]){
  printf("\n Instrução BKPT \n ");
  printf("\n Status atual do programa");
  Mostra_Registrador(registradores);
  Mostra_CPSR(CPSR);
   // Mostra_memory_program(frase,buffer1,buffer2 ,file, memoria_programa); //com erro
}

void B_ponto(char vet[], int registradores[], char CPSR[]){
  printf("\n Encontrada instrução do tipo b .");

}

