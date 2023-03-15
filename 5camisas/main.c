#include <stdio.h>
#include <stdlib.h>

//Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
//Si se compran tres camisas o más se aplica un descuento del 20% sobre el total de la compra
//y si son menos de tres camisas un descuento del 10%

int main()
{
    int total, cantidad;
    float precioFinal;

    printf("Ingrese la cantidad de camisas a comprar: ");
    scanf("%d", &cantidad);

     printf("Ingrese el total de la compra: ");
    scanf("%d", &total);

    if(cantidad > 2){
        precioFinal = total - (total *0.20);
        printf("\n Como supera las 3 camisas, se le aplica un descuento mayor, su precio final es de: $ %.2f", precioFinal);
    }else{
        precioFinal = total - (total *0.10);
        printf("\n Como no supera las 3 camisas, se le aplica un descuento menor, su precio final es de: $ %.2f", precioFinal);
    }

    return 0;
}
