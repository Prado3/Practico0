#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//10. Cargar las pilas A y B, y luego compararlas, evaluando si son completamente iguales
//(en cantidad de elementos, valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.

int main()
{
    Pila a, b, aux1, aux2;
    inicpila(&a);
    inicpila(&b);
    inicpila(&aux1);
    inicpila(&aux2);

    for(int i = 0; i < 14; i++){
        apilar(&a, rand()%10);
    }

    for(int i = 0; i < 11; i++){
        apilar(&b, rand()%10);
    }

    while(!pilavacia(&a) && !pilavacia(&b)){
        apilar(&aux1, desapilar(&a));
        apilar(&aux2, desapilar(&b));
    }

    if(pilavacia(&a) && pilavacia(&b)){
        printf("\n ambas pilas tienen la misma cantidad de elemntos");
    }else{
        printf("\n tienen diferente cantidad de elementos");
    }

    while(!pilavacia(&aux1) && !pilavacia(&aux2)){
        if(tope(&aux1) == tope(&aux2)){
            printf("\n Tienen el mismo orden y valor a: %d y b: %d", tope(&aux1), tope(&aux2));
            apilar(&a, desapilar(&aux1));
            apilar(&b, desapilar(&aux2));

        }else{
            printf("\n Tienen diferente orden y valor a: %d y b: %d", tope(&aux1), tope(&aux2));
            apilar(&a, desapilar(&aux1));
            apilar(&b, desapilar(&aux2));

        }
    }


    return 0;
}
