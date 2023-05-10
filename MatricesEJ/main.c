#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define FIL 3
#define COL 2
#define FILSTR 20
#define COLSTR 20
#define ESC 27

void cargarMatriz(int fila, int colu, int m[fila][colu]);
void mostrarMatriz(int fila, int colu,int m[fila][colu]);
void cargarMatrizRandom(int fila,int colu,int m[fila][colu]);
int sumaMatriz(int fila, int colu, int m[fila][colu]);
float promedioMatriz(int fila, int colu, int m[fila][colu]);
void buscarEnMatriz(int fila,int colu,int m[fila][colu], int elemento);
int cargarArregloPalabras(char n[][20], int dim);
void mostrarArregloString(char n[][20],int validos);
int buscarString(char n[][20], int validos, char palabra[][20]);

int main()
{
    srand(time(NULL));
    int matriz[FIL][COL];
    int matrizRand[FIL][COL];
    int totalSumaMatriz=0;
    float promeDeMatriz=0;
    char nombres[FILSTR][COLSTR];
    int cantidadNombres=0;
    int posicionPalabra;
    char nombreBuscar[10][20];

    //cargarMatriz(FIL,COL,matriz);
    //mostrarMatriz(FIL,COL, matriz);

    //cargarMatrizRandom(FIL,COL,matrizRand);
   // mostrarMatriz(FIL,COL, matrizRand);
    //totalSumaMatriz = sumaMatriz(FIL,COL,matriz);
   // printf("\n La suma total de la matriz es: %d",totalSumaMatriz);

   // promeDeMatriz = promedioMatriz(FIL,COL,matriz);
   // printf("\n El promedio de una matriz es: %.2f", promeDeMatriz);

   // buscarEnMatriz(FIL,COL,matriz,3);

    cantidadNombres=cargarArregloPalabras(nombres,FILSTR);
    printf("\n La cantidad de nombres cargados es: %d", cantidadNombres);
    mostrarArregloString(nombres,cantidadNombres);

    printf("\n Ingrese el nombre a buscar: ");
    gets(nombreBuscar[0]);

    posicionPalabra = buscarString(nombres,cantidadNombres,nombreBuscar);

    if(posicionPalabra<0){
        printf("\n No se encuentra el nombre");
    }else{
        printf("\n El nombre se encuentra en la fila: %d", posicionPalabra);
    }

    return 0;
}

void cargarMatriz(int fila, int colu, int m[fila][colu]){
    int j =0;

    for(int i = 0; i<fila;i++){
        for(j=0;j<colu;j++){
            printf("\n Ingrese un numero: ");
            scanf("%d", &m[i][j]);
        }
    }
}

void mostrarMatriz(int fila, int colu, int m[fila][colu]){
    int j =0;

    for(int i = 0; i<fila;i++){
        for(j=0;j<colu;j++){
            printf("%d - ", m[i][j]);
        }
        printf("\n");
    }
}

void cargarMatrizRandom(int fila,int colu,int m[fila][colu]){
    int j = 0;

    for(int i= 0;i<fila;i++){
        for(j=0;j<colu;j++){
            m[i][j]=rand()%20;
        }
    }
}

int sumaMatriz(int fila, int colu, int m[fila][colu]){
    int j=0;
    int suma=0;

    for(int i =0;i<fila;i++){
        for(j=0;j<colu;j++){
            suma = suma + m[i][j];
        }
    }
    return suma;
}

float promedioMatriz(int fila, int colu, int m[fila][colu]){
    int j=0;
    int suma = 0;
    float cantElementos = (float)fila * (float)colu;
    float promedio = 0;

    printf("\n La cantidad de elementos es: %.2f", cantElementos);
    suma = sumaMatriz(fila,colu,m);
    promedio = (float)suma / cantElementos;

    return promedio;
}

void buscarEnMatriz(int fila,int colu,int m[fila][colu], int elemento){
    int j=0;
    int dato=0;

    for(int i =0;i<fila;i++){
        for(j=0;j<colu;j++){
            if(elemento==m[i][j]){
                dato++;
            }
        }
    }

    printf("\n El elemento se encuentra %d veces en la matriz", dato);
}

int cargarArregloPalabras(char n[][20], int dim){
    int i = 0;
    char op;

    do{
        system("cls");
        printf("\n Ingrese un nombre: ");
        gets(n[i]);
        i++;
        fflush(stdin);

        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }while(i<dim && op!=ESC);
    return i;
}

void mostrarArregloString(char n[][20],int validos){
    for(int i =0;i<validos;i++){
        printf("\n %s", n[i]);
    }
}

int buscarString(char n[][20], int validos, char palabra[][20]){
    int i=0;
    int res =0;


    while(i<validos){
        res=strcmp(n[i],palabra[0]);
        if(res==0){
            return i;
        }
        i++;
    }

    return -1;
}

void ordenArregloPalabras(char n[][20],int validos){
    char aux[20];
    int i,j;
    float comp;

    for(i=0;i<validos;i++){
        for(j=0;j<validos;j++){
            comp=strcmp(n[j],n[j+1]);
            if(comp>0){
                strcpy(aux=n[j]);
                strcpy(n[j],n[j+1]);
                strcpy(n[i+1]=aux);
            }
        }
    }
}


