#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"

stJugadores cargarJugadores(){
    stJugadores jugadores;

    jugadores.id=iIncremental();

    printf("\n Ingrese el nombre y apellido del jugador: ");
    fflush(stdin);
    gets(jugadores.nombreYApellido);

    printf("\n Ingrese el dni del jugador: ");
    scanf("%d", &jugadores.dni);

    printf("\n Ingrese la edad del jugador: ");
    scanf("%d", &jugadores.edad);

    return jugadores;
}

void mostrarJugadores(stJugadores jugadores){
    printf("\n Nombre y Apellido: %s", jugadores.nombreYApellido);
    printf("\n DNI:.............. %d", jugadores.dni);
    printf("\n Edad:............. %d", jugadores.edad);
    printf("\n ID:............... %d", jugadores.id);
    printf("\n ===========================");
}

