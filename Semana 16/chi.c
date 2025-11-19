#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double modelo(double aw, double b0, double b1, double b2, double b3) {
    return b0 * pow(aw, b1) + b2 * pow(aw, b3);
}

double chi(double *aw, double *Xe, int n,
           double b0, double b1, double b2, double b3)
{
    double s = 0;
    for (int i = 0; i < n; i++) {
        double r = Xe[i] - modelo(aw[i], b0, b1, b2, b3);
        s += r * r;
    }
    return s;
}

int main() {
    srand(time(NULL));

    // ---- LECTURA DE DATOS ----
    FILE *fp = fopen("café.txt", "r");
    if(!fp){ printf("No se pudo abrir datos.txt\n"); return 1; }

    double aw[5000], Xe[5000];
    int n = 0;
    while (fscanf(fp, "%lf %lf", &aw[n], &Xe[n]) == 2)
        n++;
    fclose(fp);

    printf("Se leyeron %d datos.\n", n);

    // ---- AJUSTE ALEATORIO ----
    double b0 = 1, b1 = 1, b2 = 1, b3 = 1;
    double best0 = b0, best1 = b1, best2 = b2, best3 = b3;
    double bestChi = chi(aw, Xe, n, b0, b1, b2, b3);

    for (int k = 0; k < 20000; k++) {
        double t0 = best0 + (rand()/(double)RAND_MAX - 0.5) * 2.0;
        double t1 = best1 + (rand()/(double)RAND_MAX - 0.5) * 1.0;
        double t2 = best2 + (rand()/(double)RAND_MAX - 0.5) * 2.0;
        double t3 = best3 + (rand()/(double)RAND_MAX - 0.5) * 1.0;

        double c = chi(aw, Xe, n, t0, t1, t2, t3);

        if (c < bestChi) {
            bestChi = c;
            best0 = t0; best1 = t1; best2 = t2; best3 = t3;
        }
    }

    // ---- RESULTADOS ----
    printf("\nMejores parámetros:\n");
    printf("b0 = %lf\n", best0);
    printf("b1 = %lf\n", best1);
    printf("b2 = %lf\n", best2);
    printf("b3 = %lf\n", best3);
    printf("\nChi-cuadrada mínima = %lf\n", bestChi);

    return 0;
}