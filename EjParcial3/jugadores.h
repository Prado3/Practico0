#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED

#define ARCHIVO_JUGADORES "jugadores.dat"
#define ARCHIVO_EQUIPO "equipo.dat"
#define ARCHIVO_JUNIO "junior.dat"
#define ARCHIVO_SENIOR "senior.dat"

typedef struct{
    int idJugador;
    char nombre[30];
    int edad;
    int idEquipo;
} stJugador;

typedef struct{
    int idEquipo;
    char nombre[30];
    int zona; /// las zonas pueden ser 1, 2 o 3
} stEquipo;

stJugador cargarJugador();
void mostrarJugador(stJugador jugador);

#endif // JUGADORES_H_INCLUDED
