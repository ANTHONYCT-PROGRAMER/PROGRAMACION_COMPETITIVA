/*
 * ============================================================
 *  COMPARADOR DE ALGORITMOS DE ORDENAMIENTO
 *  Curso   : PROGRAMACION COMPETITIVA
 *  Alumno  : ANTHONY CONDORI TICONA
 *  Semestre: VI - Ingenieria de Sistemas
 *  UNA - PUNO
 * ============================================================
 *
 *  Descripcion:
 *    El programa pide al usuario la cantidad de numeros a generar
 *    y el rango [min, max]. Luego ejecuta 8 algoritmos de
 *    ordenamiento sobre el mismo arreglo y muestra los resultados
 *    ordenados de menor a mayor segun el tiempo en nanosegundos.
 *
 *  Como compilar:
 *    g++ -O0 -std=c++11 -o comparador sorting_comparator.cpp
 *
 *  Como ejecutar:
 *    ./comparador
 *    (el programa pedira los datos por pantalla)
 * ============================================================
 */

#include <iostream>   // cout, cin, endl
#include <chrono>     // para medir tiempo en nanosegundos
#include <cstdlib>    // rand(), srand(), atoi()

using namespace std;
using namespace chrono;

// ============================================================
//  Estructura para guardar el resultado de cada algoritmo
// ============================================================
struct Resultado {
    const char* nombre;
    long long   pasos;
    long long   tiempoNs;
};

// ============================================================
//  Funciones auxiliares
// ============================================================

// Copiar un arreglo (para no modificar el original)
void copiarArreglo(int* origen, int* destino, int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origen[i];
}

// Imprimir un arreglo en pantalla
void imprimirArreglo(int* arr, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

// Imprimir una linea separadora
void linea(char c = '-', int largo = 72) {
    for (int i = 0; i < largo; i++) cout << c;
    cout << endl;
}

// ============================================================
//  ALGORITMOS DE ORDENAMIENTO
//  Cada funcion retorna la cantidad de pasos realizados
// ============================================================

// ------------------------------------------------------------
// 1. BUBBLE SORT
//    Compara elementos adyacentes y los intercambia si estan
//    en el orden incorrecto. Repite hasta que no hay cambios.
//    Complejidad: O(n^2)
// ------------------------------------------------------------
long long bubbleSort(int* arr, int n) {
    long long pasos = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            pasos++;
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return pasos;
}

// ------------------------------------------------------------
// 2. SELECTION SORT
//    Busca el minimo en el subarreglo no ordenado y lo coloca
//    al inicio. Repite para cada posicion.
//    Complejidad: O(n^2)
// ------------------------------------------------------------
long long selectionSort(int* arr, int n) {
    long long pasos = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            pasos++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
    return pasos;
}

// ------------------------------------------------------------
// 3. INSERTION SORT
//    Toma cada elemento y lo inserta en su posicion correcta
//    dentro de la parte ya ordenada del arreglo.
//    Complejidad: O(n^2) peor caso, O(n) mejor caso
// ------------------------------------------------------------
long long insertionSort(int* arr, int n) {
    long long pasos = 0;
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            pasos++;
            arr[j + 1] = arr[j];
            j--;
        }
        pasos++;
        arr[j + 1] = clave;
    }
    return pasos;
}

// ------------------------------------------------------------
// 4. SHELL SORT
//    Mejora de Insertion Sort. Ordena elementos separados por
//    un "gap" que va reduciendose hasta llegar a 1.
//    Complejidad: O(n log^2 n) aprox.
// ------------------------------------------------------------
long long shellSort(int* arr, int n) {
    long long pasos = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                pasos++;
                arr[j] = arr[j - gap];
                j -= gap;
            }
            pasos++;
            arr[j] = temp;
        }
    }
    return pasos;
}

// ------------------------------------------------------------
// 5. MERGE SORT
//    Divide el arreglo a la mitad recursivamente, luego fusiona
//    las mitades de forma ordenada.
//    Complejidad: O(n log n)
// ------------------------------------------------------------
long long contadorMerge = 0;

