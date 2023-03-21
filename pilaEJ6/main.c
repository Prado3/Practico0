#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//6. Pasar el primer elemento (tope) de la pila DADA a su última posición (base),
// dejando los restantes elementos en el mismo orden.


int main()
{
    Pila dada, aux1, aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    for(int i = 0; i < 5; i++){
        leer(&dada);
    }

    mostrar(&dada);

    apilar(&aux1, desapilar(&dada));

    while(!pilavacia(&dada)){
        apilar(&aux2, desapilar(&dada));
    }

    apilar(&dada, desapilar(&aux1));

    while(!pilavacia(&aux2)){
        apilar(&dada, desapilar(&aux2));
    }

    mostrar(&dada);


    return 0;
}
