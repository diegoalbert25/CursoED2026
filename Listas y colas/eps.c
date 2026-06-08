#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct nodo

{
    char cedula[20];
    char nombre[50];

    int dia;
    int mes;
    int anio;
    int edad;

    struct nodo*sig;
    
    


}nodo;

/*Cola Prioritaria*/

nodo*cabPrioridad = NULL;
nodo*ultimoPrioridad = NULL;

/*Cola Normal*/

nodo*cabNormal = NULL;
nodo*ultimoNormal = NULL;

/*Calcular Edad*/

int calcularEdad(int dia, int mes, int anio)
{
    time_t t = time(NULL);
    struct tm *actual = localtime(&t);

    int edad = (actual->tm_year + 1900) - anio;

    if(mes > (actual->tm_mon + 1) ||
       (mes == (actual->tm_mon + 1)&&
        dia > actual->tm_mday))

    {
        edad--;
    }

    return edad;
    
}


/*Encolar*/

void enqueue(nodo**cabeza, nodo**ultimo, nodo*nuevo)
{
    nuevo -> sig = NULL;

    if(*cabeza == NULL)
    {
        *cabeza = nuevo;
        *ultimo = nuevo;
    }
    else
    {
        (*ultimo)-> sig = nuevo;
        *ultimo = nuevo;
    }

}


/*Registro del paciente*/

void registrarPaciente()
{
    nodo *nuevo = (nodo *)malloc(sizeof(nodo));

    if(nuevo == NULL)
    {
        printf("Error de memoria\n");
        return;
    }

    printf("\nCedula: ");
    scanf("%s", nuevo->cedula);

    getchar();

    printf("Nombre: ");
    fgets(nuevo->nombre, 50, stdin);
    nuevo->nombre[strcspn(nuevo->nombre, "\n")] = '\0';

    printf("Fecha de nacimiento\n");

    printf("Dia: ");
    scanf("%d" , &nuevo->dia);

    printf("Mes: ");
    scanf("%d" , &nuevo->mes);

    printf("Anio: ");
    scanf("%d" , &nuevo->anio);

    nuevo->edad = calcularEdad(
        
        nuevo->dia,
        nuevo->mes,
        nuevo->anio
    );


    char sexo;

    printf("Sexo(M o F): ");
    scanf(" %c", &sexo);

    if(sexo == 'F' ||
        sexo == 'f' ||
        nuevo->edad >= 60)
    {
    
        enqueue(
            &cabPrioridad,
            &ultimoPrioridad,
            nuevo
        );
        printf("Paciente agregado a COLA PRIORITARIA\n");


    }
    else
    {
        enqueue(
            &cabNormal,
            &ultimoNormal,
            nuevo
        );
        printf("Paciente agregado a COLA NORMAL\n");

    }
}

void mostrarCola(nodo *cab)
{
    nodo *actual = cab;

    if(actual == NULL)
    {
        printf("\nCola vacia\n");
        return;
    }

    while (actual != NULL)
    {
        printf("\n------------------");
        printf("\nCedula: %s", actual->cedula);
        printf("\nNombre: %s", actual->nombre);
        printf("\nEdad: %d", actual->edad);
        printf("\n------------------\n");

        actual = actual->sig;
    }
    
}

