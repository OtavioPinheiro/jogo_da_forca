#include <stdio.h>
#include <string.h>
#include <locale.h>

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura() {
    printf("*****************\n");
    printf("* Jogo de Forca *\n");
    printf("*****************\n");
}

void chuta() {
    char chute;
    printf("Qual letra?\n");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
}

int jachutou(char letra) {
    int achou = 0;
    for (int i = 0; i < tentativas; ++i) {
        if(chutes[i] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {
    printf("Voce ja deu %d chutes\n", tentativas);

    for (int i = 0; i < strlen(palavrasecreta); ++i) {
        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
}

int main() {
    int acertou = 0;
    int enforcou = 0;

//    setlocale(LC_ALL, "PORTUGUESE"); not work on CLion!!

    abertura();
    escolhepalavra();

    do {
        desenhaforca();
        chuta();
        tentativas++;
    } while (!acertou && !enforcou);
}
