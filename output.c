#include <stdio.h>
int main() {
char nombre[100];
int edad;
scanf("%d", &nombre);
scanf("%d", &edad);
printf("%s\n", nombre);
printf("%s\n", edad);
if ((edad >= 18)) {
printf("%s\n", "Mayor de edad");
}
else {
printf("%s\n", "Menor de edad");
}
return 0;
}
