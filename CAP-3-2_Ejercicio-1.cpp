#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Crear matriz dinámica
int** crearMatriz(int filas, int columnas) {
    int **matriz = new int*[filas];
    for(int i = 0; i < filas; i++)
    {  matriz[i] = new int[columnas];  }
    return matriz; }
// Llenar matriz con valores aleatorios
void llenarMatriz(int **matriz, int filas, int columnas) {
    for(int i = 0; i < filas; i++)
    { for(int j = 0; j < columnas; j++)
        {  matriz[i][j] = rand() % 201 - 100;  } } }
// Mostrar matriz
void mostrarMatriz(int **matriz, int filas, int columnas) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t"; }
        cout << endl; }}
// Ordenar matriz ascendente
void ordenarMatriz(int **matriz, int filas, int columnas) {
    int total = filas * columnas;
    for(int i = 0; i < total - 1; i++) {
        for(int j = i + 1; j < total; j++) {
            int fila1 = i / columnas;
            int col1 = i % columnas;
            int fila2 = j / columnas;
            int col2 = j % columnas;
            if(matriz[fila1][col1] > matriz[fila2][col2]) {
                int aux = matriz[fila1][col1];
                matriz[fila1][col1] = matriz[fila2][col2];
                matriz[fila2][col2] = aux;
            }}}}
// Liberar memoria
void liberarMatriz(int **matriz, int filas) {
    for(int i = 0; i < filas; i++)
    { delete[] matriz[i]; }
    delete[] matriz; }
int main() {
    srand(time(0));
    int filas = 5; int columnas = 7;
    int **matriz = crearMatriz(filas,columnas);
    llenarMatriz( matriz, filas, columnas);
    cout<<"Matriz original:"<<endl;
    mostrarMatriz( matriz, filas, columnas);
    ordenarMatriz( matriz, filas, columnas);
    cout<<"\nMatriz ordenada:"<<endl;
    mostrarMatriz( matriz, filas, columnas);
        liberarMatriz( matriz, filas);
        return 0; }