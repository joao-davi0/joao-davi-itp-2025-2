#include<stdio.h>
#include<locale.h>

int main () {

    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int m;

    printf("Tamanho da matriz: ");
    scanf("%d", &m);

    // validação de entrada
    if (m > 10) {
        printf("Entrada inválida.\n");
    
    } else {
        int precos[m][m], x, z;

        // leitura da matriz
        printf("Digite os preços:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &precos[i][j]);
            } 
        }

        printf("Informe a origem e o destino da viagem, respectivamente:\n");
        scanf("%d %d", &x, &z);

        int menor_preco = precos[x][z];         // assume que o menor preço é o da viagem direta
        int melhor_y = -1;                      // possível cidade intermediária

        // testando para todas as possíveis cidades intermediárias y
        for (int y = 0; y < m; y++) {
            if (y == x || y == z)
                continue;

            // verifica se existe voo para a cidade
            if (precos[x][y] > 0 && precos[y][z] > 0) {
                int custo = precos[x][y] + precos[y][z];
                if (menor_preco == 0 || custo < menor_preco) {
                    // se existir uma rota mais barata, atualiza o menor preço
                    menor_preco = custo;
                    melhor_y = y;
                }
            }
        }

        if (melhor_y == -1) {
            // sem cidade intermediária
            printf("%d-%d R$%d\n", x, z, menor_preco);
        } else {
            // com cidade intermediária
            printf("%d-%d-%d R$%d\n", x, melhor_y, z, menor_preco);
        }
    }

    return 0;
}