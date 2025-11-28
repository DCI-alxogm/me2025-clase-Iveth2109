#include <stdio.h>

double interp_lineal(double x0, double x1, double y0, double y1, double x){
    return y0+(y1-y0)*(x-x0)/(x1-x0);
}

int main() {
    double x0=1, y0=0;
    double x1=4, y1=1.386294;
    double xi=2;

    double yi=interp_lineal(x0, x1, y0, y1, xi);

    printf("Interpolacion lineal F(2) = %lf\n", yi);

    return 0;
}