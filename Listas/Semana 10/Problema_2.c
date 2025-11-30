#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// A função retorna um vetor dinâmico contendo os índices
int *buscaNoVetor(int *v, int n, int valor, int *qtd) {

    *qtd = 0;  // inicia a quantidade com zero

    // conta quantas vezes o valor aparece
    for (int i = 0; i < n; i++) {
        if (v[i] == valor)
            (*qtd)++;
    }

    // se não houve ocorrências, retorna NULL
    if (*qtd == 0)
        return NULL;

    // caso exista pelo menos uma ocorrência, aloca vetor de índices
    int *indices = (int*) malloc((*qtd) * sizeof(int));

    int pos = 0;

    // guarda os índices
    for (int i = 0; i < n; i++) {
        if (v[i] == valor) {
            indices[pos] = i;
            pos++;
        }
    }

    return indices;
}

int main() {
    // para ajuste de acentuação
    setlocale(LC_ALL,"Portuguese");

    int n;
    scanf("%d", &n);

    // aloca vetor v
    int *v = (int*) malloc(n * sizeof(int));

    // lê valores do vetor
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int valor;
    scanf("%d", &valor);

    int qtd;

    // chama a função que retorna o vetor de índices
    int *indices = buscaNoVetor(v, n, valor, &qtd);

    // caso não existam ocorrências
    if (indices == NULL) {
        printf("Nenhuma ocorrência.\n");
    }
    else {
        // imprime quantidade
        printf("%d\n", qtd);

        // imprime índices
        for (int i = 0; i < qtd; i++)
            printf("%d ", indices[i]);
        printf("\n");

        // libera o vetor de índices
        free(indices);
    }

    // libera vetor principal
    free(v);

    return 0;
}