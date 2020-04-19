# <center> TP0 </center>

### <center> BOTTA, Guido Tomas </center>

### <center> Padron: 102103 </center>

### <center> Enlace a Github: https://github.com/guidobotta/tp0-taller </center>

## Paso 0

### Capturas de pantalla de la ejecución del aplicativo (con y sin Valgrind).

![Ejecución con y sin valgrind](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%200/consinvalgrind.png?raw=true)

### ¿Para qué sirve Valgrind? ¿Cuáles son sus opciones más comunes?

Valgrind se usa para detectar errores en la memoria. Perdida de memoria o accesos indeseados.

- --tool=mencheck (que viene por defecto)
- --leak-check=full busca las pérdidas de memoria y entrega información detallada de cada fuga. Las opciones, además de full, pueden ser 'no', 'summary' o 'yes'.
- --leak-resolution=(low|med|high) muestra información detallada según la opción elegida.
- --undef-value-errores=(yes|no) indica si se verifican o no las variables no inicializadas.

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

El caracter pipe | permite encadenar comandos. La salida de un comando resulta ser la entrada del siguiente. Por ejemplo, se podría hacer que la salida de un programa "calculo" sea la entrada de un programa "main" (./calculo | ./main).

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

- Se solucionaron los errores en las normas de programación mencionados en el paso 1.
- En 'paso2_main.c' se agrego el #include "paso2_wordscounter.h", lo que soluciona el problema de la falta de declaración de las funciones contenidas en dicho archivo.
- Se reemplazo el uso de strcpy por el de memcpy, que permite una restricción a la cantidad de datos a copiar. Aún tiene el error de tomar una longitud variable que puede provocar comportamientos indeseados.

### Captura de pantalla indicando la correcta ejecución de verificación de normas de programación.

![Verificación normas de programación](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%202/exitonormas.png?raw=true)

### Captura de pantalla indicando los errores de generación del ejecutable. Explicar cada uno e indicar si se trata de errores del compilador o del linker.

![Errores de compilación paso 2](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%202/errorpaso2.png?raw=true)

- Los errores de las lineas 7, 15 y 20 en 'paso2_wordscounter.h' son producidos por no contar con el #include <> necesario. En este caso con la librería 'stdio.h' alcanza para ambos tipos (FILE y size_t).
- El error de la linea 30 en 'paso2_wordscounter.c' es producido por no incluir la librería 'stdlib.h'.

Son errores en tiempo de compilación.

## Paso 3

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 2 a 3](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%203/diffpaso2a3.png?raw=true)

- Se agregaron las librerías 'string.h' y 'stdio.h' a 'paso3_wordscounter.h'
- Se agreg+o la librería 'stdlib.h' a 'paso3_wordscounter.c'

b. Captura de pantalla indicando los errores de generación del ejecutable. Explicar cada uno e indicar si se trata de errores del compilador o del linker.

![Errores de compilación paso 3](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%203/errorpaso3.png?raw=true)

El error sucede porque la función 'wordscounter_destroy' está declarada pero no definida. Es un error de linkeo, ya pasó la etapa de compilación, pudo generar los '.o' pero al querer buscar la función mencionada, se encontró con que no está definida.

## Paso 4

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 3 a 4](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%204/diffpaso3a4.png?raw=true)

Se definió la funcion 'wordscounter_destroy', aunque no hace nada.

b. Captura de pantalla del resultado de ejecución con Valgrind​ de la prueba ‘TDA’. Describir los errores reportados por Valgrind.

![Valgrind paso 4 TDA](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%204/valgrindpaso4tda.png?raw=true)

Esta ejecución con valgrind muestra pérdida de memoria en el archivo 'paso4_main.c' en las líneas 14, del FILE* input que no se cierra, y 24, que ejecuta la función 'wordscounter_process', que a su vez ejecuta la función 'wordscounter_next_state', que hace un malloc el cual nunca es liberado.

