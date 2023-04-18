#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

int cargarArreglo(float array[], int valido, int dimension);
void mostrarArreglo(float array[], int valido);
float sumarArreglo(float array[], int valido);

int main()
{
    int dim = 100;
    float arreglo[dim];
    int valido = 0;
    float suma;

    valido = cargarArreglo(arreglo, valido, dim);
    mostrarArreglo(arreglo,valido);

    suma = sumarArreglo(arreglo,valido);
    printf("\n La suma total del arreglo es: %.2f", suma);
    return 0;
}

int cargarArreglo(float array[], int valido, int dimension){
    char op;

    while(op != ESC && valido < dimension){
        printf("\n Ingrese un numero real: ");
        scanf("%f", &array[valido]);
        valido++;

        printf("\n Ingrese ESC para no agregar mas elementos...");
        op=getch();
    }
    return valido;
}

void mostrarArreglo(float array[], int valido){
    for(int i = 0; i<valido;i++){
        printf("\n %.2f ",array[i]);
    }
}

float sumarArreglo(float array[], int valido){
    float suma=0;
    int i = 0;
    while(i < valido){
        suma = suma + array[i];
        i++;
    }

    return suma;
}



