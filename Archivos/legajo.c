#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "legajo.h"

stAlumno cargarLegajo(int i){
    stAlumno alumno;

    alumno.legajo = i;

    printf("\n Ingrese nombre y apellido del alumno: ");
    fflush(stdin);
    gets(alumno.nombreYApellido);

    printf("\n Ingrese la edad del alumno edad: ");
    scanf("%d", &alumno.edad);

    printf("\n Ingrese el anio de nacimiento: ");
    scanf("%d", &alumno.anio);

    return alumno;
}

void mostrarLegajo(stAlumno alumno){
    printf("\n Nombre y Apellido:..: %s", alumno.nombreYApellido);
    printf("\n Edad:...............: %d", alumno.edad);
    printf("\n A�o:................: %d", alumno.anio);
    printf("\n Legajo:.............: %d", alumno.legajo);
    printf("\n==================================");
}
