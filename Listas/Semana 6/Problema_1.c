#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("Digite o número de questões: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Número de questões inválido.\n");
        return 1;
    }

    int gabarito[n], respostas[n];
    int acertos = 0;

    printf("Digite as respostas do gabarito: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &gabarito[i]);
    }

    printf("Digite as respostas do aluno: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &respostas[i]);
    }

    // Contagem de acertos
    for (int i = 0; i < n; i++) {
        if (respostas[i] == gabarito[i]) {
            acertos++;
        }
    }

    // Exibe o resultado com singular ou plural corretamente
    if (acertos == 1) {
        printf("1 acerto\n");
    } else {
        printf("%d acertos\n", acertos);
    }

    return 0;
}