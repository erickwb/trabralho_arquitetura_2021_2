#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//funçoes_basicas
//void execult(char buffer1 [], char buffer2[], int registradores[], char CPSR[]){
void ConvertChar(char vet[]);
void Decodifica(char vet[], int registradores[], char CPSR[]);
//instruçoes_01
void LSL(char vet[],int registradores[], char CPSR[]);
void LSR(char vet[],int registradores[], char CPSR[]);
void ASR(char vet[],int registradores[], char CPSR[]);
void ADD_com_LM(char vet[],int registradores[], char CPSR[]);
void SUB_com_LM(char vet[], int registradores[], char CPSR[]);

//instruções de parada
void Undefined(char vet[], int registradores[], char CPSR[]);
void B_ponto(char vet[], int registradores[], char CPSR[]);
//Show_things
void Mostra_Registrador(int registradores[]);
void Mostra_CPSR(char CPSR[]);
void Mostra_memory_program(char frase[], char buffer1[], char buffer2[], FILE *file, unsigned int memoria_programa);
//updates_things
void Atualiza_CPSR(int registradores[],char CPSR[], int Ld);
void Copia_conteudo(char origem[], char buffer1[], char buffer2[]);


#endif // HEADER_H_INCLUDED

