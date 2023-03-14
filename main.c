#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notas;
    int menor;
    int mayor;
    int total = 0;
    int cantNotas = 0;
    float promedio;

    do{
        system("cls");
        printf("\n Ingrese las notas(Ingrese 0 para salir): ");
        scanf("%d", &notas);

        if(notas!=0){
        if(cantNotas==0){
            menor = notas;
            mayor = notas;
        }else{
            if(notas<menor){
                menor = notas;
            }else {
                if(notas > mayor){
                    mayor = notas;
                }
            }
        }
        }

        cantNotas = cantNotas + 1;
        total = total + notas;

    }while( notas != 0);
    if(cantNotas>0){
    promedio = (float)total / cantNotas;
    }
    printf(" \n Total de notas ingresadas: %d",total);
    printf(" \n Cantidad de notas ingresadas: %d",cantNotas);
    printf(" \n Promedio de notas ingresadas: %.2f",promedio);
    printf(" \n Menor nota ingresada: %d", menor);
    printf(" \n Mayot nota ingresada: %d",mayor);



    return 0;
}
