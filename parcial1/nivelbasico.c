
#include <stdio.h>

#define MAX 100

// Mostrar arreglo
void mostrar(int v[], int n) {
    int i;
    printf("Arreglo: ");
    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Copiar arreglo
void copiar(int origen[], int destino[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

// Metodo Burbuja
void burbuja(int v[], int n) {
    int i, j, aux;

    printf("\n--- Metodo Burbuja ---\n");

    for(i = 0; i < n - 1; i++) {
        printf("Pasada %d:\n", i + 1);

        for(j = 0; j < n - 1 - i; j++) {
            if(v[j] > v[j + 1]) {
                

                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                mostrar(v, n);
            }
        }
    }
}

// Metodo Seleccion
void seleccion(int v[], int n) {
    int i, j, min, aux;

    printf("\n--- Metodo Seleccion ---\n");

    for(i = 0; i < n - 1; i++) {
        min = i;

        for(j = i + 1; j < n; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }

        if(min != i) {
            
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }

        printf("Pasada %d: ", i + 1);
        mostrar(v, n);
    }
}

// Metodo Insercion
void insercion(int v[], int n) {
    int i, j, key;

    printf("\n--- Metodo Insercion ---\n");

    for(i = 1; i < n; i++) {
        key = v[i];
        j = i - 1;

        printf("Insertando: %d\n", key);

        while(j >= 0 && v[j] > key) {
            

            v[j + 1] = v[j];
            j--;

            mostrar(v, n);
        }

        v[j + 1] = key;
        mostrar(v, n);
    }
}

int main() {
    int v[MAX];         // arreglo de trabajo
    int original[MAX];  // arreglo original (NO se modifica)
    int aux[MAX];       // copia para cada metodo

    int n = 0;
    int op;
    int datos = 0;
    int i;

    do {
        printf("\n--- MENU ---\n");

        if(datos == 0) {
            printf("1. Registrar datos\n");
        } else {
            printf("1. Registrar datos\n");
            printf("2. Mostrar arreglo original\n");
            printf("3. Burbuja\n");
            printf("4. Seleccion\n");
            printf("5. Insercion\n");
            printf("6. Salir\n");
        }

        printf("Opcion: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Cantidad de datos: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    printf("Dato %d: ", i + 1);
                    scanf("%d", &v[i]);

                    original[i] = v[i]; 
                }

                datos = 1;
                break;

            case 2:
                if(datos == 1) {
                    printf("Arreglo original:\n");
                    mostrar(original, n);
                } else {
                    printf("Primero registre datos\n");
                }
                break;

            case 3:
                if(datos == 1) {
                    copiar(original, aux, n); 
                    burbuja(aux, n);
                } else {
                    printf("Primero registre datos\n");
                }
                break;

            case 4:
                if(datos == 1) {
                    copiar(original, aux, n);
                    seleccion(aux, n);
                } else {
                    printf("Primero registre datos\n");
                }
                break;

            case 5:
                if(datos == 1) {
                    copiar(original, aux, n);
                    insercion(aux, n);
                } else {
                    printf("Primero registre datos\n");
                }
                break;

            case 6:
                if(datos == 1) {
                    printf("Fin del programa\n");
                } else {
                    printf("Opcion invalida\n");
                }
                break;

            default:
                printf("Opcion invalida\n");
        }

    } while(op != 6);

    return 0;
}
