#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "legajo.h"

stLegajo cargarUnLegajo(){
    stLegajo legajo;

    printf("\n Ingrese el nombre: ");
    fflush(stdin);
    gets(legajo.nombres);

    printf("\n Ingrese su sexo: ");
    fflush(stdin);
    gets(legajo.genero);

    printf("\n Ingrese su matricula: ");
    scanf("%d", &legajo.matricula);

    return legajo;
}

void muestraUnLegajo(stLegajo legajo){
    printf("\n Nombre:......: %s", legajo.nombres);
    printf("\n Genero:......: %s", legajo.genero);
    printf("\n Matricula:...: %d", legajo.matricula);
    printf("\n==================================");
}

