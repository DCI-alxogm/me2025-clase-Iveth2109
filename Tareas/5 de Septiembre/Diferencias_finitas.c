#include <stdio.h>
#include <math.h>

int main(){
  float xi1, xi, xi2, fi1, fi, fi2, fad, fat, fcen, error_ad, error_at, error_cen, error_real;
  xi1=0;
  xi=0.5;
  xi2=1;

  fi1=1.2;
  fi=0.925;
  fi2=0.2;

  error_real=-0.9125;

  //Derivada hacía adelante
  fad=(fi2-fi)/(xi2-xi);
  error_ad=((error_real-fad)/error_real)*100;

  //Derivada hacía atras
  fat=(fi-fi1)/(xi-xi1);
  error_at=((error_real-fat)/error_real)*100;

  //Derivada centrada
  fcen=(fi2-fi1)/(xi2-xi1);
  error_cen=((error_real-fcen)/error_real)*100;

  printf("Valores de las derivadas\n");
  printf("\n%f    %f   %f\n", fad, fat, fcen);
  printf("\nError porcentual relativo\n");
  printf("\n%f    %f    %f", error_ad, error_at, error_cen);
}