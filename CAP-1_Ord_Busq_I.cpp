//Algoritmo de Burbuja (Bubble sort)

void burbuja(int arr[], int n){
    for(int i = 0; i < n - 1; i++){ 
        for(int j = 0; j < n - 1 - i; j++){ // <- Optimizado aquí
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


// Algoritmo de Selección (Selection Sort)

void seleccion(int arr[], int n){
    for(int i= 0; i < n-1; ++i){
        int indMin = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[indMin]){
                indMin = j;
            }
        }
        swap(arr[i], arr[indMin]);
    }
}


//Algoritmo de Inserción (Insertion Sort)

void insercion(int arr[], int n){
    for(int i = 1; i < n; ++i){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


//BUSQUEDA

//Algoritmo de Búsqueda Lineal

int busquedaLineal(int arr[], int n, int valor){
    for(int i = 0; i < n; ++i){
        if(valor == arr[i]){
            return i;
        }
    }
    return -1;
}