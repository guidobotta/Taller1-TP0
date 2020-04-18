# <center> TP0 </center>

### <center> BOTTA, Guido Tomas </center>

### <center> Padron: 102103 </center>

### <center> Enlace a Github: https://github.com/guidobotta/tp0-taller </center>

## Paso 0

### Capturas de pantalla de la ejecución del aplicativo (con y sin Valgrind).

![Ejecución con y sin valgrind](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%200/consinvalgrind.png?raw=true)

### ¿Para qué sirve Valgrind? ¿Cuáles son sus opciones más comunes?

Valgrind se usa para detectar errores en la memoria. Perdida de memoria o accesos indeseados.

--leak-check=full y -v se pueden usar para ver más detalles.

# poner imagenes buscar info

### ¿Qué representa sizeof()? ¿Cuál sería el valor de salida de sizeof(char)y sizeof(int)?

sizeof() devuelve el tamaño en bytes que ocupa un tipo de dato. sizeof(char) devuelve 1, mientras que sizeof(int) podría devolver 4 u 8 dependiendo la arquitectura de la computadora.

### ¿El sizeof() de una struct de C es igual a la suma del sizeof() de cada uno sus elementos? Justifique mediante un ejemplo.

Se puede ver que no siempre se cumple que el sizeof() de una struct es igual a la suma del sizeof() de cada uno de sus elementos con un sencillo ejemplo.

Se tiene un struct formado por un int a, un char b y un int* c:

![Código completo](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%200/codigo.png?raw=true)

Como se puede ver, en este caso el int tiene tamaño de 4 bytes, el char de 1 byte y el int* de 8 bytes. La suma de estos sería de 13 bytes, pero se puede ver que el sizeof() del struct definido devuelve 16.

![Resultado código](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%200/tam16.png?raw=true)

Este comportamiento se podría modificar agregando al final del struct “\_\_attribute__((packed))”

![Struct modificado](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%200/modificado.png?raw=true)

Se puede ver que ahora el sizeof() del struct devuelve 13.

![Resultado modificado](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%200/tam13.png?raw=true)

### Investigar la existencia de los archivos estándar: STDIN, STDOUT, STDERR. Explicar brevemente su uso y cómo redirigirlos en caso de ser necesario (caracteres > y <) y como conectar la salida estándar de un proceso a la entrada estándar de otro con un pipe (carácter).

- La entrada estándar, STDIN (Standard Input), es la vía por donde se envían datos al programa.
- La salida estándar, STDOUT (Standard Output), determina el destino del resultado de un programa o proceso.
- El error estándar, STDERR (Standard Error), determina el destino de los errores producidos en un programa o proceso.

Estos archivos pueden ser redirigidos con los caracteres > y < al ejecutar un programa:

- Para redirigir el STDIN, se utiliza < (./main < entrada.txt).
- Para redirigir el STDOUT, se utiliza > o 1> (./main > salida.txt).
- Para redirigir el STDERR, se utiliza 2> (./main 2> errores.txt).

El caracter pipe | permite encadenar comandos. La salida de un comando resulta ser la entrada del siguiente. Por ejemplo, se podría hacer que la entrada de un programa sea la salida de la ejecución del mismo (./main | ./main).

## Paso 1

### Captura de pantalla mostrando los problemas de estilo detectados. Explicar cada uno.

![Problemas de estilo paso 1](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%201/errorformato.png?raw=true)

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

![Errores de compilación paso 1](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%201/errorcodigo.png?raw=true)

Son todos problemas provenientes de no incluir el archivo donde se encuentran las declaraciones de estos tipos/funciones (paso1_wordscounter.h). Es un problema de compilación, ya que se quieren utilizar sin nunca haber sido declaradas.

### ¿El sistema reportó algún WARNING? ¿Por qué?

Porque se ejecutó con el flag -Werror, que trata warnings como errors.

## Paso 2

### Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 1 a 2](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%202/diffarchivos.png?raw=true)

# completar

### Captura de pantalla indicando la correcta ejecución de verificación de normas de programación.

![Verificación normas de programación](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%202/exitonormas.png?raw=true)

### Captura de pantalla indicando los errores de generación del ejecutable. Explicar cada uno e indicar si se trata de errores del compilador o del linker.

![Errores de compilación paso 2](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%202/errorpaso2.png?raw=true)

- Los errores de las lineas 7, 15 y 20 en 'paso2_wordscounter.h' son producidos por no contar con el #include <> necesario. En este caso con la librería 'stdio.h' alcanza para ambos tipos (FILE y size_t).
- COMPLETAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
- El error de la linea 30 en 'paso2_wordscounter.c' es producido por no incluir la librería 'stdlib.h'.

Son errores en tiempo de compilación.

## Paso 3

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 2 a 3](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%203/diffpaso2a3.png?raw=true)

b. Captura de pantalla indicando los errores de generación del ejecutable. Explicar cada uno e indicar si se trata de errores del compilador o del linker.

![Errores de compilación paso 3](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%203/errorpaso3.png?raw=true)

## Paso 4

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 3 a 4](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%204/diffpaso3a4.png?raw=true)

b. Captura de pantalla del resultado de ejecución con Valgrind​ de la prueba ‘TDA’. Describir los errores reportados por Valgrind.

c. Captura de pantalla del resultado de ejecución con Valgrind​ de la prueba ‘Long Filename’. Describir los errores reportados por Valgrind.

d. ¿Podría solucionarse este error utilizando la función strncpy​ ? ¿Qué hubiera ocurrido con la ejecución de la prueba?

e. Explicar de qué se trata un ​ segmentation fault​ y un ​ buffer overflow​ .

## Paso 5

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 4 a 5](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%205/diffpaso4a5.png?raw=true)

b. Describa el motivo por el que fallan las prueba ‘Invalid File’ y ‘Single Word’. ¿Qué información entrega SERCOM para identificar el error? Realice una captura de pantalla.

c. Captura de pantalla de la ejecución del comando hexdump​ . ¿Cuál es el último carácter del archivo input_single_word.txt?

d. Captura de pantalla con el resultado de la ejecución con gdb​ . Explique brevemente los comandos utilizados en gdb​ . ¿Por qué motivo el debugger no se detuvo en el breakpoint de la línea 45: self->words++; ?

## Paso 6

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 5 a 6](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%206/diffpaso5a6.png?raw=true)

b. Captura de pantalla mostrando t odas las entregas realizadas​ , tanto exitosas como fallidas.

c. Captura de pantalla mostrando la ejecución de la prueba ‘Single Word’ de forma local​ con las distintas variantes indicadas.

## Paso 7 (Tomar como conclusión)

Revisar el estado de todas las pruebas ejecutadas en SERCOM con el código del paso 6.
Abrir cada una de las salidas de V
algrind​ y controlar que no hay errores reportados que no fueran
detectados como un fallo en la ejecución. Revisar con atención el listado de archivos abiertos al
finalizar el programa.
Controlar el código final entregado. Verificar el uso de buenas prácticas de programación y el
cumplimiento del enunciado del trabajo.
Proceder con la impresión del código fuente entregado por el SERCOM en la página de entregas y
adjuntar al informe.
Recordar utilizar la carátula brindada por la materia en el sitio de la cátedra.