void fusionar(int* arr, int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        contadorMerge++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) { contadorMerge++; arr[k++] = L[i++]; }
    while (j < n2) { contadorMerge++; arr[k++] = R[j++]; }

    delete[] L;
    delete[] R;
}

void mergeOrdenar(int* arr, int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeOrdenar(arr, izq, medio);
        mergeOrdenar(arr, medio + 1, der);
        fusionar(arr, izq, medio, der);
    }
}

long long mergeSort(int* arr, int n) {
    contadorMerge = 0;
    mergeOrdenar(arr, 0, n - 1);
    return contadorMerge;
}

// ------------------------------------------------------------
// 6. QUICK SORT
//    Elige un pivote y particiona el arreglo: menores a la
//    izquierda, mayores a la derecha. Luego ordena cada parte.
//    Complejidad: O(n log n) promedio, O(n^2) peor caso
// ------------------------------------------------------------
long long contadorQuick = 0;

int partir(int* arr, int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        contadorQuick++;
        if (arr[j] <= pivote) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1]; arr[i + 1] = arr[alto]; arr[alto] = tmp;
    return i + 1;
}

void quickOrdenar(int* arr, int bajo, int alto) {
    if (bajo < alto) {
        int pi = partir(arr, bajo, alto);
        quickOrdenar(arr, bajo, pi - 1);
        quickOrdenar(arr, pi + 1, alto);
    }
}

long long quickSort(int* arr, int n) {
    contadorQuick = 0;
    quickOrdenar(arr, 0, n - 1);
    return contadorQuick;
}

// ------------------------------------------------------------
// 7. HEAP SORT
//    Construye un max-heap y luego extrae el maximo repetidamente
//    para ir formando el arreglo ordenado.
//    Complejidad: O(n log n)
// ------------------------------------------------------------
long long contadorHeap = 0;

void heapify(int* arr, int n, int i) {
    int mayor = i;
    int izq   = 2 * i + 1;
    int der   = 2 * i + 2;

    contadorHeap++;
    if (izq < n && arr[izq] > arr[mayor]) mayor = izq;
    contadorHeap++;
    if (der < n && arr[der] > arr[mayor]) mayor = der;

    if (mayor != i) {
        int tmp = arr[i]; arr[i] = arr[mayor]; arr[mayor] = tmp;
        heapify(arr, n, mayor);
    }
}

long long heapSort(int* arr, int n) {
    contadorHeap = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;
        heapify(arr, i, 0);
    }
    return contadorHeap;
}

// ------------------------------------------------------------
// 8. COUNTING SORT
//    Cuenta cuantas veces aparece cada valor y reconstruye
//    el arreglo ordenado. Muy eficiente cuando el rango es pequeno.
//    Complejidad: O(n + k), donde k = tamano del rango
// ------------------------------------------------------------
long long countingSort(int* arr, int n, int minVal, int maxVal) {
    long long pasos = 0;
    int rango = maxVal - minVal + 1;

    int* conteo = new int[rango]();
    int* salida  = new int[n];

    for (int i = 0; i < n; i++) { conteo[arr[i] - minVal]++; pasos++; }
    for (int i = 1; i < rango; i++) { conteo[i] += conteo[i - 1]; pasos++; }
    for (int i = n - 1; i >= 0; i--) {
        salida[conteo[arr[i] - minVal] - 1] = arr[i];
        conteo[arr[i] - minVal]--;
        pasos++;
    }
    for (int i = 0; i < n; i++) { arr[i] = salida[i]; pasos++; }

    delete[] conteo;
    delete[] salida;
    return pasos;
}

// ============================================================
//  Ordenar resultados por tiempo de menor a mayor
//  (usamos Insertion Sort sobre el arreglo de resultados)
// ============================================================
void ordenarResultados(Resultado* res, int total) {
    for (int i = 1; i < total; i++) {
        Resultado tmp = res[i];
        int j = i - 1;
        while (j >= 0 && res[j].tiempoNs > tmp.tiempoNs) {
            res[j + 1] = res[j];
            j--;
        }
        res[j + 1] = tmp;
    }
}

