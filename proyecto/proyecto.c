#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>
#include <ncurses.h>
#include "EasyPIO.h"

void disp_binary(int);
void delay(int);
void autofantastico();
void choque();
void f1();
void bondi();
//extern void bondi_asm();
//extern void bondi_inf();
extern void formula1();

void delay(int time)
{
   usleep(time * 1000); /* Dormir en microsegundos */
}

void leds(int i)
{
   const char led[] = {14,15,18,23,24,25,8,7};
   int indice = 0;
   int t;
   for (t = 128; t > 0; t = t / 2) {
      if (i & t)
         digitalWrite(led[indice], 1);
      else
         digitalWrite(led[indice], 0);
      indice++;
   }
}


void disp_binary(int i)
{
   int t;
   leds(i);
   for (t = 128; t > 0; t = t / 2) {
      if (i & t)
         printf("* ");
      else
         printf("_ ");
   }
   printf("\n");
}

void readPassword(char *password, int maxLength) {
    struct termios oldTerm, newTerm;
    
    tcgetattr(fileno(stdin), &oldTerm);
    newTerm = oldTerm;
    newTerm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(fileno(stdin), TCSANOW, &newTerm);
    
    int i = 0;
    char c;
    while (i < maxLength - 1 && (c = getchar()) != '\n') {
        password[i++] = c;
        putchar('*');
    }
    password[i] = '\0';
    
    tcsetattr(fileno(stdin), TCSANOW, &oldTerm);
    putchar('\n');
}

void autofantastico()
{
   unsigned char output;
   char t;
   int on_time = 200;  /* set holding time */
   int min_time = 20; // Límite mínimo de tiempo
   int max_time = 500; // Límite máximo de tiempo
  
   initscr(); // Inicializar la biblioteca ncurses
   keypad(stdscr, TRUE); // Habilitar el reconocimiento de teclas especiales, incluyendo las flechas
   nodelay(stdscr, TRUE); // Habilitar el modo de entrada de teclado no bloqueante
   noecho(); // Desactivar la impresión automática de los caracteres ingresados

   mvprintw(0, 0, "Has elegido la Función de Auto Fantástico:\n\n(Para salir pulsa la tecla 'q'. Para cambiar la velocidad, con las flechas))\n\n");
   refresh(); // Actualizar la pantalla

   while (1) {
         output = 0x80;

         for (int i = 0; i < 8; i++) {
            disp_binary(output);
            delay(on_time); /* Esperar un tiempo */
            output = output >> 1; /* Desplazar los bits a posiciones inferiores */
            printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio

            // Verificar si se ha presionado la tecla 'q', KEY_UP o KEY_DOWN
            int c = getch();
            if (c == 'q') {
               endwin(); // Finalizar el modo ncurses
               system("clear"); // Borrar la pantalla
               return;
            } else if (c == KEY_UP) {
               on_time -= 20; // Subir la velocidad en 20 milisegundos
               if (on_time < min_time) {
               on_time = min_time; // Asegurarse de que la velocidad no sea menor que el límite mínimo
               }
            } else if (c == KEY_DOWN) {
               on_time += 20; // Bajar la velocidad en 20 milisegundos
               if (on_time > max_time) {
                  on_time = max_time; // Asegurarse de que la velocidad no sea mayor que el límite máximo
               }
            }
         }

         output = 0x01;

         for (int i = 0; i < 6; i++) {
            output = output << 1;
            disp_binary(output);
            delay(on_time);
            printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio

            // Verificar si se ha presionado la tecla 'q', KEY_UP o KEY_DOWN
            int c = getch();
            if (c == 'q') {
               endwin(); // Finalizar el modo ncurses
               system("clear"); // Borrar la pantalla
               return;
            } else if (c == KEY_UP) {
               on_time -= 20; // Subir la velocidad en 20 milisegundos
               if (on_time < min_time) {
                  on_time = min_time; // Asegurarse de que la velocidad no sea menor que el límite mínimo
               }
            } else if (c == KEY_DOWN) {
               on_time += 20; // Bajar la velocidad en 20 milisegundos
               if (on_time > max_time) {
                  on_time = max_time; // Asegurarse de que la velocidad no sea mayor que el límite máximo
               }
            }
         }
   }

   endwin(); // Finalizar el modo ncurses
}

