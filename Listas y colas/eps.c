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