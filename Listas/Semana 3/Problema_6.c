#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); //Separador decimal passa a ser a v�rgula

    char febre, dor_cabeca, dor_corpo, tosse;

    printf("Tem febre? (S/N)\n");
    scanf(" %c", &febre);

    printf("Tem dor de cabe�a? (S/N)\n");
    scanf(" %c", &dor_cabeca);

    printf("Tem dor no corpo? (S/N)\n");
    scanf(" %c", &dor_corpo);

    printf("Tem tosse? (S/N)\n");
    scanf(" %c", &tosse);

    if ((febre == 's' || febre == 'S') && (dor_cabeca == 's' || dor_cabeca == 'S') && (dor_corpo == 's' || dor_corpo == 'S') && (tosse == 'n' || tosse == 'N')) {
        //Febre + dor de cabe�a + dor no corpo
        printf("Poss�vel gripe.\n ");

    } else if ((febre == 's' || febre == 'S') && (dor_cabeca == 'n' || dor_cabeca == 'N') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 's' || tosse == 'S')) {
        //Tosse + febre
        printf("Poss�vel resfriado.\n ");

    } else if ((febre == 'n' || febre == 'N') && (dor_cabeca == 's' || dor_cabeca == 'S') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 'n' || tosse == 'N')) {
        //S� dor de cabe�a
        printf("Poss�vel enxaqueca.\n ");

    } else if ((febre == 's' || febre == 'S') && (dor_cabeca == 'n' || dor_cabeca == 'N') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 'n' || tosse == 'N')) {
        //S� febre
        printf("Consulte um m�dico.\n ");

    } else if ((febre == 'n' || febre == 'N') && (dor_cabeca == 'n' || dor_cabeca == 'N') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 'n' || tosse == 'N')) {
        //Nenhum sintoma
        printf("Voc� parece estar bem.\n ");

    } else {
        //Qualquer outra combina��o de sintomas
        printf("Consulte um m�dico para avalia��o.\n ");
    }


    return 0;
}