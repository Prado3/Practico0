#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//9. Verificar si una pila DADA es capicúa.



int main()
{
    Pila dada, aux1, aux2, capicua;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&capicua);

    int num;
    int bandera = 0;
    char op;

    do{
        printf("\n Ingrese un numero: ");
        scanf("%d", &num);
        apilar(&dada, num);

        printf("\n Presione ESC para salir");
        op=getch();
    }while(op!=ESC);

    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&capicua, tope(&dada));
        apilar(&aux1, desapilar(&dada));
    }
    mostrar(&capicua);
    while(!pilavacia(&aux1)){
        apilar(&dada, desapilar(&aux1));
    }

    while(!pilavacia(&dada) && !pilavacia(&capicua) && bandera!=1){
        if(tope(&dada) == tope(&capicua)){
            apilar(&aux1, desapilar(&dada));
            apilar(&aux1, desapilar(&capicua));
        }else{
            printf("\n No son capicua");
            bandera = 1;
        }
    }

    if(pilavacia(&dada) && pilavacia(&capicua)){
        printf("\n Son capicua");
    }

    return 0;
}
