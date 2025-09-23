#include <stdio.h>
#include <math.h>

double f(double x){
  return pow(x, 10)-1;
}

double f1(double x){
  return 10*pow(x, 9);
}

double f2(double x){
  return 90*pow(x, 8);
}

//Método de punto fijo
double g(double x){
  return pow(x, 1.0/10.0);
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

//Método de la secante
void secante(double x0, double x1, double tol, int maxIter){
  int iter=0;
  double x2, Err;

  printf("\n    Método de la secante    \n");
  printf("Iter\t    xi-1\t\t  xi\t\t  xi+1\t\t  Error\n");

  while (iter<maxIter){
    x2=x0-f(x0)*(x1-x0)/(f(x1)-f(x0));
    Err=fabs((x2-x1)/x2);
    printf("%d\t  %f\t  %f\t  %f\t  %e\n", iter, x0, x1, x2, Err);
    
    if(Err<tol){
      printf("\nConvergió en %d iteraciones\n", iter+1);
      printf("La raíz aproximada es: %f\n", x1);
      return;
    }
    x0=x2;
    iter++;
  }
  printf("\nNo convergió\n");
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
  secante(0.5, 0.4, tol, maxIter);
  newton_modificado(0.5, tol, maxIter);
}