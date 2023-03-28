#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//7. Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.




int main()
{
    srand(time(NULL));
    Pila dada, elemento, aux1;

    inicpila(&dada);
    inicpila(&elemento);
    inicpila(&aux1);

    int num;

    for(int i = 0; i < 10; i++){
        apilar(&dada, rand()%20);
    }

    mostrar(&dada);

    printf("\n Ingrese un elemento: ");
    scanf("%d", &num);
    apilar(&elemento, num);

    while(!pilavacia(&dada) && !pilavacia(&elemento)){
            if(tope(&dada) == tope(&elemento)){
                printf("\n El elemento esta dentro de la pila");
                apilar(&aux1, desapilar(&elemento));
                }else{
                apilar(&aux1, desapilar(&dada));
            }
        }


    if(pilavacia(&dada)){
        printf("\n El elemento no se encuentra en la pila");
    }





    return 0;
}
