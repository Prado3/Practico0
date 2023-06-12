#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "jugadores.h"
#define ESTRUCTURA 1000

#define ESC 27

int idJ();
void cargarJugadoresArchi(char nombreArchivo[], int dim);
void mostrarJugadorArchi(char nombreArchivo[]);
void pasarJugadores(char nombreArchivo[]);

int main()
{
    stJugador jugador[ESTRUCTURA];

    cargarJugadoresArchi(ARCHIVO_JUGADORES,ESTRUCTURA);
    mostrarJugadorArchi(ARCHIVO_JUGADORES);
    pasarJugadores(ARCHIVO_JUGADORES);
    mostrarJugadorArchi(ARCHIVO_JUNIO);
    mostrarJugadorArchi(ARCHIVO_SENIOR);
    return 0;
}

void cargarJugadoresArchi(char nombreArchivo[], int dim){
    char op;
    int i=0;
    stJugador jugador;
    FILE* archi=fopen(nombreArchivo,"wb");
    if(archi){
        while(i<dim && op!=ESC){
            system("cls");
            jugador=cargarJugador();
            i++;
            fwrite(&jugador,sizeof(stJugador),1,archi);
            printf("\n Ingrese ESC para dejar de cargar..");
            op=getch();
        }
        fclose(archi);
    }

}

int idJ(){
    static int i=0;
    i++;
    return i;
}

void mostrarJugadorArchi(char nombreArchivo[]){
    stJugador jugador;
    FILE* archi= fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&jugador,sizeof(stJugador),1,archi)>0){
            mostrarJugador(jugador);
        }
    }
    fclose(archi);
}

void pasarJugadores(char nombreArchivo[]){
    stJugador jugador;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&jugador,sizeof(stJugador),1,archi)>0){
            if(jugador.edad>=30){
                FILE* archiSenio=fopen(ARCHIVO_SENIOR,"ab");
                fwrite(&jugador,sizeof(stJugador),1,archiSenio);
                fclose(archiSenio);
            }else{
                FILE* archiJunior=fopen(ARCHIVO_JUNIO,"ab");
                fwrite(&jugador,sizeof(stJugador),1,archiJunior);
                fclose(archiJunior);
            }

        }
        fclose(archi);
    }
}
