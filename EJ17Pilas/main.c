#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//14. Determinar si la cantidad de elementos de la pila DADA es par.
//Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y
//si es impar pasar el tope a la pila IMPAR. (NO contar los elementos)

int main()
{
    Pila Origen, Distinto, aux;
   inicpila(&Origen);
   inicpila(&Distinto);
   inicpila(&aux);

   int num;
   char opcion = 's';

   while(opcion == 's'){

   printf("\n Ingrese un numero: (ingrese 0 para salir)");
   scanf("%d", &num);
   apilar(&Origen, num);

   printf("\n Desea continuar? (s / n)");
    scanf(" %c", &opcion);
   }

   mostrar(&Origen);

   while(!pilavacia(&Origen)){
      if (tope(&Origen) >= 5) {
         apilar (&Distinto, desapilar(&Origen));
      }else{
            apilar (&aux, desapilar(&Origen));

      }
   }
   mostrar(&Distinto);


    return 0;
}
