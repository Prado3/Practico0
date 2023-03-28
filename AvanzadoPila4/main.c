#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27


//4. Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables enteras, solo pilas)



int main()
{
    Pila dada, aux1, menor;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&menor);

    int num;
    char opcion;



    do{
        printf("\n Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&dada, num);

        printf("\n Presione ESC para salir ");
        opcion=getch();


    }while(opcion!=ESC);

    if(!pilavacia(&dada)){
        apilar(&menor, desapilar(&dada));
        while(!pilavacia(&dada)){
            if(tope(&dada) < tope(&menor)){
                apilar(&menor, desapilar(&dada));
            }else{
                apilar(&aux1, desapilar(&dada));
            }

       }
    }
    mostrar(&menor);

    //mostrar(tope(&menor));



    return 0;
}
