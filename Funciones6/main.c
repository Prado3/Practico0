#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

//2. Hacer una función que pase todos los elementos de una pila a otra.


void cargarPila(Pila *p);
void pasarPila(Pila *p,Pila *p2);
void pasarMismoOrden(Pila *p,Pila *p2);
int menor(Pila *p);
void ordenar(Pila *p, Pila *p2);
void insertarElemento(Pila *p);



int main()
{
    Pila elemento, elemento2;
    inicpila(&elemento);
    inicpila(&elemento2);
    char op;
    int menorElemento;

    do{
        mostrar(&elemento);
        int funcion;
        printf("\n Carga Pila = 1");
        printf("\n Pasar una Pila a otra Pila = 2");
        printf("\n Pasar una Pila a otra con el mismo orden = 3");
        printf("\n Encontrar el menor elemento de una pila = 4");
        printf("\n Pasar una Pila a otra de forma ordenada = 5");
        printf("\n Insertar un elemento en una pila ordenada = 6");
        printf("\n Ingrese el numero de la funcion que desea usar: ");
        scanf("%d", &funcion);
        switch(funcion){
        case 1:
            cargarPila(&elemento);
            mostrar(&elemento);
            break;
        case 2:
            mostrar(&elemento);
            pasarPila(&elemento, &elemento2);
            mostrar(&elemento2);
            break;
        case 3:
            mostrar(&elemento);
            pasarMismoOrden(&elemento, &elemento2);
            mostrar(&elemento2);
            break;
        case 4:
            mostrar(&elemento);
            menorElemento = menor(&elemento);
            printf("\n El menor elemento es: %d", menorElemento);
            break;
        case 5:
            mostrar(&elemento);
            ordenar(&elemento, &elemento2);
            mostrar(&elemento2);
            break;
        case 6:
            mostrar(&elemento2);
            insertarElemento(&elemento2);
            mostrar(&elemento2);
        }

        printf("\n Presione ESC para salir");
        op=getch();
        system("cls");
    }while(op!=ESC);
    return 0;
}

void cargarPila(Pila *p){
    char op;
    int nro;

    do{
        printf("\n Ingrese un elemento: ");
        scanf("%d", &nro);
        apilar(p, nro);

        printf("\n Presione ESC para salir");
        op=getch();
    }while(op!=ESC);
}

void pasarPila(Pila *p,Pila *p2){
    while(!pilavacia(p)){
        apilar(p2, desapilar(p));
    }
}

void pasarMismoOrden(Pila *p,Pila *p2){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(p)){
        apilar(&aux, desapilar(p));
    }
    while(!pilavacia(&aux)){
        apilar(p2, desapilar(&aux));
    }
}

int menor(Pila *p){
    Pila menorPila, aux;
    inicpila(&menorPila);
    inicpila(&aux);
    int menor;

    if(!pilavacia(p)){
        apilar(&menorPila, desapilar(p));
        while(!pilavacia(p)){
            if(tope(p) < tope(&menorPila)){
                apilar(&menorPila, desapilar(p));
            }else{
                apilar(&aux, desapilar(p));
            }
        }
    }
    menor = tope(&menorPila);
    while(pilavacia(&menorPila)){
        apilar(&aux, desapilar(&menorPila));
    }
    while(pilavacia(&aux)){
        apilar(p, desapilar(&aux));
    }
    //printf("\n %d", menor);

    return menor;
}

void ordenar(Pila *p, Pila *p2){
    Pila menorPila, aux;
    inicpila(&menorPila);
    inicpila(&aux);

    while(!pilavacia(p)){
        if(!pilavacia(p)){
            apilar(&menorPila, desapilar(p));
            while(!pilavacia(p)){
                if(tope(p) < tope(&menorPila)){
                    apilar(&menorPila, desapilar(p));
                }else{
                    apilar(&aux, desapilar(p));
                }
            }
            apilar(p2, desapilar(&menorPila));
            while(!pilavacia(&menorPila)){
                apilar(&aux, desapilar(&menorPila));
            }
            while(!pilavacia(&aux)){
                apilar(p, desapilar(&aux));
            }
        }
    }
}

void insertarElemento(Pila *p){
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    char op;
    int nro;

    do{
        printf("\n Ingrese el numero a insertar en la pila ordenada: ");
        scanf("%d", &nro);
        apilar(&menor, nro);

        while(!pilavacia(&menor)){
            if(tope(p) < tope(&menor)){
                apilar(p, desapilar(&menor));
            }else{
                apilar(&aux, desapilar(p));
            }
        }
        while(!pilavacia(&aux)){
            apilar(p, desapilar(&aux));
        }

        printf("\n Presione ESC para salir");
        op=getch();
    }while(op!=ESC);
}

