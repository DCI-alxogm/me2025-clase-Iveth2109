#include <stdio.h>
#include <math.h>

float f(float x) {
  return (-0.5*pow(x,2))+(2.5*x)+4.5;
}

int main() {
  float Err_max=1e-6;
  float a=0.0f, b=5.0, x1, x2, f1, f2, Err;
  float d=(sqrtf(5)-1)/2;
  int iter=0;

  x1=b-d*(b-a);
  x2=a+d*(b-a);
  f1=f(x1);
  f2=f(x2);
  Err=fabsf(b-a);

  do {
    if (f1<f2) {
      a=x1;
      x1=x2;
      f1=f2;
      x2=a+d*(b-a);
      f2=f(x2);
    } else {
        b=x2;
        x2=x1;
        f2=f1;
        x1=b-d*(b-a);
        f1=f(x1);
      }

      Err=fabsf(b-a);
      iter++;
    } while (Err>Err_max);

    float xmax=(a+b)/2;
    printf("El punto máximo aproximado es: %.7f\n", xmax);
    printf("f(x_max) = %.7f\n", f(xmax));
    printf("Iteraciones: %d\n", iter);

    return 0;
}