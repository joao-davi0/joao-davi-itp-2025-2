#include <stdio.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "Portuguese"); //Lembrete: o separador decimal passa a ser a vírgula.

    int x, y;
    float div, media;

    printf ("Digite dois números inteiros separados por espaço: ");
    scanf ("%d %d", &x, &y);

    div = (float)x/y; //Note com isso que o segundo número não pode ser zero.
    media = (x+y)/2.0;

    printf ("Soma: %d\n", x+y);
    printf ("Diferença: %d\n", x-y);
    printf ("Produto: %d\n", x*y);
    printf ("Divisão: %.2f\n", div);
    printf ("Resto: %d\n", x%y);
    printf ("Média aritmética: %.2f\n", media);


    return 0;
}