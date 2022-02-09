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

void ADD_com_LD_HM(char vet[], int registradores[], char CPSR[]){

  int Ld = 0;

  Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Hm = 0;
  Hm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Hm = (Hm | (vet[3] & 8)) >> 3;

  registradores[Ld] = registradores[Ld] + registradores[Hm];

  Atualiza_CPSR(registradores, CPSR, Ld);
}

void MOV_com_LD_HM(char vet[], int registradores[], char CPSR[]){

  int Ld = 0;

  Ld = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Hm = 0;
  Hm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Hm = (Hm | (vet[3] & 8)) >> 3;

  registradores[Ld] = registradores[Hm];

  Atualiza_CPSR(registradores, CPSR, Ld);
}

void ADD_com_HD_LM(char vet[], int registradores[], char CPSR[]){

  int Hd = 0;

  Hd = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Lm = (Lm | (vet[3] & 8)) >> 3;

  registradores[Hd] = registradores[Hd] + registradores[Lm];

  Atualiza_CPSR(registradores, CPSR, Hd);
}

void MOV_com_HD_LM(char vet[], int registradores[], char CPSR[]){

  int Hd = 0;

  Hd = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Lm = (Lm | (vet[3] & 8)) >> 3;

  registradores[Hd] = registradores[Lm];

  Atualiza_CPSR(registradores, CPSR, Hd);
}

void ADD_com_HD_HM(char vet[], int registradores[], char CPSR[]){

  int Hd = 0;

  Hd = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Hm = 0;
  Hm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Hm = (Hm | (vet[3] & 8)) >> 3;

  registradores[Hd] = registradores[Hd] + registradores[Hm];

  Atualiza_CPSR(registradores, CPSR, Hd);
}

void MOV_com_HD_HM(char vet[], int registradores[], char CPSR[]){

  int Hd = 0;

  Hd = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Hm = 0;
  Hm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Hm = (Hm | (vet[3] & 8)) >> 3;

  registradores[Hd] = registradores[Hm];

  Atualiza_CPSR(registradores, CPSR, Hd);
}

void CMP_com_LN_HM(char vet[], int registradores[], char CPSR[]){
  int Ln = 0;

  Ln = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Hm = 0;
  Hm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Hm = (Hm | (vet[3] & 8)) >> 3;

  registradores[Ln] = registradores[Ln] + (~registradores[Hm]) + 1;

  Atualiza_CPSR(registradores, CPSR, Ln);
}

void CMP_com_HN_LM(char vet[], int registradores[], char CPSR[]){
  int Hn = 0;

  Hn = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Lm = (Lm | (vet[3] & 8)) >> 3;

  registradores[Hn] = registradores[Hn] + (~registradores[Lm]) + 1;

  Atualiza_CPSR(registradores, CPSR, Hn);
}

void CMP_com_HN_HM(char vet[], int registradores[], char CPSR[]){
  int Hn = 0;

  Hn = (vet[3] & 7); //3 primeiros bits do quarto digito ;

  int Hm = 0;
  Hm = ((vet[2] & 3) << 4); //pegando os 2priemiros bits do terceiro digito  
  Hm = (Hm | (vet[3] & 8)) >> 3;

  registradores[Hn] = registradores[Hn] + (~registradores[Hm]) + 1;

  Atualiza_CPSR(registradores, CPSR, Hn);
}

void BX(char vet[], int registradores[], char CPSR[]){
  int Rm = 0;

  Rm = ((vet[3] & 8) >> 3);//pegando o ultimo bit do ultimo numero e >> para o inicio
  Rm = Rm | ((vet[2] & 7) << 1);//pegando os 3 ultimos bits do terceiro numero e adicionando com 'ou' o ultimo bit
  

  registradores[0] = registradores[Rm] & 0xfffffffe;
  if((Rm & 1) == 1){
    CPSR[8] = 'T';
  }else{
    CPSR[8] = 't';
  }
}

