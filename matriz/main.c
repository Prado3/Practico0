#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define DIM 5
#define NAME 100

void cargarMatriz(int fil, int col,int m[fil][col]);

int main()
{
    int fil=30;
    int col=30;
    int mat[fil][col];
    int i=0;
    int j=0;
    char names[NAME][20];
    int validosName=0;

    for(i=0;i<2;i++){
        printf("\n Ingrese un numbre: ");
        scanf("%s", names[i]);
    }
    for(i=0;i<2;i++){
        printf("\n Nombre: %s",names[i]);
    }

    //cargarMatriz(fil,col,mat);

    //printf("\n Listado de la matriz\n");
    /*for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}

void cargarMatriz(int fil, int col,int m[fil][col]){
    int j=0;
    int i=0;

    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
           m[i][j]=rand()%100;
        }
    }
}
