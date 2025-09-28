//Para este problema, se tenía que repetir lo mismo que el 6
//pero usando Newton Raphson, en este caso es mejor la aproximación con Newton
//Además de que da un erro relativo % muy pequeño, al sustituir el valor
//en la ecuación, se aproxima más al volumen deseado que es de 30 m^3

#include <stdio.h>
#include <math.h>

float f(float h) {
  float R = 3.0f;
  return (M_PI/3.0f) * h*h * (3*R - h) - 30.0f;
}

float df(float h) {
  float R = 3.0f;
  return M_PI * h * (3*R - 1.5f*h);
}

int main(){
  double h0=2.0, h1, Err;
  int nIter=3;
  int iter=0;

  printf("Iter  \t  h_n   \t   f(h_n)   \t   Error\n");

  while (iter<nIter){
    h1 = h0 - f(h0)/df(h0);
    Err=fabs((h1-h0)/h1);

    printf("%d  \t  %f  \t  %f  \t  %f\n", iter, h0, f(h0), Err);

    h0=h1;
    iter++;
  }
  printf("\nProfundidad aproximada h después de %d iteraciones: %.6f m\n", nIter, h1);
  printf("Error relativo porcentual en la última iteración: %.6f %%\n", Err*100.0);

  return 0;
}