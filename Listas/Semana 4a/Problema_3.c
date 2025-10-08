#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    int A, B;
    
    printf("Digite dois números diferentes (Separados por espaço): ");
    scanf("%d %d", &A, &B);
    
    int somaA = 1; 
    int somaB = 1; 

    for (int i = 2; i <= A / 2; i++) {
        if (A % i == 0) {
            somaA += i;
        }
    }

    for (int i = 2; i <= B / 2; i++) {
        if (B % i == 0) {
            somaB += i;
        }
    }

    if (abs(somaA - B) <= 2 && abs(somaB - A) <= 2) {
        printf("S\n ");
    } else {
        printf("N\n ");
    }

    return 0;
}