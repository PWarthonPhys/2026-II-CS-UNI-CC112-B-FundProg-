#include<iostream>
#define N 5
#define M 5
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int Notas[N][M] ;
    //system("color 0a");
    for(int i=0; i<N;i++){//FILAS
        for(int j=0; j<M; j++){ //columnas
            Notas[i][j] = rand ()%26 + 65; //<---0
            cout << (char)Notas[i][j]<< " ";
            //_sleep(200);
        }
        cout << endl;
    }

    return 0;
}
