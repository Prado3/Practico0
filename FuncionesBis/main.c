#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27

int ran(int valor);
float divi(float a, float b);


int main()
{
    srand(time(NULL));
    int a;
    int b;
    int c;
    int n;
    int negativo;
    a = ran(a);
    b = ran(b);
    c = ran(c);

    printf("\n Ingrese numero: ");
    scanf("%d", &n);

    negativo = nega(&n);

    printf("\n EL numero en negativo es: %d",negativo);
    //calculadora();
    //printf("\n %d - %d - %d", a, b, c);
    //menorMayor(a, b, c);


    //tabla(n);

    //n = sumaN(n);
    //printf("\n La suma de los numero menores a n es: %d", n);

    return 0;
}

int ran(int valor)
{
    valor = rand()%100;

    return valor;
}

void menorMayor(int a, int b, int c)
{

    if(a < b && a <c)
    {
        printf("\n El menor es %d", a);
    }
    else
    {
        if(b < c)
        {
            printf("\n El menor es %d", b);
        }
        else
        {
            printf("\n El menor es %d", c);
        }
    }

    if(a > b && a > c)
    {
        printf("\n El mayor es %d", a);
    }
    else
    {
        if(b > c)
        {
            printf("\n El mayor es %d", b);
        }
        else
        {
            printf("\n El mayor es %d", c);
        }
    }

    return 0;
}

int sumaN(int n)
{
    int suma = 0;
    while(n > 0)
    {
        n = n - 1;
        suma = suma + n;
    }

    return suma;
}

void tabla(int t)
{
    int r;
    for(int i = 0; i < 11; i++)
    {
        r = t * i;
        printf("\n %d x %d = %d",t,i,r);
    }
}

void calculadora()
{
    int a;
    int b;
    char op;

    printf("\ Ingrese un numero:");
    scanf("%d", &a);
    printf("\ Ingrese un numero:");
    scanf("%d", &b);
    do
    {
        system("cls");
        muestraOpciones();

        op=getch();
        switch(op)
        {
        case 49:
            printf("\n La suma es %d",suma(a,b));
            break;
        case 50:
            printf("\n La resta es %d",resta(a,b));
            break;
        case 51:
            printf("\n La multiplicacion es %d",multi(a,b));
            break;
        case 52:
            printf("\n La la divicion es %.2f",divi((float)a,(float)b));
        }
        //system("pause");
        getch();
    }
    while(op!=ESC);
}

void muestraOpciones()
{
    printf("\n 1. sumar");
    printf("\n 2. restar");
    printf("\n 3. multiplicar");
    printf("\n 4. dividir");
}

int suma(int a, int b){
    return a + b;
}

int resta(int a, int b){
    return a - b;
}

int multi(int a, int b){
    return a*b;
}

float divi(float a, float b){
    return a/b;
}

void nega(int *n){
    n = *n * -1;
}




