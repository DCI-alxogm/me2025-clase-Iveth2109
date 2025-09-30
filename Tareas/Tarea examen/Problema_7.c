#include <stdio.h>
#include <math.h>

double f(double T, double o) {
    return (-139.34411 + (1.575701e5)/T - (6.642308e7)/pow(T,2) + (1.243800e10)/pow(T,3) - (8.621949e11)/pow(T,4)) - log(o);
}

double biseccion(double o, double a, double b, double Err_max) {
double k, kold, Err;
  kold = a;

  do {
    k = (a + b) / 2.0;
    Err = fabs(k - kold) / k;

    if (f(k, o) * f(a, o) < 0.0) {
      b = k;
    } else {
        a = k;
    }

    kold = k;
} while (Err > Err_max);

  return k;
}

int main() {
  double o1 = 14.621;
  double o2 = 6.413;

  double a = 270.15;
  double b = 320.15;
  double Err_max = 1e-6;

  double T1 = biseccion(o1, a, b, Err_max);
  double T2 = biseccion(o2, a, b, Err_max);

  printf("Para o = %.3f mg/L, la raíz es T = %.7f K\n", o1, T1);
  printf("La temperatura en °C es = %.7f °C\n", T1-273.15);
  printf("f(T1) = %.7f\n\n", f(T1, o1));

  printf("Para o = %.3f mg/L, la raíz es T = %.7f K\n", o2, T2);
  printf("La temperatura en °C es = %.7f °C\n", T2-273.15);
  printf("f(T2) = %.7f\n", f(T2, o2));

  return 0;
}