// ============================================================
//  MAIN
// ============================================================
int main() {

    int n, minV, maxV;

    // ── Pedir datos al usuario ──
    linea('=');
    cout << "    COMPARADOR DE ALGORITMOS DE ORDENAMIENTO" << endl;
    cout << "    Curso  : Programacion Competitiva" << endl;
    cout << "    UNA Puno - Ing. de Sistemas - VI Semestre" << endl;
    linea('=');

    cout << "  Ingrese la cantidad de numeros a generar : ";
    cin >> n;

    cout << "  Ingrese el valor minimo del rango        : ";
    cin >> minV;

    cout << "  Ingrese el valor maximo del rango        : ";
    cin >> maxV;

    // Validaciones
    if (n <= 0) {
        cout << "ERROR: La cantidad debe ser un numero positivo." << endl;
        return 1;
    }
    if (minV >= maxV) {
        cout << "ERROR: El valor minimo debe ser menor que el maximo." << endl;
        return 1;
    }

    // ── Generar arreglo aleatorio con semilla fija ──
    srand(42);
    int* original = new int[n];
    for (int i = 0; i < n; i++)
        original[i] = minV + rand() % (maxV - minV + 1);

    // ── Mostrar configuracion elegida ──
    linea();
    cout << "  Cantidad de elementos : " << n << endl;
    cout << "  Rango                 : [" << minV << ", " << maxV << "]" << endl;
    linea();
    cout << "  Arreglo generado aleatoriamente (" << n << " elementos):" << endl;
    cout << "  ";
    imprimirArreglo(original, n);
    linea();

    // ── Ejecutar los 8 algoritmos y medir ──
    const int TOTAL = 8;
    Resultado resultados[TOTAL];
    int* arr = new int[n];

    #define MEDIR(idx, etiqueta, llamada)                                             \
    {                                                                                 \
        copiarArreglo(original, arr, n);                                              \
        auto inicio = high_resolution_clock::now();                                   \
        long long p = llamada;                                                        \
        auto fin    = high_resolution_clock::now();                                   \
        resultados[idx].nombre   = etiqueta;                                          \
        resultados[idx].pasos    = p;                                                 \
        resultados[idx].tiempoNs = duration_cast<nanoseconds>(fin - inicio).count(); \
    }

    MEDIR(0, "Bubble Sort",    bubbleSort(arr, n))
    MEDIR(1, "Selection Sort", selectionSort(arr, n))
    MEDIR(2, "Insertion Sort", insertionSort(arr, n))
    MEDIR(3, "Shell Sort",     shellSort(arr, n))
    MEDIR(4, "Merge Sort",     mergeSort(arr, n))
    MEDIR(5, "Quick Sort",     quickSort(arr, n))
    MEDIR(6, "Heap Sort",      heapSort(arr, n))
    MEDIR(7, "Counting Sort",  countingSort(arr, n, minV, maxV))

    #undef MEDIR

    // ── Ordenar resultados por tiempo ──
    ordenarResultados(resultados, TOTAL);

    // ── Mostrar tabla ──
    cout << "  RESULTADOS (ordenados de menor a mayor tiempo)" << endl;
    linea();
    cout.width(5);  cout << "Pos";
    cout.width(17); cout << "Algoritmo";
    cout.width(20); cout << "Pasos";
    cout.width(24); cout << "Tiempo de ejecucion";
    cout << endl;
    linea();

    for (int i = 0; i < TOTAL; i++) {
        cout.width(5);  cout << (i + 1);
        cout.width(17); cout << resultados[i].nombre;
        cout.width(20); cout << resultados[i].pasos;
        cout.width(18); cout << resultados[i].tiempoNs;
        cout << " ns" << endl;
    }

    linea('=');
    cout << "  >> El mas rapido fue : " << resultados[0].nombre
         << " con " << resultados[0].tiempoNs << " ns" << endl;
    cout << "  >> El mas lento fue  : " << resultados[TOTAL-1].nombre
         << " con " << resultados[TOTAL-1].tiempoNs << " ns" << endl;
    linea('=');

    delete[] original;
    delete[] arr;
    return 0;
}
