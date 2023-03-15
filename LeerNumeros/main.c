#include <stdio.h>
#include <stdlib.h>

//Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente

int main()
{
    int nr1;
    int nr2;

    printf("\n Ingrese numero: ");
    scanf("%d", &nr1);

    printf("\n Ingrese numero: ");
    scanf("%d", &nr2);

    if(nr1 > nr2){
        printf("%d %d", nr2, nr1);
    }else{
        printf("%d %d", nr1, nr2);
    }




    return 0;
}
