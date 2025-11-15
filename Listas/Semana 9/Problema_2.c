#include<stdio.h>
#include<locale.h>

int main() {

    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int M;

    printf("Quantidade de usuários: ");
    scanf("%d", &M);

    int mat[M][M];

    // leitura da matriz
    printf("Digite a matriz:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int x;

    printf("Sugestões para qual usuário?\n");
    scanf("%d", &x);

    int sugere[M];     // vetor de sugestões
    for (int i = 0; i < M; i++)
        sugere[i] = 0;

    // percorre todos os usuários b
    for (int b = 0; b < M; b++) {

        if (b == x) continue;           // não pode sugerir a si mesmo
        if (mat[x][b] == 1) continue;   // já são amigos, não sugerir

        // verifica se há amigos em comum
        for (int k = 0; k < M; k++) {
            if (mat[x][k] == 1 && mat[b][k] == 1) {
                sugere[b] = 1;
                break;    
            }
        }
    }

    // imprime sugestões em ordem crescente
    for (int i = 0; i < M; i++) {
        if (sugere[i] == 1)
            printf("%d ", i);
    }

    return 0;
}