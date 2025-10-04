#include <stdio.h>
#include <math.h>

int main () {

    float m, c, taxa;
    int tempo;

    printf("Informe seu capital inicial: ");
    scanf ("%f", &c);

    printf("Informe o percentual de juros: ");
    scanf("%f", &taxa);

    printf("Indique o tempo em anos: ");
    scanf("%d", &tempo);

    m = c * (pow(1 + taxa/100, tempo));

    printf("Montante final: %.2f\n", m);


    return 0;
}