#include <iostream>
using namespace std;

int main() {
  string cad;
  cout << "Ingrese una palabra: ";
  getline(cin, cad);
  int contador{0};
    for (int i = 0; i < cad.length(); i++) {
      if (isdigit(cad[i])) {
          contador++;
    }
  }
  cout << "en la cadena hay: " << contador << " numeros"<< endl;
  return 0;
}
