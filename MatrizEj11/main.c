#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define STRFIL 30
#define STRCOL 30
#define ESC 27

int cargarArregloNombres(char n[][30],int dim);
void mostrarArregloNombres(char n[][30], int validos);
void ordenarArregloPorInsersion(char n[][30], int validos);

int main()
{
    char nombres[STRFIL][STRCOL];
    int validosNombre=0;

    validosNombre = cargarArregloNombres(nombres,STRFIL);
    printf("\n %d", validosNombre);

    mostrarArregloNombres(nombres,validosNombre);
    ordenarArregloPorInsersion(nombres,validosNombre);
    mostrarArregloNombres(nombres,validosNombre);

    return 0;
}

int cargarArregloNombres(char n[][30],int dim){
    int i =0;
    char op;

    while(i<dim && op!=ESC){
        system("cls");
        printf("\n Ingrese un nombre: ");
        gets(n[i]);
        i++;
        fflush(stdin);

        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }

    return i;
}

void mostrarArregloNombres(char n[][30], int validos){
    for(int i =0;i<validos;i++){
        printf("\n %s", n[i]);
    }
}

void ordenarArregloPorInsersion(char n[][30], int validos){
    char aux[20];
    int i = 0;
    int j = 0;
    int comp =0;

    for(i=0;i<validos;i++){
        for(j=0;j<validos;j++){
            comp=strcmp(n[j],n[j+1]);
            if(comp>0){
                strcpy(aux,n[j]);
                strcpy(n[j],n[j+1]);
                strcpy(n[j+1],aux);
            }
        }
    }
}
