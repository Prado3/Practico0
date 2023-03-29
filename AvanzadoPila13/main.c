#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "conio.h"
#define ESC 27

//13. Suponer un juego de cartas en el que en cada mano se reparten dos cartas por jugador.
//Un jugador gana la mano cuando la suma de sus cartas es mayor que las del contrario y al hacerlo coloca todas las cartas
//(las de él y las de su rival) en su pila de puntos. En caso de empate (y para simplificar) siempre gana el jugador1.
//Simular la ejecución del juego de tal manera que dada una pila MAZO (con un número de elementos múltiplo de cuatro)
//distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2 como si estos hubieran jugado.
//Utilizar las pilas auxiliares que crea conveniente.


int main()
{
    srand(time(NULL));
    Pila jugador1, jugador2, puntosjug1, puntosjug2, aux1, aux2, mazo, resmano;

    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&puntosjug1);
    inicpila(&puntosjug2);
    inicpila(&aux1);
    inicpila(&aux2);
    inicpila(&mazo);
    inicpila(&resmano);

    int sumj1 = 0;
    int sumj2 = 0;

    for(int i = 0; i < 20; i++){
        apilar(&mazo, rand()%40);
    }
    mostrar(&mazo);
    while(!pilavacia(&mazo)){
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
        apilar(&jugador1, desapilar(&mazo));
        apilar(&jugador2, desapilar(&mazo));
        while(!pilavacia(&jugador1)){
            sumj1 = sumj1 + tope(&jugador1);
            apilar(&resmano, desapilar(&jugador1));
        }
        while(!pilavacia(&jugador2)){
            sumj2 = sumj2 + tope(&jugador2);
            apilar(&resmano, desapilar(&jugador2));
        }
        if(sumj1 > sumj2 || sumj1 == sumj2){
            while(!pilavacia(&resmano)){
                apilar(&puntosjug1, desapilar(&resmano));
            }
        }else{
            while(!pilavacia(&resmano)){
                apilar(&puntosjug2, desapilar(&resmano));
            }
        }
    }

    mostrar(&puntosjug1);
    mostrar(&puntosjug2);



    return 0;
}
