#ifndef LEGAJO_H_INCLUDED
#define LEGAJO_H_INCLUDED

typedef struct{
    int matricula;
    char nombres[30];
    char genero[30];
} stLegajo;

stLegajo cargarUnLegajo();
void muestraUnLegajo(stLegajo legajo);


#endif // LEGAJO_H_INCLUDED
