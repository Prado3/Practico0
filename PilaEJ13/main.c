#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//13. Suponiendo la existencia de una pila LÍMITE,
//pasar los elementos de la pila DADA que sean mayores o iguales que el tope de LIMITE a la pila MAYORES,
//y los elementos que sean menores a la pila MENORES.





int main()
{
    Pila limite, dada, menores, mayores, aux1;
    inicpila(&limite);
    inicpila(&dada);
    inicpila(&menores);
    inicpila(&mayores);
    inicpila(&aux1);

    for(int i = 0; i < 10; i++)
    {
        apilar(&limite, i);
    }

    for(int i = 0; i < 10; i++)
    {
        apilar(&dada, rand()%20);
    }


    mostrar(&limite);
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(tope(&limite) <= tope(&dada)){
            apilar(&mayores, desapilar(&dada));
        }else{
            apilar(&menores, desapilar(&dada));
        }
    }

    mostrar(&menores);
    mostrar(&mayores);

    return 0;
}
