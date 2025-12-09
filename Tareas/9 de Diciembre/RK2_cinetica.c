#include <stdio.h>
#include <math.h>

const double k=0.45;
const double Cmax=1.0;

double f(double C) {
    return k*C*(Cmax-C);
}

int main(void) {
    double tin=0.01;
    int N=2500;
    double t=0.0;
    double C=0.02;

    printf("n\t t(min)\t\t C(mol/L)\t k1\t\t k2\n");
    printf("0\t %.2f\t %.10f\t %.10f\n", t, C, f(C));

    for (int n=1; n<=N; n++) {
        double k1=f(C);
        double C_mid=C+(tin/2.0)*k1;
        double k2=f(C_mid);

        C=C+tin*k2;
        t=t+tin;
        printf("%d\t %.2f\t %.10f\t %.10f\t %.10f\n", n, t, C, k1, k2);
    }

    return 0;
}