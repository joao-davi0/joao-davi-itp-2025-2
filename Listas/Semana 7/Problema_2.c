#include<stdio.h>
#include<string.h>
#include<locale.h>

int main(){

    setlocale(LC_ALL, "Portuguese");

    char placa[11]; // 10 caracteres + \0

    printf("Digite a placa do veículo: ");
    scanf("%s", placa);

    int n = strlen(placa);

    // verifica se tem padrão brasileiro 
    if (n == 8 &&
        (placa[0] >= 65 && placa[0] <=90) &&
        (placa[1] >= 65 && placa[1] <=90) &&
        (placa[2] >= 65 && placa[2] <=90) &&
        (placa[3] == '-') &&
        (placa[4] >= 48 && placa[4] <=57) &&
        (placa[5] >= 48 && placa[5] <=57) &&
        (placa[6] >= 48 && placa[6] <=57) &&
        (placa[7] >= 48 && placa[7] <=57)) {

        printf("Brasileiro\n");

    // verifica se tem padrão mercosul
    } else if (n == 7 &&
        (placa[0] >= 65 && placa[0] <=90) &&
        (placa[1] >= 65 && placa[1] <=90) &&
        (placa[2] >= 65 && placa[2] <=90) &&
        (placa[3] >= 48 && placa[3] <=57) &&
        (placa[4] >= 65 && placa[4] <=90) &&
        (placa[5] >= 48 && placa[5] <=57) &&
        (placa[6] >= 48 && placa[6] <=57)) {
        
        printf("Mercosul\n");

    // invalida entradas fora de ambos os padrões
    } else {
        printf("Inválido\n");
    }

    return 0;
}