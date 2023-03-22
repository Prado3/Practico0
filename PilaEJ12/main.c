#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//12. Suponiendo la existencia de una pila MODELO (vacía o no),
//eliminar de la pila DADA todos los elementos que existan en MODELO.




int main()
{
    Pila modelo, dada, aux1, aux2, aux3;
    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&aux3);

    for(int i = 0; i < 10; i++)
    {
        apilar(&dada, rand()%20);
    }

    for(int i = 0; i < 10; i++)
    {
        apilar(&modelo, rand()%20);
    }

    mostrar(&modelo);
    mostrar(&dada);


    while(!pilavacia(&modelo))
    {
        while(!pilavacia(&dada))
        {
            if(tope(&modelo) == tope(&dada))
            {
                apilar(&aux3, desapilar(&dada));
            }
            else
            {
                apilar(&aux1, desapilar(&dada));
            }
        }
        while(!pilavacia(&aux1)){
            apilar(&dada, desapilar(&aux1));

        }

        apilar(&aux2, desapilar(&modelo));

    }
    while(!pilavacia(&aux2)){
        apilar(&modelo, desapilar(&aux2));

    }


    mostrar(&modelo);
    mostrar(&dada);
    mostrar(&aux3);

    return 0;
}
