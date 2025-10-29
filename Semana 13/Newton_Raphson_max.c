#include <stdio.h>
#include <math.h>

double f(double x){
  return (-0.5*pow(x,2))+(2.5*x)+4.5;
}

double df(double x){
  return -x+2.5;
}

double sf(double x){
  return -1;
}

int main(void){
  double x0=0.0, x1, Err;
  double Err_max=1e-8;
  int maxIter=1000;
  int iter=0;

  printf("Iter  \t  x_n   \t   f(x_n)   \t   Error\n");

  while (iter<maxIter){
    x1=x0-(df(x0)/sf(x0));
    Err=fabs((x1-x0)/x1);

    printf("%d  \t  %f  \t  %f  \t  %f\n", iter, x0, f(x0), Err);

    if(Err<Err_max){
      printf("\nConvergio en %d iteraciones\n", iter);
      printf("Raíz aproximada: %f\n", x1);
      return 0;
    }
    x0=x1;
    iter++;
  }
  printf("\nNo convergio después de %d iteraciones", maxIter);
  printf("\nÚltimo valor %f   Error: %f\n", x1, Err);

  return 0;
}