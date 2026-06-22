# Sudoku Solver

Proyecto en C++ para resolver Sudoku de 9x9 usando búsqueda recursiva con backtracking.

## Descripción

Este programa lee las posiciones iniciales de un Sudoku desde el archivo `in.txt`, intenta resolverlo y muestra en consola el Sudoku inicial y, si es posible, el Sudoku resuelto.

## Archivos principales

- `main.cpp`: implementación del solucionador.
- `in.txt`: datos de entrada con las posiciones conocidas del Sudoku.

## Cómo funciona

1. Lee cada línea de `in.txt` con tres valores: fila, columna y valor.
2. Coloca esos valores en el tablero inicial.
3. Usa backtracking para llenar las casillas vacías (representadas con `0`).
4. Verifica que cada número colocado respete las reglas del Sudoku:
   - No se repite en la misma fila.
   - No se repite en la misma columna.
   - No se repite en el mismo subcuadro 3x3.
5. Imprime el tablero inicial y el tablero resuelto si existe una solución.

## Formato de entrada

Cada línea de `in.txt` debe contener tres números separados por espacios:

```
fila columna valor
```

- `fila`: entero entre 1 y 9.
- `columna`: entero entre 1 y 9.
- `valor`: entero entre 0 y 9. El valor `0` representa una casilla vacía.

Ejemplo de `in.txt`:

```
1 1 5
1 2 3
1 5 7
2 1 6
2 4 1
2 5 9
2 6 5
3 2 9
3 3 8
3 8 6
```

## Compilación y ejecución

Desde la carpeta del proyecto, compila con un compilador de C++ como `g++`:

```bash
g++ main.cpp -o sudoku
```

Ejecuta el programa con:

```bash
./sudoku
```

En Windows con MinGW:

```bash
g++ main.cpp -o sudoku.exe
sudoku.exe
```

## Salida esperada

El programa imprime primero el Sudoku inicial y después el Sudoku resuelto si se encontró la solución.

Ejemplo de salida:

```
Sudoku inicial:
5 3 0 | 0 7 0 | 0 0 0
6 0 0 | 1 9 5 | 0 0 0
0 9 8 | 0 0 0 | 0 6 0
------+-------+------
8 0 0 | 0 6 0 | 0 0 3
4 0 0 | 8 0 3 | 0 0 1
7 0 0 | 0 2 0 | 0 0 6
------+-------+------
0 6 0 | 0 0 0 | 2 8 0
0 0 0 | 4 1 9 | 0 0 5
0 0 0 | 0 8 0 | 0 7 9

Sudoku resuelto:
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9
```

## Notas

- El tablero se representa internamente como una matriz de tamaño `9x9`.
- El programa no maneja entradas incorrectas más allá de las comprobaciones básicas de rango.
- Si el Sudoku no tiene solución con los datos proporcionados, se muestra un mensaje indicando que no se pudo resolver.
