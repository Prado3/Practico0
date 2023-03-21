#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int main()
{
    Pila pilita, aux, menores, mayores;

    inicpila(&pilita);
    inicpila(&aux);
    inicpila(&menores);
    inicpila(&mayores);

    for(int i = 0; i < 40; i++){
        apilar(&pilita, rand()%100);
    }

    mostrar(&pilita);

    //while(!pilavacia(&pilita)){
    //    apilar(&aux, desapilar(&pilita));
    //}
    //mostrar(&aux);

    while(!pilavacia(&pilita)){
        if(tope(&pilita)> 50){
            apilar(&mayores, desapilar(&pilita));
        }else{
            apilar(&menores, desapilar(&pilita));
        }

    }
    mostrar(&menores);
    mostrar(&mayores);


    return 0;
}
