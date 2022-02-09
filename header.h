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
void ADD_com_LD_HM(char vet[], int registradores[], char CPSR[]);
void MOV_com_LD_HM(char vet[], int registradores[], char CPSR[]);
void ADD_com_HD_LM(char vet[], int registradores[], char CPSR[]);
void MOV_com_HD_LM(char vet[], int registradores[], char CPSR[]);
void ADD_com_HD_HM(char vet[], int registradores[], char CPSR[]);
void MOV_com_HD_HM(char vet[], int registradores[], char CPSR[]);
void CMP_com_LN_HM(char vet[], int registradores[], char CPSR[]);
void CMP_com_HN_LM(char vet[], int registradores[], char CPSR[]);
void CMP_com_HN_HM(char vet[], int registradores[], char CPSR[]);
void BX(char vet[], int registradores[], char CPSR[]);
void BLX(char vet[], int registradores[], char CPSR[]);
void LDR_com_imediato8(char vet[], int registradores[], char CPSR[]);
void STR(char vet[], int registradores[], char CPSR[]);
void STRH(char vet[], int registradores[], char CPSR[]);
void STRB(char vet[], int registradores[], char CPSR[]);
void LDRSB_pre(char vet[], int registradores[], char CPSR[]);
void LDR(char vet[], int registradores[], char CPSR[]);
void LDRH(char vet[], int registradores[], char CPSR[]);
void LDRB(char vet[], int registradores[], char CPSR[]);
void LDRSH_pre(char vet[], int registradores[], char CPSR[]);
void SXTH(char vet[], int registradores[], char CPSR[]);
void SXTB(char vet[], int registradores[], char CPSR[]);
void UXTH(char vet[], int registradores[], char CPSR[]);
void UXTB(char vet[], int registradores[], char CPSR[]);
void REV(char vet[], int registradores[], char CPSR[]);
void REV16(char vet[], int registradores[], char CPSR[]);
void REVSH(char vet[], int registradores[], char CPSR[]);
void PUSH(char vet[], int registradores[], char CPSR[]);
void POP(char vet[], int registradores[], char CPSR[]);
void SETEND_LE(char vet[], int registradores[], char CPSR[]);
void SETEND_BE(char vet[], int registradores[], char CPSR[]);
void CPSIE(char vet[], int registradores[], char CPSR[]);
void CPSID(char vet[], int registradores[], char CPSR[]);
void STMIA(char vet[], int registradores[], char CPSR[]);
void LDMIA(char vet[], int registradores[], char CPSR[]);

//instruções de parada
void Undefined(char vet[], int registradores[], char CPSR[]);
void B_ponto(char vet[], int registradores[], char CPSR[]);
//Show_things
void Mostra_Registrador(int registradores[]);
void Mostra_CPSR(char CPSR[]);
void Mostra_memory_data(int address[], int conteudo[], int cont);
//updates_things
void Atualiza_CPSR(int registradores[],char CPSR[], int Ld);
void Copia_conteudo(char origem[], char buffer1[], char buffer2[]);

//funções de store/load
void Store_memory_data(int address, int conteudo);
int Load_memory_data(int address);


#endif // HEADER_H_INCLUDED

