#ifndef LEGAJO_H_INCLUDED
#define LEGAJO_H_INCLUDED

typedef struct{
    int legajo;
    char nombreYApellido[30];
    int edad;
    int anio;
} stAlumno;

stAlumno cargarLegajo(int i);
void mostrarLegajo(stAlumno alumno);

#endif // LEGAJO_H_INCLUDED
