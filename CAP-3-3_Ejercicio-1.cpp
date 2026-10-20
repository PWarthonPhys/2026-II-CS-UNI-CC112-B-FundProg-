//Ejercicio 1: Cálculo de la mínima distancia de Hamming entre cadenas de ADN utilizando punteros

// La diferencia de hamming entre dos cadenas de la misma longitud es el número de posiciones similares 
// donde los caracteres son diferentes. Hallar la mínima diferencia de hamming (diferente a cero) 
// entre 5 cadenas de 5 caracteres (incluyendo ‘\0’) que representan códigos de ADN.
// Todas las cadenas están en un arreglo denominado ADN. Los 4 caracteres posibles para formar las 
// cadenas son 'A','C','G','T'. Utilice punteros para acceder a las cadenas y compararlas. Imprima las 
// cadenas comparadas y sus diferencias de hamming.
// Indique un par de cadenas que tengan la menor distancia.
// Por ejemplo, para las cadenas:
// "AAAC","ACCC","AGCC", "GGAC", "GGGA"
// La menor distancia es: 1 entre ACCC y AGCC.


#include <iostream>
using namespace std;
// Calcula la distancia de Hamming entre dos cadenas usando punteros
int distanciaHamming(char *cadena1, char *cadena2) {
    int distancia = 0;
    while(*cadena1 != '\0' && *cadena2 != '\0') {
        if(*cadena1 != *cadena2) {
            distancia++; }
        cadena1++;
        cadena2++;
    }
    return distancia;
}
// Programa principal
int main() {
    char ADN[5][5] = {
        "AAAC", "ACCC", "AGCC", "GGAC", "GGGA"
    };
    int menorDistancia = 999;
    char *cadenaA;
    char *cadenaB;
    cout << "Comparaciones de cadenas:" << endl;
    // Comparar todas las cadenas entre sí
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            int distancia = distanciaHamming(
                ADN[i], ADN[j] );
            cout << ADN[i] << " - " << ADN[j] << " : " << distancia << endl;
            // Buscar la menor distancia diferente de cero
            if(distancia > 0 && distancia < menorDistancia) {
                menorDistancia = distancia;
                cadenaA = ADN[i];
                cadenaB = ADN[j]; } }
    }
    cout << endl;
    cout << "Menor distancia de Hamming: " << menorDistancia << endl;
    cout << "Cadenas con menor distancia: " << cadenaA << " y " << cadenaB << endl;
    return 0;
}