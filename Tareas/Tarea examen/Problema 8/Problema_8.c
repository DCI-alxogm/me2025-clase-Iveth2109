#include <stdio.h>
#include <math.h>

double f(double c, double W, double Q, double k, double V) {
  return W - Q*c - k*V*sqrt(c);
}

int main(){
  double V = 1e6;
  double Q = 1e5;
  double W = 1e6;
  double k = 0.25;

  double c0 = 4.0;
  double d = 0.5;
  double c_next, Err;
  int nIter = 3;
  int iter;

  printf("Iter\t   c_i\t\t   c_i+1\t\t Err_rel (%%)\n");

  for(iter = 1; iter <= nIter; iter++){
    c_next = c0 - f(c0, W, Q, k, V) * d / (f(c0 + d, W, Q, k, V) - f(c0, W, Q, k, V));
    Err = fabs((c_next - c0)/c_next) * 100.0;  // error relativo %
    printf("%d\t%lf\t%lf\t%lf\n", iter, c0, c_next, Err);
    c0 = c_next;
    }

  printf("\nConcentración aproximada después de %d iteraciones: %lf g/m3\n", nIter, c_next);
  printf("Error relativo porcentual en la última iteración: %lf %%\n", Err);

  return 0;
}
