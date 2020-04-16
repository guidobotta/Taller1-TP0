# TP0

# **DAR FORMATO!!**
BOTTA, Guido Tomas
Padron: 102103
https://github.com/guidobotta/tp0-taller

## Paso 0

### Capturas de pantalla de la ejecución del aplicativo (con y sin Valgrind).

![](https://github.com/guidobotta/tp0-taller/blob/master/Paso%200/consinvalgrind.png?raw=true)

### ¿Para qué sirve Valgrind? ¿Cuáles son sus opciones más comunes?

Valgrind se usa para detectar errores en la memoria. Perdida de memoria o accesos indeseados.

--leak-check=full y -v se pueden usar para ver más detalles.

# poner imagenes buscar info

### ¿Qué representa sizeof()? ¿Cuál sería el valor de salida de sizeof(char)y sizeof(int)?

sizeof() devuelve el tamaño en bytes que ocupa un tipo de dato. sizeof(char) devuelve 1, mientras que sizeof(int) podría devolver 4 u 8 dependiendo la arquitectura de la computadora.

### ¿El sizeof() de una struct de C es igual a la suma del sizeof() de cada uno sus elementos? Justifique mediante un ejemplo.

Se puede ver que no siempre se cumple que el sizeof() de una struct es igual a la suma del sizeof() de cada uno de sus elementos con un sencillo ejemplo.

Se tiene un struct formado por un int a, un char b y un int* c:

![](https://github.com/guidobotta/tp0-taller/blob/master/Paso%200/codigo.png?raw=true)

Como se puede ver, en este caso el int tiene tamaño de 4 bytes, el char de 1 byte y el int* de 8 bytes. La suma de estos sería de 13 bytes, pero se puede ver que el sizeof() del struct definido devuelve 16.

![](https://github.com/guidobotta/tp0-taller/blob/master/Paso%200/tam16.png?raw=true)

Este comportamiento se podría modificar agregando al final del struct “\_\_attribute__((packed))”

![](https://github.com/guidobotta/tp0-taller/blob/master/Paso%200/modificado.png?raw=true)

Se puede ver que ahora el sizeof() del struct devuelve 13.

![](https://github.com/guidobotta/tp0-taller/blob/master/Paso%200/tam13.png?raw=true)

### Investigar la existencia de los archivos estándar: STDIN, STDOUT, STDERR. Explicar brevemente su uso y cómo redirigirlos en caso de ser necesario (caracteres > y <) y como conectar la salida estándar de un proceso a la entrada estándar de otro con un pipe (carácter).

# completar

## Paso 1

### Captura de pantalla mostrando los problemas de estilo detectados. Explicar cada uno.

# imagen

- Linea 27 de ‘paso1_wordscounter.c’, falta un espacio entre el ‘while’ y el ‘(’.
- Linea 41 de ‘paso1_wordscounter.c’, sobra dos espacios entre el ‘(’ y ‘c’.
- Linea 47 de ‘paso1_wordscounter.c’, else debería estar en línea 46 después del ‘}’
- Linea 48 de ‘paso1_wordscounter.c’, falta un espacio entre el ‘if’ y el ‘(’.
- Linea 53 de ‘paso1_wordscounter.c’, sobra espacio entre ‘next_state’ y el ‘;’.
- No aparece, pero en la linea 14 de ‘paso1_wordscounter.c’ hay una llave que debería ir en línea 13.
- Linea 12 de ‘paso1_main.c’, se recomienda usar ‘snprintf’ en lugar de ‘strcpy’.
- Linea 15 de ‘paso1_main.c’, else debería estar en línea 14 después del ‘}’.
- Linea 5 de ‘paso1_wordscounter.h’, comentario muy largo, pasa los 80 caracteres de longitud recomendados.

### Captura de pantalla indicando los errores de generación del ejecutable. Explicar cada uno e indicar si se trata de errores del compilador o del linker.

# imagen

Son todos problemas provenientes de no incluir el archivo donde se encuentran las declaraciones de estos tipos/funciones (paso1_wordscounter.h). Es un problema de compilación, ya que se quieren utilizar sin nunca haber sido declaradas.

### ¿El sistema reportó algún WARNING? ¿Por qué?

Porque se ejecutó con el flag -Werror, que trata warnings como errors.

## Paso 2

### Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

# imagen

# completar

### Captura de pantalla indicando la correcta ejecución de verificación de normas de programación.

# imagen

### Captura de pantalla indicando los errores de generación del ejecutable. Explicar cada uno e indicar si se trata de errores del compilador o del linker.

# imagen

# completar

## Paso 3

## Paso 4

## Paso 5

## Paso 6

## Paso 7