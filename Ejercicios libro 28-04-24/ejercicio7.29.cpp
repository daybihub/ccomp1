#include <iostream>
#include <vector>

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

bool resolverReinas(vector<vector<int>>& tablero, int col) {
    if (col >= 8)
        return true;

    for (int i = 0; i < 8; i++) {
        if (esPosicionSegura(tablero, i, col)) {
            // Colocar la reina en la posición (i, col)
            tablero[i][col] = 1;

            if (resolverReinas(tablero, col + 1))
                return true;

            // Si colocar la reina en (i, col) no lleva a una solución, entonces la quitamos
            tablero[i][col] = 0;
        }
    }

    return false;
}

int main() {
    // Inicializar el tablero
    vector<vector<int>> tablero(8, vector<int>(8, 0));

    if (resolverReinas(tablero, 0)) {
        // Imprimir el tablero con las reinas colocadas
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No se encontró una solución." << endl;
    }

    return 0;
}
