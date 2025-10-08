#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int colecao[m + 1];
    
    for (int i = 1; i <= m; i++) {
        colecao[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int fig;
        scanf("%d", &fig);
        colecao[fig] = 1;
    }

    int primeira = 1;
    for (int i = 1; i <= m; i++) {
        if (colecao[i] == 0) {
            if (!primeira) {
                printf(" ");
            }
            printf("%d", i);
            primeira = 0;
        }
    }
    printf("\n");

    return 0;
}