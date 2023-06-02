#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

void disp_binary(int);
void delay(int);
void autofantastico();

void funcion1() {
    printf("Ha seleccionado la función 1\n");
    autofantastico();
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

void delay(int time)
{
   usleep(time * 1000); /* Dormir en microsegundos */
}

void disp_binary(int i)
{
   int t;
   for (t = 128; t > 0; t = t / 2) {
      if (i & t)
         printf("1 ");
      else
         printf("0 ");
   }
   printf("\n");
}

void autofantastico()
{
   unsigned char output;
   char t;
   int on_time;  /* set holding time */

   for (t = 0; t < 10; t++) {
      output = 0x80;

      for (int i = 0; i < 8; i++) {
         on_time = 100; /* Tiempo de espera en milisegundos */
         disp_binary(output);
         delay(on_time); /* Esperar un tiempo */
         output = output >> 1; /* Desplazar los bits a posiciones inferiores */
      }

      output = 0x01;

      for (int i = 0; i < 6; i++) {
         output = output << 1;
         on_time = 100; /* Tiempo de espera en milisegundos */
         disp_binary(output);
         delay(on_time);
      }
   }
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
            printf("Bienvenido al Sistema!\n");

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