#include <iostream>
#include <vector>
using namespace std;

bool esPosicionSegura(const vector<vector<int>>& tablero, int row, int col) {
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
bool resolverReinasFuerzaBrutaExhaustiva(vector<vector<int>>& tablero, int col, int& intento) {
    // Si todas las reinas están colocadas, entonces hemos encontrado una solución
    if (col >= 8)
        return true;
    // Intentar colocar la reina en cada fila de esta columna
    for (int i = 0; i < 8; i++) {
        if (esPosicionSegura(tablero, i, col)) {
            tablero[i][col] = 1;
            // Llamar recursivamente para colocar las reinas restantes
            if (resolverReinasFuerzaBrutaExhaustiva(tablero, col + 1, intento))
                return true;
            // Si no es posible colocar una reina en la posición actual, retroceder
            tablero[i][col] = 0;
        }
    }
    intento++;
    return false;
}

int main() {
    vector<vector<int>> tablero(8, vector<int>(8, 0));
    int intento = 1;
    
    if (resolverReinasFuerzaBrutaExhaustiva(tablero, 0, intento)) {
        cout << "Solucion encontrada en el intento " << intento << ":" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No se encontro una solucion." << endl;
    }
    return 0;
}