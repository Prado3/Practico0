#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//11. Suponiendo la existencia de una pila MODELO que no esté vacía,
//eliminar de la pila DADA todos los elementos que sean iguales al tope de la pila MODELO.



int main()
{
    Pila modelo, dada, aux1, aux2;

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    for(int i = 0; i < 10; i++){
            apilar(&dada, i);
    }

    for(int i = 0; i < 10; i++){
            apilar(&modelo, i);
    }

    while(!pilavacia(&modelo) && !pilavacia(&dada)){
        if(tope(&modelo) == tope(&dada)){
            apilar(&aux1, desapilar(&dada));

        }else{
            apilar(&aux2, desapilar(&dada));
        }
    }

    while(!pilavacia(&aux2)){
        apilar(&dada, desapilar(&aux2));
    }

    mostrar(&aux1);
    mostrar(&dada);

    return 0;
}
