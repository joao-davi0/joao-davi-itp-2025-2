#include <stdio.h>
#include <locale.h>

int main(){

    setlocale (LC_ALL, "Portuguese"); //Separador decimal passa a ser a vírgula

    float valor;

    printf("Informe o valor da sua compra: ");
    scanf("%f", &valor);

    if (valor <= 100.0) {
        printf("Você não possui desconto.\n");
        printf("Valor a ser pago: R$ %.2f\n ", valor);

    } else if (valor > 100.0 && valor <= 500.0) {
        printf("Você possui 10 porcento de desconto.\n");
        printf("Valor a ser pago: R$ %.2f\n ", valor*0.9);

    } else if (valor > 500.0 && valor <= 1000.0) {
        printf("Você possui 15 porcento de desconto.\n");
        printf("Valor a ser pago: R$ %.2f\n ", valor*0.85);

    } else {
        printf("Você possui 20 porcento de desconto.\n");
        printf("Valor a ser pago: R$ %.2f\n ", valor*0.8);
    }


    return 0;
}