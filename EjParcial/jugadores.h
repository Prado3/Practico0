#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED

typedef struct{
    int id;
    int dni;
    char nombreYApellido[30];
    int edad;
}stJugadores;

stJugadores cargarJugadores();
void mostrarJugadores(stJugadores jugadores);
#endif // JUGADORES_H_INCLUDED
