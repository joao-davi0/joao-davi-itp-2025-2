#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    char campo[21]; // até 20 caracteres + \0
    int indice;

    printf("Digite o seu campo minado: ");
    scanf("%s", campo);

    printf("Digite o índice: ");
    scanf("%d", &indice);

    int n = strlen(campo);

    if(campo[indice] == 'x'){
        // se escolheu mina
        printf("Bum!\n");
    } else {
        int minas = 0;

        if (indice > 0 && campo[indice-1] == 'x')
            // verifica se há mina à esquerda
            minas ++;
            
        if (indice < n-1 && campo[indice+1] == 'x')
            // verifica se há mina à direita
            minas ++;
        
        printf("%d", minas);
    }

    return 0;
}