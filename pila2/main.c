#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//2. Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO.
//Pasar todos los elementos de la pila ORIGEN a la pila DESTINO.


int main()
{
    Pila origen, destino;

    inicpila(&origen);
    inicpila(&destino);

    for(int i = 0; i < 5; i++){
        leer(&origen);
    }

    mostrar(&origen);
    mostrar(&destino);

    while(!pilavacia(&origen)){
        apilar(&destino, desapilar(&origen));
    }

    mostrar(&origen);
    mostrar(&destino);

    return 0;
}
