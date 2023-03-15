#include <stdio.h>
#include <stdlib.h>

//Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Programación 1

int main()
{
    int nota, total = 0, cantNotas = 0;
    float promedio;


    for(int i = 1; i < 8; i++){
        printf("\n Ingrese su nota: ");
        scanf("%d", &nota);

        total = total + nota;
        cantNotas = cantNotas + 1;

    }



    promedio = (float)total / (float)cantNotas;

    printf("\n El promedio es: %.2f", promedio);
    return 0;
}
