/*
 * Conversión de un número decimal a binario utilizando recursividad.
 */

#include <iostream>
using namespace std;

void convertirABinario(unsigned long long numero) {
	if (numero > 1) {
		convertirABinario(numero / 2);
	}

	cout << numero % 2;
}

int main() {
	long long numero;
	cout << "Ingrese un número decimal no negativo: ";
	cin >> numero;Conversión de un número decimal a binario utilizando recursividad

	if (numero < 0) {
		cout << "El número debe ser no negativo.\n";
		return 1;
	}

	cout << "En binario: ";
	convertirABinario(static_cast<unsigned long long>(numero));
	cout << '\n';

	return 0;
}
