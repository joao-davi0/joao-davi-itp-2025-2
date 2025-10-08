#include <stdio.h>

int main () {

    float comp_f, larg_f, larg_b;
    int dobras = 0;

    printf("Digite o comprimento da folha (cm): ");
    scanf("%f", &comp_f);

    printf("Digite a largura da folha (cm): ");
    scanf("%f", &larg_f);

    printf("Digite a largura do bolso (cm): ");
    scanf("%f", &larg_b);

    while (comp_f >= larg_b && larg_f >= larg_b) {
        if (comp_f >= larg_f) {
            comp_f /= 2;
        }
        else {
            larg_f /= 2;
        }
        dobras ++;
    }

    printf("A folha precisa ser dobrada %d vezes para caber no bolso.\n ", dobras);

    return 0;
}