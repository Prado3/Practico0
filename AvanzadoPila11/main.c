#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//11. Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2)
//dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).


int main()
{
    srand(time(NULL));
    Pila ordenada1, ordenada2, ordenadafinal, aux1, aux2, menor;

    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&ordenadafinal);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&menor);

    for(int i = 0; i < 10; i++){
        apilar(&ordenada1, rand()%20);
    }

    for(int i = 0; i < 10; i++){
        apilar(&ordenada2, rand()%20);
    }

    mostrar(&ordenada1);
    mostrar(&ordenada2);

    while(!pilavacia(&ordenada2)){
        apilar(&ordenada1, desapilar(&ordenada2));
    }

    mostrar(&ordenada1);

    while(!pilavacia(&ordenada1)){
        if(!pilavacia(&ordenada1)){
            apilar(&menor, desapilar(&ordenada1));
            while(!pilavacia(&ordenada1)){
                if(tope(&ordenada1) < tope(&menor)){
                    apilar(&menor, desapilar(&ordenada1));
                }else{
                    apilar(&aux1, desapilar(&ordenada1));
                }
            }
            apilar(&ordenadafinal, desapilar(&menor));
            while(!pilavacia(&menor)){
                apilar(&aux1, desapilar(&menor));
            }
            while(!pilavacia(&aux1)){
                apilar(&ordenada1, desapilar(&aux1));
            }
        }
    }

    mostrar(&ordenadafinal);

    return 0;
}
