#include <stdio.h>
#include <string.h>
int potencia(int base, int exponente) {
int resultado;
int i;
resultado = 1;
i = 0;
while ((i < exponente)) {
resultado = (resultado * base);
i = (i + 1);
}
printf("%d\n", resultado);
}

int dividir(int a, int b) {
int resultado;
resultado = (a / b);
printf("%d\n", resultado);
}

int multiplicar(int a, int b) {
int resultado;
resultado = (a * b);
printf("%d\n", resultado);
}

int restar(int a, int b) {
int resultado;
resultado = (a - b);
printf("%d\n", resultado);
}

int sumar(int a, int b) {
int resultado;
resultado = (a + b);
printf("%d\n", resultado);
}

int main() {
int x;
int y;
x = 10;
y = 2;
sumar(x, y);
restar(x, y);
multiplicar(x, y);
dividir(x, y);
potencia(x, y);
return 0;
}
