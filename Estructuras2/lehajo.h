#ifndef LEHAJO_H_INCLUDED
#define LEHAJO_H_INCLUDED

typedef struct{
    int matricula;
    char nombre[30];
    char genero[30];
} stAlumno;

stAlumno cargarLegajo(int i);
void muestraLegajo(stAlumno legajo);

#endif // LEHAJO_H_INCLUDED
