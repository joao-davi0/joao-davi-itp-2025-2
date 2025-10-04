#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); //Separador decimal passa a ser a v�rgula

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
        printf("Os valores informados n�o formam um tri�ngulo.\n ");
    } else {
        float a, b, c;

        //Defini��o do maior lado
        if (l1 >= l2 && l1 >= l3) {
            a = l1, b = l2, c = l3;
        } else if (l2 >= l1 && l2 >= l3) {
            a = l2, b = l1, c = l3;
        } else if (l3 >= l1 && l3 >= l2) {
            a = l3, b = l1, c = l2;
        }

        //Classifica��o quanto aos lados
        if (l1 == l2 && l2 == l3) {
            printf("Os lados formam um tri�ngulo equil�tero.\n");
        } else if (l1 == l2 || l2 == l3 || l1 == l3) {
            printf("Os lados formam um tri�ngulo is�sceles.\n");
        } else {
            printf("Os lados formam um tri�ngulo escaleno.\n");
        } 

        //Classifica��o quanto aos �ngulos
        if ((a * a) == (b * b) + (c * c)) {
            printf("O tri�ngulo � ret�ngulo.\n ");
        } else if ((a * a) < (b * b) + (c * c)) {
            printf("O tri�ngulo � acut�ngulo.\n ");
        } else {
            printf("O tri�ngulo � obtus�ngulo.\n ");
        }
    }

    return 0;
}