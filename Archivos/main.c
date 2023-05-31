#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "pila.h"
#include "legajo.h"
#define ESC 27
#define DIM_LEGAJO 1000
#define ARCHI_LEGAJO "legajo.dat"

int cargarArregloALumno(stAlumno alumno[],int dim);
void mostrarArregloAlumno(stAlumno alumno[], int v);
int cargarArchivo(char nombreDelArchivo[], int dim);
void muestraDatoArchivo(char nombreDelArchivo[]);
int cargarUnAlumnoArchivo(char nombreDelArchivo[], int v);
void pasarPilaAlumnosMayores(char nombreDelArchivo[],Pila* dada);
int cantidadDeAlumnosMayores(char nombreDelArchivo[], int edad);
void mostrarRangoEdadNombres(char nombreDelArchivo[], int min, int max);
void alumnoMayor(char nombreDelArchivo[]);

int main()
{
    stAlumno alumno[DIM_LEGAJO];
    int vAlumno =0;
    Pila dada;
    inicpila(&dada);
    int canMayores=0;

    vAlumno=cargarArchivo(ARCHI_LEGAJO,DIM_LEGAJO);
    muestraDatoArchivo(ARCHI_LEGAJO);
    system("PAUSE()");
    //vAlumno=cargarUnAlumnoArchivo(ARCHI_LEGAJO,vAlumno);
    //muestraDatoArchivo(ARCHI_LEGAJO);

    //pasarPilaAlumnosMayores(ARCHI_LEGAJO,&dada);
    //mostrar(&dada);
    //canMayores=cantidadDeAlumnosMayores(ARCHI_LEGAJO,20);
    //printf("\n La cantidad de alumnos mayores a 20 es: %d", canMayores);
    //mostrarRangoEdadNombres(ARCHI_LEGAJO,20,70);
    alumnoMayor(ARCHI_LEGAJO);



    return 0;
}

int cargarArregloALumno(stAlumno alumno[],int dim){
    char op;
    int i=0;

    while(i<dim && op!=ESC){
        system("cls");
        alumno[i]=cargarLegajo(i);
        i++;

        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }
    return i;
}

void mostrarArregloAlumno(stAlumno alumno[], int v){
    for(int i =0;i<v;i++){
        mostrarLegajo(alumno[i]);
    }
}

int cargarArchivo(char nombreDelArchivo[], int dim){
    char op;
    stAlumno alumno;
    int i=0;
    FILE* archi = fopen(nombreDelArchivo, "ab");
    if(archi){
        while(op!=ESC && i<dim){
            system("cls");
            alumno=cargarLegajo(i);
            i++;
            fwrite(&alumno, sizeof(stAlumno),1, archi);
            printf("\n Ingrese ESC para dejar de cargar...");
            op=getch();
        }
        fclose(archi);
    }
}

void muestraDatoArchivo(char nombreDelArchivo[]){
    stAlumno alumno;
    FILE* archi=fopen(nombreDelArchivo, "rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            mostrarLegajo(alumno);
        }
        fclose(archi);
    }
}

int cargarUnAlumnoArchivo(char nombreDelArchivo[], int v){
    stAlumno alumno;
    FILE* archi=fopen(nombreDelArchivo,"ab");
    if(archi){
        system("cls");
        alumno=cargarLegajo(v);
        fwrite(&alumno,sizeof(stAlumno),1,archi);
        fclose(archi);
    }
}

void pasarPilaAlumnosMayores(char nombreDelArchivo[],Pila* dada){
    stAlumno alumno;
    FILE* archi =fopen(nombreDelArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            if(alumno.edad>=18){
                apilar(dada,alumno.edad);
            }
        }
        fclose(archi);
    }
}

int cantidadDeAlumnosMayores(char nombreDelArchivo[], int edad){
    stAlumno alumno;
    int i=0;
    FILE* archi=fopen(nombreDelArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            if(alumno.edad>edad){
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

void mostrarRangoEdadNombres(char nombreDelArchivo[], int min, int max){
    stAlumno alumno;
    FILE* archi=fopen(nombreDelArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            if(alumno.edad>min && alumno.edad<max){
                printf("\n %s", alumno.nombreYApellido);
            }
        }
        fclose(archi);
    }
}

void alumnoMayor(char nombreDelArchivo[]){
    stAlumno alumno;
    stAlumno aux;
    FILE* archi=fopen(nombreDelArchivo,"rb");
    //fseek(archi,1,SEEK_SET);
    fread(&alumno,sizeof(stAlumno),1,archi);
    aux=alumno;
    printf("edad %d",aux.edad);
    system("pause");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            if(aux.edad<alumno.edad){
                aux=alumno;
                printf("edad %d",aux.edad);
    system("pause");
            }
        }
        fclose(archi);
    }
    mostrarLegajo(aux);
}
