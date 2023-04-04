#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

//1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.

void cargarPila(Pila *p);

int main()
{
    Pila elemento;
    inicpila(&elemento);

    cargarPila(&elemento);
    mostrar(&elemento);

    return 0;
}

void cargarPila(Pila *p){
    char op;
    int nro;

    do{
        printf("\n Ingrese un elemento: ");
        scanf("%d", &nro);
        apilar(p, nro);

        printf("\n Presione ESC para salir");
        op=getch();
    }while(op!=ESC);
}

