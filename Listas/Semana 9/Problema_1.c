#include<stdio.h>
#include<locale.h>

int main() {

    // para ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int M, N;

    printf("Digite a quantidade de linhas e colunas, respectivamente: ");
    scanf("%d %d", &M, &N);

    // validação de entrada
    if (M > 10 || N > 10) {
        printf("Entrada inválida.\n");
    } else {

        int campo[M][N], setoresIrrigados = 0, setoresSecos = 0;

        // lê os valores da matriz
        printf("Digite os setores do campo:\n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &campo[i][j]);
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // para a primeira linha, +1 setor irrigado se o que estiver abaixo for um irrigador
                if (((i == 0) && (campo[0][j] == 1)) && (campo[i+1][j] == 2))
                    setoresIrrigados++;
                // se o setor abaixo não for irrigador, +1 setor seco
                else if (((i == 0) && (campo[0][j] == 1)) && (campo[i+1][j] != 2))
                    setoresSecos++;

                // para a última linha, +1 setor irrigado se o que estiver acima for um irrigador
                if (((i == M-1) && (campo[M-1][j] == 1)) && (campo[M-2][j] == 2))
                    setoresIrrigados++;
                // se o setor acima não for irrigador, +1 setor seco
                else if (((i == M-1) && (campo[M-1][j] == 1)) && (campo[M-2][j] != 2))
                    setoresSecos++;

                // para as demais linhas
                if (i > 0 && i < M-1) {
                    // para a primeira coluna, +1 setor irrigado se o que estiver à direita for um irrigador
                    if (((j == 0) && (campo[i][0] == 1)) && (campo[i][j+1] == 2))
                        setoresIrrigados++;
                    // se o setor à direita não for irrigador, +1 setor seco
                    else if (((j == 0) && (campo[i][0] == 1)) && (campo[i][j+1] != 2))
                        setoresSecos++;

                    // para a última coluna, +1 setor irrigado se o que estiver à esquerda for um irrigador
                    if (((j == N-1) && (campo[i][N-1] == 1)) && (campo[i][N-2] == 2))
                        setoresIrrigados++;
                    // se o setor à esquerda não for irrigador, +1 setor seco
                    else if (((j == N-1) && (campo[i][N-1] == 1)) && (campo[i][N-2] != 2))
                        setoresSecos++;

                    // para as demais colunas, verifica acima, abaixo, na esquerda e na direita,
                    // pois não há risco de acessar um valor fora da matriz
                    else if (((j > 0 && j < N-1) && (campo[i][j] == 1)) &&
                    (((campo[i-1][j] == 2) || (campo[i][j+1] == 2)) || ((campo[i+1][j] == 2) || (campo[i][j-1] == 2))))
                        setoresIrrigados++;
                    else if (((j > 0 && j < N-1) && (campo[i][j] == 1)) &&
                    (((campo[i-1][j] != 2) && (campo[i][j+1] != 2)) && ((campo[i+1][j] != 2) && (campo[i][j-1] != 2))))
                        setoresSecos++;
                }
            }
        }

        printf("%d %d\n", setoresIrrigados, setoresSecos);
    }

    return 0;
}