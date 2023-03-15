#include <stdio.h>
#include <stdlib.h>

//Determinar si un alumno aprueba a reprueba un curso,
//sabiendo que aprobara si su promedio de tres calificaciones es mayor o igual a 7; reprueba en caso contrario.

int main()
{
    int nota;
    int sumaTotal;
    float promedio;
    int canNotas = 3;

    for(int i = 1 ; i < 4 ; i++){
        printf("\n Ingrese su nota %d : ", i);
        scanf("%d", &nota);

        sumaTotal = sumaTotal + nota;
    }

    promedio = (float)sumaTotal / 3;
    if(promedio >= 7){
        printf("\n A aprobado la materia");
    }else{
        printf("\n A reporbado la materia");
    }

    return 0;
}
