#include <stdio.h>
#include <math.h>

float f(float x){
  return sin(10*x)-cos(3*x);
}

int main(){
  float Err_max=0.0001;
  float a=3.0f, b=5.0f;
  float subin=0.05;
  float x1, x2, k, Err, kold, fk, Eapr, Ea;
  int r=0, n;
  float a0, b0;

  x1=a;
  while (x1<b){
    x2=x1+subin;

    if(f(x1)*f(x2)<0.0f){
      r++;
      printf("Raíz %d en el intervalo [%f , %f]\n", r, x1, x2);
      printf("n  \t   f(k)  \t  Eaprox   \t   E_r   \t    Ea\n");

      kold=INFINITY;
      n=0;
      a0=x1;
      b0=x2;

      do{
        n++;
        k=(x1+x2)/2.0f;
        fk=f(k);

        if (f(k)*f(x1)<0.0f){
          x2=k;
        }else{
          x1=k;
        }
        Eapr=k-kold;
        Err=fabs(Eapr)/fabs(k);
        Ea=(b0-a0)/pow(2,n);
        kold=k;
        printf("%d   \t   %f   \t   %f   \t   %f   \t   %f   \t   %f\n", n, k, fk, Eapr, Err, Ea);
      } while (Err>Err_max);

      printf("La raíz aproximada es: %.7f\n", k);
      printf("f(c_raíz)=%7f\n", f(k));
    }
    x1=x2;
  }
  printf("\nTotal de raíces encontradas: %d\n", r);
}