#include <stdio.h>
#include <locale.h>

int main () {

    setlocale (LC_ALL, "Portuguese"); //Lembrete: separador decimal passa a ser a vírgula

    float peso, altura, imc;

    printf ("Informe sua altura (metros): \n");
    scanf ("%f", &altura);

    printf ("Informe seu peso (kg): \n");
    scanf ("%f", &peso);

    imc = peso / (altura * altura);

    if (imc < 18.5)
        printf ("Seu IMC é: %.2f (Abaixo do peso)\n ", imc);
    if (imc >= 18.5 && imc <= 24.9)
        printf ("Seu IMC é: %.2f (Peso normal)\n ", imc);
    if (imc >= 25 && imc <= 29.9)
        printf ("Seu IMC é: %.2f (Sobrepeso)\n ", imc);
    if (imc > 30)
        printf ("Seu IMC é: %.2f (Obesidade)\n ", imc);


    return 0;
}