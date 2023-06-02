#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
            break;
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


    
