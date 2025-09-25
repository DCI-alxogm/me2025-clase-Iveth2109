#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

float factorial(int n){
    float fact=1;
    for (int i=1; i<=n; i++){
        fact *=i;
    }
    return fact;
}

// Funciones
float f1(float x){return x - 1 - 0.5*sin(x);}
float f2(float x){return log(x);}

// Derivadas k-ésimas
float derivada_k_f1(float x, int k){
    int mod=k%4;
    if(mod==0) return x - 1 - 0.5*sin(x);
    if(mod==1) return 1 - 0.5*cos(x);
    if(mod==2) return 0.5*sin(x);
    return 0.5*cos(x);
}

float derivada_k_f2(float x, int k){
    if(k==0) return log(x);
    else return pow(-1, k-1) * factorial(k-1) / pow(x, k);
}

// Función auxiliar para leer número o pi
float leer_valor(char* mensaje){
    char input[20];
    float valor;
    printf("%s", mensaje);
    scanf("%s", input);

    if(strcmp(input, "pi")==0) valor = M_PI;
    else if(strcmp(input, "pi/2")==0) valor = M_PI/2;
    else if(strcmp(input, "pi/4")==0) valor = M_PI/4;
    else valor = atof(input);

    return valor;
}

int main(){
    char respuesta;

    do{
        float xi, h, aprox, Rn, error, xi2, m;
        int ordenn, opcion;

        printf("¿Cuál función quiere usar?\n");
        printf("1. x - 1 - 0.5*sin(x)\n");
        printf("2. ln(x)\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        // Leer xi y h con soporte para pi
        xi = leer_valor("Ingrese el valor de xi (número o pi, pi/2, pi/4): ");
        h  = leer_valor("Ingrese el valor de h (número o pi, pi/2, pi/4): ");
        
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
                    deriv_medio = derivada_k_f1(xi, n+1);  
                    valor_real = f1(xi2);
                    break;
                case 2:
                    deriv = derivada_k_f2(xi, n);
                    deriv_medio = derivada_k_f2(xi, n+1);
                    valor_real = f2(xi2);
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