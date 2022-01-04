#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abertura(){
    printf("*********************************\n");
    printf("*       Jogo da Forca           *\n");
    printf("*********************************\n");
}

void capturaChute(){
     char chute; 
        printf("Chute uma letra da palavra: ");
        scanf(" %c", &chute); 

        chutes[tentativas] = chute;
        
        tentativas++;

}

int main (){
    //palavra secreta representada por um vetor de 30 posições
    char palavra_secreta[30];

    // array de char para registrar os chutes feitos pelo usuário
    char chutes[26];

    //armazena a palavra "melancia" na variavel palavra_secreta
    sprintf(palavra_secreta, "bobo");

    //variáveis booleanas 0 para falso e 1 para verdadeiro
    int acertou = 0;
    int enforcou = 0;

    //registra a quantidade de tentativas feitas pelo usuário e 
    //também serve para indicar em qual posição do array está registrado o chute feito pelo usuário
    int tentativas = 0;

    abertura();

    //o loop deve acontecer pelo menos uma vez
    do {

        //1 - loop do tipo for que inicia com 0 e termina antes do tamanho maximo da palavra_secreta
        //2 - ele basicamente percorre a palavra_secreta, em busca de uma letra igual a que o usuário digitou
        //3 - caso a letra seja encontrada, a variável achou recebe o valor 1, caso não, permanece com o valor 0
        //4 - com base nisso se imprime a letra correspondente ou um "_" correspondente a um caractere não encontrado.
        //5 - imprime primeiro os espaços em branco pra depois perguntar qual o chute do usuário, já que o numero de tentativas no inicio do loop é 0


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

        capturaChute(&chutes);

    }while (!acertou && !enforcou);

    return 0;
}