/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

//Un obrero necesita calcular su salario semanal, el cual se obtiene de la sig. 
//manera: Si trabaja 40 horas o menos se le paga $300 por hora 
//Si trabaja más de 40 horas se le paga $300 por cada una de las primeras 40 horas 
//y $400 por cada hora extra. 

int main()
{
    int horas;
    int horaExtra = 400;
    int horaNormal = 300;
    int salario;
    
    printf("\n Ingrese la cantidad de horas trabajadas esta semana: ");
    scanf("%d", &horas);
    
    if(horas > 40){
        salario = (horas - 40)* horaExtra + (40 * horaNormal);
    }else{
        salario = horas * horaNormal;
    }
    
    printf("\n Su salario es de: $ %d", salario);

    return 0;
}
