#include <stdio.h>
#include <math.h>

// ===== Primera función =====
float fA(float x) {
    return exp(3*x);
}
float fA1(float x) {
    return pow(3,1)*exp(3*x);
}
float fA2(float x) {
    return pow(3,2)*exp(3*x);
}
float fA3(float x) {
    return pow(3,3)*exp(3*x);
}
float fA4(float x) {
    return pow(3,4)*exp(3*x);
}
float fA5(float x) {
    return pow(3,5)*exp(3*x);
}
float fA6(float x) {
    return pow(3,6)*exp(3*x);
}
float fA7(float x) {
    return pow(3,7)*exp(3*x);
}
float fA8(float x) {
    return pow(3,8)*exp(3*x);
}
float fA9(float x) {
    return pow(3,9)*exp(3*x);
}
float fA10(float x) {
    return pow(3,10)*exp(3*x);
}

// ===== Segunda función =====
float fB(float x) {
    return sin(2*x)+cos(x);
}
float fB1(float x) {
    return 2*cos(2*x)-sin(x);
}
float fB2(float x) {
    return -4*sin(2*x)-cos(x);
}
float fB3(float x) {
    return -8*cos(2*x)+sin(x);
}
float fB4(float x) {
    return 16*sin(2*x)+cos(x);
}
float fB5(float x) {
    return 32*cos(2*x)-sin(x);
}
float fB6(float x) {
    return -64*sin(2*x)-cos(x);
}
float fB7(float x) {
    return -128*cos(2*x)+sin(x);
}
float fB8(float x) {
    return 256*sin(2*x)+cos(x);
}
float fB9(float x) {
    return 512*cos(2*x)-cos(x);
}
float fB10(float x) {
    return -1024*sin(2*x)-cos(x);
}


float fC(float x) {
    return log(x+1);
}
float fC1(float x) {
    return 1/(x+1);
}
float fC2(float x) {
    return -1/pow(x+1,2);
}
float fC3(float x) {
    return 2/pow(x+1,3);
}
float fC4(float x) {
    return -6/pow(x+1,4);
}
float fC5(float x) {
    return 24/pow(x+1,5);
}
float fC6(float x) {
    return -120/pow(x+1,6);
}
float fC7(float x) {
    return 720/pow(x+1,7);
}
float fC8(float x) {
    return -5040/pow(x+1,8);
}
float fC9(float x) {
    return 40320/pow(x+1,9);
}
float fC10(float x) {
    return -362880/pow(x+1,10);
}


float fD(float x) {
    return cos(5*x);
}
float fD1(float x) {
    return -5*sin(5*x);
}
float fD2(float x) {
    return -25*cos(5*x);
}
float fD3(float x) {
    return 125*sin(5*x);
}
float fD4(float x) {
    return 625*cos(5*x);
}
float fD5(float x) {
    return -3125*sin(5*x);
}
float fD6(float x) {
    return -15625*cos(5*x);
}
float fD7(float x) {
    return 78125*sin(5*x);
}
float fD8(float x) {
    return 390625*cos(5*x);
}
float fD9(float x) {
    return -1953125*sin(5*x);
}
float fD10(float x) {
    return -9765625*cos(5*x);
}

float fE(float x) {
    return sin(x);
}
float fE1(float x) {
    return cos(x);
}
float fE2(float x) {
    return -sin(x);
}
float fE3(float x) {
    return -cos(x);
}
float fE4(float x) {
    return sin(x);
}
float fE5(float x) {
    return cos(x);
}
float fE6(float x) {
    return -sin(x);
}
float fE7(float x) {
    return -cos(x);
}
float fE8(float x) {
    return sin(x);
}
float fE9(float x) {
    return cos(x);
}
float fE10(float x) {
    return -sin(x);
}

