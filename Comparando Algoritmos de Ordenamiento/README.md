# Comparador de Algoritmos de Ordenamiento

**Curso:** Programación Competitiva  
**Semestre:** VI — Ingeniería de Sistemas  
**Universidad:** Universidad Nacional del Altiplano — Puno

---

## ¿De qué trata este programa?

Este programa compara el rendimiento de 8 algoritmos de ordenamiento sobre un mismo arreglo de números generados aleatoriamente. Al ejecutarlo, el programa pide los datos por pantalla: cuántos números generar y el rango mínimo y máximo. Luego ejecuta todos los algoritmos, mide el tiempo en nanosegundos y muestra los resultados ordenados de más rápido a más lento.

Se implementó usando únicamente `iostream`, `chrono` y `cstdlib` de la librería estándar de C++. Sin librerías externas.

---

## Algoritmos que se comparan

| N° | Algoritmo | Complejidad |
|----|-----------|-------------|
| 1 | Bubble Sort | O(n²) |
| 2 | Selection Sort | O(n²) |
| 3 | Insertion Sort | O(n²) — O(n) mejor caso |
| 4 | Shell Sort | O(n log² n) aprox. |
| 5 | Merge Sort | O(n log n) |
| 6 | Quick Sort | O(n log n) promedio |
| 7 | Heap Sort | O(n log n) |
| 8 | Counting Sort | O(n + k) |

---

## Cómo compilar y ejecutar

### Requisitos

- Tener instalado `g++` con soporte C++11 o superior.
- En Linux/macOS ya viene instalado. En Windows se puede usar MinGW o WSL.

### Paso 1 — Clonar el repositorio

```bash
git clone https://github.com/tu-usuario/sorting-comparator.git
cd Comparando Algoritmos de Ordenamiento
```

### Paso 2 — Compilar

```bash
g++ -O0 -std=c++11 -o comparador main.cpp
```

> Se usa `-O0` para desactivar las optimizaciones del compilador y que los tiempos reflejen el comportamiento real de cada algoritmo.

### Paso 3 — Ejecutar

```bash
./comparador
```

El programa va a pedir los datos uno por uno:

```
Ingrese la cantidad de numeros a generar :
Ingrese el valor minimo del rango        :
Ingrese el valor maximo del rango        :
```

---

## Ejemplos de ejecución

---

### Ejemplo 1

#### Datos de entrada

Ejecutar el programa:
```bash
./comparador
```

Cuando el programa pida los datos, ingresar esto (uno por uno y presionar Enter):

```
15
1
50
```

#### Datos de salida

```
========================================================================
    COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
    Curso  : Programacion Competitiva
    UNA Puno - Ing. de Sistemas - VI Semestre
========================================================================
  Ingrese la cantidad de numeros a generar : 15
  Ingrese el valor minimo del rango        : 1
  Ingrese el valor maximo del rango        : 50
------------------------------------------------------------------------
  Cantidad de elementos : 15
  Rango                 : [1, 50]
------------------------------------------------------------------------
  Arreglo generado aleatoriamente (15 elementos):
  [ 17, 41, 32, 42, 13, 9, 22, 41, 36, 44, 25, 44, 18, 5, 47 ]
------------------------------------------------------------------------
  RESULTADOS (ordenados de menor a mayor tiempo)
------------------------------------------------------------------------
  Pos        Algoritmo               Pasos     Tiempo de ejecucion
------------------------------------------------------------------------
    1   Insertion Sort                  59               446 ns
    2       Shell Sort                  54               607 ns
    3    Counting Sort                  94               743 ns
    4   Selection Sort                 105               804 ns
    5      Bubble Sort                 105               915 ns
    6       Quick Sort                  68               978 ns
    7        Heap Sort                 110              1361 ns
    8       Merge Sort                  59              4673 ns
========================================================================
  >> El mas rapido fue : Insertion Sort con 446 ns
  >> El mas lento fue  : Merge Sort con 4673 ns
========================================================================
```

---

###  Ejemplo 2

#### Datos de entrada

Ejecutar el programa:
```bash
./comparador
```

Cuando el programa pida los datos, ingresar esto (uno por uno y presionar Enter):

```
20
100
500
```

#### Datos de salida

```
========================================================================
    COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
    Curso  : Programacion Competitiva
    UNA Puno - Ing. de Sistemas - VI Semestre
========================================================================
  Ingrese la cantidad de numeros a generar : 15
  Ingrese el valor minimo del rango        : 1
  Ingrese el valor maximo del rango        : 50
------------------------------------------------------------------------
  Cantidad de elementos : 15
  Rango                 : [1, 50]
------------------------------------------------------------------------
  Arreglo generado aleatoriamente (15 elementos):
  [ 26, 1, 20, 7, 34, 30, 17, 45, 10, 20, 10, 1, 22, 50, 37 ]
------------------------------------------------------------------------
  RESULTADOS (ordenados de menor a mayor tiempo)
------------------------------------------------------------------------
  Pos        Algoritmo               Pasos     Tiempo de ejecucion
------------------------------------------------------------------------
    1   Insertion Sort                  56               700 ns
    2       Shell Sort                  54              1100 ns
    3       Quick Sort                  46              1300 ns
    4   Selection Sort                 105              1500 ns
    5      Bubble Sort                 105              1700 ns
    6        Heap Sort                 104              2200 ns
    7    Counting Sort                  94              2400 ns
    8       Merge Sort                  59             18300 ns
========================================================================
  >> El mas rapido fue : Insertion Sort con 700 ns
  >> El mas lento fue  : Merge Sort con 18300 ns
========================================================================
```

---

## Notas

- La **semilla aleatoria está fija** (`srand(42)`) para que los mismos datos de entrada siempre generen el mismo arreglo y los resultados sean reproducibles.
- Los **tiempos en nanosegundos** pueden variar un poco entre ejecuciones según la carga del procesador. Es normal.
- La columna **Pasos** cuenta las comparaciones u operaciones elementales de cada algoritmo.
- **Counting Sort** es más eficiente cuando el rango `k` es pequeño. Con rangos grandes como [100, 500], su arreglo de conteo crece y puede volverse menos conveniente.

---

## Estructura del repositorio

```
Comparando Algoritmos de Ordenamiento/
├── main.cpp   # Codigo fuente del programa
└── README.md                # Este archivo
```

---

## Autor
Estudiante - ANTHONY CT
Trabajo práctico — **Programación Competitiva**  
VI Semestre — Escuela Profesional de Ingeniería de Sistemas  
Universidad Nacional del Altiplano — Puno, Perú
