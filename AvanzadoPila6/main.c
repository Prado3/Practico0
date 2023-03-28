#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//6.Usando lo resuelto en el ejercicio 4,
//pasar los elementos de una pila a otra de forma tal que la segunda pila quede ordenada de mayor (tope) a menor (base).
//Esto se llama método de ordenación por selección.



int main()
{
    Pila dada, aux1, menor, ordenada;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&menor);
    inicpila(&ordenada);

    int num;
    char opcion;



    do{
        printf("\n Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&dada, num);

        printf("\n Presione ESC para salir ");
        opcion=getch();


    }while(opcion!=ESC);

    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(!pilavacia(&dada)){
            apilar(&menor, desapilar(&dada));
            while(!pilavacia(&dada)){
                if(tope(&dada) < tope(&menor)){
                    apilar(&menor, desapilar(&dada));
                }else{
                    apilar(&aux1, desapilar(&dada));
                }
            }
            apilar(&ordenada, desapilar(&menor));
            while(!pilavacia(&menor)){
                apilar(&aux1, desapilar(&menor));
            }
            while(!pilavacia(&aux1)){
                apilar(&dada, desapilar(&aux1));
            }
        }
    }


    mostrar(&ordenada);


    return 0;
}
