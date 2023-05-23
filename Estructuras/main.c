#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "legajo.h"
#define DIM_LEGAJOS 1000
#define ESC 27

int cargarArregloLegajo(stLegajo legajos[], int dim);
void muestrLegajo(stLegajo legajos[],int v);

int main()
{
    stLegajo legajos[DIM_LEGAJOS];
    int vLegajo=0;

    vLegajo=cargarArregloLegajo(legajos,DIM_LEGAJOS);
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
