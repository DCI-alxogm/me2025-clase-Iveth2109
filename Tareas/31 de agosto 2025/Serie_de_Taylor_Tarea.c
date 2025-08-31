#include <stdio.h>
#include <math.h>

float factorial(int n){
  float fact=1;
  for (int i=1; i<=n; i++){
    fact *=i;
  }
  return fact;
}

float f1(float x){return exp(3*x);}
float f2(float x){return sin(2*x)+cos(x);}
float f3(float x){return log(x+1);}
float f4(float x){return cos(5*x);}
float f5(float x){return sin(x);}

float derivada_k_f1(float x, int k){
  return pow(3, k)*exp(3*x);
}
float derivada_k_f2(float x, int k){
  int mod=k%4;
  if(mod==0) return sin(2*x) + cos(x);
  if(mod==1) return 2*cos(2*x)-sin(x);
  if(mod==2) return -4*sin(2*x)-cos(x);
  return -8*cos(2*x)+sin(x);
}
float derivada_k_f3(float x, int k){
  float signo = (k%2==0) ? 1.0:-1.0;
  float fact=factorial(k-1);  
  if(k==0) return log(x+1);
  return signo*fact/pow(x+1, k);
}
float derivada_k_f4(float x, int k){
  int mod=k%4;
  float factor=pow(5, k);
  if(mod==0) return factor*cos(5*x);
  if(mod==1) return -factor*sin(5*x);
  if(mod==2) return -factor*cos(5*x);
  return factor*sin(5*x);
}
float derivada_k_f5(float x, int k){
  int mod=k%4;
  if(mod==0) return sin(x);
  if(mod==1) return cos(x);
  if(mod==2) return -sin(x);
  return -cos(x);
}

int main(){
  char respuesta;

  do{
  float xi, h, aprox, Rn, error, xi2, m;
  int ordenn, opcion;

  printf("¿Cuál función quiere usar?\n");
  printf("1. e^(3x)\n");
  printf("2. sin(2x)+cos(x)\n");
  printf("3. log(x+1)\n");
  printf("4. cos(5x)\n");
  printf("5. sin(x)\n");
  printf("Opción: ");
  scanf("%d", &opcion);

  printf("Ingrese el valor de xi:");
  scanf("%f", &xi);
  printf("Ingrese el valor de h:");
  scanf("%f", &h);
  printf("Ingrese el orden n:");
  scanf("%d", &ordenn);

  xi2=xi+h;
  m=(xi+xi2)/2;
  aprox=0;

  printf("\n%-3s %-15s %-15s %-15s\n", "n", "Aprox", "Rn", "Error");
  for(int n=0; n<=ordenn; n++){
    float deriv, deriv_medio, valor_real;

    switch(opcion){
      case 1:
        deriv = derivada_k_f1(xi, n);
        deriv_medio = derivada_k_f1(m, n+1);
        valor_real = f1(xi2);
        break;
      case 2:
        deriv = derivada_k_f2(xi, n);
        deriv_medio = derivada_k_f2(m, n+1);
        valor_real = f2(xi2);
        break;
      case 3:
        deriv = derivada_k_f3(xi, n);
        deriv_medio = derivada_k_f3(m, n+1);
        valor_real = f3(xi2);
        break;
      case 4:
        deriv = derivada_k_f4(xi, n);
        deriv_medio = derivada_k_f4(m, n+1);
        valor_real = f4(xi2);
        break;
      case 5:
        deriv = derivada_k_f5(xi, n);
        deriv_medio = derivada_k_f5(m, n+1);
        valor_real = f5(xi2);
        break;
      default:
        printf("Opción invalida");
        return 1;
    }
    aprox += deriv*pow(h, n)/factorial(n);
    Rn=deriv_medio*pow(h, n+1)/factorial(n+1);
    error=valor_real-aprox;

    printf("%-3d %-15.10f %-15.10f %-15.10f\n", n, aprox, Rn, error);
  }

    printf("\n¿Quieres usar otra función (s/n)?");
    scanf(" %c", &respuesta);
  } while (respuesta=='s'|| respuesta=='S');
  return 0;
}