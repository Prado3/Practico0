#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define DIM 5


int main()
{
    char pal1[DIM];
    char pal2[20];

    printf("\n Ingrese una palabra: ");
    scanf("%s", pal1);
    fflush(stdin);
    printf("\n Ingrese una palabra: ");
    gets(pal2);
    for(int i = 0; i<strlen(pal1);i++){
        printf("\n%c",pal1[i]);
    }


    printf("\n pal1: %s - %d", pal1, strlen(pal1));
    printf("\n pal1: %s - %d", pal2,strlen(pal2));

    //compara cadenas strmp(); si son iguales devuelve 0, si retorna -1 la primera es menor que la seg
    //compara cadenas con mayusculas incluidas strmpi(); si retorna 1 es mayor la segunda
    strcat(pal2,pal1);
    strcpy(pal1, pal2);

    printf("\n pal1: %s - %d", pal1, strlen(pal1));
    printf("\n pal1: %s - %d", pal2,strlen(pal1));


    return 0;
}
