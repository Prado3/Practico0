#include <stdio.h>
#include <stdlib.h>

//Leer tres números diferentes e imprimir el número mayor de los tres.

int main()
{
    int nr1;
    int nr2;
    int nr3;

    printf("\n Ingrese numero: ");
    scanf("%d", &nr1);

    printf("\n Ingrese numero: ");
    scanf("%d", &nr2);

    printf("\n Ingrese numero: ");
    scanf("%d", &nr3);

    if(nr1> nr2 & nr1 > nr3){
        printf("%d", nr1);
    }else{
        if(nr2>nr3){
            printf("%d", nr2);
        }else{
            printf("%d", nr3);
        }
    }


    return 0;
}
