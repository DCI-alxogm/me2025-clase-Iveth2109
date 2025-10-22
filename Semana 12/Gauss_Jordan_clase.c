//Resultados obtenidos del este código
//La matriz tiene dimensión 3 x 3

//Matriz original:
   //3.000   -0.100   -0.200 |    7.850
   //0.100    7.000   -0.300 |  -19.300
   //0.300   -0.200   10.000 |   71.400
//Se normalizó la fila 1 dividiendo entre 3.000000 para que el pivote sea 1.

//Matriz después del paso 1:
   //1.000   -0.033   -0.067 |    2.617
   //0.000    7.003   -0.293 |  -19.562
   //0.000   -0.190   10.020 |   70.615
//Se normalizó la fila 2 dividiendo entre 7.003333 para que el pivote sea 1.

//Matriz después del paso 2:
   //1.000    0.000   -0.068 |    2.524
   //0.000    1.000   -0.042 |   -2.793
   //0.000    0.000   10.012 |   70.084
//Se normalizó la fila 3 dividiendo entre 10.012042 para que el pivote sea 1.

//Matriz después del paso 3:
   //1.000    0.000    0.000 |    3.000
   //0.000    1.000    0.000 |   -2.500
   //0.000    0.000    1.000 |    7.000

//El sistema parece estar bien condicionado

//Solución del sistema:
//X1 = 3.000000
//X2 = -2.500000
//X3 = 7.000000

#include <stdio.h>
#include <math.h>

#define MAX 10

int main() {
  int n, i, j, k, m;
  double A[MAX][MAX], B[MAX], X[MAX], factor, temp;
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

  //Método de Gauss-Jordan
  for (k = 0; k < n; k++) {

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
    for (j = 0; j < n; j++)
      A[k][j] /= pivote;
    B[k] /= pivote;

    printf("Se normalizó la fila %d dividiendo entre %.6f para que el pivote sea 1.\n", k + 1, pivote);
  }

  //Eliminar los demás elementos en la columna k
  for (i = 0; i < n; i++) {
    if (i != k) {
      factor = A[i][k];
      for (j = 0; j < n; j++)
        A[i][j] -= factor * A[k][j];
      B[i] -= factor * B[k];
    }
  }

  // Imprimir matriz
  printf("\nMatriz después del paso %d:\n", k + 1);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("%8.3f ", A[i][j]);
    printf("| %8.3f\n", B[i]);
    }
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

  //Imprimir resultados
  printf("\nSolución del sistema:\n");
  for (i = 0; i < n; i++) {
    X[i] = B[i];
    printf("X%d = %.6f\n", i + 1, X[i]);
  }

  return 0;
}