#include <stdio.h>
#include <locale.h>

int main (){

    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int m, n;

    printf("Informe a quantidade de números do sorteio e da aposta, respectivamente (separados por espaço): ");
    scanf("%d %d", &m, &n);

    // condições de invalidação
    if (m > 30) {
        printf("Inválido. Não coloque mais que 30 números sorteados.");
    } else if (m > n) {
        printf("Inválido. Não digite mais números sorteados que apostados.");
    } else if (n > 50) {
        printf("Inválido. Não coloque mais que 50 números apostados.");
    } else { // condições em que é válido
        
        int sorteios[m], apostas[n];
        int acertos = 0;

        // lê e armazena os números no vetor sorteios
        printf("Informe os números sorteados: ");
        for (int i = 0; i < m; i++) {
            scanf("%d", &sorteios[i]);
        }

        // lê e armazena os números no vetor apostas
        printf("Informe os números apostados: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &apostas[i]);
        }

        // percorre o vetor de sorteios
        for (int i = 0; i < m; i++) {
            // percorre o vetor de apostas
            for (int j = 0; j < n; j ++) {
                // se o número nos dois vetores for igual, +1 acerto
                if (sorteios[i] == apostas[j]) {
                    acertos++;
                    // quebra o loop para passar para o próximo elemento do vetor sorteios
                    break;
                }
            }
        }
    
    printf("Acertos: %d\n", acertos);
    }

    return 0;
}