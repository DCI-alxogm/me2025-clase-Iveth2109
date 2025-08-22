//Laura Iveth Martinez Prado
//Serie de Mclaurin
//22 de agosto de 2025

#include <stdio.h>
#include<math.h>

int main(){
  float x, Es, Ea, aprox_act, termino, aprox_ant;
  int n;
  char respuesta;

  float factorial(int n){
    float fact=1;
    for (int i=1; i<=n; i++){
      fact *=i;
    }
    return fact;
  }

  do{
    printf("Ingresa el valor de x\n");
    scanf("%f", &x);
    printf("Ingresa el valor del error deseado (%%)\n");
    scanf("%f", &Es);

    printf("\nn   Aprox(e^x)    Error(%%)\n");

    aprox_act=0;
    aprox_ant=0;
    n=0;
    Ea=100;

    while (Ea>Es){
      termino=pow(x, n)/factorial(n);
      aprox_ant=aprox_act;
      aprox_act += termino;

      if (n==0){
        printf("%d    %f    -\n", n, aprox_act);
      } else{
        Ea=fabs((aprox_act-aprox_ant)/aprox_act)*100;
        printf("%d    %f    %f\n", n, aprox_act, Ea);
      }

      n++;
    }

    printf("¿Quieres ntroducir otros valores? (s/n)\n");
    scanf(" %c", &respuesta);
  
  } while (respuesta == 's');

  return 0;
}