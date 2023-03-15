#include <stdio.h>
#include <stdlib.h>

//En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5000
//¿Cuál será la cantidad que pagara una persona por su compra?

int main()
{
    int totalCompra;
    float descuento = 0.20;
    float precioFinal;

    printf("\n Ingrese su compra total: ");
    scanf("%d", &totalCompra);

    precioFinal = totalCompra - (totalCompra*0.20);

    if(totalCompra >= 5000){
        printf("\n Su precio final con descuento por superar los $5000 es de: $ %.2f", precioFinal);
    }else{
        printf("\n Su precio no supero los $5000, asi que no se le aplica descuento, su monto final es de: $ %d", totalCompra);
    }


    return 0;
}
