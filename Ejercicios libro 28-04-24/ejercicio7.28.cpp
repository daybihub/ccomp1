#include <iostream>
#include <string>
using namespace std;

bool verificarPalindromo(const string &cadena, int inicio, int fin) {
    if (inicio >= fin) {
        return true;
    }
    if (cadena[inicio] != cadena[fin]) {
        return false;
    }
    return verificarPalindromo(cadena, inicio + 1, fin - 1);
}

bool esPalindromo(const string &cadena) {// Función que limpia la cadena eliminando espacios, comas, puntos y signos de interrogación
    string cadenaLimpia;
    for (char caracter : cadena) {
        if (isalpha(caracter)) { // is alpha sirve para no incluir caracteres no alfabéticos
            cadenaLimpia += tolower(caracter);
        }
    }
    return verificarPalindromo(cadenaLimpia, 0, cadenaLimpia.length() - 1);
}

int main() {
    string cadena = "Red roses run no risk, sir, on nurses order.";
    cout << boolalpha << esPalindromo(cadena) << endl;
    return 0;
}