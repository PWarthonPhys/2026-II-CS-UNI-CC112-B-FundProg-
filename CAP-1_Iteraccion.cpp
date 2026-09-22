//Iteracion def.
// La iteración consiste en repetir un conjunto de instrucciones mediante estructuras 
// repetitivas como for, while o do while, hasta que se cumpla una condición determinada.
// A diferencia de la recursividad, en la iteración la función no se llama a sí misma, sino 
// que utiliza un ciclo que controla la repetición del proceso.
// En este ejercicio se utilizará una estructura repetitiva para analizar varios números 
// ingresados por el usuario y determinar cuántos números positivos, negativos y ceros existen.

//Desarrollar un programa en lenguaje C que permita ingresar N números enteros y determine:
//    • Cantidad de números positivos. 
//    • Cantidad de números negativos. 
//    • Cantidad de números iguales a cero. 
//El programa debe utilizar una estructura repetitiva (for) para procesar todos los valores ingresados.


#include <iostream>
using namespace std;

void sign (int);

void sign ( int a ){
    if (a > 0){
        cout << " Positivo "<<endl;
    }
    else{ 
        if(a == 0){ 
            cout << " Cero "<<endl;
        }
        else {
            cout << " Negativo "<<endl;
        }
    }

}

int main()
{
    int cantidad;
    int numero;

    int positivos = 0;
    int negativos = 0;
    int ceros = 0;

    cout <<"Ingrese cantidad de numeros  ";
    cin >> cantidad;
    
    for(int i = 1; i <= cantidad; i++ ){
        cout << "Ingrese el numero " << i << " "  ;
        cin >> numero;
        sign(numero);

    }


    return 0;
}

