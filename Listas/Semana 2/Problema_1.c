#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); //Separador decimal passa a ser a v?rgula

    float peso, altura, imc;

    printf ("Informe sua altura (metros): \n");
    scanf ("%f", &altura);

    printf ("Informe seu peso (kg): \n");
    scanf ("%f", &peso);

    imc = peso / (altura * altura);

    printf ("Seu IMC é: %.2f\n", imc);


    return 0;
}