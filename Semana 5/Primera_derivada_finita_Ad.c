#include <stdio.h>
#include <math.h>

float fx(float x);

int main(){
  int i;
  float a=-2, b=2, h=0.25;
  int n=(int)((b-a)/h)+1;
  float x[n], fpa[n];

  for(i=0; i<n; i++){
    x[i]=a+i*h;
  }
  for(i=0; i<n; i++){
    fpa[i]=(fx(x[i+1])-fx(x[i]))/h;
    printf("%f  %f\n", x[i], fpa[i]);
  }
}

float fx(float x){
  float f;
  f=x*x*x-2*x+4;
  return f;
}