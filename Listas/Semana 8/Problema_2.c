#include<stdio.h>
#include<locale.h>

int main(){

    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    int chuva[12], meses[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int maisChuva, x, y;

    printf("Digite a quantidade de chuva de cada mês: ");
    // armazena as quantidades de chuva de cada mês
    for (int i = 0; i < 12; i++)
        scanf("%d", &chuva [i]);

    // usando o algoritmo selection sort
    for (int i = 0; i < 11; i++) {
        maisChuva = i;
        for (int j = i+1; j < 12; j++) {
            if (chuva[j] > chuva[maisChuva]) {
                maisChuva = j;
            }
        }
        x = chuva[i];
        y = meses[i];
        chuva[i] = chuva[maisChuva];
        meses[i] = meses[maisChuva];
        chuva[maisChuva] = x;
        meses[maisChuva] = y;
    }

    for (int i = 0; i < 12; i++){
        // imprimindo de acordo com cada mês
        if (meses[i] == 1)
            printf("Janeiro %d\n", chuva[i]);
        else if (meses[i] == 2)
            printf("Fevereiro %d\n", chuva[i]);
        else if (meses[i] == 3)
            printf("Março %d\n", chuva[i]);
        else if (meses[i] == 4)
            printf("Abril %d\n", chuva[i]);
        else if (meses[i] == 5)
            printf("Maio %d\n", chuva[i]);
        else if (meses[i] == 6)
            printf("Junho %d\n", chuva[i]);
        else if (meses[i] == 7)
            printf("Julho %d\n", chuva[i]);
        else if (meses[i] == 8)
            printf("Agosto %d\n", chuva[i]);
        else if (meses[i] == 9)
            printf("Setembro %d\n", chuva[i]);
        else if (meses[i] == 10)
            printf("Outubro %d\n", chuva[i]);
        else if (meses[i] == 11)
            printf("Novembro %d\n", chuva[i]);
        else if (meses[i] == 12)
            printf("Dezembro %d\n", chuva[i]);
    }

    return 0;
}