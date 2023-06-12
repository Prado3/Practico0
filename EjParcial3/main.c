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
int cantidadRegistros(char nombreArchivo[]);
int cantidadRegistrosFiltro(char nombreArchivo[],int filtro);
void procentaje(int filtro);
int pasarNombres(char nombres[][20]);
void mostrarArreglo(char nombres[][20], int v);

int main()
{
    stJugador jugador[ESTRUCTURA];
    int cont=0;
    char nombres[20][20];
    int canNombres=0;

    //cargarJugadoresArchi(ARCHIVO_JUGADORES,ESTRUCTURA);
    mostrarJugadorArchi(ARCHIVO_JUGADORES);
    //pasarJugadores(ARCHIVO_JUGADORES);
    //mostrarJugadorArchi(ARCHIVO_JUNIO);
    //mostrarJugadorArchi(ARCHIVO_SENIOR);
    procentaje(20);
    canNombres=pasarNombres(nombres);
    printf("\n la cantidad de nombres pasados es: %d", canNombres);
    mostrarArreglo(nombres,canNombres);
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

int cantidadRegistros(char nombreArchivo[]){
    int cont=0;
    FILE* archi= fopen(nombreArchivo,"rb");
    if(archi){
        fseek(archi,0,SEEK_END);
        cont=ftell(archi)/sizeof(stJugador);
        fclose(archi);
    }
    return cont;
}

int cantidadRegistrosFiltro(char nombreArchivo[],int filtro){
    int cont=0;
    stJugador jugador;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&jugador,sizeof(stJugador),1,archi)>0){
            if(jugador.edad>filtro){
                cont++;
            }
        }
        fclose(archi);
    }
    return cont;
}

void procentaje(int filtro){
    stJugador jugador;
    int canTotal=cantidadRegistros(ARCHIVO_JUGADORES);
    int canFiltro=cantidadRegistrosFiltro(ARCHIVO_JUGADORES,filtro);
    float resultado=0;

    resultado=((float)canFiltro*100)/(float)canTotal;
    printf("\n La cantidad de jugadores mayores a %d es: %.2f",filtro,resultado);

}

int pasarNombres(char nombres[][20]){
    stJugador jugador;
    int i =0;
    FILE* archi=fopen(ARCHIVO_JUGADORES,"rb");
    if(archi){
        while(fread(&jugador,sizeof(stJugador),1,archi)){
             strcpy(nombres[i],jugador.nombre);
             i++;
        }
    }
    return i;
}

void mostrarArreglo(char nombres[][20], int v){
    for(int i=0;i<v;i++){
        printf("\n Nombre: %s",nombres[i]);
    }
}

