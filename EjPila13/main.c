#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#define ESC 27

void cargaPilaRandom(Pila* p);
void muestraPila(Pila c);

int main()
{
    Pila mazo, jugador1, jugador2, aux;
    inicpila(&mazo);
    inicpila(&aux);
    inicpila(&jugador1);
    inicpila(&jugador2);
    int puntosJugador1=0;
    int puntosJugador2=0;

    cargaPilaRandom(&mazo);
    muestraPila(mazo);

    while(!pilavacia(&mazo)){
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
    }

    while(!pilavacia(&jugador1) && !pilavacia(&jugador2)){
        puntosJugador1=puntosJugador1+tope(&jugador1);
        puntosJugador2+=tope(&jugador2);

        apilar(&aux, desapilar(&jugador1));
        apilar(&aux, desapilar(&jugador2));
    }

    if(puntosJugador1>=puntosJugador2){
        while(!pilavacia(&aux)){
            apilar(&jugador1, desapilar(&aux));
        }
    }else{
        while(!pilavacia(&aux)){
            apilar(&jugador2, desapilar(&aux));
        }
    }

    printf("\n Pila puntos jugador 1: %d", puntosJugador1);
    muestraPila(jugador1);

    printf("\n Pila puntos jugador 2: %d", puntosJugador2);
    muestraPila(jugador2);

    return 0;
}

void cargaPilaRandom(Pila* p){
    for(int i = 0; i < 40; i++){
        apilar(p, i);
    }
}

void muestraPila(Pila c){
    Pila aux;
    inicpila(&aux);
    int cont=0;
    while(!pilavacia(&c)){
        if(cont%15==0){
            printf("\n");
        }
        printf("%d - ", tope(&c));
        apilar(&aux, desapilar(&c));
        cont++;
    }
}

