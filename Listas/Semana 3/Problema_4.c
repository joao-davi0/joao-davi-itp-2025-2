#include <stdio.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL, "Portuguese");

    char j1, j2;

    printf ("Escolha do jogador 1 (P para pedra, A para papel, T para tesoura)(Digite com letras maiúsculas): ");
    scanf (" %c", &j1);

    printf ("Escolha do jogador 2 (P para pedra, A para papel, T para tesoura)(Digite com letras maiúsculas): ");
    scanf (" %c", &j2); 

    if ((j1 != 'P' && j1 != 'A' && j1 != 'T') || (j2 != 'P' && j2 != 'A' && j2 != 'T')) { //Validação de entrada
        printf ("Entrada inválida.\n ");
    } else if ((j1 == 'P' && j2 == 'T') || (j1 == 'A' && j2 == 'P') || (j1 == 'T' && j2 == 'A')) { //Condições de vitória do jogador 1
        printf ("Vitória do jogador 1!\n ");
    } else if (j1 == j2) { //Condições de empate
        printf ("Empate!\n ");
    } else { //Condições de vitória do jogador 2
        printf ("Vitória do jogador 2!.\n ");
    }


    return 0;
}