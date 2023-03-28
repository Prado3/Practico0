#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//5.Insertar un elemento en una pila ordenada de menor (tope) a mayor (base) de forma tal
//que se conserve el orden. (sin variables enteras, solo pilas)


int main()
{
    Pila ordenada, menor, mayor, aux1, elemento;
    inicpila(&ordenada);
    inicpila(&menor);
    inicpila(&mayor);
    inicpila(&aux1);
    inicpila(&elemento);

    int num;

    for(int i = 1; i < 11; i++){
        apilar(&aux1, i);
    }

    while(!pilavacia(&aux1)){
        apilar(&ordenada, desapilar(&aux1));
    }

    mostrar(&ordenada);

    printf("\n Ingrese un numero: ");
    scanf("%d", &num);
    apilar(&elemento, num);

    mostrar(&elemento);

    while(!pilavacia(&elemento)){
        if(tope(&ordenada) > tope(&elemento)){
            apilar(&ordenada, desapilar(&elemento));
        }else{
            apilar(&aux1, desapilar(&ordenada));
        }
    }

    while(!pilavacia(&aux1)){
        apilar(&ordenada, desapilar(&aux1));
    }

    mostrar(&ordenada);

    return 0;
}
