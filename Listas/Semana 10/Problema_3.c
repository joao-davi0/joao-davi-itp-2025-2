#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

// mistura duas strings alternando caracteres e retorna uma nova string alocada dinamicamente
char * misturar(char *str1, char *str2) {

    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // aloca a nova string
    char *nova = malloc((n1 + n2 + 1) * sizeof(char));

    int i = 0, j = 0, k = 0;

    // alterna caracteres enquanto ambas têm letras disponíveis
    while (i < n1 && j < n2) {
        nova[k++] = str1[i++];
        nova[k++] = str2[j++];
    }

    // copia resto da string 1 (se sobrar)
    while (i < n1) {
        nova[k++] = str1[i++];
    }

    // copia resto da string 2 (se sobrar)
    while (j < n2) {
        nova[k++] = str2[j++];
    }

    nova[k] = '\0'; // finaliza string
    return nova;
}

int main() {
    // ajuste de acentuação
    setlocale(LC_ALL, "Portuguese");

    char str1[101], str2[101];

    // leitura das duas strings (com espaços)
    fgets(str1, 101, stdin);
    fgets(str2, 101, stdin);

    // remove '\n' caso exista
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    char *resultado = misturar(str1, str2);

    printf("%s\n", resultado);

    free(resultado); // libera memória
    return 0;
}