//Ejercicio en clase 8 de agosto de 2025
//Laura Iveth Martinez Prado

#include <stdio.h>
#include <math.h>

int main(){
  float numeros[5];
  numeros[0]=3.1;
  numeros[1]=3.4;
  numeros[2]=3.8;
  numeros[3]=4.2;
  numeros[4]=4.6;

  printf("Valores de los flotantes");
  printf("\n%f %f %f %f %f", numeros[0], numeros[1], numeros[2], numeros[3], numeros[4]);
  printf("\nValores de las funciones");
  printf("\nValores al cuadrado");
  printf("\n%f %f %f %f %f", numeros[0]*numeros[0], numeros[1]*numeros[1], numeros[2]*numeros[2], numeros[3]*numeros[3], numeros[4]*numeros[4]);
  printf("\nValores exp(x)+cos(x)");
  printf("\n%f %f %f %f %f", exp(numeros[0])+cos(numeros[0]), exp(numeros[1])+cos(numeros[1]), exp(numeros[2])+cos(numeros[2]), exp(numeros[3])+cos(numeros[3]), exp(numeros[4])+cos(numeros[4]));
  printf("\nValores log(x+1)");
  printf("\n%f %f %f %f %f", log(numeros[0])+1, log(numeros[1])+1, log(numeros[2])+1, log(numeros[3])+1, log(numeros[4])+1);
}