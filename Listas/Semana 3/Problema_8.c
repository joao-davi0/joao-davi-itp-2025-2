#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); //Separador decimal passa a ser a vírgula

    float l1, l2, l3;

    printf("Digite o valor do primeiro lado: ");
    scanf("%f", &l1);

    printf("Digite o valor do segundo lado: ");
    scanf("%f", &l2);

    printf("Digite o valor do terceiro lado: ");
    scanf("%f", &l3);

    if (l1 <= 0.0 || l2 <= 0.0 || l3 <= 0.0) {
        printf("Digite apenas valores positivos.\n ");
    } else if (((l1 + l2) <= l3) || ((l2 + l3) <= l1) || ((l1 + l3) <= l2)) {
        printf("Os valores informados não formam um triângulo.\n ");
    } else {
        float a, b, c;

        //Definição do maior lado
        if (l1 >= l2 && l1 >= l3) {
            a = l1, b = l2, c = l3;
        } else if (l2 >= l1 && l2 >= l3) {
            a = l2, b = l1, c = l3;
        } else if (l3 >= l1 && l3 >= l2) {
            a = l3, b = l1, c = l2;
        }

        //Classificação quanto aos lados
        if (l1 == l2 && l2 == l3) {
            printf("Os lados formam um triângulo equilátero.\n");
        } else if (l1 == l2 || l2 == l3 || l1 == l3) {
            printf("Os lados formam um triângulo isósceles.\n");
        } else {
            printf("Os lados formam um triângulo escaleno.\n");
        } 

        //Classificação quanto aos ângulos
        if ((a * a) == (b * b) + (c * c)) {
            printf("O triângulo é retângulo.\n ");
        } else if ((a * a) < (b * b) + (c * c)) {
            printf("O triângulo é acutângulo.\n ");
        } else {
            printf("O triângulo é obtusângulo.\n ");
        }
    }

    return 0;
}