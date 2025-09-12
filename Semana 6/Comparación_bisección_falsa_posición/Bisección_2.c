//Ejercicio 2
//Por el método de bisección, encontrar la raíz en el rango de 0 y 1.3

#include <stdio.h>
#include <math.h>

float f(float x) {
  return pow(x,10)-1;
}

int main() {
  float Err_max = 0.0001;
  float a = 0.0f, b = 1.3f, k, Err, kold=INFINITY, fk, Eapr;
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