#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//3. Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos al valor 8.


int main()
{
    Pila dada, distintos, aux;

    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&aux);

    for(int i = 0; i < 10; i++){
        leer(&dada);

        if(tope(&dada)!=8){
            apilar(&distintos, desapilar(&dada));
        }else{
            apilar(&dada, desapilar(&dada));

        }
    }

    mostrar(&dada);
    mostrar(&distintos);


    return 0;
}
