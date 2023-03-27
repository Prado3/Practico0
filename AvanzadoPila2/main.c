#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27


//2.Contar los elementos de una pila (usar variables enteras)


int main()
{
    Pila dada, aux1;

    inicpila(&dada);
    inicpila(&aux1);

    int num;
    int suma = 0;
    char opcion;

    do{
        printf("\n Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&dada, num);

        printf("\n Presione ESC para salir ");
        opcion=getch();


    }while(opcion!=ESC);

    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&aux1, desapilar(&dada));
        suma = suma + 1;
    }

    printf("\n La cantidad de elementos es: %d",suma);
    mostrar(&aux1);


    return 0;
}
