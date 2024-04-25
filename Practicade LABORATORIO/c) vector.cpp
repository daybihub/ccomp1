#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numeros; // Crea un vector de enteros vacío
    numeros.push_back(10);
    numeros.push_back(20); // Agrega elementos al final del vector
    numeros.push_back(30);

    cout << "El tamaño del vector es: " << numeros.size() << endl; // Imprime el tamaño actual del vector

    cout << "Elementos del vector: ";
    for (int num : numeros) { // Accede a los elementos y los imprime
        cout << num << " "; 
    }
    cout << endl;

    numeros.pop_back(); // Elimina el último elemento

    cout << "Vector después de pop_back: ";     // Imprime el vector después de eliminar el último elemento
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}