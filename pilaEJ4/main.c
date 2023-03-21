#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//4. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
//Pasar los elementos de la pila ORIGEN a la pila DESTINO, pero dejándolos en el mismo orden.



int main()
{
    Pila origen, destino, aux;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&aux);

    for(int i = 0; i < 5; i++){
        leer(&origen);
    }
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&aux, desapilar(&origen));
    }
    mostrar(&aux);

    while(!pilavacia(&aux)){
        apilar(&destino, desapilar(&aux));
    }

   mostrar(&destino);

    return 0;
}
