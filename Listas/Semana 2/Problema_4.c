#include <stdio.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "Portuguese"); //Lembrete: o separador decimal passa a ser a v�rgula.

    int x, y;
    float div, media;

    printf ("Digite dois n�meros inteiros separados por espa�o: ");
    scanf ("%d %d", &x, &y);

    div = (float)x/y; //Note com isso que o segundo n�mero n�o pode ser zero.
    media = (x+y)/2.0;

    printf ("Soma: %d\n", x+y);
    printf ("Diferen�a: %d\n", x-y);
    printf ("Produto: %d\n", x*y);
    printf ("Divis�o: %.2f\n", div);
    printf ("Resto: %d\n", x%y);
    printf ("M�dia aritm�tica: %.2f\n", media);


    return 0;
}