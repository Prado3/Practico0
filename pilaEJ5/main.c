#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//5. Cargar desde el teclado la pila DADA.
//Invertir la pila de manera que DADA contenga los elementos cargados originalmente en ella, pero en orden inverso.




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


    while(!pilavacia(&dada)){
        apilar(&aux1, desapilar(&dada));
    }

    while(!pilavacia(&aux1)){
        apilar(&aux2, desapilar(&aux1));
    }

    while(!pilavacia(&aux2)){
        apilar(&dada, desapilar(&aux2));
    }

    mostrar(&dada);

    return 0;
}
