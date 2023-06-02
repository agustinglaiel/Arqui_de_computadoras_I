#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void funcion1() {
    printf("Ha seleccionado la función 1\n");
}

void funcion2() {
    printf("Ha seleccionado la función 2\n");
}

void funcion3() {
    printf("Ha seleccionado la función 3\n");
}

void funcion4() {
    printf("Ha seleccionado la función 4\n");
}

void funcion5() {
    printf("Ha seleccionado la función 5\n");
}

int main() {
    int intentos = 0;
    char clave[] = "12345";  // Clave predefinida como cadena de caracteres

    while (intentos < 3) {
        char password[6];
        
        printf("Ingrese su password de 5 dígitos: ");

        // Leer la contraseña como una cadena de caracteres
        scanf("%5s", password);

        // Verificar si la contraseña es correcta
        if (strcmp(password, clave) == 0) {
            printf("Bienvenido al Sistema\n");

            int opcion;

            while (true) {
                printf("Seleccione una función:\n");
                printf("1 - Función 1\n");
                printf("2 - Función 2\n");
                printf("3 - Función 3\n");
                printf("4 - Función 4\n");
                printf("5 - Función 5\n");
                printf("6 - Salir\n");
                printf("Ingrese su opción: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:
                        funcion1();
                        break;
                    case 2:
                        funcion2();
                        break;
                    case 3:
                        funcion3();
                        break;
                    case 4:
                        funcion4();
                        break;
                    case 5:
                        funcion5();
                        break;
                    case 6:
                        printf("Usted ha salido del sistema\n");
                        return 0;
                    default:
                        printf("Opción no válida\n");
                }
            }
        } else {
            printf("Password no válida\n");
            intentos++;
        }
    }

    if (intentos == 3) {
        printf("Se excedió el número máximo de intentos. El programa abortará.\n");
    }

    return 0;
}

    
