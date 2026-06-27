#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SABORES 10
#define MAX_NOMBRE 30

typedef struct
{
    char nombre[MAX_NOMBRE];
    char sabor[MAX_NOMBRE];
    float litros;
    float total;
} Cliente;

typedef struct
{
    char sabor[MAX_NOMBRE];
    float litros;
} Recipiente;

#define MAX_CLIENTES 50

Cliente cola[MAX_CLIENTES];

int cabeza = 0;
int final = -1;

void encolar()
{
    if (final == MAX_CLIENTES - 1)
    {
        printf("La cola esta llena.\n");
        return;
    }

    final++;

    printf("Nombre del cliente: ");
    scanf(" %[^\n]", cola[final].nombre);

    printf("Sabor: ");
    scanf(" %[^\n]", cola[final].sabor);

    printf("Cantidad de litros: ");
    scanf("%f", &cola[final].litros);

    cola[final].total = cola[final].litros * 8000;

    printf("Cliente registrado correctamente.\n");
}

void desencolar()
{
    if (cabeza > final)
    {
        printf("No hay clientes en espera.\n");
        return;
    }

    printf("\n--- ATENDIENDO CLIENTE ---\n");
    printf("Nombre: %s\n", cola[cabeza].nombre);
    printf("Sabor: %s\n", cola[cabeza].sabor);
    printf("Cantidad: %.2f litros\n", cola[cabeza].litros);
    printf("Total: $%.2f\n", cola[cabeza].total);

    cabeza++;

    printf("Cliente atendido correctamente.\n");
}

#define MAX_CLIENTES 50

Cliente cola[MAX_CLIENTES];
Recipiente pila[MAX_SABORES];



int tope = -1;

void push()
{
    if (tope == MAX_SABORES - 1)
    {
        printf("La pila esta llena.\n");
        return;
    }

    tope++;

    printf("Nombre del sabor: ");
    scanf(" %[^\n]", pila[tope].sabor);

    printf("Cantidad de litros: ");
    scanf("%f", &pila[tope].litros);

    printf("Recipiente agregado correctamente.\n");
}

void buscarRecipiente()
{
    Recipiente auxiliar[MAX_SABORES];
    int topeAux = -1;

    while (tope >= 0)
    {
        if (strcmp(pila[tope].sabor, cola[cabeza].sabor) == 0)
        {
            pila[tope].litros -= cola[cabeza].litros;

            if (pila[tope].litros <= 0)
            {
                tope--;
            }

            break;
        }

        auxiliar[++topeAux] = pila[tope];
        tope--;
    }

    while (topeAux >= 0)
    {
        pila[++tope] = auxiliar[topeAux];
        topeAux--;
    }
}
void mostrarCola()
{
    int i;

    if (cabeza > final)
    {
        printf("No hay clientes en espera.\n");
        return;
    }

    printf("\n----- CLIENTES EN ESPERA -----\n");

    for (i = cabeza; i <= final; i++)
    {
        printf("Nombre: %s\n", cola[i].nombre);
        printf("Sabor: %s\n", cola[i].sabor);
        printf("Litros: %.2f\n", cola[i].litros);
        printf("Total: $%.2f\n\n", cola[i].total);
    }
}
void mostrarPila()
{
    int i;

    if (tope == -1)
    {
        printf("La pila esta vacia.\n");
        return;
    }

    printf("\n------ PILA DE RECIPIENTES ------\n");

    for (i = tope; i >= 0; i--)
    {
        printf("Sabor: %s\n", pila[i].sabor);
        printf("Litros: %.2f\n\n", pila[i].litros);
    }
}
int main()
{
    int opcion;

    do
    {
        printf("\n===== HELADERIA DOÑA PEPE =====\n");
        printf("1. Registrar recipiente\n");
        printf("2. Mostrar pila\n");
        printf("3. Registrar cliente\n");
        printf("4. Mostrar cola\n");
        printf("5. Atender cliente\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                push();
                break;

            case 2:
                mostrarPila();
                break;

            case 3:
                encolar();
                break;

            case 4:
                mostrarCola();
                break;

            case 5:
                desencolar();
                break;

            case 6:
                printf("Gracias por utilizar el sistema.\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }

    } while(opcion != 6);
}