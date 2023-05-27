#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lehajo.h"
#define ESC 27
#define DIM_LEGAJOS 1000

int cargarAlumnosLegajo(stAlumno legajo[], int dim);
void mostrarArregloLegajo(stAlumno legajo[], int v);
void ordenarLegajoNombreInsercion(stAlumno legajo[], int v);
int cantidadGeneroArreglo(stAlumno legajo[], int v);

int main()
{
    stAlumno legajo[DIM_LEGAJOS];
    int vLegajo=0;
    int cantidadGenero=0;

    vLegajo = cargarAlumnosLegajo(legajo,DIM_LEGAJOS);
    mostrarArregloLegajo(legajo,vLegajo);
    ordenarLegajoNombreInsercion(legajo,vLegajo);
    mostrarArregloLegajo(legajo,vLegajo);
    cantidadGenero=cantidadGeneroArreglo(legajo,vLegajo);
    printf("\n La cantidad del genero elegido: %d", cantidadGenero);

    return 0;
}

int cargarAlumnosLegajo(stAlumno legajo[], int dim){
    char op;
    int i=0;

    while(i<dim && ESC!=op){
        system("cls");
        legajo[i]=cargarLegajo(i);
        i++;
        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }
    return i;
}

void mostrarArregloLegajo(stAlumno legajo[], int v){
    for(int i =0; i<v;i++){
        muestraLegajo(legajo[i]);
    }
}

void ordenarLegajoNombreInsercion(stAlumno legajo[], int v){
    stAlumno aux[30];
    int j=0;

    for(int i=0;i<v-1;i++){
        for(j=0;j<v-1;j++){
            if(strcmpi(legajo[j].nombre, legajo[j+1].nombre)>0){
                aux[0]=legajo[j];
                legajo[j]=legajo[j+1];
                legajo[j+1]=aux[0];
            }
        }
    }
}

int cantidadGeneroArreglo(stAlumno legajo[], int v){
    stAlumno gene[30];
    int cantidad=0;
    int i=0;

    printf("\n Ingrese el genero a buscar: ");
    fflush(stdin);
    gets(gene[0].genero);
    printf("\n %s",gene[0].genero);
    while(i<v){
        if(strcmp(gene[0].genero,legajo[i].genero)==0){
            cantidad++;
        }
        i++;
    }
    return cantidad;
}


