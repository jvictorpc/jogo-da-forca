#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

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
    int erros = chutesErrados();
    
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

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

void adicionaPalavra(){
    char quer;

    printf("Voce deseja adicionar outra palavra ao banco de dados? (s/n)");
    scanf(" %c", &quer);

    if(quer == 's'){
        system("cls");

        char nova_palavra[TAM_MAX];

        printf("Informe qual a palavra que vc deseja adicionar: ");
        scanf("%s", nova_palavra);

        FILE* arquivo;

        arquivo = fopen("palavras.txt", "r+");

        if(arquivo == 0){
            printf("desculpe, tivemos um problema no banco de dados.");
            exit(1);
        }

        int qtd_palavras;

        fscanf(arquivo,"%d", &qtd_palavras);
        qtd_palavras++;

        fseek(arquivo,0, SEEK_SET);
        fprintf(arquivo, "%d", qtd_palavras);

        fseek(arquivo, 0, SEEK_END);
        fprintf(arquivo, "\n%s", nova_palavra);

        fclose(arquivo);
    }


}

int chutesErrados(){
     int erros = 0;

    for ( int i = 0; i < chutesDados; i++){
        int existe = 0;
       
        if (!jaChutou(chutes[i])) erros++;
    }

    return erros;
}
int enforcou (){
    
    return chutesErrados() >=5;
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

   if(acertou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

    } else {
        printf("\nPuxa, voce foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavra_secreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionaPalavra();

    return 0;
}