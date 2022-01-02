#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


void ConvertChar(char vet[]);
void Decodifica(char vet[], int registradores[], char CPSR[]);
void LSL(char vet[],int registradores[], char CPSR[]);
void LSR(char vet[],int registradores[], char CPSR[]);
void ASR(char vet[],int registradores[], char CPSR[]);
void ADD_com_LM(char vet[],int registradores[], char CPSR[]);

void Mostra_Registrador(int registradores[]);
void Mostra_CPSR(char CPSR[]);
void Atualiza_CPSR(int registradores[],char CPSR[], int Ld);


#endif // HEADER_H_INCLUDED

