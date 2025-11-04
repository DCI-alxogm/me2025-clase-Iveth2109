#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f(double x, double y) {
    return y-x-2*x*x-2*x*y-y*y;
}
 
int main() {
    double x_min=-2.0, x_max=2.0;
    double y_min=1.0, y_max=3.0;
 
    int N=5000; 
 
    double x_rand, y_rand, z;
    double best_x=0, best_y=0, best_z=-1e9;

    srand(time(NULL));

    for (int i=0; i<N; i++) {
        x_rand=x_min+(double)rand()/RAND_MAX*(x_max-x_min);
        y_rand=y_min+(double)rand()/RAND_MAX*(y_max-y_min);
 
        z=f(x_rand, y_rand);

        if (z>best_z) {
            best_z=z;
            best_x=x_rand;
            best_y=y_rand;
        }
    }
 
    printf("Máximo encontrado:\n");
    printf("x = %.4f, y = %.4f, f(x,y) = %.4f\n", best_x, best_y, best_z);
 
    return 0;
}