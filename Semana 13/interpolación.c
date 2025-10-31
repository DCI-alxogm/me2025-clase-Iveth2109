#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2*sin(x)-pow(x,2)/10;
}

int main() {
  double a=0, b=1, c=5;
  double fa, fb, fc;
  double x_max, fx_max;
  double denom, Err, Err_max = 0.0001;
  int iter=0, maxIter=1000;

  printf("Iter\t a\t b\t c\t x_max\t f(x_max)\t Error\n");

  do {
    fa=f(a);
    fb=f(b);
    fc=f(c);
    denom=(fa*(b-c)+fb*(c-a)+fc*(a-b));

  if (fabs(denom)<1e-12) {
    printf("Denominador muy pequeño, se detiene la iteración.\n");
    break;
  }

  x_max=0.5*((fa*(pow(b, 2)-pow(c, 2))+fb*(pow(c, 2)-pow(a, 2))+fc*(pow(a, 2)-pow(b, 2)))/denom);
  fx_max=f(x_max);
  printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t ", iter, a, b, c, x_max, fx_max);

  if (x_max>b) {
    if (fx_max>fb) {
      a=b;
      b=x_max;
    } else {
        c=x_max;
      }
    } else {
        if (fx_max>fb) {
          c=b;
          b=x_max;
      } else {
        a=x_max;
      }
    }

  Err=fabs(c-a);
  printf("%.6e\n", Err);

    iter++;
  } while (Err>Err_max && iter<maxIter);

  printf("\nConvergio en %d iteraciones\n", iter);
  printf("Punto máximo aproximado en x = %.8f\n", x_max);
  printf("Valor de la función en el punto máximo: f(x) = %.8f\n", fx_max);

  return 0;
}