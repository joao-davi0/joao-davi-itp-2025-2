#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); //Separador decimal passa a ser a vírgula

    char febre, dor_cabeca, dor_corpo, tosse;

    printf("Tem febre? (S/N)\n");
    scanf(" %c", &febre);

    printf("Tem dor de cabeça? (S/N)\n");
    scanf(" %c", &dor_cabeca);

    printf("Tem dor no corpo? (S/N)\n");
    scanf(" %c", &dor_corpo);

    printf("Tem tosse? (S/N)\n");
    scanf(" %c", &tosse);

    if ((febre == 's' || febre == 'S') && (dor_cabeca == 's' || dor_cabeca == 'S') && (dor_corpo == 's' || dor_corpo == 'S') && (tosse == 'n' || tosse == 'N')) {
        //Febre + dor de cabeça + dor no corpo
        printf("Possível gripe.\n ");

    } else if ((febre == 's' || febre == 'S') && (dor_cabeca == 'n' || dor_cabeca == 'N') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 's' || tosse == 'S')) {
        //Tosse + febre
        printf("Possível resfriado.\n ");

    } else if ((febre == 'n' || febre == 'N') && (dor_cabeca == 's' || dor_cabeca == 'S') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 'n' || tosse == 'N')) {
        //Só dor de cabeça
        printf("Possível enxaqueca.\n ");

    } else if ((febre == 's' || febre == 'S') && (dor_cabeca == 'n' || dor_cabeca == 'N') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 'n' || tosse == 'N')) {
        //Só febre
        printf("Consulte um médico.\n ");

    } else if ((febre == 'n' || febre == 'N') && (dor_cabeca == 'n' || dor_cabeca == 'N') && (dor_corpo == 'n' || dor_corpo == 'N') && (tosse == 'n' || tosse == 'N')) {
        //Nenhum sintoma
        printf("Você parece estar bem.\n ");

    } else {
        //Qualquer outra combinação de sintomas
        printf("Consulte um médico para avaliação.\n ");
    }


    return 0;
}