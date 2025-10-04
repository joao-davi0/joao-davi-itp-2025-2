#include <stdio.h>
#include <math.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); //Separador decimal passa a ser a vírgula

    float a;

    printf("Digite o valor de a: ");
    scanf("%f", &a);

    if (a == 0.0) {
        printf("Esta não é uma equação do 2º grau.\n ");

    } else {
        float b, c, delta, raiz1, raiz2;

        printf("Digite o valor de b: ");
        scanf("%f", &b);

        printf("Digite o valor de c: ");
        scanf("%f", &c);

        delta = (b * b) - (4 * a * c);
        raiz1 = ((-b + sqrt(delta)) / (2 * a));
        raiz2 = ((-b - sqrt(delta)) / (2 * a));

        if (delta < 0) {
            printf("A equação não possui raízes reais.\n ");

        } else if (delta == 0) {
            printf("A raíz real é %.2f\n ", raiz1);

        } else {
            printf("As raízes reais são %.2f e %.2f\n ", raiz1, raiz2);
        }
    }


    return 0;
}