#include <stdio.h>
#include <math.h>
 
double f(double x){
    return exp(-x) - x;
}
 
int main(void){
  double x0=0.1;
  double x1=0.0;
  double x2, Err;
  double Err_max=1e-8;
  int maxIter=1000;
  int iter=0;
 
  printf("Iter\t   xi-1\t\t   xi\t\t   xi+1\t\t Error\n");
 
  while (iter<maxIter){
    x2=x0-f(x0)*(x1-x0)/(f(x1)-f(x0));
    Err=fabs((x2-x0)/x2);
 
    printf("%d\t%lf\t%lf\t%lf\t%e\n", iter, x0, x1, x2, Err);
 
    if (Err<Err_max){
    printf("\nConvergió en %d iteraciones\n", iter+1);
    printf("Raíz aproximada: %.10f\n", x2);
    return 0;
    }
    x0 = x2;
    iter++;
    }
    printf("\nNo convergió después de %d iteraciones\n", maxIter);
    printf("Último valor: %f Error: %e\n", x2, Err);
 
    return 0;
}