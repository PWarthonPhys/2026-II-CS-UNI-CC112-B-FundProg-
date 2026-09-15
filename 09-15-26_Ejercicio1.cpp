#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;

// Prototipos de funciones
void merge(int *documento, int *hash, int inicio, int medio, int fin);
void mergeSort(int *documento, int *hash, int inicio, int fin);
void buscarPorHash(int *documento, int *hash, int n, int hashBuscado);
void imprimirDatos(int *documento, int *hash, int n, const char *titulo);

int main()
{
    int documentos[MAX] = {101,102,103,104,105};

    int hashes[MAX] = {500,200,500,100,300};

    int n = 5;

    cout << "\nSISTEMA DE GESTION DOCUMENTAL\n";

    imprimirDatos(documentos, hashes, n, "Datos originales");

    mergeSort(documentos, hashes, 0, n-1);

    imprimirDatos(documentos, hashes, n, "Documentos ordenados por Hash");

    int hashBuscado = 500;

    buscarPorHash(documentos, hashes, n, hashBuscado);

    return 0;
}


//----------------------------------------------------
// ORDENAMIENTO MERGE SORT
//----------------------------------------------------

void merge(int *documento, int *hash, int inicio, int medio, int fin)
{
    int tempDocumento[MAX];
    int tempHash[MAX];

    int i = inicio;
    int j = medio + 1;
    int k = 0;

    while(i <= medio && j <= fin)
    {
        if(*(hash+i) <= *(hash+j))
        {
            *(tempDocumento+k)=*(documento+i);
            *(tempHash+k)=*(hash+i);
            i++;
        }
        else
        {
            *(tempDocumento+k)=*(documento+j);
            *(tempHash+k)=*(hash+j);
            j++;
        }

        k++;
    }

    while(i <= medio)
    {
        *(tempDocumento+k)=*(documento+i);
        *(tempHash+k)=*(hash+i);
        i++;
        k++;
    }

    while(j <= fin)
    {
        *(tempDocumento+k)=*(documento+j);
        *(tempHash+k)=*(hash+j);
        j++;
        k++;
    }

    for(int x=0;x<k;x++)
    {
        *(documento+inicio+x)=*(tempDocumento+x);
        *(hash+inicio+x)=*(tempHash+x);
    }
}


void mergeSort(int *documento,int *hash,int inicio,int fin)
{
    if(inicio<fin)
    {
        int medio=(inicio+fin)/2;

        mergeSort(documento,hash,inicio,medio);

        mergeSort(documento,hash,medio+1,fin);

        merge(documento,hash,inicio,medio,fin);
    }
}


//----------------------------------------------------
// BUSQUEDA BINARIA
//----------------------------------------------------

void buscarPorHash(int *documento,int *hash,int n,int hashBuscado)
{
    int inicio=0;
    int fin=n-1;
    int posicion=-1;

    while(inicio<=fin)
    {
        int medio=(inicio+fin)/2;

        if(*(hash+medio)==hashBuscado)
        {
            posicion=medio;
            break;
        }
        else if(*(hash+medio)<hashBuscado)
        {
            inicio=medio+1;
        }
        else
        {
            fin=medio-1;
        }
    }

    if(posicion==-1)
    {
        cout<<"\nNo existen documentos con Hash "<<hashBuscado<<endl;
    }
    else
    {
        cout<<"\nDOCUMENTOS ENCONTRADOS CON HASH "<<hashBuscado<<endl;

        cout<<setw(12)<<"Documento"
            <<setw(12)<<"Hash"<<endl;

        int i=posicion;

        while(i>0 && *(hash+i-1)==hashBuscado)
        {
            i--;
        }

        while(i<n && *(hash+i)==hashBuscado)
        {
            cout<<setw(12)<<*(documento+i)
                <<setw(12)<<*(hash+i)
                <<endl;

            i++;
        }
    }
}


//----------------------------------------------------
// IMPRESION DE DATOS
//----------------------------------------------------

void imprimirDatos(int *documento,int *hash,int n,const char *titulo)
{
    cout<<"\n"<<titulo<<endl;

    cout<<setw(12)<<"Documento"
        <<setw(12)<<"Hash"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<setw(12)<<*(documento+i)
            <<setw(12)<<*(hash+i)
            <<endl;
    }
}
