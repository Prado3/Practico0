#include <stdio.h>
#include <stdlib.h>

//Leer 15 números negativos y convertirlos en positivos e imprimir dichos números.

int main()
{
    int numero, positivo;

    for(int i = 0; i < 15; i++){
        printf("\n Ingrese un numero negativo: ");
        scanf("%d", &numero);

        positivo = -1 * numero;

        printf("\n Su numero en positivo seria: %d", positivo);

    }
    return 0;
}
