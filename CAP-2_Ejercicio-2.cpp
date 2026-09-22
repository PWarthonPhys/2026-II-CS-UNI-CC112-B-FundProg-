#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;


// Prototipos

void quickSort(int *codigo, double *promedio, int inicio, int fin);

int particion(int *codigo, double *promedio, int inicio, int fin);

void intercambiar(int *a, int *b);

void intercambiarDouble(double *a, double *b);

void mostrarRanking(int *codigo, double *promedio, int n);



int main()
{

    int codigo[MAX] = {
        202501,
        202502,
        202503,
        202504,
        202505
    };


    double promedio[MAX] = {
        14.5,
        18.2,
        15.8,
        19.0,
        16.7
    };


    int n = 5;



    cout << "RANKING ACADEMICO ORIGINAL\n";

    mostrarRanking(codigo, promedio, n);



    // Aplicar Quick Sort

    quickSort(codigo, promedio, 0, n - 1);



    cout << "\nRANKING ACADEMICO ORDENADO\n";

    mostrarRanking(codigo, promedio, n);



    return 0;

}



//------------------------------------------------
// QUICK SORT
//------------------------------------------------


void quickSort(int *codigo,
               double *promedio,
               int inicio,
               int fin)
{

    if(inicio < fin)
    {

        int posicion = particion(codigo,
                                 promedio,
                                 inicio,
                                 fin);



        quickSort(codigo,
                  promedio,
                  inicio,
                  posicion - 1);



        quickSort(codigo,
                  promedio,
                  posicion + 1,
                  fin);

    }

}




int particion(int *codigo,
              double *promedio,
              int inicio,
              int fin)
{

    double pivote = *(promedio + fin);


    int i = inicio - 1;



    for(int j = inicio; j < fin; j++)
    {

        // Orden descendente

        if(*(promedio + j) > pivote)
        {

            i++;


            intercambiar(codigo+i,
                         codigo+j);


            intercambiarDouble(promedio+i,
                               promedio+j);

        }

    }



    intercambiar(codigo+i+1,
                 codigo+fin);


    intercambiarDouble(promedio+i+1,
                       promedio+fin);



    return i+1;

}





void intercambiar(int *a, int *b)
{

    int aux = *a;

    *a = *b;

    *b = aux;

}





void intercambiarDouble(double *a, double *b)
{

    double aux = *a;

    *a = *b;

    *b = aux;

}




void mostrarRanking(int *codigo,
                    double *promedio,
                    int n)
{


    cout << endl;


    cout << setw(12) << "Posicion"
         << setw(15) << "Codigo"
         << setw(15) << "Promedio"
         << endl;



    for(int i=0;i<n;i++)
    {

        cout << setw(12)
             << i+1

             << setw(15)
             << *(codigo+i)

             << setw(15)
             << *(promedio+i)

             << endl;

    }

}
