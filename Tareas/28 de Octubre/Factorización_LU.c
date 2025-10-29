#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
  int n, i, j, k;
  double A[MAX][MAX], L[MAX][MAX], U[MAX][MAX], B[MAX], Y[MAX], X[MAX];
  FILE *archivo, *salida;

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

  for (i=0; i<n; i++)
    for (j=0; j<n; j++) {
      L[i][j]=0.0;
      U[i][j]=0.0;
    }

  printf("\nINICIO DE FACTORIZACIÓN LU\n");

  for (i=0; i<n; i++) {
    printf("\nPaso %d:\n", i+1);

    for (j=i; j<n; j++) {
      double suma=0;
      for (k=0; k<i; k++)
        suma+=L[i][k]*U[k][j];
      U[i][j]=A[i][j]-suma;
      printf("U[%d][%d] = %.6f\n", i+1, j+1, U[i][j]);
    }

    for (j=i; j<n; j++) {
      if (i==j) {
        L[i][i]=1.0;
        printf("L[%d][%d] = 1.000000\n", i+1, i+1);
      } else {
        double suma=0;
        for (k=0; k<i; k++)
          suma+=L[j][k]*U[k][i];
        L[j][i]=(A[j][i]-suma)/U[i][i];
        printf("L[%d][%d] = %.6f\n", j+1, i+1, L[j][i]);
      }
    }

    printf("\nMatriz L (parcial):\n");
    for (k=0; k<n; k++) {
      for (j=0; j<n; j++)
        printf("%8.3f ", L[k][j]);
      printf("\n");
    }

    printf("\nMatriz U (parcial):\n");
    for (k=0; k<n; k++) {
      for (j=0; j<n; j++)
        printf("%8.3f ", U[k][j]);
      printf("\n");
    }
  }

  // Guardar matrices L y U en un archivo
  salida = fopen("matrices_LU.txt", "w");
  if (!salida) {
    printf("No se pudo crear el archivo matrices_LU.txt\n");
    return 1;
  }

  fprintf(salida, "%d\n", n);
  fprintf(salida, "Matriz L:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++)
      fprintf(salida, "%.6f ", L[i][j]);
    fprintf(salida, "\n");
  }

  fprintf(salida, "Matriz U:\n");
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++)
      fprintf(salida, "%.6f ", U[i][j]);
    fprintf(salida, "\n");
  }
  fclose(salida);
  printf("\nLas matrices L y U se guardaron en 'matrices_LU.txt'\n");

  printf("\nSustitución hacia adelante (L·Y=B)\n");
  for (i=0; i<n; i++) {
    double suma=0;
    for (j=0; j<i; j++)
      suma+=L[i][j]*Y[j];
    Y[i]=B[i]-suma;
    printf("Y[%d] = %.6f\n", i+1, Y[i]);
  }

  printf("\nSustitución regresiva (U·X=Y)\n");
  for (i=n-1; i>=0; i--) {
    double suma=0;
    for (j=i+1; j<n; j++)
      suma+=U[i][j]*X[j];
    X[i]=(Y[i]-suma)/U[i][i];
    printf("X[%d] = %.6f\n", i+1, X[i]);
  }

  printf("\nSolución final del sistema\n");
  for (i=0; i<n; i++)
    printf("X%d = %.6f\n", i+1, X[i]);

  return 0;
}