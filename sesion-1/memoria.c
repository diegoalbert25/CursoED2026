#include "stdio.h"


int main(){
    //4294967296 - 2147483648
    int array[5] = {2147483647, 20, 30, 40, 50};
    char array2[5];
    printf("El valor del array 0 %d\n", array[0]);
    printf("Posicion 1 Esto es %x - ", &array[0]); //Posicion de memoria donde vive el primer entero
    printf(" igual a esto %x\n", array);
    //printf("Posicion %d\n", array[10]);
    printf("Posicion de segundo elemento %x - ", &array[1]);
    printf("\ndireccion de memoria 0 de Array 2 %x - ", &array2[0]); //Posicion de memoria donde vive el primer entero
    printf("\ndireccion de memoria 1 de Array 2 %x - ", &array2[1]); //Posicion de memoria donde vive el primer entero
    printf("\ndireccion de memoria 1 de Array 2 %x - ", &array2[2]); //Posicion de memoria donde vive el primer entero
    printf("\ndireccion de memoria 1 de Array 2 %x - ", &array2[3]); //Posicion de memoria donde vive el primer entero
    return 0;
}