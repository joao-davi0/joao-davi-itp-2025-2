#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define LIN 5 // número de linhas
#define COL 5 // número de colunas
#define MINAS 5 // número de minas

// inicializa o campo com 0 e posiciona as minas (-1)
void inicializaCampo(int campo[LIN][COL]) {
    for (int i = 0; i < LIN; i++)
        for (int j = 0; j < COL; j++)
            campo[i][j] = 0;

    int minas_colocadas = 0;
    while (minas_colocadas < MINAS) {
        int i = rand() % LIN;
        int j = rand() % COL;
        if (campo[i][j] != -1) {
            campo[i][j] = -1;
            minas_colocadas++;
        }
    }
}

// imprime o campo para o jogador
void imprimeCampo(int campo[LIN][COL], int revelado[LIN][COL]) {
    printf("Campo:\n");
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (revelado[i][j]) {
                if (campo[i][j] == -1)
                    printf("* ");
                else
                    printf("%d ", campo[i][j]);
            } else
                printf("- ");
        }
        printf("\n");
    }
}

// conta minas adjacentes
int minasAdjacentes(int campo[LIN][COL], int linha, int col) {
    int cont = 0;
    for (int i = linha - 1; i <= linha + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < LIN && j >= 0 && j < COL && !(i == linha && j == col))
                if (campo[i][j] == -1)
                    cont++;
        }
    }
    return cont;
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // para ajuste da acentuação nos printfs
    int campo[LIN][COL];
    int revelado[LIN][COL] = {0};
    int linha, col;
    int jogadas_restantes = LIN * COL - MINAS;
    int ganhou = 0;

    srand(time(NULL));

    inicializaCampo(campo);

    printf("Bem-vindo ao Campo Minado!\n");
    printf("Escolha linhas e colunas de 1 a %d para revelar.\n", LIN);

    while (!ganhou) {
        imprimeCampo(campo, revelado);

        printf("Digite a linha e a coluna que deseja revelar separadas por espaço (1 a %d): ", LIN);
        scanf("%d %d", &linha, &col);

        // Ajusta para índice do vetor (0 a 4)
        linha--;
        col--;

        if (linha < 0 || linha >= LIN || col < 0 || col >= COL) {
            printf("Posição inválida! Tente novamente.\n");
            continue;
        }

        if (revelado[linha][col]) {
            printf("Posição já revelada! Tente outra.\n");
            continue;
        }

        if (campo[linha][col] == -1) {
            printf("BOOM! Você acertou uma mina. Fim de jogo.\n");
            // revela todas as minas
            for (int i = 0; i < LIN; i++)
                for (int j = 0; j < COL; j++)
                    if (campo[i][j] == -1) revelado[i][j] = 1;
            imprimeCampo(campo, revelado);
            break;
        } else {
            campo[linha][col] = minasAdjacentes(campo, linha, col);
            revelado[linha][col] = 1;
            jogadas_restantes--;
            if (jogadas_restantes == 0) {
                printf("Parabéns! Você venceu!\n");
                ganhou = 1;
                imprimeCampo(campo, revelado);
            }
        }
    }

    return 0;
}