#include <iostream>

#define MAX 9

using namespace std;

bool esValido(int tablero[MAX][MAX], int fila, int col, int num) {
    for (int x = 0; x < MAX; x++) {
        if (tablero[fila][x] == num) return false;
    }

    for (int x = 0; x < MAX; x++) {
        if (tablero[x][col] == num) return false;
    }

    int inicioFila = fila - fila % 3;
    int inicioCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i + inicioFila][j + inicioCol] == num) return false;
        }
    }

    return true;
}

bool SolucionarSudoku(int tablero[MAX][MAX]) {
    for (int fila = 0; fila < MAX; fila++) {
        for (int col = 0; col < MAX; col++) {
            if (tablero[fila][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (esValido(tablero, fila, col, num)) {
                        tablero[fila][col] = num;
                        if (SolucionarSudoku(tablero)) {
                            return true;
                        }
                        tablero[fila][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Imprimir(int tablero[MAX][MAX]) {
    for (int fila = 0; fila < MAX; fila++) {
        if (fila % 3 == 0 && fila != 0) {
            cout << "------+-------+------" << endl;
        }

        for (int col = 0; col < MAX; col++) {
            if (col % 3 == 0 && col != 0) {
                cout << "| ";
            }
            cout << tablero[fila][col] << " ";
        }
        cout << endl;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int tablero[MAX][MAX] = {};
    int pos_x, pos_y, valor;
    while (cin >> pos_x >> pos_y >> valor) {
        if (pos_x >= 1 && pos_x <= 9 && pos_y >= 1 && pos_y <= 9 && valor >= 0 && valor <= 9) {
            tablero[pos_x - 1][pos_y - 1] = valor;
        }
    }

    cout << "Sudoku inicial:" << endl;
    Imprimir(tablero);

    if (SolucionarSudoku(tablero)) {
        cout << endl << "Sudoku resuelto:" << endl;
        Imprimir(tablero);
    } else {
        cout << endl << "No se pudo resolver el Sudoku con los datos dados." << endl;
    }

    return 0;
}
