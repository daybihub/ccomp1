#include "Student.h"
#include <iostream>

using namespace std;

int main() {
  string name1, name2;
  int age1, age2;

  cout << "Ingrese el nombre del primer estudiante: ";
  cin >> name1;
  cout << "Ingrese la edad del primer estudiante: ";
  cin >> age1;

  cout << "Ingrese el nombre del segundo estudiante: ";
  cin >> name2;
  cout << "Ingrese la edad del segundo estudiante: ";
  cin >> age2;

  Student student1(name1, age1);
  Student student2(name2, age2);

  cout << "\nDatos del primer estudiante:" << endl;
  cout << "Nombre: " << student1.getName() << endl;
  cout << "Edad: " << student1.getAge() << endl;
  cout << "Es mayor de edad: " << (student1.isOlder() ? "Si" : "No") << endl;

  cout << "\nDatos del segundo estudiante:" << endl;
  cout << "Nombre: " << student2.getName() << endl;
  cout << "Edad: " << student2.getAge() << endl;
  cout << "Es mayor de edad: " << (student2.isOlder() ? "Si" : "No") << endl;

  return 0;
}