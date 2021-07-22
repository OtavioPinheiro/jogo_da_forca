# Jogo da forca.
## Objetivo
O objetivo desse programa é praticar os conhecimentos da linguagem C implementando um jogo da forca.

## Sumário

## Informações
### Manipulando arquivos em C
#### Funções
- `fscanf()`: Utilizada para ler caracteres ASCII e *strings* de um arquivo.
  
  **Exemplo:**
    ```c
    int n1, n2;

    int sucesso = fscanf("%d %d", &n1, &n2);
    if(sucesso == 2) {
        printf("Os dois números: %d e %d", n1, n2);
    }
    else {
        printf("Aconteceu um erro");
    }
    ```
  **FONTE:** ALURA.<br><br>
- `fprintf()`: Utilizada para escrever caracteres ASCII e *strings* em um arquivo.
- `feof()`: Utilizada para verificar se o ponteiro do arquivo já chegou ao final.
  
    **Exemplo:**
  ```c
  FILE* f;
  char c;
    
  f = fopen("arquivo.txt", "r");
  while(!feof(f)) {
    c = fgetc(f);    
    printf("Char %c\n", c);
  }
  ```
  **FONTE:** ALURA.<br><br>
- `fgetc()`: Utilizada para ler apenas o próximo *char* do arquivo.
- `fread()`: Utilizada para ler uma quantidade específica de bytes de um arquivo.
- `fwrite()`: Utilizada para escrever uma quantidade específica de bytes em um arquivo.