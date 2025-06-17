#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
int nombre;
{
  char __input_buf[100];
  fgets(__input_buf, sizeof(__input_buf), stdin);
  if (sscanf(__input_buf, "%d", &nombre) != 1) {
    fprintf(stderr, "Error: se esperaba un número entero para 'nombre'.\n");
    exit(1);
  }
}
return 0;
}
