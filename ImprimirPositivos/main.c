#include <stdio.h>
#include <stdlib.h>

//Leer 10 n�meros e imprimir solamente los n�meros positivos

int main()
{
    int numero;

    for(int i = 0; i < 10; i++){
        printf("\n Ingrese un numero: ");
        scanf("%d", &numero);

        if(numero > 0){
            printf("\n El numero %d es positivo", numero);
        }else{
            printf("\n El numero %d es negativo", numero);
        }
    }
    return 0;
}
