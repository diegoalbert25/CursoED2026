#include <stdio.h> 
#define N 15

void insertionSort(int arr[], int n);
void mostrar();
int arreglo[N] = {156, 252, 454, 666, 5555, 1546, 2234, 4564, 1789, 50, 6456, 4562, 45674, 4571, 54567};
void main(){
    mostrar();
    insertionSort(arreglo, N);
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i]; // Elemento a insertar
        int j = i - 1;
        // Desplazar hacia la derecha los elementos mayores que 'clave'
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insertar 'clave' en la posición que dejó libre
        arr[j + 1] = clave;
        mostrar();
    }
}
void mostrar(){
    for(int i=0; i<N; i++){
        printf("%d - ", arreglo[i]);
    }
    printf("\n ");
}