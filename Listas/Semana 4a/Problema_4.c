#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");

    float x, y, x_ant = 0, y_ant = 0, dist_centro, dist_ant, pts, pts_totais = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite as coordenadas x e y do lançamento %d (separadas por espaço): ", i + 1);
        scanf("%f %f", &x, &y);

        dist_centro = sqrt(x * x + y * y);

        if (dist_centro <= 1) pts = 10;
        else if (dist_centro <= 2) pts = 6;
        else if (dist_centro <= 3) pts = 4;
        else pts = 0;

        if (i > 0) {
            dist_ant = sqrt((x - x_ant) * (x - x_ant) + (y - y_ant) * (y - y_ant));
            if (dist_ant <= 3) {
                pts += pts / 2;
            }
        }

        pts_totais += pts;
        x_ant = x;
        y_ant = y;
    }

    printf("Pontuação total: %.1f\n", pts_totais);

    return 0;
}