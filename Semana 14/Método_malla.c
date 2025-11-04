#include <stdio.h>
#include <math.h>
 
int main() {
  double x_min=-2.0, x_max=2.0;
  double y_min=1.0, y_max=3.0;
  int nx = 100, ny = 100;
 
  double dx=(x_max-x_min)/(nx-1);
  double dy=(y_max-y_min)/(ny - 1);
 
  double x, y, z;
  double zmax=-1e9;
  double xmax=0, ymax=0;

  for (int i=0; i<nx; i++) {
    x=x_min+i*dx;
    for (int j=0; j<ny; j++) {
      y=y_min+j*dy;

      z=y-x-2*pow(x,2)-2*x*y-pow(y,2);

      if (z>zmax) {
          zmax=z;
          xmax=x;
          ymax=y;
      }
    }
  }
 
  printf("Punto máximo:\n");
  printf("x = %.4f, y = %.4f, f(x,y) = %.4f\n", xmax, ymax, zmax);
 
  return 0;
}