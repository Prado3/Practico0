#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

int main()
{
    Pila temperaturas, aux;
    inicpila(&temperaturas);
    inicpila(&aux);

    int temp;
    char op;

    do{
        printf("\n Ingrese una temperatura: ");
        scanf("%d", &temp);
        apilar(&temperaturas, temp);

        printf("\n Presione ESC para salir ");
        op=getch();


    }while(op!=ESC);

    mostrar(&temperaturas);

    return 0;
}
