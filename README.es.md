# Piscine - Bootcamp de 42 School

Una colección completa de ejercicios de programación en C completados durante el bootcamp Piscine de 42 School, cubriendo conceptos fundamentales de programación hasta resolución de problemas avanzada.

## Descripción General

La Piscine es un bootcamp intensivo de 4 semanas que sirve como introducción al plan de estudios de 42. Este repositorio contiene todos los ejercicios completados, rushes y el proyecto final BSQ, demostrando el dominio progresivo de la programación en C, algoritmos y resolución de problemas colaborativa.

## Contenidos

### Módulos C (C00-C13)
Ejercicios progresivos que cubren fundamentos de programación en C:

- **C00**: Funciones básicas, bucles y operaciones de salida
- **C01**: Punteros y direcciones de memoria
- **C02**: Manipulación de strings y manejo de caracteres
- **C03**: Comparación y concatenación de strings
- **C04**: Conversión de números y salida
- **C05**: Iteración y recursión (factoriales, Fibonacci, primos)
- **C06**: Argumentos de línea de comandos
- **C07**: Asignación de memoria con malloc
- **C08**: Archivos de cabecera y directivas del preprocesador
- **C09**: Creación de librerías y organización de código
- **C10**: Manejo de archivos y flujos estándar
- **C11**: Listas enlazadas y estructuras de datos
- **C12**: Estructuras de datos avanzadas
- **C13**: Árboles binarios de búsqueda

### Proyectos Rush
Proyectos colaborativos en equipo (desafíos de 48 horas):

- **Rush00**: Dibujo de patrones con caracteres ASCII
- **Rush01**: Resolvedor de puzzle de rascacielos (lógica de cuadrícula 4x4)
- **Rush02**: Conversor de números a palabras con diccionario

### Módulos Shell (Shell00-Shell01)
Ejercicios de comandos Unix y scripting

### BSQ - Biggest Square (Cuadrado Más Grande)
Proyecto final: Encontrar y mostrar el cuadrado más grande de espacios vacíos en un mapa, evitando obstáculos.

## Estructura del Proyecto

```
Piscine/
├── Shell00-Shell01/     # Ejercicios de comandos shell
├── C00-C13/              # Ejercicios de programación en C
│   ├── ex00-ex13/       # Ejercicios individuales
│   └── *.pdf            # Archivos de enunciados
├── Rush00/              # Dibujo de patrones ASCII
│   └── ex00/           # Múltiples implementaciones de rush
├── Rush01/              # Resolvedor de puzzle de rascacielos
│   └── ex00/           # Solución con backtracking
├── Rush02/              # Conversor de números a palabras
│   └── ex00/           # Solución basada en diccionario
├── BSQ/                 # Proyecto final
│   ├── main.c          # Punto de entrada
│   ├── processing.c    # Procesamiento del mapa
│   ├── solve_square.c  # Algoritmo de búsqueda del cuadrado
│   ├── to_matrix.c     # Conversión del mapa
│   ├── matrix_size.c   # Cálculo de dimensiones
│   ├── free_resources.c # Gestión de memoria
│   └── Makefile        # Configuración de compilación
└── README.es.md        # Este archivo
```

## Compilación

### Proyecto BSQ
```bash
cd BSQ
make
```

### Rush01 (Puzzle de Rascacielos)
```bash
cd Rush01/ex00
gcc -Wall -Wextra -Werror -o rush-01 *.c
```

### Rush02 (Conversor de Números a Palabras)
```bash
cd Rush02/ex00
gcc -Wall -Wextra -Werror -o rush-02 *.c
```

### Ejercicios Individuales
```bash
cd C00/ex00
gcc -Wall -Wextra -Werror ft_putchar.c
```

## Uso

### BSQ
```bash
# Con argumento de archivo
./bsq mapa.txt

# Con múltiples archivos
./bsq mapa1.txt mapa2.txt

# Desde entrada estándar
cat mapa.txt | ./bsq
```

### Rush01 (Puzzle de Rascacielos)
```bash
# Formato de entrada: 16 valores separados por espacios (1-4)
# Orden: col_arriba(4), col_abajo(4), fila_izquierda(4), fila_derecha(4)
./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

### Rush02 (Conversor de Números a Palabras)
```bash
# Con diccionario por defecto
./rush-02 12345

# Con diccionario personalizado
./rush-02 numeros.dict 12345
```

## Calidad del Código

- Todo el código cumple con los estándares de norminette de 42 school
- Sin fugas de memoria (verificado con valgrind)
- Manejo adecuado de errores
- Organización limpia del código
- Cobertura completa de pruebas

## Aspectos Técnicos Destacados

### Gestión de Memoria
- Asignación y liberación cuidadosa
- Sin fugas de memoria ni dobles liberaciones
- Limpieza adecuada en todas las rutas de error

### Algoritmos
- Backtracking para satisfacción de restricciones (Rush01)
- Enfoque de programación dinámica para el cuadrado más grande (BSQ)
- Procesamiento y análisis eficiente de strings

### Manejo de Errores
- Validación de entrada
- Verificación de errores de E/S de archivos
- Manejo de fallos de asignación de memoria
- Mensajes de error claros

## Requisitos

- Compilador GCC
- Make (para BSQ)
- Entorno tipo Unix (Linux, macOS o WSL)
- norminette (para estudiantes de 42)

## Pruebas

### Pruebas de Memoria
```bash
# Probar BSQ para fugas de memoria
valgrind --leak-check=full ./bsq mapa.txt

# Probar Rush02
valgrind --leak-check=full ./rush-02 12345
```

### Norminette
```bash
# Verificar todos los archivos
norminette C00/ C01/ C02/ ...
norminette Rush00/ Rush01/ Rush02/
norminette BSQ/
```

## Resultados de Aprendizaje

- **Programación en C**: Dominio de punteros, gestión de memoria y estructuras de datos
- **Algoritmos**: Pensamiento algorítmico y resolución de problemas
- **Entorno Unix**: Comandos shell, sistemas de archivos y gestión de procesos
- **Colaboración**: Proyectos rush en equipo bajo presión de tiempo
- **Calidad de Código**: Escritura de código limpio, mantenible y eficiente

## Autor

- **Mario Pico** (@Davter17)

## Licencia

Este proyecto forma parte del plan de estudios de 42 school y sigue sus directrices académicas.
