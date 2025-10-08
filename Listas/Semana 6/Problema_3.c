#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int alturas[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &alturas[i]);
    }

    int max = alturas[0];

    for (int i = 1; i < n; i++) {
        if (alturas[i] > max) {
            max = alturas[i];
        }
    }

    int primeira = -1, segunda = -1;

    for (int i = 0; i < n; i++) {
        if (alturas[i] == max) {
            if (primeira == -1) primeira = i;
            else {
                segunda = i;
                break;
            }
        }
    }

    int comprimento = segunda - primeira - 1;
    printf("%d\n", comprimento);

    return 0;
}