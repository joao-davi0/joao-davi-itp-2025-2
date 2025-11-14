#include<stdio.h>
#include<locale.h>

int main(){

    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int n;

    printf("Quantidade de pilotos na corrida: ");
    scanf("%d", &n);

    // validação de entrada
    if (n < 1 || n > 20) {
        printf("Quantidade de pilotos inválida.\n");
    } else {

        int largada[n], chegada[n], posGanhas[n+1];
        int i, k, piloto;

        printf("Ordem de largada: ");
        for (i = 0; i < n; i++)
            scanf("%d", &largada[i]);

        printf("Ordem de chegada: ");
        for (i = 0; i < n; i++)
            scanf("%d", &chegada[i]);

        for (int j = 0; j < n; j++) {
            piloto = largada[j];
            int posLargada = j+1;

            for (k = 0; k < n; k++) {
                if (piloto == chegada[k]) {
                    int posChegada = k+1;

                    posGanhas[piloto] = posLargada - posChegada;
                    break;
                }

            }
        }

        int pilotoVencedor = 1;
        int maiorGanho = posGanhas[1];

        for (piloto = 2; piloto <= n; piloto++){
            if (posGanhas[piloto] > maiorGanho) {
                maiorGanho = posGanhas[piloto];
                pilotoVencedor = piloto;
            }

        }

        int empate = 0;

        for (piloto = 1; piloto <= n; piloto++) {
            if (piloto != pilotoVencedor && posGanhas[piloto] == maiorGanho) {
                empate = 1;
                break;
            }
        }

        if (empate)
            printf("Empate.\n");
        else
            printf("%d", pilotoVencedor);
    }

    return 0;
}