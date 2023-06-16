#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

stPaciente cargarPaciente(int dni, float temp){
    stPaciente paciente;

    paciente.temperatura=temp;

    strcpy(paciente.dni,dni);

    paciente.id=idAutoincremental();

    printf("\n Ingrese el nombre: ");
    fflush(stdin);
    gets(paciente.nombre);

    printf("\n Ingrese el apellido: ");
    fflush(stdin);
    gets(paciente.apellido);

    printf("\n Ingrese el sexo: ");
    fflush(stdin);
    gets(paciente.sexo);

    return paciente;
}

void mostrarSexo(stPaciente paciente){
    printf("\n nombre: %s",paciente.nombre);
    printf("\n apellido: %s",paciente.apellido);
    printf("\n sexo: %s",paciente.sexo);
}
