#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo),
//realizar un programa que calcule en la pila C la operación de unión.
//A : base 1 2 3  tope
//B: base 2 3 5 7 tope
//Pila AUB = base 3 2 1 7 5 tope

int main()
{
    Pila a, b, c, aux1, iguales;

    inicpila(&a);
    inicpila(&b);
    inicpila(&c);
    inicpila(&aux1);
    inicpila(&iguales);

    apilar(&a, 1);
    apilar(&a, 2);
    apilar(&a, 3);
    apilar(&b, 2);
    apilar(&b, 3);
    apilar(&b, 5);
    apilar(&b, 7);

    mostrar(&a);
    mostrar(&b);

    while(!pilavacia(&a)){
        while(!pilavacia(&b)){
            if(tope(&a) == tope(&b)){
                apilar(&iguales, desapilar(&b));
            }else{
                apilar(&aux1, desapilar(&b));
            }
        }
        while(!pilavacia(&aux1)){
            apilar(&b, desapilar(&aux1));
        }
        apilar(&c, desapilar(&a));
    }
    while(!pilavacia(&b)){
        apilar(&c, desapilar(&b));
    }


    mostrar(&c);
    return 0;
}
