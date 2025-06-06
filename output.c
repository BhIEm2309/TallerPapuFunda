#include <stdio.h>
int main() {
char* nombre;
int edad;
float altura;
nombre = "Lucas";
edad = 20;
altura = 1.750000;
printf("%s\n", nombre);
printf("%s\n", edad);
printf("%s\n", altura);
if ((edad >= 18)) {
printf("%s\n", "Mayor de edad");
}
else {
printf("%s\n", "Menor de edad");
}
while ((edad > 0)) {
printf("%s\n", edad);
edad = (edad - 1);
}
return 0;
}
