#include <stdio.h>
#include <math.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese"); //Separador decimal passa a ser a v�rgula

    float x, y, teia;
    int n, l;

    printf("Digite as coordenadas iniciais (x, y) do Homem-Aranha (Separadas por espa�o): ");
    scanf("%f %f", &x, &y);

    printf("Informe o comprimento m�ximo da teia (m): ");
    scanf("%f", &teia);

    printf("Informe a quantidade de alvos: ");
    scanf("%d", &n);

    int sucesso = 1; 

    for (l = 0; l < n; l++) {
        float ax, ay;
        printf("Digite as coordenadas x e y do alvo %d (separadas por espa�o): ", l + 1);
        scanf("%f %f", &ax, &ay);

        float dist = sqrt((ax - x) * (ax -x) + (ay - y) * (ay - y));

        if (dist > teia) {
            sucesso = 0;
            break;
        }
        x = 2 * ax - x;
        y = ay;
    }
        
    if (sucesso)
        printf("S\n ");
    else 
        printf("N\n ");

    return 0;
}