#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return 2*x*y+2*x-pow(x,2)-2*pow(y,2);
}

double fx(double x, double y) {
    return 2*y+2-2*x;
}

double fy(double x, double y) {
    return 2*x-4*y;
}

double fxx() {return -2;}
double fyy() {return -4;}
double fxy() {return 2;}

int main() {
  double x=-1.0, y=1.0;
  double dx, dy;
  double h;
  double tol=1e-6;
  int maxIter=100, iter=0;

  printf("Iter\t\tx\t\ty\t\tf(x,y)\n");
  for (iter=0; iter<maxIter; iter++) {
    dx=fx(x, y);
    dy=fy(x, y);

    double num=-(pow(dx,2)+pow(dy,2));
    double den=dx*(dx*fxx()+dy*fxy())+dy*(dx*fxy()+dy*fyy());
    h=num/den;

    x=x+h*dx;
    y=y+h*dy;
    printf("%d\t\t%.6f\t%.6f\t%.6f\n", iter, x, y, f(x,y));

    if (sqrt(pow(dx,2)+pow(dy,2))<tol) //Se saca la magnitud del 
      break;
    }

  printf("\nMáximo aproximado en: (x, y) = (%.6f, %.6f)\n", x, y);
  printf("f(x,y) = %.6f\n", f(x,y));
  return 0;
}