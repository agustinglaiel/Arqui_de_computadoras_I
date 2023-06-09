#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>
#include <ncurses.h>


void disp_binary(int);
void delay(int);
void autofantastico();
void choque();
void f1();
void bondi();

void delay(int time)
{
   usleep(time * 1000); /* Dormir en microsegundos */
}

void disp_binary(int i)
{
   int t;
   for (t = 128; t > 0; t = t / 2) {
      if (i & t)
         printf("* ");
      else
         printf("_ ");
   }
   printf("\n");
}

void autofantastico()
{
   unsigned char output;
   char t;
   int on_time;  /* set holding time */

   for (t = 0; t < 5; t++) {
      output = 0x80;

      for (int i = 0; i < 8; i++) {
         on_time = 200; /* Tiempo de espera en milisegundos */
         disp_binary(output);
         delay(on_time); /* Esperar un tiempo */
         output = output >> 1; /* Desplazar los bits a posiciones inferiores */
         printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio

      }

      output = 0x01;

      for (int i = 0; i < 6; i++) {
         output = output << 1;
         on_time = 200; /* Tiempo de espera en milisegundos */
         disp_binary(output);
         delay(on_time);
         printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio

      }
   }
}

void choque() {
   unsigned char output;
   int on_time;  /* set holding time */
   unsigned char patrones[] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42, 0x81};

   while (true) {
      for (int i = 0; i < 7; i++) {
         output = patrones[i];
         on_time = 200; /* Tiempo de espera en milisegundos */
         disp_binary(output);
         delay(on_time);
         printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio
      }

      // Leer el carácter ingresado por el usuario
      int c = getchar();

      // Verificar si el carácter es 'q' o 'Esc'
      if (c == 'q' || c == 27) {
         return;
         system("clear"); // Borrar la pantalla
         
      }
   }
}

void f1() {
    unsigned char output;
    char t;
    int on_time;  /* set holding time */
    printf("Has elegido la opcion de F1:\n\n");

    output = 0x80;

    for (int i = 2; i < 512; i = (i*2)+2) {
        on_time = 1000; /* Tiempo de espera en milisegundos */
        disp_binary(output);
        delay(on_time); /* Esperar un tiempo */
        output = output + (output/i); /* Le suma el bit de la derecha */
        printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio
    }
    
    output = 0x00;
    on_time = 1000; /* Tiempo de espera en milisegundos */
    disp_binary(output);
    delay(on_time);
    printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio
}

void bondi()
{
   unsigned char output;
   int on_time;  /* set holding time */

   unsigned char patrones[] = {0x80, 0xC0, 0xE0, 0xF0, 0xB8, 0x9C, 0x4E, 0x27, 0x13, 0x09, 0x04};

   for (int t = 0; t < 5; t++) {
      for (int i = 0; i < 11; i++) {
         output = patrones[i];
         on_time = 500; /* Tiempo de espera en milisegundos */
         disp_binary(output);
         delay(on_time);
         printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio
      }
   }
}

int main() {
    int intentos = 0;
    char clave[] = "12345";  // Clave predefinida como cadena de caracteres
    struct termios old_term, new_term;

    while (intentos < 3) {
        char password[50];
        int passwordLength;
        
        printf("Ingrese su password: ");
        // Desactivar el eco del teclado
        tcgetattr(fileno(stdin), &old_term);
        new_term = old_term;
        new_term.c_lflag &= ~ECHO;
        tcsetattr(fileno(stdin), TCSANOW, &new_term);
        
        // Leer la contraseña
        fgets(password, sizeof(password), stdin);
        
        // Restaurar la configuración original del teclado
        tcsetattr(fileno(stdin), TCSANOW, &old_term);
        
        // Eliminar el salto de línea del final de la contraseña
        passwordLength = strlen(password);
        if (password[passwordLength - 1] == '\n')
            password[passwordLength - 1] = '\0';
        
        // Verificar si la contraseña es correcta
        if (strncmp(password, clave, strlen(clave)) == 0) {
            printf("\nBienvenido al Sistema!\n");

            int opcion;

            while (true) {
                printf("Seleccione una función:\n");
                printf("1 - Auto Fantástico\n");
                printf("2 - Choque\n");
                printf("3 - Formula 1\n");
                printf("4 - Se me pasó el bondi\n");
                printf("5 - Salir\n");
                printf("Ingrese su opción: ");
                scanf("%d", &opcion);
                
                system("clear"); // Borrar la pantalla

                switch (opcion) {
                    case 1:
                        autofantastico();
                        break;
                    case 2:
                        choque();
                        break;
                    case 3:
                        f1();
                        break;
                    case 4:
                        bondi();
                        break;
                    case 5:
                        printf("Usted ha salido del sistema\n");
                        return 0;
                    default:
                        printf("Opción no válida\n");
                }
                system("clear"); // Borrar la pantalla
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