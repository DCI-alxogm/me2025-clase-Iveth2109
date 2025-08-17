//Laura Iveth Martínez Prado
//13 de agosto de 2025

#include <stdio.h>

int main(){

int n;
char respuesta;

do{
printf("Introduce un número para saber si es par o impar\n");
scanf("%d", &n);
  if(n%2==0){
  printf("El numero es par");
  }
  else{
  printf("El número es impar");
  }
printf("\n¿Quieres introducir otro número (s/n?\n");
scanf(" %c", &respuesta);
}while (respuesta=='s');

return 0;

}