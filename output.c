#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int potencia(int base, int exponente) {
int r;
int i;
r = 1;
i = 0;
while ((i < exponente)) {
r = (r * base);
i = (i + 1);
}
printf("%s\n", "Potencia:");
printf("%d\n", r);
}

int dividir(int a, int b) {
int r;
r = ({ int __right; __right = b; if (__right == 0) { fprintf(stderr, "Error: división por cero.\n"); exit(1); } a / __right; });
printf("%s\n", "Division:");
printf("%d\n", r);
}

int multiplicar(int a, int b) {
int r;
r = (a * b);
printf("%s\n", "Multiplicacion:");
printf("%d\n", r);
}

int restar(int a, int b) {
int r;
r = (a - b);
printf("%s\n", "Resta:");
printf("%d\n", r);
}

int sumar(int a, int b) {
int r;
r = (a + b);
printf("%s\n", "Suma:");
printf("%d\n", r);
}

int main() {
int x;
int y;
printf("%s\n", "Ingrese primer numero:");
{
  char __input_buf[100];
  fgets(__input_buf, sizeof(__input_buf), stdin);
  if (sscanf(__input_buf, "%d", &x) != 1) {
    fprintf(stderr, "Error: se esperaba un número entero para 'x'.\n");
    exit(1);
  }
}
printf("%s\n", "Ingrese segundo numero:");
{
  char __input_buf[100];
  fgets(__input_buf, sizeof(__input_buf), stdin);
  if (sscanf(__input_buf, "%d", &y) != 1) {
    fprintf(stderr, "Error: se esperaba un número entero para 'y'.\n");
    exit(1);
  }
}
printf("%s\n", "=============================================");
sumar(x, y);
restar(x, y);
multiplicar(x, y);
dividir(x, y);
potencia(x, y);
printf("%s\n", "=============================================");
return 0;
}
