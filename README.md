# Taller Fundamentos de la Computación - Compilador Lenguaje D++

# Documentación del Lenguaje
La gramática utilizada por nuestro lenguaje D++, con una sintaxis inspirada en C/C++ y Python posee las siguientes características:

### Tipos de datos
- `integer` → números enteros
- `floating` → números decimales
- `chain` → cadenas de texto (strings)

### Operadores
- **Aritméticos**: `+`, `-`, `*`, `/`, `%`
- **Comparación**: `==`, `!=`, `<`, `<=`, `>`, `>=`

### Condicionales
- `if (cond) { ... } else { ... }`

### Ciclos
- `while (cond) { ... }`
- `for (init; cond; update) { ... }` *(traducido internamente a `while`)*

  
### Funciones de Entrada/Salida
- `write x;` → leer desde teclado (scanf)
- `print x;` → imprimir variable o literal (printf)

### Funciones
- **Definición**:
  ```plaintext
  function nombre() {
      // cuerpo
  }

# Estructura interna del compilador.

Para el funcionamiento del compilador se hace uso de los siguientes archivos:

- `scanner.l` → Definición de tokens y análisis léxico. (Flex)
- `parser.y` → Gramática del lenguaje y análisis sintáctico. (Bison)
- `ast_c.h / ast_c.c` → Definición e implementación del árbol AST.
- `generarCodigo.c` → Recorrido del AST y generación de código C

# Ejemplos de sintaxis
| **Funciones de entrada/salida** |
```plaintext
print x;
write y;
```
| **Declarar variables** |
```plaintext
integer edad;
floating pi;
chain nombre;
```
| **Asignación** |
```plaintext
edad = 20;
pi = 3.14;
nombre = 'blem';
```
| **Operaciones aritméticas** |
```plaintext
suma = 5 + 3;
resta = 10 - 5;
multiplicación = 5 * 2;
división = 10 / 2;
resto = 10 % 3;
```
| **Condicionales** |
```plaintext
if (x == 0) {
    print "cero";
} else {
    print "no cero";
}
```
| **Comparaciones** |
```plaintext
a == b;   a != b;
a > 10;   a < 10;
a >= 10;  a <= 10;
```
| **Ciclos** |
```plaintext
while (x < 5) {
    x = x + 1;
}

for (i = 0; i < 5; i = i + 1) {
    print i;
}
```
| **Funciones** |
```plaintext
function saludar() {
    print "Hola mundo";
}
```
# Como compilar (Bash):
1. flex scanner.l
2. bison -d parser.y
3. gcc parser.tab.c lex.yy.c ast_c.c generarCodigo.c -o dpp_compiler -lm
4. ./dpp_compiler < test.dpp
5. gcc output.c -o programa
6. ./programa

# Autores
Taller desarrollado por:
- Benjamín Miranda Araya.
- Vicente Ruiz Escobar.
