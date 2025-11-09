#include <stdio.h>
#include <math.h>

#define MAX 10

double f(double *x, int n) {
    // Para n=2 → x[0]=x, x[1]=y
    return 2*x[0]*x[1]+2*x[0]-x[0]*x[0]-2*x[1]*x[1];
}

void gradiente(double *x, double *grad, int n, double delta) {
  double temp[MAX];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) temp[j]=x[j];
    temp[i]=x[i]+delta;
    double f1=f(temp, n);
    temp[i]=x[i]-delta;
    double f2=f(temp, n);
    grad[i]=(f1-f2)/(2*delta);
  }
}

int main() {
  int n=2; // número de variables
  double x[MAX]={-1.0, 1.0};
  double grad[MAX];
  double delta=1e-5, tol=1e-6;
  double h=0.1; //Tamaño de paso fijo
  int maxIter=1000;

  printf("Iter\t");
  for (int i=0; i<n; i++) printf("x%d\t\t", i+1);
  printf("f(x)\n");

  for (int iter=0; iter<maxIter; iter++) {
    gradiente(x, grad, n, delta);

    double norm=0;
    for (int i=0; i<n; i++) norm+=grad[i]*grad[i];
    norm = sqrt(norm);

  printf("%d\t", iter);
  for (int i=0; i<n; i++) printf("%.6f\t", x[i]);
  printf("%.6f\n", f(x, n));

  if (norm < tol) break;
    for (int i=0; i<n; i++)
      x[i]=x[i]+h*grad[i];
  }
  printf("\nPunto aproximado:\n");
  for (int i=0; i<n; i++)
    printf("x%d = %.6f\n", i+1, x[i]);
  printf("f(x) = %.6f\n", f(x, n));

  return 0;
}