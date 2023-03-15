#include <stdio.h>
#include <stdlib.h>

//Suponga que se tiene un conjunto de calificaciones de un grupo de 40 alumnos.
//Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.

int main()
{
    int nota, cantAlumnos = 0, total = 0, menor;
    float promedio;

    for(int i = 0; i < 40; i++){
        printf("\n Ingrese nota alumno %d: ", i);
        scanf("%d", &nota);

        if(cantAlumnos == 0){
            menor = nota;
        }else{
            if(nota < menor){
                menor = nota;
            }
        }

        total = total + nota;
        cantAlumnos = cantAlumnos + 1;
        promedio = (float)total / (float)cantAlumnos;

        printf("\n La menor nota hasta ahora es: %d", menor);
        printf("\n El promedio de las notas hasta ahora es: %.2f", promedio);

    }



    return 0;
}
