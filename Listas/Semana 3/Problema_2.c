#include <stdio.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "Portuguese"); //Lembrete: separador decimal passa a ser a vírgula

    float consumo;
    char tipo;

    printf ("Digite o consumo (kWh): ");
    scanf ("%f", &consumo);

    printf ("Informe o tipo de consumidor (R para residencial, C para comercial e I para industrial): ");
    scanf (" %c", &tipo);

    if (tipo == 'R' || tipo == 'r') { //Para aceitar letras maiúsculas ou minúsculas
        printf ("Valor total a ser pago: R$ %.2f\n ", (consumo * 0.6) + 15.0);
    } else if (tipo == 'C' || tipo == 'c') {
        printf ("Valor total a ser pago: R$ %.2f\n ", (consumo * 0.48) + 15.0);
    } else if (tipo == 'I' || tipo == 'i') {
        printf ("Valor total a ser pago: R$ %.2f\n ", (consumo * 1.29) + 15.0);
    } else {
        printf ("Tipo de consumidor inválido\n ");
    }


    return 0;
}