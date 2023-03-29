#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado en la pila ORIGEN.
//Para este ejercicio usar lo aprendido para el ejercicio 5.


int main()
{
    Pila origen, aux1, aux2, menor;

    inicpila(&origen);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&menor);

    int num;
    char op;

    do{
        printf("\n Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&origen, num);

        printf("\n Precione ESC para salir");
        op=getch();
    }while(op!=ESC);

    mostrar(&origen);

    while(!pilavacia(&origen)){
        if(!pilavacia(&origen)){
            apilar(&menor, desapilar(&origen));
            while(!pilavacia(&origen)){
                if(tope(&origen) < tope(&menor)){
                    apilar(&menor, desapilar(&origen));
                }else{
                    apilar(&aux1, desapilar(&origen));
                }
            }
            apilar(&aux2, desapilar(&menor));
            while(!pilavacia(&menor)){
                apilar(&aux1, desapilar(&menor));
            }
            while(!pilavacia(&aux1)){
                apilar(&origen, desapilar(&aux1));
            }
        }
    }

    while(!pilavacia(&aux2)){
        apilar(&aux1, desapilar(&aux2));
    }

    while(!pilavacia(&aux1)){
        apilar(&origen, desapilar(&aux1));
    }

    mostrar(&origen);





    return 0;
}
