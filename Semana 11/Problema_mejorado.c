#include <stdio.h>
 
int main() {
  double A[3][3]={
    {0, 2, 3},
    {4, 6, 7},
    {2, 1, 6}
  };
  double B[3]={8, -3, 5};
  double X[3];
  double factor, suma, temp;
  int n, m, k;

  if(A[0][0]==0){
    for(m=0; m<3; m++){
      temp=A[0][m];
      A[0][m]=A[1][m];
      A[1][m]=temp;
    }
    temp=B[0];
    B[0]=B[1];
    B[1]=temp;

    printf("\nSe intercambió la fila 1 con la fila 2 porque A[0][0] es igual a 0\n");
  }

  for (k=0; k<2; k++) {
    for (n=k+1; n<3; n++) {
        factor=A[n][k]/A[k][k];
        for (m=k; m<3; m++) {
            A[n][m]=A[n][m]-factor*A[k][n];
        }
        B[n]=B[n]-factor*B[k];
      }
    }
 
  for (n=2; n>=0; n--) {
      suma=0;
      for (m=n+1; m<3; m++) {
          suma+=A[n][m]*X[m];
      }
      X[n]=(B[n]-suma)/A[n][n];
    }
  printf("Soluciones del sistema:\n");
    for (n=0; n<3; n++) {
      printf("X%d = %.6f\n", n+1, X[n]);
    }
  return 0;
}