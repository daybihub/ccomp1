//implemente un programa que pida opor teclado una cadena considerando espacios, y convierta dicha cadena a Mayusculas.
#include <iostream>
using namespace std;
int main() {
    string input;
    cout << "Ingrese una palabra: ";
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 'a' + 'A';
        }
    }
    cout << "En mayusculas es: " << input << endl;
    return 0;
}

