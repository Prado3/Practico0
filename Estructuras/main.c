#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "legajo.h"
#include <string.h>
#define DIM_LEGAJOS 1000
#define ESC 27

int cargarArregloLegajo(stLegajo legajos[], int dim);
void muestrLegajo(stLegajo legajos[],int v);
void ordenarLegajoMatricula(stLegajo legajos[],int v);

int main()
{
    stLegajo legajos[DIM_LEGAJOS];
    int vLegajo=0;

    vLegajo=cargarArregloLegajo(legajos,DIM_LEGAJOS);
    muestrLegajo(legajos,vLegajo);
    ordenarLegajoMatricula(legajos,vLegajo);
    muestrLegajo(legajos,vLegajo);

    return 0;
}

int cargarArregloLegajo(stLegajo legajos[], int dim){
    char op;
    int i=0;

    while(i<dim && op!=ESC){
        system("cls");
        legajos[i]=cargarUnLegajo();
        i++;
        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }
    return i;
}

void muestrLegajo(stLegajo legajos[],int v){
    for(int i =0;i<v;i++){
        muestraUnLegajo(legajos[i]);
    }
}

void ordenarLegajoMatricula(stLegajo legajos[],int v){
    int posMenor=0;
    int j=0;
    int z=0;

    for(int i =0; i<v;i++){
        for(j=0;j<v;j++){
            if(legajos[j].matricula<legajos[posMenor].matricula){
                posMenor=j;
            }
        }
        for(z=v;z>=0;z--){
            legajos[z+1].matricula=legajos[z].matricula;
        }
        legajos[i].matricula=legajos[posMenor].matricula;
        for(z=v;z>=0;z--){
            strcpy(legajos[z+1].nombres, legajos[z].nombres);
        }
        strcpy(legajos[i].nombres, legajos[posMenor].nombres);
        for(z=v;z>=0;z--){
            strcpy(legajos[z+1].genero, legajos[z].genero);
        }
        strcpy(legajos[i].genero, legajos[posMenor].genero);
    }
}
