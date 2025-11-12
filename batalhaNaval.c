#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <ctype.h> 

#define TAMANHO 5
#define NUM_NAVIOS 3

/**
 * @brief 
 */
void inicializarTabuleiros(int logica[TAMANHO][TAMANHO], char visivel[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            logica[i][j] = 0;  
            visivel[i][j] = '~';
        }
    }
}

/**
 * @brief 
 */
void mostrarTabuleiro(char visivel[TAMANHO][TAMANHO]) {
    printf("\n   "); 

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d  ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", visivel[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief 
 */
void posicionarNavios(int logica[TAMANHO][TAMANHO]) {
    int naviosPosicionados = 0;
    int linha, coluna;

    while (naviosPosicionados < NUM_NAVIOS) {
        linha = rand() % TAMANHO; 
        coluna = rand() % TAMANHO;

      
        if (logica[linha][coluna] == 0) {
            logica[linha][coluna] = 1;
            naviosPosicionados++;

        }
    }
}
/**
 * @brief 
 */
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    int tabuleiroLogica[TAMANHO][TAMANHO];
    char tabuleiroVisivel[TAMANHO][TAMANHO];

    int linha, coluna;
    int naviosAbatidos = 0;
    int tentativas = 0;
    
    srand(time(NULL)); 
    inicializarTabuleiros(tabuleiroLogica, tabuleiroVisivel);
    posicionarNavios(tabuleiroLogica);

    printf("--- BEM-VINDO À BATALHA NAVAL (Simples) ---\n");
    printf("Tente afundar os %d navios escondidos no tabuleiro %dx%d.\n", NUM_NAVIOS, TAMANHO, TAMANHO);


    while (naviosAbatidos < NUM_NAVIOS) {
        mostrarTabuleiro(tabuleiroVisivel);
        
        printf("Digite as coordenadas (linha e coluna) para atirar (ex: 1 3): ");
        

        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("\nEntrada inválida! Digite dois números separados por espaço.\n");
            limparBufferEntrada();
            continue; 
        }


        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("\nCoordenadas fora do tabuleiro! Tente de 0 a %d.\n", TAMANHO - 1);
            continue;

        if (tabuleiroVisivel[linha][coluna] != '~') {
            printf("\nVocê já atirou aí! Tente outro local.\n");
            continue;
        }

  
        tentativas++;
        if (tabuleiroLogica[linha][coluna] == 1) {

            printf("\n*** FOGO! *** Você acertou um navio!\n");
            tabuleiroVisivel[linha][coluna] = 'X'; 
            naviosAbatidos++;
        } else {
       
            printf("\n--- ÁGUA! --- Você errou.\n");
            tabuleiroVisivel[linha][coluna] = 'O'; 
        }
    }

    printf("\n=============================================\n");
    printf("PARABÉNS! Você afundou todos os %d navios!\n", NUM_NAVIOS);
    printf("Você precisou de %d tentativas.\n", tentativas);
    printf("=============================================\n");
    
    mostrarTabuleiro(tabuleiroVisivel);

    return 0;
}