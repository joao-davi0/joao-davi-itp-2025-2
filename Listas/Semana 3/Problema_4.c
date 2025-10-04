#include <stdio.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "Portuguese");

    char j1, j2;

    printf ("Escolha do jogador 1 (P para pedra, A para papel, T para tesoura)(Digite com letras mai�sculas): ");
    scanf (" %c", &j1);

    printf ("Escolha do jogador 2 (P para pedra, A para papel, T para tesoura)(Digite com letras mai�sculas): ");
    scanf (" %c", &j2); 

    if ((j1 != 'P' && j1 != 'A' && j1 != 'T') || (j2 != 'P' && j2 != 'A' && j2 != 'T')) { //Valida��o de entrada
        printf ("Entrada inv�lida.\n ");
    } else if ((j1 == 'P' && j2 == 'T') || (j1 == 'A' && j2 == 'P') || (j1 == 'T' && j2 == 'A')) { //Condi��es de vit�ria do jogador 1
        printf ("Vit�ria do jogador 1!\n ");
    } else if (j1 == j2) { //Condi��es de empate
        printf ("Empate!\n ");
    } else { //Condi��es de vit�ria do jogador 2
        printf ("Vit�ria do jogador 2!.\n ");
    }


    return 0;
}