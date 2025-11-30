#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int *alocarVetor(int n) {
    return (int *) malloc(n * sizeof(int));
}

int *somaVetores(int *u, int *v, int n1, int n2) {
    // verifica se as dimensões são compatíveis
    if (n1 != n2)
        return NULL;

    // aloca o vetor resultado
    int *resultado = alocarVetor(n1);

    for (int i = 0; i < n1; i++)
        resultado[i] = u[i] + v[i];

    return resultado;
}

int main() {
    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    // alocação dinâmica dos vetores
    int *u = alocarVetor(n1);
    int *v = alocarVetor(n2);

    // lendo u
    for (int i = 0; i < n1; i++)
        scanf("%d", &u[i]);

    // lendo v
    for (int i = 0; i < n2; i++)
        scanf("%d", &v[i]);

    int *soma = somaVetores(u, v, n1, n2);

    // verifica se houve erro (dimensões incompatíveis) 
    if (soma == NULL) {
        printf("Dimensões incompatíveis.\n");
    } else {
        for (int i = 0; i < n1; i++)
            printf("%d ", soma[i]);
        printf("\n");
        free(soma);     // libera a memória do vetor soma
    }

    // liberando os espaços de memória
    free(u);
    free(v);

    return 0;
}