// Factorial
float factorial(int n) {
    float fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    float xi, h;
    int orden_max, opcion;

    // Punteros a funciones
    float (*f)(float);
    float (*f1)(float);
    float (*f2)(float);
    float (*f3)(float);
    float (*f4)(float);
    float (*f5)(float);
    float (*f6)(float);
    float (*f7)(float);
    float (*f8)(float);
    float (*f9)(float);
    float (*f10)(float);

    // Menú de funciones
    printf("Elige la funcion:\n");
    printf("1. e^3x\n");
    printf("2. sin(2x)+cos(x)\n");
    printf("3. log(x+1)\n");
    printf("4. cos(5x)\n");
    printf("5. sen(x)\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        f = fA; f1 = fA1; f2 = fA2; f3 = fA3; f4 = fA4; f5 = fA5; f6 = fA6; f7 = fA7; f8 = fA8; f9 = fA9; f10 = fA10;
    } else if (opcion == 2) {
        f = fB; f1 = fB1; f2 = fB2; f3 = fB3; f4 = fB4; f5 = fB5; f6 = fB6; f7 = fB7; f8 = fB8; f9 = fB9; f10 = fB10;
    } else if (opcion == 3) {
        f = fC; f1 = fC1; f2 = fC2; f3 = fC3; f4 = fC4; f5 = fC5; f6 = fC6; f7 = fC7; f8 = fC8; f9 = fC9; f10 = fC10;
    } else if (opcion == 4) {
        f = fD; f1 = fD1; f2 = fD2; f3 = fD3; f4 = fD4; f5 = fD5; f6 = fD6; f7 = fD7; f8 = fD8; f9 = fD9; f10 = fD10;
    } else if (opcion == 5) {
        f = fE; f1 = fE1; f2 = fE2; f3 = fE3; f4 = fE4; f5 = fE5; f6 = fE6; f7 = fE7; f8 = fE8; f9 = fE9; f10 = fE10;
    }

    // Datos de entrada
    printf("Ingresa el valor de xi: ");
    scanf("%f", &xi);
    printf("Ingresa el valor de h: ");
    scanf("%f", &h);
    printf("Ingresa el orden maximo (0 a 9): ");
    scanf("%d", &orden_max);

    float xi1 = xi + h;
    float m = (xi1 + xi) / 2.0;

    printf("\nn   Aproximacion      Rn           Error\n");

    for (int n = 0; n <= orden_max; n++) {
        float aprox = f(xi); // término n=0

        if (n >= 1) aprox += f1(xi) * pow(h, 1) / factorial(1);
        if (n >= 2) aprox += f2(xi) * pow(h, 2) / factorial(2);
        if (n >= 3) aprox += f3(xi) * pow(h, 3) / factorial(3);
        if (n >= 4) aprox += f4(xi) * pow(h, 4) / factorial(4);
        if (n >= 5) aprox += f5(xi) * pow(h, 5) / factorial(5);
        if (n >= 6) aprox += f6(xi) * pow(h, 6) / factorial(6);
        if (n >= 7) aprox += f7(xi) * pow(h, 7) / factorial(7);
        if (n >= 8) aprox += f8(xi) * pow(h, 8) / factorial(8);
        if (n >= 9) aprox += f9(xi) * pow(h, 9) / factorial(9);

        float Rn = 0;
        if (n == 0) Rn = f1(m) * pow(h, 1) / factorial(1);
        if (n == 1) Rn = f2(m) * pow(h, 2) / factorial(2);
        if (n == 2) Rn = f3(m) * pow(h, 3) / factorial(3);
        if (n == 3) Rn = f4(m) * pow(h, 4) / factorial(4);
        if (n == 4) Rn = f5(m) * pow(h, 5) / factorial(5);
        if (n == 5) Rn = f6(m) * pow(h, 6) / factorial(6);
        if (n == 6) Rn = f7(m) * pow(h, 7) / factorial(7);
        if (n == 7) Rn = f8(m) * pow(h, 8) / factorial(8);
        if (n == 8) Rn = f9(m) * pow(h, 9) / factorial(9);
        if (n == 9) Rn = f10(m) * pow(h, 10) / factorial(10);

        float error = f(xi1) - aprox;

        printf("%d   %f   %f   %f\n", n, aprox, Rn, error);
    }

    return 0;
}