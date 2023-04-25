#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

int cargarArreglo(int array[], int validos, int dimension);
void recorrerArreglo(int array[], int validos);
void maximoCaracter(char array[],int validos);
int capicua(int array[], int validos);
void invertirArreglo(int array[], int validos,int dim);

int main()
{
    int dim = 20;
    char arreglo[dim];
    int validos = 0;
    char max;
    int arreglo2[dim];
    int validos2 = 0;
    int capi=0;

    //validos = cargarArreglo(arreglo,validos,dim);
    //recorrerArreglo(arreglo,validos);
    //maximoCaracter(arreglo,validos);
    validos2 = cargarArreglo(arreglo2,validos2,dim);
    recorrerArreglo(arreglo2,validos2);
    //capi = capicua(arreglo2,validos2);
    //if(capi==0){
   //     printf("\n No es capicua");
   // }else{
   //     printf("\n Es capicua");
   // }
    invertirArreglo(arreglo2,validos2,dim);
    recorrerArreglo(arreglo2,validos2);



    return 0;
}

int cargarArreglo(int array[], int validos, int dimension){
    char op;

    while(op!=ESC && validos < dimension){
        printf("\n Ingrese un caracter: ");
        scanf("%d", &array[validos]);
        validos++;
        fflush(stdin);

        printf("\n Ingrese ESC para salir...");
        op=getch();
    }
    return validos;
}

void recorrerArreglo(int array[], int validos){
    for(int i = 0; i < validos;i++){
        printf("\n %d", array[i]);
    }
}

void maximoCaracter(char array[],int validos){
    int i = 0;
    char max = array[validos-1];
    printf("\n %c",max);

    while(i<validos-1){
        if(array[i]>max){
            max = array[i];
            i++;
        }else{
            i++;
        }
    }
    printf("\n El maximocaracter es: %c", max);
}

int capicua(int array[], int validos){
    validos = validos - 1;
    int i = 0;

    while(i <= validos){
        if(array[i]==array[validos]){
            i++;
            validos--;
        }else{
            return 0;
        }
    }
    return 1;
}

void invertirArreglo(int array[], int validos,int dim){
    int i = 0;
    validos=validos-1;

    while(i<validos){
        array[dim-1]=array[validos];
        array[validos]=array[i];
        array[i]=array[dim-1];
        validos--;
        i++;
    }
}
