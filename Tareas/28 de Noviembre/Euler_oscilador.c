#include <stdio.h>
#include <math.h>

const double omega=1.0;

double f_x(double x, double v) {
    return v;
}

double f_v(double x, double v) {
    return -omega*omega*x;
}

int main(void) {
    double h=0.1;      
    int N=10; //Iteraciones
    double t=0.0;

    double x=1.0;      /* x(0) */
    double v=0.0;      /* v(0) */

    printf("n\t t(s)\t\t x\t\t v\n");
    printf("0\t %.2f\t %.10f\t %.10f\n", t, x, v);

    for (int n=1; n<=N; ++n) {

        double dxdt=f_x(x, v);
        double dvdt=f_v(x, v);

        x=x+h*dxdt;
        v=v+h*dvdt;
        t=t+h;

        printf("%d\t %.2f\t %.10f\t %.10f\n", n, t, x, v);
    }

    return 0;
}