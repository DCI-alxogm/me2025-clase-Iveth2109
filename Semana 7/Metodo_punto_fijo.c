#include <stdio.h>
#include <math.h>

double g(double x){
  return exp(-x);
}

int main(void){
  double x0=0.0, x1, Err;
  const double Err_max=1e-8;
  const int maxIter=1000;
  int iter=0;

  printf("Iter  \t  x_n  \t  g(x_n)  \t  Error\n");

  while (iter<maxIter){
    x1=g(x0);
    Err=fabs(x1-x0)/x1;

    printf("%d    %f    %f    %f\n", iter, x0, x1, Err);

    if(Err<Err_max){
    printf("\nConvergio en %d iteraciones\n", iter);
    printf("Raíz aproximada: %f", x1);
    return 0;
    }
    x0=x1;
    iter++;
  }
  printf("\nNo convergio después de % iteraciones", maxIter);
  printf("\nÚltimo valor: %f    Error: %f", x1, Err);

  return 0;
}