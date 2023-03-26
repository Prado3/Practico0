#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//14. Determinar si la cantidad de elementos de la pila DADA es par.
//Si es par, pasar el elemento del tope de la pila AUX a la pila PAR y
//si es impar pasar el tope a la pila IMPAR. (NO contar los elementos)

int main()
{
    Pila dada, aux, aux1, aux2, par, impar;
    inicpila(&dada);
    inicpila(&aux);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&par);
    inicpila(&impar);



    for(int i = 0; i < 10; i++)
    {
        apilar(&dada, rand()%20);
    }

    for(int i = 0; i < 12; i++)
    {
        apilar(&aux, rand()%20);
    }

   // mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&aux1, desapilar(&dada));
        if(!pilavacia(&dada)){
            apilar(&aux2,desapilar( &dada));
        }
    }
    //mostrar(&aux1);
    //mostrar(&aux2);
    //mostrar(&dada);


    while(!pilavacia(&aux1) && !pilavacia(&aux2)){
        apilar(&dada, desapilar(&aux1));
        apilar(&dada, desapilar(&aux2));
    }
    //mostrar(&aux1);
    //mostrar(&aux2);

    if(pilavacia(&aux1) && pilavacia(&aux2)){
        printf("\n La pila dada tiene una cantidad de elementos pares");
    }else{
        printf("\n La pila dada tiene una cantidad de elementos impares");

    }

    while(!pilavacia(&aux)){
    //int tope;
    //apilar(&aux, tope);
        if(tope(&aux) % 2 == 0){
            apilar(&par, desapilar(&aux));
        }else{
            apilar(&impar, desapilar(&aux));

        }
    }
    mostrar(&par);
    mostrar(&impar);


    return 0;
}
