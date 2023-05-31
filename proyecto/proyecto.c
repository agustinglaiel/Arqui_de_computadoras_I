#include <iostream>
#include "string.h"
#include "conio.h"
#include <vector>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

void retardo(unsigned long int); // da tiempo entre las luces
void mostrar(unsigned char);
int fvelocidad(unsigned long int); // aumenta o disminuye velocidad

void auto_fantastico(unsigned long int);
void carrera(unsigned long int);
void choque(unsigned long int);
void bateriaDescargandose(unsigned long int);
void chocaLos5(unsigned long int);

int main(){
    char contrasenia[] = {'m', 'e', 's', 's', 'i', '1', '0'};
    char contra;
    char cont[6];
    int a=0;
    int contador=0, intentos=3;
    
    while (intentos!=0){
        printf("Ingrese la contraseña del Sistema\n");

        for (int i=0, i<5; i++){
            a = getch();
            cont[i]=a;
            printf("*")
        }
        //cont[5]='\0' aca chat dice agregar el caracter nulo al final de la cadena

        if (strcmp(cont, "messi10") != 0) {
            contador++;
            intentos--;
            system("cls");
            printf("\nContraseña incorrecta, le quedan %d intentos\n", intentos);
        } else {
            intentos=0;
        }
    }
    
    if (contador<3){
        system("cls");
        printf("Ingreso al sistema\n")
    } else {
        printf("Contraseña incorrecta\n")
    }

    int opcion =1;
    unsigned long int velocidad_aux = 145000000;
    unsigned long int velocidad = velocidad_aux;

    do{
        if(contador < 3){
            printf("\n(1) Autos fantastico\n");
            printf("(2) La carrera\n");
            printf("(3) El choque\n");
            printf("(4) Bateria descargandose\n");
            printf("(5) Choca los 5\n");
            printf("(6) Salir\n");

            printf("\nIngrese la opcion que desee visualizar: ");
            scanf("%d", &opcion);

            while (opcion < 1 || opcion > 6) {
            printf("Valor erroneo, ingrese nuevamente: ");
            scanf("%d", &opcion);
            }

            switch (opcion){
                case 1:
                    system("cls");
                    auto_fantastico(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 2:
                    system("cls");
                    carrera(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 3:
                    system("cls");
                    choque(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 4:
                    system("cls");
                    bateriaDescargandose(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 5:
                    system("cls");
                    chocaLos5(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 6:
                    system("cls");
                    printf("Sistema apagado");
                    break;
                default:
                    system("cls");
                    printf("No existe secuencia para ese numero\n");
                    opcion = 0;
                }   
            } while (opcion != 6);
        }
    }
}

void retardo(unsigned long int a){
    while (a)
    {
        a--;
    }
    
}
    
