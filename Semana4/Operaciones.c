#include <stdio.h>
#include <math.h>

int main(){
  int a, b, c, d;
  a=3;
  b=4;
  c=5;
  d=7;

  printf("Valores asignados");
  printf("\n%d %d %d %d", a, b, c, d);
  printf("\nValores de las funciones");
  printf("\ne=(a+b)*c7d= %d", (a+b)*c/d);
  printf("\ne=((a+b)*c)/d =%d", ((a+b)*c)/d);
  printf("\ne=a+b*c/d= %d", a+b*c/d);
  printf("\ne=a+(b*c)/d= %d", a+(b*c)/d);
}