//Laura Iveth Martínez Prado
//Raíces de un binomio
//Ejercicio en clase 15 de agosto de 2025 

#include <stdio.h>
#include <math.h>

int main(){
  float a,b,c, x1, x2, xi1, xi2, discr;
  char respuesta;

  do{
  printf("Ingresa el valor de a\n");
  scanf("%f", &a);
  printf("\nIngresa el valor de b\n");
  scanf("%f", &b);
  printf("\nIngresa el valor de c\n");
  scanf("%f", &c);

  if(a==0){
    if(b==0){
      printf("No hay solución\n");
    }
    else{
      x1=-c/b;
      printf("El valor de x1 es %f\n", x1);
    }
  }
  else{
    discr=(b*b)-(4*a*c);

    if(discr>0){
      x1=(-b+sqrt(discr))/(2*a);
      x2=(-b-sqrt(discr))/(2*a);
      printf("Las raíces reales son: x1=%f, x2=%f\n", x1, x2);
    }
    else if(discr==0){
      x1=-b/(2*a);
      printf("La raíz doble es: x=%f\n", x1);
    }
    else{
      printf("Las raíces son complejas\n");
      x1=-b/(2*a);
      x2=x1;
      xi1=sqrt(fabs(discr))/(2*a);
      xi2=-xi1;
      printf("Las raíces complejas son: %f+%fi  y  %f%fi\n", x1, xi1, x2, xi2);
    }
  }

  printf("\n¿Quieres introducir otros números (s/n)?\n");
  scanf(" %c", &respuesta);
  }while (respuesta=='s');

  return 0;
}
