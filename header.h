#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//funçoes_basicas
void ConvertChar(char vet[]);
void Decodifica(char vet[], int registradores[], char CPSR[]);
//instruçoes_01
void LSL(char vet[],int registradores[], char CPSR[]);
void LSR(char vet[],int registradores[], char CPSR[]);
void ASR(char vet[],int registradores[], char CPSR[]);
void ADD_com_LM(char vet[],int registradores[], char CPSR[]);
//Show_things
void Mostra_Registrador(int registradores[]);
void Mostra_CPSR(char CPSR[]);
void Mostra_Data_Programa(char buffer1[], char buffer2[]);
//updates_things
void Atualiza_CPSR(int registradores[],char CPSR[], int Ld);
void Copia_conteudo(char origem[], char buffer1[], char buffer2[]);


#endif // HEADER_H_INCLUDED

