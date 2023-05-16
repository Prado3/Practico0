#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define ESC 27
#define FIL 20
#define COL 30

int cargaDatos(int l[20], char n[][30], int e[20], int v, int dim);
void muestraArreglo(int l[],char n[][30],int e[], int v);
int encontrarAlumno(char n[][30], int v, char dato[][30]);
void imprimirLegajo(int l[], char n[][30], int e[], int v, char dato[][30]);
void ordenarInsercion(int l[], char n[][30], int e[], int v);

int main()
{
    int legajos[FIL];
    char nombres[FIL][COL];
    char dato[FIL][COL];
    int anios[FIL];
    int validos=0;

    validos=cargaDatos(legajos,nombres,anios,validos,FIL);
    muestraArreglo(legajos,nombres,anios,validos);
    printf("\n Ingrese el alumno a bucar: ");
    fflush(stdin);
    gets(dato[0]);
    imprimirLegajo(legajos,nombres,anios,validos,dato);
    ordenarInsercion(legajos,nombres,anios,validos);
    muestraArreglo(legajos,nombres,anios,validos);


    return 0;
}

int cargaDatos(int l[], char n[][30], int e[], int v, int dim){
    char op;

    while(v<dim && op!=ESC){
        system("cls");
        printf("\n Ingrese el nombre: ");
        fflush(stdin);
        gets(n[v]);

        printf("\n Ingrese la edad del alumno: ");
        scanf("%d", &e[v]);

        l[v]=v;

        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();

        v++;
    }

    return v;
}

void muestraArreglo(int l[],char n[][30],int e[], int v){
    for(int i=0;i<v;i++){
        printf("\n Legajo: %d ", l[i]);
        printf(" - Nombre: %s ", n[i]);
        printf(" - Edad: %d ", e[i]);
    }
}

int encontrarAlumno(char n[][30], int v, char dato[][30]){
    int i=0;
    while(i<v){
        if(strcmp(dato[0],n[i])==0){
            return i;
        }
        i++;
    }

    return -1;
}

void imprimirLegajo(int l[], char n[][30], int e[], int v, char dato[][30]){
    int posAlumno=encontrarAlumno(n,v,dato);
    printf("\n El dato es: %s", dato[0]);
    if(posAlumno>=0){
        system("cls");
        printf("\n El alumno a buscar es:");
        printf("\n Legajo: %d ", l[posAlumno]);
        printf(" - Nombre: %s ", n[posAlumno]);
        printf(" - Edad: %d ", e[posAlumno]);
    }else{
        printf("\n No se encuentra el alumno a buscar");
    }
}

void ordenarInsercion(int l[], char n[][30], int e[], int v){
    int j=0;
    char aux[20];
    int auxE=0;
    int auxL=0;

    for(int i=0;i<v-1;i++){
        for(j=0;j<v-1;j++){
            if(strcmp(n[j],n[j+i])>0){
                strcpy(aux,n[j]);
                strcpy(n[j],n[j+1]);
                strcpy(n[j+1],aux);

                auxE=e[j];
                e[j]=e[j+1];
                e[j+1]=auxE;

                auxL=l[j];
                l[j]=l[j+1];
                l[j+1]=auxL;
            }
        }
    }
}
