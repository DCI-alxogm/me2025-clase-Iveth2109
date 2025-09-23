//En este problema se tenía que resolver el polinomio x^3-5x^2-7x-3 con x0=0 y x0=4
//Sin embargo, al estar los dos valores muy cerca de la raíz de 6, dan el mismo valor, solo se encuentra 1 raíz
//No se puede usar un valor más bajo ya que diverge porque no se cumple la condición de |g(x)|<1

#include <stdio.h>
#include <math.h>

double f(double x){
  return pow(x, 3)-5*pow(x, 2)-7*x-3;
}

double f1(double x){
  return 3*pow(x, 2)-10*x-7;
}

double f2(double x){
  return 6*x-10;
}

//Método de punto fijo
double g(double x){
    return cbrt(5*pow(x,2) + 7*x + 3);
}

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

// Método de la secante (corregido)
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

  punto_fijo(0.68, tol, maxIter);
  newton(0.68, tol, maxIter);
  secante(0.1, 0.0, tol, maxIter);
  newton_modificado(0.68, tol, maxIter);
}