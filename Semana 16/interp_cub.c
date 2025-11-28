#include <stdio.h>

double interp_cubica(double x[], double y[], double xi){
    double L0, L1, L2, L3;

    L0=((xi-x[1])*(xi-x[2])*(xi-x[3]))/((x[0]-x[1])*(x[0]-x[2])*(x[0]-x[3]));
    L1=((xi-x[0])*(xi-x[2])*(xi-x[3]))/((x[1]-x[0])*(x[1]-x[2])*(x[1]-x[3]));
    L2=((xi-x[0])*(xi-x[1])*(xi-x[3]))/((x[2]-x[0])*(x[2]-x[1])*(x[2]-x[3]));
    L3=((xi-x[0])*(xi-x[1])*(xi-x[2]))/((x[3]-x[0])*(x[3]-x[1])*(x[3]-x[2]));

    return y[0]*L0+y[1]*L1+y[2]*L2+y[3]*L3;
}

int main(){
    double x[]={1, 4, 5, 6};
    double y[]={0, 1.386294, 1.609438, 1.791752};
    double xi=2;

    double yi=interp_cubica(x, y, xi);

    printf("Interpolacion cubica F(2) = %lf\n", yi);

    return 0;
}