// Ejercicio 2: Manipulación de cadenas con punteros

// Escriba un programa que lea una frase de máximo 100 caracteres y los almacenes en un vector de caracteres 
// (NO en una variable tipo string).
//     a) Imprima la dirección de cada carácter.
//     b) Utilizando punteros (es decir la notación con *) invierta la frase en el mismo vector de caracteres.
//     c) Imprima la dirección de cada carácter después de invertir.


#include <iostream>
using namespace std;
int main()
{
    char frase[101];
    cout << "Ingrese una frase: ";
    cin.getline(frase, 101);
    cout << "Direcciones de memoria del texto original:" << endl;
    char *p = frase;
    while(*p != '\0')
    {
        cout << "Caracter " << *p  << ": " << static_cast<void*>(p) << endl;  p++;
    }
    // Buscar el ultimo caracter
    char *inicio = frase;
    char *fin = frase;
    while(*fin != '\0')
    {  fin++;  }
    fin--;
    // Invertir utilizando punteros
    while(inicio < fin)
    {
        char aux = *inicio; *inicio = *fin; *fin = aux;
        inicio++; fin--;
    }
    cout << "Frase invertida: " << frase << endl;
    cout << "Direcciones de memoria de la frase invertida:" << endl;
    p = frase;
    while(*p != '\0')
    {
        cout << "Caracter " << *p<< ": " << static_cast<void*>(p)<< endl;p++;
    }
    return 0;
}