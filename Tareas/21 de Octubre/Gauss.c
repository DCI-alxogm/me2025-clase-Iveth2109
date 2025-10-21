#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
  int n, i, j, k, m;
  double A[MAX][MAX], B[MAX], X[MAX], factor, suma, temp;
  FILE *archivo;

  //Dimensión de la matriz
  archivo = fopen("datos.txt", "r");
    if (!archivo) {
      printf("No se pudo abrir el archivo.\n");
      return 1;
    }

  fscanf(archivo, "%d", &n);
  printf("La matriz tiene dimensión %d x %d\n", n, n);

  //Matriz A
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      fscanf(archivo, "%lf", &A[i][j]);

  //Vector B
  for (i = 0; i < n; i++)
    fscanf(archivo, "%lf", &B[i]);
  fclose(archivo);

  //Matriz original
  printf("\nMatriz original:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
        printf("%8.3f ", A[i][j]);
      printf("| %8.3f\n", B[i]);
  }

  //Eliminación hacia adelante con intercambio y normalización
  for (k = 0; k < n - 1; k++) {

  //Intercambiar filas
  if (A[k][k] == 0) {
    int filaCambio = -1;
    for (i = k + 1; i < n; i++) {
      if (A[i][k] != 0) {
        filaCambio = i;
        break;
      }
    }

  if (filaCambio != -1) {
  for (m = 0; m < n; m++) {
    temp = A[k][m];
    A[k][m] = A[filaCambio][m];
    A[filaCambio][m] = temp;
  }
    temp = B[k];
    B[k] = B[filaCambio];
    B[filaCambio] = temp;

      printf("\nSe intercambió la fila %d con la fila %d (pivote nulo)\n", k + 1, filaCambio + 1);
    } else {
      printf("\nNo se encontró fila con pivote no nulo en columna %d\n", k + 1);
      return 1;
    }
  }

  //Normalización de filas
  if (A[k][k] != 1) {
    double pivote = A[k][k];
    for (j = k; j < n; j++)
        A[k][j] /= pivote;
      B[k] /= pivote;

      printf("Se normalizó la fila %d dividiendo entre %.6f para que el pivote sea 1.\n", k + 1, pivote);
  }

  //Eliminación hacia adelante
  for (i = k + 1; i < n; i++) {
    factor = A[i][k] / A[k][k];
    for (j = k; j < n; j++)
        A[i][j] -= factor * A[k][j];
      B[i] -= factor * B[k];
  }

  //Imprimir matriz
  printf("\nMatriz después de eliminar columna %d:\n", k + 1);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
        printf("%8.3f ", A[i][j]);
    printf("| %8.3f\n", B[i]);
    }
  }

  //Normalización última fila
  if (A[n-1][n-1] != 1) {
    double pivote = A[n-1][n-1];
    A[n-1][n-1] /= pivote;  // solo un elemento no cero
    B[n-1] /= pivote;
    printf("\nSe normalizó la última fila dividiendo entre %.6f para que el pivote sea 1.\n", pivote);

  // Imprimir matriz
  printf("\nMatriz después de normalizar la última fila:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
        printf("%8.3f ", A[i][j]);
      printf("| %8.3f\n", B[i]);
    }
  }

  //Sustitución regresiva
  for (i = n - 1; i >= 0; i--) {
    suma = 0;
    for (j = i + 1; j < n; j++)
        suma += A[i][j] * X[j];
      X[i] = (B[i] - suma) / A[i][i];
  }
  //Evaluar si está mal condicionado
  int malCondicionado = 0;
  for (k = 0; k < n; k++) {
    if (fabs(A[k][k]) < 1e-6) {
      malCondicionado = 1;
      break;
    }
  }
  if (malCondicionado)
    printf("\nEl sistema podría estar mal condicionado (pivote muy pequeño)\n");
  else
    printf("\nEl sistema parece estar bien condicionado\n");

  //Resultado final
  printf("\nSolución del sistema:\n");
  for (i = 0; i < n; i++)
    printf("X%d = %.6f\n", i + 1, X[i]);

  return 0;
}