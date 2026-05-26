#include <stdio.h> 
#define N 5
void bubbleSort(int arr[], int n);
void mostrar();
int arreglo[N] = {6, 2, 4, 1, 5};
void main(){
    bubbleSort(arreglo, 5);
}
void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            mostrar();
        // Si el elemento actual es mayor que el siguiente, intercambiarlos 
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
}

void mostrar(){
    for(int i=0; i<N; i++){
        printf("%d - ", arreglo[i]);
    }
    printf("\n ");
}