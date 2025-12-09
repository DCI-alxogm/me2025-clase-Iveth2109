#include <stdio.h>
#include <math.h>

const double k=0.45;
const double Cmax=1.0;

double f(double C) {
    return k*C*(Cmax-C);
}

int main(void) {
    double tin=0.1;
    int N = 250;
    double t = 0.0;
    double C = 0.02;

    printf("n\t t(min)\t\t C(mol/L)\t k1\t\t k2\t\t k3\t\t k4\n");
    printf("0\t %.2f\t %.10f\t %.10f\n", t, C, f(C));

    for (int n=1; n<=N; n++) {

        //k1
        double k1=f(C);

        //k2
        double C_k2=C+(tin/2.0)*k1;
        double k2=f(C_k2);

        //k3
        double C_k3=C+(tin/2.0)*k2;
        double k3=f(C_k3);

        //k4
        double C_k4=C+tin*k3;
        double k4=f(C_k4);

        C=C+(tin/6.0)*(k1+2*k2+2*k3+k4);
        t=t+tin;

        printf("%d\t %.2f\t %.10f\t %.10f\t %.10f\t %.10f\t %.10f\n", n, t, C, k1, k2, k3, k4);
    }

    return 0;
}