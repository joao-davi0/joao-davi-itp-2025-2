#include <stdio.h>
#include <locale.h>

int main () {

    setlocale (LC_ALL, "Portuguese"); //Separador decimal passa a ser a v�rgula

    float n1, n2, n3, media, nfinal;

    printf ("Digite sua primeira nota: ");
    scanf ("%f", &n1);

    printf ("Digite sua segunda nota: ");
    scanf ("%f", &n2);

    printf ("Digite sua terceira nota: ");
    scanf ("%f", &n3);

    media = (n1 + n2 + n3) / 3.0;

    if (media >= 7.0) {
        printf ("Sua m�dia � %.1f (Aprovado).\n ", media);
    } else if (media < 4.0) {
        printf ("Sua m�dia � %.1f (Reprovado).\n ", media);
    } else {
        printf ("Sua m�dia � %.1f (Recupera��o).\n", media);
        nfinal = 10 - media;
        printf ("Voc� precisa de %.1f na prova final.\n ", nfinal);
    }


    return 0;
}