void BLX(char vet[], int registradores[], char CPSR[]){
  int Rm = 0;

  Rm = ((vet[3] & 8) >> 3);//pegando o ultimo bit do ultimo numero e >> para o inicio
  Rm = Rm | ((vet[2] & 7) << 1);//pegando os 3 ultimos bits do terceiro numero e adicionando com 'ou' o ultimo bit
  
  registradores[14] = registradores[0] + 4 + 1;//registrador lr recebe endereço de retorno
  registradores[0] = registradores[Rm] & 0xfffffffe;//pc recebe endereço para pulo
  if((Rm & 1) == 1){
    CPSR[8] = 'T';
  }else{
    CPSR[8] = 't';
  }
  
}

void LDR_com_imediato8(char vet[], int registradores[], char CPSR[]){
  int imediato = 0;
  //pegando os 8 primeiros, no terceiro e quarto bit
  imediato = ((vet[2] & 15) << 4);
  imediato = imediato | (vet[3] & 15);
  
  int Ld = 0;
  Ld = (vet[1] & 7);//3 bits do segundo numero

  int address = registradores[0] + imediato*4; 
  registradores[Ld] = Load_memory_data(address);

  Atualiza_CPSR(registradores, CPSR, Ld);
}

void STR(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  int address = registradores[Ln] + registradores[Lm];
  Store_memory_data(address, registradores[Ld]);
  
  Atualiza_CPSR(registradores, CPSR, Ld);
}

void STRH(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  
  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void STRB(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void LDRSB_pre(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void LDR(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void LDRH(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void LDRB(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void LDRSH_pre(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Ln = 0;
  Ln = ((vet[2] & 3) << 4);
  Ln = (Ln | (vet[3] & 8)) >> 3;

  int Lm = 0;
  Lm = ((vet[1] & 1) << 2);//pegando o primeiro bit do segundo número
  Lm = Lm | ((vet[2] & 12) >> 2);//pegando os 2 ultimos bits do terceiro número

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void SXTH(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4);
  Lm = (Lm | (vet[3] & 8)) >> 3;

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void SXTB(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4);
  Lm = (Lm | (vet[3] & 8)) >> 3;

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void UXTH(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4);
  Lm = (Lm | (vet[3] & 8)) >> 3;

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void UXTB(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4);
  Lm = (Lm | (vet[3] & 8)) >> 3;

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void REV(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4);
  Lm = (Lm | (vet[3] & 8)) >> 3;

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void REV16(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4);
  Lm = (Lm | (vet[3] & 8)) >> 3;

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void REVSH(char vet[], int registradores[], char CPSR[]){
  int Ld = 0;
  Ld = (vet[3] & 7);

  int Lm = 0;
  Lm = ((vet[2] & 3) << 4);
  Lm = (Lm | (vet[3] & 8)) >> 3;

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void PUSH(char vet[], int registradores[], char CPSR[]){
  int r1, r2 = 0;

  r1 = vet[3];
  r2 = vet[2];

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void POP(char vet[], int registradores[], char CPSR[]){
  int r1, r2 = 0;

  r1 = vet[3];
  r2 = vet[2];

  //registradores[Ld] = registradores[Ld];

  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void SETEND_LE(char vet[], int registradores[], char CPSR[]){
  //CPSR[E] = 'e';


  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void SETEND_BE(char vet[], int registradores[], char CPSR[]){
  //CPSR[E] = 'E';


  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void CPSIE(char vet[], int registradores[], char CPSR[]){
  //CPSR[E] = 'e';


  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void CPSID(char vet[], int registradores[], char CPSR[]){
  //CPSR[E] = 'e';


  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void STMIA(char vet[], int registradores[], char CPSR[]){
  int ln = 0;
  int r1 = 0;
  int r2 = 0;

  r1 = vet[3];
  r2 = vet[2];

  ln = (vet[1] & 7);


  //Atualiza_CPSR(registradores, CPSR, Ln);
}

void LDMIA(char vet[], int registradores[], char CPSR[]){
  int ln = 0;
  int r1 = 0;
  int r2 = 0;

  r1 = vet[3];
  r2 = vet[2];

  ln = (vet[1] & 7);


  //Atualiza_CPSR(registradores, CPSR, Ln);
}




// instruçoes de parada
void Undefined(char vet[], int registradores[], char CPSR[]){
  printf("\n Instrução Indefinida encontrada"); 
  
}

void B_ponto(char vet[], int registradores[], char CPSR[]){
  printf("\n Encontrada instrução do tipo b .");

}
