#include <stdio.h>

void imprimeHorario(int h, int m, int formato) {
    if (m >= 60) {
        h += m / 60;
        m %= 60;
    }
    h %= 24;

    if (formato == 0) {
        printf("%02d:%02d\n", h, m);
    } else {
        int h12 = h % 12;
        if (h12 == 0) h12 = 12;
        printf("%02d:%02d %s\n", h12, m, (h < 12) ? "AM" : "PM");
    }
}

int main() {
    int hora, minuto, formato;
    scanf("%d %d %d", &hora, &minuto, &formato);

    imprimeHorario(hora, minuto, formato);
    imprimeHorario(hora + 1, minuto, formato);
    imprimeHorario(hora + 2, minuto + 10, formato);
    imprimeHorario(hora + 4, minuto + 40, formato);
    imprimeHorario(hora + 12, minuto + 5, formato);

    return 0;
}