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