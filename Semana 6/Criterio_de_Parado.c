#include <stdio.h>
#include <math.h>

float f(float c) {
  return ((9.81f * 68.1f) / c) * (1 - expf(-(c / 68.1f) * 10.0f)) - 40.0f;
}

int main() {
  float Err_max = 0.001;
  float a = 4.0f, b = 20.0f, k, Err, kold=INFINITY, fk, Eapr;
  printf("raiz \t f(k) \t Eaprox \t E_r \n");

  do {
    k = (a + b) / 2.0f;
    fk= f(k);

    if (f(k) * f(a) < 0.0f) {
      b = k;
    } else {
       a = k;
    }
    Eapr=k-kold;
    Err = fabsf(Eapr) / k;
      kold = k;
      printf("%f  \t  %f  \t  %f  \t  %f \n", k,fk, Eapr, Err);
    } while (Err > Err_max);

  printf("La raíz aproximada es: %.7f\n", k);
  printf("f(c_raiz) = %.7f\n", f(k));

  return 0;
}