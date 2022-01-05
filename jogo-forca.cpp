#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 26

void abertura(){
    printf("*********************************\n");
    printf("*       Jogo da Forca           *\n");
    printf("*********************************\n");
}

void capturaChute(char *chutes,int tentativas){
     char chute; 
        printf("Chute uma letra da palavra: ");
        scanf(" %c", &chute); 

        chutes[tentativas] = chute;

}

int main (){
   
    char palavra_secreta[30];

    char chutes[TAM_MAX];

    sprintf(palavra_secreta, "bobo");

    
    int acertou = 0;
    int enforcou = 0;

   
    int tentativas = 0;

    abertura();

    do {

        for (int i = 0; i < strlen(palavra_secreta); i++) {

            int achou  = 0;

            for(int j = 0; j < tentativas; j++){
                if (chutes[j] == palavra_secreta[i]){
                    achou = 1;
                    break;
                }
            }
            if (achou){
                printf("%c ", palavra_secreta[i]);
            }else{
                printf("_ ");
            }
            
        }

        printf("\n");

        capturaChute(chutes, tentativas);
        tentativas++;

    }while (!acertou && !enforcou);

    return 0;
}