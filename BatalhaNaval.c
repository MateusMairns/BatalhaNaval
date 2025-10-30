#include <stdio.h>

int main() {
    // ---------- 1. Declaração de variáveis ----------
    int TAM = 10;        // Tamanho do tabuleiro (10x10)
    int AGUA = 0;        // Representa água
    int OCUPADO = 3;     // Representa parte de um navio
    int NAVIO = 3;       // Tamanho dos navios pequenos

    int tabuleiro[10][10];  // Matriz do tabuleiro
    int i, j;

    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'}; // Linhas
    int numeros[10] = {1,2,3,4,5,6,7,8,9,10};                    // Colunas
    // ---------- 2. Inicializa o tabuleiro com água ----------
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ---------- 3. Coordenadas iniciais dos navios ----------
    int linhaH = 2, colH = 3;  // Navio horizontal
    int linhaV = 4, colV = 5;  // Navio vertical

    // ---------- 4. Validação dos limites ----------
    if (colH + NAVIO > TAM || linhaV + NAVIO > TAM) {
        printf("Erro: navios fora dos limites do tabuleiro!\n");
        return 0;
    }

    // ---------- 5. Posicionamento dos navios ----------
    // Navio Horizontal →
    for (i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colH + i] = OCUPADO;
    }

    // Navio Vertical ↓
    for (i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colV] = OCUPADO;
    }

    // ---------- 6. Navios diagonais completos ----------
    // Diagonal principal ↘ (A1 até J10)
    for (i = 0; i < TAM; i++) {
        tabuleiro[i][i] = OCUPADO;
    }

    // Diagonal secundária ↙ (A10 até J1)
    for (i = 0; i < TAM; i++) {
        tabuleiro[i][TAM - 1 - i] = OCUPADO;
    }

    // ---------- 7. Exibe o tabuleiro ----------
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    // Cabeçalho das colunas
    printf("     ");
    for (j = 1; j <= TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Linhas com letras
    for (i = 0; i < TAM; i++) {
        printf("%c | ", letras[i]);
        for (j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}