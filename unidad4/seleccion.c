#include <stdio.h> 
#define N 5
void selectionSort(int arr[], int n);
void mostrar();
int arreglo[N] = {6, 2, 4, 1, 5};
void main(){
    selectionSort(arreglo, 5);
}
void selectionSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        mostrar();
        int minIndex = i; 
        // Encontrar el mínimo en arr[i..n-1] 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[minIndex]) { 
                minIndex = j; 
            } 
        } 
        // Intercambiar (swap) el mínimo encontrado con el elemento en i 
        int temp = arr[i]; 
        arr[i] = arr[minIndex]; 
        arr[minIndex] = temp; 
    } 
    mostrar();
}

void mostrar(){
    for(int i=0; i<N; i++){
        printf("%d - ", arreglo[i]);
    }
    printf("\n ");
}