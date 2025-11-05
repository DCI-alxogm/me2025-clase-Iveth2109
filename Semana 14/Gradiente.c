#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return 2*x*y + 2*x - x*x - 2*y*y;
}

double fx(double x, double y) {
    return 2*y + 2 - 2*x;
}
 
double fy(double x, double y) {
    return 2*x - 4*y;
}

double fxx() { return -2; }
double fyy() { return -4; }
double fxy() { return 2; }
 
int main() {

    double x = -1.0, y = 1.0;
    double dx, dy;
    double h;
    double tol = 1e-6;
    int maxIter = 100, iter = 0;
 
    printf("\nMáximo aproximado en: (x, y) = (%.6f, %.6f)\n", x, y);
    printf("f(x,y) = %.6f\n", f(x,y));
 
    return 0;
}