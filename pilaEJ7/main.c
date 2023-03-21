#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//7. Pasar el último elemento (base) de la pila DADA a su primera posición (tope),
//dejando los restantes elementos en el mismo orden.



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

   apilar(&aux2, desapilar(&aux1));

   while(!pilavacia(&aux1)){
        apilar(&dada, desapilar(&aux1));
   }

   apilar(&dada, desapilar(&aux2));

   mostrar(&dada);

    return 0;
}