c. Captura de pantalla del resultado de ejecución con Valgrind​ de la prueba ‘Long Filename’. Describir los errores reportados por Valgrind.

![Valgrind paso 4 Long Filename](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%204/valgrindpaso4longfile.png?raw=true)

Esta ejecución muestra que se genera un buffer overflow en el buffer char filepath[30], ya que en la función memcpy se está pasando una longitud máxima que depende del string pasado por parámetro, por lo tanto es variable y puede ser mayor al máximo soportado por el buffer.

d. ¿Podría solucionarse este error utilizando la función strncpy​? ¿Qué hubiera ocurrido con la ejecución de la prueba?

No, ya que el problema no es la terminación de la cadena del string (la principal diferencia entre memcpy y strncpy). El problema es la limitación de caracteres, ambas funciones pueden pasarse de caracteres y generar un buffer overflow.

e. Explicar de qué se trata un segmentation fault​ y un buffer overflow​.

# completar

## Paso 5

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 4 a 5](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%205/diffpaso4a5.png?raw=true)

- Se eliminó el uso de un buffer y de la función memcpy, y directamente se utilizó el argumento pasado al ejecutar para el nombre del archivo.
- Se agregó una condición al final de la ejecución del programa que cierra el archivo abierto en caso de que se haya pasado alguno por parámetro.
- Se cambió el uso de una lista de caracteres guardados en memoria dinámica para saber los delimitadores por una lista de caracteres en memoria estática.

b. Describa el motivo por el que fallan las prueba ‘Invalid File’ y ‘Single Word’. ¿Qué información entrega SERCOM para identificar el error? Realice una captura de pantalla.

![Invalid File paso 5](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%205/invalidfilepaso5.png?raw=true)

La prueba 'Invalid File' falla ya que el programa retorna '255' en vez de '1'. Esto ocurre porque esta prueba espera que se devuelva el código de ERROR, que en el archivo main se definió como -1 en vez de 1.

![Single Word paso 5](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%205/singlewordpaso5.png?raw=true)

# completar

c. Captura de pantalla de la ejecución del comando hexdump​. ¿Cuál es el último carácter del archivo input_single_word.txt?

![Hexdump paso 5](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%205/hexdumppaso5.png?raw=true)

El último caracter del archivo 'input_single_word.txt' es un EOT (0x0000004).

d. Captura de pantalla con el resultado de la ejecución con gdb​ . Explique brevemente los comandos utilizados en gdb​. ¿Por qué motivo el debugger no se detuvo en el breakpoint de la línea 45: self->words++?

![GDB paso 5](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%205/gdbpaso5.png?raw=true)

El debbuger no se detiene en el break de la linea 45 porque nunca llega al if de la linea 44 cumpliendo dicha condición, ya que el último caracter del txt es un EOF (-1).

## Paso 6

a. Describa en breves palabras las correcciones realizadas respecto de la versión anterior.

![Correcciones paso 5 a 6](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%206/diffpaso5a6.png?raw=true)

- Se cambió la definición de ERROR de -1 a 1.
- Se definieron a través de un #define los delimitadores de palabras.
- Se cambio el orden de los condicionales en la función wordscounter_next_state para que no ocurra el error de no contar la palabra si se encuentra con un EOF al final de esta.

b. Captura de pantalla mostrando todas las entregas realizadas​ , tanto exitosas como fallidas.

![Entregas Sercom](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%206/sercompaso6.png?raw=true)

c. Captura de pantalla mostrando la ejecución de la prueba ‘Single Word’ de forma local​ con las distintas variantes indicadas.

![Ejecuciones paso 6](https://github.com/guidobotta/tp0-taller/blob/master/img/Paso%206/ejecucionpaso6.png?raw=true)

En la ejecución con la forma './tp < input_single_word.txt > output_single_word.txt' se redirige la salida, creando un .txt cuyo contenido es '1', al igual que en las anteriores ejecuciones.

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