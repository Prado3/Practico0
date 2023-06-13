#include <stdio.h>
#include <stdlib.h>
#include "jugadores.h"
#include <conio.h>
#include "string.h"

#define ESTRUCTURA 20
#define ARCHIVO_JUGADORES "jugadores.dat"
#define ESC 27

int cargarEstructura(stJugadores jugadores[], int dim);
void mostrarEstructura(stJugadores jugadores[], int v);
void pasarJugadoresArchivo(stJugadores jugadores[], char nombreArchivo[]);
void mostrarArchivo(char nombreArchivo[]);
int cantidadArchivos(char nombreArchivo[]);
int iIncremental();
int id();
void modificarEdad(char nombreArchivo[], int pos);
void mayoresEdad(char nombreArchivo[]);
//int mostrarMayor(char nombreArchivo);
int encontrarNombre(char nombreArchivo[], char nombre[20]);

int main()
{
    stJugadores jugadores[ESTRUCTURA];
    int JValidos=0;
    int canArchivos=0;
    stJugadores mayor[ESTRUCTURA];
    int buscar=0;
    char nombre[20];

    //JValidos=cargarEstructura(jugadores,ESTRUCTURA);
    //mostrarEstructura(jugadores,JValidos);
    //pasarJugadoresArchivo(jugadores,ARCHIVO_JUGADORES);
    mostrarArchivo(ARCHIVO_JUGADORES);

    canArchivos=cantidadArchivos(ARCHIVO_JUGADORES);
    printf("\n La cantidad de jugadores en el archivo es de: %d", canArchivos);
    modificarEdad(ARCHIVO_JUGADORES,3);
    mostrarArchivo(ARCHIVO_JUGADORES);
    //mayoresEdad(ARCHIVO_JUGADORES);
//    mayorEdad(ARCHIVO_JUGADORES);
    printf("\n Ingrese el nombre a buscar: ");
    fflush(stdin);
    gets(nombre);
    buscar=encontrarNombre(ARCHIVO_JUGADORES,nombre);
    if(buscar==-1)
    {
        printf("\n No se encontro el jugador");
    }
    else
    {
        printf("\n El dni del jugador buscado es: %d", buscar);
    }

    return 0;
}

int iIncremental()
{
    static int i=0;
    i++;
    return i;
}

/*int id(){
    stJugadores jugadores;
    int id=iIncremental();
    FILE* archi=fopen(ARCHIVO_JUGADORES,"rb");
    if(archi){
        fseek(archi,sizeof(stJugadores)*(-1),SEEK_END);
        while(fread(&jugadores,sizeof(stJugadores),1,archi)>0){
            id=jugadores.id;
        }
        fclose(archi);
    }
    return id+1;
}*/

int cargarEstructura(stJugadores jugadores[], int dim)
{
    char op;
    int i=0;

    while(i<dim && op!=ESC)
    {
        system("cls");
        jugadores[i]=cargarJugadores();
        i++;
        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }
    return i;
}

void mostrarEstructura(stJugadores jugadores[], int v)
{
    for(int i =0; i<v; i++)
    {
        mostrarJugadores(jugadores[i]);
    }
}

void pasarJugadoresArchivo(stJugadores jugadores[], char nombreArchivo[])
{
    int i=0;

    FILE* archi=fopen(nombreArchivo, "ab");
    if(archi)
    {
        if(fread(&jugadores,sizeof(stJugadores),1,archi)==0)
        {
            while(i<5)
            {
                fwrite(&jugadores[i],sizeof(stJugadores),1,archi);
                i++;
            }
        }
        fclose(archi);
    }
}

void mostrarArchivo(char nombreArchivo[])
{
    stJugadores jugadores;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&jugadores, sizeof(stJugadores),1,archi)>0)
        {
            mostrarJugadores(jugadores);
        }
        fclose(archi);
    }
}

int cantidadArchivos(char nombreArchivo[])
{
    int con=0;
    FILE* archi=fopen(nombreArchivo, "rb");
    if(archi)
    {
        fseek(archi,0,SEEK_END);
        con= ftell(archi)/sizeof(stJugadores);
        fclose(archi);
    }

    return con;
}

void modificarEdad(char nombreArchivo[], int pos)
{
    stJugadores jugadores;
    int nuevaEdad=0;
    FILE* archi= fopen(nombreArchivo,"r+b");
    //fseek(archi,0,SEEK_SET);
    //rewind(archi);
    int flag =0;
    if(archi)
    {
        while(flag == 0 && fread(&jugadores,sizeof(stJugadores),1,archi)>0)
        {
            if(jugadores.id==pos)
            {
                printf("\n La edad ahora es de: %d", jugadores.edad);
                printf("\n Ingrese su edad correcta: ");
                scanf("%d", &nuevaEdad);
                jugadores.edad=nuevaEdad;
                //fseek(archi,0,SEEK_CUR);
                fseek(archi,(-1)*sizeof(stJugadores),SEEK_CUR);
                fwrite(&jugadores,sizeof(stJugadores),1,archi);
                printf("\n La edad ahora es de: %d", jugadores.edad);
                flag =1;
            }
        }
        fclose(archi);
    }

}

void mayoresEdad(char nombreArchivo[])
{
    stJugadores jugadores;
    FILE* archi =fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&jugadores,sizeof(stJugadores),1,archi)>0)
        {
            if(jugadores.dni>18)
            {

                mostrarJugadores(jugadores);
            }
        }
    }

}

/*int mostrarMayor(char nombreArchivo[]){
    stJugadores jugadores;
    stJugadores mayor;
    FILE* archi=fopen(nombreArchivo,"rb");
    fread(&jugadores,sizeof(stJugadores),1,archi);
    mayor=jugadores;
    if(archi){
        while(fread(&jugadores,sizeof(stJugadores),1,archi)>0){
            if(mayor.edad<jugadores.edad){
                mayor=jugadores;
            }
        }
        fclose(archi);
    }
    mostrarJugadores(mayor);
    return mayor;
}*/

int encontrarNombre(char nombreArchivo[], char nombre[20])
{
    stJugadores jugadores;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&jugadores,sizeof(stJugadores),1,archi)>0)
        {
            if(strcmpi(nombre,jugadores.nombreYApellido)==0)
            {
                return jugadores.dni;
            }
        }
        fclose(archi);
    }
    return -1;
}



