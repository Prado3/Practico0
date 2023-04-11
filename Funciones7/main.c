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
void ordenadaInser(Pila *p, Pila *p2);
int suma(Pila s);
float division(int suma, int cantidad);
float promedio(Pila p);
int decimal(Pila p);





int main()
{
    Pila elemento, elemento2;
    inicpila(&elemento);
    inicpila(&elemento2);
    char op;
    int menorElemento;
    int sum;
    float prom;
    int deci;

    do{
        mostrar(&elemento);
        int funcion;
        printf("\n Carga Pila = 1");
        printf("\n Pasar una Pila a otra Pila = 2");
        printf("\n Pasar una Pila a otra con el mismo orden = 3");
        printf("\n Encontrar el menor elemento de una pila = 4");
        printf("\n Pasar una Pila a otra de forma ordenada = 5");
        printf("\n Insertar un elemento en una pila ordenada = 6");
        printf("\n Ordenar una pila por insercion= 7");
        printf("\n Sumar los ultimos numeros de una pila= 8");
        printf("\n Sacar promedio de todos los elementos= 9");
        printf("\n Pasar los elementos de una pila a decimal= 10");
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
            break;
        case 7:
            mostrar(&elemento);
            ordenadaInser(&elemento, &elemento2);
            mostrar(&elemento2);
            break;
        case 8:
            mostrar(&elemento);
            sum = suma(elemento);
            printf("\n la suma es %d", sum);
        case 9:
            mostrar(&elemento);
            prom = promedio(elemento);
            printf("\n El promedio es %.2f", prom);
            break;
        case 10:
            mostrar(&elemento);
            deci = decimal(elemento);
            printf("\n %d", deci);
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

void ordenadaInser(Pila *p, Pila *p2){
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(p)){
        while(!pilavacia(p2) && tope(p2) < tope(p)){
            apilar(&aux, desapilar(p2));
        }

        apilar(p2, desapilar(p));

        while(!pilavacia(&aux)){
            apilar(p, desapilar(&aux));
        }
    }
}

int suma(Pila s){
    Pila aux;
    inicpila(&aux);
    int suma;

    apilar(&aux, desapilar(&s));
    suma = tope(&aux) + tope(&s);

    return suma;
}

float promedio(Pila p){
   int sum = 0;
   int cant = 0;
   float prome = 0;

   sum = sumar(&p);
   printf("\n %d", sum);
   cant = cantidad(&p);
   prome = division(sum, cant);

   return prome;
}

int sumar(Pila p){
    Pila aux;
    inicpila(&aux);
    int suma = 0;

    while(!pilavacia(&p)){
        suma = suma + tope(&p);
        apilar(&aux, desapilar(&p));
    }

    return suma;
}

int cantidad(Pila p){
    Pila aux;
    inicpila(&aux);
    int cantidad = 0;

    while(!pilavacia(&p)){
        cantidad = cantidad + 1;
        apilar(&aux, desapilar(&p));
    }
    printf("\n %d", cantidad);

    return cantidad;
}

float division(int suma, int cantidad){
    float promedio;

    promedio = (float)suma / (float)cantidad;

    return promedio;
}

int decimal(Pila p){
    Pila aux;
    inicpila(&aux);
    int deci = 0;
    int con = 1;
    int top;

    while(!pilavacia(&p)){
        if(tope(&p) < 10){
            deci = tope(&p) * con;
            apilar(&aux, desapilar(&p));
                while(!pilavacia(&p)){
                top = tope(&p);
                con = con * 10;
                deci = deci + (top * con);
                apilar(&aux, desapilar(&p));
                }
            }
        }
    return deci;
}





