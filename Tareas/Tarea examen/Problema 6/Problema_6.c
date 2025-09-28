#include <stdio.h>
#include <math.h>

float f(float h) {
  float R = 3.0f;
  return (M_PI/3.0f) * h*h * (3*R - h) - 30.0f;
}

int main() {
  float a=0.0f, b=6.0f, k, Err, kold=INFINITY, fk, Eapr;
  int iter = 0;

  printf("Iter\t h\t\t f(h)\t\t Eaprox\t\t Err_rel\n");

do {
  iter++;
  k = ((f(b)*a) - (f(a)*b)) / (f(b) - f(a));
  fk = f(k);

  if (f(k) * f(a) < 0.0f) {
    b = k;
  } else {
      a = k;
  }

  Eapr = k - kold;
  if (iter == 1) {
    Err = 0.0f;
  } else {
      Err = fabsf(Eapr) / k;
  }
  kold = k;

  printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", iter, k, fk, Eapr, Err);

  } while (iter < 3);

  printf("\nProfundidad aproximada h = %.6f m\n", k);

  return 0;
}