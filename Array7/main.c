#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

int cargarArregloOrdenado(char array[], int valido, int dimension);
void recorrerArregloOrdenado(char array[], int valido);
void insertarElemento(char array[],int valido, char elemento);

int main()
{
    int dim = 20;
    char arreglo[dim];
    int valido=0;
    char elemento;

    valido = cargarArregloOrdenado(arreglo,valido,dim);

    recorrerArregloOrdenado(arreglo, valido);

    printf("\n Inserte la letra a ubicar en orden: ");
    scanf("%c", &elemento);

    insertarElemento(arreglo,valido,elemento);

    recorrerArregloOrdenado(arreglo, valido+1);


    return 0;
}

int cargarArregloOrdenado(char array[], int valido, int dimension){
    char op;

    do{
        printf("\n Ingrese en orden el abecedacio: ");
        scanf("%c", &array[valido]);
        valido++;
        fflush(stdin);

        printf("\n Ingrese ESC para dejar de agregar...");
        op=getch();
    }while(op!=ESC && valido<dimension);
    return valido;
}

void recorrerArregloOrdenado(char array[], int valido){
    for(int i = 0; i < valido; i++){
        printf("\n %c", array[i]);
    }
}

void insertarElemento(char array[],int valido, char elemento){
    int i = valido-1;
    int bandera = 0;
    printf("\ %c", elemento);
    printf("\ %d", elemento);

    while(i>=0){
        while(elemento >= array[i] && bandera == 0){
            array[i+1] = elemento;
            bandera++;
        }

        if(elemento < array[i]){
            array[i+1] = array[i];
        }
        i--;
    }
}
