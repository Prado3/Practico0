#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27
#define DIM_MAYOR 100

int cargarPila(Pila* p);
void recorrerArreglo(float a[], int validos);
float promedioArreglo(float a[],int validos);
void informacionPromedio(Pila p, float a[], int valor,int validos);
float mayorArreglo(float array[],int validos);
int menorPila(Pila p);

int main()
{
    Pila precipiaciones, menores;
    inicpila(&precipiaciones);
    inicpila(&menores);
    int menor;
    float mayoresSesenta[DIM_MAYOR];
    int validos = 0;
    int valor=0;
    int menorP;
    float mayorA;

    menor = cargarPila(&precipiaciones);
    printf("\n %d", menor);

    while(!pilavacia(&precipiaciones)){
        if(tope(&precipiaciones)>=60){
            mayoresSesenta[validos]=tope(&precipiaciones);
            desapilar(&precipiaciones);
            validos++;
        }else{
            apilar(&menores, desapilar(&precipiaciones));
        }
    }
    mostrar(&menores);
    recorrerArreglo(mayoresSesenta,validos);
    printf("\n Ingrese una temperatura a comparar: ");
    scanf("%d", &valor);
    informacionPromedio(menores,mayoresSesenta,valor,validos);

    menorP = menorPila(menores);
    printf("\n El menor de pila es: %d", menorP);

    mayorA = mayorArreglo(mayoresSesenta,validos);
    printf("\n El mayor del arreglo es: %.2f", mayorA);


    return 0;
}

int cargarPila(Pila* p){
    Pila aux;
    inicpila(&aux);
    char op;
    int nro;
    int menor;

    do{
        printf("\n Ingrese el numero de presipitaciones: ");
        scanf("%d",&nro);
        if(nro<=180){
            apilar(p, nro);
        }else{
            printf("\n El numero no puedesuperar los 180");
        }

        printf("\n Ingrese ESC para dejar de cargar");
        op=getch();
    }while(op!=ESC);

    if(!pilavacia(p)){
        menor=tope(p);
        while(!pilavacia(p)){
            if(tope(p)<menor){
                menor=tope(p);
                apilar(&aux, desapilar(p));
            }else{
                apilar(&aux, desapilar(p));
            }
        }
        while(!pilavacia(&aux)){
            apilar(p, desapilar(&aux));
        }
    }
    mostrar(p);


    return menor;
}

void recorrerArreglo(float a[], int validos){
    for(int i = 0; i < validos;i++){
        printf("\n %f", a[i]);
    }
}

float promedioArreglo(float a[],int validos){
    float suma = 0;
    float promedio = 0;
    int i = 0;

    while(i<validos){
        suma = suma + a[i];
        i++;
    }
    printf("\n %f",suma);
    promedio=(float)suma/(float)i;
    printf("\n %f", promedio);

    return promedio;
}

float porcentajePila(Pila p){
    Pila aux;
    inicpila(&aux);
    int suma = 0;
    float promedio = 0;
    int i = 0;

    while(!pilavacia(&p)){
        suma = suma + tope(&p);
        apilar(&aux, desapilar(&p));
        i++;
    }

    promedio = (float)suma/(float)i;
    return promedio;
}

void informacionPromedio(Pila p, float a[], int valor,int validos){
    float promedio = 0;
    float porcentaje = 0;
    float resultado = 0;
    promedio = promedioArreglo(a,validos);
    printf("\n El promedio es: %.2f", promedio);

    porcentaje = porcentajePila(p);
    if(porcentaje<valor){
        resultado = 100-((porcentaje*100)/(float)valor);
        printf("\n Las precipitaciones son %.2f menos que el valor ingresado", resultado);
    }else{
        resultado=100-(((float)valor*100)/porcentaje);
        printf("\n Las precipitaciones son %.2f mas que el valor ingresado", resultado);
    }
}

float mayorArreglo(float array[],int validos){
    int i = 0;
    float mayor = 0;

    if(validos>0){
    mayor = array[i];
        while(i<validos){
            if(array[i]>mayor){
                mayor = array[i];
            }
            i++;
        }
    }
    printf("\n %f", mayor);

    return mayor;
}

int menorPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int menor;

    if(!pilavacia(&p)){
        menor = tope(&p);
        while(!pilavacia(&p)){
            if(menor>tope(&p)){
                menor = tope(&p);
            }
            desapilar(&p);
        }
    }

    return menor;
}


