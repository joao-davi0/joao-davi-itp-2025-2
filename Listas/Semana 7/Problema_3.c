#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(){

    setlocale(LC_ALL, "Portuguese"); // para ajuste da acentuação nos printfs

    char nome[11], frequencia[1001], palavra[25]; // 10 caracteres + \0 e 1000 caracteres + \0
    int presencas = 0, i = 0,j = 0, dias = 0, faltas = 0;

    printf("Digite o nome do(a) aluno(a): ");
    scanf("%s", nome);

    getchar(); // para desconsiderar o \n

    printf("Informe a frequência: ");
    fgets(frequencia, 1000, stdin);

    // verifica a string até o final
    while(frequencia[i] != '\0') {

        char c = frequencia[i];

        // palavras terminam em espaço ou quebra de linha
        if(c == ' ' || c == '\n') {
            if (j > 0) {
                palavra[j] = '\0';

                // verificação do formato DD/MM
                if (strlen(palavra) == 5 &&
                palavra[0] >= 48 && palavra[0] <= 57 &&
                palavra[1] >= 48 && palavra[1] <= 57 &&
                palavra[2] == '/' &&
                palavra[3] >= 48 && palavra[3] <= 57 &&
                palavra[4] >= 48 && palavra[4] <= 57) {

                    // se o aluno faltou em aula anterior
                    if(dias > 0 && !presencas)
                        faltas++;
                    
                    dias++;
                    presencas = 0;
                }

                // compara a palavra e o nome do aluno
                else if(strcmp(palavra, nome) == 0) {
                    presencas = 1; // ganha presença
                }

                j = 0;
            }
        } else {
            palavra[j++] = c;
        }

        i++;
    }

    // verificação da última palavra
    if (j > 0) {
        palavra[j] = '\0';

        // se for uma data
        if (strlen(palavra) == 5 &&
            palavra[0] >= 48 && palavra[0] <= 57 &&
            palavra[1] >= 48 && palavra[1] <= 57 &&
            palavra[2] == '/' &&
            palavra[3] >= 48 && palavra[3] <= 57 &&
            palavra[4] >= 48 && palavra[4] <= 57) {

            if(dias > 0 && !presencas)
                faltas++;
            
            dias++;
            presencas = 0;
        }

        // se for nome de aluno
        else if(strcmp(palavra, nome) == 0) {
            presencas = 1;
        }
    }

    // se o aluno faltou no último dia
    if (dias > 0 && !presencas)
        faltas++;

    printf("%d", faltas);

    return 0;
}