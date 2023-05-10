#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edades[DIM];
    char nombres[DIM][20];
    char apellidos[DIM][20];
    char dni[DIM][13];
    int validosArreglo=0;

    return 0;
}

int cargaArreglos(int e[],char n[][20],char a[][30],char dni[][12], int dim){
    int i = 0;
    char op;

    while(i<dim && op != ESC){
        system("cls");
        printf("\n Ingrese la edad: ");
        scanf("%d", &e[i]);

        printf("\n Ingrese el nombre: ");
        fflush(stdin);
        gets(n[i]);

        printf("\n Ingrese el apellido: ");
        fflush(stdin);
        gets(a[i]);

        printf("\n Ingrese el dni: ");
        fflush(stdin);
        gets(dni[i]);

        i++;

        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }
}
