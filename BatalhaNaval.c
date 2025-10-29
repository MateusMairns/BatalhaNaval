#include <stdio.h>

int main() {
    int TAM = 10;        // Tamanho do tabuleiro
    int AGUA = 0;        // Representa água
    int OCUPADO = 3;     // Representa parte de um navio
    int NAVIO = 3;       // Tamanho dos navios (3 posições)

    int tabuleiro[10][10]; // Matriz do tabuleiro
    int i, j;

    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'}; // Linhas
    int numeros[10] = {1,2,3,4,5,6,7,8,9,10};                    // Colunas

    // ---------- 1. Inicializa o tabuleiro com água ----------
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ---------- 2. Declaração dos navios ----------
    int navioHorizontal[3] = {OCUPADO, OCUPADO, OCUPADO};
    int navioVertical[3]   = {OCUPADO, OCUPADO, OCUPADO};

    // ---------- 3. Coordenadas iniciais dos navios ----------
    int linhaH = 2;  // Linha inicial do navio horizontal (C)
    int colH   = 4;  // Coluna inicial do navio horizontal (coluna 5)

    int linhaV = 5;  // Linha inicial do navio vertical (F)
    int colV   = 7;  // Coluna inicial do navio vertical (coluna 8)

    // ---------- 4. Validação simples para evitar sair dos limites ----------
    if (colH + NAVIO > TAM || linhaV + NAVIO > TAM) {
        printf("Erro: navios fora dos limites do tabuleiro!\n");
        return 1;
    }

    // ---------- 5. Posicionamento do navio horizontal ----------
    for (i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colH + i] = navioHorizontal[i];
    }

    // ---------- 6. Posicionamento do navio vertical ----------
    for (i = 0; i < NAVIO; i++) {
        if (tabuleiro[linhaV + i][colV] == OCUPADO) {
            printf("Erro: sobreposição de navios detectada!\n");
            return 1;
        }
        tabuleiro[linhaV + i][colV] = navioVertical[i];
    }

    // ---------- 7. Exibe o tabuleiro com letras e números ----------
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    // Cabeçalho das colunas
    printf("   ");
    for (j = 0; j < TAM; j++) {
        printf("%2d ", numeros[j]);
    }
    printf("\n");

    // Linhas com letras
    for (i = 0; i < TAM; i++) {
        printf("%c: ", letras[i]);
        for (j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}

