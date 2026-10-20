
//Ejercicio 1: Optimización de distancia mínima de salto utilizando punteros

//Hay un río de longitud L a lo largo del cual se han colocado rocas. Hay una roca en la ubicación 0 
//(el comienzo del río), una roca en la ubicación L (el final del río) y luego n otras rocas entre estas.
//Por ejemplo, en un río de longitud 12, podríamos tener rocas en las siguientes ubicaciones: 0, 5, 8 y 12.
//Una vaca comienza en la primera roca (ubicación 0), salta de allí a la segunda roca, salta de la segunda 
//roca a la tercera roca, y así sucesivamente, hasta llegar a la roca al final del río (ubicación L).
//Su distancia mínima de salto es la distancia mínima entre cualquier par de rocas consecutivas. En el 
//ejemplo anterior, la distancia mínima de salto es tres, como lo demuestra la distancia entre las rocas 
//en las ubicaciones 5 y 8.El granjero John está aburrido de los saltos cortos que realiza la vaca, por 
//lo que quiere aumentar la distancia mínima de salto tanto como sea posible. No puede quitar la roca en 
//la ubicación 0 o L, pero puede quitar m de las otras rocas.
//En el ejemplo anterior, supongamos que el granjero John puede quitar una piedra. Su elección es entonces 
//quitar la roca en la ubicación 5 o la ubicación 8. Si quita la roca en la ubicación 5, la distancia mínima
//de salto es cuatro (desde la ubicación 8 a la ubicación 12). Sin embargo, no debería hacer eso, porque 
//si quita la roca en la ubicación 8, entonces logrará una distancia de salto mínima mayor de cinco 
//(de la ubicación 0 a la ubicación 5).
//Tu tarea es maximizar la distancia mínima de salto que el granjero John puede lograr quitando m rocas.
//Utiliza punteros.


#include <iostream>
using namespace std;
// =================================================================
// Verifica si una distancia mínima es posible utilizando punteros
// =================================================================
bool esPosible(
    int *rocas, int cantidad, int eliminar, int distancia)
{
    int eliminadas = 0; int ultimaRoca = rocas[0];
    for(int i = 1; i < cantidad; i++)
    {
        int salto = rocas[i] - ultimaRoca;
        if(salto < distancia){ eliminadas++;}
        else{ ultimaRoca = rocas[i]; }
    }
    return eliminadas <= eliminar;
}

// =================================================
// Búsqueda binaria de la distancia máxima
// =================================================
int buscarDistanciaMaxima(
    int *rocas, int cantidad, int eliminar) {
    int inicio = 1; int fin = rocas[cantidad-1]; int respuesta = 0;
    while(inicio <= fin)
    {
        int medio = (inicio + fin) / 2;
        if(esPosible(rocas,cantidad,eliminar,medio))
        {  respuesta = medio; inicio = medio + 1; }
        else{  fin = medio - 1; }
    }  return respuesta; }

// =================================================
// Programa principal
// =================================================
int main()
{
    int L = 25; int n = 5; int m = 2; int rocas[] =
    {
        0,2,11,14,17,21,25
    };
    int cantidad = n + 2;
    int resultado =
        buscarDistanciaMaxima(
            rocas, cantidad, m);
    cout << "Distancia minima maxima: " << resultado;
    return 0;
}