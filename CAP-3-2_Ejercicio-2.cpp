// Ejercicio 2: Gestión dinámica de postulantes mediante estructuras y punteros en C++

// La Corporación UNIX en sus planes de expansión desea contratar más empleados para
// el área de ventas. Los postulantes ingresan su código de postulación (3 dígitos) 
// y edad al sistema de contrataciones. El sistema elige el(los) postulante(s) cuya(s) 
// edad(es) sea menor o igual a la edad deseada del empleado o empleados a contratarse.
// Desarrolle el programa en C++ usando asignación dinámica de memoria y una estructura.
// Ejemplo de salida:
// Entrada:
// Por favor, ingrese el número de postulantes: 3
// Ingrese código del postulante (3 dígitos): 234
// Ingrese la edad: 34
// Ingrese código del postulante (3 dígitos): 325
// Ingrese la edad: 56
// Ingrese código del postulante (3 dígitos): 432
// Ingrese la edad: 45
// Por favor, ingrese la edad deseada del empleado:
// 47
// Salida:
// 234 34
// 432 45

#include <iostream>
using namespace std;
// Estructura para almacenar información del postulante
struct Postulante {
    int codigo;
    int edad; };
// Función para registrar postulantes utilizando memoria dinámica
void registrarPostulantes(Postulante *p, int cantidad) {
    for(int i = 0; i < cantidad; i++) {
        cout << "Ingrese codigo del postulante (3 digitos): ";
        cin >> p[i].codigo;
        cout << "Ingrese la edad: ";
        cin >> p[i].edad;
    }}
// Función para buscar postulantes según la edad deseada
void buscarPostulantes(
    Postulante *p,
    int cantidad,
    int edadDeseada)
{
    cout << "\nPostulantes seleccionados:" << endl;
    for(int i = 0; i < cantidad; i++) {
        if(p[i].edad <= edadDeseada) {
            cout << p[i].codigo << " " << p[i].edad << endl; } } }
int main() {
    int cantidad;
    cout << "Por favor, ingrese el numero de postulantes: "; cin >> cantidad;
    // Asignación dinámica de memoria
    Postulante *postulantes =
        new Postulante[cantidad];
    // Registro de datos
    registrarPostulantes(
        postulantes, cantidad);
    int edadDeseada;
    cout << "Por favor, ingrese la edad deseada del empleado: ";
    cin >> edadDeseada;
    // Búsqueda de postulantes que cumplen la condición
    buscarPostulantes(
        postulantes,
        cantidad,
        edadDeseada);
    // Liberar memoria dinámica
    delete[] postulantes;
    return 0;
}