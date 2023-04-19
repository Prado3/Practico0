#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

int cargarArreglo(char array[], int valido, int dimension);
void mostrarArreglo(char array[], int valido);
void encontrarElemento(char array[], int valido, char elemento);

int main()
{
    int dim = 20;
    char arreglo[dim];
    int valido = 0;
    char elemento;


    valido = cargarArreglo(arreglo,valido,dim);
    mostrarArreglo(arreglo, valido);

    printf("\n Ingrese el elemento a encontrar: ");
    scanf("%c",&elemento);
    fflush(stdin);
    encontrarElemento(arreglo,valido,elemento);

    return 0;
}

int cargarArreglo(char array[], int valido, int dimension){
    char op;

    do{
        printf("\n Ingrese un caracter: ");
        scanf("%c", &array[valido]);
        valido++;
        fflush(stdin);
        printf("\n Ingrese ESC para dejar de agregar elementos...");
        op=getch();

    }while(op != ESC && valido<dimension);
    return valido;
}

void mostrarArreglo(char array[], int valido){
    for(int i = 0; i<valido;i++){
        printf("\n %c", array[i]);
    }
}

void encontrarElemento(char array[], int valido, char elemento){
    int i = 0;

    while(i<valido){
        if(elemento == array[i]){
            printf("\n El elemento se encuentra en el arreglo");
        }
        i++;
    }
    if(i>=valido){
        printf("\n EL elemento no se encuentra en el arreglo");
    }
}


