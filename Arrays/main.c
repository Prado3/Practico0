#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

int cargarArreglo(int arreglo[], int validos, int dim);
void mostrarArreglo(int array[], int valido);
int sumaArreglo(int array[], int valido);
void cargarPilaDeArreglo(int array[], int valido, Pila *p);

int main()
{
    Pila dada;
    inicpila(&dada);
    int dim = 20;
    int arreglo[dim];
    int valido= 0;
    int suma = 0;

    valido = cargarArreglo(arreglo,valido, dim);
    printf("\n La cantidad de elementos cargados es: %d", valido);

    mostrarArreglo(arreglo, valido);

    suma = sumaArreglo(arreglo, valido);
    printf("\n La suma de los elementos del arreglo es: %d", suma);

    cargarPilaDeArreglo(arreglo,valido,&dada);
    mostrar(&dada);

    return 0;
}

int cargarArreglo(int array[], int validos, int dimension){
    char op;
    int i = 0;

    do{
        printf("\n Ingrese un numero entero: ");
        scanf("%d", &array[validos]);

        printf("\n Ingrese ESC para dejar de agregar...");
        op=getch();
        validos++;
    }while(op!=ESC && validos < dimension);

    return validos;
}

void mostrarArreglo(int array[], int valido){

    for(int i = 0; i <valido; i++){
        printf("\n %d - %d", array[i], i);
    }
}

int sumaArreglo(int array[], int valido){
    int suma = 0;
    int i = 0;

    while( i < valido){
        suma = suma + array[i];
        i++;
    }
    return suma;
}

void cargarPilaDeArreglo(int array[], int valido, Pila *p){
    int i = 0;

    for(i = valido; i > 0; i--){
        apilar(p, array[i-1]);
    }
}
