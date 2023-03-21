#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//8. Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.




int main()
{
   Pila mazo, jugador1, jugador2;

   inicpila(&mazo);
   inicpila(&jugador1);
   inicpila(&jugador2);

   for(int i = 0; i < 40; i++){
        apilar(&mazo, rand()%40);
   }
   mostrar(&mazo);

   while(!pilavacia(&mazo)){
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
   }

   mostrar(&jugador1);
   mostrar(&jugador2);

    return 0;
}
