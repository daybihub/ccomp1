#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Función para verificar si una reina puede colocarse en la posición (row, col)
bool esPosicionSegura(vector<vector<int>>& tablero, int row, int col) {
    int i, j;

    // Verificar la fila en la dirección izquierda
    for (i = 0; i < col; i++)
        if (tablero[row][i])
            return false;

    // Verificar la diagonal superior izquierda
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j])
            return false;

    // Verificar la diagonal inferior izquierda
    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (tablero[i][j])
            return false;

    return true;
}

bool resolverReinasSinRecursividad(vector<vector<int>>& tablero) {
    stack<int> columnas;
    int col = 0;

    while (true) {
        if (col >= 8)
            return true;

        bool reinasColocadas = false;
        for (int i = 0; i < 8; i++) {
            if (esPosicionSegura(tablero, i, col)) {
                // Colocar la reina en la posición (i, col)
                tablero[i][col] = 1;
                columnas.push(col);
                col++;
                reinasColocadas = true;
                break;
            }
        }

        // Si no se pudo colocar una reina en la columna actual, retrocedemos
        if (!reinasColocadas) {
            if (columnas.empty())
                return false;
            else {
                col = columnas.top();
                columnas.pop();
                for (int i = 0; i < 8; i++) {
                    if (tablero[i][col] == 1) {
                        tablero[i][col] = 0;
                        break;
                    }
                }
                col++;
            }
        }
    }
}

int main() {
    // Inicializar el tablero
    vector<vector<int>> tablero(8, vector<int>(8, 0));

    if (resolverReinasSinRecursividad(tablero)) {
        // Imprimir el tablero con las reinas colocadas
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No se encontro una solución." << endl;
    }

    return 0;
}
