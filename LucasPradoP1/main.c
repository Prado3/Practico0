#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#include <time.h>

#define DIM_NOTAS 100
#define ESC 27

int cargaNotasInt(int array[],int validos,int dim);
int cargarArregloRandom(int array[], int dim, int cantidad);
void muestraArreglo(int array[], int validos);
int buscaDatoArregloInt(int array[],int validos,int dato);
void ordenarArregloSeleccion(int array[], int validos);


int main()
{
    srand(time(NULL));
    int notas[DIM_NOTAS];
    int vNotas = 0;

    //vNotas = cargarArregloRandom(notas,DIM_NOTAS,3);
    vNotas = cargaNotasInt(notas,vNotas,DIM_NOTAS);
    muestraArreglo(notas,vNotas);
    ordenarArregloSeleccion(notas,vNotas);
    muestraArreglo(notas,vNotas);
   // int encontrado = buscaDatoArregloInt(notas,vNotas, 10);

  //  if(!encontrado){
  //      printf("\n No se encontro el dato");
  //  }else{
  //      printf("\n Se encontro el dato");
  //  }
    return 0;
}

int buscaDatoArregloInt(int array[],int validos,int dato){
    int i = 0;
    int flag = 0;
    while(i<validos && flag==0){
        if(array[i]==dato){
            flag=1;
        }
        i++;
    }
    return flag;
}

void muestraArreglo(int array[], int validos){
    for(int i = 0;i<validos;i++){
        if(i%20==0){
            printf("\n");
        }
        printf("\n %3d", array[i]);
    }
}

int cargarArregloRandom(int array[], int dim, int cantidad){
    int i=0;
    if(cantidad<=dim){
        for(i = 0; i< cantidad;i++){
            array[i]=rand()%11;
        }
    }
    return i;
}

int cargaNotasInt(int array[],int validos,int dim){
    char op=0;
    int i = validos;

    while(i<dim && op!=ESC){
       do{
            printf("\n Ingrese una nota (1-10): ");
            scanf("%d", &array[i]);
            if(array[i]<1 || array[i]>10){
                printf("\n La nota no es valida");
                getch();
                system("cls");
            }
       }while(array[i]<1 || array[i]>10);
       i++;
       printf("\n ESC para salir..");
       op=getch();
       system("cls");
    }
    return i;
}

void ordenarArregloSeleccion(int array[], int validos){
    int menor;
    int recorrer = 0;

    menor = array[recorrer];
    while(validos>recorrer){
        int i = 0;
        while(i<validos){
            if(array[i]<menor){
                menor=array[i];
                i++;
            }else{
                i++;
            }
        }
        array[recorrer]=menor;
        recorrer++;
    }
}