void choque() {
   unsigned char output;
   int on_time = 200;  /* set holding time */
   int min_time = 20; // Límite mínimo de tiempo
   int max_time = 500; // Límite máximo de tiempo

   unsigned char patrones[] = {0x81, 0x42, 0x24, 0x18, 0x24, 0x42, 0x81};

   initscr(); // Inicializar la biblioteca ncurses
   keypad(stdscr, TRUE); // Habilitar el reconocimiento de teclas especiales, incluyendo las flechas
   nodelay(stdscr, TRUE); // Habilitar el modo de entrada de teclado no bloqueante
   noecho(); // Desactivar la impresión automática de los caracteres ingresados

   mvprintw(0, 0, "Has elegido la Función del Choque:\n\n(Para salir pulsa la tecla 'q'. Para cambiar la velocidad, con las flechas)\n\n");
   refresh(); // Actualizar la pantalla

   while (1) {
      for (int i = 0; i < 7; i++) {
         output = patrones[i];
         disp_binary(output);
         delay(on_time);
         printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio

         // Verificar si se ha presionado la tecla 'q', KEY_UP o KEY_DOWN
         int c = getch();
         if (c == 'q') {
            endwin(); // Finalizar el modo ncurses
            system("clear"); // Borrar la pantalla
            return;
         } else if (c == KEY_UP) {
            on_time -= 20; // Subir la velocidad en 20 milisegundos
            if (on_time < min_time) {
               on_time = min_time; // Asegurarse de que la velocidad no sea menor que el límite mínimo
            }
         } else if (c == KEY_DOWN) {
            on_time += 20; // Bajar la velocidad en 20 milisegundos
            if (on_time > max_time) {
               on_time = max_time; // Asegurarse de que la velocidad no sea mayor que el límite máximo
            }
         }
      }
   }

   endwin(); // Finalizar el modo ncurses
}
void f1() {
    unsigned char output;
    int on_time = 500;  /* set holding time */
    int min_time = 200; // Límite mínimo de tiempo
    int max_time = 1000; // Límite máximo de tiempo
    
    initscr(); // Inicializar la biblioteca ncurses
    keypad(stdscr, TRUE); // Habilitar el reconocimiento de teclas especiales, incluyendo las flechas
    nodelay(stdscr, TRUE); // Habilitar el modo de entrada de teclado no bloqueante
    noecho(); // Desactivar la impresión automática de los caracteres ingresados

    mvprintw(0, 0, "Has elegido la Función de Fórmula 1:\n\n(Para salir pulsa la tecla 'q')\n\n");
    refresh(); // Actualizar la pantalla


   while (1) {
         output = 0x80;
         for (int i = 2; i < 512; i = (i*2)+2) {
            disp_binary(output);
            delay(on_time); /* Esperar un tiempo */
            output = output + (output/i); /* Le suma el bit de la derecha */
            printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio
            // Verificar si se ha presionado la tecla 'q', KEY_UP o KEY_DOWN
            int c = getch();
            if (c == 'q') {
               endwin(); // Finalizar el modo ncurses
               system("clear"); // Borrar la pantalla
               return;
            } else if (c == KEY_UP) {
                  on_time -= 100; // Subir la velocidad en 100 milisegundos
                  if (on_time < min_time) {
                     on_time = min_time; // Asegurarse de que la velocidad no sea menor que el límite mínimo
                  }
               } else if (c == KEY_DOWN) {
                  on_time += 100; // Bajar la velocidad en 100 milisegundos
                  if (on_time > max_time) {
                     on_time = max_time; // Asegurarse de que la velocidad no sea mayor que el límite máximo
                  }
               }
            }
            output = 0x00;
            disp_binary(output);
            delay(on_time);
            printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio   
   }
   endwin(); // Finalizar el modo ncurses
}

void bondi()
{
   unsigned char output;
   int on_time = 200;  /* set holding time */
   int min_time = 20; // Límite mínimo de tiempo
   int max_time = 500; // Límite máximo de tiempo

   unsigned char patrones[] = {0x80, 0xC0, 0xE0, 0xF0, 0xB8, 0x9C, 0x4E, 0x27, 0x13, 0x09, 0x04, 0x02, 0x01};

   initscr(); // Inicializar la biblioteca ncurses
   keypad(stdscr, TRUE); // Habilitar el reconocimiento de teclas especiales, incluyendo las flechas
   nodelay(stdscr, TRUE); // Habilitar el modo de entrada de teclado no bloqueante
   noecho(); // Desactivar la impresión automática de los caracteres ingresados

   mvprintw(0, 0, "Has elegido la Función del Bondi:\n\n(Para salir pulsa la tecla 'q'. Para cambiar la velocidad, con las flechas))\n\n");
   refresh(); // Actualizar la pantalla

   while (1) {
      for (int i = 0; i < 13; i++) {
         output = patrones[i];
         disp_binary(output);
         delay(on_time);
         printf("\033[A\r"); // Mover el cursor a la línea anterior y al inicio

         // Verificar si se ha presionado la tecla 'q', KEY_UP o KEY_DOWN
         int c = getch();
         if (c == 'q') {
            endwin(); // Finalizar el modo ncurses
            system("clear"); // Borrar la pantalla
            return;
         } else if (c == KEY_UP) {
            on_time -= 20; // Subir la velocidad en 20 milisegundos
            if (on_time < min_time) {
               on_time = min_time; // Asegurarse de que la velocidad no sea menor que el límite mínimo
            }
         } else if (c == KEY_DOWN) {
            on_time += 20; // Bajar la velocidad en 20 milisegundos
            if (on_time > max_time) {
               on_time = max_time; // Asegurarse de que la velocidad no sea mayor que el límite máximo
            }
         }
      }
   }

   endwin(); // Finalizar el modo ncurses
}
int main() {
    
    pioInit();
    const char led[] = {14,15,18,23,24,25,8,7};
    for(int i=0; i<8; i++){
  	 pinMode(led[i], OUTPUT); // Configure los 8 pines para los LEDs como salidas en main
    }
    leds(0x00);
    
    int intentos = 0;
    char clave[] = "12345";  // Clave predefinida como cadena de caracteres

    while (intentos < 3) {
        char password[50];
        
        printf("Ingrese su password: ");
        readPassword(password, sizeof(password));
        
        // Verificar si la contraseña es correcta
        if (strcmp(password, clave) == 0) {
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
                        formula1();
                        //f1();
                        break;
                    case 4:
                        //bondi_asm();
                        //bondi_inf();
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
