#include <stdio.h>
#include <string.h>
int dividir(int a, int b) {
int resultado;
resultado = (a / b);
printf("%s\n", "La división es:");
printf("%d\n", resultado);
}

int multiplicar(int a, int b) {
int resultado;
resultado = (a * b);
printf("%s\n", "La multiplicación es:");
printf("%d\n", resultado);
}

int restar(int a, int b) {
int resultado;
resultado = (a - b);
printf("%s\n", "La resta es:");
printf("%d\n", resultado);
}

int sumar(int a, int b) {
int resultado;
resultado = (a + b);
printf("%s\n", "La suma es:");
printf("%d\n", resultado);
}

int main() {
int x;
int y;
printf("%s\n", "Ingrese el primer número:");
scanf("%d", &x);
printf("%s\n", "Ingrese el segundo número:");
scanf("%d", &y);
sumar(x, y);
restar(x, y);
multiplicar(x, y);
dividir(x, y);
return 0;
}
