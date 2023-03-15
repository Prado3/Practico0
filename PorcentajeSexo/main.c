#include <stdio.h>
#include <stdlib.h>

//Un maestro desea saber qué porcentaje de hombres y que porcentaje de mujeres hay en un grupo de estudiantes.

int main()
{
    int hombres;
    int totalAlumnos;
    int mujeres;
    float promedioM;
    float promedioH;

    printf("\n Ingrese la cantidad de alumnos: ");
    scanf("%d", &totalAlumnos);

    printf("\n Ingrese la cantidad de hombres: ");
    scanf("%d", &hombres);

    mujeres = totalAlumnos - hombres;

    promedioH = ((float)hombres*100)/totalAlumnos;
    promedioM = 100 - promedioH;

    printf("\n El porcentaje de hombres es de: %.2f porciento", promedioH );
    printf("\n El porcentaje de mujeres es de: %.2f porciento", promedioM );



    return 0;
}
