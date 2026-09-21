// Conversión de un número decimal a binario utilizando recursividad
// Planteamiento
// Entrada:
// Número decimal: 13
// 
// Proceso:
// 13 / 2 = 6 residuo 1
// 6 / 2 = 3 residuo 0
// 3 / 2 = 1 residuo 1
// 1 / 2 = 0 residuo 1
// 
// Salida:
// Número binario: 1101

#include <iostream>
using namespace std;

void decimalABinario(int decimal) {
    if (decimal > 1) {
        decimalABinario(decimal / 2);
    }
    cout << decimal % 2;
}

int main() {
    int numeroDecimal;

    cout << "Ingrese un número decimal: ";
    cin >> numeroDecimal;

    cout << "El número binario es: ";
    decimalABinario(numeroDecimal);
    cout << endl;

    return 0;
}