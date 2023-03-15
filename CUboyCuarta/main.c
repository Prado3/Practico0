#include <stdio.h>
#include <stdlib.h>

//Leer 10 números y obtener su cubo y su cuarta.

int main()
{
    int numero, cubo, cuarta, cuboPow, cuartaPow;
    for(int i = 0; i <10; i++){
        printf("\n Ingrese el numero %d: ", i+1);
        scanf("%d", &numero);

        cubo = numero * numero * numero;
        cuboPow = pow(numero, 3);
        cuarta = cubo * numero;
        cuartaPow = pow(numero, 4);

        printf("\n El cubo del numero %d es %d - %d", numero, cubo, cuboPow);
        printf("\n La cuarta del numero %d es %d - %d", numero, cuarta, cuartaPow);
    }
    return 0;
}
