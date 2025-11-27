//Problema de oscilador armonico

#include <stdio.h>
#include <math.h>

int main() {
    const double omega=1.0;
    const double h=0.1;
    const int N=40; //Iteraciones

    double x=1.0; //x(0)
    double v=0.0; //v(0)

    printf("n\tt\tx\t\tv\t\tk1x\t\tk1v\t\tk2x\t\tk2v\t\tk3x\t\tk3v\t\tk4x\t\tk4v\n");
  
    for (int n=0; n<=N; ++n) {
        double t=n*h;
        printf("%3d\t%.3f\t%.6f\t%.6f\t", n, t, x, v);

        double k1x=v;
        double k1v=-omega*omega*x;

        double k2x=v+0.5*h*k1v;
        double k2v=-omega*omega*(x+0.5*h*k1x);

        double k3x=v+0.5*h*k2v;
        double k3v=-omega*omega*(x+0.5*h*k2x);

        double k4x=v+h*k3v;
        double k4v=-omega*omega*(x+h*k3x);

        printf("%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", k1x, k1v, k2x, k2v, k3x, k3v, k4x, k4v);

        double x_new=x+(h/6.0)*(k1x+2.0*k2x+2.0*k3x+k4x);
        double v_new=v+(h/6.0)*(k1v+2.0*k2v+2.0*k3v+k4v);

        x=x_new;
        v=v_new;
    }

    return 0;
}