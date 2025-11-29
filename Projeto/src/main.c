#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define MINAS 5   // número de minas fixo no jogo

// FUNÇÕES DE ALOCAÇÃO

// aloca dinamicamente uma matriz int ** (lin x col)
int **alocaMatriz(int lin, int col) {
    int **m = malloc(lin * sizeof(int *));
    if (m == NULL) {
        printf("Erro: memória insuficiente.\n");
        exit(1);
    }

    for (int i = 0; i < lin; i++) {
        m[i] = malloc(col * sizeof(int));
        if (m[i] == NULL) {
            printf("Erro: memória insuficiente.\n");
            exit(1);
        }
    }

    return m;
}

// libera matriz alocada
void liberaMatriz(int **m, int lin) {
    for (int i = 0; i < lin; i++)
        free(m[i]);
    free(m);
}

// FUNÇÕES DO JOGO

// inicializa o campo com 0 e distribui minas (-1)
void inicializaCampo(int **campo, int lin, int col) {
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            campo[i][j] = 0;

    int minas_colocadas = 0;
    while (minas_colocadas < MINAS) {
        int i = rand() % lin;
        int j = rand() % col;

        if (campo[i][j] != -1) {
            campo[i][j] = -1;
            minas_colocadas++;
        }
    }
}

// conta minas adjacentes
int minasAdjacentes(int **campo, int lin, int col, int i, int j) {
    int cont = 0;

    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < lin && y >= 0 && y < col && !(x == i && y == j))
                if (campo[x][y] == -1)
                    cont++;
        }
    }

    return cont;
}

// imprime o campo
void imprimeCampo(int **campo, int **revelado, int **flag, int lin, int col) {
    printf("\n   ");
    for (int j = 0; j < col; j++)
        printf("%d ", j + 1);

    printf("\n");

    for (int i = 0; i < lin; i++) {
        printf("%d  ", i + 1);

        for (int j = 0; j < col; j++) {
            if (flag[i][j]) {
                printf("F ");   // F = flag
            }
            else if (!revelado[i][j]) {
                printf("- ");  // escondido
            }
            else if (campo[i][j] == -1) {
                printf("* ");  // mina
            }
            else {
                printf("%d ", campo[i][j]); // número
            }
        }
        printf("\n");
    }
    printf("\n");
}

// FUNÇÃO PRINCIPAL

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int lin = 5, col = 5;
    int **campo = alocaMatriz(lin, col);
    int **revelado = alocaMatriz(lin, col);
    int **flag = alocaMatriz(lin, col);

    // zera revelado e flag
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++) {
            revelado[i][j] = 0;
            flag[i][j] = 0;
        }

    inicializaCampo(campo, lin, col);

    char nome[50];
    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';  // remove '\n'

    printf("Bem-vindo, %s, ao Campo Minado!\n", nome);

    int jogadas_restantes = lin * col - MINAS;
    int linha, coluna;
    char comando;

    while (1) {
        imprimeCampo(campo, revelado, flag, lin, col);

        printf("Comandos:\n");
        printf("  r L C  -> revelar\n");
        printf("  f L C  -> marcar/desmarcar bandeira\n");
        printf("Ex: r 2 3\n");

        printf("Digite comando: ");
        scanf(" %c %d %d", &comando, &linha, &coluna);

        linha--; coluna--;

        if (linha < 0 || linha >= lin || coluna < 0 || coluna >= col) {
            printf("Posição inválida!\n");
            continue;
        }

        if (comando == 'f') {  // marca bandeira
            if (!revelado[linha][coluna]) {
                flag[linha][coluna] = !flag[linha][coluna];
                printf("Bandeira %s!\n", flag[linha][coluna] ? "colocada" : "removida");
            }
            continue;
        }

        if (comando == 'r') {  // revelar
            if (flag[linha][coluna]) {
                printf("Posição marcada como bandeira. Remova antes de revelar.\n");
                continue;
            }

            if (campo[linha][coluna] == -1) {
                printf("BOOM! Você acertou uma mina. Fim de jogo.\n");

                // revela todas as minas
                for (int i = 0; i < lin; i++)
                    for (int j = 0; j < col; j++)
                        if (campo[i][j] == -1)
                            revelado[i][j] = 1;

                imprimeCampo(campo, revelado, flag, lin, col);
                break;
            }

            revelado[linha][coluna] = 1;
            campo[linha][coluna] = minasAdjacentes(campo, lin, col, linha, coluna);
            jogadas_restantes--;

            if (jogadas_restantes == 0) {
                printf("Parabéns, %s! Você venceu!\n", nome);
                imprimeCampo(campo, revelado, flag, lin, col);
                break;
            }
        }
    }

    liberaMatriz(campo, lin);
    liberaMatriz(revelado, lin);
    liberaMatriz(flag, lin);

    return 0;
}