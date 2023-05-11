#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27
#define DIM 20

int cargarArreglo(int a[], int validos, int dimension);
void mostrarArreglo(int a[], int validos);
void ordenarArregloSeleccion(int a[], int validos);
void ordenarArregloInsercion(int a[], int validos);
void ordenarArregloChar(char arreglo1[], char arreglo2[], int arregloOrdenado[]);
void mostrarArregloChar(char a[], int validos);
int cargarArregloChar(char a[],int dimension);

int main()
{
    int arreglo[DIM];
    int validos = 0;
    char arregloChar1[DIM];
    char arregloChar2[DIM];
    char arregloCharOrdenado[DIM];
    int validosChar1;
    int validosChar2;
    int validosCharOrdenado;

    //validos = cargarArreglo(arreglo,validos,DIM);
    //printf("\n %d", validos);

    //mostrarArreglo(arreglo,validos);
    //ordenarArregloSeleccion(arreglo, validos);
    //ordenarArregloInsercion(arreglo,validos);
    //printf("\n %d", validos);
    //mostrarArreglo(arreglo,validos);
    validosChar1 = cargarArregloChar(arregloChar1, DIM);
    printf("\n Ahora carga el segundo arreglo..");
    validosChar2 = cargarArregloChar(arregloChar2, DIM);
    //ordenarArregloChar(arregloChar1,arregloChar2,arregloCharOrdenado);
    mostrarArregloChar(arregloChar1, validosChar1);
    mostrarArregloChar(arregloChar2, validosChar2);





    return 0;
}

int cargarArreglo(int a[], int validos, int dimension){
    int i = validos;
    for(i; i<dimension;i++){
        a[i]=rand()%20;
    }
    return i;
}

int cargarArregloChar(char a[],int dimension){
    char op;
    char letra;
    int i =0;

    do{
        system("cls");
        printf("\n Ingrese una letra: ");
        scanf("%c", &a[i]);
        i++;
        fflush(stdin);

        printf("\n Ingrese ESC para dejar de cargar...");
        op=getch();
    }while(op!=ESC && i<dimension);

    return i;
}

void mostrarArreglo(int a[], int validos){
    for(int i =0; i < validos;i++){
        printf("%d - ", a[i]);
    }
}

void mostrarArregloChar(char a[], int validos){
    for(int i = 0; i<validos;i++){
        printf("\n %c", a[i]);
    }
}

void ordenarArregloSeleccion(int a[], int validos){
    int aux;
    for(int i = 0; i < validos; i++){
        for(int j = i + 1; j <validos;j++){
            if(a[i]>a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}

void ordenarArregloInsercion(int a[], int validos){
    int aux;
    int pos;
    for(int i =0;i<validos;i++){
        pos = i;
        aux = a[i];

        while(pos>0 && a[pos-1]>aux){
            a[pos] = a[pos-1];
            pos--;
        }
        a[pos] = aux;
    }
}

void ordenarArregloChar(char arreglo1[], char arreglo2[], int arregloOrdenado[]){
    int i = 0;
    char aux;
    char min;

    while(i<14){
        min = arreglo1[i];
        for(int j = 0; j<7;j++){
            if(min>arreglo1[j]){
                min = arreglo1[j];
            }
        }
        for(int j = 0; j<7;j++){
            if(min>arreglo2[j]){
                min = arreglo2[j];
            }
        }
        arregloOrdenado[i] = min;
        i++;
    }
}
