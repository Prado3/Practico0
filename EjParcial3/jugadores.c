#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"

stJugador cargarJugador(){
    stJugador jugador;
    stEquipo equipo;
    int idE=0;
    printf("\n Ingrese el id de su equipo: ");
    scanf("%d", &idE);

    FILE* archiE=fopen(ARCHIVO_EQUIPO,"rb");
    if(archiE){
        while(fread(&equipo,sizeof(stEquipo),1,archiE)>0){
            if(equipo.idEquipo==idE){
                jugador.idEquipo=idE;
                printf("\n Ingrese el nombre del Jugador: ");
                fflush(stdin);
                gets(jugador.nombre);

                printf("\n Ingrese la edad: ");
                scanf("%d", &jugador.edad);

                jugador.idJugador=idJ() ;
            }
        }
        fclose(archiE);
    }




    return jugador;
}

void mostrarJugador(stJugador jugador){
    printf("\n Nombre:....%s",jugador.nombre);
    printf("\n Edad:......%d",jugador.edad);
    printf("\n idEquipo:..%d", jugador.idEquipo);
    printf("\n idJugador:..%d", jugador.idJugador);
}
