#include <stdio.h>
#include <math.h>

#include <math.h>

double f(double x){
  return exp(-x) - x;
}

double f1(double x){
  return -exp(-x) - 1;
}

double f2(double x){
  return exp(-x);
}

double g(double x){
  return exp(-x);
}

// Método punto fijo
void punto_fijo(double x0, double tol, int maxIter){
  int iter=0;
  double x1, Err;

  printf("\n    Método de punto fijo    \n");
  printf("Iter\t    xi\t\t    xi+1\t\t  Error\n");

  while (iter<maxIter){
    x1=g(x0);
    Err=fabs((x1-x0)/x1);
    printf("%d\t  %f\t  %f\t  %e\n", iter, x0, x1, Err);

    if(Err<tol){
      printf("\nConvergió en %d iteraciones\n", iter+1);
      printf("La raíz aproximada es: %f\n", x1);
      return;
    }
    x0=x1;
    iter++;
  }
  printf("\nNo convergió\n");
}

//Método de Newton Raphson
void newton(double x0, double tol, int maxIter) {
  int iter=0;
  double x1, Err;

  printf("\n   Metodo de Newton-Raphson   \n");
  printf("Iter\t   xi\t\t   xi+1\t\t Error\n");

  while (iter < maxIter) {
    x1=x0-f(x0)/f1(x0);
    Err=fabs((x1-x0)/x1);
    printf("%d\t%lf\t%lf\t%e\n", iter, x0, x1, Err);

    if (Err < tol) {
      printf("\nConvergió en %d iteraciones\n", iter+1);
      printf("Raíz aproximada: %.10f\n", x1);
      return;
    }
    x0 = x1;
    iter++;
  }
  printf("\nNo convergió\n");
}

// Bisección
void biseccion(double a, double b, double tol, int maxIter){
  int iter = 0;
  double k, kold, Err;

  kold = a;
  printf("\n   Método de Bisección   \n");
  printf("Iter\t  k_old\t\t  k\t\t  Error\n");
  do {
    k = (a + b) / 2.0;
    Err = fabs((k - kold) / k);
    printf("%d\t%f\t%f\t%e\n", iter, kold, k, Err);

    if (f(k) * f(a) < 0.0) {
      b = k;
    } else {
        a = k;
    }

    kold = k;
    iter++;

    if (iter >= maxIter) break;

    } while (Err > tol);

    printf("\nConvergió en %d iteraciones\n", iter+1);
    printf("La raíz aproximada es: %.7f\n", k);
}

// Método de Falsa Posición
void falsa_posicion(float a, float b, float tol, int maxIter){
  float k, kold = INFINITY, fk, Eapr, Err;
  int iter = 0;

  printf("\n   Método de Falsa Posición   \n");
  printf("Iter\t  k\t\t  f(k)\t\t  Eapr\t\t  Err\n");

  do {
    k = ((f(b)*a) - (f(a)*b)) / (f(b) - f(a));
    fk = f(k);
    Eapr = k - kold;
    Err = fabs(Eapr) / fabs(k);
    printf("%d\t%f\t%f\t%f\t%e\n", iter, k, fk, Eapr, Err);

    if (f(k) * f(a) < 0.0f) {
      b = k;
    } else {
        a = k;
    }

    kold = k;
    iter++;

    if (iter >= maxIter) break;

  } while (Err > tol);

  printf("\nConvergió en %d iteraciones\n", iter+1);
  printf("La raíz aproximada es: %.7f\n", k);
}

// Método de la secante
void secante(double x0, double x1, double tol, int maxIter){
  int iter = 0;
  double x2, Err;

  printf("\n    Método de la secante    \n");
  printf("Iter\t    xi-1\t\t  xi\t\t  xi+1\t\t  Error\n");

  while (iter < maxIter){
    double f0 = f(x0);
    double f1 = f(x1);
    double denom = f1 - f0;

   if (fabs(denom) < 1e-14){
      printf("Error: denominador muy pequeño en iter %d (f1-f0 ≈ 0)\n", iter);
      return;
    }

    x2 = x1 - f1 * (x1 - x0) / denom;
    if (fabs(x2) > 1e-16)
      Err = fabs((x2 - x1) / x2);
    else
      Err = fabs(x2 - x1);
      printf("%d\t  %f\t  %f\t  %f\t  %e\n", iter, x0, x1, x2, Err);

    if (Err < tol){
      printf("\nConvergió en %d iteraciones\n", iter+1);
      printf("La raíz aproximada es: %f\n", x2);
      return;
    }
    x0 = x1;
    x1 = x2;
    iter++;
    }
    printf("\nNo convergió después de %d iteraciones\n", maxIter);
}


//Método de Newton Raphson modificado
void newton_modificado(double x0, double tol, int maxIter){
  int iter=0;
  double x1, Err;

  printf("\n    Método de Newton Raphson Modificado    \n");
  printf("Iter\t    xi-1\t\t  xi\t\t  xi+1\t\t  Error\n");

  while (iter<maxIter){
    double denom=pow(f1(x0), 2)-f(x0)*f2(x0);
    if (fabs(denom)<1e-12){
      printf("Error: denominador muy pequeño en iter %d\n", iter);
    }

    x1=x0-(f(x0)*f1(x0))/denom;
    Err=fabs((x1-x0)/x1);
    printf("%d\t  %f\t  %f\t  %e\n", iter, x0, x1, Err);
    
    if(Err<tol){
      printf("\nConvergió en %d iteraciones\n", iter+1);
      printf("La raíz aproximada es: %f", x1);
      return;
    }
    x0=x1;
    iter++;
  }
  printf("\nNo convergió\n");
}

int main(){
  double tol=1e-8;
  int maxIter=1000;

  punto_fijo(0.5, tol, maxIter);
  newton(0.5, tol, maxIter);
  secante(0.0, 1.0, tol, maxIter);
  newton_modificado(0.5, tol, maxIter);
  biseccion(0.0, 1.0, tol, maxIter);
  falsa_posicion(0.0, 1.0, tol, maxIter);
}