#include <stdio.h>
#include <stdlib.h>

//Calcular e imprimir la tabla de multiplicar de un número cualquiera.
//Imprimir el multiplicando, el multiplicador y el producto.


int main()

{
    int numero;

    printf("\n Ingrese el numero a consultar: ");
    scanf("%d", &numero);

    for(int i = 1; i <11; i++){
        printf("\n %d * %d = %d", i, numero, i*numero);
    }

    return 0;
}
