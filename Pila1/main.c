#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//1. Cargar desde el teclado una pila DADA con 5 elementos.
//Pasar los tres primeros elementos que se encuentren en el tope a la pila AUX1
//y los restantes a la pila AUX2, ambas pilas inicializadas.

int main()
{
    Pila dada, aux1, aux2;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    for(int i = 0; i < 5; i++){
        leer(&dada);
    }

    for(int i = 0; i < 5;i++ ){
        if(i < 3){
            apilar(&aux1, desapilar(&dada));
        }else{
            apilar(&aux2, desapilar(&dada));
        }
    }

    mostrar(&aux1);
    mostrar(&aux2);
    return 0;
}
