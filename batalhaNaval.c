#include <stdio.h>

int main() {
    char colunaLetra[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];
    int i, j;
    char letra;
    int numero;

    // 1. Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Coloca alguns navios manualmente (1 = navio)
    tabuleiro[1][3] = 1;
    tabuleiro[4][7] = 1;
    tabuleiro[7][2] = 1;
    tabuleiro[2][8] = 1;
    tabuleiro[6][5] = 1;

    int acertos = 0;
    int tentativas = 5;

    // 3. Laço do jogo (5 tiros)
    for (int rodada = 1; rodada <= tentativas; rodada++) {
        // Mostra o tabuleiro
        printf("\n=== TABULEIRO BATALHA NAVAL ===\n");
        printf("   ");
        for (j = 0; j < 10; j++) {
            printf(" %c", colunaLetra[j]);
        }
        printf("\n");

        for (i = 0; i < 10; i++) {
            printf("%2d ", i + 1);
            for (j = 0; j < 10; j++) {
                if (tabuleiro[i][j] == 2)
                    printf(" X"); // acerto
                else if (tabuleiro[i][j] == -1)
                    printf(" O"); // erro
                else
                    printf(" 0"); // água não revelada
            }
            printf("\n");
        }

        // 4. Jogador escolhe o tiro
        printf("\nTiro %d de %d\n", rodada, tentativas);
        printf("Digite a coordenada (ex: C5): ");
        scanf(" %c%d", &letra, &numero);

        int coluna = letra - 'A';
        int linha = numero - 1;

        if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
            printf("  Coordenada inválida! Tente novamente.\n");
            rodada--; // não conta tentativa inválida
            continue;
        }

        if (tabuleiro[linha][coluna] == 1) {
            printf(" Acertou um navio!\n");
            tabuleiro[linha][coluna] = 2;
            acertos++;
        } else if (tabuleiro[linha][coluna] == 0) {
            printf(" Água!\n");
            tabuleiro[linha][coluna] = -1;
        } else {
            printf(" Você já atirou aqui!\n");
            rodada--; // não conta tiro repetido
        }

        // Se acertar todos os navios, encerra
        if (acertos == 5) {
            printf("\n Você afundou todos os navios! Parabéns!\n");
            break;
        }
    }

    // 5. Fim do jogo
    printf("\n=== FIM DE JOGO ===\n");
    printf("Você acertou %d navios!\n", acertos);

    // Mostra o tabuleiro final
    printf("\n   ");
    for (j = 0; j < 10; j++) {
        printf(" %c", colunaLetra[j]);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 2)
                printf(" X");
            else if (tabuleiro[i][j] == -1)
                printf(" O");
            else if (tabuleiro[i][j] == 1)
                printf(" N"); // mostra onde estavam os navios
            else
                printf(" 0");
        }
        printf("\n");
    }

    return 0;
}