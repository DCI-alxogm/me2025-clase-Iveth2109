#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
  int n, i, j, iter, max_iter;
  double A[MAX][MAX], B[MAX], X[MAX], X_old[MAX];
  double suma, error, tol;
  FILE *archivo;

  archivo = fopen("datos.txt", "r");
  if (!archivo) {
    printf("No se pudo abrir el archivo.\n");
    return 1;
  }

  fscanf(archivo, "%d", &n);
  printf("La matriz tiene dimensión %d x %d\n", n, n);

  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      fscanf(archivo, "%lf", &A[i][j]);

  for (i=0; i<n; i++)
    fscanf(archivo, "%lf", &B[i]);

  fclose(archivo);

  printf("\nMatriz del sistema (A|B):\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++)
      printf("%8.3f ", A[i][j]);
    printf("| %8.3f\n", B[i]);
  }

  printf("\nIngrese la tolerancia del error: ");
  scanf("%lf", &tol);
  printf("Ingrese el número máximo de iteraciones: ");
  scanf("%d", &max_iter);

  for (i=0; i<n; i++)
    X[i]=0.0;

  printf("\nIteraciones del método Gauss-Seidel:\n");

  for (iter=1; iter<=max_iter; iter++) {
    for (i=0; i<n; i++)
      X_old[i]=X[i];

    for (i=0; i<n; i++) {
      suma=0;
      for (j=0; j<n; j++) {
        if (j!=i)
        suma+=A[i][j]*X[j];
      }
      X[i]=(B[i]-suma)/A[i][i];
    }

  error=fabs(X[0]-X_old[0]);
    for (i=1; i<n; i++) {
      double e=fabs(X[i]-X_old[i]);
      if (e>error)
        error=e;
    }

  printf("Iteración %d: ", iter);
  for (i=0; i<n; i++)
    printf("X%d = %.6f  ", i+1, X[i]);
  printf(" Error = %.6e\n", error);

  if (error < tol) {
    printf("\nConvergencia alcanzada en %d iteraciones.\n", iter);
    break;
  }
  }

  if (iter>max_iter)
    printf("\nNo se alcanzó la convergencia en %d iteraciones.\n", max_iter);

  printf("\nSolución aproximada:\n");
  for (i=0; i<n; i++)
    printf("X%d = %.6f\n", i+1, X[i]);

  return 0;
}