#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("*****************\n");
    printf("* Jogo de Forca *\n");
    printf("*****************\n");
}

void chuta() {
    char chute;
    printf("Qual letra?\n");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
}

int jachutou(char letra) {
    int achou = 0;
    for (int i = 0; i < chutesdados; ++i) {
        if(chutes[i] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {
    printf("Voce ja deu %d chutes\n", chutesdados);

    for (int i = 0; i < strlen(palavrasecreta); ++i) {
        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void adicionapalavra() {
    char quer;
    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N) ");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novapalavra[20];
        printf("Qual a palavra nova? ");
        scanf("%s", novapalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");
        if(f == 0){
            printf("Desculpe! banco de dados nao disponivel\n\n");
            exit(1);
        }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);
        fclose(f);
    }
}

void escolhepalavra() {
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe! banco de dados nao disponivel\n\n");
        exit(1);
    }

    int qtdepalavras;
    fscanf(f, "%d", &qtdepalavras);

    srand(time(0));
    int randomico = rand() % qtdepalavras;

    for (int i = 0; i <= randomico ; ++i) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

int acertou() {
    for (int i = 0; i < strlen(palavrasecreta); ++i) {
        if(!jachutou(palavrasecreta[i])) {
            return  0;
        }
    }
    return 1;
}

int enforcou() {
    
    int erros = 0;

    for (int i = 0; i < chutesdados; ++i) {
        int existe = 0;

        for (int j = 0; j < strlen(palavrasecreta); ++j) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros >= 5;
}

int main() {

//    setlocale(LC_ALL, "PORTUGUESE"); not work on CLion!!

    abertura();
    escolhepalavra();

    do {
        desenhaforca();
        chuta();
        chutesdados++;
    } while (!acertou() && !enforcou());

    adicionapalavra();
}
