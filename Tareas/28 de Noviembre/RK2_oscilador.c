#include <stdio.h>
#include <math.h>

int main() {
    const double omega=1.0;
    const double h=0.1;
    const int N=10; //Iteraciones 

    double x=1.0;   /* x(0) */
    double v=0.0;   /* v(0) */

    printf("n\tt\tx\t\tv\t\tk1x\t\tk1v\t\tk2x\t\tk2v\n");

    for (int n=0; n<=N; ++n) {
        double t=n*h;
        printf("%3d\t%.3f\t%.6f\t%.6f\t", n, t, x, v);

        double k1x=v;
        double k1v=-omega*omega*x;

        double xm=x+0.5*h*k1x;
        double vm=v+0.5*h*k1v;

        double k2x=vm;
        double k2v=-omega*omega*xm;

        printf("%.6f\t%.6f\t%.6f\t%.6f\n", k1x, k1v, k2x, k2v);

        double x_new=x+h*k2x;
        double v_new=v+h*k2v;

        x=x_new;
        v=v_new;
    }

    return 0;
}