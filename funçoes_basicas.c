#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
void execult(char buffer1 [], char buffer2[], int registradores[], char CPSR[]){
    ConvertChar(buffer1); 
    Decodifica(buffer1, registradores, CPSR); // 4 primeiros bytes
        //
    ConvertChar(buffer2); 
    Decodifica(buffer2, registradores, CPSR); // 4 primeiros bytes
}
*/

void ConvertChar(char vet[]){
    
    for (int i = 0; i < 4; i++){ 
        //caso seja de 0 a 9
        if((vet[i] >= '0') && (vet[i] <= '9')){
            vet[i] = vet[i] - '0'; //operacao para trasforma de char p/ int

        }
        //caso seja de a - f
        if((vet[i] >= 'a') && (vet[i] <= 'f')){
            vet[i] = vet[i] - 'W'; //operacao para trasforma de char p/ int
 
        }
        else if (vet[i] > 'f'){ //corrigir tal caso
            printf("O digito invalido, digite um digito em hexadecimal\n");
        }
    }
}



//parametros: vetor de char, arquivo de destino
void Decodifica(char vet[], int registradores[], char CPSR[], int memoria_de_dados_address[], int memoria_de_dados_conteudo[], int cont_m){

    //primeiro digito = 4bits primeiros da instruçao thumb
    switch (vet[0]){
    case 0:
        if((vet[1] >> 3) == 0){
            //caso LSL
            LSL(vet, registradores, CPSR);
        }
        if((vet[1] >> 3) == 1){
            //caso LSR
            LSR(vet, registradores, CPSR);
        } 
    break;
    case 1:
         //instruçao ASR
        if((vet[1] >> 3) == 0){
            ASR(vet, registradores, CPSR);
        }
        //instruçoes ADD / SUB com LM
        if ((vet[1] >> 1) == 4 ){
            //instruçao ADD com LM
            ADD_com_LM(vet, registradores, CPSR);

        }
       
        break;  
         
    case 4:
        //instruçoes ADD / MOV com LD_HM
        if((vet[1] == 4) && ((vet[2] & 12) == 4)){
            //instruçoes ADD com LD_HM
            ADD_com_LD_HM(vet, registradores, CPSR);    
        }
        if((vet[1] == 6) && ((vet[2] & 12) == 4)){
            //instruçoes MOV com LD_HM
            MOV_com_LD_HM(vet, registradores, CPSR);
        }

        //instruçoes ADD / MOV com HD_LM
        if((vet[1] == 4) && ((vet[2] & 12) == 8)){
            //instruçoes ADD com HD_LM
            ADD_com_HD_LM(vet, registradores, CPSR);    
        }
         if((vet[1] == 6) && ((vet[2] & 12) == 8)){
            //instruçoes MOV com HD_LM
            MOV_com_HD_LM(vet, registradores, CPSR);    
        }

        //instruçoes ADD / MOV com HD_HM
        if((vet[1] == 4) && ((vet[2] & 12) == 12)){
            //instruçoes ADD com HD_HM
            ADD_com_HD_HM(vet, registradores, CPSR);    
        }
        if((vet[1] == 6) && ((vet[2] & 12) == 12)){
            //instruçoes MOV com HD_HM
            MOV_com_HD_HM(vet, registradores, CPSR);    
        }
        
        //instruçoes CMP
        if(vet[1] == 5){
            //instruçoes CMP com LN_HM
            if((vet[2] & 12) == 4){
            CMP_com_LN_HM(vet, registradores, CPSR);  
            }
            //instruçoes CMP com HN_LM
            if((vet[2] & 12) == 8){
            CMP_com_HN_LM(vet, registradores, CPSR);  
            }
            //instruçoes CMP com HN_HM
            if((vet[2] & 12) == 12){
            CMP_com_HN_HM(vet, registradores, CPSR);  
            }
        }

        //instruçoes BX/BLX
        if(vet[1] == 7){
            //instrução BX
            if((vet[2] & 8) == 0){
                BX(vet, registradores, CPSR); 
            }
            //instrução BLX
            if((vet[2] & 8) == 8){
               BLX(vet, registradores, CPSR);  
            }

        }

        //instrução LDR_com_imediato8
        if((vet[1] & 8) == 8){
            LDR_com_imediato8(vet, registradores, CPSR, memoria_de_dados_address, memoria_de_dados_conteudo, cont_m);
        }

        break;

    case 5:
        //instruções STR | STRH | STRB | LDRSB pre
        if((vet[1] & 14) == 0){
            //instrução STR
            STR(vet, registradores, CPSR, memoria_de_dados_address, memoria_de_dados_conteudo, cont_m);
        }
        if((vet[1] & 14) == 2){
            //instrução STRH
            STRH(vet, registradores, CPSR);
        }
        if((vet[1] & 14) == 4){
            //instrução STRB
            STRB(vet, registradores, CPSR);
        }
        if((vet[1] & 14) == 6){
            //instrução LDRSB_pre
            LDRSB_pre(vet, registradores, CPSR);
        }

        //instruções LDR | LDRH | LDRB | LDRSH pre
        if((vet[1] & 14) == 8){
            //instrução LDR
            LDR(vet, registradores, CPSR);
        }
        if((vet[1] & 14) == 10){
            //instrução LDRH
            LDRH(vet, registradores, CPSR);
        }
        if((vet[1] & 14) == 12){
            //instrução LDRB
            LDRB(vet, registradores, CPSR);
        }
        if((vet[1] & 14) == 14){
            //instrução LDRSH_pre
            LDRSH_pre(vet, registradores, CPSR);
        }

        break;

    case 11:
        //intruções SXTH | SXTB | UXTH | UXTB
        if(vet[1] == 2){
            //instrução SXTH
            if((vet[2] & 12) == 0){
                SXTH(vet, registradores, CPSR);    
            }
            //instrução SXTB
            if((vet[2] & 12) == 4){
                SXTB(vet, registradores, CPSR);    
            }
            //instrução UXTH
            if((vet[2] & 12) == 8){
                UXTH(vet, registradores, CPSR);    
            }
            //instrução UXTB
            if((vet[2] & 12) == 12){
                UXTB(vet, registradores, CPSR);    
            }
        }

        //intruções REV | REV16 | | REVSH
        if(vet[1] == 2){
            //instrução REV
            if((vet[2] & 12) == 0){
                REV(vet, registradores, CPSR);    
            }
            //instrução REV16
            if((vet[2] & 12) == 4){
                REV16(vet, registradores, CPSR);    
            }
            //instrução REVSH
            if((vet[2] & 12) == 12){
                REVSH(vet, registradores, CPSR);    
            }
        }

        //intruções PUSH | POP
        if((vet[1] & 6) == 4){
            //instrução PUSH
            if((vet[1] & 8) == 0){
                PUSH(vet, registradores, CPSR);    
            }
            //instrução POP
            if((vet[1] & 8) == 8){
                POP(vet, registradores, CPSR);    
            }
        }

        //intruções SETEND LE | SETEND BE
        if((vet[1] == 6) && (vet[2] == 5)){
            if((vet[3] & 8) == 0){
                //instrução SETEND_LE
                SETEND_LE(vet, registradores, CPSR);
            }
            if((vet[3] & 8) == 8){
                //instrução SETEND_BE
                SETEND_BE(vet, registradores, CPSR);
            }
        }

        //intruções CPSIE | CPSID
        if((vet[1] == 6) && (vet[2] == 6)){
            // instrução CPSIE
            CPSIE(vet, registradores, CPSR);
        }
        if((vet[1] == 6) && (vet[2] == 7)){
            // instrução CPSID
            CPSID(vet, registradores, CPSR);
        }

        break;

    case 12:
        //intruções STMIA | LDMIA
        if((vet[1] & 8) == 0){
            // instruçao STMIA 
            STMIA(vet, registradores, CPSR);
        }
        if((vet[1] & 8 ) == 8){
            //instruçao LDMIA
            LDMIA(vet, registradores, CPSR);
        }
        break;

    case 13:  
        if(vet[1] == 14)  {
            Undefined(vet, registradores, CPSR);
            break;
        }
    break;
    case 14:
        if((vet[1] >> 3) == 0){
            B_ponto(vet, registradores, CPSR);
            break;
        }
        break;
}

