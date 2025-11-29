#include<stdio.h>
#include<locale.h>

int main () {

    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int m;
    
    printf("Quantos times?\n");
    scanf("%d", &m);

    // validação de entrada
    if (m > 20) {
        printf("Entrada inválida.");

    } else {
        int resultados[m][m], i, j, empates = 0;

        // leitura da matriz
        printf("Informe os resultados dos jogos:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &resultados[i][j]);
            }
        }

        // contando os empates
        for (int k = 0; k < m; k++) {
            for (int l = 0; l < m; l++) {
                if (resultados[k][l] == resultados[l][k])
                    empates++;
            }
        }

        // - m para excluir as diagonais
        // div. por 2 porque os empates são contados 2 vezes
        printf("Houveram %d empates.\n", (empates - m) / 2);
    }

    return 0;
}