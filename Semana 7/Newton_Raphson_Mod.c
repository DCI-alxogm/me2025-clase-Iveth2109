#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-x)-x;
}

double f1(double x){
    return -exp(-x)-1;
}

double f2(double x){
    return exp(-x);
}

int main(){
  double x0=0.0;     // valor inicial
  double x1, Err;
  double Err_max=1e-8;
  int maxIter=1000;
  int iter=0;

  printf("Iter\t   xi\t\t   xi+1\t\t Error\n");

  while (iter<maxIter){
    x1=x0-(f(x0)*f1(x0))/(pow(f1(x0), 2)-f(x0)*f2(x0));
    Err=fabs((x1-x0)/x1);
    printf("%d\t%lf\t%lf\t%e\n", iter, x0, x1, Err);

    if (Err < Err_max){
    printf("\nConvergió en %d iteraciones\n", iter+1);
    printf("Raíz aproximada: %.10f\n", x1);
      return 0;
    }

    x0 = x1;  // actualizar
    iter++;
    }

  printf("\nNo convergió después de %d iteraciones\n", maxIter);
  printf("Último valor: %f Error: %e\n", x1, Err);

  return 0;
}
