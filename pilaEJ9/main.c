#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//9. Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.




int main()
{
   Pila a, b, aux;

   inicpila(&a);
   inicpila(&b);
   inicpila(&aux);

   for(int i = 0; i < 5; i++){
    apilar(&a, rand()%10);
   }

   for(int i = 0; i < 7 ;i++){
    apilar(&b, rand()%10);
   }

   while(!pilavacia(&a) && !pilavacia(&b)){
        apilar(&aux, desapilar(&a));
        apilar(&aux, desapilar(&b));
   }
   printf("\n Pila a: ");
   mostrar(&a);
   printf("\n Pila b: ");
   mostrar(&b);
    return 0;
}
