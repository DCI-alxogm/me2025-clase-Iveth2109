#include <stdio.h>
#include <math.h>

float fx(float x);

int main(){
  int i;
  float a=-2, b=2, h=0.25;
  int n=(int)((b-a)/h)+1;
  float x[n], fpa[n], fpb[n], fpc[n], sda[n], sdb[n], sdc[n];

  for(i=0; i<n; i++){
    x[i]=a+i*h;
  }

  for(i=0; i<n; i++){
    fpa[i]=(fx(x[i+1])-fx(x[i]))/h;
    fpb[i]=(fx(x[i])-fx(x[i-1]))/h;
    fpc[i]=(fx(x[i+1])-fx(x[i-1]))/h;
  }

  printf("Primera derivada\n");
  printf("%-10s %-12s %-12s %-12s\n", "x", "Adelante", "Atras", "Centrada");
  for(i=0; i<n; i++){
    printf("%-10.2f %-12.4f %-12.4f %-12.4f\n", x[i], fpa[i], fpb[i], fpc[i]);
  }

  for(i=0; i<n; i++){
    sda[i] = (fx(x[i+2]) - 2*fx(x[i+1]) + fx(x[i])) / (h*h);
    sdb[i] = (fx(x[i-2]) - 2*fx(x[i-1]) + fx(x[i])) / (h*h);
    sdc[i] = (fx(x[i+1]) - 2*fx(x[i]) + fx(x[i-1])) / (h*h);
  }

  printf("\nSegunda derivada");
  printf("\n%-10s %-12s %-12s %-12s\n", "x", "Adelante", "Atras", "Centrada");
  for(i=0; i<n; i++){
    printf("%-10.2f %-12.4f %-12.4f %-12.4f\n", x[i], sda[i], sdb[i], sdc[i]);
  }

  FILE *fp = fopen("resultados.csv", "w");
  if(fp == NULL){
    printf("\nError al crear el archivo.\n");
    return 1;
  }

  fprintf(fp, "x,Primera_Adelante,Primera_Atras,Primera_Centrada,Segunda_Adelante,Segunda_Atras,Segunda_Centrada\n");

  for(i=0; i<n; i++){
    fprintf(fp, "%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f\n",
            x[i], fpa[i], fpb[i], fpc[i], sda[i], sdb[i], sdc[i]);
  }

  fclose(fp);
  printf("\nDatos guardados en 'resultados.csv'.\n");

}

float fx(float x){
    return x*x*x - 2*x + 4;
}