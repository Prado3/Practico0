#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27
#define DIM 20

int cargarPilas(Pila* A, Pila* B, Pila c);
void ingresarDato(Pila* dato);
int contarDatoElegidoEnC(Pila C, Pila* dato);
int pasarPilaArreglo(Pila* C,int array[], int dimension);
void recorrerArreglo(int array[], int validos);
int encuentraMayorArreglo(int array[],int validos);

int main()
{
    Pila pilaA, pilaB, pilaC;
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&pilaC);

    cargarPilas(&pilaA,&pilaB,pilaC);

    return 0;
}

int cargarPilas(Pila* A, Pila* B, Pila C){
    char op;
    int num;
    int cantidad;
    int datoI;
    Pila dato;
    inicpila(&dato);
    int validos = 0;
    int arreglo[DIM];
    int mayor;

    do{
        printf("\n Ingrese los datos: ");
        scanf("%d",&num);

        if(num%3==0 && num%2==0){
            apilar(B, num);
        }else{
            if(num%3==0){
                apilar(A,num);
            }else{
                apilar(&C, num);
            }
        }

        printf("\n Ingrese ESC para dejar de cargar datos...");
        op=getch();
    }while(op!=ESC);

    mostrar(A);
    mostrar(B);
    mostrar(&C);

    ingresarDato(&dato);
    mostrar(&dato);
    datoI = tope(&dato);
    cantidad = contarDatoElegidoEnC(C, &dato);

    printf("\n El dato ingresado por el usuario: %d, se encuentra %d veces en la Pila C", datoI, cantidad);

    validos = pasarPilaArreglo(&C,arreglo,DIM);
    printf("\n Los validos son %d", validos);
    mostrar(&C);
    recorrerArreglo(arreglo,validos);

    mayor = encuentraMayorArreglo(arreglo, validos);
    printf("\n El mayor es %d", mayor);

    return cantidad;
}

void ingresarDato(Pila* dato){
    int num;

    printf("\n Ingrese el dato para comparar con la Pila C: ");
    scanf("%d", &num);
    apilar(dato,num);
}

int contarDatoElegidoEnC(Pila C, Pila* dato){
    int cantidad = 0;

    while(!pilavacia(&C)){
        if(tope(dato)==tope(&C)){
            cantidad++;
        }
        desapilar(&C);
    }

    return cantidad;
}

int pasarPilaArreglo(Pila* C,int array[], int dimension){
    int validos = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(C) && validos<dimension){
        if(tope(C)< 51 && tope(C)>4){
            array[validos] = tope(C);
            desapilar(C);
            validos++;
        }else{
            apilar(&aux, desapilar(C));
        }
    }

    while(!pilavacia(&aux)){
        apilar(C, desapilar(&aux));
    }

    return validos;
}

void recorrerArreglo(int array[], int validos){
    for(int i =0; i<validos;i++){
        printf("\n %d", array[i]);
    }
}

int encuentraMayorArreglo(int array[],int validos){
    int i = validos-1;
    int mayor;

    if(i>=0){
        mayor = array[i];
        while(i>=0){
            if(array[i]>mayor){
                mayor = array[i];
            }
            i--;
            i--;
        }
    }
    return mayor;
}





