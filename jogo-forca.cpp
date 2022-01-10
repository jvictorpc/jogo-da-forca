#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

#define TAM_MAX 26

//variaveis globais
int chutesDados = 0;
char palavra_secreta[30];
char chutes[TAM_MAX];

void abertura(){
    printf("*********************************\n");
    printf("*       Jogo da Forca           *\n");
    printf("*********************************\n");
}

void capturaChute(){
    char chute; 
    printf("Chute uma letra da palavra: ");
    scanf(" %c", &chute); 

    chutes[chutesDados] = chute;
    chutesDados++;

}

int jaChutou (char letra){

    int achou  = 0;

    for(int j = 0; j < chutesDados; j++){
        if (chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca (){

    for (int i = 0; i < strlen(palavra_secreta); i++) {
       int achou = jaChutou(palavra_secreta[i]);
        if (achou){
            printf("%c ", palavra_secreta[i]);
        }else{
            printf("_ ");
        }
        
    }
    printf("\n");
}

void escolhePalavra( ){
    FILE *f;

    f = fopen("./palavras.txt", "r");

    if(f == 0){
        printf("Desculpe, banco de dados não disponivel");
        exit(1);
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);

    srand(time(0));
    int randomico = rand() % qtdPalavras;

    for (int i =0; i <= randomico; i++){
        fscanf(f, "%s", palavra_secreta);
    }

}

int enforcou (){
    int erros = 0;

    for ( int i = 0; i < chutesDados; i++){
        int existe = 0;

        for (int j =0; j < strlen(palavra_secreta); j++){
            if (chutes[i] == palavra_secreta[j]){
                existe = 1;
                break;
            }
        }
        if (!existe) erros++;
    }
    
    return erros >=5;
}

int acertou (){
    for (int i = 0 ; i < strlen(palavra_secreta); i++){
        if (!jaChutou(palavra_secreta[i])){
            return 0;
        }
    }

    return 1;
}

int main (){   

    escolhePalavra();
    abertura();

    do {
        desenhaForca();
        capturaChute();
    }while (!acertou() && !enforcou());

    return 0;
}