#include <stdio.h>
#include <math.h>

float f(float x){
    return 25*pow(x,3) - 6*pow(x,2) + 7*x - 88;
}

float f_derivada_exacta(float x){
    return 75*pow(x,2) - 12*x + 7;  // f'(x) exacta
}

int main(){
    float xi, h;
    float xi1, xi2;
    float fi1, fi, fi2;
    float fad, fat, fcen;
    float error_ad, error_at, error_cen;
    float error_real;

    xi = 2.0; 
    h = 0.2;

    xi1 = xi - h;
    xi2 = xi + h;

    fi1 = f(xi1);
    fi  = f(xi);
    fi2 = f(xi2);

    error_real = f_derivada_exacta(xi);

    printf("Derivada exacta en x = %f: %f\n\n", xi, error_real);

    // Derivada hacia adelante
    fad = (fi2 - fi) / (xi2 - xi);
    error_ad = ((error_real - fad)/error_real) * 100;

    // Derivada hacia atrás 
    fat = (fi - fi1) / (xi - xi1);
    error_at = ((error_real - fat)/error_real) * 100;

    // Derivada centrada 
    fcen = (fi2 - fi1) / (xi2 - xi1);
    error_cen = ((error_real - fcen)/error_real) * 100;

    printf("Valores de las derivadas\n");
    printf("Hacia adelante: %f\nHacia atras: %f\nCentrada: %f\n", fad, fat, fcen);
    printf("\nError porcentual relativo (%%)\n");
    printf("Hacia adelante: %f\nHacia atras: %f\nCentrada: %f\n", error_ad, error_at, error_cen);

    return 0;
}