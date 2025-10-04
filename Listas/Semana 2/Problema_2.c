#include <stdio.h>

int main () {

    float C, F, K;

    printf ("Informe a temperatura em graus Celsius: ");
    scanf ("%f", &C);

    F = (C * 9/5) + 32; 
    K = C + 273.15;

    printf ("Temperatura em Fahrenheit: %.1f\n", F);
    printf ("Temperatura em Kelvin: %.1f\n", K);


    return 0;
}

