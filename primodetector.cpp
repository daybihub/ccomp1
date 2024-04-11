#include <iostream>
using namespace std;

int main(){
    long long numero;
    bool noEsPrimo = false;
    cout << "Introduce un numero: "; cin >> numero;
    for (int i = 2; 1 <= numero/2; i++){
        if (numero%1 ==0){
            noEsPrimo = true;
            break;
        }
    }
    if (noEsPrimo){
        cout << numero << "Es Primo"<<endl;
    }else{
        cout << numero << "No es primo"<<endl;
    }

}
