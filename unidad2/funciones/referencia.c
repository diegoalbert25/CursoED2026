#include "stdio.h"

void incrementarUno(int *p) {
    (*p)++; 
}
int main(){
    int z = 7;
    printf("%d - ", z);
    incrementarUno(&z);
    printf("%d", z);
}