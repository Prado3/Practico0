#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[12];
    char sexo[20];
    float temperatura;
}stPaciente;

stPaciente cargarPaciente(int dni, float temp);
void mostrarSexo(stPaciente paciente);

#endif // PACIENTE_H_INCLUDED
