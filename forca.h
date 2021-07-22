#ifndef JOGO_DA_FORCA_FORCA_H
#define JOGO_DA_FORCA_FORCA_H
#define TAMANHO_PALAVRA 20
void chuta();
int jachutou(char letra);
void desenhaforca();
void adicionapalavra();
void escolhepalavra();
int acertou();
int enforcou();
int chuteserrados();
char* exibeBonecoSeMaiorQue(int erros, int chutes, char* parteBoneco);
#endif //JOGO_DA_FORCA_FORCA_H
