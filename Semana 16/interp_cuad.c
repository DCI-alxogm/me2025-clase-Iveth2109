#include <stdio.h>

double interp_cuadratica(double x[], double y[], double xi){
    double L0, L1, L2;

    L0=((xi-x[1])*(xi-x[2]))/((x[0]-x[1])*(x[0]-x[2]));
    L1=((xi-x[0])*(xi-x[2]))/((x[1]-x[0])*(x[1]-x[2]));
    L2=((xi-x[0])*(xi-x[1]))/((x[2]-x[0])*(x[2]-x[1]));

    return y[0]*L0+y[1]*L1+y[2]*L2;
}

int main(){
    double x[]={1, 4, 5};
    double y[]={0, 1.386294, 1.609438};
    double xi=2;

    double yi=interp_cuadratica(x, y, xi);

    printf("Interpolacion cuadratica F(2) = %lf\n", yi);

    return 0;
}