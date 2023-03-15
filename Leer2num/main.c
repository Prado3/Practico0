#include <stdio.h>
#include <stdlib.h>

//Leer 2 números; si son iguales que los multiplique,
//si el primero es mayor que el segundo que los reste y si no que los sume

int main()
{
    int nr1;
    int nr2;
    int resultado;

    printf("\n Ingrese numero: ");
    scanf("%d", &nr1);

    printf("\n Ingrese numero: ");
    scanf("%d", &nr2);

    if(nr1 == nr2){
        resultado = nr1 * nr2;
        printf("%d", resultado);
    }else{
        if(nr1 < nr2){
            resultado = nr1 + nr2;
            printf("%d", resultado);
        }else{
            resultado = nr1 - nr2;
            printf("%d", resultado);
        }
    }

    return 0;
}
