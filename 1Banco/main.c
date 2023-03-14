#include <stdio.h>
#include <stdlib.h>
//Suponga que un individuo desea invertir su capital en un banco
//y desea saber cuánto dinero ganará después de un mes si el banco paga a razón de 2% mensual

int main()
{
    int capital;
    float interes = 0.02;
    float ganancia;


    printf("\n Ingrese el capital a invertir: ");
    scanf("%d", &capital);

    ganancia = capital * interes;

    printf("\n Su ganancia mensual es de:$ %.2f", ganancia);


    return 0;
}
