#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lehajo.h"

stAlumno cargarLegajo(int i){
    stAlumno legajo;

    printf("\n Ingrese el nombre: ");
    fflush(stdin);
    gets(legajo.nombre);

    printf("\n Ingrese el genero: ");
    fflush(stdin);
    gets(legajo.genero);

    legajo.matricula = i;

    return legajo;
}

void muestraLegajo(stAlumno legajo){
    printf("\n Nombre:......: %s", legajo.nombre);
    printf("\n Genero:......: %s", legajo.genero);
    printf("\n Matricula:...: %d", legajo.matricula);
    printf("\n==================================");
}
