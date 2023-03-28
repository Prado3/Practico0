#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27


//3. Calcular el promedio de los valores de una pila (usar variables)


int main()
{
    Pila dada, aux1;

    inicpila(&dada);
    inicpila(&aux1);

    int num;
    float suma = 0;
    float cont = 0;
    float promedio;
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

        suma = suma + tope(&dada);
        cont = cont + 1;
        apilar(&aux1, desapilar(&dada));
    }
    promedio = suma / cont;

    printf("\n El promedio es: %.2f", promedio);
    mostrar(&aux1);


    return 0;
}
