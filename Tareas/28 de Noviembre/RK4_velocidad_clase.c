#include <stdio.h>
#include <math.h>

const double g=9.81;
const double c=12.5;
const double m=68.1;
const double a=8.3;
const double b=2.2;
const double vmax=46.0;

double f(double v) {
    double div=v/vmax;
    double divpow=pow(div, b);             //r^b
    double multi=v+a*divpow;       //v + a * (v/vmax)^b
    double termino=(c/m)*multi;     //(c/m) * (v + a * (v/vmax)^b)
    return g-termino;                    //dv/dt
}

int main(void) {
    double h=0.1;
    int N=3; //iteraciones
    double t=0.0;
    double v=0.0;

    printf("n\t t(s)\t\t v(m/s)\t\t f(v) (m/s^2)\n");
    printf("0\t %.2f\t %.10f\t %.10f\n", t, v, f(v));

    for (int n=1; n<=N; n++) {

        //k1
        double k1=f(v);

        //k2
        double v_k2=v+(h/2.0)*k1;
        double k2=f(v_k2);

        //k3
        double v_k3=v+(h/2.0)*k2;
        double k3=f(v_k3);

        //k4
        double v_k4=v+h*k3;
        double k4=f(v_k4);

        v=v+(h/6.0)*(k1+2*k2+2*k3+k4);
        t=t+h;

        printf("%d\t %.2f\t %.10f\t %.10f\t %.10f\t %.10f\t %.10f\n", n, t, v, k1, k2, k3, k4);
    }

    return 0;
}