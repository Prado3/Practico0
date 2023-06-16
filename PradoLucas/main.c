#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "paciente.h"

#define ESC 27
#define ESTRUCTURA 1000
#define ARCHIVO_PACIENTE "paciente.dat"
#define ARCHIVO_SANOS "sanos.dat"
#define ARCHIVO_ENFERMOS "enfermos.dat"

int idAutoincremental();
int validarDni(char nombreArchivo[], char dni[12]);
int validarTemperatura(char nombreArchivo[], float temp);
void cargarArchivoPaciente(char nombreArchivo[]);
void mostrarSexoParticular(char nombreArchivo[], char sexo[20]);
void pasarSegunSexo(char nombreArchivo[],stPaciente masculino[],stPaciente femenino[], int* vm, int* vf);
int cantidadEnArchivo(char nombreArchivo[]);
void pasarSanosEnfermos(char archiSanos[], char archiEnfermos[], stPaciente masculino[], stPaciente femenino[], int vm, int vf, float tempCondicional);
void calcularPorcentaje(char archiTotal[], char archiSanos[], char archiEnfermos[]);
void mostrarArchivoSExo(char archi[]);

int main()
{
    stPaciente paciente[ESTRUCTURA];
    stPaciente masculino[ESTRUCTURA];
    stPaciente femenino[ESTRUCTURA];
    int validosMasculino=0;
    int validosFemenino=0;
    char sexo[10];
    float tempe=37;

    cargarArchivoPaciente(ARCHIVO_PACIENTE);
    printf("\n Ingrese el sexo a mostrar: ");
    fflush(stdin);
    gets(sexo);
    mostrarSexoParticular(ARCHIVO_PACIENTE,sexo);
    pasarSegunSexo(ARCHIVO_ENFERMOS,masculino,femenino,validosMasculino,validosFemenino);
    pasarSanosEnfermos(ARCHIVO_SANOS,ARCHIVO_ENFERMOS,masculino,femenino,validosMasculino,validosFemenino,tempe);
    calcularPorcentaje(ARCHIVO_PACIENTE,ARCHIVO_SANOS,ARCHIVO_SANOS);
    mostrarArchivoSExo(ARCHIVO_SANOS);
    mostrarArchivoSExo(ARCHIVO_ENFERMOS);




    return 0;
}



// PUNTO 1
int validarDni(char nombreArchivo[], char dni[12]){
    stPaciente paciente;
    int flag=1;
    if(nombreArchivo){
        while(flag==1 && fread(&paciente,sizeof(stPaciente),1,nombreArchivo)>0){
            if(strcmp(dni,paciente.dni)==0){
                printf("\n El dni ya se encuentra ingresado");
                flag=0;
            }
        }
    }
    printf("%d", flag);
    return flag;
}

//PUNTO 2
int validarTemperatura(char nombreArchivo[], float temp){
    stPaciente paciente;
    int flag=1;
    float min=35;
    float max=40;
    fseek(nombreArchivo,0,SEEK_SET);
    if(nombreArchivo){
        while(flag==1 && fread(&paciente,sizeof(stPaciente),1,nombreArchivo)>0){
            printf("%d", flag);
            if(temp>= min && temp <= max){
                flag=1;
            }else{
                printf("\n La temperatura no es valida");
            }
        }
    }
    printf("%d", flag);
    return flag;
}

//PUNTO 2
int idAutoincremental(){
    static int i=0;
    i++;
    return i;
}

//PUNTO 2
void cargarArchivoPaciente(char nombreArchivo[]){
    char op;
    float temperatura=0;
    char dni[12];
    stPaciente paciente;
    FILE* archi=fopen(nombreArchivo,"ab");
    if(archi){
        while(op!= ESC){
            printf("\n Ingrese su dni: ");
            scanf("%d", &dni);
            printf("\n Ingrese su temperatura: ");
            scanf("%f", &temperatura);

            if(validarDni(archi,dni)==1 && validarTemperatura(archi,temperatura)==1){
                system("cls");
                paciente=cargarPaciente(dni,temperatura);
                fwrite(&paciente,sizeof(stPaciente),1,archi);
            }
            printf("\n Ingrese ESC para dejar de cargar...");
            op=getch();
        }
    }
}

//PUNTO 3
void mostrarSexoParticular(char nombreArchivo[], char sexo[20]){
    stPaciente paciente;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&paciente,sizeof(stPaciente),1,archi)>0){
            if(strcmpi(sexo,paciente.sexo)==0){
                mostrarSexo(paciente);
            }
        }
    }
}

//PUNTO 4
void pasarSegunSexo(char nombreArchivo[],stPaciente masculino[],stPaciente femenino[], int *vm, int *vf){
    stPaciente paciente;
    FILE* archi=fopen(nombreArchivo,"rb");
    int vM=0;
    int vF=0;
    if(archi){
        while(fread(&paciente,sizeof(stPaciente),1,archi)>0){
            if(strcmp(paciente.sexo,masculino)==0){
               masculino[vM]=paciente;
               vM++;
            }else{
                femenino[vF]=paciente;
                vF++;
            }
        }
        fclose(archi);
    }
    vm=vM;
    vf=vF;
}

// PUNTO 5
int cantidadEnArchivo(char nombreArchivo[]){
    stPaciente paciente;
    int con=0;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        fseek(nombreArchivo,0,SEEK_END);
        con = ftell(nombreArchivo)/sizeof(stPaciente);
        fclose(nombreArchivo);
    }
    return con;
}

// PUNTO 6
void pasarSanosEnfermos(char archiSanos[], char archiEnfermos[],stPaciente masculino[], stPaciente femenino[], int vm, int vf, float tempCondicional){
    stPaciente paciente;
    FILE* archiS=fopen(archiSanos,"ab");
    FILE* archiE=fopen(archiEnfermos,"ab");
    if(archiE && archiS){
        for(int i=0;i<vm;i++){
            if(masculino[i].temperatura<=tempCondicional){
                paciente=masculino[i];
                fwrite(&paciente,sizeof(stPaciente),1,archiSanos);
            }else{
                paciente=masculino[i];
                fwrite(&paciente,sizeof(stPaciente),1,archiEnfermos);
            }
        }
        for(int j=0;j<vf;j++){
            if(femenino[j].temperatura<=tempCondicional){
                paciente=femenino[j];
                fwrite(&paciente,sizeof(stPaciente),1,archiSanos);
            }else{
                paciente=femenino[j];
                fwrite(&paciente,sizeof(stPaciente),1,archiEnfermos);
            }
        }
        fclose(archiE && archiS);
    }
}

// PUNTO 7
void calcularPorcentaje(char archiTotal[], char archiSanos[], char archiEnfermos[]){
    int cantTotal=cantidadEnArchivo(archiTotal);
    int cantSanos=cantidadEnArchivo(archiSanos);
    int cantEnfermos=cantidadEnArchivo(archiEnfermos);

    float porSanos= ((float)cantSanos*100)/(float)cantTotal;
    float porEnfermos= ((float)cantEnfermos*100)/(float)cantTotal;

    printf("\n El procentaje de sanos es de: % %.2f", porSanos);
    printf("\n El procentaje de enfermos es de: % %.2f", porEnfermos);
}

//punt8
void mostrarArchivoSExo(char archi[]){
    stPaciente paciente;
    FILE* archiv=fopen(archi,"rb");
    if(archiv){
        while(fread(&paciente,sizeof(stPaciente),1,archiv)>0){
            mostrarSexo(paciente);
        }
        fclose(archiv);
    }
}

