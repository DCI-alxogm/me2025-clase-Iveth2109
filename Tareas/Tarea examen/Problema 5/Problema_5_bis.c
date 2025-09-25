#include <stdio.h>
#include <math.h>

float f(float x) {
    return -0.5*pow(x, 2)+2.5*x+4.5;
}

int main() {
    float Err_max = 0.00001;
    float a = 6.0f, b = 7.0f, k, Err, kold=INFINITY, fk, Eapr;
    int iter = 0;

    printf("Iter \t raiz \t f(k) \t Eaprox \t E_r \n");

    do {
        iter++;
        k = (a + b) / 2.0f;
        fk = f(k);

        if (f(k) * f(a) < 0.0f) {
            b = k;
        } else {
            a = k;
        }

        Eapr = k - kold;
        Err = fabsf(Eapr) / k;
        kold = k;

        printf("%d \t %f  \t %f  \t %f  \t %f \n", iter, k, fk, Eapr, Err);

    } while (Err > Err_max && iter < 3);

    printf("La raíz aproximada tras 3 iteraciones es: %.7f\n", k);
    printf("f(c_raiz) = %.7f\n", f(k));

    return 0;
}