#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//8. Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido y dejar el resto en el mismo orden.


int main()
{
    srand(time(NULL));
    Pila dada, elemento, aux1, eliminado;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&eliminado);
    inicpila(&elemento);

    int num;

    for(int i = 0; i < 10; i++){
        apilar(&dada, rand()%10);
    }

    printf("\n Ingrese un elemento: ");
    scanf("%d", &num);
    apilar(&elemento, num);

    mostrar(&dada);
    while(!pilavacia(&dada)){
        if(tope(&dada) == tope(&elemento)){
            apilar(&eliminado, desapilar(&dada));
        }else{
            apilar(&aux1, desapilar(&dada));
        }
    }
    while(!pilavacia(&aux1)){
        apilar(&dada, desapilar(&aux1));
    }

    mostrar(&eliminado);
    mostrar(&dada);


    return 0;
}
